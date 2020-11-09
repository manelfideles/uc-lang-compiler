/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 13 "uccompiler.y" /* yacc.c:1909  */

    char* str_value;
    // node_ptr

#line 137 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
