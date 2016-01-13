/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         SQL_parser_parse
#define yylex           SQL_parser_lex
#define yyerror         SQL_parser_error
#define yydebug         SQL_parser_debug
#define yynerrs         SQL_parser_nerrs

#define yylval          SQL_parser_lval
#define yychar          SQL_parser_char

/* Copy the first part of user declarations.  */
#line 2 "SQL_parser.y" /* yacc.c:339  */

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
//  File:               SQL_parser.y
//  Rev:                R5B
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



#line 121 "SQL_parser_.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "SQL_parser_.tab.h".  */
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
#line 49 "SQL_parser.y" /* yacc.c:355  */

  int intval;
  double floatval;
  long long int bigint;
  char *strval;

#line 278 "SQL_parser_.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE SQL_parser_lval;

int SQL_parser_parse (void);

#endif /* !YY_SQL_PARSER_SQL_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 293 "SQL_parser_.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1166

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  124
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  158
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  345

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   364

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   122,     2,     2,     2,    24,    19,     2,
     118,   119,    22,    20,   121,    21,   120,    23,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   117,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    26,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    18,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    25,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   123
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    96,    96,    97,    98,   101,   107,   112,   117,   118,
     121,   137,   155,   158,   166,   172,   178,   184,   192,   198,
     204,   210,   216,   222,   228,   234,   240,   246,   252,   258,
     264,   265,   266,   267,   268,   269,   275,   281,   287,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   307,   315,
     316,   323,   324,   329,   336,   337,   345,   346,   352,   358,
     364,   370,   376,   382,   388,   394,   400,   406,   412,   418,
     427,   446,   467,   473,   479,   485,   493,   506,   516,   541,
     542,   549,   550,   557,   562,   572,   573,   580,   581,   582,
     585,   586,   592,   597,   598,   604,   605,   609,   612,   617,
     620,   621,   624,   629,   634,   639,   644,   649,   654,   659,
     664,   669,   674,   679,   684,   689,   696,   701,   706,   711,
     716,   724,   732,   733,   740,   741,   744,   749,   757,   765,
     771,   777,   785,   791,   799,   800,   801,   803,   809,   817,
     825,   828,   831,   839,   847,   855,   863,   866,   869,   877,
     885,   893,   901,   904,   912,   920,   928,   936,   944
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "END", "error", "$undefined", "EOL", "NAME", "STRING", "USERVAR", "ASC",
  "DESC", "BOOL", "INTERVAL_VALUE", "BIGINT", "INTNUM", "APPROXNUM", "OR",
  "ANDOP", "NOT", "BETWEEN", "'|'", "'&'", "'+'", "'-'", "'*'", "'/'",
  "'%'", "MOD", "'^'", "COMPARISON", "ASSIGN", "INSERT", "INTO", "VALUES",
  "UPDATE", "SET", "DELETE", "FROM", "WHERE", "LIKE", "AND", "OROP", "USE",
  "ORDER", "BY", "LIMIT", "COMMENT", "CREATE", "DROP", "TABLE", "DATABASE",
  "LEADING", "TRAILING", "BOTH", "FOR", "IN", "IS", "IF", "NULLX", "XOR",
  "AUTO_INCREMENT", "AUTOINCREMENT", "SQLDEFAULT", "UNIQUE", "PRIMARY",
  "KEY", "INDEX", "INTERVAL", "BIT", "TINYINT", "SMALLINT", "MEDIUMINT",
  "INT", "DTINTEGER", "REAL", "DOUBLE", "DTFLOAT", "DECIMAL", "NUMERIC",
  "DATE", "TIME", "TIMESTAMP", "DATETIME", "DTCHAR", "VARCHAR", "BINARY",
  "VARBINARY", "TINYBLOB", "BLOB", "MEDIUMBLOB", "LONGBLOB", "TINYTEXT",
  "TEXT", "MEDIUMTEXT", "LONGTEXT", "ENUM", "YEAR", "FASCII", "FBIN",
  "FBIT_LENGTH", "FCONCAT", "FCURDATE", "FCURTIME", "FDATE_ADD",
  "FDATE_SUB", "FHEX", "FLOWER", "FLENGTH", "FNOW", "FREVERSE", "FSPACE",
  "FTRIM", "FUHEX", "FUPPER", "FDATE", "FTIME", "token", "FSUBSTRING",
  "UMINUS", "';'", "'('", "')'", "'.'", "','", "'!'", "\"()\"", "$accept",
  "statement_list", "statement", "create_table_statement",
  "create_column_list", "create_definition", "data_type", "enum_list",
  "optional_length", "column_list", "optional_column_attributes",
  "create_database_statement", "update_statement", "expression_list",
  "insert_statement", "delete_statement", "optional_where",
  "optional_orderby", "orderby_list", "table_reference",
  "optional_asc_desc", "optional_limit", "expression", "value_list",
  "optional_value_list", "trim_ltb", "interval_expression",
  "interval_value_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   124,    38,
      43,    45,    42,    47,    37,   273,    94,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,    59,    40,    41,
      46,    44,    33,   364
};
# endif

