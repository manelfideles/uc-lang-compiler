%{
    // Alexandre Santos 2018277730
    // Manuel Fideles 2018282990
    #include "y.tab.h"
    #include <string.h>
    #include "functions.h"
    #include "semantics.h"
    int column = 1; int comment_start_column = 1;
    int line = 1; int comment_start_line = 1;
    int e1 = 1;         // 1 -> error mode ligado, 0 -> desligado
    int e2 = 0;
    int t = 0;
    int s = 0;

    NodePtr* program = NULL;
    symtab* SYMTAB= NULL;

%}

CHAR        char
ELSE        else
WHILE       while
IF          if
INT         int
SHORT       short
DOUBLE      double
RETURN      return
VOID        void
BITWISEAND  "&"
BITWISEOR   "|"
BITWISEXOR  "^"
AND         "&&"
ASSIGN      "="
MUL         "*"
COMMA       ","
DIV         "/"
EQ          "=="
GE          ">="
GT          ">"
LBRACE      "{"
LE          "<="
LPAR        "("
LT          "<"
MOD         "%"
NE          "!="
MINUS       \-
PLUS        \+
NOT         "!"
OR          "||"
RBRACE      "}"
RPAR        ")"
SEMI        ";"
ID          ([_a-zA-Z])([_a-zA-Z0-9])*
INTLIT      [0-9]+
REALLIT     ([0-9]+"."[0-9]*([eE][\+\-]?[0-9]+)?)|("."[0-9]+([eE][\+\-]?[0-9]+)?)|([0-9]+[eE][\+\-]?[0-9]+)
CHRLIT      \'([^\'\n\\]|\\n|\\t|\\\\|\\\'|\\\"|\\([0-7]{1,3}))\'
RESERVED    auto|break|const|continue|do|enum|extern|float|for|goto|register|long|signed|unsigned|sizeof|static|struct|switch|case|default|typedef|union|volatile|_Bool|_Imaginary|restrict|inline|_Complex|"["|"]"|"++"|"--"

%X COMMENT_1 COMMENT_2

%%

    /* TRATAMENTO DE COMENTÁRIOS */

"/*"                        {comment_start_column = column; comment_start_line = line; column += yyleng; BEGIN COMMENT_1;}
<COMMENT_1>.                {column += yyleng;}
<COMMENT_1>\r|\n|(\r\n)     {line++; column = 1;} 
<COMMENT_1><<EOF>>          {
    printf("Line %d, col %d: unterminated comment\n", comment_start_line, comment_start_column);
    column += yyleng;
    BEGIN 0;
}
<COMMENT_1>"*/"             {column += yyleng; BEGIN 0;}

"//"                        {column += yyleng; BEGIN COMMENT_2;}
<COMMENT_2>.                {column += yyleng;}
<COMMENT_2>\r|\n|(\r\n)     {line++; column = 1; BEGIN 0;}


