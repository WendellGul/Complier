/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

    #include "compiler.h"
    void yyerror(char *);
    extern int yylex();
    void setFileName(char *tar, char *src, char *postfix);
    FILE *treeFile = NULL;
    FILE *targetFile = NULL;
    TreeNode *syntaxTree = NULL;
    char message[100];
    ErrorType et = ERR_OTHER;

#line 78 "parser.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    KW_INT = 258,
    KW_FLOAT = 259,
    KW_CHAR = 260,
    KW_STRUCT = 261,
    KW_RETURN = 262,
    KW_IF = 263,
    KW_ELSE = 264,
    KW_WHILE = 265,
    KW_CONTINUE = 266,
    KW_BREAK = 267,
    TK_CINT = 268,
    TK_CCHAR = 269,
    TK_CFLOAT = 270,
    TK_CSTR = 271,
    TK_ID = 272,
    ERROR = 273,
    LOWER_THAN_ELSE = 274,
    TK_OR = 275,
    TK_AND = 276,
    TK_LEQ = 277,
    TK_GEQ = 278,
    TK_EQ = 279,
    TK_NEQ = 280
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 13 "parser.y" /* yacc.c:355  */

    int iValue; // integer value
    char cValue; // char value
    float fValue; // float value
    char *sValue; // string value
    char name[30]; // name of variable
    TreeNode *nPtr; // node pointer

#line 153 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 184 "parser.tab.c" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   518

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  179

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   280

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,     2,     2,     2,    33,     2,     2,
      35,    36,    31,    29,    41,    30,    37,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    40,
      28,    20,    27,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    21,    22,    23,    24,    25,
      26
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    50,    50,    55,    60,    61,    68,    74,    79,    85,
      95,   106,   110,   119,   123,   129,   134,   141,   152,   160,
     161,   168,   173,   183,   198,   208,   218,   233,   248,   255,
     259,   273,   280,   288,   300,   301,   308,   313,   322,   326,
     333,   345,   357,   373,   387,   402,   421,   440,   457,   469,
     483,   495,   501,   508,   509,   516,   522,   534,   538,   545,
     557,   571,   575,   582,   596,   603,   610,   617,   623,   630,
     637,   644,   651,   660,   666,   672,   683,   693,   703,   712,
     718,   724,   730,   735,   740,   747,   750,   753,   756,   759,
     762,   767,   774,   778
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "KW_INT", "KW_FLOAT", "KW_CHAR",
  "KW_STRUCT", "KW_RETURN", "KW_IF", "KW_ELSE", "KW_WHILE", "KW_CONTINUE",
  "KW_BREAK", "TK_CINT", "TK_CCHAR", "TK_CFLOAT", "TK_CSTR", "TK_ID",
  "ERROR", "LOWER_THAN_ELSE", "'='", "TK_OR", "TK_AND", "TK_LEQ", "TK_GEQ",
  "TK_EQ", "TK_NEQ", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'!'", "'('", "')'", "'.'", "'['", "']'", "';'", "','", "'{'", "'}'",
  "$accept", "program_start", "program", "extern_define_list",
  "extern_define", "extern_declare_list", "specifier", "type",
  "struct_specifier", "option_tag", "var_declare", "function_declare",
  "param_list", "param_declare", "compound_statement", "statement_list",
  "statement", "define_list", "define", "declare_list", "declare",
  "expression", "relation_op", "args", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
      61,   275,   276,   277,   278,   279,   280,    62,    60,    43,
      45,    42,    47,    37,    33,    40,    41,    46,    91,    93,
      59,    44,   123,   125
};
# endif

#define YYPACT_NINF -80

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-80)))

