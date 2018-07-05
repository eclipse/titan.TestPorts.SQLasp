%option noyywrap nodefault case-insensitive yylineno nounput
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
//  File:               SQL_parser.l
//  Rev:                R5B
//  Prodnr:             CNL 113 760
//
#include "SQL_parser_.tab.h"
#include "SQL_Functions.hh"
extern int SQL_parser_error(const char *s);
extern char* replace_ENV_VAR(char* s);

%}

CR         [\r]
LF         [\n]
DIGIT      [0-9]
COLON      [:]
SEMICOLON  [;]
CRLF       [\r][\n]
%x COMMENT
%s BETWEEN_MODE


%%

CREATE { return CREATE; }
IF { return IF; }
NOT { return NOT; }
DROP { return DROP; }
TABLE { return TABLE; }
DATABASE { return DATABASE; }

INSERT { return INSERT; }
INTO { return INTO; }
VALUES? { return VALUES; }
UPDATE { return UPDATE; }
SET { return SET; }
DELETE { return DELETE; }
FROM { return FROM; }
WHERE { return WHERE; }
ORDER { return ORDER; }
BY { return BY; }
LIKE { return LIKE; }
BETWEEN { BEGIN BETWEEN_MODE; return BETWEEN; }
<BETWEEN_MODE>AND { BEGIN INITIAL; return AND; }
INT8|BIGINT { return BIGINT; }
AND { return ANDOP; }
OR { return OROP; }
USE { return USE; }
COMMENT { return COMMENT; }
LIMIT { return LIMIT; }

LEADING { return LEADING; }
TRAILING { return TRAILING; }
BOTH { return BOTH; }
FOR { return FOR; }
IN { return IN; }
IS { return IS; }
NULL { return NULLX; }
XOR { return XOR; }
ASC { SQL_parser_lval.strval = strdup(yytext); return ASC; }
DESC { SQL_parser_lval.strval = strdup(yytext); return DESC; }
AUTO_INCREMENT { return AUTO_INCREMENT; } 
AUTOINCREMENT { return AUTOINCREMENT; } 
DEFAULT { return SQLDEFAULT; }
UNIQUE { return UNIQUE; }
PRIMARY { return PRIMARY; }
KEY { return KEY; }
INDEX { return INDEX; }

INTERVAL { return INTERVAL; }
MICROSECOND { SQL_parser_lval.strval = strdup(yytext); return INTERVAL_VALUE; }
SECOND { SQL_parser_lval.strval = strdup(yytext); return INTERVAL_VALUE; }
MINUTE { SQL_parser_lval.strval = strdup(yytext); return INTERVAL_VALUE; }
HOUR { SQL_parser_lval.strval = strdup(yytext);  return INTERVAL_VALUE; }
DAY	{ SQL_parser_lval.strval = strdup(yytext); return INTERVAL_VALUE; }
WEEK { SQL_parser_lval.strval = strdup(yytext); return INTERVAL_VALUE; }
MONTH { SQL_parser_lval.strval = strdup(yytext); return INTERVAL_VALUE; }
QUARTER { SQL_parser_lval.strval = strdup(yytext); return INTERVAL_VALUE; }
YEAR { return YEAR; }
SECOND_MICROSECOND { SQL_parser_lval.strval = strdup(yytext); return INTERVAL_VALUE; }
MINUTE_MICROSECOND { SQL_parser_lval.strval = strdup(yytext); return INTERVAL_VALUE; }
MINUTE_SECOND { SQL_parser_lval.strval = strdup(yytext); return INTERVAL_VALUE; }
HOUR_MICROSECOND { SQL_parser_lval.strval = strdup(yytext); return INTERVAL_VALUE; }
HOUR_SECOND { SQL_parser_lval.strval = strdup(yytext); return INTERVAL_VALUE; }
HOUR_MINUTE { SQL_parser_lval.strval = strdup(yytext); return INTERVAL_VALUE; }
DAY_MICROSECOND { SQL_parser_lval.strval = strdup(yytext); return INTERVAL_VALUE; }
DAY_SECOND { SQL_parser_lval.strval = strdup(yytext); return INTERVAL_VALUE; }
DAY_MINUTE { SQL_parser_lval.strval = strdup(yytext); return INTERVAL_VALUE; }
DAY_HOUR { SQL_parser_lval.strval = strdup(yytext); return INTERVAL_VALUE; }
YEAR_MONTH { SQL_parser_lval.strval = strdup(yytext); return INTERVAL_VALUE; }

