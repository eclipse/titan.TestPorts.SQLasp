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
//  File:               SQL_interface.hh
//  Description:        SQL test port source
//  Rev:                R6A
//  Prodnr:             CNL 113 760
// 

#include <stdlib.h>

namespace SQL_engine{
class SQL_engine_base;

typedef SQL_engine_base* (*new_engine_func)();

typedef enum { No_Engine=0,SQLite_engine=1,MySQL_engine=2,OraSQL_engine=3} engine_types;

class SQL_Engine_register_data {
public:
  engine_types engine;
  new_engine_func new_func;
  
  SQL_Engine_register_data(engine_types eng,new_engine_func fc){
    engine=eng;
    new_func=fc;
  }
} ;

typedef struct {
  int error_code;
  char* error_text;
} SQL_error;

typedef struct {
  const char* name;
  const char* value;
} SQL_config_data;


typedef enum {text, int_data,real_data,binary_data,bitstring_data,null_data_value} SQL_field_type;

typedef union {
  long long int int_data;
  unsigned char* text_binary_data;
  double real_data;
} SQL_field_data_union;

typedef struct {
  SQL_field_type       field_type;
  char*                field_name;
  int                  data_length;
  SQL_field_data_union field_data;
} SQL_field_data;

typedef struct {
  int num_of_fields;
  SQL_field_data* field_data;
} SQL_row_data;

typedef struct {
  int number_of_rows;
  SQL_row_data *rows;
} SQL_result_data;


class SQL_engine_base{
public:
  enum log_severity { SQLTP_LOG_DEBUG, SQLTP_LOG_WARNING, SQLTP_LOG_ERROR};
  
  
  engine_types engine;
  bool debug_enabled;
  void log(log_severity,const char *fmt, ...)
    __attribute__ ((__format__ (__printf__, 3, 4)));
  virtual int open_database_connection(const SQL_config_data*, SQL_error&)=0;
  virtual int execute_sql_command(const unsigned char* sql, 
                                  const unsigned long sql_length,
                                  SQL_result_data& sql_res,
                                  SQL_error&)=0;
  virtual int close_database_connection(SQL_error&)=0;
  SQL_engine_base(){engine=No_Engine;debug_enabled=false;}
  SQL_engine_base(engine_types eng){engine=eng;debug_enabled=false;}
  virtual ~SQL_engine_base(){}
};

class SQL_registrator{
public:
  SQL_registrator();
  SQL_registrator(const SQL_Engine_register_data* v);
  ~SQL_registrator(){};
};

class SQL_engine_register{
public:
  int length;
  const SQL_Engine_register_data** list;
  void add_engine(const SQL_Engine_register_data *);
  SQL_engine_register(){length=0;list=NULL;}
  ~SQL_engine_register();
};

}

