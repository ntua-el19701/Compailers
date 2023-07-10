
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser/parser.y"

#include <cstdio>
#include <iostream>
#include "../lexer/lexer.hpp"
#include "../ast/ast.hpp"

#include <string>
using namespace std;


extern int lineno;
SymbolTable st;


/* Line 189 of yacc.c  */
#line 88 "parser/parser.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_eof = 0,
     T_and = 258,
     T_char = 259,
     T_div = 260,
     T_do = 261,
     T_else = 262,
     T_fun = 263,
     T_if = 264,
     T_int = 265,
     T_mod = 266,
     T_not = 267,
     T_nothing = 268,
     T_or = 269,
     T_ref = 270,
     T_return = 271,
     T_then = 272,
     T_var = 273,
     T_while = 274,
     T_writeInteger = 275,
     T_writeChar = 276,
     T_writeString = 277,
     T_id = 278,
     T_const_int = 279,
     T_const_char = 280,
     T_const_string = 281,
     T_geq = 282,
     T_leq = 283,
     T_assign = 284
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 15 "parser/parser.y"
   
   AST *program;
   int num;
   char *id;
   char op;
   char *const_char;
   char *const_str;
   Expr *expr;
   Stmt *stmt;
   Cond *cond; 
   Block *stmt_list;
   Func_def *func_def;
   Local_def_gen *local_def_gen;
   Header *header;
   Fpar_def_gen *fpar_def_gen;
   Fpar_def *fpar_def;
   Comma_id_gen *comma_id_gen;
   Type_gen *type_gen;
   Typos typos;
   Type *type;
   Ret_type *ret_type;
   Fpar_type *fpar_type;
   Local_def *local_def;
   Func_decl *func_decl;
   Var_def *var_def;
   Func_call_stmt *func_call_stmt;
   Func_call_expr *func_call_expr;
   Comma_expr_gen *comma_expr_gen;
   L_value *l_value;
   Expr *expr_high;
   Cond *cond_high;
 



