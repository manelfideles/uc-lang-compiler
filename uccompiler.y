%{
        #include <stdlib.h>
        #include <stdio.h>
        #include <string.h>
        #include "y.tab.h"

        int yylex();
        int yyerror(char *msg);


%}

%union {
    char* str_value;
    // node_ptr
}

%token<str_value> RESERVED MINUS PLUS MUL DIV MOD BITWISEAND BITWISEOR BITWISEXOR AND NOT OR EQ NE LE GE LT GT CHAR INT SHORT DOUBLE VOID IF ELSE WHILE RETURN ASSIGN COMMA LBRACE RBRACE LPAR RPAR SEMI
%token<str_value> ID CHRLIT INTLIT REALLIT

%right ASSIGN
%left OR
%left AND
%left BITWISEXOR
%left EQ NE
%left GE GT LE LT
%left PLUS MINUS
%left MUL DIV MOD
%right NOT
%left RPAR
%right LPAR
%right ELSE

%%

FunctionsAndDeclarations: %empty
                        | FunctionDefinition FunctionsAndDeclarations
                        | FunctionDeclaration FunctionsAndDeclarations
                        | Declaration FunctionsAndDeclarations
                        ;

FunctionDefinition: Typespec FunctionDeclarator FunctionBody
                  ;

FunctionBody:   LBRACE DeclarationsAndStatements RBRACE
            |   LBRACE RBRACE
            ;

DeclarationsAndStatements: Statement DeclarationsAndStatements
                         | Declaration DeclarationsAndStatements
                         | Statement
                         | Declaration
                         ;

FunctionDeclaration:    Typespec FunctionDeclarator SEMI
                   ;

FunctionDeclarator: ID LPAR ParameterList RPAR
                  ;

ParameterList:  ParameterDeclaration
             |  COMMA ParameterList
             ;

ParameterDeclaration: Typespec
                    | Typespec ID
                    ;

Declaration:    Typespec Declarator Declaration SEMI
           |    COMMA Declarator
           ;

Declarator:  ID
          |  ID ASSIGN Expr
          ;

Statement:   Expr SEMI
         |   SEMI
         |   LBRACE Statement RBRACE
         |   IF LPAR Expr RPAR Statement
         |   IF LPAR Expr RPAR Statement ELSE Statement
         |   WHILE LPAR Expr RPAR Statement
         |   RETURN Expr SEMI
         |   RETURN SEMI
         ;

Expr:   Expr ASSIGN Expr
    |   Expr MUL Expr
    |   Expr DIV Expr
    |   Expr PLUS Expr
    |   Expr MINUS Expr
    |   Expr MOD Expr
    |   Expr EQ Expr
    |   Expr GE Expr
    |   Expr GT Expr
    |   Expr LE Expr
    |   Expr LT Expr
    |   Expr NE Expr
    |   Expr AND Expr
    |   Expr OR Expr
    |   Expr BITWISEAND Expr
    |   Expr BITWISEOR Expr
    |   Expr BITWISEXOR Expr
    |   Expr COMMA Expr
    |   PLUS Expr
    |   MINUS Expr
    |   NOT Expr
    |   ID LPAR RPAR
    |   ID LPAR Expr RPAR
    |   COMMA Expr
    |   ID
    |   INTLIT
    |   CHRLIT
    |   REALLIT
    |   LPAR Expr RPAR
    ;
Typespec: CHAR
        | INT
        | SHORT
        | DOUBLE
        | VOID
        ;
%%

int yyerror(char *msg) {
    printf("%s", msg);
    return 1;
}