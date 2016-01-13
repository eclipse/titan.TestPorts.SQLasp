/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_SQL_PARSER_SQL_PARSER_TAB_H_INCLUDED
# define YY_SQL_PARSER_SQL_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int SQL_parser_debug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    END = 0,
    EOL = 258,
    NAME = 259,
    STRING = 260,
    USERVAR = 261,
    ASC = 262,
    DESC = 263,
    BOOL = 264,
    INTERVAL_VALUE = 265,
    BIGINT = 266,
    INTNUM = 267,
    APPROXNUM = 268,
    OR = 269,
    ANDOP = 270,
    NOT = 271,
    BETWEEN = 272,
    MOD = 273,
    COMPARISON = 274,
    ASSIGN = 275,
    INSERT = 276,
    INTO = 277,
    VALUES = 278,
    UPDATE = 279,
    SET = 280,
    DELETE = 281,
    FROM = 282,
    WHERE = 283,
    LIKE = 284,
    AND = 285,
    OROP = 286,
    USE = 287,
    ORDER = 288,
    BY = 289,
    LIMIT = 290,
    COMMENT = 291,
    CREATE = 292,
    DROP = 293,
    TABLE = 294,
    DATABASE = 295,
    LEADING = 296,
    TRAILING = 297,
    BOTH = 298,
    FOR = 299,
    IN = 300,
    IS = 301,
    IF = 302,
    NULLX = 303,
    XOR = 304,
    AUTO_INCREMENT = 305,
    AUTOINCREMENT = 306,
    SQLDEFAULT = 307,
    UNIQUE = 308,
    PRIMARY = 309,
    KEY = 310,
    INDEX = 311,
    INTERVAL = 312,
    BIT = 313,
    TINYINT = 314,
    SMALLINT = 315,
    MEDIUMINT = 316,
    INT = 317,
    DTINTEGER = 318,
    REAL = 319,
    DOUBLE = 320,
    DTFLOAT = 321,
    DECIMAL = 322,
    NUMERIC = 323,
    DATE = 324,
    TIME = 325,
    TIMESTAMP = 326,
    DATETIME = 327,
    DTCHAR = 328,
    VARCHAR = 329,
    BINARY = 330,
    VARBINARY = 331,
    TINYBLOB = 332,
    BLOB = 333,
    MEDIUMBLOB = 334,
    LONGBLOB = 335,
    TINYTEXT = 336,
    TEXT = 337,
    MEDIUMTEXT = 338,
    LONGTEXT = 339,
    ENUM = 340,
    YEAR = 341,
    FASCII = 342,
    FBIN = 343,
    FBIT_LENGTH = 344,
    FCONCAT = 345,
    FCURDATE = 346,
    FCURTIME = 347,
    FDATE_ADD = 348,
    FDATE_SUB = 349,
    FHEX = 350,
    FLOWER = 351,
    FLENGTH = 352,
    FNOW = 353,
    FREVERSE = 354,
    FSPACE = 355,
    FTRIM = 356,
    FUHEX = 357,
    FUPPER = 358,
    FDATE = 359,
    FTIME = 360,
    token = 361,
    FSUBSTRING = 362,
    UMINUS = 363
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 49 "SQL_parser.y" /* yacc.c:1909  */

  int intval;
  double floatval;
  long long int bigint;
  char *strval;

#line 171 "SQL_parser_.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE SQL_parser_lval;

int SQL_parser_parse (void);

#endif /* !YY_SQL_PARSER_SQL_PARSER_TAB_H_INCLUDED  */
