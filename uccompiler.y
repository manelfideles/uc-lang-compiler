%{
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

%}

%union {
    char* str_value;
    char* id_value;
    struct node *node;
}

%define parse.error verbose

%token<str_value> MINUS PLUS MUL DIV MOD BITWISEAND BITWISEOR BITWISEXOR AND NOT OR EQ NE LE GE LT GT CHAR INT SHORT DOUBLE VOID IF ELSE WHILE RETURN ASSIGN COMMA LBRACE RBRACE LPAR RPAR SEMI
%token<str_value> ID CHRLIT INTLIT REALLIT
%type<node> Program FunctionsAndDeclarations FunctionDefinition FunctionBody DeclarationsAndStatements FunctionDeclaration FunctionDeclarator ParameterList ParameterListAux ParameterDeclaration Declaration DeclarationAux Declarator Statement StatementAux Assignment FunctionCall ArgumentsInFunction Expr Typespec IdToken DeclarationsAndStatementsAux ExprAux

    /* prioridade mais alta em baixo mais baixa em cima */
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
                                    program = createNode("Program");
                                    $$ = program = appendNode(program, $1);
                                  }
       ;
FunctionsAndDeclarations: %empty                                        {
                                                                            if(debug) printf("FunctionsAndDeclarations: EMPTY\n");
                                                                            $$ = createNode("Null");
                                                                        }
                        | FunctionDefinition FunctionsAndDeclarations   {
                                                                            if(debug) printf("FunctionsAndDeclarations: FunctionDefinition\n");
                                                                            if(strcmp($2->type, "Null") != 0) {
                                                                                $1->next = $2;
                                                                                $$ = $1;
                                                                            }
                                                                            else {$$ = $1;}
                                                                        }
                        | FunctionDeclaration FunctionsAndDeclarations  {
                                                                            if(debug) printf("FunctionsAndDeclarations: FunctionDeclaration\n");
                                                                            if(strcmp($2->type, "Null") != 0) {
                                                                                $1->next = $2;
                                                                                $$ = $1;
                                                                            }
                                                                            else {$$ = $1;}
                                                                        }
                        | Declaration FunctionsAndDeclarations          {
                                                                            if(debug) printf("FunctionsAndDeclarations: Declaration\n");
                                                                            if(strcmp($2->type, "Null") != 0) {
                                                                                $1->next = $2;
                                                                                $$ = $1;
                                                                            }
                                                                            else {$$ = $1;}
                                                                        }
                        ;

FunctionDefinition: Typespec FunctionDeclarator FunctionBody {
                                                                if(debug) printf("Function Definition: Typespec FunctionDeclarator FunctionBody\n");
                                                                struct node* tmp = $2;
                                                                while(tmp->next) tmp = tmp->next;
                                                                $1->next = $2; tmp->next = $3;
                                                                //printNode($1); printNode($1->next); printNode($1->next->next); printNode($1->next->next->next); 
                                                                $$ = appendNode(createNode("FuncDefinition"), $1);
                                                             }
                  ;

FunctionBody:   LBRACE DeclarationsAndStatements RBRACE {
                                                            if(debug) printf("FunctionBody: {DeclarationsAndStatements}\n");
                                                            $$ = appendNode(createNode("FuncBody"), $2);
                                                            //printNode($$);
                                                        }
            |   LBRACE RBRACE                           {
                                                            if(debug) printf("FunctionBody: {}\n");
                                                            //printNode($$);
                                                        }
            ;

DeclarationsAndStatements: Statement DeclarationsAndStatementsAux   {
                                                                    if(debug) printf("DeclarationsAndStatements: Statements\n");
                                                                    struct node* tmp = $1;
                                                                    while(tmp->next) tmp = tmp->next;
                                                                    tmp->next = $2;
                                                                    $$ = $1;
                                                                 }
                         | Declaration DeclarationsAndStatementsAux {
                                                                    if(debug) printf("DeclarationsAndStatements: Declaration\n");
                                                                    struct node* dec = createNode("Declaration");
                                                                    dec = appendNode(dec, $1);
                                                                    dec->next = $2;
                                                                    $$ = dec;
                                                                 }
                         ;
DeclarationsAndStatementsAux: %empty                    {$$ = createNode("Null");}
                            | DeclarationsAndStatements {$$ = $1;}
                            ;

