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
#line 1 "uccompiler.y" /* yacc.c:339  */

        #include <stdlib.h>
        #include <stdio.h>
        #include <string.h>
        #include "functions.h"
        #include "y.tab.h"
        #define MAXSTRINGLEN 300

        int yylex();
        int yyerror(const char *s);

        NodePtr* program;
    

        // FLags de erros lexicais sintáticos e imprimir árvore
        int e1, e2, t;

        // para imprimir as produções
        int debug = 0;

        //string de intlit reallit chrlit id
        char string[MAXSTRINGLEN];


#line 91 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    MINUS = 258,
    PLUS = 259,
    MUL = 260,
    DIV = 261,
    MOD = 262,
    BITWISEAND = 263,
    BITWISEOR = 264,
    BITWISEXOR = 265,
    AND = 266,
    NOT = 267,
    OR = 268,
    EQ = 269,
    NE = 270,
    LE = 271,
    GE = 272,
    LT = 273,
    GT = 274,
    CHAR = 275,
    INT = 276,
    SHORT = 277,
    DOUBLE = 278,
    VOID = 279,
    IF = 280,
    ELSE = 281,
    WHILE = 282,
    RETURN = 283,
    ASSIGN = 284,
    COMMA = 285,
    LBRACE = 286,
    RBRACE = 287,
    LPAR = 288,
    RPAR = 289,
    SEMI = 290,
    ID = 291,
    CHRLIT = 292,
    INTLIT = 293,
    REALLIT = 294
  };
#endif
/* Tokens.  */
#define MINUS 258
#define PLUS 259
#define MUL 260
#define DIV 261
#define MOD 262
#define BITWISEAND 263
#define BITWISEOR 264
#define BITWISEXOR 265
#define AND 266
#define NOT 267
#define OR 268
#define EQ 269
#define NE 270
#define LE 271
#define GE 272
#define LT 273
#define GT 274
#define CHAR 275
#define INT 276
#define SHORT 277
#define DOUBLE 278
#define VOID 279
#define IF 280
#define ELSE 281
#define WHILE 282
#define RETURN 283
#define ASSIGN 284
#define COMMA 285
#define LBRACE 286
#define RBRACE 287
#define LPAR 288
#define RPAR 289
#define SEMI 290
#define ID 291
#define CHRLIT 292
#define INTLIT 293
#define REALLIT 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 26 "uccompiler.y" /* yacc.c:355  */

    char* str_value;
    char* id_value;
    struct node *node;

#line 215 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 232 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   496

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  132

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    56,    56,    62,    66,    74,    82,    92,   102,   107,
     113,   120,   128,   129,   132,   140,   149,   161,   164,   168,
     173,   180,   191,   197,   203,   207,   214,   219,   223,   227,
     231,   240,   244,   248,   254,   265,   272,   281,   291,   302,
     305,   312,   317,   322,   328,   334,   340,   346,   352,   358,
     364,   370,   376,   382,   388,   394,   400,   406,   412,   418,
     424,   428,   432,   436,   440,   444,   450,   455,   462,   463,
     464,   465,   466,   468
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MINUS", "PLUS", "MUL", "DIV", "MOD",
  "BITWISEAND", "BITWISEOR", "BITWISEXOR", "AND", "NOT", "OR", "EQ", "NE",
  "LE", "GE", "LT", "GT", "CHAR", "INT", "SHORT", "DOUBLE", "VOID", "IF",
  "ELSE", "WHILE", "RETURN", "ASSIGN", "COMMA", "LBRACE", "RBRACE", "LPAR",
  "RPAR", "SEMI", "ID", "CHRLIT", "INTLIT", "REALLIT", "$accept",
  "Program", "FunctionsAndDeclarations", "FunctionDefinition",
  "FunctionBody", "DeclarationsAndStatements",
  "DeclarationsAndStatementsAux", "FunctionDeclaration",
  "FunctionDeclarator", "ParameterList", "ParameterListAux",
  "ParameterDeclaration", "Declaration", "DeclarationAux", "Declarator",
  "Statement", "StatementAux", "Assignment", "FunctionCall",
  "ArgumentsInFunction", "ExprAux", "Expr", "Typespec", "IdToken", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

