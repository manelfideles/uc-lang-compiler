%{
        #include <stdlib.h>
        #include <stdio.h>
        #include <string.h>
        #include "functions.h"
        #include "y.tab.h"
        #define MAXSTRINGLEN 300

        int yylex();
        int yyerror(const char *s);

        NodePtr* root = NULL;
        NodePtr* current = NULL;

        // FLags de erros lexicais sintáticos e imprimir árvore
        int e1, e2, t;

        // para imprimir as produções
        int debug = 0;

        //string de intlit reallit chrlit id
        char string[MAXSTRINGLEN];

%}

%union {
    char* str_value;
    struct node *node;
}

%define parse.error verbose

%token<str_value> MINUS PLUS MUL DIV MOD BITWISEAND BITWISEOR BITWISEXOR AND NOT OR EQ NE LE GE LT GT CHAR INT SHORT DOUBLE VOID IF ELSE WHILE RETURN ASSIGN COMMA LBRACE RBRACE LPAR RPAR SEMI
%token<str_value> ID CHRLIT INTLIT REALLIT
%type<node> Program FunctionsAndDeclarations FunctionDefinition FunctionBody DeclarationsAndStatements FunctionDeclaration FunctionDeclarator ParameterList ParameterDeclaration ParameterDeclarationAux Declaration DeclarationAux Declarator Statement StatementAux Assignment FunctionCall ArgumentsInFunction Expr Typespec

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
                                    root = createNode("Program");
                                    $$ = root = appendNode(root, $1);
                                    printNode(root);
                                  }
       ;
FunctionsAndDeclarations: %empty {
                                    if(debug) printf("FunctionsAndDeclarations: EMPTY\n");
                                    $$ = createNode("Null");
                                 }
                        | FunctionDefinition FunctionsAndDeclarations   {
                                                                            if($2->type == "Null") $$ = $1;
                                                                            else $$ = appendNode($1, $2);
                                                                            if(debug) printf("FunctionsAndDeclarations: FunctionDefinition\n");
                                                                            //printNode($$);
                                                                        }
                        | FunctionDeclaration FunctionsAndDeclarations  {
                                                                            if(debug) printf("FunctionsAndDeclarations: FunctionDeclaration\n");
                                                                            if($2->type == "Null") $$ = appendNode($1, $2);
                                                                            //printNode($$);
                                                                        }
                        | Declaration FunctionsAndDeclarations          {
                                                                            if($2->type == "Null") $$ = $1;
                                                                            else $$ = appendNode($1, $2);
                                                                            if(debug) printf("FunctionsAndDeclarations: Declaration\n");
                                                                            //printNode($$);
                                                                        }
                        ;

FunctionDefinition: Typespec FunctionDeclarator FunctionBody {
                                                                $$ = appendNode($1, appendNode($2, $3));
                                                                if(debug) printf("Function Definition: Typespec FunctionDeclarator FunctionBody\n");
                                                                //printNode($$);
                                                                //printf("%s %s %s\n", $1->type, $2->type, $3->type);
                                                                //printf("cona\n");
                                                             }
                  ;

FunctionBody:   LBRACE DeclarationsAndStatements RBRACE {
                                                            $$ = $2;
                                                            if(debug) printf("FunctionBody: {DeclarationsAndStatements}\n");
                                                            //printNode($$);
                                                        }
            |   LBRACE RBRACE                           {
                                                            if(debug) printf("FunctionBody: {}\n");
                                                            //printNode($$);
                                                        }
            ;

DeclarationsAndStatements: Statement DeclarationsAndStatements   {
                                                                    if(debug) printf("DeclarationsAndStatements: Statements\n");
                                                                    //printf("%s\n", $1->type);
                                                                    $$ = appendNode($1, $2);
                                                                    //printNode($$);
                                                                 }
                         | Declaration DeclarationsAndStatements {
                                                                    if(debug) printf("DeclarationsAndStatements: Declaration\n");
                                                                    //printNode($$);
                                                                    //printNode($1); printNode($2);
                                                                    $$ = appendNode($1, $2);
                                                                 }
                         | Statement                             {
                                                                    if(debug) printf("DeclarationsAndStatements: Statement\n");
                                                                    printf("%s\n", $1->type);
                                                                    $$ = $1;
                                                                    //printNode($1);
                                                                 }
                         | Declaration                           {
                                                                    if(debug) printf("DeclarationsAndStatements: Declaration\n");
                                                                    $$ = $1;
                                                                    //printNode($1);
                                                                 }
                         ;