FunctionDeclaration:  Typespec FunctionDeclarator SEMI {
                                                            if(debug) printf("FunctionDeclaration: Typespec Function Declarator SEMI\n");
                                                            $1->next = $2;
                                                            $$ = appendNode(createNode("FuncDeclaration"), $1);
                                                            //printNode($$);
                                                       }
                   ;

FunctionDeclarator: IdToken LPAR ParameterList RPAR  {
                                                    if(debug) printf("FunctionDeclarator: ID (ParameterList)\n");
                                                    struct node* paramlist = createNode("ParamList");
                                                    paramlist = appendNode(paramlist, $3);
                                                    $1->next = paramlist;
                                                    $$ = $1;
                                                }
                  ;

ParameterList:  ParameterDeclaration ParameterListAux {
                                                        if(debug) printf("Parameter List: Parameter Declaration\n");
                                                        if(strcmp($2->type, "Null") != 0) {
                                                            $1->next = $2;
                                                            $$ = appendNode(createNode("ParamDeclaration"), $1);
                                                            //printNode($$); printNode($$->next);
                                                        }
                                                        else {
                                                            $$ = appendNode(createNode("ParamDeclaration"), $1);
                                                        }
                                                      }
             ;
ParameterListAux: COMMA ParameterList     {
                                            $$ = $2;
                                          }
                | %empty                  {
                                            $$ = createNode("Null");
                                          }
                ;
ParameterDeclaration: Typespec      {
                                        if(debug) printf("ParameterDeclaration: TypeSpec ParameterDeclarationAux\n");
                                        $$ = $1;
                                        //printNode($$);
                                    }
                    | Typespec IdToken   {
                                        if(debug) printf("ParameterDeclaration: TypeSpec ID ParameterDeclarationAux\n");
                                        $1->next = $2;
                                        $$ = $1;
                                    }
                    ;

Declaration: Typespec Declarator DeclarationAux SEMI {
                                                        if(debug) printf("Declaration: TypeSpec Declarator DeclarationAux SEMI\n");
                                                        if(strcmp($3->type, "Null") != 0) {
                                                            $1->next = $2;
                                                            $2->next = $3;
                                                        } 
                                                        else $1->next = $2;
                                                        $$ = $1;
                                                        //printNode($$);
                                                     }
           ;
DeclarationAux: COMMA Declarator DeclarationAux {
                                                    if(debug) printf("DeclarationAux: COMMA Declarator DeclarationAux\n");
                                                    if(strcmp($3->type, "Null") != 0) $$ = $2;
                                                    else $2->next = $3;
                                                    //printNode($$);
                                                }
              | %empty                          {
                                                    if(debug) printf("DeclarationAux: EMPTY\n");
                                                    $$ = createNode("Null");
                                                }
              ;

Declarator:  IdToken             {
                                if(debug) printf("Declarator: ID\n");
                                $$ = $1;
                            }
          |  IdToken ASSIGN Expr {
                                if(debug) printf("Declarator: ID ASSIGN Expr\n");
                                $1->next = $3;
                                $$ = $1;
                            }
          ;

Statement:   Expr SEMI                                  {
                                                            if(debug) printf("Statement: Expr SEMI\n");
                                                            $$ = $1;
                                                            //printNode($$);
                                                        }
         |   SEMI                                       {
                                                            if(debug) printf("Statement: SEMI\n");
                                                            //printNode($$);
                                                        }
         |   IF LPAR Expr RPAR Statement                {
                                                            if(debug) printf("Statement: IF LPAR Expr RPAR Statement\n");
                                                            //
                                                        }
         |   IF LPAR Expr RPAR Statement ELSE Statement {   
                                                            if(debug) printf("Statement: IF LPAR Expr RPAR Statement ELSE Statement\n");
                                                            //
                                                        }
         |   WHILE LPAR Expr RPAR Statement             {   
                                                            if(debug) printf("Statement: WHILE LPAR Expr RPAR Statement\n");
                                                            struct node* while_token = createNode("While");
                                                            while_token = appendNode(while_token, $3);
                                                            struct node* tmp = $3;
                                                            while(tmp->next) tmp = tmp->next;
                                                            tmp->next = $5;
                                                            $$ = while_token;
                                                        }
         |   RETURN Expr SEMI                           {
                                                            if(debug) printf("Statement: RETURN Expr SEMI\n");
                                                            $$ = appendNode(createNode("Return"), $2);
                                                        }
         |   RETURN SEMI                                {
                                                            if(debug) printf("Statement: RETURN SEMI\n");
                                                            $$ = createNode("Return");
                                                        }
         |   LBRACE StatementAux RBRACE                 {
                                                            if(debug) printf("Statement: LBRACE Statement RBRACE \n");
                                                            struct node* statlist = createNode("StatList");
                                                            $$ = appendNode(statlist, $2);
                                                        }
         ;