#define YYPACT_NINF -170

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-170)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      80,   -27,     3,    -7,    15,   108,   -85,  -170,  -170,  -170,
    -170,  -170,     3,   -97,    10,     3,    50,    53,  -170,   -48,
    -170,   -26,    75,    91,    71,   -98,  -170,  -170,     0,   300,
    -170,    83,   -28,   300,    70,    36,   112,   300,   -94,  -170,
      96,  -170,  -170,  -170,  -170,   300,   300,  -170,     9,    18,
      21,    23,     8,    20,    26,    27,    28,    29,    30,    31,
      43,    47,    51,    58,    65,    66,    67,    68,   300,   300,
     404,    35,   242,   167,    70,  1109,   145,   147,   971,   130,
      76,    77,   -75,  -170,    78,    79,   300,   193,   300,   948,
     -12,   300,   300,   300,   300,  -170,  -170,   300,   300,   300,
     300,   300,    81,   300,   300,   117,   300,   300,   300,   300,
     300,   524,  1109,   300,   146,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,    84,    40,   300,   300,   170,
    -170,  1109,   176,   147,   300,   192,  -170,    87,   201,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
    -170,  -170,  -170,  -170,    87,    87,    87,    87,  -170,  -170,
    -170,  -170,  -170,  -170,  -170,  -170,   201,  -170,  -170,    89,
     204,   204,  -170,    36,    36,  -170,  -170,    92,  -170,   -12,
     549,   592,   617,   642,   429,   454,   667,   692,   717,  -170,
     742,   767,  -170,  -170,  -170,    -6,   114,   300,   792,   817,
     842,   867,   135,   115,  -170,   948,   113,   917,   948,   948,
     948,   948,   948,   948,   -12,  1109,  1109,   300,  -170,    -3,
    -170,  1109,  -170,   118,   271,  -170,   116,  1059,  -170,   198,
    -170,  -170,   120,  -170,  -170,  -170,  -170,  -170,  -170,  -170,
    -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,   120,   119,
     204,  -170,   -69,   -16,  -170,   -15,  -170,  -170,  -170,  -170,
    -170,   173,   173,  -170,  -170,  -170,  -170,  -170,  -170,  -170,
    1084,  -170,  -170,  -170,  -170,   300,  -170,   300,   300,   121,
    -170,  -170,   300,  -170,  1109,   300,  -170,  -170,  -170,    -2,
     238,   188,   244,  -170,  -170,  -170,    25,   187,   194,  -170,
      13,  -170,   255,  -170,  -170,   300,   141,   142,   300,   479,
     143,   948,  -170,   148,  1059,  -170,   252,  -170,  -170,  -170,
    -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,   942,  -170,
    -170,   149,   300,  -170,  -170,  -170,  -170,   151,  -170,  -170,
    -170,  -170,   892,  -170,  -170
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     0,     0,     0,     0,     9,     8,     7,
       6,     5,     0,    85,     0,     0,     0,     0,     1,     0,
       3,     0,     0,     0,    79,     0,    70,     4,     0,     0,
      86,     0,    79,     0,    81,     0,     0,     0,    93,    96,
      95,   100,    98,    97,    99,     0,     0,   101,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     122,     0,     0,     0,    81,    80,     0,    90,     0,     0,
       0,     0,     0,    12,     0,     0,   124,     0,     0,   112,
     108,     0,     0,     0,     0,   146,   147,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   113,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      73,    72,     0,    90,     0,     0,    78,    51,     0,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      30,    31,    32,    33,    51,    51,    51,    51,    39,    40,
      41,    42,    43,    44,    45,    46,     0,    34,    56,     0,
       0,     0,    10,     0,     0,    77,   125,     0,    94,   120,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   152,
       0,     0,   134,   135,   136,     0,     0,     0,     0,     0,
       0,     0,   122,     0,    92,   109,     0,     0,   102,   103,
     104,   105,   106,   107,   114,   115,   110,     0,   118,     0,
     116,   111,   123,     0,     0,    71,    82,    87,    91,     0,
      24,    49,    48,    18,    19,    20,    21,    22,    23,    25,
      26,    27,    28,    29,    35,    36,    37,    38,    47,    17,
       0,    54,     0,     0,    13,     0,   128,   142,   143,   144,
     145,     0,     0,   149,   150,   151,   153,   154,   156,   132,
       0,   157,   158,   148,   155,     0,   129,     0,     0,     0,
     119,   117,     0,    75,    74,     0,    88,    89,    83,     0,
       0,     0,     0,    58,    63,    64,     0,    65,     0,    68,
       0,    15,     0,    16,    11,     0,     0,     0,     0,     0,
       0,   121,   126,     0,    87,    52,     0,    50,    57,    69,
      59,    62,    60,    61,    66,    67,    14,    55,     0,   137,
     138,     0,     0,   130,   127,    76,    84,     0,   140,   141,
     139,   133,     0,    53,   131
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -170,  -170,   260,  -170,    97,    93,  -170,   107,   873,  -169,
    -170,  -170,  -170,  -170,  -170,  -170,   246,   205,  -170,   -11,
     -29,   153,   -33,    -8,  -170,  -170,    19,  -170
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,    82,    83,   168,   232,   230,   252,
     249,     8,     9,    32,    10,    11,    34,    77,   226,    14,
     288,   136,    70,    71,   177,   197,   306,   340
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      75,    21,   253,    12,    24,    28,   280,    13,    33,   113,
     114,   115,    89,    90,   116,   117,   118,   119,   120,   121,
      35,   122,    36,    22,    86,   123,    87,   124,    15,    85,
     320,   123,    20,   124,   321,   111,   112,   322,   323,   131,
      78,   125,   126,    23,   172,   127,   173,   125,   126,   218,
     301,   127,   302,   281,    25,   179,   219,    26,   180,   181,
     182,   183,    16,    17,   184,   185,   186,   187,   188,    27,
     190,   191,   195,   198,   199,   200,   201,   202,   176,    30,
     205,   300,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,    29,    73,   221,    31,   220,   196,    79,    80,
      81,   227,   203,   303,   304,   302,   173,    33,    18,     1,
      72,    76,     2,   268,     3,   128,    84,   315,    37,   316,
     222,    38,    39,    40,    88,     4,    41,    91,    42,    43,
      44,    95,   326,    45,   302,   291,    92,     1,    46,    93,
       2,    94,     3,    96,    97,    98,    99,   100,   101,   102,
     113,   114,   115,     4,   129,   116,   117,   118,   119,   120,
     121,   103,   122,   292,   270,   104,   192,   193,   194,   105,
     275,   132,   123,    47,   124,   293,   106,   294,   295,   296,
     297,   298,   299,   107,   108,   109,   110,   134,   125,   126,
     135,   284,   127,   169,   170,   171,   174,   178,   175,   206,
     189,   223,   217,   224,   228,   229,   231,   250,   251,   279,
     289,   256,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,   277,    67,   269,   276,    68,   282,   285,   305,    69,
     312,   290,   309,   317,   318,   311,    38,    39,    40,   319,
     324,    41,   314,    42,    43,    44,   128,   325,    45,   327,
     329,   330,   334,    46,   337,    19,   254,   335,   341,   310,
     343,   255,   328,   248,   313,    38,    39,    40,    74,   133,
      41,   307,    42,    43,    44,   336,   225,    45,     0,     0,
       0,     0,    46,     0,     0,     0,     0,     0,    47,   342,
     331,     0,   130,     0,    38,    39,    40,     0,     0,    41,
       0,    42,    43,    44,     0,     0,    45,     0,     0,     0,
       0,    46,     0,     0,     0,     0,     0,    47,     0,     0,
       0,   283,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    47,    67,     0,     0,
      68,     0,     0,     0,    69,     0,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,     0,    67,     0,     0,    68,
       0,     0,     0,    69,     0,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,     0,    67,     0,     0,    68,   113,
     114,   115,    69,     0,   116,   117,   118,   119,   120,   121,
       0,   122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   123,     0,   124,   113,   114,   115,     0,     0,   116,
     117,   118,   119,   120,   121,     0,   122,   125,   126,     0,
       0,   127,     0,     0,     0,     0,   123,     0,   124,   113,
     114,   115,     0,     0,   116,   117,   118,   119,   120,   121,
       0,   122,   125,   126,     0,     0,   127,     0,     0,     0,
       0,   123,     0,   124,   113,   114,   115,     0,     0,   116,
     117,   118,   119,   120,   121,     0,   122,   125,   126,     0,
       0,   127,     0,     0,     0,     0,   123,     0,   124,     0,
       0,     0,     0,     0,     0,   128,     0,     0,     0,     0,
       0,   332,   125,   126,     0,     0,   127,     0,     0,   113,
     114,   115,     0,     0,   116,   117,   118,   119,   120,   121,
     261,   122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   123,     0,   124,   113,   114,   115,     0,     0,   116,
     117,   118,   119,   120,   121,   262,   122,   125,   126,     0,
       0,   127,     0,     0,     0,     0,   123,     0,   124,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   333,     0,
       0,     0,   125,   126,     0,     0,   127,   113,   114,   115,
       0,     0,   116,   117,   118,   119,   120,   121,     0,   122,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   123,
       0,   124,   113,   114,   115,     0,     0,   116,   117,   118,
     119,   120,   121,   204,   122,   125,   126,     0,     0,   127,
       0,     0,     0,     0,   123,     0,   124,   113,   114,   115,
       0,     0,   116,   117,   118,   119,   120,   121,   257,   122,
     125,   126,     0,     0,   127,     0,     0,     0,     0,   123,
       0,   124,   113,   114,   115,     0,     0,   116,   117,   118,
     119,   120,   121,     0,   122,   125,   126,     0,     0,   127,
       0,     0,     0,     0,   123,     0,   124,   113,   114,   115,
       0,   258,   116,   117,   118,   119,   120,   121,     0,   122,
     125,   126,     0,     0,   127,     0,     0,     0,     0,   123,
       0,   124,   113,   114,   115,     0,   259,   116,   117,   118,
     119,   120,   121,     0,   122,   125,   126,     0,     0,   127,
       0,     0,     0,     0,   123,     0,   124,   113,   114,   115,
       0,   260,   116,   117,   118,   119,   120,   121,     0,   122,
     125,   126,     0,     0,   127,     0,     0,     0,     0,   123,
       0,   124,   113,   114,   115,     0,   263,   116,   117,   118,
     119,   120,   121,     0,   122,   125,   126,     0,     0,   127,
       0,     0,     0,     0,   123,     0,   124,   113,   114,   115,
       0,   264,   116,   117,   118,   119,   120,   121,     0,   122,
     125,   126,     0,     0,   127,     0,     0,     0,     0,   123,
       0,   124,   113,   114,   115,     0,   265,   116,   117,   118,
     119,   120,   121,     0,   122,   125,   126,     0,     0,   127,
       0,     0,     0,     0,   123,     0,   124,   113,   114,   115,
       0,   266,   116,   117,   118,   119,   120,   121,     0,   122,
     125,   126,     0,     0,   127,     0,     0,     0,     0,   123,
       0,   124,   113,   114,   115,     0,   267,   116,   117,   118,
     119,   120,   121,     0,   122,   125,   126,     0,     0,   127,
       0,     0,     0,     0,   123,     0,   124,   113,   114,   115,
       0,   271,   116,   117,   118,   119,   120,   121,     0,   122,
     125,   126,     0,     0,   127,     0,     0,     0,     0,   123,
       0,   124,   113,   114,   115,     0,   272,   116,   117,   118,
     119,   120,   121,     0,   122,   125,   126,     0,     0,   127,
       0,     0,   338,     0,   123,   278,   124,   113,   114,   115,
       0,   273,   116,   117,   118,   119,   120,   121,     0,   122,
     125,   126,     0,     0,   127,   122,     0,     0,     0,   123,
       0,   124,   137,     0,     0,   123,   274,   124,     0,     0,
       0,     0,     0,     0,     0,   125,   126,     0,     0,   127,
       0,   125,   126,     0,   138,   127,     0,     0,     0,     0,
       0,   344,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,     0,     0,     0,     0,   244,   245,   246,
     247,     0,     0,     0,     0,     0,   339,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   286,   287,     0,     0,
       0,     0,     0,     0,   113,   114,   115,     0,     0,   116,
     117,   118,   119,   120,   121,     0,   122,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   123,     0,   124,   113,
     114,   115,     0,     0,   116,   117,   118,   119,   120,   121,
       0,   122,   125,   126,     0,     0,   127,     0,     0,   308,
       0,   123,     0,   124,   113,   114,   115,     0,     0,   116,
     117,   118,   119,   120,   121,     0,   122,   125,   126,     0,
       0,   127,     0,     0,     0,     0,   123,     0,   124,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   125,   126,     0,     0,   127
};