#define YYPACT_NINF -33

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-33)))

#define YYTABLE_NINF -60

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -5,   -33,   -33,   -33,   -33,   -33,     6,   -33,    -5,    -5,
      -5,   -11,   -33,   -33,   -33,   -33,   -33,   -23,     1,   -20,
      80,   -33,   -33,   -11,     5,   168,    -5,   168,   168,   168,
       9,    10,   161,   154,   -33,   168,   -33,   -33,   -33,   -33,
      29,   117,   117,   -33,   -33,   205,   -11,    -1,     1,    36,
     -33,   403,    40,    45,   -11,   -33,   -33,   -33,   168,   168,
     -33,   238,   154,    56,   271,   -33,   -33,   -33,   -33,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   -33,   168,   168,   -33,
     -33,    -5,   -33,   -33,   303,   335,   -33,   -33,   -33,   -33,
      32,    32,   -33,   -33,   -33,   460,    63,   454,   437,   420,
     477,   477,    17,    17,    17,    17,   403,   403,    57,   367,
     -33,   154,   154,   -33,   168,   -33,    67,   -33,   -33,   385,
     154,   -33
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    68,    69,    70,    71,    72,     0,     2,     3,     3,
       3,     0,     1,     4,     5,     6,    73,     0,    23,    24,
       0,    14,     7,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    35,     9,     0,    27,    66,    65,    67,
       0,    12,    12,    42,    41,     0,     0,    64,    23,    24,
      21,    25,     0,    18,    19,    62,    61,    60,     0,     0,
      32,     0,    35,     0,     0,     8,    13,    11,    10,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    26,     0,     0,    22,
      15,     0,    16,    20,     0,     0,    31,    34,    33,    63,
      46,    45,    43,    44,    47,    50,    51,    52,    48,    49,
      53,    54,    57,    55,    58,    56,    59,    36,     0,    39,
      17,     0,     0,    37,     0,    38,    28,    30,    40,    39,
       0,    29
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -33,   -33,    77,   -33,   -33,    74,    53,   -33,   -33,    15,
     -33,   -33,    -6,    48,    86,   -32,    35,   -33,   -33,   -14,
     -33,   -25,   -15,    18
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     6,     7,     8,    22,    66,    67,     9,    17,    52,
      92,    53,    10,    24,    18,    42,    63,    43,    44,   118,
     125,    45,    11,    47
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      51,    62,    55,    56,    57,    46,    12,    61,    20,    25,
      64,    54,    21,    26,    41,     1,     2,     3,     4,     5,
      69,    70,    71,    72,    73,    16,    46,    46,    87,    19,
      62,    23,    88,    94,    95,    41,    41,    71,    72,    73,
      50,    49,    58,    59,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,    65,   117,   119,    49,    25,    69,    70,    71,    72,
      73,    74,    93,    76,    90,    91,    54,    79,    80,    81,
      82,    83,    84,    27,    28,    13,    14,    15,    98,   126,
     127,   123,    29,   130,    40,    68,    89,    97,   131,   129,
       1,     2,     3,     4,     5,    30,   120,    31,    32,    48,
     128,    33,    34,    35,     0,    36,    16,    37,    38,    39,
      27,    28,     0,     0,     0,     0,     0,     0,     0,    29,
       0,     0,     0,     0,     0,     0,     0,     1,     2,     3,
       4,     5,    30,     0,    31,    32,     0,     0,    33,     0,
      35,     0,    36,    16,    37,    38,    39,    27,    28,     0,
       0,     0,     0,     0,    27,    28,    29,     0,     0,     0,
       0,    27,    28,    29,     0,     0,     0,     0,     0,    30,
      29,    31,    32,     0,     0,    33,     0,    35,     0,    36,
      16,    37,    38,    39,    35,     0,    60,    16,    37,    38,
      39,    35,     0,     0,    16,    37,    38,    39,    69,    70,
      71,    72,    73,    74,    75,    76,    77,     0,    78,    79,
      80,    81,    82,    83,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    85,     0,     0,     0,     0,
      86,    69,    70,    71,    72,    73,    74,    75,    76,    77,
       0,    78,    79,    80,    81,    82,    83,    84,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    85,     0,
       0,     0,     0,    96,    69,    70,    71,    72,    73,    74,
      75,    76,    77,     0,    78,    79,    80,    81,    82,    83,
      84,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    85,     0,     0,     0,    99,    69,    70,    71,    72,
      73,    74,    75,    76,    77,     0,    78,    79,    80,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    85,     0,     0,     0,   121,    69,    70,
      71,    72,    73,    74,    75,    76,    77,     0,    78,    79,
      80,    81,    82,    83,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    85,     0,     0,     0,   122,
      69,    70,    71,    72,    73,    74,    75,    76,    77,     0,
      78,    79,    80,    81,    82,    83,    84,     0,    69,    70,
      71,    72,    73,    74,    75,    76,    77,   124,    78,    79,
      80,    81,    82,    83,    84,     0,    69,    70,    71,    72,
      73,    74,    75,    76,    77,   -59,    78,    79,    80,    81,
      82,    83,    84,    69,    70,    71,    72,    73,    74,    75,
      76,    77,     0,     0,    79,    80,    81,    82,    83,    84,
      69,    70,    71,    72,    73,    74,    75,    76,     0,     0,
       0,    79,    80,    81,    82,    83,    84,    69,    70,    71,
      72,    73,    74,    69,    70,    71,    72,    73,    79,    80,
      81,    82,    83,    84,    79,    80,    81,    82,    83,    84,
      69,    70,    71,    72,    73,     0,     0,     0,     0,     0,
       0,     0,     0,    81,    82,    83,    84
};

