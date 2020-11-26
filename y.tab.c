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
# define YYERROR_VERBOSE 0
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
    RESERVED = 291,
    ID = 292,
    CHRLIT = 293,
    INTLIT = 294,
    REALLIT = 295
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
#define RESERVED 291
#define ID 292
#define CHRLIT 293
#define INTLIT 294
#define REALLIT 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 26 "uccompiler.y" /* yacc.c:355  */

    char* str_value;
    char* id_value;
    struct node *node;

#line 217 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 234 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   441

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  140

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    55,    55,    63,    71,    79,    91,    92,    93,    96,
     105,   109,   112,   125,   138,   139,   142,   150,   159,   163,
     170,   175,   182,   200,   202,   214,   224,   225,   228,   238,
     239,   240,   248,   320,   332,   333,   334,   335,   337,   348,
     350,   351,   353,   354,   362,   363,   375,   383,   384,   387,
     393,   399,   405,   411,   417,   423,   429,   435,   441,   447,
     453,   459,   465,   471,   477,   483,   489,   493,   497,   501,
     502,   506,   507,   511,   517,   522,   529,   530,   531,   532,
     533,   535
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MINUS", "PLUS", "MUL", "DIV", "MOD",
  "BITWISEAND", "BITWISEOR", "BITWISEXOR", "AND", "NOT", "OR", "EQ", "NE",
  "LE", "GE", "LT", "GT", "CHAR", "INT", "SHORT", "DOUBLE", "VOID", "IF",
  "ELSE", "WHILE", "RETURN", "ASSIGN", "COMMA", "LBRACE", "RBRACE", "LPAR",
  "RPAR", "SEMI", "RESERVED", "ID", "CHRLIT", "INTLIT", "REALLIT",
  "$accept", "Program", "FunctionsAndDeclarations", "FunctionDefinition",
  "FunctionBody", "DeclarationsAndStatements", "FunctionDeclaration",
  "FunctionDeclarator", "ParameterList", "ParameterDeclaration",
  "Declaration", "DeclarationAux", "Declarator", "Statement",
  "StatementList", "StatementError", "ArgList", "FuncCallArgList",
  "FunctionCall", "Expr", "Typespec", "IdToken", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

#define YYPACT_NINF -116

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-116)))