#define YYTABLE_NINF -83

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     111,     0,   -80,   -80,    36,    81,   -80,   -80,   111,     5,
     -80,   -80,   -80,    61,    89,   -80,   -80,   -16,    45,   -80,
     108,    44,     2,    68,   152,    20,   -80,    97,    24,   -80,
      20,    75,   124,   152,   -80,     9,    35,   126,   152,   145,
     -80,   -80,   212,    20,    20,    20,   463,   -80,    83,   -80,
     165,   162,   143,   463,   164,   169,   -80,    62,   190,   -80,
     -80,    -9,   171,   173,   -80,   -80,   -80,   176,   192,   -23,
     -23,   406,    20,    20,    20,   -80,   -80,   -80,   -80,   -80,
     -80,    20,    20,    20,    20,   198,   244,    20,   -80,   188,
     178,   -80,   188,   -80,   -80,    55,   253,     7,    16,   177,
     180,   -80,   175,    62,   344,   -80,    67,   -80,    77,   -80,
      93,   -80,   322,   185,   -80,   463,   480,   148,    69,    69,
     -23,   -23,   -80,    63,   386,   463,   184,   -80,   -80,   -80,
     -24,   365,   193,   276,   194,   279,   -80,   -80,   -80,   -80,
     -80,   -18,   -80,   -18,   -80,   285,   285,   -80,   -80,   -80,
     -80,   -80,   153,   210,   425,   153,   219,   444,   -80,   -80,
     247,   115,   189,   -80,   115,   153,   153,   249,    -2,   251,
     -80,   -80,   -80,   153,   153,   153,   -80,   -80,   -80
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    15,    16,    19,     0,     2,     3,     0,     0,
      13,    14,    10,    18,     0,     1,     5,     0,     0,     7,
       0,    61,     0,    11,    53,     0,     9,     0,     0,     6,
       0,     0,     0,    53,     8,     0,     0,     0,    53,     0,
      80,    81,     0,     0,     0,     0,    63,    27,     0,    25,
       0,     0,    29,    62,     0,     0,    33,     0,     0,    21,
      12,     0,     0,    57,    17,    54,    82,     0,     0,    73,
      74,     0,     0,     0,     0,    87,    88,    89,    90,    86,
      85,     0,     0,     0,     0,     0,     0,     0,    26,     0,
      31,    24,     0,    23,    22,     0,     0,     0,     0,     0,
       0,    38,     0,     0,     0,    56,     0,    55,     0,    84,
       0,    76,    92,     0,    72,    64,    66,    65,    68,    69,
      70,    71,    78,     0,     0,    67,     0,    30,    28,    37,
       0,     0,     0,     0,     0,     0,    52,    51,    32,    35,
      36,     0,    59,    60,    58,     0,     0,    75,    83,    77,
      40,    39,     0,     0,     0,     0,     0,     0,    93,    91,
      43,     0,     0,    50,     0,     0,     0,    42,     0,    41,
      49,    48,    47,     0,     0,     0,    46,    45,    44
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -80,   -80,   -80,   254,   -80,   228,     1,   -80,   -80,   -80,
     214,   -80,    70,   -80,   243,   168,   166,    80,   -80,   -19,
       4,   -25,   -80,   -79
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,     8,    20,    36,    10,    11,    14,
      21,    22,    51,    52,   101,   102,   103,    37,    38,    62,
      63,   104,    87,   113
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      46,     9,    25,    32,    25,    53,    17,   174,   132,     9,
      58,    25,    66,    23,    85,    86,   150,   134,    69,    70,
      71,    39,    18,   106,    26,    48,    59,     2,     3,    50,
       4,   105,   106,    40,    66,    41,    61,    42,   129,    23,
      12,    56,   133,   112,    33,    19,    27,   115,   116,   117,
      43,   135,    59,    13,    44,    45,   118,   119,   120,   121,
      49,   124,   125,    95,    30,   -21,   158,   159,   141,    96,
      97,   131,    98,    99,   100,    40,    54,    41,   143,    42,
      28,    15,    31,   -21,    59,   -21,   -21,   142,    55,   144,
      50,    66,    43,    50,    59,   129,    44,    45,    56,    66,
      83,    84,   148,   -20,    33,   -34,    85,    86,   154,    35,
     157,    -4,     1,    57,     2,     3,    95,     4,    65,    88,
     112,   112,    96,    97,    89,    98,    99,   100,    40,    66,
      41,    24,    42,    47,   145,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,    29,    44,
      45,   -82,   -82,   -82,    95,     2,     3,    33,     4,   127,
      96,    97,   128,    98,    99,   100,    40,    56,    41,    64,
      42,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    66,    59,    43,    92,    85,    86,    44,    45,   126,
     168,     2,     3,   110,     4,    33,    96,    97,    91,    98,
      99,   100,    40,    93,    41,    40,    42,    41,    94,    42,
      25,   107,   109,    67,   108,   122,    31,   136,   138,    43,
     137,   147,    43,    44,    45,    89,    44,    45,   111,   152,
     155,    33,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   123,   161,    68,   -79,   -79,
     -79,   -79,   -79,   -79,   130,   164,   166,    40,   173,    41,
     175,    42,    16,    60,    90,    34,    40,     0,    41,     0,
      42,   139,     0,     0,    43,     0,     0,   153,    44,    45,
     156,     0,     0,    43,     0,     0,   110,    44,    45,    40,
       0,    41,    40,    42,    41,     0,    42,     0,    40,     0,
      41,     0,    42,     0,     0,     0,    43,     0,     0,    43,
      44,    45,     0,    44,    45,    43,     0,     0,   160,    44,
      45,   163,     0,     0,     0,     0,     0,   167,   169,     0,
     170,   171,   172,     0,     0,     0,     0,     0,     0,   176,
     177,   178,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     0,     0,     0,     0,    85,
      86,     0,     0,   146,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,     0,     0,     0,
       0,    85,    86,     0,   140,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,     0,     0,
       0,     0,    85,    86,     0,   151,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
       0,     0,     0,    85,    86,   149,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
       0,     0,   114,    85,    86,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,     0,     0,
       0,   162,    85,    86,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,     0,     0,     0,
     165,    85,    86,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,     0,     0,     0,
      85,    86,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,     0,     0,     0,     0,    85,    86
};