static const yytype_int16 yycheck[] =
{
      25,    33,    27,    28,    29,    20,     0,    32,    31,    29,
      35,    26,    35,    33,    20,    20,    21,    22,    23,    24,
       3,     4,     5,     6,     7,    36,    41,    42,    29,    11,
      62,    30,    33,    58,    59,    41,    42,     5,     6,     7,
      35,    23,    33,    33,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    32,    87,    88,    46,    29,     3,     4,     5,     6,
       7,     8,    54,    10,    34,    30,    91,    14,    15,    16,
      17,    18,    19,     3,     4,     8,     9,    10,    32,   121,
     122,    34,    12,    26,    20,    42,    48,    62,   130,   124,
      20,    21,    22,    23,    24,    25,    91,    27,    28,    23,
     124,    31,    32,    33,    -1,    35,    36,    37,    38,    39,
       3,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    -1,    27,    28,    -1,    -1,    31,    -1,
      33,    -1,    35,    36,    37,    38,    39,     3,     4,    -1,
      -1,    -1,    -1,    -1,     3,     4,    12,    -1,    -1,    -1,
      -1,     3,     4,    12,    -1,    -1,    -1,    -1,    -1,    25,
      12,    27,    28,    -1,    -1,    31,    -1,    33,    -1,    35,
      36,    37,    38,    39,    33,    -1,    35,    36,    37,    38,
      39,    33,    -1,    -1,    36,    37,    38,    39,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      35,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,    16,    17,    18,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    35,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    16,    17,    18,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    34,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    16,
      17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    34,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    16,    17,    18,    19,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    30,    13,    14,
      15,    16,    17,    18,    19,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    30,    13,    14,    15,    16,
      17,    18,    19,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    -1,
      -1,    14,    15,    16,    17,    18,    19,     3,     4,     5,
       6,     7,     8,     3,     4,     5,     6,     7,    14,    15,
      16,    17,    18,    19,    14,    15,    16,    17,    18,    19,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    16,    17,    18,    19
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    21,    22,    23,    24,    41,    42,    43,    47,
      52,    62,     0,    42,    42,    42,    36,    48,    54,    63,
      31,    35,    44,    30,    53,    29,    33,     3,     4,    12,
      25,    27,    28,    31,    32,    33,    35,    37,    38,    39,
      45,    52,    55,    57,    58,    61,    62,    63,    54,    63,
      35,    61,    49,    51,    62,    61,    61,    61,    33,    33,
      35,    61,    55,    56,    61,    32,    45,    46,    46,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    13,    14,
      15,    16,    17,    18,    19,    30,    35,    29,    33,    53,
      34,    30,    50,    63,    61,    61,    35,    56,    32,    34,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    59,    61,
      49,    34,    34,    34,    30,    60,    55,    55,    59,    61,
      26,    55
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    42,    42,    43,    44,    44,
      45,    45,    46,    46,    47,    48,    49,    50,    50,    51,
      51,    52,    53,    53,    54,    54,    55,    55,    55,    55,
      55,    55,    55,    55,    56,    56,    57,    58,    59,    60,
      60,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    62,    62,
      62,    62,    62,    63
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     2,     3,     3,     2,
       2,     2,     0,     1,     3,     4,     2,     2,     0,     1,
       2,     4,     3,     0,     1,     3,     2,     1,     5,     7,
       5,     3,     2,     3,     2,     0,     3,     4,     2,     0,
       2,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
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
        case 2:
#line 56 "uccompiler.y" /* yacc.c:1646  */
    {
                                    if(debug) printf("Program\n");
                                    program = createNode("Program");
                                    (yyval.node) = program = appendNode(program, (yyvsp[0].node));
                                  }
#line 1480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 62 "uccompiler.y" /* yacc.c:1646  */
    {
                                                                            if(debug) printf("FunctionsAndDeclarations: EMPTY\n");
                                                                            (yyval.node) = createNode("Null");
                                                                        }
#line 1489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 66 "uccompiler.y" /* yacc.c:1646  */
    {
                                                                            if(debug) printf("FunctionsAndDeclarations: FunctionDefinition\n");
                                                                            if(strcmp((yyvsp[0].node)->type, "Null") != 0) {
                                                                                (yyvsp[-1].node)->next = (yyvsp[0].node);
                                                                                (yyval.node) = (yyvsp[-1].node);
                                                                            }
                                                                            else {(yyval.node) = (yyvsp[-1].node);}
                                                                        }
#line 1502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 74 "uccompiler.y" /* yacc.c:1646  */
    {
                                                                            if(debug) printf("FunctionsAndDeclarations: FunctionDeclaration\n");
                                                                            if(strcmp((yyvsp[0].node)->type, "Null") != 0) {
                                                                                (yyvsp[-1].node)->next = (yyvsp[0].node);
                                                                                (yyval.node) = (yyvsp[-1].node);
                                                                            }
                                                                            else {(yyval.node) = (yyvsp[-1].node);}
                                                                        }
#line 1515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 82 "uccompiler.y" /* yacc.c:1646  */
    {
                                                                            if(debug) printf("FunctionsAndDeclarations: Declaration\n");
                                                                            if(strcmp((yyvsp[0].node)->type, "Null") != 0) {
                                                                                (yyvsp[-1].node)->next = (yyvsp[0].node);
                                                                                (yyval.node) = (yyvsp[-1].node);
                                                                            }
                                                                            else {(yyval.node) = (yyvsp[-1].node);}
                                                                        }
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 92 "uccompiler.y" /* yacc.c:1646  */
    {
                                                                if(debug) printf("Function Definition: Typespec FunctionDeclarator FunctionBody\n");
                                                                struct node* tmp = (yyvsp[-1].node);
                                                                while(tmp->next) tmp = tmp->next;
                                                                (yyvsp[-2].node)->next = (yyvsp[-1].node); tmp->next = (yyvsp[0].node);
                                                                //printNode($1); printNode($1->next); printNode($1->next->next); printNode($1->next->next->next); 
                                                                (yyval.node) = appendNode(createNode("FuncDefinition"), (yyvsp[-2].node));
                                                             }
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 102 "uccompiler.y" /* yacc.c:1646  */
    {
                                                            if(debug) printf("FunctionBody: {DeclarationsAndStatements}\n");
                                                            (yyval.node) = appendNode(createNode("FuncBody"), (yyvsp[-1].node));
                                                            //printNode($$);
                                                        }
#line 1551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 107 "uccompiler.y" /* yacc.c:1646  */
    {
                                                            if(debug) printf("FunctionBody: {}\n");
                                                            //printNode($$);
                                                        }
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 113 "uccompiler.y" /* yacc.c:1646  */
    {
                                                                    if(debug) printf("DeclarationsAndStatements: Statements\n");
                                                                    struct node* tmp = (yyvsp[-1].node);
                                                                    while(tmp->next) tmp = tmp->next;
                                                                    tmp->next = (yyvsp[0].node);
                                                                    (yyval.node) = (yyvsp[-1].node);
                                                                 }
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 120 "uccompiler.y" /* yacc.c:1646  */
    {
                                                                    if(debug) printf("DeclarationsAndStatements: Declaration\n");
                                                                    struct node* dec = createNode("Declaration");
                                                                    dec = appendNode(dec, (yyvsp[-1].node));
                                                                    dec->next = (yyvsp[0].node);
                                                                    (yyval.node) = dec;
                                                                 }
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 128 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = createNode("Null");}
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 129 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 132 "uccompiler.y" /* yacc.c:1646  */
    {
                                                            if(debug) printf("FunctionDeclaration: Typespec Function Declarator SEMI\n");
                                                            (yyvsp[-2].node)->next = (yyvsp[-1].node);
                                                            (yyval.node) = appendNode(createNode("FuncDeclaration"), (yyvsp[-2].node));
                                                            //printNode($$);
                                                       }
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 140 "uccompiler.y" /* yacc.c:1646  */
    {
                                                    if(debug) printf("FunctionDeclarator: ID (ParameterList)\n");
                                                    struct node* paramlist = createNode("ParamList");
                                                    paramlist = appendNode(paramlist, (yyvsp[-1].node));
                                                    (yyvsp[-3].node)->next = paramlist;
                                                    (yyval.node) = (yyvsp[-3].node);
                                                }
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 149 "uccompiler.y" /* yacc.c:1646  */
    {
                                                        if(debug) printf("Parameter List: Parameter Declaration\n");
                                                        if(strcmp((yyvsp[0].node)->type, "Null") != 0) {
                                                            (yyvsp[-1].node)->next = (yyvsp[0].node);
                                                            (yyval.node) = appendNode(createNode("ParamDeclaration"), (yyvsp[-1].node));
                                                            //printNode($$); printNode($$->next);
                                                        }
                                                        else {
                                                            (yyval.node) = appendNode(createNode("ParamDeclaration"), (yyvsp[-1].node));
                                                        }
                                                      }
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 161 "uccompiler.y" /* yacc.c:1646  */
    {
                                            (yyval.node) = (yyvsp[0].node);
                                          }
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 164 "uccompiler.y" /* yacc.c:1646  */
    {
                                            (yyval.node) = createNode("Null");
                                          }
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 168 "uccompiler.y" /* yacc.c:1646  */
    {
                                        if(debug) printf("ParameterDeclaration: TypeSpec ParameterDeclarationAux\n");
                                        (yyval.node) = (yyvsp[0].node);
                                        //printNode($$);
                                    }
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 173 "uccompiler.y" /* yacc.c:1646  */
    {
                                        if(debug) printf("ParameterDeclaration: TypeSpec ID ParameterDeclarationAux\n");
                                        (yyvsp[-1].node)->next = (yyvsp[0].node);
                                        (yyval.node) = (yyvsp[-1].node);
                                    }
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 180 "uccompiler.y" /* yacc.c:1646  */
    {
                                                        if(debug) printf("Declaration: TypeSpec Declarator DeclarationAux SEMI\n");
                                                        if(strcmp((yyvsp[-1].node)->type, "Null") != 0) {
                                                            (yyvsp[-3].node)->next = (yyvsp[-2].node);
                                                            (yyvsp[-2].node)->next = (yyvsp[-1].node);
                                                        } 
                                                        else (yyvsp[-3].node)->next = (yyvsp[-2].node);
                                                        (yyval.node) = (yyvsp[-3].node);
                                                        //printNode($$);
                                                     }
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 191 "uccompiler.y" /* yacc.c:1646  */
    {
                                                    if(debug) printf("DeclarationAux: COMMA Declarator DeclarationAux\n");
                                                    if(strcmp((yyvsp[0].node)->type, "Null") != 0) (yyval.node) = (yyvsp[-1].node);
                                                    else (yyvsp[-1].node)->next = (yyvsp[0].node);
                                                    //printNode($$);
                                                }
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 197 "uccompiler.y" /* yacc.c:1646  */
    {
                                                    if(debug) printf("DeclarationAux: EMPTY\n");
                                                    (yyval.node) = createNode("Null");
                                                }
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 203 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Declarator: ID\n");
                                (yyval.node) = (yyvsp[0].node);
                            }
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 207 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Declarator: ID ASSIGN Expr\n");
                                (yyvsp[-2].node)->next = (yyvsp[0].node);
                                (yyval.node) = (yyvsp[-2].node);
                            }
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 214 "uccompiler.y" /* yacc.c:1646  */
    {
                                                            if(debug) printf("Statement: Expr SEMI\n");
                                                            (yyval.node) = (yyvsp[-1].node);
                                                            //printNode($$);
                                                        }
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 219 "uccompiler.y" /* yacc.c:1646  */
    {
                                                            if(debug) printf("Statement: SEMI\n");
                                                            //printNode($$);
                                                        }
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 223 "uccompiler.y" /* yacc.c:1646  */
    {
                                                            if(debug) printf("Statement: IF LPAR Expr RPAR Statement\n");
                                                            //
                                                        }
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 227 "uccompiler.y" /* yacc.c:1646  */
    {   
                                                            if(debug) printf("Statement: IF LPAR Expr RPAR Statement ELSE Statement\n");
                                                            //
                                                        }
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 231 "uccompiler.y" /* yacc.c:1646  */
    {   
                                                            if(debug) printf("Statement: WHILE LPAR Expr RPAR Statement\n");
                                                            struct node* while_token = createNode("While");
                                                            while_token = appendNode(while_token, (yyvsp[-2].node));
                                                            struct node* tmp = (yyvsp[-2].node);
                                                            while(tmp->next) tmp = tmp->next;
                                                            tmp->next = (yyvsp[0].node);
                                                            (yyval.node) = while_token;
                                                        }
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 240 "uccompiler.y" /* yacc.c:1646  */
    {
                                                            if(debug) printf("Statement: RETURN Expr SEMI\n");
                                                            (yyval.node) = appendNode(createNode("Return"), (yyvsp[-1].node));
                                                        }
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 244 "uccompiler.y" /* yacc.c:1646  */
    {
                                                            if(debug) printf("Statement: RETURN SEMI\n");
                                                            (yyval.node) = createNode("Return");
                                                        }