#define YYTABLE_NINF -40

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     100,   -24,  -116,  -116,  -116,  -116,  -116,    32,  -116,    68,
     253,   344,   -20,  -116,  -116,  -116,  -116,  -116,  -116,    -9,
     -17,  -116,    -2,    75,  -116,  -116,   -20,  -116,   254,    60,
     254,   254,   254,     3,     5,     2,   155,  -116,   232,  -116,
    -116,  -116,  -116,   115,  -116,  -116,   -11,  -116,   324,   -20,
      42,  -116,    16,   324,    37,  -116,   -20,  -116,  -116,  -116,
     254,   254,  -116,   -10,    12,  -116,  -116,    45,   172,    51,
      40,  -116,  -116,  -116,   254,  -116,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   222,    60,  -116,  -116,   111,   292,  -116,
    -116,  -116,  -116,    58,  -116,  -116,  -116,   324,   157,   157,
    -116,  -116,  -116,   417,   400,   343,   383,   366,   422,   422,
     125,   125,   125,   125,   324,    52,  -116,   127,   324,  -116,
     212,   212,  -116,   254,  -116,    78,  -116,   324,   212,  -116
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    76,    77,    78,    79,    80,     0,     2,     0,
       0,     0,     0,    23,     1,     3,     4,     5,    81,     0,
       0,    25,    26,     0,    16,     9,     0,    22,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    11,     0,    30,
      74,    73,    75,     0,    15,    14,     0,    69,    42,     0,
      72,    24,    26,    27,     0,    18,    20,    68,    67,    66,
       0,     0,    35,     0,     0,    37,    40,     0,     0,     0,
       0,    10,    13,    12,     0,    29,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    17,    21,     0,     0,    34,
      36,    41,    28,     0,    38,    71,    70,    43,    53,    52,
      50,    51,    54,    57,    58,    59,    55,    56,    60,    61,
      64,    62,    65,    63,    49,     0,    47,     0,    44,    19,
       0,     0,    48,     0,    46,    31,    33,    45,     0,    32
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -116,  -116,   159,  -116,  -116,  -116,  -116,  -116,  -116,     0,
     -15,  -116,    83,   -13,    43,  -115,   -26,  -116,  -116,   -28,
     -22,    17
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     7,     8,     9,    25,    43,    10,    19,    54,    55,
      11,    20,    21,    66,    67,    68,    46,   127,    47,    48,
      12,    50
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      53,    49,    57,    58,    59,    30,    31,    56,    44,    63,
      45,    13,    70,    26,    32,   135,   136,    18,    27,    74,
      74,    49,    23,   139,    75,    99,    24,    28,    72,    22,
      73,    29,    14,    98,    97,    38,    60,    62,    61,    18,
      40,    41,    42,    52,   100,    28,   107,   101,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   128,    52,    94,    -6,     1,
      74,    95,    56,    96,   106,    93,     1,   102,    30,    31,
       2,     3,     4,     5,     6,   105,   132,    32,     2,     3,
       4,     5,     6,   101,   129,     2,     3,     4,     5,     6,
      33,     1,    34,    35,   138,   137,    36,    37,    38,    51,
      39,   104,    18,    40,    41,    42,     1,     0,    30,    31,
       2,     3,     4,     5,     6,     0,     0,    32,    76,    77,
      78,    79,    80,     0,     0,     2,     3,     4,     5,     6,
      33,    74,    34,    35,     0,   130,    36,    71,    38,     0,
      39,     0,    18,    40,    41,    42,    64,   133,    30,    31,
       0,   134,    78,    79,    80,     0,     0,    32,    15,    16,
      17,     0,     0,   103,     0,    30,    31,     0,     0,     0,
      33,     0,    34,    35,    32,     0,    36,    65,    38,     0,
      39,     0,    18,    40,    41,    42,     0,    33,     0,    34,
      35,     0,     0,    36,   -39,    38,     0,    39,     0,    18,
      40,    41,    42,   103,     0,    30,    31,     0,     0,     0,
       0,     0,     0,   125,    32,    30,    31,     0,     0,     0,
       0,     0,     0,    69,    32,    30,    31,    33,     0,    34,
      35,     0,     0,    36,    32,    38,     0,    39,     0,    18,
      40,    41,    42,    -7,     1,    38,   126,    30,    31,    18,
      40,    41,    42,     0,     0,    38,    32,     0,     0,    18,
      40,    41,    42,     2,     3,     4,     5,     6,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,     0,     0,
       0,    18,    40,    41,    42,    76,    77,    78,    79,    80,
      81,    82,    83,    84,     0,    85,    86,    87,    88,    89,
      90,    91,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    92,     0,     0,     0,     0,   131,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,    85,    86,    87,
      88,    89,    90,    91,    -8,     1,    76,    77,    78,    79,
      80,    81,     0,    92,     0,     0,     0,    86,    87,    88,
      89,    90,    91,     0,     2,     3,     4,     5,     6,    76,
      77,    78,    79,    80,    81,    82,    83,    84,     0,     0,
      86,    87,    88,    89,    90,    91,    76,    77,    78,    79,
      80,    81,    82,    83,     0,     0,     0,    86,    87,    88,
      89,    90,    91,    76,    77,    78,    79,    80,    81,     0,
      83,     0,     0,     0,    86,    87,    88,    89,    90,    91,
      76,    77,    78,    79,    80,    76,    77,    78,    79,    80,
       0,    86,    87,    88,    89,    90,    91,     0,    88,    89,
      90,    91
};

