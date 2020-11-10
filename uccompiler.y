%{
        #include <stdlib.h>
        #include <stdio.h>
        #include <string.h>
        #include "functions.h"
        #include "y.tab.h"

        int yylex();
        int yyerror(const char *s);

        NodePtr* root = NULL;
        NodePtr* current = NULL;

        // FLags de erros lexicais, sintáticos, e imprimir árvore
        int e1, e2, t;
        int debug = 0;

%}

%union {
    char* str_value;
    //NodePtr* node;
}

%define parse.error verbose

%token<str_value> MINUS PLUS MUL DIV MOD BITWISEAND BITWISEOR BITWISEXOR AND NOT OR EQ NE LE GE LT GT CHAR INT SHORT DOUBLE VOID IF ELSE WHILE RETURN ASSIGN COMMA LBRACE RBRACE LPAR RPAR SEMI
%token<str_value> ID CHRLIT INTLIT REALLIT
//%type<node> Program, VarDec, FuncDec, FuncDefin, ParamList, FuncBody, ParamDec, StatList, If, While, Return, Or, And, Eq, Ne, Lt, Gt, Le, Ge, Add, Sub, Mul, Div, Mod, Not, Minus, Plus, Store, Comma, Call, BitWiseAnd, BitWiseXor, BitWiseOr, Char, ChrLit, Id, Int, Short, IntLit, Double, RealLit, Void, Null

    /* prioridade mais alta em baixo, mais baixa em cima */
%left COMMA
%right ASSIGN
%left OR
%left AND
%left BITWISEOR
%left BITWISEXOR
%left BITWISEAND
%left EQ NE
%left GE GT LE LT
%left PLUS MINUS
%left MUL DIV MOD
%right NOT
%left RPAR
%right LPAR
%right ELSE

%%
Program: FunctionsAndDeclarations {
                                    if(debug) printf("Program\n");
                                  }
       ;
FunctionsAndDeclarations: %empty {if(debug) printf("FunctionsAndDeclarations: EMPTY\n");}
                        | FunctionDefinition FunctionsAndDeclarations {if(debug) printf("FunctionsAndDeclarations: FunctionDefinition\n");}
                        | FunctionDeclaration FunctionsAndDeclarations {if(debug) printf("FunctionsAndDeclarations: FunctionDeclaration\n");}
                        | Declaration FunctionsAndDeclarations {if(debug) printf("FunctionsAndDeclarations: Declaration\n");}
                        ;

FunctionDefinition: Typespec FunctionDeclarator FunctionBody {if(debug) printf("Function Definition: Typespec FunctionDeclarator FunctionBody\n");}
                  ;

FunctionBody:   LBRACE DeclarationsAndStatements RBRACE {if(debug) printf("FunctionBody: {DeclarationsAndStatements}\n");}
            |   LBRACE RBRACE {if(debug) printf("FunctionBody: {}\n");}
            ;

DeclarationsAndStatements: Statement DeclarationsAndStatements {if(debug) printf("DeclarationsAndStatements: Statements\n");}
                         | Declaration DeclarationsAndStatements {if(debug) printf("DeclarationsAndStatements: Declaration\n");}
                         | Statement {if(debug) printf("DeclarationsAndStatements: Statement\n");}
                         | Declaration{if(debug) printf("DeclarationsAndStatements: Declaration\n");}
                         ;

FunctionDeclaration:  Typespec FunctionDeclarator SEMI {if(debug) printf("FunctionDeclaration: Typespec Function Declarator SEMI\n");}
                   ;

FunctionDeclarator: ID LPAR ParameterList RPAR {if(debug) printf("FunctionDeclarator: ID (ParameterList)\n");}
                  ;

ParameterList:  ParameterDeclaration {if(debug) printf("Parameter List: Parameter Declaration\n");}
             |  COMMA ParameterList {if(debug) printf("Parameter List: COMMA ParameterList\n");}
             ;

ParameterDeclaration: Typespec ParameterDeclarationAux {if(debug) printf("ParameterDeclaration: TypeSpec ParameterDeclarationAux\n");}
                    | Typespec ID ParameterDeclarationAux {if(debug) printf("ParameterDeclaration: TypeSpec ID ParameterDeclarationAux\n");}
                    ;
ParameterDeclarationAux: COMMA ParameterDeclaration {if(debug) printf("ParameterDeclarationAux: COMMA ParameterDeclaration\n");}
                       | %empty {if(debug) printf("ParameterDeclarationAux: EMPTY\n");}
                       ;

Declaration: Typespec Declarator DeclarationAux SEMI {if(debug) printf("Declaration: TypeSpec Declarator DeclarationAux SEMI\n");}
           ;
DeclarationAux: COMMA Declarator DeclarationAux {if(debug) printf("DeclarationAux: COMMA Declarator DeclarationAux\n");}
              | %empty {if(debug) printf("DeclarationAux: EMPTY\n");}
              ;