#line 1794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 248 "uccompiler.y" /* yacc.c:1646  */
    {
                                                            if(debug) printf("Statement: LBRACE Statement RBRACE \n");
                                                            struct node* statlist = createNode("StatList");
                                                            (yyval.node) = appendNode(statlist, (yyvsp[-1].node));
                                                        }
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 254 "uccompiler.y" /* yacc.c:1646  */
    {
                                        if(debug) printf("StatementAux: Statement\n");
                                        struct node* tmp = (yyvsp[-1].node);
                                        if(strcmp((yyvsp[0].node)->type, "Null") != 0) {
                                            while(tmp->next) tmp = tmp->next;
                                            tmp->next = (yyvsp[0].node);
                                            (yyval.node) = (yyvsp[-1].node);
                                        }
                                        else {(yyval.node) = (yyvsp[-1].node);}
                                        //printNode($$);
                                     }
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 265 "uccompiler.y" /* yacc.c:1646  */
    {
                                        if(debug) printf("StatementAux: EMPTY\n");
                                        (yyval.node) = createNode("Null");
                                        //printNode($$);
                                     }
#line 1830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 272 "uccompiler.y" /* yacc.c:1646  */
    {
                            if(debug) printf("Assignment: ID ASSIGN Expr\n");
                            struct node* store = createNode("Store");
                            store = appendNode(store, (yyvsp[0].node));
                            (yyval.node) = appendNode(store, (yyvsp[-2].node));
                            //printNode($$);
                           }
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 281 "uccompiler.y" /* yacc.c:1646  */
    {
                                                if(debug) printf("FunctionCall: ID LPAR ArgumentsInFunction RPAR\n");
                                                struct node* call = createNode("Call");
                                                (yyvsp[-3].node)->next = (yyvsp[-1].node);
                                                call = appendNode(call, (yyvsp[-3].node));
                                                (yyval.node) = call;
                                                //printNode($$);
                                               }
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 291 "uccompiler.y" /* yacc.c:1646  */
    {
                                        if(debug) printf("ArgumentsInFunction: Expr\n");
                                        struct node* tmp = (yyvsp[-1].node);
                                        if(strcmp((yyvsp[0].node)->type, "Null") != 0) {
                                            while(tmp->next) tmp = tmp->next;
                                            tmp->next = (yyvsp[0].node);
                                            (yyval.node) = (yyvsp[-1].node);
                                        }
                                        else {(yyval.node) = (yyvsp[-1].node);}
                                        //printNode($$);
                                   }
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 302 "uccompiler.y" /* yacc.c:1646  */
    {
                                        (yyval.node) = createNode("Null");
                                    }
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 305 "uccompiler.y" /* yacc.c:1646  */
    {
                                        if(debug) printf("ArgumentsInFunction: COMMA Expr\n");
                                        (yyval.node) = (yyvsp[0].node);
                                        //printNode($$);
                                    }
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 312 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: FunctionCall\n");
                                (yyval.node) = (yyvsp[0].node);
                                //printNode($$);
                               }
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 317 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: Assignment\n");
                                (yyval.node) = (yyvsp[0].node);
                                //printNode($$);
                               }
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 322 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: Expr OR Expr\n");
                                struct node* aux = createNode("Mul");
                                aux = appendNode(aux, (yyvsp[0].node));
                                (yyval.node) = appendNode(aux, (yyvsp[-2].node));
                               }
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 328 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: Expr OR Expr\n");
                                struct node* aux = createNode("Div");
                                aux = appendNode(aux, (yyvsp[0].node));
                                (yyval.node) = appendNode(aux, (yyvsp[-2].node));
                               }
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 334 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: Expr OR Expr\n");
                                struct node* aux = createNode("Add");
                                aux = appendNode(aux, (yyvsp[0].node));
                                (yyval.node) = appendNode(aux, (yyvsp[-2].node));
                               }