static const yytype_int16 yycheck[] =
{
      28,    23,    30,    31,    32,     3,     4,    29,    23,    35,
      23,    35,    38,    30,    12,   130,   131,    37,    35,    30,
      30,    43,    31,   138,    35,    35,    35,    29,    43,    12,
      43,    33,     0,    61,    60,    33,    33,    35,    33,    37,
      38,    39,    40,    26,    32,    29,    74,    35,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    49,    30,     0,     1,
      30,    34,    94,    56,    34,    33,     1,    32,     3,     4,
      20,    21,    22,    23,    24,    34,    34,    12,    20,    21,
      22,    23,    24,    35,    94,    20,    21,    22,    23,    24,
      25,     1,    27,    28,    26,   133,    31,    32,    33,    26,
      35,    68,    37,    38,    39,    40,     1,    -1,     3,     4,
      20,    21,    22,    23,    24,    -1,    -1,    12,     3,     4,
       5,     6,     7,    -1,    -1,    20,    21,    22,    23,    24,
      25,    30,    27,    28,    -1,    34,    31,    32,    33,    -1,
      35,    -1,    37,    38,    39,    40,     1,    30,     3,     4,
      -1,    34,     5,     6,     7,    -1,    -1,    12,     9,    10,
      11,    -1,    -1,     1,    -1,     3,     4,    -1,    -1,    -1,
      25,    -1,    27,    28,    12,    -1,    31,    32,    33,    -1,
      35,    -1,    37,    38,    39,    40,    -1,    25,    -1,    27,
      28,    -1,    -1,    31,    32,    33,    -1,    35,    -1,    37,
      38,    39,    40,     1,    -1,     3,     4,    -1,    -1,    -1,
      -1,    -1,    -1,     1,    12,     3,     4,    -1,    -1,    -1,
      -1,    -1,    -1,     1,    12,     3,     4,    25,    -1,    27,
      28,    -1,    -1,    31,    12,    33,    -1,    35,    -1,    37,
      38,    39,    40,     0,     1,    33,    34,     3,     4,    37,
      38,    39,    40,    -1,    -1,    33,    12,    -1,    -1,    37,
      38,    39,    40,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,
      -1,    37,    38,    39,    40,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    13,    14,    15,    16,    17,
      18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    34,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
      16,    17,    18,    19,     0,     1,     3,     4,     5,     6,
       7,     8,    -1,    29,    -1,    -1,    -1,    14,    15,    16,
      17,    18,    19,    -1,    20,    21,    22,    23,    24,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    -1,    -1,    14,    15,    16,
      17,    18,    19,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    -1,    14,    15,    16,    17,    18,    19,
       3,     4,     5,     6,     7,     3,     4,     5,     6,     7,
      -1,    14,    15,    16,    17,    18,    19,    -1,    16,    17,
      18,    19
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    20,    21,    22,    23,    24,    42,    43,    44,
      47,    51,    61,    35,     0,    43,    43,    43,    37,    48,
      52,    53,    62,    31,    35,    45,    30,    35,    29,    33,
       3,     4,    12,    25,    27,    28,    31,    32,    33,    35,
      38,    39,    40,    46,    51,    54,    57,    59,    60,    61,
      62,    53,    62,    60,    49,    50,    61,    60,    60,    60,
      33,    33,    35,    57,     1,    32,    54,    55,    56,     1,
      57,    32,    51,    54,    30,    35,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    13,    14,    15,    16,    17,
      18,    19,    29,    33,    30,    34,    62,    57,    60,    35,
      32,    35,    32,     1,    55,    34,    34,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,     1,    34,    58,    60,    50,
      34,    34,    34,    30,    34,    56,    56,    60,    26,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    43,    43,    43,    43,    43,    44,
      45,    45,    46,    46,    46,    46,    47,    48,    49,    49,
      50,    50,    51,    51,    52,    52,    53,    53,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    55,    55,
      56,    56,    57,    57,    58,    58,    59,    59,    59,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    61,    61,    61,    61,
      61,    62
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     1,     1,     1,     3,
       3,     2,     2,     2,     1,     1,     3,     4,     1,     3,
       1,     2,     3,     2,     3,     1,     1,     3,     3,     2,
       1,     5,     7,     5,     3,     2,     3,     2,     2,     1,
       1,     2,     1,     3,     1,     3,     4,     3,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
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
#line 55 "uccompiler.y" /* yacc.c:1646  */
    {
                                    if((yyvsp[0].node)) {
                                        program = createNode("Program");
                                        (yyval.node) = program = appendNode(program, (yyvsp[0].node));
                                    }
                                    else {(yyval.node) = NULL; t = 1;}
                                  }
#line 1477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 63 "uccompiler.y" /* yacc.c:1646  */
    {
                                                                            if(debug) printf("FunctionsAndDeclarations: FunctionDefinition\n");
                                                                            if((yyvsp[0].node)) {
                                                                                (yyvsp[-1].node)->next = (yyvsp[0].node);
                                                                                (yyval.node) = (yyvsp[-1].node);
                                                                            }
                                                                            else {(yyval.node) = (yyvsp[-1].node);}
                                                                        }
#line 1490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 71 "uccompiler.y" /* yacc.c:1646  */
    {
                                                                            if(debug) printf("FunctionsAndDeclarations: FunctionDeclaration\n");
                                                                            if((yyvsp[0].node)) {
                                                                                (yyvsp[-1].node)->next = (yyvsp[0].node);
                                                                                (yyval.node) = (yyvsp[-1].node);
                                                                            }
                                                                            else {(yyval.node) = (yyvsp[-1].node);}
                                                                        }
#line 1503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 79 "uccompiler.y" /* yacc.c:1646  */
    {
                                                                            if(debug) printf("FunctionsAndDeclarations: Declaration\n");
                                                                            if((yyvsp[-1].node)) {
                                                                                if((yyvsp[0].node)) {
                                                                                    NodePtr* tmp = (yyvsp[-1].node);
                                                                                    while(tmp->next) tmp = tmp->next;
                                                                                    tmp->next = (yyvsp[0].node);
                                                                                }
                                                                                (yyval.node) = (yyvsp[-1].node);
                                                                            }
                                                                            else {(yyval.node) = (yyvsp[0].node);}
                                                                        }
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 91 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 92 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 93 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 96 "uccompiler.y" /* yacc.c:1646  */
    {
                                                                if(debug) printf("Function Definition: Typespec FunctionDeclarator FunctionBody\n");
                                                                struct node* tmp = (yyvsp[-1].node);
                                                                while(tmp->next) tmp = tmp->next;
                                                                (yyvsp[-2].node)->next = (yyvsp[-1].node); tmp->next = (yyvsp[0].node);
                                                                (yyval.node) = appendNode(createNode("FuncDefinition"), (yyvsp[-2].node));
                                                             }
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 105 "uccompiler.y" /* yacc.c:1646  */
    {
                                                            if(debug) printf("FunctionBody: {DeclarationsAndStatements}\n");
                                                            (yyval.node) = appendNode(createNode("FuncBody"), (yyvsp[-1].node));
                                                        }
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 109 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = appendNode(createNode("FuncBody"), NULL);}
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 112 "uccompiler.y" /* yacc.c:1646  */
    {
                                                                        if(debug) printf("DeclarationsAndStatements: Statements\n");
                                                                        if((yyvsp[-1].node)) {
                                                                            if((yyvsp[0].node)) {
                                                                                struct node* tmp = (yyvsp[-1].node);
                                                                                while(tmp->next) tmp = tmp->next;
                                                                                tmp->next = (yyvsp[0].node);
                                                                                (yyval.node) = (yyvsp[-1].node);
                                                                            }
                                                                        }
                                                                        else if((yyvsp[0].node)) {(yyval.node) = (yyvsp[0].node);}
                                                                        else {(yyval.node) = NULL;}
                                                                    }
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 125 "uccompiler.y" /* yacc.c:1646  */
    {
                                                                        if(debug) printf("DeclarationsAndStatements: Declaration\n");
                                                                        if((yyvsp[-1].node)) {
                                                                            if((yyvsp[0].node)) {
                                                                                struct node* tmp = (yyvsp[-1].node);
                                                                                while(tmp->next) tmp = tmp->next;
                                                                                tmp->next = (yyvsp[0].node);
                                                                                }
                                                                            (yyval.node) = (yyvsp[-1].node);
                                                                        }
                                                                        else if((yyvsp[0].node)) {(yyval.node) = (yyvsp[0].node);}
                                                                        else {(yyval.node) = NULL;}
                                                                    }
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 138 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);printf("droga");}
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 139 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);printf("aaaaaa");}
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 142 "uccompiler.y" /* yacc.c:1646  */
    {
                                                            if(debug) printf("FunctionDeclaration: Typespec Function Declarator SEMI\n");
                                                            (yyvsp[-2].node)->next = (yyvsp[-1].node);
                                                            (yyval.node) = appendNode(createNode("FuncDeclaration"), (yyvsp[-2].node));
                                                            //printNode($$);
                                                       }
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 150 "uccompiler.y" /* yacc.c:1646  */
    {
                                                    if(debug) printf("FunctionDeclarator: ID (ParameterList)\n");
                                                    struct node* paramlist = createNode("ParamList");
                                                    paramlist = appendNode(paramlist, (yyvsp[-1].node));
                                                    (yyvsp[-3].node)->next = paramlist;
                                                    (yyval.node) = (yyvsp[-3].node);
                                                }
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 159 "uccompiler.y" /* yacc.c:1646  */
    {
                                                        if(debug) printf("Parameter List: Parameter Declaration\n");
                                                        (yyval.node) = appendNode(createNode("ParamDeclaration"), (yyvsp[0].node));
                                                      }
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 163 "uccompiler.y" /* yacc.c:1646  */
    {
                                                            struct node* tmp = (yyvsp[-2].node);
                                                            while(tmp->next != NULL) tmp = tmp->next;
                                                            tmp->next = appendNode(createNode("ParamDeclaration"), (yyvsp[0].node));
                                                            (yyval.node) = (yyvsp[-2].node);
                                                        }
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 170 "uccompiler.y" /* yacc.c:1646  */
    {
                                        if(debug) printf("ParameterDeclaration: TypeSpec ParameterDeclarationAux\n");
                                        (yyval.node) = (yyvsp[0].node);
                                        //printNode($$);
                                    }
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 175 "uccompiler.y" /* yacc.c:1646  */
    {
                                        if(debug) printf("ParameterDeclaration: TypeSpec ID ParameterDeclarationAux\n");
                                        (yyvsp[-1].node)->next = (yyvsp[0].node);
                                        (yyval.node) = (yyvsp[-1].node);
                                    }
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 182 "uccompiler.y" /* yacc.c:1646  */
    {
                                            if(debug) printf("Declaration: TypeSpec Declarator DeclarationAux SEMI\n");
                                            if((yyvsp[-1].node)) {
                                                struct node* tmp = (yyvsp[-1].node);
                                                while(tmp) {
                                                    // criar nó typespec
                                                    struct node* typespec = createNode((yyvsp[-2].node)->type);
                                                    // bebés = os filhos de tmp
                                                    struct node* babies = tmp->children;
                                                    // tmp->children = nó typespec
                                                    tmp->children = typespec;
                                                    // nó typespec->next = bebés
                                                    typespec->next = babies;
                                                    tmp = tmp->next;
                                                }
                                            }
                                            (yyval.node) = (yyvsp[-1].node);
                                          }
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 200 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL; t = 1;}
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 202 "uccompiler.y" /* yacc.c:1646  */
    {
                                                    if(debug) printf("DeclarationAux: COMMA Declarator DeclarationAux\n");
                                                    //ll de declarators
                                                    if((yyvsp[-2].node)) {
                                                        struct node* tmp = (yyvsp[-2].node);
                                                        while(tmp->next) tmp = tmp->next;
                                                        if((yyvsp[0].node)) tmp->next = appendNode(createNode("Declaration"), (yyvsp[0].node));
                                                        (yyval.node) = (yyvsp[-2].node);
                                                    }
                                                    else if((yyvsp[0].node)) {(yyval.node) = (yyvsp[0].node);}
                                                    else {(yyval.node) = NULL;}
                                                }
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 214 "uccompiler.y" /* yacc.c:1646  */
    {
                                                    if(debug) printf("DeclarationAux: EMPTY\n");
                                                    if((yyvsp[0].node)) {
                                                        struct node* dec = createNode("Declaration");
                                                        (yyval.node) = appendNode(dec, (yyvsp[0].node));
                                                    }
                                                    else {(yyval.node) = NULL;}
                                                }
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 224 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 225 "uccompiler.y" /* yacc.c:1646  */
    {(yyvsp[-2].node)->next = (yyvsp[0].node); (yyval.node) = (yyvsp[-2].node);}
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 228 "uccompiler.y" /* yacc.c:1646  */
    {
                                                            if(debug) printf("Statement: LBRACE Statement RBRACE \n");
                                                            // criar statlist
                                                            (yyval.node) = (yyvsp[-1].node);
                                                            if((yyvsp[-1].node) && (yyvsp[-1].node)->next) {
                                                                struct node* statlist = createNode("StatList");
                                                                statlist = appendNode(statlist, (yyvsp[-1].node));
                                                                (yyval.node) = statlist;
                                                            }
                                                        }
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 238 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 239 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 240 "uccompiler.y" /* yacc.c:1646  */
    {
                                                            struct node* if_aux = createNode("If");
                                                            struct node* tmp = (yyvsp[-2].node);
                                                            while(tmp->next != NULL) {tmp = tmp->next;}
                                                            if((yyvsp[0].node) == NULL) {tmp->next = createNode("Null");}
                                                            else {tmp->next = (yyvsp[0].node); (yyvsp[0].node)->next = createNode("Null");}
                                                            (yyval.node) = appendNode(if_aux, (yyvsp[-2].node));
                                                        }
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 248 "uccompiler.y" /* yacc.c:1646  */
    {   
                                                            struct node* if_aux = createNode("If");
                                                            struct node* tmp = (yyvsp[-4].node);
                                                            while(tmp->next != NULL) {tmp = tmp->next;}


                                                            if((yyvsp[-2].node) && !(yyvsp[0].node)) {
                                                                struct node* tmp1 = (yyvsp[-2].node);
                                                                int k = 0;
                                                                if(tmp1->next) k++;
                                                                if(k == 0) {tmp->next = (yyvsp[-2].node); (yyvsp[-2].node)->next = createNode("Null");}
                                                                else {
                                                                    struct node* statlist = createNode("StatList");
                                                                    statlist->next = createNode("Null");
                                                                    tmp->next = appendNode(statlist, (yyvsp[-2].node));
                                                                }
                                                            }

                                                            else if(!(yyvsp[-2].node) && (yyvsp[0].node)) {
                                                                struct node* aux = (yyvsp[0].node);
                                                                int i = 0;
                                                                if(aux->next != NULL) i++;
                                                                if(i == 0){
                                                                    struct node* null = createNode("Null");
                                                                    tmp->next = null;
                                                                    null->next = (yyvsp[0].node);
                                                                }
                                                                else {
                                                                    struct node* null = createNode("Null");
                                                                    tmp->next = null;
                                                                    struct node* statlist2 = createNode("StatList");
                                                                    null->next = appendNode(statlist2, (yyvsp[0].node));
                                                                }
                                                            }

                                                            else if((yyvsp[-2].node) && (yyvsp[0].node)) {
                                                                //printf("%s --- %s\n", $5->type, $7->type);
                                                                struct node* tmp2 = (yyvsp[-2].node);
                                                                struct node* statlist = NULL;
                                                                struct node* tmp3 = (yyvsp[0].node);
                                                                struct node* statlist2 = NULL;
                                                                int i = 0; 
                                                                if(tmp2->next != NULL) {i++;}
                                                                if(i == 0){tmp->next = (yyvsp[-2].node);}
                                                                else {
                                                                    statlist = appendNode(createNode("StatList"), (yyvsp[-2].node));
                                                                    tmp->next = statlist;
                                                                }

                                                                int j = 0;
                                                                if(tmp3->next != NULL) j++;
                                                                if(j == 0) {
                                                                    if(statlist) statlist->next = (yyvsp[0].node);
                                                                    else {(yyvsp[-2].node)->next = (yyvsp[0].node);}
                                                                }
                                                                else {
                                                                    statlist2 = appendNode(createNode("StatList"), (yyvsp[0].node));
                                                                    if(statlist) statlist->next = statlist2;
                                                                    else {(yyvsp[-2].node)->next = statlist2;}
                                                                }
                                                            }

                                                            else {
                                                                struct node* A = createNode("Null");
                                                                struct node* B = createNode("Null");
                                                                tmp->next = A;
                                                                A->next = B;
                                                            }

                                                            if_aux = appendNode(if_aux, (yyvsp[-4].node));
                                                            (yyval.node) = if_aux;
                                                        }
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 320 "uccompiler.y" /* yacc.c:1646  */
    {   
                                                            struct node* while_token = createNode("While");
                                                            struct node* tmp = (yyvsp[-2].node);

                                                            while(tmp->next != NULL) tmp = tmp->next;
                                                            if((yyvsp[0].node)) tmp->next = (yyvsp[0].node);
                                                            else tmp->next = createNode("Null");

                                                            while_token = appendNode(while_token, (yyvsp[-2].node));
                                                            (yyval.node) = while_token;

                                                        }
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 332 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = appendNode(createNode("Return"), (yyvsp[-1].node));}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 333 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = appendNode(createNode("Return"), createNode("Null"));}
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 334 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL; t = 1;}
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 335 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 337 "uccompiler.y" /* yacc.c:1646  */
    {
                                                if((yyvsp[-1].node)) {
                                                    if((yyvsp[0].node)) {
                                                        struct node* tmp = (yyvsp[-1].node);
                                                        while(tmp->next) tmp = tmp->next;
                                                        tmp->next = (yyvsp[0].node);
                                                    }
                                                    (yyval.node) = (yyvsp[-1].node);
                                                }
                                                else (yyval.node) = (yyvsp[0].node);
                                             }
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 348 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 350 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 351 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL; t = 1;}
#line 1939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 353 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 354 "uccompiler.y" /* yacc.c:1646  */
    {
                                                if(debug) printf("Expr: Expr COMMA Expr\n");
                                                struct node* aux = createNode("Comma");
                                                aux = appendNode(aux, (yyvsp[0].node));
                                                (yyval.node) = appendNode(aux, (yyvsp[-2].node));
                                            }
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 362 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 363 "uccompiler.y" /* yacc.c:1646  */
    {
                                                if((yyvsp[-2].node)) {
                                                    struct node* tmp = (yyvsp[-2].node);
                                                    while(tmp->next) tmp = tmp->next;
                                                    if((yyvsp[-1].str_value)) tmp->next = (yyvsp[0].node);
                                                    (yyval.node) = (yyvsp[-2].node);
                                                }
                                                else if ((yyvsp[-1].str_value)) {(yyval.node) = (yyvsp[0].node);}
                                                else {(yyval.node) = NULL;}
                                                
                                            }