static const yytype_int16 yycheck[] =
{
      33,    12,   171,    30,    15,    31,     9,     4,    36,    15,
      16,    17,    45,    46,    20,    21,    22,    23,    24,    25,
     118,    27,   120,   120,   118,    37,   120,    39,    35,    37,
       5,    37,   117,    39,     9,    68,    69,    12,    13,    72,
       4,    53,    54,    33,   119,    57,   121,    53,    54,     9,
     119,    57,   121,    56,     4,    88,    16,     4,    91,    92,
      93,    94,    47,    48,    97,    98,    99,   100,   101,   117,
     103,   104,   105,   106,   107,   108,   109,   110,    86,     4,
     113,   250,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   118,   121,   127,     4,    56,   105,    62,    63,
      64,   134,   110,   119,   119,   121,   121,    36,     0,    29,
      27,    41,    32,   119,    34,   121,     4,   119,   118,   121,
     128,     4,     5,     6,    28,    45,     9,   118,    11,    12,
      13,   123,   119,    16,   121,    16,   118,    29,    21,   118,
      32,   118,    34,   123,   118,   118,   118,   118,   118,   118,
      15,    16,    17,    45,   119,    20,    21,    22,    23,    24,
      25,   118,    27,    44,   197,   118,    49,    50,    51,   118,
      35,     4,    37,    56,    39,    56,   118,    58,    59,    60,
      61,    62,    63,   118,   118,   118,   118,    42,    53,    54,
      43,   224,    57,    63,   118,   118,   118,     4,   119,    53,
     119,    31,   118,    27,    12,   118,     5,   118,     4,   217,
      12,   119,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   118,   115,   119,   119,   118,   118,   121,    65,   122,
     119,   121,   275,     5,    56,   278,     4,     5,     6,     5,
      63,     9,   285,    11,    12,    13,   121,    63,    16,     4,
     119,   119,   119,    21,    12,     5,   173,   119,   119,   277,
     119,   174,   305,   166,   282,     4,     5,     6,    32,    74,
       9,   262,    11,    12,    13,   314,   133,    16,    -1,    -1,
      -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,    56,   332,
     308,    -1,    60,    -1,     4,     5,     6,    -1,    -1,     9,
      -1,    11,    12,    13,    -1,    -1,    16,    -1,    -1,    -1,
      -1,    21,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    56,   115,    -1,    -1,
     118,    -1,    -1,    -1,   122,    -1,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,    -1,   115,    -1,    -1,   118,
      -1,    -1,    -1,   122,    -1,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,    -1,   115,    -1,    -1,   118,    15,
      16,    17,   122,    -1,    20,    21,    22,    23,    24,    25,
      -1,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    -1,    39,    15,    16,    17,    -1,    -1,    20,
      21,    22,    23,    24,    25,    -1,    27,    53,    54,    -1,
      -1,    57,    -1,    -1,    -1,    -1,    37,    -1,    39,    15,
      16,    17,    -1,    -1,    20,    21,    22,    23,    24,    25,
      -1,    27,    53,    54,    -1,    -1,    57,    -1,    -1,    -1,
      -1,    37,    -1,    39,    15,    16,    17,    -1,    -1,    20,
      21,    22,    23,    24,    25,    -1,    27,    53,    54,    -1,
      -1,    57,    -1,    -1,    -1,    -1,    37,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,
      -1,    52,    53,    54,    -1,    -1,    57,    -1,    -1,    15,
      16,    17,    -1,    -1,    20,    21,    22,    23,    24,    25,
     121,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    -1,    39,    15,    16,    17,    -1,    -1,    20,
      21,    22,    23,    24,    25,   121,    27,    53,    54,    -1,
      -1,    57,    -1,    -1,    -1,    -1,    37,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,
      -1,    -1,    53,    54,    -1,    -1,    57,    15,    16,    17,
      -1,    -1,    20,    21,    22,    23,    24,    25,    -1,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      -1,    39,    15,    16,    17,    -1,    -1,    20,    21,    22,
      23,    24,    25,   119,    27,    53,    54,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    37,    -1,    39,    15,    16,    17,
      -1,    -1,    20,    21,    22,    23,    24,    25,   119,    27,
      53,    54,    -1,    -1,    57,    -1,    -1,    -1,    -1,    37,
      -1,    39,    15,    16,    17,    -1,    -1,    20,    21,    22,
      23,    24,    25,    -1,    27,    53,    54,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    37,    -1,    39,    15,    16,    17,
      -1,   119,    20,    21,    22,    23,    24,    25,    -1,    27,
      53,    54,    -1,    -1,    57,    -1,    -1,    -1,    -1,    37,
      -1,    39,    15,    16,    17,    -1,   119,    20,    21,    22,
      23,    24,    25,    -1,    27,    53,    54,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    37,    -1,    39,    15,    16,    17,
      -1,   119,    20,    21,    22,    23,    24,    25,    -1,    27,
      53,    54,    -1,    -1,    57,    -1,    -1,    -1,    -1,    37,
      -1,    39,    15,    16,    17,    -1,   119,    20,    21,    22,
      23,    24,    25,    -1,    27,    53,    54,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    37,    -1,    39,    15,    16,    17,
      -1,   119,    20,    21,    22,    23,    24,    25,    -1,    27,
      53,    54,    -1,    -1,    57,    -1,    -1,    -1,    -1,    37,
      -1,    39,    15,    16,    17,    -1,   119,    20,    21,    22,
      23,    24,    25,    -1,    27,    53,    54,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    37,    -1,    39,    15,    16,    17,
      -1,   119,    20,    21,    22,    23,    24,    25,    -1,    27,
      53,    54,    -1,    -1,    57,    -1,    -1,    -1,    -1,    37,
      -1,    39,    15,    16,    17,    -1,   119,    20,    21,    22,
      23,    24,    25,    -1,    27,    53,    54,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    37,    -1,    39,    15,    16,    17,
      -1,   119,    20,    21,    22,    23,    24,    25,    -1,    27,
      53,    54,    -1,    -1,    57,    -1,    -1,    -1,    -1,    37,
      -1,    39,    15,    16,    17,    -1,   119,    20,    21,    22,
      23,    24,    25,    -1,    27,    53,    54,    -1,    -1,    57,
      -1,    -1,    10,    -1,    37,    38,    39,    15,    16,    17,
      -1,   119,    20,    21,    22,    23,    24,    25,    -1,    27,
      53,    54,    -1,    -1,    57,    27,    -1,    -1,    -1,    37,
      -1,    39,    11,    -1,    -1,    37,   119,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    54,    -1,    -1,    57,
      -1,    53,    54,    -1,    33,    57,    -1,    -1,    -1,    -1,
      -1,   119,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,    -1,    -1,    -1,    -1,   154,   155,   156,
     157,    -1,    -1,    -1,    -1,    -1,    94,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,     7,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    -1,    20,
      21,    22,    23,    24,    25,    -1,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,    39,    15,
      16,    17,    -1,    -1,    20,    21,    22,    23,    24,    25,
      -1,    27,    53,    54,    -1,    -1,    57,    -1,    -1,    35,
      -1,    37,    -1,    39,    15,    16,    17,    -1,    -1,    20,
      21,    22,    23,    24,    25,    -1,    27,    53,    54,    -1,
      -1,    57,    -1,    -1,    -1,    -1,    37,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    54,    -1,    -1,    57
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    29,    32,    34,    45,   125,   126,   127,   135,   136,
     138,   139,    30,     4,   143,    35,    47,    48,     0,   126,
     117,   143,   120,    33,   143,     4,     4,   117,    31,   118,
       4,     4,   137,    36,   140,   118,   120,   118,     4,     5,
       6,     9,    11,    12,    13,    16,    21,    56,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   115,   118,   122,
     146,   147,    27,   121,   140,   146,    41,   141,     4,    62,
      63,    64,   128,   129,     4,   147,   118,   120,    28,   146,
     146,   118,   118,   118,   118,   123,   123,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   146,   146,    15,    16,    17,    20,    21,    22,    23,
      24,    25,    27,    37,    39,    53,    54,    57,   121,   119,
      60,   146,     4,   141,    42,    43,   145,    11,    33,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,   130,    63,
     118,   118,   119,   121,   118,   119,   147,   148,     4,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   119,
     146,   146,    49,    50,    51,   146,   147,   149,   146,   146,
     146,   146,   146,   147,   119,   146,    53,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   118,     9,    16,
      56,   146,   147,    31,    27,   145,   142,   146,    12,   118,
     132,     5,   131,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   131,   134,
     118,     4,   133,   133,   129,   128,   119,   119,   119,   119,
     119,   121,   121,   119,   119,   119,   119,   119,   119,   119,
     146,   119,   119,   119,   119,    35,   119,   118,    38,   147,
       9,    56,   118,    60,   146,   121,     7,     8,   144,    12,
     121,    16,    44,    56,    58,    59,    60,    61,    62,    63,
     133,   119,   121,   119,   119,    65,   150,   150,    35,   146,
     147,   146,   119,   147,   146,   119,   121,     5,    56,     5,
       5,     9,    12,    13,    63,    63,   119,     4,   146,   119,
     119,   147,    52,   119,   119,   119,   144,    12,    10,    94,
     151,   119,   146,   119,   119
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   124,   125,   125,   125,   126,   126,   126,   126,   126,
     127,   127,   128,   128,   129,   129,   129,   129,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   131,
     131,   132,   132,   132,   133,   133,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     135,   136,   137,   137,   137,   137,   138,   138,   139,   140,
     140,   141,   141,   142,   142,   143,   143,   144,   144,   144,
     145,   145,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   147,   147,   148,   148,   146,   146,   146,   146,
     146,   146,   146,   146,   149,   149,   149,   146,   146,   150,
     151,   151,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     3,     1,     1,     1,     1,     1,
       6,     8,     1,     3,     5,     4,     4,     3,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       3,     0,     3,     5,     1,     3,     0,     3,     2,     3,
       3,     3,     3,     2,     2,     2,     3,     3,     2,     3,
       3,     7,     3,     3,     5,     5,    10,     7,     6,     0,
       2,     0,     3,     2,     4,     1,     3,     0,     1,     1,
       0,     2,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     2,     3,
       3,     3,     2,     2,     3,     3,     3,     4,     3,     4,
       3,     5,     1,     3,     0,     1,     5,     6,     4,     4,
       6,     8,     4,     7,     1,     1,     1,     6,     6,     3,
       1,     1,     4,     4,     4,     4,     2,     2,     4,     4,
       4,     4,     3,     4,     4,     4,     4,     4,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 97 "SQL_parser.y" /* yacc.c:1646  */
    {  }
#line 1788 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 98 "SQL_parser.y" /* yacc.c:1646  */
    {  }
#line 1794 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 101 "SQL_parser.y" /* yacc.c:1646  */
    {
    SQL__Functions::SQL__Rollback__Parameters parameters(conn_id, select_query, original_query, *primary_keys, current_table);

    SQL__Functions::f__getRollback__Delete(*sql_port, parameters, *rollback_queries,  *result_record, sql_exception_received); 
  
  }
#line 1805 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 107 "SQL_parser.y" /* yacc.c:1646  */
    {
    SQL__Functions::SQL__Rollback__Parameters parameters(conn_id, select_query, original_query, *primary_keys, current_table);
    
    SQL__Functions::f__getRollback__Insert(*sql_port, parameters, select_query_after, *rollback_queries, *result_record, sql_exception_received);
  }
#line 1815 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 112 "SQL_parser.y" /* yacc.c:1646  */
    { 
    SQL__Functions::SQL__Rollback__Parameters parameters(conn_id, select_query, original_query, *primary_keys, current_table);

    SQL__Functions::f__getRollback__Update(*sql_port, parameters, *rollback_queries,  *result_record, sql_exception_received); 
  }
#line 1825 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 117 "SQL_parser.y" /* yacc.c:1646  */
    { /* do the miracle in the statement */ }
#line 1831 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 118 "SQL_parser.y" /* yacc.c:1646  */
    { /* do the miracle in the statement */ }
#line 1837 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 121 "SQL_parser.y" /* yacc.c:1646  */
    { 
    SQL__Query query = SQL__Query("CREATE TABLE");
    int rollback_index = (*rollback_queries).size_of();
    int result_index = (*result_record).size_of();
    SQL__Query__result result;
    SQL__exception e;

    query = query + " " + (yyvsp[-3].strval) + "(" + (yyvsp[-1].strval) + ");";
    
    if(f__query(*sql_port, conn_id, query, result, e)) {
      (*result_record)[result_index] = result;
      (*rollback_queries)[rollback_index] = SQL__Query("DROP TABLE ") + (yyvsp[-3].strval) + ";";
    } else {sql_exception_received = true;};
    
    free((yyvsp[-3].strval)); free((yyvsp[-1].strval));
  }
#line 1858 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 137 "SQL_parser.y" /* yacc.c:1646  */
    { 
    SQL__Query query = SQL__Query("CREATE TABLE");
    int rollback_index = (*rollback_queries).size_of();
    int result_index = (*result_record).size_of();
    SQL__Query__result result;
    SQL__exception e;

    query = query + " " + (yyvsp[-5].strval) + "." + (yyvsp[-3].strval) + "(" + (yyvsp[-1].strval) + ");";
  
    if(f__query(*sql_port, conn_id, query, result, e)) {
      (*result_record)[result_index] = result;
      (*rollback_queries)[rollback_index] = SQL__Query("DROP TABLE ") + (yyvsp[-5].strval) + "." + (yyvsp[-3].strval);
    } else {sql_exception_received = true;};
  
   free((yyvsp[-5].strval)); free((yyvsp[-3].strval)); free((yyvsp[-1].strval));
 }
#line 1879 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 155 "SQL_parser.y" /* yacc.c:1646  */
    {
    (yyval.strval) = (yyvsp[0].strval);
  }
#line 1887 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 158 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[1024];
    sprintf(buffer, "%s, %s", (yyvsp[-2].strval), (yyvsp[0].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-2].strval)); free((yyvsp[0].strval));
  }