static const yytype_int16 yycheck[] =
{
      25,     0,    20,     1,    20,    30,     1,     9,     1,     8,
       1,    20,    36,     9,    37,    38,    40,     1,    43,    44,
      45,     1,    17,    41,    40,     1,    17,     3,     4,    28,
       6,    40,    41,    13,    36,    15,     1,    17,    40,    35,
      40,    43,    35,    68,    42,    40,     1,    72,    73,    74,
      30,    35,    17,    17,    34,    35,    81,    82,    83,    84,
      36,    86,    87,     1,    20,    20,   145,   146,     1,     7,
       8,    96,    10,    11,    12,    13,     1,    15,     1,    17,
      35,     0,    38,    38,    17,    40,    41,   106,    13,   108,
      89,    36,    30,    92,    17,    40,    34,    35,    43,    36,
      31,    32,    39,    42,    42,    43,    37,    38,   133,    41,
     135,     0,     1,    33,     3,     4,     1,     6,    38,    36,
     145,   146,     7,     8,    41,    10,    11,    12,    13,    36,
      15,    42,    17,    36,    41,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    40,    34,
      35,    36,    37,    38,     1,     3,     4,    42,     6,    89,
       7,     8,    92,    10,    11,    12,    13,    43,    15,    43,
      17,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    36,    17,    30,    41,    37,    38,    34,    35,     1,
       1,     3,     4,     1,     6,    42,     7,     8,    36,    10,
      11,    12,    13,    39,    15,    13,    17,    15,    39,    17,
      20,    40,    36,     1,    41,    17,    38,    40,    43,    30,
      40,    36,    30,    34,    35,    41,    34,    35,    36,    36,
      36,    42,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,     1,    36,    35,    36,    37,
      38,    39,    40,    41,     1,    36,     9,    13,     9,    15,
       9,    17,     8,    35,    50,    22,    13,    -1,    15,    -1,
      17,   103,    -1,    -1,    30,    -1,    -1,     1,    34,    35,
       1,    -1,    -1,    30,    -1,    -1,     1,    34,    35,    13,
      -1,    15,    13,    17,    15,    -1,    17,    -1,    13,    -1,
      15,    -1,    17,    -1,    -1,    -1,    30,    -1,    -1,    30,
      34,    35,    -1,    34,    35,    30,    -1,    -1,   152,    34,
      35,   155,    -1,    -1,    -1,    -1,    -1,   161,   162,    -1,
     164,   165,   166,    -1,    -1,    -1,    -1,    -1,    -1,   173,
     174,   175,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    37,
      38,    -1,    -1,    41,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    37,    38,    -1,    40,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    37,    38,    -1,    40,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    37,    38,    39,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    36,    37,    38,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    36,    37,    38,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      36,    37,    38,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      37,    38,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    37,    38
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     6,    45,    46,    47,    48,    50,
      51,    52,    40,    17,    53,     0,    47,     1,    17,    40,
      49,    54,    55,    64,    42,    20,    40,     1,    35,    40,
      20,    38,     1,    42,    58,    41,    50,    61,    62,     1,
      13,    15,    17,    30,    34,    35,    65,    36,     1,    36,
      50,    56,    57,    65,     1,    13,    43,    61,     1,    17,
      49,     1,    63,    64,    43,    61,    36,     1,    35,    65,
      65,    65,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    37,    38,    66,    36,    41,
      54,    36,    41,    39,    39,     1,     7,     8,    10,    11,
      12,    58,    59,    60,    65,    40,    41,    40,    41,    36,
       1,    36,    65,    67,    36,    65,    65,    65,    65,    65,
      65,    65,    17,     1,    65,    65,     1,    56,    56,    40,
       1,    65,     1,    35,     1,    35,    40,    40,    43,    59,
      40,     1,    63,     1,    63,    41,    41,    36,    39,    39,
      40,    40,    36,     1,    65,    36,     1,    65,    67,    67,
      60,    36,    36,    60,    36,    36,     9,    60,     1,    60,
      60,    60,    60,     9,     9,     9,    60,    60,    60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    46,    47,    47,    48,    48,    48,    48,
      48,    49,    49,    50,    50,    51,    51,    52,    52,    53,
      53,    54,    54,    54,    55,    55,    55,    55,    56,    56,
      56,    57,    58,    58,    59,    59,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    61,    61,    62,    62,    63,    63,    63,
      63,    64,    64,    64,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    66,    66,    66,    66,    66,
      66,    67,    67,    67
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     0,     2,     3,     2,     3,     3,
       2,     1,     3,     1,     1,     1,     1,     5,     2,     0,
       1,     1,     4,     4,     4,     3,     4,     3,     3,     1,
       3,     2,     4,     2,     0,     2,     2,     2,     1,     3,
       3,     5,     5,     4,     7,     7,     7,     6,     5,     5,
       4,     2,     2,     0,     2,     3,     3,     1,     3,     3,
       3,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     4,     3,     4,     3,     1,
       1,     1,     2,     4,     3,     1,     1,     1,     1,     1,
       1,     3,     1,     3
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 50 "parser.y" /* yacc.c:1646  */
    {
        syntaxTree = (yyvsp[0].nPtr);
    }
#line 1547 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 55 "parser.y" /* yacc.c:1646  */
    {
        (yyval.nPtr) = nTerminal(Program, (yyvsp[0].nPtr));
        (yyvsp[0].nPtr)->parent = (yyval.nPtr);
    }
#line 1556 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 60 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = nTerminal(None, NULL);}
#line 1562 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 61 "parser.y" /* yacc.c:1646  */
    {
        (yyval.nPtr) = nTerminal(ExtDefList, (yyvsp[-1].nPtr));
        (yyvsp[-1].nPtr)->parent = (yyval.nPtr);
        addBro((yyvsp[-1].nPtr), (yyvsp[0].nPtr));
    }
#line 1572 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 68 "parser.y" /* yacc.c:1646  */
    {
        (yyval.nPtr) = nTerminal(ExtDef, (yyvsp[-2].nPtr));
        (yyvsp[-2].nPtr)->parent = (yyval.nPtr);
        addBro((yyvsp[-2].nPtr), (yyvsp[-1].nPtr));
        addBro((yyvsp[-1].nPtr), terminal(_SEMI, ';', ""));    
    }
#line 1583 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 74 "parser.y" /* yacc.c:1646  */
    {
        (yyval.nPtr) = nTerminal(ExtDef, (yyvsp[-1].nPtr));
        (yyvsp[-1].nPtr)->parent = (yyval.nPtr);
        addBro((yyvsp[-1].nPtr), terminal(_SEMI, ';', ""));
    }
#line 1593 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 79 "parser.y" /* yacc.c:1646  */
    {
        (yyval.nPtr) = nTerminal(ExtDef, (yyvsp[-2].nPtr));
        (yyvsp[-2].nPtr)->parent = (yyval.nPtr);
        addBro((yyvsp[-2].nPtr), (yyvsp[-1].nPtr));
        addBro((yyvsp[-1].nPtr), (yyvsp[0].nPtr));
    }
#line 1604 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 85 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p2 = terminal(None, 0, "");
        (yyval.nPtr) = nTerminal(ExtDef, (yyvsp[-2].nPtr));
        (yyvsp[-2].nPtr)->parent = (yyval.nPtr);
        addBro((yyvsp[-2].nPtr), p2);
        addBro(p2, terminal(_SEMI, ';', ""));
        setErrType(ERR_TYPE1);
        m_error("something wrong with ExtDecList before \";\"", (yylsp[-1]).last_line);
        setErrType(ERR_OTHER);
    }
#line 1619 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 95 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p1 = terminal(None, 0, "");
        (yyval.nPtr) = nTerminal(ExtDef, p1);
        p1->parent = (yyval.nPtr);
        addBro(p1, terminal(_SEMI, ';', ""));
        setErrType(ERR_TYPE1);
        m_error("something wrong with Specifier before \";\"", (yylsp[-1]).last_line);
        setErrType(ERR_OTHER);
    }
#line 1633 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 106 "parser.y" /* yacc.c:1646  */
    {
        (yyval.nPtr) = nTerminal(ExtDecList, (yyvsp[0].nPtr));
        (yyvsp[0].nPtr)->parent = (yyval.nPtr);
    }
#line 1642 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 110 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p2 = terminal(_COMMA, ',', "");
        (yyval.nPtr) = nTerminal(ExtDecList, (yyvsp[-2].nPtr));
        (yyvsp[-2].nPtr)->parent = (yyval.nPtr);
        addBro((yyvsp[-2].nPtr), p2);
        addBro(p2, (yyvsp[0].nPtr));
    }
#line 1654 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 119 "parser.y" /* yacc.c:1646  */
    {
        (yyval.nPtr) = nTerminal(Specifier, (yyvsp[0].nPtr));
        (yyvsp[0].nPtr)->parent = (yyval.nPtr);
    }
#line 1663 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 123 "parser.y" /* yacc.c:1646  */
    {
        (yyval.nPtr) = nTerminal(Specifier, (yyvsp[0].nPtr));
        (yyvsp[0].nPtr)->parent = (yyval.nPtr);
    }
#line 1672 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 129 "parser.y" /* yacc.c:1646  */
    { 
        TreeNode *p1 = terminal(_INT, KW_INT, "");
        (yyval.nPtr) = nTerminal(_TYPE, p1);
        p1->parent = (yyval.nPtr);
    }
#line 1682 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 134 "parser.y" /* yacc.c:1646  */
    { 
        TreeNode *p1 = terminal(_FLOAT, KW_FLOAT, "");
        (yyval.nPtr) = nTerminal(_TYPE, p1);
        p1->parent = (yyval.nPtr); 
    }