#line 1978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 375 "uccompiler.y" /* yacc.c:1646  */
    {
                                                    if(debug) printf("FunctionCall: ID LPAR ArgumentsInFunction RPAR\n");
                                                    struct node* call = createNode("Call");
                                                    (yyvsp[-3].node)->next = (yyvsp[-1].node);
                                                    call = appendNode(call, (yyvsp[-3].node));
                                                    (yyval.node) = call;
                                                    //printNode($$);
                                                }
#line 1991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 383 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = appendNode(createNode("Call"), (yyvsp[-2].node));}
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 384 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL; t = 1;}
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 387 "uccompiler.y" /* yacc.c:1646  */
    {
                                    if(debug) printf("Assignment: ID ASSIGN Expr\n");
                                    struct node* store = createNode("Store");
                                    store = appendNode(store, (yyvsp[0].node));
                                    (yyval.node) = appendNode(store, (yyvsp[-2].node));
                               }
#line 2014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 393 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: Expr OR Expr\n");
                                struct node* aux = createNode("Mul");
                                aux = appendNode(aux, (yyvsp[0].node));
                                (yyval.node) = appendNode(aux, (yyvsp[-2].node));
                               }
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 399 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: Expr OR Expr\n");
                                struct node* aux = createNode("Div");
                                aux = appendNode(aux, (yyvsp[0].node));
                                (yyval.node) = appendNode(aux, (yyvsp[-2].node));
                               }
