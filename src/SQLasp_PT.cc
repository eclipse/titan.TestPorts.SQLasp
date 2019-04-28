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
//  File:               SQLasp_PT.cc
//  Description:        SQL test port source
//  Rev:                R6A
//  Prodnr:             CNL 113 760
// 



#include "SQLasp_PT.hh"
#include "SQL_interface.hh"
#include <stdarg.h>

namespace SQL_engine{

SQL_engine_register& getregister(){
static SQL_engine_register if1_v;
return if1_v;
}

SQL_registrator::SQL_registrator(){
}

SQL_registrator::SQL_registrator(const SQL_Engine_register_data* v){
  SQL_engine_register& if1_list=getregister();
  if1_list.add_engine(v);
}

void SQL_engine_register::add_engine(const SQL_Engine_register_data* i){
  length++;
  list=(const SQL_Engine_register_data**)Realloc(list,sizeof(SQL_Engine_register_data*)*length);
  list[length-1]=i;
  
}

SQL_engine_register::~SQL_engine_register(){
  Free(list);
}


void SQL_engine_base::log(log_severity sev,const char *fmt, ...){
  va_list args;
  switch(sev){
    case SQLTP_LOG_ERROR:{
         va_start(args, fmt);
         char *error_str = mprintf_va_list(fmt, args);
         va_end(args);
         try {
           TTCN_error("SQLasp test port: %s", error_str);
         } catch (...) {
           Free(error_str);
           throw;
         }
         Free(error_str);
      }
      break;
    case SQLTP_LOG_WARNING:
      TTCN_Logger::begin_event(TTCN_Logger::TTCN_WARNING);
      TTCN_Logger::log_event_str("SQLasp test port: warning: ");
      va_start(args, fmt);
      TTCN_Logger::log_event_va_list(fmt, args);
      va_end(args);
      TTCN_Logger::end_event();
      break;
    case SQLTP_LOG_DEBUG:
      if(debug_enabled){
        TTCN_Logger::begin_event(TTCN_Logger::DEBUG_TESTPORT);
        TTCN_Logger::log_event_str("SQLasp test port: debug: ");
        va_start(args, fmt);
        TTCN_Logger::log_event_va_list(fmt, args);
        va_end(args);
        TTCN_Logger::end_event();
      }
      break;
  }
}

} // namespace SQL_engine

using namespace SQL_engine;

