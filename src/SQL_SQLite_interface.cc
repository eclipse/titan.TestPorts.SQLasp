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
//  File:               SQL_SQLite_interface.cc
//  Description:        SQL test port SQLite interface source
//  Rev:                R6A
//  Prodnr:             CNL 113 760
// 
#include "SQL_interface.hh"
#include "sqlite3.h"
#include "memory.h"
#include "string.h"

namespace SQL_engine{
  SQL_engine_base *new_SQLite_engine();
}

static const SQL_engine::SQL_Engine_register_data SQLite_register_data=SQL_engine::SQL_Engine_register_data(SQL_engine::SQLite_engine, &SQL_engine::new_SQLite_engine);
static const SQL_engine::SQL_registrator local_iff=SQL_engine::SQL_registrator(&SQLite_register_data);


namespace SQL_engine{

class SQL_SQLite_engine: public SQL_engine_base{
public:  
  sqlite3 *sql_handle;
  int state; // 0 - not connected
             // 1 - connected, sqlite_close() must be called.
  virtual int open_database_connection(const SQL_config_data*, SQL_error&);
  virtual int execute_sql_command(const unsigned char *sql,
                                  const unsigned long sql_length,
                                  SQL_result_data &sql_res,
                                  SQL_error&);

  virtual int close_database_connection(SQL_error&);
  SQL_SQLite_engine();
  virtual ~SQL_SQLite_engine();
private: 
  typedef enum {utf8=0, utf16=1, v2=2} connection_types;
  connection_types conn_type;
  int busy_retries;
};

  SQL_SQLite_engine::SQL_SQLite_engine(){
    engine=SQLite_engine;
    state=0;
    sql_handle=NULL;
    busy_retries = -1;
    conn_type=utf8;
  }//constructor

  SQL_SQLite_engine::~SQL_SQLite_engine(){
    if(state){
      sqlite3_close(sql_handle);
    }
  }//desructor