#line 1692 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 141 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p1, *p3;
        p1 = terminal(_STRUCT, KW_STRUCT, "");
        p3 = terminal(_BEGIN, '{', "");
        (yyval.nPtr) = nTerminal(StructSpecifier, p1);
        p1->parent = (yyval.nPtr);
        addBro(p1, (yyvsp[-3].nPtr));
        addBro((yyvsp[-3].nPtr), p3);
        addBro(p3, (yyvsp[-1].nPtr));
        addBro((yyvsp[-1].nPtr), terminal(_END, '}', ""));
    }
#line 1708 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 152 "parser.y" /* yacc.c:1646  */
    {
        // 语法树相关
        TreeNode *p1 = terminal(_STRUCT, KW_STRUCT, "");
        (yyval.nPtr) = nTerminal(StructSpecifier, p1);
        p1->parent = (yyval.nPtr);
        addBro(p1, terminal(_ID, 0, (yyvsp[0].name)));
    }
#line 1720 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 160 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = nTerminal(None, NULL); }
#line 1726 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 161 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p1 = terminal(_ID, 0, (yyvsp[0].name));
        (yyval.nPtr) = nTerminal(OptTag, p1);
        p1->parent = (yyval.nPtr);
    }
#line 1736 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 168 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p1 = terminal(_ID, 0, (yyvsp[0].name));
        (yyval.nPtr) = nTerminal(VarDec, p1);
        p1->parent = (yyval.nPtr);
    }
#line 1746 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 173 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p2, *p3;
        p2 = terminal(_LB, '[', "");
        p3 = terminal(_INT, (yyvsp[-1].iValue), "");
        (yyval.nPtr) = nTerminal(VarDec, (yyvsp[-3].nPtr));
        (yyvsp[-3].nPtr)->parent = (yyval.nPtr);
        addBro((yyvsp[-3].nPtr), p2);
        addBro(p2, p3);
        addBro(p3, terminal(_RB, ']', ""));
    }
#line 1761 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 183 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p2, *p3;
        p2 = terminal(_LB, '[', "");
        p3 = terminal(None, 0, "");
        (yyval.nPtr) = nTerminal(VarDec, (yyvsp[-3].nPtr));
        (yyvsp[-3].nPtr)->parent = (yyval.nPtr);
        addBro((yyvsp[-3].nPtr), p2);
        addBro(p2, p3);
        addBro(p3, terminal(_RB, ']', ""));
        setErrType(ERR_TYPE2);
        m_error("missing a integer between \"[]\"", (yylsp[-1]).last_line);
        setErrType(ERR_OTHER);
    }
#line 1779 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 198 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p1, *p2;
        p1 = terminal(_ID, 0, (yyvsp[-3].name));
        p2 = terminal(_LP, '(', "");
        (yyval.nPtr) = nTerminal(FuncDec, p1);
        p1->parent = (yyval.nPtr);
        addBro(p1, p2);
        addBro(p2, (yyvsp[-1].nPtr));
        addBro((yyvsp[-1].nPtr), terminal(_RP, ')', ""));
    }
#line 1794 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 208 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p1, *p2, *p3;
        p1 = terminal(_ID, 0, (yyvsp[-2].name));
        p2 = terminal(_LP, '(', "");
        p3 = terminal(_RP, ')', "");
        (yyval.nPtr) = nTerminal(FuncDec, p1);
        p1->parent = (yyval.nPtr);
        addBro(p1, p2);
        addBro(p2, p3);
    }
#line 1809 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 218 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p1, *p2, *p3, *p4;
        p1 = terminal(_ID, 0, (yyvsp[-3].name));
        p2 = terminal(_LP, '(', "");
        p3 = terminal(None, 0, "");
        p4 = terminal(_RP, ')', "");
        (yyval.nPtr) = nTerminal(FuncDec, p1);
        p1->parent = (yyval.nPtr);
        addBro(p1, p2);
        addBro(p2, p3);
        addBro(p3, p4);
        setErrType(ERR_TYPE3);
        m_error("something wrong with VarList between \"()\"", (yylsp[-1]).last_line);
        setErrType(ERR_OTHER);
    }
#line 1829 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 233 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p1, *p2, *p3;
        p1 = terminal(_ID, 0, (yyvsp[-2].name));
        p2 = terminal(None, 0, "");
        p3 = terminal(_RP, ')', "");
        (yyval.nPtr) = nTerminal(FuncDec, p1);
        p1->parent = (yyval.nPtr);
        addBro(p1, p2);
        addBro(p2, p3);
        setErrType(ERR_TYPE3);
        m_error("missing \"(\"", (yylsp[-1]).last_line);
        setErrType(ERR_OTHER);
    }
#line 1847 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 248 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p2 = terminal(_COMMA, ',', "");
        (yyval.nPtr) = nTerminal(ParamList, (yyvsp[-2].nPtr));
        (yyvsp[-2].nPtr)->parent = (yyval.nPtr);
        addBro((yyvsp[-2].nPtr), p2);
        addBro(p2, (yyvsp[0].nPtr));
    }
#line 1859 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 255 "parser.y" /* yacc.c:1646  */
    {
        (yyval.nPtr) = nTerminal(ParamList, (yyvsp[0].nPtr));
        (yyvsp[0].nPtr)->parent = (yyval.nPtr);
    }
#line 1868 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 259 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p1, *p2;
        p1 = terminal(None, 0, "");
        p2 = terminal(_COMMA, ',', "");
        (yyval.nPtr) = nTerminal(ParamList, p1);
        p1->parent = (yyval.nPtr);
        addBro(p1, p2);
        addBro(p2, (yyvsp[0].nPtr));
        setErrType(ERR_TYPE4);
        m_error("something wrong with ParamDec", (yylsp[-2]).last_line);
        setErrType(ERR_OTHER);
    }
#line 1885 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 273 "parser.y" /* yacc.c:1646  */
    {
        (yyval.nPtr) = nTerminal(ParamDec, (yyvsp[-1].nPtr));
        (yyvsp[-1].nPtr)->parent = (yyval.nPtr);
        addBro((yyvsp[-1].nPtr), (yyvsp[0].nPtr));
    }
#line 1895 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 280 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p1 = terminal(_BEGIN, '{', "");
        (yyval.nPtr) = nTerminal(CompSt, p1);
        p1->parent = (yyval.nPtr);
        addBro(p1, (yyvsp[-2].nPtr));
        addBro((yyvsp[-2].nPtr), (yyvsp[-1].nPtr));
        addBro((yyvsp[-1].nPtr), terminal(_END, '}', ""));
    }