BIT { SQL_parser_lval.strval = strdup(yytext); return BIT; }
TINYINT { SQL_parser_lval.strval = strdup(yytext); return TINYINT; }
SMALLINT { SQL_parser_lval.strval = strdup(yytext); return SMALLINT; }
MEDIUMINT { SQL_parser_lval.strval = strdup(yytext); return MEDIUMINT; }
INT { SQL_parser_lval.strval = strdup(yytext); return INT; }
INTEGER { SQL_parser_lval.strval = strdup(yytext); return DTINTEGER; } 
REAL { SQL_parser_lval.strval = strdup(yytext); return REAL; }
DOUBLE { SQL_parser_lval.strval = strdup(yytext); return DOUBLE; }
FLOAT { SQL_parser_lval.strval = strdup(yytext); return DTFLOAT; }
DECIMAL { SQL_parser_lval.strval = strdup(yytext); return DECIMAL; }
NUMERIC { SQL_parser_lval.strval = strdup(yytext); return NUMERIC; }
DATE { SQL_parser_lval.strval = strdup(yytext); return DATE; }
TIME { SQL_parser_lval.strval = strdup(yytext); return TIME; }
TIMESTAMP { SQL_parser_lval.strval = strdup(yytext); return TIMESTAMP; }
DATETIME { SQL_parser_lval.strval = strdup(yytext); return DATETIME; }
CHAR { SQL_parser_lval.strval = strdup(yytext); return DTCHAR; }
VARCHAR { SQL_parser_lval.strval = strdup(yytext); return VARCHAR; }
BINARY { SQL_parser_lval.strval = strdup(yytext); return BINARY; }
VARBINARY { SQL_parser_lval.strval = strdup(yytext); return VARBINARY; }
TINYBLOB { SQL_parser_lval.strval = strdup(yytext); return TINYBLOB; }
BLOB { SQL_parser_lval.strval = strdup(yytext); return BLOB; }
MEDIUMBLOB { SQL_parser_lval.strval = strdup(yytext); return MEDIUMBLOB; }
LONGBLOB { SQL_parser_lval.strval = strdup(yytext); return LONGBLOB; }
TINYTEXT { SQL_parser_lval.strval = strdup(yytext); return TINYTEXT; }
TEXT { SQL_parser_lval.strval = strdup(yytext); return TEXT; } 
MEDIUMTEXT { SQL_parser_lval.strval = strdup(yytext); return MEDIUMTEXT; }
LONGTEXT { SQL_parser_lval.strval = strdup(yytext); return LONGTEXT; }
ENUM { return ENUM; }

-?[0-9]+ { SQL_parser_lval.intval = atoi(yytext); return INTNUM; }
-?[0-9]+"."[0-9]* |
-?"."[0-9]+ |
-?[0-9]+E[-+]?[0-9]+ |
-?[0-9]+"."[0-9]*E[-+]?[0-9]+ |
-?"."[0-9]+E[-+]?[0-9]+ { SQL_parser_lval.floatval = atof(yytext) ;
return APPROXNUM; }

TRUE { SQL_parser_lval.strval = strdup(yytext); return BOOL; }
UNKNOWN { SQL_parser_lval.strval = strdup(yytext); return BOOL; }
FALSE { SQL_parser_lval.strval = strdup(yytext); return BOOL; }