StatementAux: Statement StatementAux {
                                        if(debug) printf("StatementAux: Statement\n");
                                        struct node* tmp = $1;
                                        if(strcmp($2->type, "Null") != 0) {
                                            while(tmp->next) tmp = tmp->next;
                                            tmp->next = $2;
                                            $$ = $1;
                                        }
                                        else {$$ = $1;}
                                        //printNode($$);
                                     }
            | %empty                 {
                                        if(debug) printf("StatementAux: EMPTY\n");
                                        $$ = createNode("Null");
                                        //printNode($$);
                                     }
            ;

Assignment: IdToken ASSIGN Expr {
                            if(debug) printf("Assignment: ID ASSIGN Expr\n");
                            struct node* store = createNode("Store");
                            store = appendNode(store, $3);
                            $$ = appendNode(store, $1);
                            //printNode($$);
                           }
          ;

FunctionCall: IdToken LPAR ArgumentsInFunction RPAR {
                                                if(debug) printf("FunctionCall: ID LPAR ArgumentsInFunction RPAR\n");
                                                struct node* call = createNode("Call");
                                                $1->next = $3;
                                                call = appendNode(call, $1);
                                                $$ = call;
                                                //printNode($$);
                                               }
            ;

ArgumentsInFunction: Expr ExprAux  {
                                        if(debug) printf("ArgumentsInFunction: Expr\n");
                                        struct node* tmp = $1;
                                        if(strcmp($2->type, "Null") != 0) {
                                            while(tmp->next) tmp = tmp->next;
                                            tmp->next = $2;
                                            $$ = $1;
                                        }
                                        else {$$ = $1;}
                                        //printNode($$);
                                   }
ExprAux: %empty                     {
                                        $$ = createNode("Null");
                                    }
        | COMMA ArgumentsInFunction {
                                        if(debug) printf("ArgumentsInFunction: COMMA Expr\n");
                                        $$ = $2;
                                        //printNode($$);
                                    }
                   ;

