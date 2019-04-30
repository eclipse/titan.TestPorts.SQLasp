/******************************************************************************
* Copyright (c) 2000-2019 Ericsson Telecom AB
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Eclipse Public License v2.0
* which accompanies this distribution, and is available at
* https://www.eclipse.org/org/documents/epl-2.0/EPL-2.0.html
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
#include "SQL_interface.hh"
#include "mysql/mysql.h"
#include "memory.h"

namespace SQL_engine{
SQL_engine_base* new_MySQl_engine();
}
static const SQL_engine::SQL_Engine_register_data MySQL_register_data=SQL_engine::SQL_Engine_register_data(SQL_engine::MySQL_engine,&SQL_engine::new_MySQl_engine);
static const SQL_engine::SQL_registrator local_iff=SQL_engine::SQL_registrator(&MySQL_register_data);


namespace SQL_engine{

class SQL_MySQL_engine: public SQL_engine_base{
public:
  MYSQL sql_handle;
  int state; // 0- not conencted
             // 1- Connected, mysql_close must be called.

  virtual int open_database_connection(const SQL_config_data*, SQL_error&);
  virtual int execute_sql_command(const unsigned char* sql, 
                                  const unsigned long sql_length,
                                  SQL_result_data& sql_res,
                                  SQL_error&);
  virtual int close_database_connection(SQL_error&);
  SQL_MySQL_engine();
  virtual ~SQL_MySQL_engine();
};


SQL_MySQL_engine::SQL_MySQL_engine(){
  engine=MySQL_engine;
  state=0;
}

SQL_MySQL_engine::~SQL_MySQL_engine(){
  if(state){
    mysql_close(&sql_handle);
  }
}

int SQL_MySQL_engine::open_database_connection(const SQL_config_data* config_data, SQL_error& err){


 const char *host=NULL;
 const char *user=NULL;
 const char *passwd=NULL;
 const char *db=NULL;
 unsigned int port=0;
 const char *unix_socket=NULL;
 unsigned long client_flag=0;
 const char *char_set=NULL;
 const char *auto_reconnect=NULL;
 unsigned int conn_timeout=5;

 log(SQLTP_LOG_DEBUG,"Creating new database connection.");
 
 if(!mysql_init(&sql_handle)){
   err.error_code=3;
   err.error_text=mprintf("Can not initialize the MySQL library. The mysql_init returned NULL.");
   return 1;
 }
 log(SQLTP_LOG_DEBUG,"Parse parameters.");

 int i=0;
 while(config_data[i].name){
   if(!strcasecmp(config_data[i].name,"host")){
     host=config_data[i].value;
   } else
   if(!strcasecmp(config_data[i].name,"user")){
     user=config_data[i].value;
   } else
   if(!strcasecmp(config_data[i].name,"password")){
     passwd=config_data[i].value;
   } else
   if(!strcasecmp(config_data[i].name,"database")){
     db=config_data[i].value;
   } else
   if(!strcasecmp(config_data[i].name,"port")){
     port=atoi(config_data[i].value);
   } else
   if(!strcasecmp(config_data[i].name,"unix_socket")){
     unix_socket=config_data[i].value;
   } else
   if(!strcasecmp(config_data[i].name,"client_flag")){
     client_flag=atoi(config_data[i].value);
   } else
   if(!strcasecmp(config_data[i].name,"char_set")){
     mysql_options(&sql_handle, MYSQL_SET_CHARSET_NAME,config_data[i].value );
     char_set=config_data[i].value;
   } else
   if(!strcasecmp(config_data[i].name, "auto_reconnect")) {
     mysql_options(&sql_handle, MYSQL_OPT_RECONNECT, config_data[i].value);
     auto_reconnect = config_data[i].value;
   } else 
   if(!strcasecmp(config_data[i].name, "connect_timeout")){
     conn_timeout=atoi(config_data[i].value);
   }
   i++;
 }
 
 log(SQLTP_LOG_DEBUG,"Parameters:");
 log(SQLTP_LOG_DEBUG,"Host: %s",host?host:"Not specified");
 log(SQLTP_LOG_DEBUG,"user: %s",user?user:"Not specified");
 log(SQLTP_LOG_DEBUG,"password: %s",passwd?passwd:"Not specified");
 log(SQLTP_LOG_DEBUG,"database: %s",db?db:"Not specified");
 log(SQLTP_LOG_DEBUG,"port: %d",port);
 log(SQLTP_LOG_DEBUG,"unix_socket: %s",unix_socket?unix_socket:"Not specified");
 log(SQLTP_LOG_DEBUG,"client_flag: %lu",client_flag);
 log(SQLTP_LOG_DEBUG,"char_set: %s",char_set?char_set:"Not specified");
 log(SQLTP_LOG_DEBUG,"Auto-reconnect: %s", (auto_reconnect) ? auto_reconnect : "Not specified");
 log(SQLTP_LOG_DEBUG,"Connect timeout: %u",conn_timeout);

 mysql_options(&sql_handle, MYSQL_OPT_CONNECT_TIMEOUT, &conn_timeout);


 if(!mysql_real_connect(&sql_handle,host,user,passwd,db,port,unix_socket,client_flag)){
   err.error_code=4;
    err.error_text=mprintf("MySQL connect failed with error message: %s.",mysql_error(&sql_handle) );
    log(SQLTP_LOG_DEBUG,"MySQL connect failed with error message: %s.",mysql_error(&sql_handle));
   mysql_close(&sql_handle);
   return 1;
 }
 log(SQLTP_LOG_DEBUG,"The new database connection is ready.");
 
 state=1;
 return 0;
}
int SQL_MySQL_engine::execute_sql_command(const unsigned char* sql, 
                                  const unsigned long sql_length,
                                  SQL_result_data& sql_res,
                                  SQL_error& err){
  if(state==0){
    err.error_code=5;
    err.error_text=mprintf("The MySQL engine isn't connected to the database. Please connect first.");
    return 1;
  }

  if(mysql_real_query(&sql_handle,(const char*)sql, sql_length)){
    err.error_code=6;
    err.error_text=mprintf("The SQL query failed with error message: %s.",mysql_error(&sql_handle));
    return 1;
  }

  MYSQL_RES* result;
  result=mysql_store_result(&sql_handle);
  
  if(!result && mysql_errno(&sql_handle)){
    err.error_code=7;
    err.error_text=mprintf("The mysql_store_result failed with error message: %s.",mysql_error(&sql_handle));
    return 1;
  }

  if(result){
    sql_res.number_of_rows= mysql_num_rows(result);
    sql_res.rows=(SQL_row_data *)Malloc(sql_res.number_of_rows*sizeof(SQL_row_data));

    unsigned int num_fields;
    MYSQL_FIELD *fields;
    num_fields = mysql_num_fields(result);
    fields = mysql_fetch_fields(result);
    for(int i=0; i<sql_res.number_of_rows; i++){
      MYSQL_ROW row=mysql_fetch_row(result);
      SQL_row_data* act_row= sql_res.rows+i;
      if(row){
        act_row->num_of_fields=num_fields;
        act_row->field_data=(SQL_field_data*)Malloc(num_fields*sizeof(SQL_field_data));
        unsigned long *lengths;
        lengths = mysql_fetch_lengths(result);
        for(unsigned int k=0; k<num_fields; k++){
          SQL_field_data* act_field=act_row->field_data+k;
          act_field->data_length=lengths[k];
          if(i==0){ // first row, store field names
            act_field->field_name=mcopystr(fields[k].name);
          } else {
            act_field->field_name=NULL;
          }
          if(row[k]){
            if(IS_NUM(fields[k].type)){ // Numeric value, integer or float
              if(fields[k].type==MYSQL_TYPE_LONGLONG 
                || fields[k].type==MYSQL_TYPE_TINY
                || fields[k].type==MYSQL_TYPE_SHORT
                || fields[k].type==MYSQL_TYPE_LONG
                || fields[k].type==MYSQL_TYPE_INT24
                ){ // integer
                act_field->field_type=int_data;
                act_field->field_data.int_data=atoll(row[k]);
              } else { // float
                act_field->field_type=real_data;
                act_field->field_data.real_data=atof(row[k]);
             }
            } else if(fields[k].type==MYSQL_TYPE_BIT) { // bitstring
                act_field->data_length=fields[k].length;
                act_field->field_type=bitstring_data;
                act_field->field_data.text_binary_data=(unsigned char*)Malloc(lengths[k]*sizeof(unsigned char));
                memcpy(act_field->field_data.text_binary_data,row[k],lengths[k]);
            } else { // text or bynary data
              if(fields[k].charsetnr==63){ // charset num==63 -> binary data, See MySQL doc.
                act_field->field_type=binary_data;
              } else {  //
                act_field->field_type=text;
              }
              act_field->field_data.text_binary_data=(unsigned char*)Malloc(lengths[k]*sizeof(unsigned char));
              memcpy(act_field->field_data.text_binary_data,row[k],lengths[k]);
            }
          } else {
            act_field->field_type=null_data_value;
          }
        
        
        }
        
      } else {
        act_row->num_of_fields=0;
        act_row->field_data=NULL;
      }
    }
    
    mysql_free_result(result);
  } else {
    sql_res.number_of_rows= mysql_affected_rows(&sql_handle);
    sql_res.rows=NULL;
  }

  return 0;
}

int SQL_MySQL_engine::close_database_connection(SQL_error&){
  log(SQLTP_LOG_DEBUG,"Closing database connection.");  mysql_close(&sql_handle);
  state=0;
  return 0;
}

SQL_engine_base* new_MySQl_engine(){
  return new SQL_MySQL_engine;
}

}