'(\\.|''|[^'\n]|[ \t\r\n])*' |
\"(\\\"|[^"])*\" { SQL_parser_lval.strval = strdup(yytext); return STRING; }
'(\\.|[^'\n])*$ { TTCN_error("Unterminated string %s", yytext); }
\"(\\.|[^"\n])*$ { TTCN_error("Unterminated string %s", yytext); }

X'[0-9A-F]+' |
0X[0-9A-F]+ { SQL_parser_lval.strval = strdup(yytext); return STRING; }

0B[01]+ |
B'[01]+' { SQL_parser_lval.strval = strdup(yytext); return STRING; }

[-+|^&/%*(),.;!] { return yytext[0]; }

"&&" { return ANDOP; }
"||" { return OROP; }
"=" { SQL_parser_lval.strval = strdup(yytext); return COMPARISON; }
">=" { SQL_parser_lval.strval = strdup(yytext); return COMPARISON; }
">" { SQL_parser_lval.strval = strdup(yytext); return COMPARISON; }
"<=" { SQL_parser_lval.strval = strdup(yytext); return COMPARISON; }
"<" { SQL_parser_lval.strval = strdup(yytext); return COMPARISON; }
"!=" |
"<>" { SQL_parser_lval.strval = strdup(yytext); return COMPARISON; }
":=" { return ASSIGN; }


SUBSTR(ING)?/"(" { SQL_parser_lval.strval = strdup(yytext); return FSUBSTRING; }
ASCII/"(" { return FASCII; }
BIN/"(" { return FBIN; }
BIT_LENGTH/"(" { return FBIT_LENGTH; }
CONCAT/"(" { return FCONCAT; }
CURDATE/"(" { return FCURDATE; }
CURRENT_DATE/"(" { return FCURDATE; }
CURRENT_TIME/"(" { return FCURTIME; }
CURTIME/"(" { return FCURTIME; }
DATE/"(" { return FDATE; }
DATE_ADD/"(" { return FDATE_ADD; }
DATE_SUB/"(" { return FDATE_SUB; }
HEX/"(" { return FHEX; }
LCASE/"(" { return FLOWER; }
LOWER/"(" { return FLOWER; }
LENGTH/"(" { return FLENGTH; }
NOW/"(" { return FNOW; }
REVERSE/"(" { return FREVERSE; }
SPACE/"(" { return FSPACE; }
TIME/"(" { return FTIME; }
TRIM/"(" { return FTRIM; }
UHEX/"(" { return FUHEX; }
UPPER/"(" { return FUPPER; }


[A-Za-z][A-Za-z0-9_]* { 
  SQL_parser_lval.strval = strdup(yytext);
  return NAME; 
}

"$""{"?[A-Za-z][A-Za-z0-9_]*"}"? { 
  SQL_parser_lval.strval = strdup(replace_ENV_VAR(yytext));
  return NAME; 
}

`[^`/\\.\r\n]+` {
  SQL_parser_lval.strval = strdup(yytext+1);
  SQL_parser_lval.strval[yyleng-2] = 0;
  return NAME; 
}

`[^`\r\n]*$ { TTCN_error("Unterminated quoted name %s", yytext); }

@[0-9a-z_.$]+ |
@\"[^"\n]+\" |
@`[^`\n]+` |
@'[^'\n]+'  { SQL_parser_lval.strval = strdup(yytext+1); return USERVAR; }

@\"[^"\n]*$ { TTCN_error("Unterminated quoted user variable %s", yytext); }
@`[^`\n]*$  { TTCN_error("Unterminated quoted user variable %s", yytext); }
@'[^'\n]*$  { TTCN_error("Unterminated quoted user variable %s", yytext); }

#.* ;
"--"[ \t].* ;
"\/*" { BEGIN COMMENT; }
<COMMENT>"*\/" { BEGIN INITIAL; }
<COMMENT>.|{CR}*{LF} ; 
<COMMENT><<EOF>> { SQL_parser_error("Unclosed comment."); }

[ \t\r\n] {}
. { 
  CHARSTRING msg("Mistery token: ");
  msg += yytext;
  
  SQL_parser_error(msg);  
}

%%