Expr:  FunctionCall            {
                                if(debug) printf("Expr: FunctionCall\n");
                                $$ = $1;
                                //printNode($$);
                               }
    |  Assignment              {
                                if(debug) printf("Expr: Assignment\n");
                                $$ = $1;
                                //printNode($$);
                               }
    |  Expr MUL Expr           {
                                if(debug) printf("Expr: Expr OR Expr\n");
                                struct node* aux = createNode("Mul");
                                aux = appendNode(aux, $3);
                                $$ = appendNode(aux, $1);
                               }
    |  Expr DIV Expr           {
                                if(debug) printf("Expr: Expr OR Expr\n");
                                struct node* aux = createNode("Div");
                                aux = appendNode(aux, $3);
                                $$ = appendNode(aux, $1);
                               }
    |  Expr PLUS Expr          {
                                if(debug) printf("Expr: Expr OR Expr\n");
                                struct node* aux = createNode("Add");
                                aux = appendNode(aux, $3);
                                $$ = appendNode(aux, $1);
                               }
    |  Expr MINUS Expr         {
                                if(debug) printf("Expr: Expr OR Expr\n");
                                struct node* aux = createNode("Sub");
                                aux = appendNode(aux, $3);
                                $$ = appendNode(aux, $1);
                               }
    |  Expr MOD Expr           {
                                if(debug) printf("Expr: Expr OR Expr\n");
                                struct node* aux = createNode("Mod");
                                aux = appendNode(aux, $3);
                                $$ = appendNode(aux, $1);
                               }
    |  Expr AND Expr           {
                                if(debug) printf("Expr: Expr OR Expr\n");
                                struct node* aux = createNode("And");
                                aux = appendNode(aux, $3);
                                $$ = appendNode(aux, $1);
                               }
    |  Expr OR Expr            {
                                if(debug) printf("Expr: Expr OR Expr\n");
                                struct node* aux = createNode("Or");
                                aux = appendNode(aux, $3);
                                $$ = appendNode(aux, $1);
                               }
    |  Expr BITWISEAND Expr    {
                                if(debug) printf("Expr: Expr BITWISEAND Expr\n");
                                struct node* aux = createNode("BitWiseAnd");
                                aux = appendNode(aux, $3);
                                $$ = appendNode(aux, $1);
                               }
    |  Expr BITWISEOR Expr     {
                                if(debug) printf("Expr: Expr BITWISEOR Expr\n");
                                struct node* aux = createNode("BitWiseOr");
                                aux = appendNode(aux, $3);
                                $$ = appendNode(aux, $1);
                               }
    |  Expr BITWISEXOR Expr    {
                                if(debug) printf("Expr: Expr BITWISEXOR Expr\n");
                                struct node* aux = createNode("BitWiseXor");
                                aux = appendNode(aux, $3);
                                $$ = appendNode(aux, $1);
                               }
    |  Expr EQ Expr            {
                                if(debug) printf("Expr: Expr EQ Expr\n");
                                struct node* aux = createNode("Eq");
                                aux = appendNode(aux, $3);
                                $$ = appendNode(aux, $1);
                               }
    |  Expr NE Expr            {
                                if(debug) printf("Expr: Expr NE Expr\n");
                                struct node* aux = createNode("Ne");
                                aux = appendNode(aux, $3);
                                $$ = appendNode(aux, $1);
                               }
    |  Expr GE Expr            {
                                if(debug) printf("Expr: Expr GE Expr\n");
                                struct node* aux = createNode("Ge");
                                aux = appendNode(aux, $3);
                                $$ = appendNode(aux, $1);
                               }
    |  Expr GT Expr            {
                                if(debug) printf("Expr: Expr GT Expr\n");
                                struct node* aux = createNode("Gt");
                                aux = appendNode(aux, $3);
                                $$ = appendNode(aux, $1);
                               }
    |  Expr LE Expr            {
                                if(debug) printf("Expr: Expr LE Expr\n");
                                struct node* aux = createNode("Le");
                                aux = appendNode(aux, $3);
                                $$ = appendNode(aux, $1);
                               }
    |  Expr LT Expr            {
                                if(debug) printf("Expr: Expr LT Expr\n");
                                struct node* aux = createNode("Lt");
                                aux = appendNode(aux, $3);
                                $$ = appendNode(aux, $1);
                               }
    |  Expr COMMA Expr         {
                                if(debug) printf("Expr: Expr COMMA Expr\n");
                                struct node* aux = createNode("Comma");
                                aux = appendNode(aux, $3);
                                $$ = appendNode(aux, $1);
                               }
    |  NOT Expr                {
                                if(debug) printf("Expr: NOT Expr\n");
                                $$ = appendNode(createNode("Not"), $2);
                               }
    |  PLUS Expr %prec NOT     {
                                if(debug) printf("Expr: PLUS Expr NOT\n");
                                $$ = appendNode(createNode("Plus"), $2);
                               }
    |  MINUS Expr %prec NOT    {
                                if(debug) printf("Expr: MINUS Expr NOT\n");
                                $$ = appendNode(createNode("Minus"), $2);
                               }
    |  LPAR Expr RPAR          {
                                if(debug) printf("Expr: LPAR Expr RPAR\n");
                                $$ = $2;
                               }
    |  IdToken                 {
                                if(debug) printf("Expr: ID\n");
                                $$ = $1;
                               }
    |  INTLIT                  {
                                if(debug) printf("Expr: INTLIT\n");
                                strcpy(string, "");
                                sprintf(string, "IntLit(%s)", yyval.str_value);
                                $$ = createNode(strdup(string));
                               }
    |  CHRLIT                  {
                                if(debug) printf("Expr: CHRLIT\n");
                                sprintf(string, "ChrLit(%s)", yyval.str_value);
                                $$ = createNode(strdup(string));
                               }
    |  REALLIT                 {
                                if(debug) printf("Expr: REALLIT\n");
                                sprintf(string, "RealLit(%s)", yyval.str_value);
                                $$ = createNode(strdup(string));
                               }
    ;

Typespec: CHAR      {$$ = createNode("Char");}
        | INT       {$$ = createNode("Int");}
        | SHORT     {$$ = createNode("Short");}
        | DOUBLE    {$$ = createNode("Double");}
        | VOID      {$$ = createNode("Void");}
        ;
IdToken: ID {strcpy(string, ""); sprintf(string, "Id(%s)", yyval.id_value); $$ = createNode(strdup(string));}

%%