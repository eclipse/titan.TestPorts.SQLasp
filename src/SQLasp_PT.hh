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
//  File:               SQLasp_PT.hh
//  Description:        SQL test port source
//  Rev:                R6A
//  Prodnr:             CNL 113 760
// 


#ifndef SQLasp__PT_HH
#define SQLasp__PT_HH

#include "SQL_PortTypes.hh"
#define DEFINED_ENGINES 3

namespace SQL_engine{
class SQL_engine_base;
}


namespace SQL__PortTypes {

class SQLasp__PT : public SQLasp__PT_BASE {
public:
	SQLasp__PT(const char *par_port_name = NULL);
	~SQLasp__PT();

	void set_parameter(const char *parameter_name,
		const char *parameter_value);

private:
  enum log_severity { SQLTP_LOG_DEBUG, SQLTP_LOG_WARNING, SQLTP_LOG_ERROR};
  bool debug_enabled;
  void log(log_severity,const char *fmt, ...)
    __attribute__ ((__format__ (__printf__, 3, 4)));
  int engine_indexes[DEFINED_ENGINES+1];

  int conn_length;
  int conn_num;
  SQL_engine::SQL_engine_base** connections;
  
  int conn_id_validator(int);

	void Handle_Fd_Event_Error(int fd);
	void Handle_Fd_Event_Writable(int fd);
	void Handle_Fd_Event_Readable(int fd);

protected:
	void user_map(const char *system_port);
	void user_unmap(const char *system_port);

	void user_start();
	void user_stop();

	void outgoing_call(const S__SQL__connect_call& call_par);
	void outgoing_call(const S__SQL__Query_call& call_par);
	void outgoing_call(const S__SQL__disconnect_call& call_par);
};

} /* end of namespace */

#endif