#line 1942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 340 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: Expr OR Expr\n");
                                struct node* aux = createNode("Sub");
                                aux = appendNode(aux, (yyvsp[0].node));
                                (yyval.node) = appendNode(aux, (yyvsp[-2].node));
                               }
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 346 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: Expr OR Expr\n");
                                struct node* aux = createNode("Mod");
                                aux = appendNode(aux, (yyvsp[0].node));
                                (yyval.node) = appendNode(aux, (yyvsp[-2].node));
                               }
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 352 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: Expr OR Expr\n");
                                struct node* aux = createNode("And");
                                aux = appendNode(aux, (yyvsp[0].node));
                                (yyval.node) = appendNode(aux, (yyvsp[-2].node));
                               }
#line 1975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 358 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: Expr OR Expr\n");
                                struct node* aux = createNode("Or");
                                aux = appendNode(aux, (yyvsp[0].node));
                                (yyval.node) = appendNode(aux, (yyvsp[-2].node));
                               }
#line 1986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 364 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: Expr BITWISEAND Expr\n");
                                struct node* aux = createNode("BitWiseAnd");
                                aux = appendNode(aux, (yyvsp[0].node));
                                (yyval.node) = appendNode(aux, (yyvsp[-2].node));
                               }
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 370 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: Expr BITWISEOR Expr\n");
                                struct node* aux = createNode("BitWiseOr");
                                aux = appendNode(aux, (yyvsp[0].node));
                                (yyval.node) = appendNode(aux, (yyvsp[-2].node));
                               }