#line 1898 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 166 "SQL_parser.y" /* yacc.c:1646  */
    {  
    char buffer[128];
    sprintf(buffer, "PRIMARY KEY (%s)", (yyvsp[-1].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-1].strval));
  }
#line 1909 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 172 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[128];
    sprintf(buffer, "KEY (%s)", (yyvsp[-1].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-1].strval));
  }
#line 1920 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 178 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[128];
    sprintf(buffer, "INDEX (%s)", (yyvsp[-1].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-1].strval));
  }
#line 1931 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 184 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[128];
    sprintf(buffer, "%s %s %s", (yyvsp[-2].strval), (yyvsp[-1].strval), (yyvsp[0].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-2].strval)); free((yyvsp[-1].strval)); free((yyvsp[0].strval));
  }
#line 1942 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 192 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[128];
    sprintf(buffer, "%s %s", (yyvsp[-1].strval), (yyvsp[0].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-1].strval)); free((yyvsp[0].strval));
  }
#line 1953 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 198 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[128];
    sprintf(buffer, "%s %s", (yyvsp[-1].strval), (yyvsp[0].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-1].strval)); free((yyvsp[0].strval));
  }
#line 1964 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 204 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[128];
    sprintf(buffer, "%s %s", (yyvsp[-1].strval), (yyvsp[0].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-1].strval)); free((yyvsp[0].strval));
  }