#line 1908 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 288 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p1, *p2;
        p1 = terminal(None, 0, "");
        p2 = terminal(_BEGIN, '}', "");
        (yyval.nPtr) = nTerminal(CompSt, p1);
        p1->parent = (yyval.nPtr);
        addBro(p1, p2);
        setErrType(ERR_TYPE5);
        m_error("missing \"{\"", (yylsp[-1]).first_line);
        setErrType(ERR_OTHER);
    }
#line 1924 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 300 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = nTerminal(None, NULL); }
#line 1930 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 301 "parser.y" /* yacc.c:1646  */
    {
        (yyval.nPtr) =  nTerminal(StmtList, (yyvsp[-1].nPtr));
        (yyvsp[-1].nPtr)->parent = (yyval.nPtr);
        addBro((yyvsp[-1].nPtr), (yyvsp[0].nPtr));
    }
#line 1940 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 308 "parser.y" /* yacc.c:1646  */
    {
        (yyval.nPtr) = nTerminal(Statement, (yyvsp[-1].nPtr));
        (yyvsp[-1].nPtr)->parent = (yyval.nPtr);
        addBro((yyvsp[-1].nPtr), terminal(_SEMI, ';', ""));
    }
#line 1950 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 313 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p1 = terminal(None, 0, "");
        (yyval.nPtr) = nTerminal(Statement, p1);
        p1->parent = (yyval.nPtr);
        addBro(p1, terminal(_SEMI, ';', ""));
        setErrType(ERR_TYPE6);
        m_error("something wrong with expression before \";\"", (yylsp[-1]).last_line);
        setErrType(ERR_OTHER);
    }
#line 1964 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 322 "parser.y" /* yacc.c:1646  */
    {
        (yyval.nPtr) = nTerminal(Statement, (yyvsp[0].nPtr));
        (yyvsp[0].nPtr)->parent = (yyval.nPtr);
    }
#line 1973 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 326 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p1 = terminal(_RETURN, KW_RETURN, "");
        (yyval.nPtr) = nTerminal(Statement, p1);
        p1->parent = (yyval.nPtr);
        addBro(p1, (yyvsp[-1].nPtr));
        addBro((yyvsp[-1].nPtr), terminal(_SEMI, ';', ""));
    }
#line 1985 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 333 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p1, *p2;
        p1 = terminal(_RETURN, KW_RETURN, "");
        p2 = terminal(None, 0, "");
        (yyval.nPtr) = nTerminal(Statement, p1);
        p1->parent = (yyval.nPtr);
        addBro(p1, p2);
        addBro(p2, terminal(_SEMI, ';', ""));
        setErrType(ERR_TYPE6);
        m_error("something wrong with expression before \";\"", (yylsp[-1]).last_line);
        setErrType(ERR_OTHER);
    }
#line 2002 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 345 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p1, *p2, *p4;
        p1 = terminal(_IF, KW_IF, "");
        p2 = terminal(_LP, '(', "");
        p4 = terminal(_RP, ')', "");
        (yyval.nPtr) = nTerminal(Statement, p1);
        p1->parent = (yyval.nPtr);
        addBro(p1, p2);
        addBro(p2, (yyvsp[-2].nPtr));
        addBro((yyvsp[-2].nPtr), p4);
        addBro(p4, (yyvsp[0].nPtr));
    }
#line 2019 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 357 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p1, *p2, *p3, *p4;
        p1 = terminal(_IF, KW_IF, "");
        p2 = terminal(_LP, '(', "");
        p3 = terminal(None, 0, "");
        p4 = terminal(_RP, ')', "");
        (yyval.nPtr) = nTerminal(Statement, p1);
        p1->parent = (yyval.nPtr);
        addBro(p1, p2);
        addBro(p2, p3);
        addBro(p3, p4);
        addBro(p4, (yyvsp[0].nPtr));
        setErrType(ERR_TYPE6);
        m_error("something wrong with expression between \"()\"", (yylsp[-2]).last_line);
        setErrType(ERR_OTHER);
    }
#line 2040 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 373 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p1, *p2, *p3;
        p1 = terminal(_IF, KW_IF, "");
        p2 = terminal(None, 0, "");
        p3 = terminal(_RP, ')', "");
        (yyval.nPtr) = nTerminal(Statement, p1);
        p1->parent = (yyval.nPtr);
        addBro(p1, p2);
        addBro(p2, p3);
        addBro(p3, (yyvsp[0].nPtr));
        setErrType(ERR_TYPE6);
        m_error("missing \"(\"", (yylsp[-2]).last_line);
        setErrType(ERR_OTHER);
    }
#line 2059 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 387 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p1, *p2, *p4, *p6;
        p1 = terminal(_IF, KW_IF, "");
        p2 = terminal(_LP, '(', "");
        p4 = terminal(_RP, ')', "");
        p6 = terminal(_ELSE, KW_ELSE, "");
        (yyval.nPtr) = nTerminal(Statement, p1);
        p1->parent = (yyval.nPtr);
        addBro(p1, p2);
        addBro(p2, (yyvsp[-4].nPtr));
        addBro((yyvsp[-4].nPtr), p4);
        addBro(p4, (yyvsp[-2].nPtr));
        addBro((yyvsp[-2].nPtr), p6);
        addBro(p6, (yyvsp[0].nPtr));
    }
#line 2079 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 402 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p1, *p2, *p4, *p5, *p6;
        p1 = terminal(_IF, KW_IF, "");
        p2 = terminal(_LP, '(', "");
        p4 = terminal(_RP, ')', "");
        p5 = terminal(None, 0, "");
        p6 = terminal(_ELSE, KW_ELSE, "");
        (yyval.nPtr) = nTerminal(Statement, p1);
        p1->parent = (yyval.nPtr);
        addBro(p1, p2);
        addBro(p2, (yyvsp[-4].nPtr));
        addBro((yyvsp[-4].nPtr), p4);
        addBro(p4, p5);
        addBro(p5, p6);
        addBro(p6, (yyvsp[0].nPtr));
        setErrType(ERR_TYPE6);
        m_error("missing \";\"", (yylsp[-2]).last_line);
        setErrType(ERR_OTHER);
    }
