%error-verbose
%{
/******************************************************************************
* Copyright (c) 2000-2018 Ericsson Telecom AB
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
//  File:               SQL_parser.y
//  Rev:                R6A
//  Prodnr:             CNL 113 760
//  Updated:            2014-06-04
//
#include <stdio.h>
#include <iostream>
#include "SQL_Functions.hh"
#include "SQL_PortTypes.hh"
#define YYDEBUG 1
int yyerror(const char *s);
char* replace_ENV_VAR(char*);
extern int yylex();
extern FILE* SQL_parser_in;

using namespace SQL__PortTypes;
using namespace SQL__Functions;

SQLasp__PT *sql_port;
SQL__Rollback__Queries *rollback_queries;
const SQL__Primary__Keys *primary_keys;
SQL__Query__Result__Record *result_record;
SQL__Query original_query;
SQL__Query select_query;
SQL__Query select_query_after;
BOOLEAN sql_exception_received;

INTEGER conn_id;
UNIVERSAL_CHARSTRING current_table;


%}

%union {
  int intval;
  double floatval;
  long long int bigint;
  char *strval;
}

%token END 0
%token EOL

%token <strval> NAME STRING USERVAR ASC DESC BOOL INTERVAL_VALUE
%token <bigint> BIGINT
%token <intval> INTNUM
%token <floatval> APPROXNUM
%left OR ANDOP NOT BETWEEN '|' '&' '+' '-' '*' '/' '%' MOD '^'
%left <strval> COMPARISON /* && || = >= > <= < != <> */
%right ASSIGN

%token INSERT INTO VALUES UPDATE SET DELETE FROM WHERE LIKE BETWEEN AND OROP USE ORDER BY LIMIT

%token COMMENT CREATE DROP TABLE DATABASE

%token LEADING TRAILING BOTH FOR IN IS IF NOT NULLX XOR AUTO_INCREMENT AUTOINCREMENT SQLDEFAULT UNIQUE PRIMARY KEY INDEX

/* interval_expression */
%token INTERVAL

/* data_types (SET previously declared) */
%token <strval> BIT TINYINT SMALLINT MEDIUMINT INT DTINTEGER REAL DOUBLE DTFLOAT DECIMAL NUMERIC DATE TIME TIMESTAMP DATETIME DTCHAR VARCHAR BINARY VARBINARY TINYBLOB BLOB MEDIUMBLOB LONGBLOB TINYTEXT TEXT MEDIUMTEXT LONGTEXT
%token ENUM YEAR

/* functions */
%token FASCII FBIN FBIT_LENGTH FCONCAT FCURDATE FCURTIME FDATE_ADD FDATE_SUB FHEX FLOWER FLENGTH FNOW FREVERSE FSPACE FTRIM FUHEX FUPPER FDATE FTIME
token <strval> FSUBSTRING

%type <strval> expression optional_asc_desc table_reference value_list optional_value_list trim_ltb interval_expression interval_value_list optional_where
%type <strval> optional_orderby orderby_list optional_limit expression_list 
%type <strval> optional_column_attributes column_list optional_length enum_list data_type create_definition create_column_list


%nonassoc UMINUS

%start statement_list


%%

statement_list: /*empty*/
  | statement ';'                {  }
  | statement_list statement ';' {  }
;

statement: delete_statement {
    SQL__Functions::SQL__Rollback__Parameters parameters(conn_id, select_query, original_query, *primary_keys, current_table);

    SQL__Functions::f__getRollback__Delete(*sql_port, parameters, *rollback_queries,  *result_record, sql_exception_received); 
  
  }
  | insert_statement {
    SQL__Functions::SQL__Rollback__Parameters parameters(conn_id, select_query, original_query, *primary_keys, current_table);
    
    SQL__Functions::f__getRollback__Insert(*sql_port, parameters, select_query_after, *rollback_queries, *result_record, sql_exception_received);
  }
  | update_statement { 
    SQL__Functions::SQL__Rollback__Parameters parameters(conn_id, select_query, original_query, *primary_keys, current_table);

    SQL__Functions::f__getRollback__Update(*sql_port, parameters, *rollback_queries,  *result_record, sql_exception_received); 
  }
  | create_database_statement { /* do the miracle in the statement */ }
  | create_table_statement { /* do the miracle in the statement */ } 
;

create_table_statement: CREATE TABLE NAME '(' create_column_list ')' { 
    SQL__Query query = SQL__Query("CREATE TABLE");
    int rollback_index = (*rollback_queries).size_of();
    int result_index = (*result_record).size_of();
    SQL__Query__result result;
    SQL__exception e;

    query = query + " " + $3 + "(" + $5 + ");";
    
    if(f__query(*sql_port, conn_id, query, result, e)) {
      (*result_record)[result_index] = result;
      (*rollback_queries)[rollback_index] = SQL__Query("DROP TABLE ") + $3 + ";";
    } else {sql_exception_received = true;};
    
    free($3); free($5);
  }
  | CREATE TABLE NAME '.' NAME '(' create_column_list ')' { 
    SQL__Query query = SQL__Query("CREATE TABLE");
    int rollback_index = (*rollback_queries).size_of();
    int result_index = (*result_record).size_of();
    SQL__Query__result result;
    SQL__exception e;

    query = query + " " + $3 + "." + $5 + "(" + $7 + ");";
  
    if(f__query(*sql_port, conn_id, query, result, e)) {
      (*result_record)[result_index] = result;
      (*rollback_queries)[rollback_index] = SQL__Query("DROP TABLE ") + $3 + "." + $5;
    } else {sql_exception_received = true;};
  
   free($3); free($5); free($7);
 }
;

create_column_list : create_definition {
    $$ = $1;
  }
  | create_column_list ',' create_definition {
    char buffer[1024];
    sprintf(buffer, "%s, %s", $1, $3);
    $$ = strdup(buffer);
    free($1); free($3);
  }
;

create_definition: PRIMARY KEY '(' column_list ')' {  
    char buffer[128];
    sprintf(buffer, "PRIMARY KEY (%s)", $4);
    $$ = strdup(buffer);
    free($4);
  }
  | KEY '(' column_list ')' {
    char buffer[128];
    sprintf(buffer, "KEY (%s)", $3);
    $$ = strdup(buffer);
    free($3);
  }
  | INDEX '(' column_list ')' {
    char buffer[128];
    sprintf(buffer, "INDEX (%s)", $3);
    $$ = strdup(buffer);
    free($3);
  }
  | NAME data_type optional_column_attributes {
    char buffer[128];
    sprintf(buffer, "%s %s %s", $1, $2, $3);
    $$ = strdup(buffer);
    free($1); free($2); free($3);
  }
;

data_type: BIT optional_length {
    char buffer[128];
    sprintf(buffer, "%s %s", $1, $2);
    $$ = strdup(buffer);
    free($1); free($2);
  }
  | TINYINT optional_length {
    char buffer[128];
    sprintf(buffer, "%s %s", $1, $2);
    $$ = strdup(buffer);
    free($1); free($2);
  }
  | SMALLINT optional_length {
    char buffer[128];
    sprintf(buffer, "%s %s", $1, $2);
    $$ = strdup(buffer);
    free($1); free($2);
  }
  | MEDIUMINT optional_length {
    char buffer[128];
    sprintf(buffer, "%s %s", $1, $2);
    $$ = strdup(buffer);
    free($1); free($2);
  }
  | INT optional_length {
    char buffer[128];
    sprintf(buffer, "%s %s", $1, $2);
    $$ = strdup(buffer);
    free($1); free($2);
  }
  | DTINTEGER optional_length {
    char buffer[128];
    sprintf(buffer, "%s %s", $1, $2);
    $$ = strdup(buffer);
    free($1); free($2);
  }
  | BIGINT optional_length {
    char buffer[128];
    sprintf(buffer, "BIGINT %s", $2);
    $$ = strdup(buffer);
    free($2);
  } 
  | REAL optional_length {
    char buffer[128];
    sprintf(buffer, "%s %s", $1, $2);
    $$ = strdup(buffer);
    free($1); free($2);
  }
  | DOUBLE optional_length {
    char buffer[128];
    sprintf(buffer, "%s %s", $1, $2);
    $$ = strdup(buffer);
    free($1); free($2);
  }
  | DTFLOAT optional_length {
    char buffer[128];
    sprintf(buffer, "%s %s", $1, $2);
    $$ = strdup(buffer);
    free($1); free($2);
  }
  | DECIMAL optional_length {
    char buffer[128];
    sprintf(buffer, "%s %s", $1, $2);
    $$ = strdup(buffer);
    free($1); free($2);
  }
  | NUMERIC optional_length {
    char buffer[128];
    sprintf(buffer, "%s %s", $1, $2);
    $$ = strdup(buffer);
    free($1); free($2);
  }
  | DATE { $$ = $1; }
  | TIME { $$ = $1; }
  | TIMESTAMP { $$ = $1; }
  | DATETIME { $$ = $1; }
  | YEAR { $$ = strdup("YEAR"); }
  | DTCHAR optional_length {
    char buffer[128];
    sprintf(buffer, "%s %s", $1, $2);
    $$ = strdup(buffer);
    free($1); free($2);
  }
  | VARCHAR optional_length {
    char buffer[128];
    sprintf(buffer, "%s %s", $1, $2);
    $$ = strdup(buffer);
    free($1); free($2);
  }
  | BINARY optional_length {
    char buffer[128];
    sprintf(buffer, "%s %s", $1, $2);
    $$ = strdup(buffer);
    free($1); free($2);
  }
  | VARBINARY optional_length {
    char buffer[128];
    sprintf(buffer, "%s %s", $1, $2);
    $$ = strdup(buffer);
    free($1); free($2);
  }
  | TINYBLOB { $$ = $1; }
  | BLOB { $$ = $1; }
  | MEDIUMBLOB { $$ = $1; }
  | LONGBLOB { $$ = $1; }
  | TINYTEXT { $$ = $1; }
  | TEXT { $$ = $1; }
  | MEDIUMTEXT { $$ = $1; }
  | LONGTEXT { $$ = $1; }
  | ENUM enum_list {
    char buffer[1024];
    sprintf(buffer, "ENUM %s", $2);
    $$ = strdup(buffer);
    free($2);
  }
  | SET enum_list {
    char buffer[1024];
    sprintf(buffer, "SET %s", $2);
    $$ = strdup(buffer);
    free($2);
  }
;

enum_list: STRING { $$ = $1; }
  | enum_list ',' STRING {
    char buffer[1024];
    sprintf(buffer, "%s, %s", $1, $3);
    $$ = strdup(buffer);
    free($1); free($3);
  }

optional_length: /* optional */ { $$ = strdup(""); }
  | '(' INTNUM ')' {
    char buffer[64];
    sprintf(buffer, "(%d)", $2);
    $$ = strdup(buffer);
  }
  | '(' INTNUM ',' INTNUM ')' {
    char buffer[64];
    sprintf(buffer, "(%d,%d)", $2, $4);
    $$ = strdup(buffer);
  }
;

column_list: NAME { $$ = $1; }
  | column_list ',' NAME {
    char buffer[1024];
    sprintf(buffer, "%s, %s", $1, $3);
    $$ = strdup(buffer);
    free($1); free($3);
  }
;

optional_column_attributes: /* optional */ { $$ = strdup(""); } 
  | optional_column_attributes NOT NULLX {
    char buffer[1024];
    sprintf(buffer, "%s NOT NULL", $1);
    $$ = strdup(buffer);
    free($1);
  }
  | optional_column_attributes NULLX { 
    char buffer[1024];
    sprintf(buffer, "%s NULL", $1);
    $$ = strdup(buffer);
    free($1); 
  }
  | optional_column_attributes SQLDEFAULT STRING {
    char buffer[1024];
    sprintf(buffer, "%s DEFAULT %s", $1, $3);
    $$ = strdup(buffer);
    free($1); free($3);
  }
  | optional_column_attributes SQLDEFAULT INTNUM {
    char buffer[1024];
    sprintf(buffer, "%s DEFAULT %d", $1, $3);
    $$ = strdup(buffer);
    free($1);
  }
  | optional_column_attributes SQLDEFAULT APPROXNUM {
    char buffer[1024];
    sprintf(buffer, "%s DEFAULT %f", $1, $3);
    $$ = strdup(buffer);
    free($1);
  }
  | optional_column_attributes SQLDEFAULT BOOL {
    char buffer[1024];
    sprintf(buffer, "%s DEFAULT %s", $1, $3);
    $$ = strdup(buffer);
    free($1); free($3);
  }
  | optional_column_attributes AUTO_INCREMENT { 
    char buffer[1024];
    sprintf(buffer, "%s AUTO_INCREMENT", $1);
    $$ = strdup(buffer);
    free($1);
  } 
  | optional_column_attributes AUTOINCREMENT { 
    char buffer[1024];
    sprintf(buffer, "%s AUTOINCREMENT", $1);
    $$ = strdup(buffer);
    free($1);
  } 
  | optional_column_attributes UNIQUE {
    char buffer[1024];
    sprintf(buffer, "%s UNIQUE", $1);
    $$ = strdup(buffer);
    free($1);
  }
  | optional_column_attributes UNIQUE KEY {
    char buffer[1024];
    sprintf(buffer, "%s UNIQUE KEY", $1);
    $$ = strdup(buffer);
    free($1);
  }
  | optional_column_attributes PRIMARY KEY {
    char buffer[1024];
    sprintf(buffer, "%s PRIMARY KEY", $1);
    $$ = strdup(buffer);
    free($1);
  }
  | optional_column_attributes KEY {
    char buffer[1024];
    sprintf(buffer, "%s KEY", $1);
    $$ = strdup(buffer);
    free($1);
  }
  | optional_column_attributes COMMENT STRING {
    char buffer[1024];
    sprintf(buffer, "%s COMMENT %s", $1, $3);
    $$ = strdup(buffer);
    free($1); free($3);
  }
;
  
  
create_database_statement: CREATE DATABASE NAME {
  SQL__Query query = SQL__Query("CREATE DATABASE");
  int rollback_index = (*rollback_queries).size_of();
  int result_index = (*result_record).size_of();
  SQL__Query__result result;
  SQL__exception e;

  query = query + " " + $3 + ";";
  
  if(f__query(*sql_port, conn_id, query, result, e)) {
    (*result_record)[result_index] = result;
    (*rollback_queries)[rollback_index] = SQL__Query("DROP DATABASE ") + $3 + ";";
  } else {sql_exception_received = true;};
  
  free($3);
}
;

/* only single table format supported */ 
update_statement: UPDATE table_reference SET expression_list optional_where optional_orderby optional_limit {
  current_table = UNIVERSAL_CHARSTRING($2);
  original_query = SQL__Query("UPDATE ") + current_table + " SET " + $4;
  select_query = SQL__Query("SELECT * FROM ") + current_table;
  if(strcmp($5, "") != 0) {
    original_query = original_query + " " + $5;
    select_query = select_query + " " + $5;
  }
  if(strcmp($6, "") != 0) {
    original_query = original_query + " " + $6;
    select_query = select_query + " " + $6;
  }
  if(strcmp($7, "") != 0) {
    original_query = original_query + " " + $7;
    select_query = select_query + " " + $7;
  }
  
  free($2); free($4); free($5); free($6); free($7);
}
;

expression_list: NAME COMPARISON expression {
    char buffer[1024];
    sprintf(buffer, "%s %s %s", $1, $2, $3);
    $$ = strdup(buffer);
    free($1); free($2); free($3);
  }
  | NAME COMPARISON SQLDEFAULT {
    char buffer[1024];
    sprintf(buffer, "%s %s DEFAULT", $1, $2);
    $$ = strdup(buffer);
    free($1); free($2);
  }
  | expression_list ',' NAME COMPARISON expression {
    char buffer[2048];
    sprintf(buffer, "%s, %s %s %s", $1, $3, $4, $5);
    $$ = strdup(buffer);
    free($1); free($3); free($4); free($5); 
  }
  | expression_list ',' NAME COMPARISON SQLDEFAULT {
    char buffer[2048];
    sprintf(buffer, "%s, %s %s DEFAULT", $1, $3, $4);
    $$ = strdup(buffer);
    free($1); free($3); free($4);
  }
;
 
insert_statement: INSERT INTO table_reference '(' value_list ')' VALUES '(' value_list ')' {
  current_table = UNIVERSAL_CHARSTRING($3);
  CharstringList column_list = SQL__Functions::f__SQL__split($5, ",");
  CharstringList value_list = SQL__Functions::f__SQL__split($9, ",");
  
  original_query = SQL__Query("INSERT INTO ") + current_table + "(" + $5 + ") VALUES (" + $9 + ")";
  select_query = SQL__Query("SELECT ") + f__getPrimary__key(*primary_keys, current_table) + " FROM " + current_table + " ORDER BY 1 ASC";
  select_query_after = SQL__Query("SELECT ") + f__getPrimary__key(*primary_keys, current_table) + 
    " FROM " + current_table + " " + SQL__Functions::f__SQL__getWHERE(column_list, value_list) + 
    " ORDER BY 1 ASC";

  free($3); free($5); free($9);
}
  | INSERT INTO table_reference VALUES '(' value_list ')' {
    current_table = UNIVERSAL_CHARSTRING($3);
    original_query = SQL__Query("INSERT INTO ") + current_table + " VALUES (" + $6 + ")";
    select_query = SQL__Query("SELECT ") + f__getPrimary__key(*primary_keys, current_table) + " FROM " + current_table + " ORDER BY 1 ASC";
    select_query_after = select_query;
    free($3); free($6);
  }
;

/* only single table format supported */
delete_statement: DELETE FROM table_reference optional_where optional_orderby optional_limit {
  current_table = UNIVERSAL_CHARSTRING($3);
  original_query = SQL__Query("DELETE FROM ") + current_table;
  select_query = SQL__Query("SELECT * FROM ") + current_table;
  
  if(strcmp($4, "") != 0) {
    original_query = original_query + " " + $4;
    select_query = select_query + " " + $4;
  }
  if(strcmp($5, "") != 0) {
    original_query = original_query + " " + $5;
    select_query = select_query + " " + $5;
  }
  if(strcmp($6, "") != 0) {
    original_query = original_query + " " + $6;
    select_query = select_query + " " + $6;
  }
  
  original_query = original_query + ";";
  select_query = select_query + ";";
  
  free($3); free($4); free($5); free($6);
}
;

optional_where: /* optional */ { $$ = strdup(""); }
  | WHERE expression {
    CHARSTRING where = CHARSTRING("WHERE ") + $2;
    $$ = strdup(where);
    free($2);
  }
;

optional_orderby: /* optional */ { $$ = strdup(""); }
  | ORDER BY orderby_list {
    CHARSTRING orderby = CHARSTRING("ORDER BY ") + $3;
    $$ = strdup(orderby);
    free($3);
  }
;

orderby_list: expression optional_asc_desc {
    CHARSTRING list = CHARSTRING($1) + " " + $2;
    $$ = strdup(list);
    free($1); free($2);
  }
  | orderby_list ',' expression optional_asc_desc {
    CHARSTRING list = CHARSTRING($1) + "," + $3;
    if(strcmp($4, "") != 0) {
      list = list + " " + $4;
    }
    $$ = strdup(list);
    free($1); free($3); free($4);
  }
;

table_reference: NAME { $$ = $1; }
  | NAME '.' NAME {
    CHARSTRING table_reference = CHARSTRING($1) + "." + $3;
    $$ = strdup(table_reference);
    free($1); free($3);
  }
;

optional_asc_desc: /* default: ASC */ { $$ = strdup(""); }
  | ASC  { $$ = $1; }
  | DESC { $$ = $1; }
;

optional_limit: /* optional */ { $$ = strdup(""); }
  | LIMIT INTNUM {
    CHARSTRING limit = CHARSTRING("LIMIT ") + int2str($2);
    $$ = strdup(limit);
  }// LIMIT INTNUM
;

expression: '(' expression ')' {
    CHARSTRING tmp = CHARSTRING("(") + $2 + ")";
    $$ = strdup(tmp);
    free($2);
  }
  | NAME { $$ = $1; }
  | NAME '.' NAME { 
    CHARSTRING name = CHARSTRING($1) + "." + $3;
    $$ = strdup(name);
    free($1); free($3);
  }
  
  | USERVAR { $$ = $1; }
  | STRING 	{ 
  		$$ = replace_ENV_VAR($1);
		free($1);
  	}	
  | INTNUM { 
    $$ = strdup(int2str($1));
  }
  | BIGINT { 
    char buffer[32];
    sprintf(buffer, "%lld", $1);
    $$ = strdup(buffer);
  }
  | APPROXNUM {
    $$ = strdup(float2str($1));
  }
  | BOOL { $$ = $1; }
  | NULLX { $$ = strdup("NULL"); }
;

expression: expression '+' expression { 
      CHARSTRING tmp = CHARSTRING($1) + "+" + $3;
      $$ = strdup(tmp); 
      free($1); free($3);
    }
  | expression '-' expression { 
    CHARSTRING tmp = CHARSTRING($1) + "-" + $3;
    $$ = strdup(tmp); 
    free($1); free($3);
  }
  | expression '*' expression {
    CHARSTRING tmp = CHARSTRING($1) + "*" + $3;
    $$ = strdup(tmp); 
    free($1); free($3);
  }
  | expression '/' expression { 
    CHARSTRING tmp = CHARSTRING($1) + "/" + $3;
    $$ = strdup(tmp); 
    free($1); free($3);
  }
  | expression '%' expression {
    CHARSTRING tmp = CHARSTRING($1) + "%" + $3;
    $$ = strdup(tmp); 
    free($1); free($3);
  }
  | expression MOD expression {
    CHARSTRING tmp = CHARSTRING($1) + " MOD " + $3;
    $$ = strdup(tmp); 
    free($1); free($3);
  }
  | '-' expression %prec UMINUS {
    CHARSTRING tmp = CHARSTRING("-") + $2;
    $$ = strdup(tmp); 
    free($2);
  }
  | expression ANDOP expression {
    CHARSTRING tmp = CHARSTRING($1) + " AND " + $3;
    $$ = strdup(tmp); 
    free($1); free($3);
  }
  | expression OROP expression {
    CHARSTRING tmp = CHARSTRING($1) + " OR " + $3;
    $$ = strdup(tmp); 
    free($1); free($3);
  }
  | expression XOR expression {
    CHARSTRING tmp = CHARSTRING($1) + " XOR " + $3;
    $$ = strdup(tmp); 
    free($1); free($3);
  }
  | NOT expression {
    CHARSTRING tmp = CHARSTRING("NOT ") + $2;
    $$ = strdup(tmp); 
    free($2);
  }
  | '!' expression {
    CHARSTRING tmp = CHARSTRING("! ") + $2;
    $$ = strdup(tmp); 
    free($2);
  }
  | expression COMPARISON expression {
    CHARSTRING tmp = CHARSTRING($1) + " " + $2 + " " + $3;
    $$ = strdup(tmp); 
    free($1); free($2); free($3);
  }
  | expression LIKE expression {
    CHARSTRING tmp = CHARSTRING($1) + " LIKE " + $3;
    $$ = strdup(tmp);
    free($1); free($3);
  } 
;

expression: expression IS NULLX {
    CHARSTRING tmp = CHARSTRING($1) + " IS NULL";
    $$ = strdup(tmp);
    free($1);
  }
  | expression IS NOT NULLX {
    CHARSTRING tmp = CHARSTRING($1) + " IS NOT NULL";
    $$ = strdup(tmp);
    free($1);
  }
  | expression IS BOOL {
    CHARSTRING tmp = CHARSTRING($1) + " IS " + $3; 
    $$ = strdup(tmp);
    free($1); free($3);
  }
  | expression IS NOT BOOL {
    CHARSTRING tmp = CHARSTRING($1) + " IS NOT " + $4;
    $$ = strdup(tmp);
    free($1); free($4);
  } 
  | USERVAR ASSIGN expression {
    char buffer[2048];
    sprintf(buffer, "@%s := %s", $1, $3);
    $$ = strdup(buffer);
    free($1); free($3);
  }
;

expression: expression BETWEEN expression AND expression %prec BETWEEN {
  char buffer[2048];
  sprintf(buffer, "%s BETWEEN %s AND %s", $1, $3, $5);
  $$ = strdup(buffer);
  free($1); free($3); free($5);
}
;

value_list: expression { $$ = $1; }
  | expression ',' value_list {
    CHARSTRING tmp = CHARSTRING($1) + "," + CHARSTRING($3);
    $$ = strdup(tmp);
    free($1); free($3);
  }
;

optional_value_list: /* optional */ { $$ = strdup(""); }
  |  value_list { $$ = $1; }
;

expression: expression IN '(' value_list ')' {
  CHARSTRING tmp = CHARSTRING($1) + " IN (" + $4 + ")";
  $$ = strdup(tmp);
  free($1); free($4);
}
  | expression NOT IN '(' value_list ')' {
    CHARSTRING tmp = CHARSTRING($1) + " NOT IN (" + $5 + ")";
    $$ = strdup(tmp);
    free($1); free($5);
  }
;

/* FUNCTIONS */
expression: NAME '(' optional_value_list ')' {
  char buffer[2048];
  sprintf(buffer, "%s(%s)", $1, $3);
  $$ = strdup(buffer);
  free($1); free($3);
}
;

expression: FSUBSTRING '(' value_list ')' {
    char buffer[1024];
    sprintf(buffer, "%s(%s)", $1, $3);
    $$ = strdup(buffer);
    free($1); free($3);
  }
  | FSUBSTRING '(' expression FROM expression ')' { 
    char buffer[2048];
    sprintf(buffer, "%s(%s FROM %s)", $1, $3, $5);
    $$ = strdup(buffer);
    free($1); free($3); free($5);
  }
  | FSUBSTRING '(' expression FROM expression FOR expression ')' {
    char buffer[2048];
    sprintf(buffer, "%s(%s FROM %s FOR %s)", $1, $3, $5, $7);
    $$ = strdup(buffer);
    free($1); free($3); free($5); free($7);
  }
;

expression: FTRIM '(' value_list ')' {
    char buffer[1024];
    sprintf(buffer, "TRIM(%s)", $3);
    $$ = strdup(buffer);
    free($3);
  }
  | FTRIM '(' trim_ltb expression FROM value_list ')' {
    char buffer[1024];
    sprintf(buffer, "TRIM(%s %s FROM %s)", $3, $4, $6);
    $$ = strdup(buffer);
    free($3); free($4); free($6);
  }
;

trim_ltb: LEADING       { $$ = strdup("LEADING"); }
        | TRAILING      { $$ = strdup("TRAILING"); }
        | BOTH          { $$ = strdup("BOTH"); }
  
expression: FDATE_ADD '(' expression ',' interval_expression ')' {
    char buffer[2048];
    sprintf(buffer, "DATE_ADD(%s, %s)", $3, $5);
    $$ = strdup(buffer);
    free($3); free($5);
  }
  | FDATE_SUB '(' expression ',' interval_expression ')' {
    char buffer[2048];
    sprintf(buffer, "DATE_SUB(%s, %s)", $3, $5);
    $$ = strdup(buffer);
    free($3); free($5);
  }
;

interval_expression: INTERVAL expression interval_value_list {
    char buffer[128];
    sprintf(buffer, "INTERVAL %s %s", $2, $3);
    $$ = strdup(buffer);
    free($2); free($3);
  }
;

interval_value_list: INTERVAL_VALUE {
    $$ = $1;
  }
  | YEAR { $$ = strdup("YEAR"); }
;

expression: FASCII '(' expression ')' {
    char buffer[1024];
    sprintf(buffer, "ASCII(%s)", $3);
    $$ = strdup(buffer);
    free($3);
  }
;

expression: FBIN '(' expression ')' {
    char buffer[1024];
    sprintf(buffer, "BIN(%s)", $3);
    $$ = strdup(buffer);
    free($3);
  }
;

expression: FBIT_LENGTH '(' expression ')' {
    char buffer[1024];
    sprintf(buffer, "BIT_LENGTH(%s)", $3);
    $$ = strdup(buffer);
    free($3);
  }
;

expression: FCONCAT '(' expression ')' {
    char buffer[1024];
    sprintf(buffer, "CONCAT(%s)", $3);
    $$ = strdup(buffer);
    free($3);
  }
;

expression: FCURDATE "()" { $$ = strdup("CURDATE()"); }
;

expression: FCURTIME "()" { $$ = strdup("CURTIME()"); }
;

expression: FDATE '(' expression ')' {
  char buffer[1024];
  sprintf(buffer, "DATE(%s)", $3);
  $$ = strdup(buffer);
  free($3);
}
;

expression: FHEX '(' expression ')' {
    char buffer[1024];
    sprintf(buffer, "HEX(%s)", $3);
    $$ = strdup(buffer);
    free($3);
  }
;

expression: FLOWER '(' expression ')' {
    char buffer[1024];
    sprintf(buffer, "LOWER(%s)", $3);
    $$ = strdup(buffer);
    free($3);
  }
;

expression: FLENGTH '(' expression ')' {
    char buffer[1024];
    sprintf(buffer, "LENGTH(%s)", $3);
    $$ = strdup(buffer);
    free($3);
  }
;

expression: FNOW '(' ')' { $$ = strdup("NOW()"); }
;

expression: FREVERSE '(' expression ')' {
    char buffer[1024];
    sprintf(buffer, "REVERSE(%s)", $3);
    $$ = strdup(buffer);
    free($3);
  }
;

expression: FSPACE '(' expression ')' {
    char buffer[1024];
    sprintf(buffer, "SPACE(%s)", $3);
    $$ = strdup(buffer);
    free($3);
  }
;

expression: FTIME '(' expression ')' {
  char buffer[1024];
  sprintf(buffer, "TIME(%s)", $3);
  $$ = strdup(buffer);
  free($3);
}
;

expression: FTRIM '(' expression ')' {
  char buffer[1024];
  sprintf(buffer, "TRIM(%s)", $3);
  $$ = strdup(buffer);
  free($3);
}
;

expression: FUHEX '(' expression ')' {
  char buffer[1024];
  sprintf(buffer, "UHEX(%s)", $3);
  $$ = strdup(buffer);
  free($3);
}
;

expression: FUPPER '(' expression ')' {
  char buffer[1024];
  sprintf(buffer, "UPPER(%s)", $3);
  $$ = strdup(buffer);
  free($3);
}
;


 

%%

INTEGER SQL__Functions::ef__SQL__strcmp(const CHARSTRING& pl__string1, const CHARSTRING& pl__string2) {
  return strcmp(pl__string1, pl__string2);
}//ef__SQL__strcmp


char* replace_ENV_VAR(char* string){
	CHARSTRING result;
	CHARSTRING evar_name;
	char* var;
	char* temp;
	char* value;
	int len;
  char* temp2=NULL;
	
	temp = strstr(string, "$");
	if(temp == NULL){ 
		return strdup(string); //No enviroment variable
	} else {
		result = CHARSTRING(temp-string,string);
		temp++; //skip '$' sign
		
		//Check if the env var is in ${..} format
		if(strncmp(temp,"{",1) == 0){
			
			var = ++temp; //skip '{' sign
			temp = strstr(string, "}"); 
			
			//check the end of the variable
			if(temp != NULL){
				evar_name = CHARSTRING(temp - var, var);
				var = getenv(evar_name);

				if(var != NULL){
					temp++; //skip '}' sign
					//insert value and check for next variable(if present)
					result += CHARSTRING(var)+CHARSTRING(temp2=replace_ENV_VAR(temp));
          free(temp2);
				} else {
					//Enviroment variable was not found
					TTCN_warning("No enviroment variable with name: %s", (const char*)evar_name);
					//skip the undefined variable and search for the next (if present)
					result += CHARSTRING(2,"${")+CHARSTRING(evar_name)+CHARSTRING(temp2=replace_ENV_VAR(temp));
          free(temp2);
				};
			} else {
				//'${' found, but no } => possibly not an enviroment variable
				//search for next variable (if present)
				result += CHARSTRING(2,"${")+CHARSTRING(temp2=replace_ENV_VAR(var));
        free(temp2);
			};
		
		//variable is in $... format 
		} else {
			var = temp;
			len = (int)strlen(temp);
			
			//search for the end of the variable name
			for(int i = 0; i<len; i++){
				if( strncmp(temp," ",1) == 0 || 
					strncmp(temp,",",1) == 0 ||
					strncmp(temp,"'",1) == 0 ||
					strncmp(temp,"\"",1)== 0 
				){
					//get value
					evar_name = CHARSTRING(temp - var, var);
					value = getenv(evar_name);
					
					if(value != NULL){
						//insert value and check for next variable(if present)
						result += CHARSTRING(value)+CHARSTRING(temp2=replace_ENV_VAR(temp));
            free(temp2);
						break;
					} else {
						//Enviroment variable was not found
						TTCN_warning("No enviroment variable with name: %s", (const char*)evar_name);
						//search for next variable (if present)
						result += CHARSTRING(1,"$")+CHARSTRING(evar_name)+CHARSTRING(temp2=replace_ENV_VAR(temp));
            free(temp2);
						break;
					};
				};
				temp++;
				
				//end of string, check if variable name
				if(i == len - 1){
					//get value
					evar_name = CHARSTRING(temp - var, var);
					value = getenv(evar_name);
					
					if(value != NULL){
						result += CHARSTRING(value);
					} else {
						//Enviroment variable was not found
						TTCN_warning("No enviroment variable with name: %s", (const char*)evar_name);
						result += CHARSTRING(1,"$")+CHARSTRING(evar_name);
					};
				};
			};// for
		};
	};
	
	return strdup((const char*)result);
}

BOOLEAN SQL__Functions::ef__SQL__Execute (const CHARSTRING& pl__sql__file, 
                                          SQLasp__PT& pl__sqlPort,
                                          const INTEGER& pl__connId,
                                          const SQL__Primary__Keys& pl__primary__keys,
                                          SQL__Rollback__Queries& pl__result,
                                          SQL__Query__Result__Record& pl__result__record) {
  
  pl__result = NULL_VALUE;
  pl__result__record = NULL_VALUE;
  rollback_queries = &pl__result;
  primary_keys = &pl__primary__keys;
  conn_id = pl__connId;
  sql_port = &pl__sqlPort;  
  result_record = &pl__result__record;
  sql_exception_received = BOOLEAN(false);

  if((SQL_parser_in = fopen((const char*)pl__sql__file, "r")) == NULL) {
    TTCN_error("SQL parser can not open %s",  (const char*)pl__sql__file);
  }
  bool parse_result = !yyparse();
  
  if(sql_exception_received){ return false; }
  return parse_result;
}//ef__SQL__Execute

int yyerror(const char *s) {
  extern int SQL_parser_lineno;
  TTCN_warning("Syntax error or unsupported expression: %s - %d\n",s, SQL_parser_lineno);
  return 0;
}