namespace SQL__PortTypes {

SQLasp__PT::SQLasp__PT(const char *par_port_name)
	: SQLasp__PT_BASE(par_port_name)
{
  conn_length=0;
  conn_num=0;
  connections=NULL;
  for(int i=0; i<(DEFINED_ENGINES+1); i++){
    engine_indexes[i]=-1;
  }
  debug_enabled=false;

}

SQLasp__PT::~SQLasp__PT()
{
  Free(connections);
}

void SQLasp__PT::set_parameter(const char * /*parameter_name*/,
	const char * /*parameter_value*/)
{

}

/*void SQLasp__PT::Handle_Fd_Event(int fd, boolean is_readable,
	boolean is_writable, boolean is_error) {}*/

void SQLasp__PT::Handle_Fd_Event_Error(int /*fd*/)
{

}

void SQLasp__PT::Handle_Fd_Event_Writable(int /*fd*/)
{

}

void SQLasp__PT::Handle_Fd_Event_Readable(int /*fd*/)
{

}

/*void SQLasp__PT::Handle_Timeout(double time_since_last_call) {}*/

void SQLasp__PT::user_map(const char * /*system_port*/)
{
  debug_enabled=TTCN_Logger::log_this_event(TTCN_Logger::DEBUG_TESTPORT);  
  log(SQLTP_LOG_DEBUG,"SQLasp__PT::user_map");
  SQL_engine_register& reg=getregister();
  log(SQLTP_LOG_DEBUG,"Number of registered engines: %d", reg.length);

  for(int i=0; i<reg.length; i++){
    if(reg.list){
      engine_types eng= reg.list[i]->engine;
      engine_indexes[eng]=i;
      log(SQLTP_LOG_DEBUG,"Engine type: %d, index %d", eng,i);
    }
  }
  log(SQLTP_LOG_DEBUG,"SQLasp__PT::user_map finished");
}

void SQLasp__PT::user_unmap(const char * /*system_port*/)
{
  log(SQLTP_LOG_DEBUG,"SQLasp__PT::user_unmap");
  for(int i=0;i<conn_length;i++){
    if(connections[i]!=NULL){
      delete connections[i];
      connections[i]=NULL;
    }
  }
  conn_num=0;
  log(SQLTP_LOG_DEBUG,"SQLasp__PT::user_unmap finished");
  
}

void SQLasp__PT::user_start()
{

}

void SQLasp__PT::user_stop()
{

}

void SQLasp__PT::outgoing_call(const S__SQL__connect_call& call_par)
{
  int eng_idx=(int)call_par.pl__conn().engine();
  if(engine_indexes[eng_idx]==-1){
    SQL__exception ex;
    ex.error__code()=1;
    ex.error__text()=CHARSTRING("Engine (" )+ CHARSTRING(SQL__engine__type::enum_to_str(call_par.pl__conn().engine()))+ CHARSTRING(") is not available");
    S__SQL__connect_exception cex=S__SQL__connect_exception(ex);
    incoming_exception(cex);
    return;
  }
  int par_lentgh=call_par.pl__conn().parameters().lengthof();
  SQL_config_data* config_data=(SQL_config_data*)Malloc((par_lentgh+1)*sizeof(SQL_config_data));
  for(int i=0;i<par_lentgh;i++){
    config_data[i].name=(const char*)call_par.pl__conn().parameters()[i].param__name();
    config_data[i].value=(const char*)call_par.pl__conn().parameters()[i].param__value();
  }
  config_data[par_lentgh].name=NULL;
  config_data[par_lentgh].value=NULL;
  SQL_engine_register& reg=getregister();
  SQL_engine_base* new_eng=(*reg.list[engine_indexes[eng_idx]]->new_func)();
  new_eng->debug_enabled=TTCN_Logger::log_this_event(TTCN_Logger::DEBUG_TESTPORT);
  int conn_idx=-1;
  if(conn_length>=(conn_num+1)){
    for(int i=0;i<conn_length;i++){
      if(connections[i]==NULL){
        conn_idx=i;
        break;
      }
    }
  } else {
    conn_idx=conn_length;
    conn_length++;
    connections=(SQL_engine_base**)Realloc(connections,conn_length*sizeof(SQL_engine_base*));
  }
  connections[conn_idx]=new_eng;
  conn_num++;
  SQL_error err;
  if(!(new_eng->open_database_connection(config_data,err))){
    S__SQL__connect_reply reply;
    SQL__Result& reply_value=reply.return_value();
    reply_value.connId()=conn_idx;
    reply_value.result__code()=SQL__Result__Code::SQL__OK;
    incoming_reply(reply);
  } else {
    SQL__exception ex;
    ex.error__code()=err.error_code;
    ex.error__text()=CHARSTRING(err.error_text);
    Free(err.error_text);
    S__SQL__connect_exception cex=S__SQL__connect_exception(ex);
    incoming_exception(cex);
    delete connections[conn_idx];
    connections[conn_idx]=NULL;
    conn_num--;
  }
  Free(config_data);
  return;
  
}

void SQLasp__PT::outgoing_call(const S__SQL__Query_call& call_par)
{
  int conn_id=call_par.connId();
  if(conn_id==-1){
    SQL__exception ex;
    ex.error__code()=2;
    ex.error__text()=CHARSTRING("The connection id (" )+ int2char(call_par.connId()) + CHARSTRING(") does not exist.");
    S__SQL__Query_exception cex=S__SQL__Query_exception(ex);
    incoming_exception(cex);
    return;
  }
  TTCN_Buffer utf8_query;
  call_par.pl__query().encode_utf8(utf8_query);
  // add null terminator
  utf8_query.put_c('\0');
  SQL_result_data res;
  SQL_error err;
  if(!(connections[conn_id]->execute_sql_command(utf8_query.get_data(),
                                                 utf8_query.get_len()-1,
                                                 res,err))){
    S__SQL__Query_reply reply;
    SQL__Query__result& q_res=reply.return_value();;
    q_res.connId()=conn_id;
    q_res.affected__rows()=res.number_of_rows;
    if(res.rows){
      q_res.data()()=NULL_VALUE;
      for(int i=res.number_of_rows-1;i>=0;i--){
        SQL__Query__Result__row& act_row=q_res.data()()[i];
        act_row=NULL_VALUE;
        SQL_row_data& res_row=res.rows[i];
        for(int k=res_row.num_of_fields-1;k>=0;k--){
          SQL__Query__Result__field& act_field=act_row[k];
          SQL_field_data& res_field=res_row.field_data[k];
          if(res_field.field_name){
            act_field.field__name()=res_field.field_name;
            Free(res_field.field_name);
          } else {
            act_field.field__name()=OMIT_VALUE;
          }
          switch(res_field.field_type){
            case null_data_value:
              act_field.field__data()().null__value()=NULL_VALUE;
              break;
            case bitstring_data:{
              int oct_num=(int)(res_field.data_length+7)/8;
              act_field.field__data()().bitstring__data()=substr(oct2bit(OCTETSTRING(oct_num,res_field.field_data.text_binary_data)),(oct_num*8)-res_field.data_length,res_field.data_length);
              Free(res_field.field_data.text_binary_data);
              }
              break;
            case binary_data:
              act_field.field__data()().binary__data()=OCTETSTRING(res_field.data_length,res_field.field_data.text_binary_data);
              Free(res_field.field_data.text_binary_data);
              break;
            case real_data:
              act_field.field__data()().real__data()=res_field.field_data.real_data;
              break;
            case int_data:
              act_field.field__data()().int__data().set_long_long_val(res_field.field_data.int_data);
              break;
            case text:
              act_field.field__data()().text().decode_utf8(res_field.data_length,res_field.field_data.text_binary_data);
              Free(res_field.field_data.text_binary_data);
              break;
          }
        }
        Free(res_row.field_data);
      }
      Free(res.rows);
    } else {
      q_res.data()=OMIT_VALUE;
    }
    incoming_reply(reply);
  } else {
    SQL__exception ex;
    ex.error__code()=err.error_code;
    ex.error__text()=CHARSTRING(err.error_text);
    Free(err.error_text);
    S__SQL__Query_exception cex=S__SQL__Query_exception(ex);
    incoming_exception(cex);
  }
  
  return;
}

void SQLasp__PT::outgoing_call(const S__SQL__disconnect_call& call_par)
{
  int conn_id=call_par.connId();
  if(conn_id==-1){
    SQL__exception ex;
    ex.error__code()=2;
    ex.error__text()=CHARSTRING("The connection id (" )+ int2char(call_par.connId()) + CHARSTRING(") does not exist.");
    S__SQL__disconnect_exception cex=S__SQL__disconnect_exception(ex);
    incoming_exception(cex);
    return;
  }
  SQL_error err;
  connections[conn_id]->close_database_connection(err);
  delete connections[conn_id];
  connections[conn_id]=NULL;
  conn_num--;

  S__SQL__disconnect_reply reply;
  SQL__Result& reply_value=reply.return_value();
  reply_value.connId()=conn_id;
  reply_value.result__code()=SQL__Result__Code::SQL__OK;
  incoming_reply(reply);
  return;

}

int SQLasp__PT::conn_id_validator(int id){
  int ret_val=-1;
  if(( id==-1) && (conn_num==1)){
    for(int i=0;i<conn_length;i++){
      if(connections[i]!=NULL) {
        ret_val=i;
        break;
      }
    }
  } else if((id>=0) && (id<conn_length) && (connections[id]!=NULL)){
        ret_val=id;
  }
  return ret_val;
}
void SQLasp__PT::log(log_severity sev,const char *fmt, ...){
  va_list args;
  switch(sev){
    case SQLTP_LOG_ERROR:{
         va_start(args, fmt);
         char *error_str = mprintf_va_list(fmt, args);
         va_end(args);
         try {
           TTCN_error("SQLasp test port: %s", error_str);
         } catch (...) {
           Free(error_str);
           throw;
         }
         Free(error_str);
      }
      break;
    case SQLTP_LOG_WARNING:
      TTCN_Logger::begin_event(TTCN_Logger::TTCN_WARNING);
      TTCN_Logger::log_event_str("SQLasp test port: warning: ");
      va_start(args, fmt);
      TTCN_Logger::log_event_va_list(fmt, args);
      va_end(args);
      TTCN_Logger::end_event();
      break;
    case SQLTP_LOG_DEBUG:
      if(debug_enabled){
        TTCN_Logger::begin_event(TTCN_Logger::DEBUG_TESTPORT);
        TTCN_Logger::log_event_str("SQLasp test port: debug: ");
        va_start(args, fmt);
        TTCN_Logger::log_event_va_list(fmt, args);
        va_end(args);
        TTCN_Logger::end_event();
      }
      break;
  }
}

} /* end of namespace */