#line 2036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 405 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: Expr OR Expr\n");
                                struct node* aux = createNode("Add");
                                aux = appendNode(aux, (yyvsp[0].node));
                                (yyval.node) = appendNode(aux, (yyvsp[-2].node));
                               }
#line 2047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 411 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: Expr OR Expr\n");
                                struct node* aux = createNode("Sub");
                                aux = appendNode(aux, (yyvsp[0].node));
                                (yyval.node) = appendNode(aux, (yyvsp[-2].node));
                               }
#line 2058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 417 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: Expr OR Expr\n");
                                struct node* aux = createNode("Mod");
                                aux = appendNode(aux, (yyvsp[0].node));
                                (yyval.node) = appendNode(aux, (yyvsp[-2].node));
                               }
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 423 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: Expr OR Expr\n");
                                struct node* aux = createNode("And");
                                aux = appendNode(aux, (yyvsp[0].node));
                                (yyval.node) = appendNode(aux, (yyvsp[-2].node));
                               }
#line 2080 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 429 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: Expr OR Expr\n");
                                struct node* aux = createNode("Or");
                                aux = appendNode(aux, (yyvsp[0].node));
                                (yyval.node) = appendNode(aux, (yyvsp[-2].node));
                               }
#line 2091 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 435 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: Expr BITWISEAND Expr\n");
                                struct node* aux = createNode("BitWiseAnd");
                                aux = appendNode(aux, (yyvsp[0].node));
                                (yyval.node) = appendNode(aux, (yyvsp[-2].node));
                               }
