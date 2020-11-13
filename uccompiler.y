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
%type<node> Program FunctionsAndDeclarations FunctionDefinition FunctionBody DeclarationsAndStatements FunctionDeclaration FunctionDeclarator ParameterList ParameterDeclaration Declaration DeclarationAux Declarator Statement StatementList FunctionCall ArgList FuncCallArgList Expr Typespec IdToken DeclarationsAndStatementsAux StatementError

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
                                                                    if(strcmp($2->type, "Null") != 0) {
                                                                        struct node* tmp = $1;
                                                                        while(tmp->next) tmp = tmp->next;
                                                                        tmp->next = $2;
                                                                        $$ = $1;
                                                                    }
                                                                    else {$$ = $1;}
                                                                    
                                                                 }
                         | Declaration DeclarationsAndStatementsAux {
                                                                    if(debug) printf("DeclarationsAndStatements: Declaration\n");
                                                                    struct node* dec = createNode("Declaration");
                                                                    dec = appendNode(dec, $1);
                                                                    if(strcmp($2->type, "Null") != 0) {
                                                                        dec->next = $2;
                                                                        $$ = dec;
                                                                    }
                                                                    else {$$ = dec;}
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

ParameterList: ParameterDeclaration                   {
                                                        if(debug) printf("Parameter List: Parameter Declaration\n");
                                                        $$ = appendNode(createNode("ParamDeclaration"), $1);
                                                      }
             | ParameterList COMMA ParameterDeclaration {
                                                            struct node* tmp = $1;
                                                            while(tmp->next != NULL) tmp = tmp->next;
                                                            tmp->next = appendNode(createNode("ParamDeclaration"), $3);
                                                            $$ = $1;
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
                                                        else {$1->next = $2;}
                                                        $$ = $1;
                                                        //printNode($$);
                                                     }
            | error SEMI                             {}
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

Statement:   LBRACE StatementList RBRACE                {
                                                            if(debug) printf("Statement: LBRACE Statement RBRACE \n");
                                                            // criar statlist
                                                            if($2) {
                                                                if($2->next == NULL) $$ = $2;
                                                                else {
                                                                    struct node* statlist = createNode("StatList");
                                                                    statlist = appendNode(statlist, $2);
                                                                    $$ = statlist;
                                                                }
                                                            }
                                                        }
         |   Expr SEMI                                  {$$ = $1;}
         |   SEMI                                       {$$ = NULL;}
         |   IF LPAR Expr RPAR StatementError %prec ELSE     {
                                                            struct node* if_aux = createNode("If");
                                                            struct node* tmp = $3;
                                                            while(tmp->next != NULL) {
                                                                tmp = tmp->next;
                                                            }
                                                            
                                                            if(strcmp($5->type, "Null") != 0) tmp->next = $5;

                                                            if_aux = appendNode(if_aux, $3);
                                                            $$ = if_aux;
                                                        }
         |   IF LPAR Expr RPAR StatementError ELSE StatementError {   
                                                            if(debug) printf("Statement: IF LPAR Expr RPAR Statement ELSE Statement\n");
                                                            struct node* if_aux = createNode("If");
                                                            struct node* tmp = $3;
                                                            while(tmp->next != NULL) tmp = tmp->next;


                                                            if($5 && !$7) {
                                                                struct node* tmp1 = $5;
                                                                int k = 0;
                                                                if(tmp1->next) k++;
                                                                if(k == 0) {tmp->next = $5; $5->next = createNode("Null");}
                                                                else {
                                                                    struct node* statlist = createNode("StatList");
                                                                    statlist->next = createNode("Null");
                                                                    tmp->next = appendNode(statlist, $5);
                                                                }
                                                            }

                                                            else if(!$5 && $7) {
                                                                struct node* aux = $7;
                                                                int i = 0;
                                                                if(aux->next != NULL) i++;
                                                                if(i == 0){
                                                                    struct node* null = createNode("Null");
                                                                    tmp->next = null;
                                                                    null->next = $7;
                                                                }
                                                                else {
                                                                    struct node* null = createNode("Null");
                                                                    tmp->next = null;
                                                                    struct node* statlist2 = createNode("StatList");
                                                                    null->next = appendNode(statlist2, $7);
                                                                }
                                                            }

                                                            else if($5 && $7) {
                                                                //printf("%s --- %s\n", $5->type, $7->type);
                                                                struct node* tmp2 = $5;
                                                                struct node* statlist = NULL;
                                                                struct node* tmp3 = $7;
                                                                struct node* statlist2 = NULL;
                                                                int i = 0; 
                                                                if(tmp2->next != NULL) {i++;}
                                                                if(i == 0){tmp->next = $5;}
                                                                else {
                                                                    statlist = appendNode(createNode("StatList"), $5);
                                                                    tmp->next = statlist;
                                                                }

                                                                int j = 0;
                                                                if(tmp3->next != NULL) j++;
                                                                if(j == 0) {
                                                                    if(statlist) statlist->next = $7;
                                                                    else {$5->next = $7;}
                                                                }
                                                                else {
                                                                    statlist2 = appendNode(createNode("StatList"), $7);
                                                                    if(statlist) statlist->next = statlist2;
                                                                    else {$5->next = statlist2;}
                                                                }
                                                            }

                                                            else {
                                                                struct node* A = createNode("Null");
                                                                struct node* B = createNode("Null");
                                                                tmp->next = A;
                                                                A->next = B;
                                                            }

                                                            if_aux = appendNode(if_aux, $3);
                                                            $$ = if_aux;
                                                        }
         |   WHILE LPAR Expr RPAR StatementError        {   
                                                            struct node* while_token = createNode("While");
                                                            struct node* tmp = $3;

                                                            while(tmp->next != NULL) tmp = tmp->next;
                                                            tmp->next = $5;

                                                            while_token = appendNode(while_token, $3);
                                                            $$ = while_token;
                                                        }
         |   RETURN Expr SEMI                           {$$ = appendNode(createNode("Return"), $2);}
         |   RETURN SEMI                                {$$ = createNode("Return");}

         |   LBRACE error RBRACE                        {}
         |   LBRACE RBRACE                              {}
         ;
StatementList: StatementError StatementList  {
                                                if(!$1) $$ = $2;
                                                else if($1 && $2) {
                                                    struct node* tmp = $1;
                                                    while(tmp->next) tmp = tmp->next;
                                                    tmp->next = $2;
                                                    $$ = $1;
                                                }
                                                else if($1 && !$2) $$ = $1;
                                                else $$ = NULL;

                                             }
             | StatementError                {$$ = $1;}
            ;
StatementError: Statement   {$$ = $1;}
              | error SEMI  {$$ = NULL;}

ArgList: Expr                               {$$ = $1;}
       | ArgList COMMA Expr                 {
                                                if(debug) printf("Expr: Expr COMMA Expr\n");
                                                struct node* aux = createNode("Comma");
                                                aux = appendNode(aux, $3);
                                                $$ = appendNode(aux, $1);
                                            }

FuncCallArgList: Expr                       {$$ = $1;}
               | FuncCallArgList COMMA Expr {
                                                // COMO FAZER ?
                                            }

FunctionCall: IdToken LPAR FuncCallArgList RPAR {
                                                    if(debug) printf("FunctionCall: ID LPAR ArgumentsInFunction RPAR\n");
                                                    struct node* call = createNode("Call");
                                                    $1->next = $3;
                                                    call = appendNode(call, $1);
                                                    $$ = call;
                                                    //printNode($$);
                                                }
            | IdToken LPAR RPAR                 {}
            | IdToken LPAR error RPAR           {}


Expr:  Expr ASSIGN Expr        {
                                    if(debug) printf("Assignment: ID ASSIGN Expr\n");
                                    struct node* store = createNode("Store");
                                    store = appendNode(store, $3);
                                    $$ = appendNode(store, $1);
                                    //printNode($$); printNode($$->children); printNode($$->children->next);
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
    |  FunctionCall            {$$ = $1;}
    |  LPAR ArgList RPAR       {
                                if(debug) printf("Expr: LPAR Expr RPAR\n");
                                $$ = $2;
                               }
    |  LPAR error RPAR         {;}
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
IdToken:  ID        {strcpy(string, ""); sprintf(string, "Id(%s)", yyval.id_value); $$ = createNode(strdup(string));}

%%