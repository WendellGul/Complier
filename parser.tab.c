
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
#line 1 "parser.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdarg.h>
    #include "complier.h"
    #define TABNUM 3
    void yyerror(char *);
    extern int yylex();
    extern int yylineno;
    FILE *yyin;
    FILE *yyout;
    char *yytext;
    
    TreeNode* nTerminal(char *name, TreeNode *child);
    TreeNode* terminal(NodeType type, int value, char *name);
    void addBro(TreeNode *p, TreeNode *bro);
    void generate(TreeNode *p, int tab);
    void printNode(TreeNode *p, int tab);
    void freeNode(TreeNode *p);



/* Line 189 of yacc.c  */
#line 97 "parser.tab.c"

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
     CONST = 258,
     VAR = 259,
     PROCEDURE = 260,
     RESERVEDBEGIN = 261,
     END = 262,
     ODD = 263,
     IF = 264,
     THEN = 265,
     CALL = 266,
     WHILE = 267,
     DO = 268,
     READ = 269,
     WRITE = 270,
     ASSIGN = 271,
     INTEGER = 272,
     ID = 273,
     ERROR = 274,
     GEQ = 275,
     LEQ = 276
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 24 "parser.y"

    int value; // integer value
    char name[30]; // name of variable
    TreeNode *nPtr; // node pointer