{RESERVED}             {if(!e1) printf("RESERVED(%s)\n", yytext); yylval.lin=line; yylval.col=column; column += yyleng; return RESERVED;}
{MINUS}                {if(!e1) printf("MINUS\n"); yylval.lin=line; yylval.col=column; column += yyleng; return MINUS;}
{PLUS}                 {if(!e1) printf("PLUS\n"); yylval.lin=line; yylval.col=column; column += yyleng; return PLUS;}
{MUL}                  {if(!e1) printf("MUL\n"); yylval.lin=line; yylval.col=column; column += yyleng; return MUL;}
{CHAR}                 {if(!e1) printf("CHAR\n"); yylval.lin=line; yylval.col=column; column += yyleng; return CHAR;}
{ELSE}                 {if(!e1) printf("ELSE\n"); yylval.lin=line; yylval.col=column; column += yyleng; return ELSE;}
{WHILE}                {if(!e1) printf("WHILE\n"); yylval.lin=line; yylval.col=column; column += yyleng; return WHILE;}
{IF}                   {if(!e1) printf("IF\n"); yylval.lin=line; yylval.col=column; column += yyleng; return IF;}
{INT}                  {if(!e1) printf("INT\n"); yylval.lin=line; yylval.col=column; column += yyleng; return INT;}
{SHORT}                {if(!e1) printf("SHORT\n"); yylval.lin=line; yylval.col=column; column += yyleng; return SHORT;}
{DOUBLE}               {if(!e1) printf("DOUBLE\n"); yylval.lin=line; yylval.col=column; column += yyleng; return DOUBLE;}
{RETURN}               {if(!e1) printf("RETURN\n"); yylval.lin=line; yylval.col=column; column += yyleng; return RETURN;}
{VOID}                 {if(!e1) printf("VOID\n"); yylval.lin=line; yylval.col=column; column += yyleng; return VOID;}
{BITWISEAND}           {if(!e1) printf("BITWISEAND\n"); yylval.lin=line; yylval.col=column; column += yyleng; return BITWISEAND;}
{BITWISEOR}            {if(!e1) printf("BITWISEOR\n"); yylval.lin=line; yylval.col=column; column += yyleng; return BITWISEOR;}
{BITWISEXOR}           {if(!e1) printf("BITWISEXOR\n"); yylval.lin=line; yylval.col=column; column += yyleng; return BITWISEXOR;}
{AND}                  {if(!e1) printf("AND\n"); yylval.lin=line; yylval.col=column; column += yyleng; return AND;}
{ASSIGN}               {if(!e1) printf("ASSIGN\n"); yylval.lin=line; yylval.col=column; column += yyleng; return ASSIGN;}
{COMMA}                {if(!e1) printf("COMMA\n"); yylval.lin=line; yylval.col=column; column += yyleng; return COMMA;}
{DIV}                  {if(!e1) printf("DIV\n"); yylval.lin=line; yylval.col=column; column += yyleng; return DIV;}
{EQ}                   {if(!e1) printf("EQ\n"); yylval.lin=line; yylval.col=column; column += yyleng; return EQ;}
{GE}                   {if(!e1) printf("GE\n"); yylval.lin=line; yylval.col=column; column += yyleng; return GE;}
{GT}                   {if(!e1) printf("GT\n"); yylval.lin=line; yylval.col=column; column += yyleng; return GT;}
{LBRACE}               {if(!e1) printf("LBRACE\n"); yylval.lin=line; yylval.col=column; column += yyleng; return LBRACE;}
{LE}                   {if(!e1) printf("LE\n"); yylval.lin=line; yylval.col=column; column += yyleng; return LE;}
{LPAR}                 {if(!e1) printf("LPAR\n"); yylval.lin=line; yylval.col=column; column += yyleng; return LPAR;}
{LT}                   {if(!e1) printf("LT\n"); yylval.lin=line; yylval.col=column; column += yyleng; return LT;}
{MOD}                  {if(!e1) printf("MOD\n"); yylval.lin=line; yylval.col=column; column += yyleng; return MOD;}
{NE}                   {if(!e1) printf("NE\n"); yylval.lin=line; yylval.col=column; column += yyleng; return NE;}
{NOT}                  {if(!e1) printf("NOT\n"); yylval.lin=line; yylval.col=column; column += yyleng; return NOT;}
{OR}                   {if(!e1) printf("OR\n"); yylval.lin=line; yylval.col=column; column += yyleng; return OR;}
{RBRACE}               {if(!e1) printf("RBRACE\n"); yylval.lin=line; yylval.col=column; column += yyleng; return RBRACE;}
{RPAR}                 {if(!e1) printf("RPAR\n"); yylval.lin=line; yylval.col=column; column += yyleng; return RPAR;}
{SEMI}                 {if(!e1) printf("SEMI\n"); yylval.lin=line; yylval.col=column; column += yyleng; return SEMI;}
{ID}                   {if(!e1) printf("ID(%s)\n", yytext); yylval.lin=line; yylval.col=column; column += yyleng; yylval.id_value = strdup(yytext); return ID;}
{INTLIT}               {if(!e1) printf("INTLIT(%s)\n", yytext); yylval.lin=line; yylval.col=column; column += yyleng; yylval.str_value = strdup(yytext); return INTLIT;}
{REALLIT}              {if(!e1) printf("REALLIT(%s)\n", yytext); yylval.lin=line; yylval.col=column; column += yyleng; yylval.str_value = strdup(yytext); return REALLIT;}

    /* TRATAMENTO DE CHRLIT */
{CHRLIT}               {if(!e1) printf("CHRLIT(%s)\n", yytext); yylval.lin=line; yylval.col=column; column += yyleng; yylval.str_value = strdup(yytext); return CHRLIT;}
\'([^\n\r\'\\]|\\.)*\' {printf("Line %d, col %d: invalid char constant (%s)\n", line, column, yytext); column += yyleng;}
\'[^\n\r\']*\'?        {printf("Line %d, col %d: unterminated char constant\n", line, column);}

" "|"\t"|"\f"          {yylval.lin=line; yylval.col=column; column += yyleng;}
"\n"|"\r"|"\r\n"       {yylval.lin=line; yylval.col=column; line++; column = 1;}
.                      {printf("Line %d, col %d: illegal character (%c)\n", line, column, *yytext); column += yyleng;}

%%

void yyerror(const char *s) {
  if(e2) printf("Line %d, col %d: %s: %s\n", line,(int)(column - strlen(yytext)), s, yytext);
}

int yywrap() {
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        // -l
        if(strcmp(argv[1], "-l") == 0) {
            e1 = 0;
            e2 = 0;
            while(yylex());
        }
        // -e1
        else if(strcmp(argv[1], "-e1") == 0) {
            e1 = 1;
            e2 = 0;
            while(yylex());
        }
        // -t
        else if(strcmp(argv[1], "-t") == 0) {
            t = 0;
            yyparse();
            if(!t) {printTree(program); /*free tree*/}
        }
        // -e2
        else if(strcmp(argv[1], "-e2") == 0) {
            e1 = 1;
            e2 = 1;
            yyparse();
            while(yylex());
        }
        else if(strcmp(argv[1],"-s")==0){
            yyparse();
            if(program){
                SYMTAB=progSymTab(program);
                program=anotAST(program,SYMTAB,NULL);
                printTable(SYMTAB);
                printTree(program);
            }
            
        }
        else {yyparse();}
    }
    else {
        e1 = 1;
        e2 = 1;
        yyparse();
        while(yylex());
    }
    
    return 0;
}