#line 1975 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 210 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[128];
    sprintf(buffer, "%s %s", (yyvsp[-1].strval), (yyvsp[0].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-1].strval)); free((yyvsp[0].strval));
  }
#line 1986 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 216 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[128];
    sprintf(buffer, "%s %s", (yyvsp[-1].strval), (yyvsp[0].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-1].strval)); free((yyvsp[0].strval));
  }
#line 1997 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 222 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[128];
    sprintf(buffer, "%s %s", (yyvsp[-1].strval), (yyvsp[0].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-1].strval)); free((yyvsp[0].strval));
  }
#line 2008 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 228 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[128];
    sprintf(buffer, "BIGINT %s", (yyvsp[0].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[0].strval));
  }
#line 2019 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 234 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[128];
    sprintf(buffer, "%s %s", (yyvsp[-1].strval), (yyvsp[0].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-1].strval)); free((yyvsp[0].strval));
  }
#line 2030 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 240 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[128];
    sprintf(buffer, "%s %s", (yyvsp[-1].strval), (yyvsp[0].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-1].strval)); free((yyvsp[0].strval));
  }
#line 2041 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 246 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[128];
    sprintf(buffer, "%s %s", (yyvsp[-1].strval), (yyvsp[0].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-1].strval)); free((yyvsp[0].strval));
  }
#line 2052 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 252 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[128];
    sprintf(buffer, "%s %s", (yyvsp[-1].strval), (yyvsp[0].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-1].strval)); free((yyvsp[0].strval));
  }
#line 2063 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 258 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[128];
    sprintf(buffer, "%s %s", (yyvsp[-1].strval), (yyvsp[0].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-1].strval)); free((yyvsp[0].strval));
  }
#line 2074 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 264 "SQL_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 2080 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 265 "SQL_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 2086 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 266 "SQL_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 2092 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 267 "SQL_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 2098 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 268 "SQL_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = strdup("YEAR"); }
#line 2104 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 269 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[128];
    sprintf(buffer, "%s %s", (yyvsp[-1].strval), (yyvsp[0].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-1].strval)); free((yyvsp[0].strval));
  }
#line 2115 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 275 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[128];
    sprintf(buffer, "%s %s", (yyvsp[-1].strval), (yyvsp[0].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-1].strval)); free((yyvsp[0].strval));
  }
#line 2126 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 281 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[128];
    sprintf(buffer, "%s %s", (yyvsp[-1].strval), (yyvsp[0].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-1].strval)); free((yyvsp[0].strval));
  }
#line 2137 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 287 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[128];
    sprintf(buffer, "%s %s", (yyvsp[-1].strval), (yyvsp[0].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-1].strval)); free((yyvsp[0].strval));
  }
#line 2148 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 293 "SQL_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 2154 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 294 "SQL_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 2160 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 295 "SQL_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 2166 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 296 "SQL_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 2172 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 297 "SQL_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 2178 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 298 "SQL_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 2184 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 299 "SQL_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 2190 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 300 "SQL_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 2196 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 301 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[1024];
    sprintf(buffer, "ENUM %s", (yyvsp[0].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[0].strval));
  }
#line 2207 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 307 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[1024];
    sprintf(buffer, "SET %s", (yyvsp[0].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[0].strval));
  }
#line 2218 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 315 "SQL_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 2224 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 316 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[1024];
    sprintf(buffer, "%s, %s", (yyvsp[-2].strval), (yyvsp[0].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-2].strval)); free((yyvsp[0].strval));
  }
#line 2235 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 323 "SQL_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = strdup(""); }
#line 2241 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 324 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[64];
    sprintf(buffer, "(%d)", (yyvsp[-1].intval));
    (yyval.strval) = strdup(buffer);
  }
#line 2251 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 329 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[64];
    sprintf(buffer, "(%d,%d)", (yyvsp[-3].intval), (yyvsp[-1].intval));
    (yyval.strval) = strdup(buffer);
  }
#line 2261 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 336 "SQL_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 2267 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 337 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[1024];
    sprintf(buffer, "%s, %s", (yyvsp[-2].strval), (yyvsp[0].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-2].strval)); free((yyvsp[0].strval));
  }
#line 2278 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 345 "SQL_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = strdup(""); }
#line 2284 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 346 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[1024];
    sprintf(buffer, "%s NOT NULL", (yyvsp[-2].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-2].strval));
  }
#line 2295 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 352 "SQL_parser.y" /* yacc.c:1646  */
    { 
    char buffer[1024];
    sprintf(buffer, "%s NULL", (yyvsp[-1].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-1].strval)); 
  }
#line 2306 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 358 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[1024];
    sprintf(buffer, "%s DEFAULT %s", (yyvsp[-2].strval), (yyvsp[0].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-2].strval)); free((yyvsp[0].strval));
  }
#line 2317 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 364 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[1024];
    sprintf(buffer, "%s DEFAULT %d", (yyvsp[-2].strval), (yyvsp[0].intval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-2].strval));
  }
#line 2328 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 370 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[1024];
    sprintf(buffer, "%s DEFAULT %f", (yyvsp[-2].strval), (yyvsp[0].floatval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-2].strval));
  }
#line 2339 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 376 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[1024];
    sprintf(buffer, "%s DEFAULT %s", (yyvsp[-2].strval), (yyvsp[0].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-2].strval)); free((yyvsp[0].strval));
  }
#line 2350 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 382 "SQL_parser.y" /* yacc.c:1646  */
    { 
    char buffer[1024];
    sprintf(buffer, "%s AUTO_INCREMENT", (yyvsp[-1].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-1].strval));
  }
#line 2361 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 388 "SQL_parser.y" /* yacc.c:1646  */
    { 
    char buffer[1024];
    sprintf(buffer, "%s AUTOINCREMENT", (yyvsp[-1].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-1].strval));
  }
#line 2372 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 394 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[1024];
    sprintf(buffer, "%s UNIQUE", (yyvsp[-1].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-1].strval));
  }
#line 2383 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 400 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[1024];
    sprintf(buffer, "%s UNIQUE KEY", (yyvsp[-2].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-2].strval));
  }
#line 2394 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 406 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[1024];
    sprintf(buffer, "%s PRIMARY KEY", (yyvsp[-2].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-2].strval));
  }
#line 2405 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 412 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[1024];
    sprintf(buffer, "%s KEY", (yyvsp[-1].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-1].strval));
  }
#line 2416 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 418 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[1024];
    sprintf(buffer, "%s COMMENT %s", (yyvsp[-2].strval), (yyvsp[0].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-2].strval)); free((yyvsp[0].strval));
  }