Declarator:  ID {if(debug) printf("Declarator: ID\n");}
          |  ID ASSIGN Expr {if(debug) printf("Declarator: ID ASSIGN Expr\n");}
          ;

Statement:   Expr SEMI {if(debug) printf("Statement: Expr SEMI\n");}
         |   SEMI {if(debug) printf("Statement: SEMI\n");}
         |   IF LPAR Expr RPAR Statement {if(debug) printf("Statement: IF LPAR Expr RPAR Statement\n");}
         |   IF LPAR Expr RPAR Statement ELSE Statement {if(debug) printf("Statement: IF LPAR Expr RPAR Statement ELSE Statement\n");}
         |   WHILE LPAR Expr RPAR Statement {if(debug) printf("Statement: WHILE LPAR Expr RPAR Statement\n");}
         |   RETURN Expr SEMI {if(debug) printf("Statement: RETURN Expr SEMI\n");}
         |   RETURN SEMI {if(debug) printf("Statement: RETURN SEMI\n");}
         |   LBRACE StatementAux RBRACE {if(debug) printf("Statement: LBRACE Statement RBRACE \n");}
         ;
StatementAux: Statement StatementAux {if(debug) printf("StatementAux: Statement\n");}
            | %empty {if(debug) printf("StatementAux: EMPTY\n");}
            ;

Assignment: ID ASSIGN Expr {if(debug) printf("Assignment: ID ASSIGN Expr\n");}
          ;

FunctionCall: ID LPAR ArgumentsInFunction RPAR {if(debug) printf("FunctionCall: ID LPAR ArgumentsInFunction RPAR\n");}
            ;

ArgumentsInFunction: %empty {if(debug) printf("ArgumentsInFunction: EMPTY\n");}
                   | Expr {if(debug) printf("ArgumentsInFunction: Expr\n");}
                   | COMMA Expr {if(debug) printf("ArgumentsInFunction: COMMA Expr\n");}
                   ;

Expr:  FunctionCall {if(debug) printf("Expr: FunctionCal\n");}
    |  Assignment {if(debug) printf("Expr: Assignment\n");}
    |  Expr MUL Expr {if(debug) printf("Expr: Expr MUL Expr\n");}
    |  Expr DIV Expr {if(debug) printf("Expr: Expr DIV Expr\n");}
    |  Expr PLUS Expr {if(debug) printf("Expr: Expr PLUS Expr\n");}
    |  Expr MINUS Expr {if(debug) printf("Expr: Expr MINUS Expr\n");}
    |  Expr MOD Expr {if(debug) printf("Expr: Expr MOD Expr\n");}
    |  Expr AND Expr {if(debug) printf("Expr: Expr AND Expr\n");}
    |  Expr OR Expr {if(debug) printf("Expr: Expr OR Expr\n");}
    |  Expr BITWISEAND Expr {if(debug) printf("Expr: Expr BITWISEAND Expr\n");}
    |  Expr BITWISEOR Expr {if(debug) printf("Expr: Expr BITWISEOR Expr\n");}
    |  Expr BITWISEXOR Expr {if(debug) printf("Expr: Expr BITWISEXOR Expr\n");}
    |  Expr EQ Expr {if(debug) printf("Expr: Expr EQ Expr\n");}
    |  Expr NE Expr {if(debug) printf("Expr: Expr NE Expr\n");}
    |  Expr GE Expr {if(debug) printf("Expr: Expr GE Expr\n");}
    |  Expr GT Expr {if(debug) printf("Expr: Expr GT Expr\n");}
    |  Expr LE Expr {if(debug) printf("Expr: Expr LE Expr\n");}
    |  Expr LT Expr {if(debug) printf("Expr: Expr LT Expr\n");}
    |  Expr COMMA Expr {if(debug) printf("Expr: Expr COMMA Expr\n");}
    |  NOT Expr {if(debug) printf("Expr: NOT Expr\n");}
    |  PLUS Expr %prec NOT {if(debug) printf("Expr: PLUS Expr NOT\n");}
    |  MINUS Expr %prec NOT {if(debug) printf("Expr: MINUS Expr NOT\n");}
    |  LPAR Expr RPAR {if(debug) printf("Expr: LPAR Expr RPAR\n");}
    |  ID {if(debug) printf("Expr: ID\n"); /*flush*/; sprintf(string, "IntLit(%s)", yyval.str_value); /*$$ = appendNode(strdup(string), NULL)*/}
    |  INTLIT {if(debug) printf("Expr: INTLIT\n");}
    |  CHRLIT {if(debug) printf("Expr: CHRLIT\n");}
    |  REALLIT {if(debug) printf("Expr: REALLIT\n");}
    ;

Typespec: CHAR
        | INT
        | SHORT
        | DOUBLE
        | VOID
        ;

%%

int main(int argc, char *argv[]) {
    if (argc > 1) {
        if(strcmp(argv[1],"-l") == 0) {
            e1 = 0;
        }
    }
    yyparse();
    return 0;
}