#line 2102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 441 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: Expr BITWISEOR Expr\n");
                                struct node* aux = createNode("BitWiseOr");
                                aux = appendNode(aux, (yyvsp[0].node));
                                (yyval.node) = appendNode(aux, (yyvsp[-2].node));
                               }
#line 2113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 447 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: Expr BITWISEXOR Expr\n");
                                struct node* aux = createNode("BitWiseXor");
                                aux = appendNode(aux, (yyvsp[0].node));
                                (yyval.node) = appendNode(aux, (yyvsp[-2].node));
                               }
#line 2124 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 453 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: Expr EQ Expr\n");
                                struct node* aux = createNode("Eq");
                                aux = appendNode(aux, (yyvsp[0].node));
                                (yyval.node) = appendNode(aux, (yyvsp[-2].node));
                               }
#line 2135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 459 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: Expr NE Expr\n");
                                struct node* aux = createNode("Ne");
                                aux = appendNode(aux, (yyvsp[0].node));
                                (yyval.node) = appendNode(aux, (yyvsp[-2].node));
                               }
#line 2146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 465 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: Expr GE Expr\n");
                                struct node* aux = createNode("Ge");
                                aux = appendNode(aux, (yyvsp[0].node));
                                (yyval.node) = appendNode(aux, (yyvsp[-2].node));
                               }