#line 2103 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 421 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p1, *p2, *p3, *p4, *p6;
        p1 = terminal(_IF, KW_IF, "");
        p2 = terminal(_LP, '(', "");
        p3 = terminal(None, 0, "");
        p4 = terminal(_RP, ')', "");
        p6 = terminal(_ELSE, KW_ELSE, "");
        (yyval.nPtr) = nTerminal(Statement, p1);
        p1->parent = (yyval.nPtr);
        addBro(p1, p2);
        addBro(p2, p3);
        addBro(p3, p4);
        addBro(p4, (yyvsp[-2].nPtr));
        addBro((yyvsp[-2].nPtr), p6);
        addBro(p6, (yyvsp[0].nPtr));
        setErrType(ERR_TYPE6);
        m_error("something wrong with expression between \"()\"", (yylsp[-4]).last_line);
        setErrType(ERR_OTHER);
    }
#line 2127 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 440 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p1, *p2, *p3, *p5;
        p1 = terminal(_IF, KW_IF, "");
        p2 = terminal(None, 0, "");
        p3 = terminal(_RP, ')', "");
        p5 = terminal(_ELSE, KW_ELSE, "");
        (yyval.nPtr) = nTerminal(Statement, p1);
        p1->parent = (yyval.nPtr);
        addBro(p1, p2);
        addBro(p2, p3);
        addBro(p3, (yyvsp[-2].nPtr));
        addBro((yyvsp[-2].nPtr), p5);
        addBro(p5, (yyvsp[0].nPtr));
        setErrType(ERR_TYPE6);
        m_error("missing \"(\"", (yylsp[-4]).last_line);
        setErrType(ERR_OTHER);
    }
#line 2149 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 457 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p1, *p2, *p4;
        p1 = terminal(_WHILE, KW_WHILE, "");
        p2 = terminal(_LP, '(', "");
        p4 = terminal(_RP, ')', "");
        (yyval.nPtr) = nTerminal(Statement, p1);
        p1->parent = (yyval.nPtr);
        addBro(p1, p2);
        addBro(p2, (yyvsp[-2].nPtr));
        addBro((yyvsp[-2].nPtr), p4);
        addBro(p4, (yyvsp[0].nPtr));
    }
#line 2166 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 469 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p1, *p2, *p3, *p4;
        p1 = terminal(_WHILE, KW_WHILE, "");
        p2 = terminal(_LP, '(', "");
        p3 = terminal(None, 0, "");
        p4 = terminal(_RP, ')', "");
        (yyval.nPtr) = nTerminal(Statement, p1);
        p1->parent = (yyval.nPtr);
        addBro(p1, p2);
        addBro(p2, p3);
        addBro(p3, p4);
        addBro(p4, (yyvsp[0].nPtr));
        m_error("something wrong with expression between \"()\"", (yylsp[-2]).last_line);
    }
#line 2185 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 483 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p1, *p2, *p3;
        p1 = terminal(_WHILE, KW_WHILE, "");
        p2 = terminal(None, 0, "");
        p3 = terminal(_RP, ')', "");
        (yyval.nPtr) = nTerminal(Statement, p1);
        p1->parent = (yyval.nPtr);
        addBro(p1, p2);
        addBro(p2, p3);
        addBro(p3, (yyvsp[0].nPtr));
        m_error("missing \"(\"", (yylsp[-2]).last_line);
    }
#line 2202 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 495 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p1 = terminal(_BREAK, KW_BREAK, "");
        (yyval.nPtr) = nTerminal(Statement, p1);
        p1->parent = (yyval.nPtr);
        addBro(p1, terminal(_SEMI, ';', ""));
    }
#line 2213 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 501 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p1 = terminal(_CONTINUE, KW_CONTINUE, "");
        (yyval.nPtr) = nTerminal(Statement, p1);
        p1->parent = (yyval.nPtr);
        addBro(p1, terminal(_SEMI, ';', ""));
    }
#line 2224 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 508 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = nTerminal(None, NULL); }
#line 2230 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 509 "parser.y" /* yacc.c:1646  */
    {
        (yyval.nPtr) = nTerminal(DefList, (yyvsp[-1].nPtr));
        (yyvsp[-1].nPtr)->parent = (yyval.nPtr);
        addBro((yyvsp[-1].nPtr), (yyvsp[0].nPtr));
    }
#line 2240 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 516 "parser.y" /* yacc.c:1646  */
    {
        (yyval.nPtr) = nTerminal(Define, (yyvsp[-2].nPtr));
        (yyvsp[-2].nPtr)->parent = (yyval.nPtr);
        addBro((yyvsp[-2].nPtr), (yyvsp[-1].nPtr));
        addBro((yyvsp[-1].nPtr), terminal(_SEMI, ';', ""));
    }
#line 2251 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 522 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p2 = terminal(None, 0, "");
        (yyval.nPtr) = nTerminal(Define, (yyvsp[-2].nPtr));
        (yyvsp[-2].nPtr)->parent = (yyval.nPtr);
        addBro((yyvsp[-2].nPtr), p2);
        addBro(p2, terminal(_SEMI, ';', ""));
        setErrType(ERR_TYPE7);
        m_error("missing declare_list", (yylsp[-1]).last_line);
        setErrType(ERR_OTHER);
    }
#line 2266 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 534 "parser.y" /* yacc.c:1646  */
    {
        (yyval.nPtr) = nTerminal(DecList, (yyvsp[0].nPtr));
        (yyvsp[0].nPtr)->parent = (yyval.nPtr);
    }
#line 2275 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 538 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p2 = terminal(_COMMA, ',', "");
        (yyval.nPtr) = nTerminal(DecList, (yyvsp[-2].nPtr));
        (yyvsp[-2].nPtr)->parent = (yyval.nPtr);
        addBro((yyvsp[-2].nPtr), p2);
        addBro(p2, (yyvsp[0].nPtr));
    }
#line 2287 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 545 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p1, *p2;
        p1 = terminal(None, 0, "");
        p2 = terminal(_COMMA, ',', "");
        (yyval.nPtr) = nTerminal(DecList, p1);
        p1->parent = (yyval.nPtr);
        addBro(p1, p2);
        addBro(p2, (yyvsp[0].nPtr));
        setErrType(ERR_TYPE8);
        m_error("something wrong with declaration", (yylsp[-2]).last_line);
        setErrType(ERR_OTHER);
    }
#line 2304 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 557 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p2, *p3;
        p2 = terminal(_COMMA, ',', "");
        p3 = terminal(None, 0, "");
        (yyval.nPtr) = nTerminal(DecList, (yyvsp[-2].nPtr));
        (yyvsp[-2].nPtr)->parent = (yyval.nPtr);
        addBro((yyvsp[-2].nPtr), p2);
        addBro(p2, p3);
        setErrType(ERR_TYPE8);
        m_error("unnecessary \",\"", (yylsp[-1]).last_line);
        setErrType(ERR_OTHER);
    }