#line 2427 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 427 "SQL_parser.y" /* yacc.c:1646  */
    {
  SQL__Query query = SQL__Query("CREATE DATABASE");
  int rollback_index = (*rollback_queries).size_of();
  int result_index = (*result_record).size_of();
  SQL__Query__result result;
  SQL__exception e;

  query = query + " " + (yyvsp[0].strval) + ";";
  
  if(f__query(*sql_port, conn_id, query, result, e)) {
    (*result_record)[result_index] = result;
    (*rollback_queries)[rollback_index] = SQL__Query("DROP DATABASE ") + (yyvsp[0].strval) + ";";
  } else {sql_exception_received = true;};
  
  free((yyvsp[0].strval));
}
#line 2448 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 446 "SQL_parser.y" /* yacc.c:1646  */
    {
  current_table = UNIVERSAL_CHARSTRING((yyvsp[-5].strval));
  original_query = SQL__Query("UPDATE ") + current_table + " SET " + (yyvsp[-3].strval);
  select_query = SQL__Query("SELECT * FROM ") + current_table;
  if(strcmp((yyvsp[-2].strval), "") != 0) {
    original_query = original_query + " " + (yyvsp[-2].strval);
    select_query = select_query + " " + (yyvsp[-2].strval);
  }
  if(strcmp((yyvsp[-1].strval), "") != 0) {
    original_query = original_query + " " + (yyvsp[-1].strval);
    select_query = select_query + " " + (yyvsp[-1].strval);
  }
  if(strcmp((yyvsp[0].strval), "") != 0) {
    original_query = original_query + " " + (yyvsp[0].strval);
    select_query = select_query + " " + (yyvsp[0].strval);
  }
  
  free((yyvsp[-5].strval)); free((yyvsp[-3].strval)); free((yyvsp[-2].strval)); free((yyvsp[-1].strval)); free((yyvsp[0].strval));
}
#line 2472 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 467 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[1024];
    sprintf(buffer, "%s %s %s", (yyvsp[-2].strval), (yyvsp[-1].strval), (yyvsp[0].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-2].strval)); free((yyvsp[-1].strval)); free((yyvsp[0].strval));
  }
#line 2483 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 473 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[1024];
    sprintf(buffer, "%s %s DEFAULT", (yyvsp[-2].strval), (yyvsp[-1].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-2].strval)); free((yyvsp[-1].strval));
  }
#line 2494 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 479 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[2048];
    sprintf(buffer, "%s, %s %s %s", (yyvsp[-4].strval), (yyvsp[-2].strval), (yyvsp[-1].strval), (yyvsp[0].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-4].strval)); free((yyvsp[-2].strval)); free((yyvsp[-1].strval)); free((yyvsp[0].strval)); 
  }
#line 2505 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 485 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[2048];
    sprintf(buffer, "%s, %s %s DEFAULT", (yyvsp[-4].strval), (yyvsp[-2].strval), (yyvsp[-1].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-4].strval)); free((yyvsp[-2].strval)); free((yyvsp[-1].strval));
  }
#line 2516 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 493 "SQL_parser.y" /* yacc.c:1646  */
    {
  current_table = UNIVERSAL_CHARSTRING((yyvsp[-7].strval));
  CharstringList column_list = SQL__Functions::f__SQL__split((yyvsp[-5].strval), ",");
  CharstringList value_list = SQL__Functions::f__SQL__split((yyvsp[-1].strval), ",");
  
  original_query = SQL__Query("INSERT INTO ") + current_table + "(" + (yyvsp[-5].strval) + ") VALUES (" + (yyvsp[-1].strval) + ")";
  select_query = SQL__Query("SELECT ") + f__getPrimary__key(*primary_keys, current_table) + " FROM " + current_table + " ORDER BY 1 ASC";
  select_query_after = SQL__Query("SELECT ") + f__getPrimary__key(*primary_keys, current_table) + 
    " FROM " + current_table + " " + SQL__Functions::f__SQL__getWHERE(column_list, value_list) + 
    " ORDER BY 1 ASC";

  free((yyvsp[-7].strval)); free((yyvsp[-5].strval)); free((yyvsp[-1].strval));
}
#line 2534 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 506 "SQL_parser.y" /* yacc.c:1646  */
    {
    current_table = UNIVERSAL_CHARSTRING((yyvsp[-4].strval));
    original_query = SQL__Query("INSERT INTO ") + current_table + " VALUES (" + (yyvsp[-1].strval) + ")";
    select_query = SQL__Query("SELECT ") + f__getPrimary__key(*primary_keys, current_table) + " FROM " + current_table + " ORDER BY 1 ASC";
    select_query_after = select_query;
    free((yyvsp[-4].strval)); free((yyvsp[-1].strval));
  }
#line 2546 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 516 "SQL_parser.y" /* yacc.c:1646  */
    {
  current_table = UNIVERSAL_CHARSTRING((yyvsp[-3].strval));
  original_query = SQL__Query("DELETE FROM ") + current_table;
  select_query = SQL__Query("SELECT * FROM ") + current_table;
  
  if(strcmp((yyvsp[-2].strval), "") != 0) {
    original_query = original_query + " " + (yyvsp[-2].strval);
    select_query = select_query + " " + (yyvsp[-2].strval);
  }
  if(strcmp((yyvsp[-1].strval), "") != 0) {
    original_query = original_query + " " + (yyvsp[-1].strval);
    select_query = select_query + " " + (yyvsp[-1].strval);
  }
  if(strcmp((yyvsp[0].strval), "") != 0) {
    original_query = original_query + " " + (yyvsp[0].strval);
    select_query = select_query + " " + (yyvsp[0].strval);
  }
  
  original_query = original_query + ";";
  select_query = select_query + ";";
  
  free((yyvsp[-3].strval)); free((yyvsp[-2].strval)); free((yyvsp[-1].strval)); free((yyvsp[0].strval));
}
#line 2574 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 541 "SQL_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = strdup(""); }
#line 2580 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 542 "SQL_parser.y" /* yacc.c:1646  */
    {
    CHARSTRING where = CHARSTRING("WHERE ") + (yyvsp[0].strval);
    (yyval.strval) = strdup(where);
    free((yyvsp[0].strval));
  }
#line 2590 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 549 "SQL_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = strdup(""); }
#line 2596 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 550 "SQL_parser.y" /* yacc.c:1646  */
    {
    CHARSTRING orderby = CHARSTRING("ORDER BY ") + (yyvsp[0].strval);
    (yyval.strval) = strdup(orderby);
    free((yyvsp[0].strval));
  }
#line 2606 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 557 "SQL_parser.y" /* yacc.c:1646  */
    {
    CHARSTRING list = CHARSTRING((yyvsp[-1].strval)) + " " + (yyvsp[0].strval);
    (yyval.strval) = strdup(list);
    free((yyvsp[-1].strval)); free((yyvsp[0].strval));
  }
#line 2616 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 562 "SQL_parser.y" /* yacc.c:1646  */
    {
    CHARSTRING list = CHARSTRING((yyvsp[-3].strval)) + "," + (yyvsp[-1].strval);
    if(strcmp((yyvsp[0].strval), "") != 0) {
      list = list + " " + (yyvsp[0].strval);
    }
    (yyval.strval) = strdup(list);
    free((yyvsp[-3].strval)); free((yyvsp[-1].strval)); free((yyvsp[0].strval));
  }
#line 2629 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 572 "SQL_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 2635 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 573 "SQL_parser.y" /* yacc.c:1646  */
    {
    CHARSTRING table_reference = CHARSTRING((yyvsp[-2].strval)) + "." + (yyvsp[0].strval);
    (yyval.strval) = strdup(table_reference);
    free((yyvsp[-2].strval)); free((yyvsp[0].strval));
  }
