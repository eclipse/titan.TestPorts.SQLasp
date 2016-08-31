/******************************************************************************
* Copyright (c) 2012, 2014  Ericsson AB
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Eclipse Public License v1.0
* which accompanies this distribution, and is available at
* http://www.eclipse.org/legal/epl-v10.html
*
* Contributors:
*  Gabor Szalai - initial implementation and initial documentation
*  Zoltan Medve
*  Janos Kovesdi
******************************************************************************/
//
//  File:               SQL_MySQL_interface.cc
//  Description:        SQL test port source
//  Rev:                R6A
//  Prodnr:             CNL 113 760
// 

#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include <stdio.h>
#include <stdio.h>
#include <string>
#include <vector>
#include "SQL_interface.hh"
#include "memory.h"

#include "occi.h"
using namespace oracle::occi;
using namespace std;
namespace SQL_engine{
SQL_engine_base* new_OraSQl_engine();
}
static const SQL_engine::SQL_Engine_register_data OraSQL_register_data=SQL_engine::SQL_Engine_register_data(SQL_engine::OraSQL_engine,&SQL_engine::new_OraSQl_engine);
static const SQL_engine::SQL_registrator local_iff=SQL_engine::SQL_registrator(&OraSQL_register_data);


namespace SQL_engine{

class SQL_OraSQL_engine: public SQL_engine_base{
public:
  Environment *env;
  Connection *conn;
  int state; // 0- not conencted
             // 1- Connected, mysql_close must be called.