#line 2157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 471 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: Expr GT Expr\n");
                                struct node* aux = createNode("Gt");
                                aux = appendNode(aux, (yyvsp[0].node));
                                (yyval.node) = appendNode(aux, (yyvsp[-2].node));
                               }
#line 2168 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 477 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: Expr LE Expr\n");
                                struct node* aux = createNode("Le");
                                aux = appendNode(aux, (yyvsp[0].node));
                                (yyval.node) = appendNode(aux, (yyvsp[-2].node));
                               }
#line 2179 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 483 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: Expr LT Expr\n");
                                struct node* aux = createNode("Lt");
                                aux = appendNode(aux, (yyvsp[0].node));
                                (yyval.node) = appendNode(aux, (yyvsp[-2].node));
                               }
#line 2190 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 489 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: NOT Expr\n");
                                (yyval.node) = appendNode(createNode("Not"), (yyvsp[0].node));
                               }
#line 2199 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 493 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: PLUS Expr NOT\n");
                                (yyval.node) = appendNode(createNode("Plus"), (yyvsp[0].node));
                               }
#line 2208 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 497 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: MINUS Expr NOT\n");
                                (yyval.node) = appendNode(createNode("Minus"), (yyvsp[0].node));
                               }
#line 2217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 501 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2223 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 502 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: LPAR Expr RPAR\n");
                                (yyval.node) = (yyvsp[-1].node);
                               }