#line 2008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 376 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: Expr BITWISEXOR Expr\n");
                                struct node* aux = createNode("BitWiseXor");
                                aux = appendNode(aux, (yyvsp[0].node));
                                (yyval.node) = appendNode(aux, (yyvsp[-2].node));
                               }
#line 2019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 382 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: Expr EQ Expr\n");
                                struct node* aux = createNode("Eq");
                                aux = appendNode(aux, (yyvsp[0].node));
                                (yyval.node) = appendNode(aux, (yyvsp[-2].node));
                               }
#line 2030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 388 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: Expr NE Expr\n");
                                struct node* aux = createNode("Ne");
                                aux = appendNode(aux, (yyvsp[0].node));
                                (yyval.node) = appendNode(aux, (yyvsp[-2].node));
                               }
#line 2041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 394 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: Expr GE Expr\n");
                                struct node* aux = createNode("Ge");
                                aux = appendNode(aux, (yyvsp[0].node));
                                (yyval.node) = appendNode(aux, (yyvsp[-2].node));
                               }
#line 2052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 400 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: Expr GT Expr\n");
                                struct node* aux = createNode("Gt");
                                aux = appendNode(aux, (yyvsp[0].node));
                                (yyval.node) = appendNode(aux, (yyvsp[-2].node));
                               }
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 406 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: Expr LE Expr\n");
                                struct node* aux = createNode("Le");
                                aux = appendNode(aux, (yyvsp[0].node));
                                (yyval.node) = appendNode(aux, (yyvsp[-2].node));
                               }
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 412 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: Expr LT Expr\n");
                                struct node* aux = createNode("Lt");
                                aux = appendNode(aux, (yyvsp[0].node));
                                (yyval.node) = appendNode(aux, (yyvsp[-2].node));
                               }