#line 2321 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 571 "parser.y" /* yacc.c:1646  */
    {
        (yyval.nPtr) = nTerminal(Declare, (yyvsp[0].nPtr));
        (yyvsp[0].nPtr)->parent = (yyval.nPtr);
    }
#line 2330 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 575 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p2 = terminal(_ASSIGNOP, '=', "");
        (yyval.nPtr) = nTerminal(Declare, (yyvsp[-2].nPtr));
        (yyvsp[-2].nPtr)->parent = (yyval.nPtr);
        addBro((yyvsp[-2].nPtr), p2);
        addBro(p2, (yyvsp[0].nPtr));
    }
#line 2342 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 582 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p1, *p2;
        p1 = terminal(None, 0, "");
        p2 = terminal(_ASSIGNOP, '=', "");
        (yyval.nPtr) = nTerminal(Declare, p1);
        p1->parent = (yyval.nPtr);
        addBro(p1, p2);
        addBro(p2, (yyvsp[0].nPtr));
        setErrType(ERR_TYPE9);
        m_error("missing the variable", (yylsp[-2]).last_line);
        setErrType(ERR_OTHER);
    }
#line 2359 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 596 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p2 = terminal(_ASSIGNOP, '=', "");
        (yyval.nPtr) = nTerminal(Expression, (yyvsp[-2].nPtr));
        (yyvsp[-2].nPtr)->parent = (yyval.nPtr);
        addBro((yyvsp[-2].nPtr), p2);
        addBro(p2, (yyvsp[0].nPtr));
    }
#line 2371 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 603 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p2 = terminal(_AND, TK_AND, "");
        (yyval.nPtr) = nTerminal(Expression, (yyvsp[-2].nPtr));
        (yyvsp[-2].nPtr)->parent = (yyval.nPtr);
        addBro((yyvsp[-2].nPtr), p2);
        addBro(p2, (yyvsp[0].nPtr));
    }
#line 2383 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 610 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p2 = terminal(_OR, TK_OR, "");
        (yyval.nPtr) = nTerminal(Expression, (yyvsp[-2].nPtr));
        (yyvsp[-2].nPtr)->parent = (yyval.nPtr);
        addBro((yyvsp[-2].nPtr), p2);
        addBro(p2, (yyvsp[0].nPtr));
    }
#line 2395 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 617 "parser.y" /* yacc.c:1646  */
    {
        (yyval.nPtr) = nTerminal(Expression, (yyvsp[-2].nPtr));
        (yyvsp[-2].nPtr)->parent = (yyval.nPtr);
        addBro((yyvsp[-2].nPtr), (yyvsp[-1].nPtr));
        addBro((yyvsp[-1].nPtr), (yyvsp[0].nPtr));
    }
#line 2406 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 623 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p2 = terminal(_PLUS, '+', "");
        (yyval.nPtr) = nTerminal(Expression, (yyvsp[-2].nPtr));
        (yyvsp[-2].nPtr)->parent = (yyval.nPtr);
        addBro((yyvsp[-2].nPtr), p2);
        addBro(p2, (yyvsp[0].nPtr));
    }
#line 2418 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 630 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p2 = terminal(_MINUS, '-', "");
        (yyval.nPtr) = nTerminal(Expression, (yyvsp[-2].nPtr));
        (yyvsp[-2].nPtr)->parent = (yyval.nPtr);
        addBro((yyvsp[-2].nPtr), p2);
        addBro(p2, (yyvsp[0].nPtr));
    }
#line 2430 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 637 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p2 = terminal(_STAR, '*', "");
        (yyval.nPtr) = nTerminal(Expression, (yyvsp[-2].nPtr));
        (yyvsp[-2].nPtr)->parent = (yyval.nPtr);
        addBro((yyvsp[-2].nPtr), p2);
        addBro(p2, (yyvsp[0].nPtr));
    }
#line 2442 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 644 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p2 = terminal(_DIV, '/', "");
        (yyval.nPtr) = nTerminal(Expression, (yyvsp[-2].nPtr));
        (yyvsp[-2].nPtr)->parent = (yyval.nPtr);
        addBro((yyvsp[-2].nPtr), p2);
        addBro(p2, (yyvsp[0].nPtr));
    }
#line 2454 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 651 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p1, *p3;
        p1 = terminal(_LP, '(', "");
        p3 = terminal(_RP, ')', "");
        (yyval.nPtr) = nTerminal(Expression, p1);
        p1->parent = (yyval.nPtr);
        addBro(p1, (yyvsp[-1].nPtr));
        addBro((yyvsp[-1].nPtr), p3);
    }
#line 2468 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 660 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p1 = terminal(_MINUS, '-', "");
        (yyval.nPtr) = nTerminal(Expression, p1);
        p1->parent = (yyval.nPtr);
        addBro(p1, (yyvsp[0].nPtr));
    }
#line 2479 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 666 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p1 = terminal(_NOT, '!', "");
        (yyval.nPtr) = nTerminal(Expression, p1);
        p1->parent = (yyval.nPtr);
        addBro(p1, (yyvsp[0].nPtr));
    }
#line 2490 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 672 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p1, *p2, *p4;
        p1 = terminal(_ID, 0, (yyvsp[-3].name));
        p2 = terminal(_LP, '(', "");
        p4 = terminal(_RP, ')', "");
        (yyval.nPtr) = nTerminal(Expression, p1);
        p1->parent = (yyval.nPtr);
        addBro(p1, p2);
        addBro(p2, (yyvsp[-1].nPtr));
        addBro((yyvsp[-1].nPtr), p4);
    }
#line 2506 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 683 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p1, *p2, *p3;
        p1 = terminal(_ID, 0, (yyvsp[-2].name));
        p2 = terminal(_LP, '(', "");
        p3 = terminal(_RP, ')', "");
        (yyval.nPtr) = nTerminal(Expression, p1);
        p1->parent = (yyval.nPtr);
        addBro(p1, p2);
        addBro(p2, p3);
    }
#line 2521 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 693 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p2, *p4;
        p2 = terminal(_LB, '[', "");
        p4 = terminal(_RB, ']', "");
        (yyval.nPtr) = nTerminal(Expression, (yyvsp[-3].nPtr));
        (yyvsp[-3].nPtr)->parent = (yyval.nPtr);
        addBro((yyvsp[-3].nPtr), p2);
        addBro(p2, (yyvsp[-1].nPtr));
        addBro((yyvsp[-1].nPtr), p4);
    }