FunctionDeclaration:  Typespec FunctionDeclarator SEMI {
                                                            if(debug) printf("FunctionDeclaration: Typespec Function Declarator SEMI\n");

                                                       }
                   ;

FunctionDeclarator: ID LPAR ParameterList RPAR  {
                                                    if(debug) printf("FunctionDeclarator: ID (ParameterList)\n");
                                                    $$ = appendNode(createNode("Id"), appendNode(createNode("Call"), $3));
                                                    printNode($$);
                                                }
                  ;

ParameterList:  ParameterDeclaration            {
                                                    if(debug) printf("Parameter List: Parameter Declaration\n");
                                                    $$ = $1;
                                                    printNode($$);
                                                }
             |  COMMA ParameterList             {
                                                    if(debug) printf("Parameter List: COMMA ParameterList\n");
                                                    $$ = appendNode(createNode("Comma"), $2);
                                                    printNode($$);
                                                }
             ;

ParameterDeclaration: Typespec ParameterDeclarationAux      {
                                                                if(debug) printf("ParameterDeclaration: TypeSpec ParameterDeclarationAux\n");
                                                                $$ = appendNode($1, $2);
                                                                printNode($$);
                                                            }
                    | Typespec ID ParameterDeclarationAux   {
                                                                if(debug) printf("ParameterDeclaration: TypeSpec ID ParameterDeclarationAux\n");
                                                                $$ = appendNode($1, appendNode(createNode("Id"), $3));
                                                                printNode($$);
                                                            }
                    ;
ParameterDeclarationAux: COMMA ParameterDeclaration {
                                                        if(debug) printf("ParameterDeclarationAux: COMMA ParameterDeclaration\n");
                                                        $$ = appendNode(createNode("Comma"), $2);
                                                        printNode($$);
                                                    }
                       | %empty                     {
                                                        if(debug) printf("ParameterDeclarationAux: EMPTY\n");
                                                        $$ = createNode("Null");
                                                    }
                       ;

Declaration: Typespec Declarator DeclarationAux SEMI {
                                                        if(debug) printf("Declaration: TypeSpec Declarator DeclarationAux SEMI\n");
                                                        $$ = appendNode($1, appendNode($2, appendNode($3, createNode("Semi"))));
                                                        printNode($$);
                                                     }
           ;
DeclarationAux: COMMA Declarator DeclarationAux {
                                                    if(debug) printf("DeclarationAux: COMMA Declarator DeclarationAux\n");
                                                    $$ = appendNode(createNode("Comma"), appendNode($2, $3));
                                                    printNode($$);
                                                }
              | %empty                          {
                                                    if(debug) printf("DeclarationAux: EMPTY\n");
                                                    $$ = createNode("Null");
                                                }
              ;

Declarator:  ID             {
                                if(debug) printf("Declarator: ID\n");
                                $$ = createNode("Id");
                            }
          |  ID ASSIGN Expr {
                                if(debug) printf("Declarator: ID ASSIGN Expr\n");
                                struct node* aux = createNode("Store");
                                aux = appendNode(aux, $3);
                                $$ = appendNode(aux, createNode("Id"));
                            }
          ;

Statement:   Expr SEMI                                  {
                                                            if(debug) printf("Statement: Expr SEMI\n");
                                                            printNode($1);
                                                            $$ = appendNode($1, createNode("Semi"));
                                                        }
         |   SEMI                                       {
                                                            if(debug) printf("Statement: SEMI\n");
                                                            $$ = createNode("Semi");
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
                                                            //
                                                        }
         |   RETURN Expr SEMI                           {
                                                            if(debug) printf("Statement: RETURN Expr SEMI\n");
                                                            $$ = appendNode(createNode("Return"), appendNode($2, createNode("Semi")));
                                                        }
         |   RETURN SEMI                                {
                                                            if(debug) printf("Statement: RETURN SEMI\n");
                                                            $$ = appendNode(createNode("Return"), createNode("Semi"));
                                                        }
         |   LBRACE StatementAux RBRACE                 {
                                                            if(debug) printf("Statement: LBRACE Statement RBRACE \n");
                                                            $$ = $2;
                                                        }
         ;