/* Line 214 of yacc.c  */
#line 190 "parser/parser.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 202 "parser/parser.cpp"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   251

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNRULES -- Number of states.  */
#define YYNSTATES  173

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    31,     2,     2,     2,     2,
      37,    38,    36,    34,    41,    35,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    39,    40,
      33,    30,    32,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,    45,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     9,    10,    13,    20,    29,    30,
      34,    40,    45,    46,    50,    52,    54,    57,    58,    63,
      65,    67,    72,    75,    77,    79,    81,    84,    91,    93,
      98,   100,   103,   108,   115,   120,   123,   127,   133,   139,
     145,   151,   157,   161,   162,   165,   169,   175,   179,   185,
     186,   190,   192,   194,   199,   201,   203,   205,   207,   209,
     213,   217,   221,   225,   229,   233,   236,   239,   241,   245,
     249,   253,   257,   261,   265,   269,   273,   277
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    48,    -1,    50,    49,    63,    -1,    -1,
      59,    49,    -1,     8,    23,    37,    38,    39,    57,    -1,
       8,    23,    37,    52,    51,    38,    39,    57,    -1,    -1,
      40,    52,    51,    -1,    15,    23,    53,    39,    58,    -1,
      23,    53,    39,    58,    -1,    -1,    41,    23,    53,    -1,
      10,    -1,     4,    -1,    54,    56,    -1,    -1,    42,    24,
      43,    56,    -1,    54,    -1,    13,    -1,    54,    42,    43,
      56,    -1,    54,    56,    -1,    48,    -1,    60,    -1,    61,
      -1,    50,    40,    -1,    18,    23,    53,    39,    55,    40,
      -1,    40,    -1,    68,    29,    69,    40,    -1,    63,    -1,
      65,    40,    -1,     9,    71,    17,    62,    -1,     9,    71,
      17,    62,     7,    62,    -1,    19,    71,     6,    62,    -1,
      16,    40,    -1,    16,    69,    40,    -1,    20,    37,    23,
      38,    40,    -1,    20,    37,    24,    38,    40,    -1,    21,
      37,    23,    38,    40,    -1,    22,    37,    23,    38,    40,
      -1,    22,    37,    26,    38,    40,    -1,    44,    64,    45,
      -1,    -1,    64,    62,    -1,    23,    37,    38,    -1,    23,
      37,    69,    67,    38,    -1,    23,    37,    38,    -1,    23,
      37,    69,    67,    38,    -1,    -1,    41,    69,    67,    -1,
      23,    -1,    26,    -1,    68,    42,    69,    43,    -1,    24,
      -1,    25,    -1,    68,    -1,    70,    -1,    66,    -1,    69,
      34,    69,    -1,    69,    35,    69,    -1,    69,    36,    69,
      -1,    69,     5,    69,    -1,    69,    11,    69,    -1,    37,
      69,    38,    -1,    34,    69,    -1,    35,    69,    -1,    72,
      -1,    71,     3,    71,    -1,    71,    14,    71,    -1,    69,
      30,    69,    -1,    69,    31,    69,    -1,    69,    32,    69,
      -1,    69,    33,    69,    -1,    69,    27,    69,    -1,    69,
      28,    69,    -1,    37,    71,    38,    -1,    12,    71,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   126,   126,   130,   134,   135,   139,   140,   144,   145,
     149,   150,   154,   155,   159,   160,   164,   168,   169,   173,
     174,   178,   179,   183,   184,   185,   189,   193,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   214,   218,   219,   223,   224,   228,   229,   234,
     235,   239,   240,   241,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   258,   259,   260,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   276,   277
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "T_eof", "error", "$undefined", "\"and\"", "\"char\"", "\"div\"",
  "\"do\"", "\"else\"", "\"fun\"", "\"if\"", "\"int\"", "\"mod\"",
  "\"not\"", "\"nothing\"", "\"or\"", "\"ref\"", "\"return\"", "\"then\"",
  "\"var\"", "\"while\"", "\"writeInteger\"", "\"writeChar\"",
  "\"writeString\"", "T_id", "\"const_int\"", "T_const_char",
  "T_const_string", "\">=\"", "\"<=\"", "\"<-\"", "'='", "'#'", "'>'",
  "'<'", "'+'", "'-'", "'*'", "'('", "')'", "':'", "';'", "','", "'['",
  "']'", "'{'", "'}'", "$accept", "program", "func_def", "local_def_gen",
  "header", "fpar_def_gen", "fpar_def", "comma_id_gen", "data_type",
  "type", "type_gen", "ret_type", "fpar_type", "local_def", "func_decl",
  "var_def", "stmt", "block", "stmt_list", "func_call_stmt",
  "func_call_expr", "comma_expr_gen", "l_value", "expr", "expr_high",
  "cond", "cond_high", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      61,    35,    62,    60,    43,    45,    42,    40,    41,    58,
      59,    44,    91,    93,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    49,    49,    50,    50,    51,    51,
      52,    52,    53,    53,    54,    54,    55,    56,    56,    57,
      57,    58,    58,    59,    59,    59,    60,    61,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    63,    64,    64,    65,    65,    66,    66,    67,
      67,    68,    68,    68,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    70,    70,    70,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    72,    72
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     0,     2,     6,     8,     0,     3,
       5,     4,     0,     3,     1,     1,     2,     0,     4,     1,
       1,     4,     2,     1,     1,     1,     2,     6,     1,     4,
       1,     2,     4,     6,     4,     2,     3,     5,     5,     5,
       5,     5,     3,     0,     2,     3,     5,     3,     5,     0,
       3,     1,     1,     4,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     2,     2,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     4,     0,     1,     0,    23,     0,
       4,     4,    24,    25,     0,    12,    43,     3,    26,     5,
       0,    12,     0,     8,     0,     0,     0,    12,     0,     0,
       0,     0,    12,     0,     0,     0,     0,     0,     0,     0,
      51,    52,    28,    42,    44,    30,     0,     0,     0,     0,
      15,    14,    20,    19,     6,     8,     0,    13,    17,     0,
       0,    51,    54,    55,     0,     0,     0,    58,    56,     0,
      57,     0,    67,     0,    35,     0,     0,     0,     0,     0,
       0,    31,     0,     0,     0,    17,    11,     9,     0,     0,
      16,    27,    77,     0,    65,    66,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    36,     0,     0,     0,     0,     0,     0,
      45,    49,     0,     0,    10,     0,    22,     7,     0,    47,
      49,    64,    76,    62,    63,    74,    75,    70,    71,    72,
      73,    59,    60,    61,    68,    69,    32,    34,     0,     0,
       0,     0,     0,     0,     0,    29,    53,    17,    17,     0,
       0,    37,    38,    39,    40,    41,    49,    46,    21,    18,
      48,    33,    50
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,     9,    10,    31,    23,    25,    53,    59,
      90,    54,    86,    11,    12,    13,    44,    45,    26,    46,
      67,   154,    68,    69,    70,    71,    72
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -117
static const yytype_int16 yypact[] =
{
       8,    58,    25,  -117,     1,    46,  -117,    61,  -117,    42,
       4,     1,  -117,  -117,     5,    64,  -117,  -117,  -117,  -117,
      86,    64,    73,    82,   100,    91,    71,    64,   105,   104,
     103,    94,    64,   139,   166,   170,   166,   108,   122,   123,
     124,  -117,  -117,  -117,  -117,  -117,    99,    53,   128,   139,
    -117,  -117,  -117,  -117,  -117,    82,   133,  -117,   131,   134,
     166,   125,  -117,  -117,   209,   209,   166,  -117,   155,   152,
    -117,    12,  -117,   209,  -117,    93,    49,    37,   153,    -2,
     188,  -117,   209,   209,   139,   156,  -117,  -117,   104,   151,
    -117,  -117,   107,   193,    -1,    -1,   120,    20,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   166,
     166,    80,   130,  -117,    80,   143,   161,   164,   168,   171,
    -117,     6,   102,     2,  -117,    32,  -117,  -117,   165,  -117,
       6,  -117,  -117,  -117,  -117,   135,   135,   135,   135,   135,
     135,    -1,    -1,  -117,   163,  -117,   208,  -117,   180,   181,
     184,   189,   196,   209,   199,  -117,  -117,   131,   131,   200,
      80,  -117,  -117,  -117,  -117,  -117,     6,  -117,  -117,  -117,
    -117,  -117,  -117
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -117,  -117,   239,   229,   241,   187,   215,    30,   -31,  -117,
     -79,   159,   167,  -117,  -117,  -117,  -106,   240,  -117,  -117,
    -117,  -116,   -26,   -34,  -117,   -33,  -117
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      47,    75,    58,    76,    98,   146,   126,    98,   147,     1,
      99,    98,     1,    99,   159,   109,     1,    99,    85,     7,
      20,   118,     7,   109,   119,     6,   110,    92,    21,   111,
      94,    95,    96,    97,   110,   108,   106,   107,   108,   112,
     106,   107,   108,    22,    18,   156,   121,   153,   122,   123,
     172,    28,   109,    85,   171,   114,   128,    48,   132,   130,
     115,   116,    57,   110,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   157,   144,   145,   168,   169,
      34,     5,    82,    14,    15,    47,    16,    35,    47,    34,
      36,    37,    38,    39,    40,    83,    35,    41,    98,    36,
      37,    38,    39,    40,    99,    24,    41,    98,    50,    27,
     109,    42,    29,    99,    51,    16,    43,    52,    20,   166,
      42,   110,    30,    32,    16,    98,    21,   106,   107,   108,
      33,    99,    56,   113,    47,    98,   106,   107,   108,    81,
      98,    99,   155,    50,    49,    77,    99,   100,   101,    51,
     102,   103,   104,   105,   106,   107,   108,    98,   131,    78,
      79,    80,    93,    99,   106,   107,   108,    84,   131,   106,
     107,   108,    88,    89,    91,   128,   117,   110,    60,   100,
     101,   148,   102,   103,   104,   105,   106,   107,   108,    61,
      62,    63,    41,    61,    62,    63,    41,    83,   125,   149,
      64,    65,   150,    66,    64,    65,   151,    73,   158,   152,
      74,    61,    62,    63,    41,   160,    61,    62,    63,    41,
     161,   162,    64,    65,   163,    73,   120,    64,    65,   164,
      73,   129,    61,    62,    63,    41,   165,   167,   170,     3,
      19,     4,    87,    64,    65,    55,    73,   127,     0,    17,
       0,   124
};