/* Line 214 of yacc.c  */
#line 162 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 174 "parser.tab.c"

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   84

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNRULES -- Number of states.  */
#define YYNSTATES  113

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   276

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    21,     2,     2,     2,     2,
      33,    34,    28,    26,    32,    27,    30,    29,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    31,
      23,    20,    22,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    24,    25
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    13,    14,    16,    17,    19,
      20,    22,    27,    28,    32,    36,    41,    42,    46,    50,
      55,    59,    60,    62,    64,    66,    68,    70,    72,    74,
      78,    83,    84,    88,    92,    95,    99,   100,   104,   105,
     107,   109,   112,   113,   117,   119,   121,   125,   127,   129,
     131,   133,   135,   137,   139,   141,   143,   145,   150,   153,
     158,   164,   165,   169,   175,   176
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      36,     0,    -1,    37,    -1,    38,    30,    -1,    39,    40,
      41,    49,    -1,    -1,    42,    -1,    -1,    45,    -1,    -1,
      47,    -1,     3,    44,    43,    31,    -1,    -1,    32,    44,
      43,    -1,    18,    20,    17,    -1,     4,    18,    46,    31,
      -1,    -1,    32,    18,    46,    -1,    48,    38,    31,    -1,
      48,    38,    31,    47,    -1,     5,    18,    31,    -1,    -1,
      50,    -1,    63,    -1,    65,    -1,    64,    -1,    66,    -1,
      68,    -1,    51,    -1,    18,    16,    54,    -1,     6,    49,
      52,     7,    -1,    -1,    31,    49,    52,    -1,    54,    62,
      54,    -1,     8,    54,    -1,    56,    57,    55,    -1,    -1,
      60,    57,    55,    -1,    -1,    26,    -1,    27,    -1,    59,
      58,    -1,    -1,    61,    59,    58,    -1,    18,    -1,    17,
      -1,    33,    54,    34,    -1,    26,    -1,    27,    -1,    28,
      -1,    29,    -1,    20,    -1,    21,    -1,    23,    -1,    25,
      -1,    22,    -1,    24,    -1,     9,    53,    10,    49,    -1,
      11,    18,    -1,    12,    53,    13,    49,    -1,    14,    33,
      18,    67,    34,    -1,    -1,    32,    18,    67,    -1,    15,
      33,    54,    69,    34,    -1,    -1,    32,    54,    69,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    45,    45,    51,    57,    64,    65,    69,    70,    74,
      75,    80,    88,    89,    97,   107,   117,   118,   128,   133,
     142,   152,   153,   156,   159,   162,   165,   168,   171,   176,
     186,   194,   195,   203,   208,   215,   221,   222,   228,   229,
     232,   237,   242,   243,   250,   253,   256,   264,   267,   272,
     275,   280,   283,   286,   289,   292,   295,   300,   311,   318,
     329,   341,   342,   352,   363,   364
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CONST", "VAR", "PROCEDURE",
  "RESERVEDBEGIN", "END", "ODD", "IF", "THEN", "CALL", "WHILE", "DO",
  "READ", "WRITE", "ASSIGN", "INTEGER", "ID", "ERROR", "'='", "'#'", "'>'",
  "'<'", "GEQ", "LEQ", "'+'", "'-'", "'*'", "'/'", "'.'", "';'", "','",
  "'('", "')'", "$accept", "program_start", "program", "subprogram",
  "subprogram_part1", "subprogram_part2", "subprogram_part3",
  "const_declare", "const_declare_part1", "const_define", "var_declare",
  "var_declare_part1", "procedure_declare", "procedure_header",
  "statement", "assign", "complex", "complex_part1", "condition",
  "expression", "expression_part1", "sign", "item", "item_part1", "factor",
  "addsub", "muldiv", "cmp", "condition_statment", "call", "loop", "read",
  "read_part1", "write", "write_part1", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
      61,    35,    62,    60,   275,   276,    43,    45,    42,    47,
      46,    59,    44,    40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    35,    36,    37,    38,    39,    39,    40,    40,    41,
      41,    42,    43,    43,    44,    45,    46,    46,    47,    47,
      48,    49,    49,    49,    49,    49,    49,    49,    49,    50,
      51,    52,    52,    53,    53,    54,    55,    55,    56,    56,
      56,    57,    58,    58,    59,    59,    59,    60,    60,    61,
      61,    62,    62,    62,    62,    62,    62,    63,    64,    65,
      66,    67,    67,    68,    69,    69
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     4,     0,     1,     0,     1,     0,
       1,     4,     0,     3,     3,     4,     0,     3,     3,     4,
       3,     0,     1,     1,     1,     1,     1,     1,     1,     3,
       4,     0,     3,     3,     2,     3,     0,     3,     0,     1,
       1,     2,     0,     3,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     2,     4,
       5,     0,     3,     5,     0,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,     2,     0,     7,     6,     0,    12,     1,
       3,     0,     9,     8,     0,     0,     0,    16,     0,    21,
      10,     5,    14,    12,    11,     0,     0,     0,    21,    38,
       0,    38,     0,     0,     0,     4,    22,    28,    23,    25,
      24,    26,    27,     0,    13,    16,    15,    20,    31,    38,
      39,    40,     0,     0,     0,    58,     0,     0,    38,    38,
      18,    17,    21,     0,    34,    21,    51,    52,    55,    53,
      56,    54,    38,    45,    44,    38,    36,    42,    21,    61,
      64,    29,    19,    31,    30,    57,    33,     0,    47,    48,
      35,     0,    49,    50,    41,     0,    59,     0,     0,    38,
       0,    32,    46,    36,    42,    61,    60,    64,    63,    37,
      43,    62,    65
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,     5,    12,    19,     6,    16,     8,
      13,    26,    20,    21,    35,    36,    37,    63,    52,    53,
      90,    54,    76,    94,    77,    91,    95,    72,    38,    39,
      40,    41,    98,    42,   100
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -50
static const yytype_int8 yypact[] =
{
      21,    11,    32,   -50,     3,    33,   -50,    19,     4,   -50,
     -50,    22,    36,   -50,    25,    11,    12,    13,    26,    16,
     -50,    21,   -50,     4,   -50,    28,    17,    18,    16,    -6,
      29,    -6,    20,    23,    38,   -50,   -50,   -50,   -50,   -50,
     -50,   -50,   -50,    24,   -50,    13,   -50,   -50,    27,   -21,
     -50,   -50,    42,    -9,   -14,   -50,    44,    41,   -21,   -21,
      36,   -50,    16,    53,   -50,    16,   -50,   -50,   -50,   -50,
     -50,   -50,   -21,   -50,   -50,   -21,   -19,   -11,    16,    30,
      31,   -50,   -50,    27,   -50,   -50,   -50,    34,   -50,   -50,
     -50,   -14,   -50,   -50,   -50,   -14,   -50,    43,    35,   -21,
      37,   -50,   -50,   -19,   -11,    30,   -50,    31,   -50,   -50,
     -50,   -50,   -50
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -50,   -50,   -50,    45,   -50,   -50,   -50,   -50,    47,    49,
     -50,    39,     5,   -50,   -27,   -50,   -50,   -16,    46,   -49,
     -31,   -50,   -18,   -30,   -20,   -50,   -50,   -50,   -50,   -50,
     -50,   -50,   -29,   -50,   -28
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      64,    48,    49,    73,    74,    50,    51,    88,    89,    80,
      81,    66,    67,    68,    69,    70,    71,    92,    93,    75,
      50,    51,    28,    86,     1,    29,    87,    30,    31,     7,
      32,    33,     9,    10,    34,    83,    15,    11,    85,    14,
      17,    18,    22,    24,    27,    25,    45,    55,    46,    47,
     107,    96,    65,    57,    59,    60,    58,    78,    62,    79,
      84,   105,    97,    99,    23,    82,    43,   101,   102,   106,
      44,   108,   109,   103,   110,   104,   111,    56,     0,   112,
       0,     0,     0,     0,    61
};

