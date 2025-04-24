/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     AND = 258,
     OR = 259,
     NOT = 260,
     BOOL = 261,
     TRUE = 262,
     FALSE = 263,
     DEF = 264,
     MAIN = 265,
     IF = 266,
     ELSE = 267,
     ELIF = 268,
     WHILE = 269,
     FOR = 270,
     DO = 271,
     VAR = 272,
     BEGIN_TOKEN = 273,
     CALL = 274,
     END = 275,
     RETURN = 276,
     RETURNS = 277,
     NULL_T = 278,
     REAL = 279,
     STRING = 280,
     TYPE = 281,
     CHAR = 282,
     INT = 283,
     INT_LITERAL = 284,
     REAL_LITERAL = 285,
     INT_PTR = 286,
     CHAR_PTR = 287,
     REAL_PTR = 288,
     ID = 289,
     STRING_LITERAL = 290,
     CHAR_LITERAL = 291,
     EQ = 292,
     NEQ = 293,
     GE = 294,
     LE = 295,
     GT = 296,
     LT = 297,
     SEMICOLON = 298,
     COMMA = 299,
     LPAREN = 300,
     RPAREN = 301,
     LBRACKET = 302,
     RBRACKET = 303,
     LBRACE = 304,
     RBRACE = 305,
     COLON = 306,
     LOWER_THAN_ELSE = 307
   };
#endif
/* Tokens.  */
#define AND 258
#define OR 259
#define NOT 260
#define BOOL 261
#define TRUE 262
#define FALSE 263
#define DEF 264
#define MAIN 265
#define IF 266
#define ELSE 267
#define ELIF 268
#define WHILE 269
#define FOR 270
#define DO 271
#define VAR 272
#define BEGIN_TOKEN 273
#define CALL 274
#define END 275
#define RETURN 276
#define RETURNS 277
#define NULL_T 278
#define REAL 279
#define STRING 280
#define TYPE 281
#define CHAR 282
#define INT 283
#define INT_LITERAL 284
#define REAL_LITERAL 285
#define INT_PTR 286
#define CHAR_PTR 287
#define REAL_PTR 288
#define ID 289
#define STRING_LITERAL 290
#define CHAR_LITERAL 291
#define EQ 292
#define NEQ 293
#define GE 294
#define LE 295
#define GT 296
#define LT 297
#define SEMICOLON 298
#define COMMA 299
#define LPAREN 300
#define RPAREN 301
#define LBRACKET 302
#define RBRACKET 303
#define LBRACE 304
#define RBRACE 305
#define COLON 306
#define LOWER_THAN_ELSE 307




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int yylex();
int yyerror(const char*);

int main_count = 0; // סופר את מספר הופעות main
int has_return = 0;
int last_param_number = 0;
typedef struct node
{
    char *token;
    struct node *left;
    struct node *right;
    } node;