#line 2085 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 418 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: Expr COMMA Expr\n");
                                struct node* aux = createNode("Comma");
                                aux = appendNode(aux, (yyvsp[0].node));
                                (yyval.node) = appendNode(aux, (yyvsp[-2].node));
                               }
#line 2096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 424 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: NOT Expr\n");
                                (yyval.node) = appendNode(createNode("Not"), (yyvsp[0].node));
                               }
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 428 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: PLUS Expr NOT\n");
                                (yyval.node) = appendNode(createNode("Plus"), (yyvsp[0].node));
                               }
#line 2114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 432 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: MINUS Expr NOT\n");
                                (yyval.node) = appendNode(createNode("Minus"), (yyvsp[0].node));
                               }
#line 2123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 436 "uccompiler.y" /* yacc.c:1646  */
    {
                                 if(debug) printf("Expr: LPAR Expr RPAR\n");
                                 (yyval.node) = (yyvsp[-1].node);
                                }
#line 2132 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 440 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: ID\n");
                                (yyval.node) = (yyvsp[0].node);
                               }
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 444 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: INTLIT\n");
                                strcpy(string, "");
                                sprintf(string, "IntLit(%s)", yyval.str_value);
                                (yyval.node) = createNode(strdup(string));
                               }
#line 2152 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 450 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: CHRLIT\n");
                                sprintf(string, "ChrLit(%s)", yyval.str_value);
                                (yyval.node) = createNode(strdup(string));
                               }
#line 2162 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 455 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: REALLIT\n");
                                sprintf(string, "RealLit(%s)", yyval.str_value);
                                (yyval.node) = createNode(strdup(string));
                               }
#line 2172 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 462 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = createNode("Char");}
#line 2178 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 463 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = createNode("Int");}
#line 2184 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 464 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = createNode("Short");}
#line 2190 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 465 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = createNode("Double");}
#line 2196 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 466 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = createNode("Void");}
#line 2202 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 468 "uccompiler.y" /* yacc.c:1646  */
    {strcpy(string, ""); sprintf(string, "Id(%s)", yyval.id_value); (yyval.node) = createNode(strdup(string));}
#line 2208 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2212 "y.tab.c" /* yacc.c:1646  */
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
#line 470 "uccompiler.y" /* yacc.c:1906  */