StatementAux: Statement StatementAux {
                                        if(debug) printf("StatementAux: Statement\n");
                                        $$ = appendNode($1, $2);
                                     }
            | %empty                 {
                                        if(debug) printf("StatementAux: EMPTY\n");
                                        $$ = createNode("Null");
                                     }
            ;

Assignment: ID ASSIGN Expr {
                            if(debug) printf("Assignment: ID ASSIGN Expr\n");
                            $$ = appendNode(appendNode(createNode("Store"), $3), createNode("Id"));
                            printNode($$);
                           }
          ;

FunctionCall: ID LPAR ArgumentsInFunction RPAR {
                                                if(debug) printf("FunctionCall: ID LPAR ArgumentsInFunction RPAR\n");
                                                $$ = appendNode(createNode("Id"), appendNode(createNode("Call"), $3));
                                               }
            ;

ArgumentsInFunction: %empty     {
                                    if(debug) printf("ArgumentsInFunction: EMPTY\n");
                                    $$ = createNode("Null");
                                }
                   | Expr       {
                                    if(debug) printf("ArgumentsInFunction: Expr\n");
                                    $$ = $1;
                                }
                   | COMMA Expr {
                                    if(debug) printf("ArgumentsInFunction: COMMA Expr\n");
                                    $$ = appendNode(createNode("Comma"), $2);
                                }
                   ;

Expr:  FunctionCall            {
                                if(debug) printf("Expr: FunctionCall\n");
                                $$ = $1;
                               }
    |  Assignment              {
                                if(debug) printf("Expr: Assignment\n");
                                $$ = $1;
                                printNode($$);
                               }
    |  Expr MUL Expr           {
                                if(debug) printf("Expr: Expr MUL Expr\n");
                                struct node* aux = createNode("Mul");
                                aux = appendNode(aux, $3);
                                $$ = appendNode(aux, $1);
                               }
    |  Expr DIV Expr           {
                                if(debug) printf("Expr: Expr DIV Expr\n");
                                struct node* aux = createNode("Div");
                                aux = appendNode(aux, $3);
                                $$ = appendNode(aux, $1);
                               }
    |  Expr PLUS Expr          {
                                if(debug) printf("Expr: Expr PLUS Expr\n");
                                struct node* aux = createNode("Plus");
                                aux = appendNode(aux, $3);
                                $$ = appendNode(aux, $1);
                               }
    |  Expr MINUS Expr         {
                                if(debug) printf("Expr: Expr MINUS Expr\n");
                                struct node* aux = createNode("Minus");
                                aux = appendNode(aux, $3);
                                $$ = appendNode(aux, $1);
                               }
    |  Expr MOD Expr           {
                                if(debug) printf("Expr: Expr MOD Expr\n");
                                struct node* aux = createNode("Mod");
                                aux = appendNode(aux, $3);
                                $$ = appendNode(aux, $1);
                               }
    |  Expr AND Expr           {
                                if(debug) printf("Expr: Expr AND Expr\n");
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
                                $$ = appendNode(createNode("Call"), $2);
                               }
    |  ID                      {
                                if(debug) printf("Expr: ID\n");
                                strcpy(string, "");
                                sprintf(string, "IntLit(%s)", yyval.str_value);
                                $$ = createNode(strdup(string));
                               }
    |  INTLIT                  {
                                if(debug) printf("Expr: INTLIT\n");
                                strcpy(string, "");
                                sprintf(string, "IntLit(%s)", yyval.str_value);
                                $$ = createNode(strdup(string));
                               }
    |  CHRLIT                  {
                                if(debug) printf("Expr: CHRLIT\n");
                                strcpy(string, "");
                                sprintf(string, "ChrLit(%s)", yyval.str_value);
                                $$ = createNode(strdup(string));
                                printNode($$);
                               }
    |  REALLIT                 {
                                if(debug) printf("Expr: REALLIT\n");
                                strcpy(string, "");
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

%%

int main(int argc, char *argv[]) {
    if (argc > 1) {
        if(strcmp(argv[1], "-l") == 0) {
            e1 = 0;
        }
        if(strcmp(argv[1], "-t") == 0) {
            t = 1;
            //printTree(root);
        }
    }
    yyparse();
    return 0;
}