static const yytype_int8 yycheck[] =
{
      49,    28,     8,    17,    18,    26,    27,    26,    27,    58,
      59,    20,    21,    22,    23,    24,    25,    28,    29,    33,
      26,    27,     6,    72,     3,     9,    75,    11,    12,    18,
      14,    15,     0,    30,    18,    62,    32,     4,    65,    20,
      18,     5,    17,    31,    18,    32,    18,    18,    31,    31,
      99,    78,    10,    33,    16,    31,    33,    13,    31,    18,
       7,    18,    32,    32,    15,    60,    21,    83,    34,    34,
      23,    34,   103,    91,   104,    95,   105,    31,    -1,   107,
      -1,    -1,    -1,    -1,    45
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    36,    37,    38,    39,    42,    18,    44,     0,
      30,     4,    40,    45,    20,    32,    43,    18,     5,    41,
      47,    48,    17,    44,    31,    32,    46,    18,     6,     9,
      11,    12,    14,    15,    18,    49,    50,    51,    63,    64,
      65,    66,    68,    38,    43,    18,    31,    31,    49,     8,
      26,    27,    53,    54,    56,    18,    53,    33,    33,    16,
      31,    46,    31,    52,    54,    10,    20,    21,    22,    23,
      24,    25,    62,    17,    18,    33,    57,    59,    13,    18,
      54,    54,    47,    49,     7,    49,    54,    54,    26,    27,
      55,    60,    28,    29,    58,    61,    49,    32,    67,    32,
      69,    52,    34,    57,    59,    18,    34,    54,    34,    55,
      58,    67,    69
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
#line 45 "parser.y"
    {
        generate((yyvsp[(1) - (1)].nPtr), 0);
        freeNode((yyvsp[(1) - (1)].nPtr));
    ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 51 "parser.y"
    { 
        (yyval.nPtr) = nTerminal("program", (yyvsp[(1) - (2)].nPtr));
        addBro((yyvsp[(1) - (2)].nPtr), terminal(typeOpr, '.', ""));
    ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 57 "parser.y"
    {
        (yyval.nPtr) = nTerminal("subprogram", (yyvsp[(1) - (4)].nPtr));
        addBro((yyvsp[(1) - (4)].nPtr), (yyvsp[(2) - (4)].nPtr));
        addBro((yyvsp[(2) - (4)].nPtr), (yyvsp[(3) - (4)].nPtr));
        addBro((yyvsp[(3) - (4)].nPtr), (yyvsp[(4) - (4)].nPtr));
    ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 64 "parser.y"
    { (yyval.nPtr) = nTerminal("", NULL); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 65 "parser.y"
    {
        (yyval.nPtr) = nTerminal("subprogram_part1", (yyvsp[(1) - (1)].nPtr));
    ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 69 "parser.y"
    { (yyval.nPtr) = nTerminal("", NULL); ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 70 "parser.y"
    { 
        (yyval.nPtr) = nTerminal("subprogram_part2", (yyvsp[(1) - (1)].nPtr));
    ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 74 "parser.y"
    { (yyval.nPtr) = nTerminal("", NULL); ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 75 "parser.y"
    { 
        (yyval.nPtr) = nTerminal("subprogram_part3", (yyvsp[(1) - (1)].nPtr));
    ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 80 "parser.y"
    {
        TreeNode *p = terminal(typeReserve, CONST, "");
        (yyval.nPtr) = nTerminal("const_declare", p);
        addBro(p, (yyvsp[(2) - (4)].nPtr));
        addBro((yyvsp[(2) - (4)].nPtr), (yyvsp[(3) - (4)].nPtr));
        addBro((yyvsp[(3) - (4)].nPtr), terminal(typeOpr, ';', ""));
    ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 88 "parser.y"
    { (yyval.nPtr) = nTerminal("", NULL); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 89 "parser.y"
    { 
        TreeNode *p = terminal(typeOpr, ',', "");
        (yyval.nPtr) = nTerminal("const_declare_part1", p);
        addBro(p, (yyvsp[(2) - (3)].nPtr));
        addBro((yyvsp[(2) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
    ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 97 "parser.y"
    { 
        TreeNode *p1, *p2;
        p1 = terminal(typeId, 0, (yyvsp[(1) - (3)].name));
        p2 = terminal(typeOpr, '=', "");
        (yyval.nPtr) = nTerminal("const_declare", p1);
        addBro(p1, p2);
        addBro(p2, terminal(typeCon, (yyvsp[(3) - (3)].value), ""));
    ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 107 "parser.y"
    { 
        TreeNode *pVar, *pId;
        pVar = terminal(typeReserve, VAR, "");
        pId = terminal(typeId, 0, (yyvsp[(2) - (4)].name));
        (yyval.nPtr) = nTerminal("var_declare", pVar);
        addBro(pVar, pId);
        addBro(pId, (yyvsp[(3) - (4)].nPtr));
        addBro((yyvsp[(3) - (4)].nPtr), terminal(typeOpr, ';', ""));
    ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 117 "parser.y"
    { (yyval.nPtr) = nTerminal("", NULL); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 118 "parser.y"
    { 
        TreeNode *p1, *pId;
        p1 = terminal(typeOpr, ',', "");
        pId = terminal(typeId, 0, (yyvsp[(2) - (3)].name));
        (yyval.nPtr) = nTerminal("var_declare_part1", p1);
        addBro(p1, pId);
        addBro(pId, (yyvsp[(3) - (3)].nPtr));
    ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 128 "parser.y"
    {
        (yyval.nPtr) = nTerminal("procedure_declare", (yyvsp[(1) - (3)].nPtr));
        addBro((yyvsp[(1) - (3)].nPtr), (yyvsp[(2) - (3)].nPtr));
        addBro((yyvsp[(2) - (3)].nPtr), terminal(typeOpr, ';', ""));
    ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 133 "parser.y"
    {
        TreeNode *p = terminal(typeOpr, ';', "");
        (yyval.nPtr) = nTerminal("procedure_declare", (yyvsp[(1) - (4)].nPtr));
        addBro((yyvsp[(1) - (4)].nPtr), (yyvsp[(2) - (4)].nPtr));
        addBro((yyvsp[(2) - (4)].nPtr), p);
        addBro(p, (yyvsp[(4) - (4)].nPtr));
    ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 142 "parser.y"
    { 
        TreeNode *p1, *p2, *p3;
        p1 = terminal(typeReserve, PROCEDURE, "");
        p2 = terminal(typeId, 0, (yyvsp[(2) - (3)].name));
        p3 = terminal(typeOpr, ';', "");
        (yyval.nPtr) = nTerminal("procedure_header", p1);
        addBro(p1, p2);
        addBro(p2, p3);
    ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 152 "parser.y"
    { (yyval.nPtr) = nTerminal("", NULL); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 153 "parser.y"
    {
        (yyval.nPtr) = nTerminal("statement", (yyvsp[(1) - (1)].nPtr));
    ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 156 "parser.y"
    {
        (yyval.nPtr) = nTerminal("statement", (yyvsp[(1) - (1)].nPtr));
    ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 159 "parser.y"
    {
        (yyval.nPtr) = nTerminal("statement", (yyvsp[(1) - (1)].nPtr));
    ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 162 "parser.y"
    {
        (yyval.nPtr) = nTerminal("statement", (yyvsp[(1) - (1)].nPtr));
    ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 165 "parser.y"
    {
        (yyval.nPtr) = nTerminal("statement", (yyvsp[(1) - (1)].nPtr));
    ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 168 "parser.y"
    {
        (yyval.nPtr) = nTerminal("statement", (yyvsp[(1) - (1)].nPtr));
    ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 171 "parser.y"
    {
        (yyval.nPtr) = nTerminal("statement", (yyvsp[(1) - (1)].nPtr));
    ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 176 "parser.y"
    {
        TreeNode *p1, *p2;
        p1 = terminal(typeId, 0, (yyvsp[(1) - (3)].name));
        p2 = terminal(typeReserve, ASSIGN, "");
        (yyval.nPtr) = nTerminal("assign", p1);
        addBro(p1, p2);
        addBro(p2, (yyvsp[(3) - (3)].nPtr));
    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 186 "parser.y"
    {
        TreeNode *p = terminal(typeReserve, RESERVEDBEGIN, "");
        (yyval.nPtr) = nTerminal("complex", p);
        addBro(p, (yyvsp[(2) - (4)].nPtr));
        addBro((yyvsp[(2) - (4)].nPtr), (yyvsp[(3) - (4)].nPtr));
        addBro((yyvsp[(3) - (4)].nPtr), terminal(typeReserve, END, ""));
    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 194 "parser.y"
    { (yyval.nPtr) = nTerminal("", NULL); ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 195 "parser.y"
    {
        TreeNode *p = terminal(typeOpr, ';', "");
        (yyval.nPtr) = nTerminal("complex_part1", p);
        addBro(p, (yyvsp[(2) - (3)].nPtr));
        addBro((yyvsp[(2) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 203 "parser.y"
    {
        (yyval.nPtr) = nTerminal("condition", (yyvsp[(1) - (3)].nPtr));
        addBro((yyvsp[(1) - (3)].nPtr), (yyvsp[(2) - (3)].nPtr));
        addBro((yyvsp[(2) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
    ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 208 "parser.y"
    {
        TreeNode *p = terminal(typeReserve, ODD, "");
        (yyval.nPtr) = nTerminal("condition", p);
        addBro(p, (yyvsp[(2) - (2)].nPtr));
    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 215 "parser.y"
    {
        (yyval.nPtr) = nTerminal("expression", (yyvsp[(1) - (3)].nPtr));
        addBro((yyvsp[(1) - (3)].nPtr), (yyvsp[(2) - (3)].nPtr));
        addBro((yyvsp[(2) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 221 "parser.y"
    { (yyval.nPtr) = nTerminal("", NULL); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 222 "parser.y"
    {
        (yyval.nPtr) = nTerminal("expression_part1", (yyvsp[(1) - (3)].nPtr));
        addBro((yyvsp[(1) - (3)].nPtr), (yyvsp[(2) - (3)].nPtr));
        addBro((yyvsp[(2) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 228 "parser.y"
    { (yyval.nPtr) = nTerminal("", NULL); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 229 "parser.y"
    {
        (yyval.nPtr) = nTerminal("sign", terminal(typeOpr, '+', ""));
    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 232 "parser.y"
    {
        (yyval.nPtr) = nTerminal("sign", terminal(typeOpr, '-', ""));
    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 237 "parser.y"
    {
        (yyval.nPtr) = nTerminal("item", (yyvsp[(1) - (2)].nPtr));
        addBro((yyvsp[(1) - (2)].nPtr), (yyvsp[(2) - (2)].nPtr));
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 242 "parser.y"
    { (yyval.nPtr) = nTerminal("", NULL); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 243 "parser.y"
    {
        (yyval.nPtr) = nTerminal("item_part1", (yyvsp[(1) - (3)].nPtr));
        addBro((yyvsp[(1) - (3)].nPtr), (yyvsp[(2) - (3)].nPtr));
        addBro((yyvsp[(2) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
    ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 250 "parser.y"
    {
        (yyval.nPtr) = nTerminal("factor", terminal(typeId, 0, (yyvsp[(1) - (1)].name)));
    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 253 "parser.y"
    {
        (yyval.nPtr) = nTerminal("factor", terminal(typeCon, (yyvsp[(1) - (1)].value), ""));
    ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 256 "parser.y"
    {
        TreeNode *p = terminal(typeOpr, '(', "");
        (yyval.nPtr) = nTerminal("factor", p);
        addBro(p, (yyvsp[(2) - (3)].nPtr));
        addBro((yyvsp[(2) - (3)].nPtr), terminal(typeOpr, ')', ""));
    ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 264 "parser.y"
    {
        (yyval.nPtr) = terminal(typeOpr, '+', "");
    ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 267 "parser.y"
    {
        (yyval.nPtr) = terminal(typeOpr, '-', "");
    ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 272 "parser.y"
    {
        (yyval.nPtr) = terminal(typeOpr, '*', "");
    ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 275 "parser.y"
    {
        (yyval.nPtr) = terminal(typeOpr, '/', "");
    ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 280 "parser.y"
    {
        (yyval.nPtr) = terminal(typeOpr, '=', "");
    ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 283 "parser.y"
    {
        (yyval.nPtr) = terminal(typeOpr, '#', "");
    ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 286 "parser.y"
    {
        (yyval.nPtr) = terminal(typeOpr, '<', "");
    ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 289 "parser.y"
    {
        (yyval.nPtr) = terminal(typeOpr, LEQ, "");
    ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 292 "parser.y"
    {
        (yyval.nPtr) = terminal(typeOpr, '>', "");
    ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 295 "parser.y"
    {
        (yyval.nPtr) = terminal(typeOpr, GEQ, "");
    ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 300 "parser.y"
    {
        TreeNode *p1, *p3;
        p1 = terminal(typeReserve, IF, "");
        p3 = terminal(typeReserve, THEN, "");
        (yyval.nPtr) = nTerminal("condition_statment", p1);
        addBro(p1, (yyvsp[(2) - (4)].nPtr));
        addBro((yyvsp[(2) - (4)].nPtr), p3);
        addBro(p3, (yyvsp[(4) - (4)].nPtr));
    ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 311 "parser.y"
    {
        TreeNode *p = terminal(typeReserve, CALL, "");
        (yyval.nPtr) = nTerminal("call", p);
        addBro(p, terminal(typeId, 0, (yyvsp[(2) - (2)].name)));
    ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 318 "parser.y"
    {
        TreeNode *p1, *p3;
        p1 = terminal(typeReserve, WHILE, "");
        p3 = terminal(typeReserve, DO, "");
        (yyval.nPtr) = nTerminal("loop", p1);
        addBro(p1, (yyvsp[(2) - (4)].nPtr));
        addBro((yyvsp[(2) - (4)].nPtr), p3);
        addBro(p3, (yyvsp[(4) - (4)].nPtr));
    ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 329 "parser.y"
    {
        TreeNode *p1, *p2, *p3;
        p1 = terminal(typeReserve, READ, "");
        p2 = terminal(typeOpr, '(', "");
        p3 = terminal(typeId, 0, (yyvsp[(3) - (5)].name));
        (yyval.nPtr) = nTerminal("read", p1);
        addBro(p1, p2);
        addBro(p2, p3);
        addBro(p3, (yyvsp[(4) - (5)].nPtr));
        addBro((yyvsp[(4) - (5)].nPtr), terminal(typeOpr, ')', ""));
    ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 341 "parser.y"
    { (yyval.nPtr) = nTerminal("", NULL); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 342 "parser.y"
    {
        TreeNode *p1, *p2;
        p1 = terminal(typeOpr, ',', "");
        p2 = terminal(typeId, 0, (yyvsp[(2) - (3)].name));
        (yyval.nPtr) = nTerminal("read_part1", p1);
        addBro(p1, p2);
        addBro(p2, (yyvsp[(3) - (3)].nPtr));
    ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 352 "parser.y"
    {
        TreeNode *p1, *p2;
        p1 = terminal(typeReserve, WRITE, "");
        p2 = terminal(typeOpr, '(', "");
        (yyval.nPtr) = nTerminal("write", p1);
        addBro(p1, p2);
        addBro(p2, (yyvsp[(3) - (5)].nPtr));
        addBro((yyvsp[(3) - (5)].nPtr), (yyvsp[(4) - (5)].nPtr));
        addBro((yyvsp[(4) - (5)].nPtr), terminal(typeOpr, ')', ""));
    ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 363 "parser.y"
    { (yyval.nPtr) = nTerminal("", NULL); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 364 "parser.y"
    {
        TreeNode *p = terminal(typeOpr, ',', "");
        (yyval.nPtr) = nTerminal("write_part1", p);
        addBro(p, (yyvsp[(2) - (3)].nPtr));
        addBro((yyvsp[(2) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
    ;}
    break;



/* Line 1455 of yacc.c  */
#line 2117 "parser.tab.c"
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
#line 372 "parser.y"

void yyerror(char *s)
{
    fprintf(stderr, "line:%d %s near '%s'", yylineno, s, yytext);
}

int main(int argc, char **argv)
{
    if(argc <= 2)
    {
        printf("Invalid input!\n");
        return 0;
    }
    if((yyin = fopen(argv[1], "r")) == NULL)
    {
        perror(argv[1]);
        return 0;
    }
    yyout = fopen(argv[2], "w");
    yyparse();
    fclose(yyin);
    fclose(yyout);
    return 0;
}

TreeNode* nTerminal(char *name, TreeNode *child)
{
    TreeNode *p;
    if((p = (TreeNode *)malloc(sizeof(TreeNode))) == NULL)
        return NULL;
    p->isTerminal = 0;
    strcpy(p->ntnode.name, name);
    p->child = child;
    p->bro = NULL;
    return p;
}

TreeNode* terminal(NodeType type, int value, char *name)
{
    TreeNode *p;
    if((p = (TreeNode *)malloc(sizeof(TreeNode))) == NULL)
        return NULL;
    p->isTerminal = 1;
    p->tnode.type = type;
    p->tnode.value = value;
    strcpy(p->tnode.name, name);
    p->child = NULL;
    p->bro = NULL;
    return p;
}

void addBro(TreeNode *p, TreeNode *bro)
{
    p->bro = bro;
}

void freeNode(TreeNode *p)
{
    if(p == NULL)
        return ;
    TreeNode *pChild, *pBro;
    pChild = p->child;
    freeNode(pChild);
    if(pChild != NULL)
        for(pBro = pChild->bro; pBro != NULL; pBro = pBro->bro)
            freeNode(pBro);
    free(p);
}

void generate(TreeNode *p, int tab)
{
    if(p == NULL)
        return ;
    TreeNode *pChild, *pBro;
    printNode(p, tab);
    pChild = p->child;
    generate(pChild, tab + 1);
    if(pChild != NULL)
        for(pBro = pChild->bro; pBro != NULL; pBro = pBro->bro)
            generate(pBro, tab + 1);
}

void printNode(TreeNode *p, int tab)
{
    int i = 0;
    if(p->isTerminal == 1)
    {
        while(tab != 0 && i++ < TABNUM * (tab - 1))
            fprintf(yyout, " ");
        if(tab != 0)
            fprintf(yyout, "|__");
        TNode tnode = p->tnode;
        switch(tnode.type)
        {
            case typeCon:
                fprintf(yyout, "INT: %d\n", tnode.value);
            break;
            case typeId:
                fprintf(yyout, "ID: %s\n", tnode.name);
            break;
            case typeOpr:
                switch(tnode.value)
                {
                    case LEQ: fprintf(yyout, "OPER: LEQ\n"); break;
                    case GEQ: fprintf(yyout, "OPER: GEQ\n"); break;
                    default : fprintf(yyout, "OPER: '%c'\n", tnode.value);
                }       
            break;
            case typeReserve:
                switch(tnode.value)
                {
                    case CONST: fprintf(yyout, "RESERVED: CONST\n"); break;
                    case VAR: fprintf(yyout, "RESERVED: VAR\n"); break;
                    case PROCEDURE: fprintf(yyout, "RESERVED: PROCEDURE\n"); break;
                    case RESERVEDBEGIN: fprintf(yyout, "RESERVED: BEGIN\n"); break;
                    case END: fprintf(yyout, "RESERVED: END\n"); break;
                    case ODD: fprintf(yyout, "RESERVED: ODD\n"); break;
                    case IF: fprintf(yyout, "RESERVED: IF\n"); break;
                    case THEN: fprintf(yyout, "RESERVED: THEN\n"); break;
                    case CALL: fprintf(yyout, "RESERVED: CALL\n"); break;
                    case WHILE: fprintf(yyout, "RESERVED: WHILE\n"); break;
                    case DO: fprintf(yyout, "RESERVED: DO\n"); break;
                    case READ: fprintf(yyout, "RESERVED: READ\n"); break;
                    case WRITE: fprintf(yyout, "RESERVED: WRITE\n"); break;
                    case ASSIGN: fprintf(yyout, "RESERVED: ASSIGN\n"); break;
                }
            break;
        }
    }
    else
    {
        NTNode ntnode = p->ntnode;
        if(strcmp(ntnode.name, "") != 0)
        {
            while(tab != 0 && i++ < TABNUM * (tab - 1))
                fprintf(yyout, " ");
            if(tab != 0)
                fprintf(yyout, "|__");
            fprintf(yyout, "%s\n", ntnode.name);
        }
    }
}