#line 2536 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 703 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p2, *p3;
        p2 = terminal(_DOT, '.', "");
        p3 = terminal(_ID, 0, (yyvsp[0].name));
        (yyval.nPtr) = nTerminal(Expression, (yyvsp[-2].nPtr));
        (yyvsp[-2].nPtr)->parent = (yyval.nPtr);
        addBro((yyvsp[-2].nPtr), p2);
        addBro(p2, p3);
    }
#line 2550 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 712 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p1;
        p1 = terminal(_ID, 0, (yyvsp[0].name));
        (yyval.nPtr) = nTerminal(Expression, p1);
        p1->parent = (yyval.nPtr);
    }
#line 2561 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 718 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p1;
        p1 = terminal(_INT, (yyvsp[0].iValue), "");
        (yyval.nPtr) = nTerminal(Expression, p1);
        p1->parent = (yyval.nPtr);
    }
#line 2572 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 724 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p1;
        p1 = terminal(_FLOAT, (yyvsp[0].fValue), "");
        (yyval.nPtr) = nTerminal(Expression, p1);
        p1->parent = (yyval.nPtr);
    }
#line 2583 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 730 "parser.y" /* yacc.c:1646  */
    {
        setErrType(ERR_TYPE10);
        m_error("missing \"(\"", (yylsp[-1]).last_line);
        setErrType(ERR_OTHER);
    }
#line 2593 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 735 "parser.y" /* yacc.c:1646  */
    {
        setErrType(ERR_TYPE10);
        m_error("missing \"]\"", (yylsp[-1]).last_line);
        setErrType(ERR_OTHER);
    }
#line 2603 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 740 "parser.y" /* yacc.c:1646  */
    {
        setErrType(ERR_TYPE10);
        m_error("missing \"(\"", (yylsp[-1]).last_line);
        setErrType(ERR_OTHER);
    }
#line 2613 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 747 "parser.y" /* yacc.c:1646  */
    {
        (yyval.nPtr) = nTerminal(RelOp, terminal(_LT, '<', "<"));
    }
#line 2621 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 750 "parser.y" /* yacc.c:1646  */
    {
        (yyval.nPtr) = nTerminal(RelOp, terminal(_GT, '>', ">"));
    }
#line 2629 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 753 "parser.y" /* yacc.c:1646  */
    {
        (yyval.nPtr) = nTerminal(RelOp, terminal(_LEQ, TK_LEQ, "<="));
    }
#line 2637 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 756 "parser.y" /* yacc.c:1646  */
    {
        (yyval.nPtr) = nTerminal(RelOp, terminal(_GEQ, TK_GEQ, ">="));
    }
#line 2645 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 759 "parser.y" /* yacc.c:1646  */
    {
        (yyval.nPtr) = nTerminal(RelOp, terminal(_EQU, TK_EQ, "=="));
    }
#line 2653 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 762 "parser.y" /* yacc.c:1646  */
    {
        (yyval.nPtr) = nTerminal(RelOp, terminal(_NEQ, TK_NEQ, "!="));
    }
#line 2661 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 767 "parser.y" /* yacc.c:1646  */
    {
        TreeNode *p2 = terminal(_COMMA, ',', "");
        (yyval.nPtr) = nTerminal(Args, (yyvsp[-2].nPtr));
        (yyvsp[-2].nPtr)->parent = (yyval.nPtr);
        addBro((yyvsp[-2].nPtr), p2);
        addBro(p2, (yyvsp[0].nPtr));
    }
#line 2673 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 774 "parser.y" /* yacc.c:1646  */
    {
        (yyval.nPtr) = nTerminal(Args, (yyvsp[0].nPtr));
        (yyvsp[0].nPtr)->parent = (yyval.nPtr);
    }
#line 2682 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 778 "parser.y" /* yacc.c:1646  */
    {
        setErrType(ERR_TYPE11);
        m_error("something wrong with your expression", (yylsp[-2]).last_line);
        setErrType(ERR_OTHER);
    }
#line 2692 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2696 "parser.tab.c" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 785 "parser.y" /* yacc.c:1906  */

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("Invalid input!\n");
        printf("You can input \"-h\" or \"-help\" for help\n");
        return 0;
    }
    if(strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "-help") == 0)
    {
        printf("usage: complier.exe [input_file_name]\n");
        printf("       Output file will be in the same directory. Output files are as follows:\n");
        printf("       1. \"[input_file_name].tree\" for syntax tree;\n");
        printf("       2. \"[input_file_name].ir\" for IR;\n");
        printf("       3. \"[input_file_name].asm\" for MIPS instructions.\n");
        return 0; 
    }
    if((yyin = fopen(argv[1], "r")) == NULL)
    {
        perror(argv[1]);
        return 0;
    }
    char treeFileName[100], irFileName[100], targetFileName[100];
    setFileName(treeFileName, argv[1], ".tree");
    setFileName(irFileName, argv[1], ".ir");
    setFileName(targetFileName, argv[1], ".asm");
    treeFile = fopen(treeFileName, "w");
    //yydebug = 1;
    yyparse();
    fclose(yyin);
    initTable();
    semantics(syntaxTree);
    printTree(syntaxTree, 0);
    fclose(treeFile);
    if(errorOccured == FALSE)
    {
        translate(syntaxTree);
        //printf("^^^^^^^^^^^^^^^^\n");
        printCode(irFileName);
        targetFile = fopen(targetFileName, "w");
        targetCode(irHead);
        fclose(targetFile);
    }
    destroyTable();
    return 0;
}

void yyerror(char *msg)
{
    if(et != ERR_OTHER)
        strcpy(message, msg + 13);
    else
        printf("%s at line %d.\n", msg, yylineno);
}

void m_error(char *msg, int lineno)
{
    printf("Error type %d at Line %d: %s, maybe %s.\n", et, lineno, message, msg);
}

void setErrType(ErrorType errType)
{
    et = errType;
}

void setFileName(char *tarName, char *srcName, char *postfix)
{
    if(srcName == NULL)
        return;
    int len = strlen(srcName), pos = -1;
    for(int i = len - 1; i >= 0; i--)
    {
        if(srcName[i] == '.')
        {
            pos = i;
            break;
        }
    }
    if(pos != -1)
    {
        int i;
        for(i = 0; i < pos; i++)
            tarName[i] = srcName[i];
        tarName[i] = '\0';
    }
    else
        strcpy(tarName, srcName);
    strcat(tarName, postfix);
}