static const yytype_int16 yycheck[] =
{
      26,    35,    33,    36,     5,   111,    85,     5,   114,     8,
      11,     5,     8,    11,   130,     3,     8,    11,    49,    18,
      15,    23,    18,     3,    26,     0,    14,    60,    23,    17,
      64,    65,    66,    66,    14,    36,    34,    35,    36,    73,
      34,    35,    36,    38,    40,    43,    80,    41,    82,    83,
     166,    21,     3,    84,   160,     6,    24,    27,    38,    93,
      23,    24,    32,    14,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    43,   109,   110,   157,   158,
       9,    23,    29,    37,    23,   111,    44,    16,   114,     9,
      19,    20,    21,    22,    23,    42,    16,    26,     5,    19,
      20,    21,    22,    23,    11,    41,    26,     5,     4,    23,
       3,    40,    39,    11,    10,    44,    45,    13,    15,   153,
      40,    14,    40,    23,    44,     5,    23,    34,    35,    36,
      39,    11,    38,    40,   160,     5,    34,    35,    36,    40,
       5,    11,    40,     4,    39,    37,    11,    27,    28,    10,
      30,    31,    32,    33,    34,    35,    36,     5,    38,    37,
      37,    37,    37,    11,    34,    35,    36,    39,    38,    34,
      35,    36,    39,    42,    40,    24,    23,    14,    12,    27,
      28,    38,    30,    31,    32,    33,    34,    35,    36,    23,
      24,    25,    26,    23,    24,    25,    26,    42,    42,    38,
      34,    35,    38,    37,    34,    35,    38,    37,    43,    38,
      40,    23,    24,    25,    26,     7,    23,    24,    25,    26,
      40,    40,    34,    35,    40,    37,    38,    34,    35,    40,
      37,    38,    23,    24,    25,    26,    40,    38,    38,     0,
      11,     0,    55,    34,    35,    30,    37,    88,    -1,     9,
      -1,    84
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    47,    48,    50,    23,     0,    18,    48,    49,
      50,    59,    60,    61,    37,    23,    44,    63,    40,    49,
      15,    23,    38,    52,    41,    53,    64,    23,    53,    39,
      40,    51,    23,    39,     9,    16,    19,    20,    21,    22,
      23,    26,    40,    45,    62,    63,    65,    68,    53,    39,
       4,    10,    13,    54,    57,    52,    38,    53,    54,    55,
      12,    23,    24,    25,    34,    35,    37,    66,    68,    69,
      70,    71,    72,    37,    40,    69,    71,    37,    37,    37,
      37,    40,    29,    42,    39,    54,    58,    51,    39,    42,
      56,    40,    71,    37,    69,    69,    69,    71,     5,    11,
      27,    28,    30,    31,    32,    33,    34,    35,    36,     3,
      14,    17,    69,    40,     6,    23,    24,    23,    23,    26,
      38,    69,    69,    69,    58,    42,    56,    57,    24,    38,
      69,    38,    38,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    71,    71,    62,    62,    38,    38,
      38,    38,    38,    41,    67,    40,    43,    43,    43,    67,
       7,    40,    40,    40,    40,    40,    69,    38,    56,    56,
      38,    62,    67
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 126 "parser/parser.y"
    {  std::cout << *(yyvsp[(1) - (1)].func_def);;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 130 "parser/parser.y"
    { (yyvsp[(1) - (3)].header)->sem(); (yyval.func_def) = new Func_def((yyvsp[(1) - (3)].header), (yyvsp[(2) - (3)].local_def_gen), (yyvsp[(3) - (3)].stmt_list));  st.closeScope();;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 134 "parser/parser.y"
    { (yyval.local_def_gen) = nullptr; ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 135 "parser/parser.y"
    { (yyval.local_def_gen) = new Local_def_gen((yyvsp[(1) - (2)].local_def), (yyvsp[(2) - (2)].local_def_gen)); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 139 "parser/parser.y"
    { (yyval.header) = new Header((yyvsp[(2) - (6)].id), nullptr, nullptr, (yyvsp[(6) - (6)].ret_type)); ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 140 "parser/parser.y"
    { (yyval.header) = new Header((yyvsp[(2) - (8)].id), (yyvsp[(4) - (8)].fpar_def), (yyvsp[(5) - (8)].fpar_def_gen), (yyvsp[(8) - (8)].ret_type)); ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 144 "parser/parser.y"
    { (yyval.fpar_def_gen) = nullptr; ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 145 "parser/parser.y"
    { (yyval.fpar_def_gen) = new Fpar_def_gen((yyvsp[(2) - (3)].fpar_def), (yyvsp[(3) - (3)].fpar_def_gen)); ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 149 "parser/parser.y"
    { (yyval.fpar_def) = new Fpar_def(true, (yyvsp[(2) - (5)].id), (yyvsp[(3) - (5)].comma_id_gen), (yyvsp[(5) - (5)].fpar_type)); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 150 "parser/parser.y"
    { (yyval.fpar_def) = new Fpar_def(false, (yyvsp[(1) - (4)].id), (yyvsp[(2) - (4)].comma_id_gen), (yyvsp[(4) - (4)].fpar_type)); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 154 "parser/parser.y"
    { (yyval.comma_id_gen) = nullptr; ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 155 "parser/parser.y"
    { (yyval.comma_id_gen) = new Comma_id_gen((yyvsp[(2) - (3)].id), (yyvsp[(3) - (3)].comma_id_gen)); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 159 "parser/parser.y"
    { (yyval.typos) =  TYPE_int; ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 160 "parser/parser.y"
    { (yyval.typos) =  TYPE_char; ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 164 "parser/parser.y"
    { (yyval.type) = new Type((yyvsp[(1) - (2)].typos), (yyvsp[(2) - (2)].type_gen)); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 168 "parser/parser.y"
    { (yyval.type_gen) = nullptr; ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 169 "parser/parser.y"
    { (yyval.type_gen) = new Type_gen((yyvsp[(2) - (4)].num), (yyvsp[(4) - (4)].type_gen)); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 173 "parser/parser.y"
    { (yyval.ret_type) = new Ret_type((yyvsp[(1) - (1)].typos)); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 174 "parser/parser.y"
    { (yyval.ret_type) = new Ret_type(TYPE_nothing); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 178 "parser/parser.y"
    { (yyval.fpar_type) = new Fpar_type((yyvsp[(1) - (4)].typos), (yyvsp[(4) - (4)].type_gen), 1); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 179 "parser/parser.y"
    { (yyval.fpar_type) = new Fpar_type((yyvsp[(1) - (2)].typos), (yyvsp[(2) - (2)].type_gen), 0); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 183 "parser/parser.y"
    { (yyval.local_def) = new Local_def((yyvsp[(1) - (1)].func_def), nullptr, nullptr); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 184 "parser/parser.y"
    { (yyval.local_def) = new Local_def(nullptr, (yyvsp[(1) - (1)].func_decl), nullptr); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 185 "parser/parser.y"
    { (yyval.local_def) = new Local_def(nullptr, nullptr, (yyvsp[(1) - (1)].var_def)); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 189 "parser/parser.y"
    { (yyval.func_decl) = new Func_decl((yyvsp[(1) - (2)].header)); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 193 "parser/parser.y"
    { (yyval.var_def) = new Var_def((yyvsp[(2) - (6)].id), (yyvsp[(3) - (6)].comma_id_gen), (yyvsp[(5) - (6)].type)); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 197 "parser/parser.y"
    { (yyval.stmt) = nullptr; ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 198 "parser/parser.y"
    { (yyval.stmt) = new Assign((yyvsp[(1) - (4)].l_value), (yyvsp[(3) - (4)].expr)); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 199 "parser/parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt_list); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 200 "parser/parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (2)].func_call_stmt); ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 201 "parser/parser.y"
    { (yyval.stmt) = new If((yyvsp[(2) - (4)].cond), (yyvsp[(4) - (4)].stmt), nullptr); ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 202 "parser/parser.y"
    { (yyval.stmt) = new If((yyvsp[(2) - (6)].cond), (yyvsp[(4) - (6)].stmt), (yyvsp[(6) - (6)].stmt)); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 203 "parser/parser.y"
    { (yyval.stmt) = new While((yyvsp[(2) - (4)].cond), (yyvsp[(4) - (4)].stmt)); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 204 "parser/parser.y"
    { (yyval.stmt) = new Return(nullptr); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 205 "parser/parser.y"
    { (yyval.stmt) = new Return((yyvsp[(2) - (3)].expr)); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 206 "parser/parser.y"
    { (yyval.stmt) = new Write_Integer((yyvsp[(3) - (5)].id), -1); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 207 "parser/parser.y"
    { (yyval.stmt) = new Write_Integer(nullptr, (yyvsp[(3) - (5)].num)); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 208 "parser/parser.y"
    { (yyval.stmt) = new Write_Char((yyvsp[(3) - (5)].id)); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 209 "parser/parser.y"
    { (yyval.stmt) = new Write_String((yyvsp[(3) - (5)].id),nullptr,0); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 210 "parser/parser.y"
    { (yyval.stmt) = new Write_String(nullptr,(yyvsp[(3) - (5)].const_str),1); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 214 "parser/parser.y"
    { (yyval.stmt_list) = (yyvsp[(2) - (3)].stmt_list);  ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 218 "parser/parser.y"
    { (yyval.stmt_list) = new Block(); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 219 "parser/parser.y"
    { (yyvsp[(1) - (2)].stmt_list)->append_stmt((yyvsp[(2) - (2)].stmt)); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 223 "parser/parser.y"
    { (yyval.func_call_stmt) = new Func_call_stmt((yyvsp[(1) - (3)].id), nullptr, nullptr); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 224 "parser/parser.y"
    { (yyval.func_call_stmt) = new Func_call_stmt((yyvsp[(1) - (5)].id), (yyvsp[(3) - (5)].expr), (yyvsp[(4) - (5)].comma_expr_gen)); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 228 "parser/parser.y"
    { (yyval.func_call_expr) = new Func_call_expr((yyvsp[(1) - (3)].id), nullptr, nullptr); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 229 "parser/parser.y"
    { (yyval.func_call_expr) = new Func_call_expr((yyvsp[(1) - (5)].id), (yyvsp[(3) - (5)].expr), (yyvsp[(4) - (5)].comma_expr_gen)); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 234 "parser/parser.y"
    { (yyval.comma_expr_gen) = nullptr; ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 235 "parser/parser.y"
    { (yyval.comma_expr_gen) = new Comma_expr_gen((yyvsp[(2) - (3)].expr), (yyvsp[(3) - (3)].comma_expr_gen)); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 239 "parser/parser.y"
    { (yyval.l_value) = new L_value(nullptr,nullptr,(yyvsp[(1) - (1)].id),nullptr,1); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 240 "parser/parser.y"
    { (yyval.l_value) = new L_value(nullptr, nullptr, nullptr, (yyvsp[(1) - (1)].const_str),2); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 241 "parser/parser.y"
    { (yyval.l_value) = new L_value((yyvsp[(1) - (4)].l_value), (yyvsp[(3) - (4)].expr),nullptr, nullptr,3 ); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 245 "parser/parser.y"
    { (yyval.expr) = new IntConst((yyvsp[(1) - (1)].num)); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 246 "parser/parser.y"
    { (yyval.expr) = new Const_char((yyvsp[(1) - (1)].const_char)); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 247 "parser/parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].l_value); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 248 "parser/parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr_high); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 249 "parser/parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].func_call_expr); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 250 "parser/parser.y"
    { (yyval.expr) = new BinOp((yyvsp[(1) - (3)].expr),"+",(yyvsp[(3) - (3)].expr)); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 251 "parser/parser.y"
    { (yyval.expr) = new BinOp((yyvsp[(1) - (3)].expr),"-",(yyvsp[(3) - (3)].expr)); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 252 "parser/parser.y"
    { (yyval.expr) = new BinOp((yyvsp[(1) - (3)].expr),"*",(yyvsp[(3) - (3)].expr)); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 253 "parser/parser.y"
    { (yyval.expr) = new BinOp((yyvsp[(1) - (3)].expr),"/",(yyvsp[(3) - (3)].expr)); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 254 "parser/parser.y"
    { (yyval.expr) = new BinOp((yyvsp[(1) - (3)].expr),"%",(yyvsp[(3) - (3)].expr)); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 258 "parser/parser.y"
    { (yyval.expr_high) = (yyvsp[(2) - (3)].expr); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 259 "parser/parser.y"
    { (yyval.expr_high) = new UnOp('+', (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 260 "parser/parser.y"
    { (yyval.expr_high) = new UnOp('-', (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 264 "parser/parser.y"
    { (yyval.cond) = (yyvsp[(1) - (1)].cond_high); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 265 "parser/parser.y"
    { (yyval.cond) = new Cond((yyvsp[(1) - (3)].cond), "&&", (yyvsp[(3) - (3)].cond)); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 266 "parser/parser.y"
    { (yyval.cond) = new Cond((yyvsp[(1) - (3)].cond), "||", (yyvsp[(3) - (3)].cond)); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 267 "parser/parser.y"
    { (yyval.cond) = new Compare((yyvsp[(1) - (3)].expr), "=", (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 268 "parser/parser.y"
    { (yyval.cond) = new Compare((yyvsp[(1) - (3)].expr), "#", (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 269 "parser/parser.y"
    { (yyval.cond) = new Compare((yyvsp[(1) - (3)].expr), ">", (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 270 "parser/parser.y"
    { (yyval.cond) = new Compare((yyvsp[(1) - (3)].expr), "<", (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 271 "parser/parser.y"
    { (yyval.cond) = new Compare((yyvsp[(1) - (3)].expr), ">=", (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 272 "parser/parser.y"
    { (yyval.cond) = new Compare((yyvsp[(1) - (3)].expr), "<=", (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 276 "parser/parser.y"
    { (yyval.cond_high) = (yyvsp[(2) - (3)].cond); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 277 "parser/parser.y"
    { (yyval.cond_high) = new Cond((yyvsp[(2) - (2)].cond),"!",nullptr); ;}
    break;



/* Line 1455 of yacc.c  */
#line 2089 "parser/parser.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 284 "parser/parser.y"


int main() {
  int result = yyparse();
  if (result == 0) printf("Success.\n");
  return result;

}