  virtual int open_database_connection(const SQL_config_data*, SQL_error&);
  virtual int execute_sql_command(const unsigned char* sql, 
                                  const unsigned long sql_length,
                                  SQL_result_data& sql_res,
                                  SQL_error&);
  virtual int close_database_connection(SQL_error&);
  SQL_OraSQL_engine();
  virtual ~SQL_OraSQL_engine();
  void clean_up();
};

void SQL_OraSQL_engine::clean_up(){
  if(conn){
    env->terminateConnection(conn);
    conn=NULL;
  }
  if(env){
    Environment::terminateEnvironment(env);
    env=NULL;
  }
  state=0;
}

SQL_OraSQL_engine::SQL_OraSQL_engine(){
  engine=OraSQL_engine;
  state=0;
  env=NULL;
  conn=NULL;
}

SQL_OraSQL_engine::~SQL_OraSQL_engine(){
  if(state){
    clean_up();
  }
}

int SQL_OraSQL_engine::open_database_connection(const SQL_config_data* config_data, SQL_error& err){


 string connstr="";
 string user="";
 string passwd="";
 string char_set="UTF8";
 string nchar_set="UTF8";

 log(SQLTP_LOG_DEBUG,"Creating new database connection.");
 

 log(SQLTP_LOG_DEBUG,"Parse parameters.");

 int i=0;
 while(config_data[i].name){
   if(!strcasecmp(config_data[i].name,"connection_string")){
     connstr=config_data[i].value;
   } else
   if(!strcasecmp(config_data[i].name,"user")){
     user=config_data[i].value;
   } else
   if(!strcasecmp(config_data[i].name,"password")){
     passwd=config_data[i].value;
   } else
   if(!strcasecmp(config_data[i].name,"char_set")){
     char_set=config_data[i].value;
   }
   if(!strcasecmp(config_data[i].name,"nchar_set")){
     nchar_set=config_data[i].value;
   }
   i++;
 }
 
 log(SQLTP_LOG_DEBUG,"Parameters:");
 log(SQLTP_LOG_DEBUG,"Connection string: %s",connstr.c_str());
 log(SQLTP_LOG_DEBUG,"user: %s",user.c_str());
 log(SQLTP_LOG_DEBUG,"password: %s",passwd.c_str());
 log(SQLTP_LOG_DEBUG,"char_set: %s",char_set.c_str());
 log(SQLTP_LOG_DEBUG,"nchar_set: %s",nchar_set.c_str());


 try{
   env = Environment::createEnvironment(char_set,nchar_set);
 } catch (exception &excp ) {
    err.error_code=4;
    err.error_text=mprintf("Oracle SQL Environment::createEnvironment() failed with error message: %s.",excp.what() );
    log(SQLTP_LOG_DEBUG,"Oracle SQL Environment::createEnvironment() failed with error message: %s.",excp.what());
    clean_up();
    return 1;
 }

 try{
   conn = env->createConnection(user,passwd,connstr);
 } catch (exception &excp ) {
    err.error_code=4;
    err.error_text=mprintf("Oracle SQL createConnection failed with error message: %s.",excp.what() );
    log(SQLTP_LOG_DEBUG,"Oracle SQL createConnection failed with error message: %s.",excp.what());
    clean_up();
    return 1;
 }


 log(SQLTP_LOG_DEBUG,"The new database connection is ready.");
 
 state=1;
 return 0;
}

int SQL_OraSQL_engine::execute_sql_command(const unsigned char* sql, 
                                  const unsigned long sql_length,
                                  SQL_result_data& sql_res,
                                  SQL_error& err){
  if(state==0){
    err.error_code=5;
    err.error_text=mprintf("The Oracle SQL engine isn't connected to the database. Please connect first.");
    return 1;
  }

 Statement *stmt=NULL; 
 ResultSet *rs=NULL;

 int retval=1;

 try{
  stmt = conn->createStatement((const char*)sql);
  Statement::Status res = stmt->execute();

  switch(res){
    case Statement::RESULT_SET_AVAILABLE:{
        log(SQLTP_LOG_DEBUG,"Oracle SQL query result set available");
        rs=stmt->getResultSet();
        int row_increase=1;
        int row_count=0;
        int row_size=0;
        sql_res.number_of_rows= row_count;
        sql_res.rows=NULL;
        
        vector<MetaData> cmd= rs->getColumnListMetaData();
        int num_fields=cmd.size();
        log(SQLTP_LOG_DEBUG,"Oracle SQL query number of fields per row: %d.", num_fields);
        while(rs->next()){
          if(row_count>=row_size){ // add more row to the result list
            sql_res.rows=(SQL_row_data *)Realloc(sql_res.rows,(row_size+row_increase)*sizeof(SQL_row_data));
            row_size+=row_increase;
            row_increase*=2;
          }
            log(SQLTP_LOG_DEBUG,"Oracle SQL row: %d, row_size %d",row_count,row_size );
          sql_res.number_of_rows= row_count+1;
          SQL_row_data* act_row= sql_res.rows+row_count;
          act_row->num_of_fields=num_fields;
          act_row->field_data=(SQL_field_data*)Malloc(num_fields*sizeof(SQL_field_data));
          for(int k=1; k<=num_fields; k++){
            SQL_field_data* act_field=act_row->field_data+k-1;

            if(row_count==0){  // first row, store the field name
              log(SQLTP_LOG_DEBUG,"Oracle SQL getting row name");
              act_field->field_name=mcopystr(cmd[k-1].getString(MetaData::ATTR_NAME).c_str());
              log(SQLTP_LOG_DEBUG,"Oracle SQL row name: %s",act_field->field_name);
              log(SQLTP_LOG_DEBUG,"Oracle SQL query field %d, name %s, type %d", k, act_field->field_name,cmd[k-1].getInt(MetaData::ATTR_DATA_TYPE));
            } else {
              act_field->field_name=NULL;
            }
            switch(cmd[k-1].getInt(MetaData::ATTR_DATA_TYPE)){
              case OCCIINT:
                {  // integer types
                  log(SQLTP_LOG_DEBUG,"Oracle SQL store data as int");
                  act_field->field_type=int_data;
                  act_field->field_data.int_data=rs->getInt(k);
                }
                break;
              case OCCIFLOAT:
              case OCCIDOUBLE:
              case OCCI_SQLT_NUM:
               {  // float/double types
                  log(SQLTP_LOG_DEBUG,"Oracle SQL store data as float");
                  act_field->field_type=real_data;
                  act_field->field_data.real_data=rs->getDouble(k);
                }
                break;
              case OCCI_SQLT_CHR:
                { // text data types
                  log(SQLTP_LOG_DEBUG,"Oracle SQL store data as text");
                  act_field->field_type=text;
                  string dt=rs->getString(k);
                  act_field->data_length=dt.size();
                  act_field->field_data.text_binary_data=(unsigned char*)Malloc(act_field->data_length*sizeof(unsigned char));
                  memcpy(act_field->field_data.text_binary_data,dt.c_str(),act_field->data_length);
                }
                break;

              default:{
                  log(SQLTP_LOG_DEBUG,"Oracle SQL store data as binary");
                  act_field->field_type=binary_data;
                  string dt=rs->getString(k);
                  act_field->data_length=dt.size();
                  act_field->field_data.text_binary_data=(unsigned char*)Malloc(act_field->data_length*sizeof(unsigned char));
                  memcpy(act_field->field_data.text_binary_data,dt.c_str(),act_field->data_length);
                }
                break;
            }
          }

          row_count++;
          log(SQLTP_LOG_DEBUG,"Oracle SQL next row");
          
        }
       
      }
        retval=0;
      break;
    case Statement::UPDATE_COUNT_AVAILABLE:
        sql_res.number_of_rows= stmt->getUpdateCount();
        log(SQLTP_LOG_DEBUG,"Oracle SQL query update count: %d.",sql_res.number_of_rows);
        sql_res.rows=NULL;
        retval=0;
      break;
    default:
        err.error_code=6;
        err.error_text=mprintf("Oracle SQL query returned an unsupported result: %d.", res);
        log(SQLTP_LOG_DEBUG,"Oracle SQL query returned an unsupported result: %d.",res);
      break;
  }

 } catch (exception &excp ) {
    err.error_code=6;
    err.error_text=mprintf("Oracle SQL query failed with error message: %s.",excp.what() );
    log(SQLTP_LOG_DEBUG,"Oracle SQL query failed with error message: %s.",excp.what());
    retval=1;
 }
              log(SQLTP_LOG_DEBUG,"Oracle SQL rs free");

 if(rs){
   stmt->closeResultSet(rs);
 }
              log(SQLTP_LOG_DEBUG,"Oracle SQL stmt free");
 if(stmt){
   conn->terminateStatement(stmt);
 }

  log(SQLTP_LOG_DEBUG,"Oracle SQL retval %d",retval);
  return retval;
}

int SQL_OraSQL_engine::close_database_connection(SQL_error&){
  log(SQLTP_LOG_DEBUG,"Closing database connection.");
  clean_up();
  return 0;
}

SQL_engine_base* new_OraSQl_engine(){
  return new SQL_OraSQL_engine;
}

}