node *mknode(char *token, node *left, node *right);
void printtree(node *tree,int depth);
void print_ast_graphical(node* tree, const char* prefix, int is_left);
int is_number(const char* str);
void print_tree(node *n);


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 27 "parser.y"
{
    int intVal;
    float realVal;
    char charVal;
    char* stringVal;
    node* node;
}
/* Line 193 of yacc.c.  */
#line 233 "parser.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 246 "parser.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   328

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNRULES -- Number of states.  */
#define YYNSTATES  238

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    58,    52,     2,
       2,     2,    56,    54,    59,    55,     2,    57,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    60,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    61,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    53
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    18,    30,    40,    41,
      44,    45,    49,    52,    57,    62,    68,    72,    74,    81,
      86,    90,    92,    96,    98,   103,   107,   110,   111,   114,
     118,   120,   121,   126,   128,   130,   132,   134,   136,   138,
     140,   145,   147,   152,   158,   162,   164,   165,   171,   179,
     181,   183,   185,   187,   189,   191,   193,   195,   197,   202,
     210,   216,   222,   227,   235,   243,   249,   254,   260,   265,
     273,   284,   289,   299,   303,   305,   307,   309,   311,   313,
     317,   321,   325,   329,   332,   335,   340,   345,   350,   354,
     358,   361,   363,   365,   369,   373,   375,   377,   381,   385,
     387,   389,   391,   393,   395,   397,   401
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      63,     0,    -1,    64,    -1,    65,    -1,    65,    64,    -1,
       9,    10,    45,    46,    51,    67,    75,    -1,     9,    34,
      45,    66,    77,    46,    51,    22,    84,    67,    74,    -1,
       9,    34,    45,    66,    77,    46,    51,    67,    75,    -1,
      -1,    17,    68,    -1,    -1,    69,    43,    68,    -1,    69,
      43,    -1,    26,    84,    51,    72,    -1,    26,    25,    51,
      70,    -1,    26,    84,    56,    51,    72,    -1,    71,    59,
      70,    -1,    71,    -1,    34,    47,    29,    48,    51,    35,
      -1,    34,    47,    29,    48,    -1,    73,    44,    72,    -1,
      73,    -1,    34,    51,    93,    -1,    34,    -1,    18,    76,
      98,    20,    -1,    18,    76,    20,    -1,    79,    76,    -1,
      -1,    65,    76,    -1,    78,    43,    77,    -1,    78,    -1,
      -1,    34,    84,    51,    34,    -1,    80,    -1,    83,    -1,
      85,    -1,    86,    -1,    88,    -1,    90,    -1,    89,    -1,
      34,    60,    19,    81,    -1,    81,    -1,    67,    18,    76,
      20,    -1,    34,    45,    82,    46,    43,    -1,    93,    44,
      82,    -1,    93,    -1,    -1,    26,    84,    51,    34,    43,
      -1,    26,    84,    51,    34,    60,    93,    43,    -1,     6,
      -1,     7,    -1,     8,    -1,    27,    -1,    28,    -1,    24,
      -1,    31,    -1,    32,    -1,    33,    -1,    34,    60,    93,
      43,    -1,    34,    47,    93,    48,    60,    36,    43,    -1,
      56,    34,    60,    93,    43,    -1,    34,    60,    52,    34,
      43,    -1,    34,    60,    23,    43,    -1,    34,    47,    93,
      48,    60,    29,    43,    -1,    11,    94,    51,    79,    87,
      12,    79,    -1,    11,    94,    51,    79,    87,    -1,    11,
      94,    51,    79,    -1,    13,    94,    51,    79,    87,    -1,
      13,    94,    51,    79,    -1,    14,    94,    51,    67,    18,
      76,    20,    -1,    16,    51,    67,    18,    76,    20,    14,
      51,    94,    43,    -1,    15,    91,    51,    79,    -1,    45,
      34,    60,    93,    43,    94,    43,    92,    46,    -1,    34,
      60,    93,    -1,    29,    -1,    30,    -1,    36,    -1,    35,
      -1,    34,    -1,    93,    54,    93,    -1,    93,    55,    93,
      -1,    93,    56,    93,    -1,    93,    57,    93,    -1,    55,
      93,    -1,    52,    93,    -1,    34,    45,    82,    46,    -1,
      34,    47,    93,    48,    -1,    56,    45,    93,    46,    -1,
      61,    93,    61,    -1,    93,    97,    93,    -1,     5,    94,
      -1,    95,    -1,    96,    -1,    93,     3,    93,    -1,    93,
       4,    93,    -1,     8,    -1,     7,    -1,    45,     8,    46,
      -1,    45,     7,    46,    -1,    37,    -1,    38,    -1,    41,
      -1,    39,    -1,    42,    -1,    40,    -1,    21,    93,    43,
      -1,    21,    94,    43,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    77,    77,    89,    91,    96,   116,   142,   157,   162,
     163,   167,   169,   175,   177,   179,   184,   186,   192,   202,
     214,   215,   220,   222,   227,   233,   238,   243,   246,   254,
     258,   263,   269,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   298,   303,   307,   308,   309,   314,   316,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   333,   335,
     337,   339,   341,   343,   353,   362,   369,   379,   386,   396,
     401,   406,   411,   416,   421,   426,   431,   436,   439,   442,
     443,   444,   445,   446,   455,   464,   465,   466,   467,   477,
     479,   481,   483,   489,   490,   495,   496,   497,   498,   502,
     503,   504,   505,   506,   507,   512,   514
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AND", "OR", "NOT", "BOOL", "TRUE",
  "FALSE", "DEF", "MAIN", "IF", "ELSE", "ELIF", "WHILE", "FOR", "DO",
  "VAR", "BEGIN_TOKEN", "CALL", "END", "RETURN", "RETURNS", "NULL_T",
  "REAL", "STRING", "TYPE", "CHAR", "INT", "INT_LITERAL", "REAL_LITERAL",
  "INT_PTR", "CHAR_PTR", "REAL_PTR", "ID", "STRING_LITERAL",
  "CHAR_LITERAL", "EQ", "NEQ", "GE", "LE", "GT", "LT", "SEMICOLON",
  "COMMA", "LPAREN", "RPAREN", "LBRACKET", "RBRACKET", "LBRACE", "RBRACE",
  "COLON", "'&'", "LOWER_THAN_ELSE", "'+'", "'-'", "'*'", "'/'", "'%'",
  "','", "'='", "'|'", "$accept", "code", "functions", "function",
  "reset_param_counter", "variables", "var_statements", "variable",
  "string_ids", "string_id", "ids", "id", "body", "body_main",
  "statements", "parameters", "parameter", "statement", "block_statement",
  "call_statement", "params", "declaration_statement", "type",
  "assignment_statement", "if_statement", "elif_statements",
  "while_statement", "do_statement", "for_statement", "for_header",
  "update_expression", "expression", "condition", "boolean_expression",
  "bool_type", "comparison_operator", "return_statement", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,    38,   307,    43,    45,    42,    47,    37,    44,
      61,   124
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    64,    65,    65,    65,    66,    67,
      67,    68,    68,    69,    69,    69,    70,    70,    71,    71,
      72,    72,    73,    73,    74,    75,    76,    76,    76,    77,
      77,    77,    78,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    80,    81,    82,    82,    82,    83,    83,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    85,    85,
      85,    85,    85,    85,    86,    86,    86,    87,    87,    88,
      89,    90,    91,    92,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    94,
      94,    94,    94,    95,    95,    96,    96,    96,    96,    97,
      97,    97,    97,    97,    97,    98,    98
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     7,    11,     9,     0,     2,
       0,     3,     2,     4,     4,     5,     3,     1,     6,     4,
       3,     1,     3,     1,     4,     3,     2,     0,     2,     3,
       1,     0,     4,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     4,     5,     3,     1,     0,     5,     7,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     7,
       5,     5,     4,     7,     7,     5,     4,     5,     4,     7,
      10,     4,     9,     3,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     2,     2,     4,     4,     4,     3,     3,
       2,     1,     1,     3,     3,     1,     1,     3,     3,     1,
       1,     1,     1,     1,     1,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     3,     0,     0,     1,     4,     0,
       8,     0,    31,    10,     0,     0,    30,     0,     0,    49,
      50,    51,    54,    52,    53,    55,    56,    57,     0,     0,
      31,     0,     9,     0,    10,     5,     0,    10,    29,     0,
       0,    12,     0,     0,     0,     0,     0,     0,     0,    27,
       0,     0,    27,    33,    41,    34,    35,    36,    37,    39,
      38,    32,     0,     0,     0,     0,     0,    11,     0,    96,
      95,    74,    75,    78,    77,    76,     0,     0,     0,     0,
       0,     0,     0,    91,    92,     0,     0,     0,    10,     0,
      46,     0,     0,     0,    28,    10,    25,    26,    10,     7,
       0,    14,    17,    23,    13,    21,     0,    90,    46,     0,
       0,     0,    84,    83,     0,     0,     0,     0,    99,   100,
     102,   104,   101,   103,     0,     0,     0,     0,     0,    10,
      10,     0,    10,     0,     0,     0,    45,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    15,
       0,     0,    98,    97,     0,    88,    93,    94,    79,    80,
      81,    82,    89,    66,     0,     0,    71,    10,     0,     0,
      46,     0,     0,    40,    62,    78,    58,     0,    42,    10,
       6,     0,    16,    22,    20,    85,    86,    87,     0,    65,
      10,     0,     0,    47,     0,    43,    44,     0,    61,    60,
       0,    19,     0,    10,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    64,    69,     0,     0,    48,    63,
      59,     0,     0,    24,    18,    68,     0,     0,   105,   106,
      67,     0,     0,     0,     0,    72,    70,    73
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    49,    12,    50,    32,    33,   101,   102,
     104,   105,   180,    35,    51,    15,    16,    52,    53,    54,
     135,    55,    28,    56,    57,   189,    58,    59,    60,    87,
     232,    81,    82,    83,    84,   128,   211
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -124
static const yytype_int16 yypact[] =
{
      -1,     1,    20,  -124,    -1,   -15,    -9,  -124,  -124,    10,
    -124,    12,    31,    52,   123,    27,    44,    65,    77,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,    47,    48,
      31,   289,  -124,    70,   188,  -124,    90,     6,  -124,    81,
     -25,    65,    67,    67,    88,    93,   123,   -26,    92,    28,
     128,   129,    28,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,   123,    77,   119,   125,   106,  -124,    67,  -124,
    -124,  -124,  -124,    23,  -124,  -124,    75,   238,   238,   115,
     238,   139,   110,  -124,  -124,   117,   148,   134,    52,   140,
     238,   238,   227,   130,  -124,   188,  -124,  -124,    52,  -124,
     136,  -124,   133,   147,  -124,   156,   125,  -124,   238,   238,
     155,   160,   269,    29,   238,    60,   238,   238,  -124,  -124,
    -124,  -124,  -124,  -124,   238,   238,   238,   238,   238,   215,
      52,   149,   215,   189,   176,   166,     3,   221,   181,   177,
     251,    50,   238,   201,   206,   196,   119,   238,   125,  -124,
     187,   254,  -124,  -124,    54,  -124,   269,   269,    29,    29,
    -124,  -124,   269,   214,   216,   238,  -124,   188,   -31,   192,
     238,   178,   194,  -124,  -124,    34,  -124,    84,  -124,   202,
    -124,   195,  -124,   269,  -124,  -124,  -124,  -124,    67,   225,
     188,   109,   222,  -124,   238,  -124,  -124,   -12,  -124,  -124,
     224,   204,   208,   215,   228,    67,   233,   197,   217,   223,
      67,   244,   230,   215,  -124,  -124,   241,   219,  -124,  -124,
    -124,   132,   246,  -124,  -124,   214,   257,    67,  -124,  -124,
    -124,   232,   252,   258,   238,  -124,  -124,   269
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -124,  -124,   296,    18,  -124,   -10,   263,  -124,   159,  -124,
     -93,  -124,  -124,   255,   -42,   285,  -124,  -123,  -124,   190,
    -103,  -124,    30,  -124,  -124,    94,  -124,  -124,  -124,  -124,
    -124,   -76,   -43,  -124,  -124,  -124,  -124
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -28
static const yytype_int16 yytable[] =
{
      85,   112,   113,    18,   115,   150,   163,    94,     1,   166,
      97,     5,   193,   149,   136,   137,   141,   208,     4,    90,
       7,    91,     4,    17,   209,   107,    65,    63,    62,   194,
       9,    66,   136,   151,    92,     6,    10,     1,   154,    42,
     156,   157,    43,    44,    45,    17,   -10,   170,   158,   159,
     160,   161,   162,   143,    46,   184,    11,   124,   125,   126,
     127,    40,    47,    13,   112,    14,   177,   196,   108,    17,
     109,   183,    68,    29,    69,    70,    89,   198,   133,   108,
     214,   109,   110,   111,    48,   126,   127,    30,   144,   191,
     225,    31,    98,   176,   136,    34,    71,    72,    36,    37,
     187,    73,    74,    75,   124,   125,   126,   127,   124,   125,
     126,   127,    76,    41,   124,   125,   126,   127,   207,    77,
     164,   155,    78,    79,    61,   192,    93,   199,    80,    19,
      20,    21,    64,    86,   221,   116,   117,   200,   124,   125,
     126,   127,   116,   117,    88,   202,    95,    22,   204,    96,
      23,    24,   205,   100,    25,    26,    27,   106,   237,   103,
     114,   129,   216,   124,   125,   126,   127,   222,   130,   118,
     119,   120,   121,   122,   123,   228,   118,   119,   120,   121,
     122,   123,   131,   145,   233,   132,   124,   125,   126,   127,
     142,   134,   146,   124,   125,   126,   127,     1,   147,    42,
     148,   152,    43,    44,    45,    17,   153,   167,   -27,   165,
     168,     1,   169,    42,    46,   172,    43,    44,    45,    17,
     174,   178,    47,   -27,   179,   181,    42,   188,    46,    43,
      44,    45,    17,   185,   190,   195,    47,   203,   197,    90,
     218,    46,   206,   201,    48,   210,   138,   217,   215,    47,
     139,   124,   125,   126,   127,   212,    71,    72,    48,   213,
     219,    73,    74,    75,   223,   224,   220,    71,    72,   171,
     227,    48,    73,    74,    75,   124,   125,   126,   127,   140,
      71,    72,    78,    79,   226,   175,    74,    75,    80,   229,
      77,   231,   234,    78,    79,    19,    20,    21,   235,    80,
       8,   236,   186,    77,    67,   182,    78,    79,   124,   125,
     126,   127,    80,    22,    39,    38,    23,    24,    99,   230,
      25,    26,    27,   124,   125,   126,   127,     0,   173
};

static const yytype_int16 yycheck[] =
{
      43,    77,    78,    13,    80,   108,   129,    49,     9,   132,
      52,    10,    43,   106,    90,    91,    92,    29,     0,    45,
       0,    47,     4,    17,    36,    68,    51,    37,    22,    60,
      45,    56,   108,   109,    60,    34,    45,     9,   114,    11,
     116,   117,    14,    15,    16,    17,    18,    44,   124,   125,
     126,   127,   128,    95,    26,   148,    46,    54,    55,    56,
      57,    31,    34,    51,   140,    34,   142,   170,    45,    17,
      47,   147,     5,    46,     7,     8,    46,    43,    88,    45,
     203,    47,     7,     8,    56,    56,    57,    43,    98,   165,
     213,    26,    62,    43,   170,    18,    29,    30,    51,    51,
      46,    34,    35,    36,    54,    55,    56,    57,    54,    55,
      56,    57,    45,    43,    54,    55,    56,    57,   194,    52,
     130,    61,    55,    56,    34,   167,    34,    43,    61,     6,
       7,     8,    51,    45,   210,     3,     4,   179,    54,    55,
      56,    57,     3,     4,    51,   188,    18,    24,   190,    20,
      27,    28,    43,    34,    31,    32,    33,    51,   234,    34,
      45,    51,   205,    54,    55,    56,    57,   210,    51,    37,
      38,    39,    40,    41,    42,    43,    37,    38,    39,    40,
      41,    42,    34,    47,   227,    51,    54,    55,    56,    57,
      60,    51,    59,    54,    55,    56,    57,     9,    51,    11,
      44,    46,    14,    15,    16,    17,    46,    18,    20,    60,
      34,     9,    46,    11,    26,    34,    14,    15,    16,    17,
      43,    20,    34,    21,    18,    29,    11,    13,    26,    14,
      15,    16,    17,    46,    18,    43,    34,    12,    60,    45,
      43,    26,    20,    48,    56,    21,    19,    14,    20,    34,
      23,    54,    55,    56,    57,    51,    29,    30,    56,    51,
      43,    34,    35,    36,    20,    35,    43,    29,    30,    48,
      51,    56,    34,    35,    36,    54,    55,    56,    57,    52,
      29,    30,    55,    56,    43,    34,    35,    36,    61,    43,
      52,    34,    60,    55,    56,     6,     7,     8,    46,    61,
       4,    43,    48,    52,    41,   146,    55,    56,    54,    55,
      56,    57,    61,    24,    25,    30,    27,    28,    63,   225,
      31,    32,    33,    54,    55,    56,    57,    -1,   138
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    63,    64,    65,    10,    34,     0,    64,    45,
      45,    46,    66,    51,    34,    77,    78,    17,    67,     6,
       7,     8,    24,    27,    28,    31,    32,    33,    84,    46,
      43,    26,    68,    69,    18,    75,    51,    51,    77,    25,
      84,    43,    11,    14,    15,    16,    26,    34,    56,    65,
      67,    76,    79,    80,    81,    83,    85,    86,    88,    89,
      90,    34,    22,    67,    51,    51,    56,    68,     5,     7,
       8,    29,    30,    34,    35,    36,    45,    52,    55,    56,
      61,    93,    94,    95,    96,    94,    45,    91,    51,    84,
      45,    47,    60,    34,    76,    18,    20,    76,    84,    75,
      34,    70,    71,    34,    72,    73,    51,    94,    45,    47,
       7,     8,    93,    93,    45,    93,     3,     4,    37,    38,
      39,    40,    41,    42,    54,    55,    56,    57,    97,    51,
      51,    34,    51,    67,    51,    82,    93,    93,    19,    23,
      52,    93,    60,    76,    67,    47,    59,    51,    44,    72,
      82,    93,    46,    46,    93,    61,    93,    93,    93,    93,
      93,    93,    93,    79,    67,    60,    79,    18,    34,    46,
      44,    48,    34,    81,    43,    34,    43,    93,    20,    18,
      74,    29,    70,    93,    72,    46,    48,    46,    13,    87,
      18,    93,    76,    43,    60,    43,    82,    60,    43,    43,
      76,    48,    94,    12,    76,    43,    20,    93,    29,    36,
      21,    98,    51,    51,    79,    20,    94,    14,    43,    43,
      43,    93,    94,    20,    35,    79,    43,    51,    43,    43,
      87,    34,    92,    94,    60,    46,    43,    93
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
#line 78 "parser.y"
    {
            if (main_count == 0) {
                yyerror("Error: missing 'main' function.");
                YYABORT;
            }
            print_ast_graphical((yyvsp[(1) - (1)].node), "", 1);
            (yyval.node) = (yyvsp[(1) - (1)].node);
        ;}
    break;

  case 3:
#line 90 "parser.y"
    { (yyval.node) = mknode("Functions", (yyvsp[(1) - (1)].node), NULL); ;}
    break;

  case 4:
#line 92 "parser.y"
    { (yyval.node) = mknode("Functions", (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); ;}
    break;

  case 5:
#line 97 "parser.y"
    {
            main_count++;
            if (main_count > 1) {
                yyerror("Error: multiple 'main' functions.");
                YYABORT;
            }

            // Create the "Main Function" node
            (yyval.node) = mknode("Main Function",
                        mknode("main", NULL, NULL),
                        (yyvsp[(7) - (7)].node));

            // Add the variables to the binary tree (AST)
            if ((yyvsp[(6) - (7)].node)) { // Check if there are variables
                // Loop through the list of variables and add them to the AST
                (yyval.node) = mknode("Main Function with Variables", (yyval.node), (yyvsp[(6) - (7)].node));
            }
        ;}
    break;

  case 6:
#line 117 "parser.y"
    {
            if (!has_return) {
                yyerror("Error: non-main function must contain at least one return.");
                YYABORT;
            }
            has_return = 0;

            node *params_node =(yyvsp[(5) - (11)].node);
            node *type_node = mknode("ReturnType", mknode((yyvsp[(9) - (11)].stringVal), NULL, NULL), params_node);

            node *func_body;

            if ((yyvsp[(10) - (11)].node)) {
                node *vars_node = mknode("Variables", (yyvsp[(10) - (11)].node), (yyvsp[(11) - (11)].node));
                func_body = mknode("FunctionBody", type_node, vars_node);
            } else {
                func_body = mknode("FunctionBody", type_node, (yyvsp[(11) - (11)].node));
            }

            (yyval.node) = mknode("Function", mknode((yyvsp[(2) - (11)].stringVal), NULL, NULL), func_body);
        ;}
    break;

  case 7:
#line 143 "parser.y"
    {
                (yyval.node) = mknode("Function",
                            mknode((yyvsp[(2) - (9)].stringVal), NULL, NULL),
                            mknode("BodyMain",
                                mknode("Variables", (yyvsp[(8) - (9)].node), NULL),
                                (yyvsp[(9) - (9)].node)
                            ));
                //$$ = $1;
            ;}
    break;

  case 8:
#line 157 "parser.y"
    { last_param_number = 0;;}
    break;

  case 9:
#line 162 "parser.y"
    { (yyval.node) = (yyvsp[(2) - (2)].node); ;}
    break;

  case 10:
#line 163 "parser.y"
    { (yyval.node) = NULL; ;}
    break;

  case 11:
#line 168 "parser.y"
    { (yyval.node) = mknode("VarDecls", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 12:
#line 170 "parser.y"
    { (yyval.node) = mknode("VarDecls", (yyvsp[(1) - (2)].node), NULL); ;}
    break;

  case 13:
#line 176 "parser.y"
    { (yyval.node) = mknode("VarDecl", mknode((yyvsp[(2) - (4)].stringVal),NULL,NULL), (yyvsp[(4) - (4)].node)); ;}
    break;

  case 14:
#line 178 "parser.y"
    { (yyval.node) = mknode("VarDecl", mknode("Type",mknode("string",NULL,NULL),NULL), (yyvsp[(4) - (4)].node)); ;}
    break;

  case 15:
#line 180 "parser.y"
    { (yyval.node) = mknode("VarDecl", mknode("PointerType", mknode((yyvsp[(2) - (5)].stringVal),NULL,NULL), NULL), (yyvsp[(5) - (5)].node)); ;}
    break;

  case 16:
#line 185 "parser.y"
    { (yyval.node) = mknode("StringList", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 17:
#line 187 "parser.y"
    { (yyval.node) = mknode("StringList", (yyvsp[(1) - (1)].node), NULL); ;}
    break;

  case 18:
#line 193 "parser.y"
    {
            node *name = mknode((yyvsp[(1) - (6)].stringVal), NULL, NULL);
            char size_str[20];
            sprintf(size_str, "%d", (yyvsp[(3) - (6)].intVal));

            node *size = mknode("Size", mknode(size_str, NULL, NULL), NULL);
            node *val  = mknode("Value", mknode((yyvsp[(6) - (6)].stringVal), NULL, NULL), NULL);
            (yyval.node) = mknode("String", name, mknode("Detail", size, val));
        ;}
    break;

  case 19:
#line 203 "parser.y"
    {
            node *name = mknode((yyvsp[(1) - (4)].stringVal), NULL, NULL);
            char size_str[20];
            sprintf(size_str, "%d", (yyvsp[(3) - (4)].intVal));
            node *size = mknode("Size", mknode(size_str, NULL, NULL), NULL);
            (yyval.node) = mknode("String", name, size);
        ;}
    break;

  case 20:
#line 214 "parser.y"
    { (yyval.node) = mknode("IdList", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 21:
#line 215 "parser.y"
    { (yyval.node) = mknode("IdList", (yyvsp[(1) - (1)].node), NULL); ;}
    break;

  case 22:
#line 221 "parser.y"
    { (yyval.node) = mknode((yyvsp[(1) - (3)].stringVal), (yyvsp[(3) - (3)].node), NULL); ;}
    break;

  case 23:
#line 223 "parser.y"
    { (yyval.node) = mknode((yyvsp[(1) - (1)].stringVal), NULL, NULL); ;}
    break;

  case 24:
#line 228 "parser.y"
    { (yyval.node) = mknode("Body", (yyvsp[(2) - (4)].node), (yyvsp[(3) - (4)].node)); ;}
    break;

  case 25:
#line 234 "parser.y"
    { (yyval.node) = mknode("BodyMain", (yyvsp[(2) - (3)].node), NULL); ;}
    break;

  case 26:
#line 239 "parser.y"
    {
            (yyval.node) = mknode("statements", (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
        ;}
    break;

  case 27:
#line 243 "parser.y"
    {
            (yyval.node) = NULL;
        ;}
    break;

  case 28:
#line 247 "parser.y"
    {
            (yyval.node) = mknode("function", (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
            last_param_number = 0;
        ;}
    break;

  case 29:
#line 255 "parser.y"
    {
            (yyval.node) = mknode("parameters", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
        ;}
    break;

  case 30:
#line 259 "parser.y"
    {
            (yyval.node) = mknode("parameter", (yyvsp[(1) - (1)].node), NULL);
        ;}
    break;

  case 31:
#line 263 "parser.y"
    {
            (yyval.node) = NULL;
        ;}
    break;

  case 32:
#line 270 "parser.y"
    {
            if (strncmp((yyvsp[(1) - (4)].stringVal), "par", 3) != 0 ) {
                YYABORT;
            }
            int current_num = atoi(&(yyvsp[(1) - (4)].stringVal)[3]);
            if (current_num != last_param_number+1) {
                printf("Error: Parameter numbers must be in strictly increasing order.");
                YYABORT;
            }

            last_param_number = current_num;
            (yyval.node) = mknode("parameter", mknode("param name", mknode((yyvsp[(1) - (4)].stringVal),NULL,NULL), NULL), mknode("param type", mknode((yyvsp[(2) - (4)].stringVal),NULL,NULL), NULL));
        ;}
    break;

  case 33:
#line 286 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 34:
#line 287 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 35:
#line 288 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 36:
#line 289 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 37:
#line 290 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 38:
#line 291 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 39:
#line 292 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 40:
#line 293 "parser.y"
    { (yyval.node) = mknode("function assign", mknode((yyvsp[(1) - (4)].stringVal), NULL, NULL), (yyvsp[(4) - (4)].node)); ;}
    break;

  case 41:
#line 294 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 42:
#line 298 "parser.y"
    { (yyval.node) = mknode("block", (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node)); ;}
    break;

  case 43:
#line 303 "parser.y"
    { (yyval.node) = mknode("call statement", mknode((yyvsp[(1) - (5)].stringVal), NULL, NULL), (yyvsp[(3) - (5)].node)); ;}
    break;

  case 44:
#line 307 "parser.y"
    { (yyval.node) = mknode("params", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 45:
#line 308 "parser.y"
    { (yyval.node) = mknode("params", (yyvsp[(1) - (1)].node), NULL); ;}
    break;

  case 46:
#line 309 "parser.y"
    { (yyval.node) = mknode("params", NULL, NULL); ;}
    break;

  case 47:
#line 315 "parser.y"
    { (yyval.node) = mknode("declaration stat", mknode((yyvsp[(2) - (5)].stringVal), NULL, NULL), mknode((yyvsp[(4) - (5)].stringVal), NULL, NULL)); ;}
    break;

  case 48:
#line 317 "parser.y"
    { (yyval.node) = mknode("declaration stat", mknode((yyvsp[(2) - (7)].stringVal), NULL, NULL), mknode((yyvsp[(4) - (7)].stringVal), (yyvsp[(6) - (7)].node), NULL)); ;}
    break;

  case 49:
#line 321 "parser.y"
    { (yyval.stringVal) = "bool"; ;}
    break;

  case 50:
#line 322 "parser.y"
    { (yyval.stringVal) = "TRUE"; ;}
    break;

  case 51:
#line 323 "parser.y"
    { (yyval.stringVal) = "FALSE"; ;}
    break;

  case 52:
#line 324 "parser.y"
    { (yyval.stringVal) = "char"; ;}
    break;

  case 53:
#line 325 "parser.y"
    { (yyval.stringVal) = "int"; ;}
    break;

  case 54:
#line 326 "parser.y"
    { (yyval.stringVal) = "real"; ;}
    break;

  case 55:
#line 327 "parser.y"
    { (yyval.stringVal) = "int_ptr"; ;}
    break;

  case 56:
#line 328 "parser.y"
    { (yyval.stringVal) = "char_ptr"; ;}
    break;

  case 57:
#line 329 "parser.y"
    { (yyval.stringVal) = "real_ptr"; ;}
    break;

  case 58:
#line 334 "parser.y"
    { (yyval.node) = mknode("Assign", mknode((yyvsp[(1) - (4)].stringVal), NULL, NULL), (yyvsp[(3) - (4)].node)); ;}
    break;

  case 59:
#line 336 "parser.y"
    { (yyval.node) = mknode("ArrayAssign", mknode((yyvsp[(1) - (7)].stringVal), (yyvsp[(3) - (7)].node), NULL), mknode((yyvsp[(6) - (7)].stringVal), NULL, NULL)); ;}
    break;

  case 60:
#line 338 "parser.y"
    { (yyval.node) = mknode("PointerAssign", mknode((yyvsp[(2) - (5)].stringVal), NULL, NULL), (yyvsp[(4) - (5)].node)); ;}
    break;

  case 61:
#line 340 "parser.y"
    { (yyval.node) = mknode("RefAssign", mknode((yyvsp[(1) - (5)].stringVal), NULL, NULL), mknode((yyvsp[(4) - (5)].stringVal), NULL, NULL)); ;}
    break;

  case 62:
#line 342 "parser.y"
    { (yyval.node) = mknode("NullAssign", mknode((yyvsp[(1) - (4)].stringVal), NULL, NULL), mknode("null", NULL, NULL)); ;}
    break;

  case 63:
#line 344 "parser.y"
    {
            char int_str[20];  // Buffer for the integer to string conversion
            sprintf(int_str, "%d", (yyvsp[(6) - (7)].intVal));  // Convert integer to string
            (yyval.node) = mknode("ArrayAssign", mknode((yyvsp[(1) - (7)].stringVal), (yyvsp[(3) - (7)].node), NULL), mknode(int_str, NULL, NULL));
        ;}
    break;

  case 64:
#line 354 "parser.y"
    {
            // if(condition) statement elif* else statement
            node *ifBranch = mknode("IfStmt", (yyvsp[(2) - (7)].node), (yyvsp[(4) - (7)].node));
            node *elifList = (yyvsp[(5) - (7)].node);
            node *elseBranch = mknode("ElseBranch", (yyvsp[(7) - (7)].node), NULL);
            node *branches = mknode("Branches", ifBranch, mknode("ElifList", elifList, elseBranch));
            (yyval.node) = mknode("IfElseStmt", NULL, branches);
        ;}
    break;

  case 65:
#line 363 "parser.y"
    {
            // if(condition) statement elif*
            node *ifBranch = mknode("IfStmt", (yyvsp[(2) - (5)].node), (yyvsp[(4) - (5)].node));
            node *branches = mknode("Branches", ifBranch, (yyvsp[(5) - (5)].node));
            (yyval.node) = mknode("IfStmt", NULL, branches);
        ;}
    break;

  case 66:
#line 370 "parser.y"
    {
            // if(condition) statement
            node *ifBranch = mknode("IfStmt", (yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node));
            node *branches = mknode("Branches", ifBranch, NULL);
            (yyval.node) = mknode("IfStmt", NULL, branches);
        ;}
    break;

  case 67:
#line 380 "parser.y"
    {
            // elif(condition) statement ... (with more elifs after)
            node *this_elif = mknode("ElifStmt", (yyvsp[(2) - (5)].node), (yyvsp[(4) - (5)].node));
            this_elif->right = (yyvsp[(5) - (5)].node);  // Chain the elifs
            (yyval.node) = this_elif;
        ;}
    break;

  case 68:
#line 387 "parser.y"
    {
            // Final elif(condition) statement
            (yyval.node) = mknode("ElifStmt", (yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node));
        ;}
    break;

  case 69:
#line 397 "parser.y"
    { (yyval.node) = mknode("WhileStmt", (yyvsp[(2) - (7)].node), (yyvsp[(6) - (7)].node)); ;}
    break;

  case 70:
#line 402 "parser.y"
    { (yyval.node) = mknode("DoStmt", (yyvsp[(5) - (10)].node), (yyvsp[(9) - (10)].node)); ;}
    break;

  case 71:
#line 407 "parser.y"
    { (yyval.node) = mknode("ForStmt", (yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node)); ;}
    break;

  case 72:
#line 412 "parser.y"
    { (yyval.node) = mknode("ForHeader", mknode("Init", mknode((yyvsp[(2) - (9)].stringVal), NULL, NULL), (yyvsp[(4) - (9)].node)), mknode("Loop", (yyvsp[(6) - (9)].node), (yyvsp[(8) - (9)].node))); ;}
    break;

  case 73:
#line 417 "parser.y"
    { (yyval.node) = mknode("Update", mknode((yyvsp[(1) - (3)].stringVal), NULL, NULL), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 74:
#line 421 "parser.y"
    {
        char int_str[20];  // Buffer for the integer to string conversion
        sprintf(int_str, "%d", (yyvsp[(1) - (1)].intVal));  // Convert integer to string
        (yyval.node) = mknode(int_str, NULL, NULL);
    ;}
    break;

  case 75:
#line 426 "parser.y"
    {
        char real_str[40];
        sprintf(real_str, "%f", (yyvsp[(1) - (1)].realVal));
        (yyval.node) = mknode(real_str, NULL, NULL);
    ;}
    break;

  case 76:
#line 431 "parser.y"
    {
        char char_str[2];  // Buffer for the char to string conversion
        sprintf(char_str, "%s", (yyvsp[(1) - (1)].stringVal));  // Convert char to string
        (yyval.node) = mknode(char_str, NULL, NULL);
    ;}
    break;

  case 77:
#line 436 "parser.y"
    {
        (yyval.node) = mknode((yyvsp[(1) - (1)].stringVal), NULL, NULL);  // STRING_LITERAL is already a string, so no conversion needed
    ;}
    break;

  case 78:
#line 439 "parser.y"
    {
        (yyval.node) = mknode((yyvsp[(1) - (1)].stringVal), NULL, NULL);
    ;}
    break;

  case 79:
#line 442 "parser.y"
    { (yyval.node) = mknode("+", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 80:
#line 443 "parser.y"
    { (yyval.node) = mknode("-", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 81:
#line 444 "parser.y"
    { (yyval.node) = mknode("*", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 82:
#line 445 "parser.y"
    { (yyval.node) = mknode("/", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 83:
#line 446 "parser.y"
    {
        if ((yyvsp[(2) - (2)].node) && is_number((yyvsp[(2) - (2)].node)->token)) {
            char *negated = malloc(strlen((yyvsp[(2) - (2)].node)->token) + 2);
            sprintf(negated, "-%s", (yyvsp[(2) - (2)].node)->token);
            (yyval.node) = mknode(negated, NULL, NULL);
        } else {
            (yyval.node) = mknode("neg", (yyvsp[(2) - (2)].node), NULL);
        }
    ;}
    break;

  case 84:
#line 455 "parser.y"
    {
        if ((yyvsp[(2) - (2)].node) && strcmp((yyvsp[(2) - (2)].node)->token, "ref") == 0) {
            yyerror("Error: cannot take address of an address (e.g., &(&x))");
            (yyval.node) = NULL;
        } else {
            (yyval.node) = mknode("ref", (yyvsp[(2) - (2)].node), NULL);
        }
    ;}
    break;

  case 85:
#line 464 "parser.y"
    { (yyval.node) = mknode("call_expr", mknode((yyvsp[(1) - (4)].stringVal), NULL, NULL), (yyvsp[(3) - (4)].node)); ;}
    break;

  case 86:
#line 465 "parser.y"
    { (yyval.node) = mknode("pointer_expr", mknode((yyvsp[(1) - (4)].stringVal), NULL, NULL), (yyvsp[(3) - (4)].node)); ;}
    break;

  case 87:
#line 466 "parser.y"
    { (yyval.node) = (yyvsp[(3) - (4)].node); ;}
    break;

  case 88:
#line 467 "parser.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); ;}
    break;

  case 89:
#line 478 "parser.y"
    { (yyval.node) = mknode((yyvsp[(2) - (3)].stringVal), (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 90:
#line 480 "parser.y"
    { (yyval.node) = mknode("Not", (yyvsp[(2) - (2)].node), NULL); ;}
    break;

  case 91:
#line 482 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 92:
#line 484 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 93:
#line 489 "parser.y"
    { (yyval.node) = mknode("And", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 94:
#line 490 "parser.y"
    { (yyval.node) = mknode("Or", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 95:
#line 495 "parser.y"
    { (yyval.node) = mknode("false", NULL, NULL); ;}
    break;

  case 96:
#line 496 "parser.y"
    { (yyval.node) = mknode("true", NULL, NULL); ;}
    break;

  case 97:
#line 497 "parser.y"
    { (yyval.node) = mknode("false", NULL,NULL); ;}
    break;

  case 98:
#line 498 "parser.y"
    { (yyval.node) = mknode("true", NULL,NULL); ;}
    break;

  case 99:
#line 502 "parser.y"
    { (yyval.stringVal) = "=="; ;}
    break;

  case 100:
#line 503 "parser.y"
    { (yyval.stringVal) = "!="; ;}
    break;

  case 101:
#line 504 "parser.y"
    { (yyval.stringVal) =  ">"; ;}
    break;

  case 102:
#line 505 "parser.y"
    { (yyval.stringVal) = ">="; ;}
    break;

  case 103:
#line 506 "parser.y"
    { (yyval.stringVal) = "<"; ;}
    break;

  case 104:
#line 507 "parser.y"
    { (yyval.stringVal) = "<="; ;}
    break;

  case 105:
#line 513 "parser.y"
    { has_return = 1; (yyval.node) = mknode("Return", (yyvsp[(2) - (3)].node), NULL); ;}
    break;

  case 106:
#line 515 "parser.y"
    {
            last_param_number = 0;
            has_return = 1; (yyval.node) = mknode("Return", (yyvsp[(2) - (3)].node), NULL); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2348 "parser.tab.c"
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
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
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


#line 521 "parser.y"


#include "lex.yy.c"

int main() {

    return yyparse();
}
void print_tree(node *n) {
    if (!n) {
        printf("NONE");
        return;
    }

    printf("(");
    printf("%s", n->token);

    if (n->left || n->right) {
        printf(" ");
        if (n->left) {
            print_tree(n->left);
        } else {
            printf("NONE");
        }

        if (n->right) {
            printf(" ");
            print_tree(n->right);
        }
    }

    printf(")");
}

void print_ast_graphical(node* tree, const char* prefix, int is_left) {
    if (!tree) return;

    // הדפסת הטוקן עם הסימנים הגרפיים
    printf("%s", prefix);
    printf(is_left ? "├── " : "└── ");
    printf("%s\n", tree->token);

    // בניית prefix חדש לילדים
    char new_prefix[1024];
    snprintf(new_prefix, sizeof(new_prefix), "%s%s", prefix, is_left ? "│   " : "    ");

    if (tree->left && tree->right) {
        print_ast_graphical(tree->left, new_prefix, 1);   // שמאל
        print_ast_graphical(tree->right, new_prefix, 0);  // ימין
    } else if (tree->left) {
        print_ast_graphical(tree->left, new_prefix, 0);
    } else if (tree->right) {
        print_ast_graphical(tree->right, new_prefix, 0);
    }
}
void printtree(node *tree, int depth)
{
    if (!tree) return;

    // הדפסת הזחה לפי עומק
    for (int i = 0; i < depth; ++i) {
        printf("  ");
    }

    // הדפסת הטוקן של הצומת
    printf("%s\n", tree->token);

    // קריאה רקורסיבית לילדים
    if (tree->left)
        printtree(tree->left, depth + 1);
    if (tree->right)
        printtree(tree->right, depth);
}





int yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
    printf("Line %d: %s\n", yylineno, yytext);
    return 1;
}

node *mknode(char *token,node *left,node *right)
{
    node *newnode = (node*)malloc(sizeof(node));
    char *newstr = (char*)malloc(sizeof(token) + 1);
    strcpy(newstr,token);
    newnode->left = left;
    newnode->right = right;
    newnode->token = newstr;
    return newnode;
}

int is_number(const char* str) {
    if (!str) return 0;
    return isdigit(str[0]) || str[0] == '.' || str[0] == '-';
}