#line 2645 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 580 "SQL_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = strdup(""); }
#line 2651 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 581 "SQL_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 2657 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 582 "SQL_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 2663 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 585 "SQL_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = strdup(""); }
#line 2669 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 586 "SQL_parser.y" /* yacc.c:1646  */
    {
    CHARSTRING limit = CHARSTRING("LIMIT ") + int2str((yyvsp[0].intval));
    (yyval.strval) = strdup(limit);
  }
#line 2678 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 592 "SQL_parser.y" /* yacc.c:1646  */
    {
    CHARSTRING tmp = CHARSTRING("(") + (yyvsp[-1].strval) + ")";
    (yyval.strval) = strdup(tmp);
    free((yyvsp[-1].strval));
  }
#line 2688 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 597 "SQL_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 2694 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 598 "SQL_parser.y" /* yacc.c:1646  */
    { 
    CHARSTRING name = CHARSTRING((yyvsp[-2].strval)) + "." + (yyvsp[0].strval);
    (yyval.strval) = strdup(name);
    free((yyvsp[-2].strval)); free((yyvsp[0].strval));
  }
#line 2704 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 604 "SQL_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 2710 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 605 "SQL_parser.y" /* yacc.c:1646  */
    { 
  		(yyval.strval) = replace_ENV_VAR((yyvsp[0].strval));
		free((yyvsp[0].strval));
  	}
#line 2719 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 609 "SQL_parser.y" /* yacc.c:1646  */
    { 
    (yyval.strval) = strdup(int2str((yyvsp[0].intval)));
  }
#line 2727 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 612 "SQL_parser.y" /* yacc.c:1646  */
    { 
    char buffer[32];
    sprintf(buffer, "%lld", (yyvsp[0].bigint));
    (yyval.strval) = strdup(buffer);
  }
#line 2737 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 617 "SQL_parser.y" /* yacc.c:1646  */
    {
    (yyval.strval) = strdup(float2str((yyvsp[0].floatval)));
  }
#line 2745 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 620 "SQL_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 2751 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 621 "SQL_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = strdup("NULL"); }
#line 2757 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 624 "SQL_parser.y" /* yacc.c:1646  */
    { 
      CHARSTRING tmp = CHARSTRING((yyvsp[-2].strval)) + "+" + (yyvsp[0].strval);
      (yyval.strval) = strdup(tmp); 
      free((yyvsp[-2].strval)); free((yyvsp[0].strval));
    }
#line 2767 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 629 "SQL_parser.y" /* yacc.c:1646  */
    { 
    CHARSTRING tmp = CHARSTRING((yyvsp[-2].strval)) + "-" + (yyvsp[0].strval);
    (yyval.strval) = strdup(tmp); 
    free((yyvsp[-2].strval)); free((yyvsp[0].strval));
  }
#line 2777 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 634 "SQL_parser.y" /* yacc.c:1646  */
    {
    CHARSTRING tmp = CHARSTRING((yyvsp[-2].strval)) + "*" + (yyvsp[0].strval);
    (yyval.strval) = strdup(tmp); 
    free((yyvsp[-2].strval)); free((yyvsp[0].strval));
  }
#line 2787 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 639 "SQL_parser.y" /* yacc.c:1646  */
    { 
    CHARSTRING tmp = CHARSTRING((yyvsp[-2].strval)) + "/" + (yyvsp[0].strval);
    (yyval.strval) = strdup(tmp); 
    free((yyvsp[-2].strval)); free((yyvsp[0].strval));
  }
#line 2797 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 644 "SQL_parser.y" /* yacc.c:1646  */
    {
    CHARSTRING tmp = CHARSTRING((yyvsp[-2].strval)) + "%" + (yyvsp[0].strval);
    (yyval.strval) = strdup(tmp); 
    free((yyvsp[-2].strval)); free((yyvsp[0].strval));
  }
#line 2807 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 649 "SQL_parser.y" /* yacc.c:1646  */
    {
    CHARSTRING tmp = CHARSTRING((yyvsp[-2].strval)) + " MOD " + (yyvsp[0].strval);
    (yyval.strval) = strdup(tmp); 
    free((yyvsp[-2].strval)); free((yyvsp[0].strval));
  }
#line 2817 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 654 "SQL_parser.y" /* yacc.c:1646  */
    {
    CHARSTRING tmp = CHARSTRING("-") + (yyvsp[0].strval);
    (yyval.strval) = strdup(tmp); 
    free((yyvsp[0].strval));
  }
#line 2827 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 659 "SQL_parser.y" /* yacc.c:1646  */
    {
    CHARSTRING tmp = CHARSTRING((yyvsp[-2].strval)) + " AND " + (yyvsp[0].strval);
    (yyval.strval) = strdup(tmp); 
    free((yyvsp[-2].strval)); free((yyvsp[0].strval));
  }
#line 2837 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 664 "SQL_parser.y" /* yacc.c:1646  */
    {
    CHARSTRING tmp = CHARSTRING((yyvsp[-2].strval)) + " OR " + (yyvsp[0].strval);
    (yyval.strval) = strdup(tmp); 
    free((yyvsp[-2].strval)); free((yyvsp[0].strval));
  }
#line 2847 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 669 "SQL_parser.y" /* yacc.c:1646  */
    {
    CHARSTRING tmp = CHARSTRING((yyvsp[-2].strval)) + " XOR " + (yyvsp[0].strval);
    (yyval.strval) = strdup(tmp); 
    free((yyvsp[-2].strval)); free((yyvsp[0].strval));
  }
#line 2857 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 674 "SQL_parser.y" /* yacc.c:1646  */
    {
    CHARSTRING tmp = CHARSTRING("NOT ") + (yyvsp[0].strval);
    (yyval.strval) = strdup(tmp); 
    free((yyvsp[0].strval));
  }
#line 2867 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 679 "SQL_parser.y" /* yacc.c:1646  */
    {
    CHARSTRING tmp = CHARSTRING("! ") + (yyvsp[0].strval);
    (yyval.strval) = strdup(tmp); 
    free((yyvsp[0].strval));
  }
#line 2877 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 684 "SQL_parser.y" /* yacc.c:1646  */
    {
    CHARSTRING tmp = CHARSTRING((yyvsp[-2].strval)) + " " + (yyvsp[-1].strval) + " " + (yyvsp[0].strval);
    (yyval.strval) = strdup(tmp); 
    free((yyvsp[-2].strval)); free((yyvsp[-1].strval)); free((yyvsp[0].strval));
  }
#line 2887 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 689 "SQL_parser.y" /* yacc.c:1646  */
    {
    CHARSTRING tmp = CHARSTRING((yyvsp[-2].strval)) + " LIKE " + (yyvsp[0].strval);
    (yyval.strval) = strdup(tmp);
    free((yyvsp[-2].strval)); free((yyvsp[0].strval));
  }
#line 2897 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 696 "SQL_parser.y" /* yacc.c:1646  */
    {
    CHARSTRING tmp = CHARSTRING((yyvsp[-2].strval)) + " IS NULL";
    (yyval.strval) = strdup(tmp);
    free((yyvsp[-2].strval));
  }
#line 2907 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 701 "SQL_parser.y" /* yacc.c:1646  */
    {
    CHARSTRING tmp = CHARSTRING((yyvsp[-3].strval)) + " IS NOT NULL";
    (yyval.strval) = strdup(tmp);
    free((yyvsp[-3].strval));
  }
#line 2917 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 706 "SQL_parser.y" /* yacc.c:1646  */
    {
    CHARSTRING tmp = CHARSTRING((yyvsp[-2].strval)) + " IS " + (yyvsp[0].strval); 
    (yyval.strval) = strdup(tmp);
    free((yyvsp[-2].strval)); free((yyvsp[0].strval));
  }
#line 2927 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 711 "SQL_parser.y" /* yacc.c:1646  */
    {
    CHARSTRING tmp = CHARSTRING((yyvsp[-3].strval)) + " IS NOT " + (yyvsp[0].strval);
    (yyval.strval) = strdup(tmp);
    free((yyvsp[-3].strval)); free((yyvsp[0].strval));
  }