#line 2232 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 506 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL; t = 1;}
#line 2238 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 507 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: ID\n");
                                (yyval.node) = (yyvsp[0].node);
                               }
#line 2247 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 511 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: INTLIT\n");
                                strcpy(string, "");
                                sprintf(string, "IntLit(%s)", yyval.str_value);
                                (yyval.node) = createNode(strdup(string));
                               }
#line 2258 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 517 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: CHRLIT\n");
                                sprintf(string, "ChrLit(%s)", yyval.str_value);
                                (yyval.node) = createNode(strdup(string));
                               }
#line 2268 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 522 "uccompiler.y" /* yacc.c:1646  */
    {
                                if(debug) printf("Expr: REALLIT\n");
                                sprintf(string, "RealLit(%s)", yyval.str_value);
                                (yyval.node) = createNode(strdup(string));
                               }
#line 2278 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 529 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = createNode("Char");}
#line 2284 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 530 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = createNode("Int");}
#line 2290 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 531 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = createNode("Short");}
#line 2296 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 532 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = createNode("Double");}
#line 2302 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 533 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = createNode("Void");}
#line 2308 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 535 "uccompiler.y" /* yacc.c:1646  */
    {strcpy(string, ""); sprintf(string, "Id(%s)", yyval.id_value); (yyval.node) = createNode(strdup(string));}
#line 2314 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2318 "y.tab.c" /* yacc.c:1646  */
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
#line 537 "uccompiler.y" /* yacc.c:1906  */
