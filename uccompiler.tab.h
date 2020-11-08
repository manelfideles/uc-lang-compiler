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

#ifndef YY_YY_UCCOMPILER_TAB_H_INCLUDED
# define YY_YY_UCCOMPILER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    RESERVED = 258,
    MINUS = 259,
    PLUS = 260,
    MUL = 261,
    DIV = 262,
    MOD = 263,
    BITWISEAND = 264,
    BITWISEOR = 265,
    BITWISEXOR = 266,
    AND = 267,
    NOT = 268,
    OR = 269,
    EQ = 270,
    NE = 271,
    LE = 272,
    GE = 273,
    LT = 274,
    GT = 275,
    CHAR = 276,
    INT = 277,
    SHORT = 278,
    DOUBLE = 279,
    VOID = 280,
    IF = 281,
    ELSE = 282,
    WHILE = 283,
    RETURN = 284,
    ASSIGN = 285,
    COMMA = 286,
    LBRACE = 287,
    RBRACE = 288,
    LPAR = 289,
    RPAR = 290,
    SEMI = 291,
    ID = 292,
    CHRLIT = 293,
    INTLIT = 294,
    REALLIT = 295
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 13 "uccompiler.y" /* yacc.c:1909  */

    char* str_value;
    // node_ptr

#line 100 "uccompiler.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_UCCOMPILER_TAB_H_INCLUDED  */