#line 2937 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 716 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[2048];
    sprintf(buffer, "@%s := %s", (yyvsp[-2].strval), (yyvsp[0].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-2].strval)); free((yyvsp[0].strval));
  }
#line 2948 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 724 "SQL_parser.y" /* yacc.c:1646  */
    {
  char buffer[2048];
  sprintf(buffer, "%s BETWEEN %s AND %s", (yyvsp[-4].strval), (yyvsp[-2].strval), (yyvsp[0].strval));
  (yyval.strval) = strdup(buffer);
  free((yyvsp[-4].strval)); free((yyvsp[-2].strval)); free((yyvsp[0].strval));
}
#line 2959 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 732 "SQL_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 2965 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 733 "SQL_parser.y" /* yacc.c:1646  */
    {
    CHARSTRING tmp = CHARSTRING((yyvsp[-2].strval)) + "," + CHARSTRING((yyvsp[0].strval));
    (yyval.strval) = strdup(tmp);
    free((yyvsp[-2].strval)); free((yyvsp[0].strval));
  }
#line 2975 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 740 "SQL_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = strdup(""); }
#line 2981 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 741 "SQL_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 2987 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 744 "SQL_parser.y" /* yacc.c:1646  */
    {
  CHARSTRING tmp = CHARSTRING((yyvsp[-4].strval)) + " IN (" + (yyvsp[-1].strval) + ")";
  (yyval.strval) = strdup(tmp);
  free((yyvsp[-4].strval)); free((yyvsp[-1].strval));
}
#line 2997 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 749 "SQL_parser.y" /* yacc.c:1646  */
    {
    CHARSTRING tmp = CHARSTRING((yyvsp[-5].strval)) + " NOT IN (" + (yyvsp[-1].strval) + ")";
    (yyval.strval) = strdup(tmp);
    free((yyvsp[-5].strval)); free((yyvsp[-1].strval));
  }
#line 3007 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 757 "SQL_parser.y" /* yacc.c:1646  */
    {
  char buffer[2048];
  sprintf(buffer, "%s(%s)", (yyvsp[-3].strval), (yyvsp[-1].strval));
  (yyval.strval) = strdup(buffer);
  free((yyvsp[-3].strval)); free((yyvsp[-1].strval));
}
#line 3018 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 765 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[1024];
    sprintf(buffer, "%s(%s)", (yyvsp[-3].strval), (yyvsp[-1].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-3].strval)); free((yyvsp[-1].strval));
  }
#line 3029 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 771 "SQL_parser.y" /* yacc.c:1646  */
    { 
    char buffer[2048];
    sprintf(buffer, "%s(%s FROM %s)", (yyvsp[-5].strval), (yyvsp[-3].strval), (yyvsp[-1].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-5].strval)); free((yyvsp[-3].strval)); free((yyvsp[-1].strval));
  }
#line 3040 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 777 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[2048];
    sprintf(buffer, "%s(%s FROM %s FOR %s)", (yyvsp[-7].strval), (yyvsp[-5].strval), (yyvsp[-3].strval), (yyvsp[-1].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-7].strval)); free((yyvsp[-5].strval)); free((yyvsp[-3].strval)); free((yyvsp[-1].strval));
  }
#line 3051 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 785 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[1024];
    sprintf(buffer, "TRIM(%s)", (yyvsp[-1].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-1].strval));
  }
#line 3062 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 791 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[1024];
    sprintf(buffer, "TRIM(%s %s FROM %s)", (yyvsp[-4].strval), (yyvsp[-3].strval), (yyvsp[-1].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-4].strval)); free((yyvsp[-3].strval)); free((yyvsp[-1].strval));
  }
#line 3073 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 799 "SQL_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = strdup("LEADING"); }
#line 3079 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 800 "SQL_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = strdup("TRAILING"); }
#line 3085 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 801 "SQL_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = strdup("BOTH"); }
#line 3091 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 803 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[2048];
    sprintf(buffer, "DATE_ADD(%s, %s)", (yyvsp[-3].strval), (yyvsp[-1].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-3].strval)); free((yyvsp[-1].strval));
  }
#line 3102 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 809 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[2048];
    sprintf(buffer, "DATE_SUB(%s, %s)", (yyvsp[-3].strval), (yyvsp[-1].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-3].strval)); free((yyvsp[-1].strval));
  }
#line 3113 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 817 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[128];
    sprintf(buffer, "INTERVAL %s %s", (yyvsp[-1].strval), (yyvsp[0].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-1].strval)); free((yyvsp[0].strval));
  }
#line 3124 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 825 "SQL_parser.y" /* yacc.c:1646  */
    {
    (yyval.strval) = (yyvsp[0].strval);
  }
#line 3132 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 828 "SQL_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = strdup("YEAR"); }
#line 3138 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 831 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[1024];
    sprintf(buffer, "ASCII(%s)", (yyvsp[-1].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-1].strval));
  }
#line 3149 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 839 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[1024];
    sprintf(buffer, "BIN(%s)", (yyvsp[-1].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-1].strval));
  }
#line 3160 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 847 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[1024];
    sprintf(buffer, "BIT_LENGTH(%s)", (yyvsp[-1].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-1].strval));
  }
#line 3171 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 855 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[1024];
    sprintf(buffer, "CONCAT(%s)", (yyvsp[-1].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-1].strval));
  }
#line 3182 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 863 "SQL_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = strdup("CURDATE()"); }
#line 3188 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 866 "SQL_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = strdup("CURTIME()"); }
#line 3194 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 869 "SQL_parser.y" /* yacc.c:1646  */
    {
  char buffer[1024];
  sprintf(buffer, "DATE(%s)", (yyvsp[-1].strval));
  (yyval.strval) = strdup(buffer);
  free((yyvsp[-1].strval));
}
#line 3205 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 877 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[1024];
    sprintf(buffer, "HEX(%s)", (yyvsp[-1].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-1].strval));
  }
#line 3216 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 885 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[1024];
    sprintf(buffer, "LOWER(%s)", (yyvsp[-1].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-1].strval));
  }
#line 3227 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 893 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[1024];
    sprintf(buffer, "LENGTH(%s)", (yyvsp[-1].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-1].strval));
  }
#line 3238 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 901 "SQL_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = strdup("NOW()"); }
#line 3244 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 904 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[1024];
    sprintf(buffer, "REVERSE(%s)", (yyvsp[-1].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-1].strval));
  }
#line 3255 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 912 "SQL_parser.y" /* yacc.c:1646  */
    {
    char buffer[1024];
    sprintf(buffer, "SPACE(%s)", (yyvsp[-1].strval));
    (yyval.strval) = strdup(buffer);
    free((yyvsp[-1].strval));
  }
#line 3266 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 920 "SQL_parser.y" /* yacc.c:1646  */
    {
  char buffer[1024];
  sprintf(buffer, "TIME(%s)", (yyvsp[-1].strval));
  (yyval.strval) = strdup(buffer);
  free((yyvsp[-1].strval));
}
#line 3277 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 928 "SQL_parser.y" /* yacc.c:1646  */
    {
  char buffer[1024];
  sprintf(buffer, "TRIM(%s)", (yyvsp[-1].strval));
  (yyval.strval) = strdup(buffer);
  free((yyvsp[-1].strval));
}
#line 3288 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 936 "SQL_parser.y" /* yacc.c:1646  */
    {
  char buffer[1024];
  sprintf(buffer, "UHEX(%s)", (yyvsp[-1].strval));
  (yyval.strval) = strdup(buffer);
  free((yyvsp[-1].strval));
}
#line 3299 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 944 "SQL_parser.y" /* yacc.c:1646  */
    {
  char buffer[1024];
  sprintf(buffer, "UPPER(%s)", (yyvsp[-1].strval));
  (yyval.strval) = strdup(buffer);
  free((yyvsp[-1].strval));
}
#line 3310 "SQL_parser_.tab.c" /* yacc.c:1646  */
    break;


#line 3314 "SQL_parser_.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 955 "SQL_parser.y" /* yacc.c:1906  */


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