  int SQL_SQLite_engine::open_database_connection(const SQL_config_data *
    config_data, SQL_error &err){
    const char *database=NULL;//:memory: (memory db), or empty string "" (tmp file db)
    int flags=0;
    //SQLITE_OPEN_READONLY         0x00000001
    //SQLITE_OPEN_READWRITE        0x00000002
    //SQLITE_OPEN_CREATE           0x00000004
    //SQLITE_OPEN_URI              0x00000040
    //SQLITE_OPEN_MEMORY           0x00000080
    //SQLITE_OPEN_NOMUTEX          0x00008000
    //SQLITE_OPEN_FULLMUTEX        0x00010000
    //SQLITE_OPEN_SHAREDCACHE      0x00020000
    //SQLITE_OPEN_PRIVATECACHE     0x00040000
    const char *zVfs=NULL; //if NULL pointer then the default sqlite3_vfs object
                           //is used ONLY DEFAULT SUPPORTED
    int i=0;
    int open=0;
    
    while(config_data[i].name){
      if(!strcasecmp(config_data[i].name, "database")){
        database = config_data[i].value;
      } else if(!strcasecmp(config_data[i].name, "type")){
        if(!strcasecmp(config_data[i].value, "utf8")){
          conn_type=utf8;
        } else if(!strcasecmp(config_data[i].value, "utf16")){
          conn_type=utf16;
        } else if(!strcasecmp(config_data[i].value, "v2")){
          conn_type=v2;
        }
      } else if(!strcasecmp(config_data[i].name, "flags")){
        flags=atoi(config_data[i].value);
      } else if(!strcasecmp(config_data[i].name, "max_busy_retries")) {
        busy_retries = atoi((const char*)config_data[i].value);
        if(busy_retries < 0) {
          err.error_code=7;
          err.error_text=mprintf("You have to specify positive max_busy_retries parameter.");
          return 1;
        }
      }
    
      ++i;
    }//while
    
    if(database == NULL){
      err.error_code=4;
      err.error_text=mprintf("Database attribute is not specified. eg: file:/home/path/mydb.db");
      return 1;
    }
    
    if(conn_type==utf8){
      open = sqlite3_open(database, &sql_handle);
    } else if(conn_type==utf16){
      open = sqlite3_open16(database, &sql_handle);
    } else if(conn_type==v2){
      open = sqlite3_open_v2(database, &sql_handle, flags, zVfs);
    }
    
    if(open != SQLITE_OK){
      err.error_code=5;
      err.error_text=mprintf("SQLite connection error: %s", 
        sqlite3_errmsg(sql_handle));
      return 1;
    }
    
    sqlite3_extended_result_codes(sql_handle,1);
    state = 1;
    
    return 0;    
  }//open_database_connection
  
  
  int SQL_SQLite_engine::execute_sql_command(const unsigned char *sql,
                                  const unsigned long sql_length,
                                  SQL_result_data &sql_res,
                                  SQL_error &err){
    
    sqlite3_stmt *statement=NULL;
    const char *tail=NULL;
    int ncols=-1;
    int nrows=0;
      
    if(state==0){
      err.error_code=5;
      err.error_text=mprintf("The SQLite engine is not connected to the database. Please connect first.");
      return 1;
    }
    
    if(sqlite3_prepare_v2(sql_handle, (const char*)sql, sql_length, &statement, &tail) == SQLITE_OK){
      ncols = sqlite3_column_count(statement);
      int step = sqlite3_step(statement);

    for(int i = 1; (busy_retries != -1) ? (i <= busy_retries) : true; ++i){
      if(step == SQLITE_DONE){
        sql_res.number_of_rows=sqlite3_changes(sql_handle);
        sql_res.rows=NULL;
        break;
      } // INSERT, UPDATE, DELETE
      else if(step == SQLITE_ROW){
        while(step == SQLITE_ROW){
          nrows++;
          step = sqlite3_step(statement);
        }
      
        sqlite3_reset(statement);
        sql_res.number_of_rows=nrows;
        sql_res.rows=(SQL_row_data *)Malloc(sql_res.number_of_rows*sizeof(SQL_row_data));
        
        for(int i = 0; i < nrows; ++i){
          if((step = sqlite3_step(statement)) != SQLITE_ROW){
            err.error_code = 7;
            err.error_text = mprintf("Step is %d not SQLITE_ROW!", step);
            return 1;
          }
          
          SQL_row_data *row=sql_res.rows+i;
          row->num_of_fields=ncols;
          row->field_data=(SQL_field_data*)Malloc(row->num_of_fields*sizeof(SQL_field_data));

          for(int j = 0; j < ncols; ++j){
            SQL_field_data *act_field=row->field_data+j;
            
            if(i == 0){
              act_field->field_name=mcopystr(sqlite3_column_name(statement,j));
            } else {
              act_field->field_name=NULL;
            }
            
            act_field->data_length=sqlite3_column_bytes(statement, j);
            
            switch(sqlite3_column_type(statement, j)){
              case SQLITE_INTEGER:
                act_field->field_type=int_data;
                act_field->field_data.int_data=sqlite3_column_int(statement, j);
              break;
              case SQLITE_TEXT:
                act_field->field_type=text;
                act_field->field_data.text_binary_data=(unsigned char*)Malloc(act_field->data_length*sizeof(unsigned char));
                memcpy(act_field->field_data.text_binary_data, sqlite3_column_text(statement, j), act_field->data_length);
              break;
              case SQLITE_FLOAT:
                act_field->field_type=real_data;
                act_field->field_data.real_data=sqlite3_column_double(statement, j);
              break;
              case SQLITE_BLOB:
                act_field->field_type=binary_data;
                act_field->field_data.text_binary_data=(unsigned char*)Malloc(act_field->data_length*sizeof(unsigned char));
                memcpy(act_field->field_data.text_binary_data, sqlite3_column_blob(statement, j), act_field->data_length);
              break;
              case SQLITE_NULL:
                act_field->field_type=null_data_value;
              break;
              default:
                err.error_code=7;
                err.error_text=mprintf("Unknown field type");
                sqlite3_finalize(statement);
          return 1;
            };
            
          }//for ncols
        }//for nrows
        break;
      }//if statement has rows (SELECT)
      else if (step == SQLITE_BUSY || step == SQLITE_IOERR_BLOCKED){
        if(busy_retries != -1 && i == busy_retries) {
          err.error_code=7;
          err.error_text=mprintf("Max retry reached. Giving up.");
          return 1;
        }

        if(sqlite3_busy_timeout(sql_handle, i*15)==0){
         step = sqlite3_step(statement);
        }
        log(SQLTP_LOG_WARNING, "Database is busy. %d. retry: %s.",i, sql);
        continue;
      }//if step SQLITE_BUSY
      else {
        err.error_code=7;
        err.error_text=mprintf("Error while query: %d", step);
        sqlite3_finalize(statement);
        return 1;
      }
    }//for true

      sqlite3_finalize(statement);
    } else {
      err.error_code=6;
      if(tail != NULL){
        err.error_text=mprintf("Error with query: %s", tail);
      } else {
        err.error_text=mprintf("Error with query.");
      }

      return 1;
    }

    return 0;
  }//execute_sql_command
  
  
  int SQL_SQLite_engine::close_database_connection(SQL_error &err){
    if(sqlite3_close(sql_handle) == SQLITE_OK){
      state=0;
      return 0;
    }
    
    err.error_code=7;
    err.error_text=mprintf("The database connection is associated with unfinalized prepared statements or unfinished sqlite3_backup objects.");
    
    return 1;
  }//close_database_connection

  SQL_engine_base* new_SQLite_engine(){
     return new SQL_SQLite_engine;
  }
}


