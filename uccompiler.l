%{
    // Alexandre Santos 2018277730
    // Manuel Fideles 2018282990
    #include "y.tab.h"
    #include <string.h>
    int column = 1; int comment_start_column = 1;
    int line = 1; int comment_start_line = 1;
    int error_mode = 1;         // 1 -> error mode ligado, 0 -> desligado

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


{RESERVED}             {if(!error_mode) printf("RESERVED(%s)\n", yytext); column += yyleng;}
{MINUS}                {if(!error_mode) printf("MINUS\n"); column += yyleng; return MINUS;}
{PLUS}                 {if(!error_mode) printf("PLUS\n"); column += yyleng; return PLUS;}
{MUL}                  {if(!error_mode) printf("MUL\n"); column += yyleng; return MUL;}
{CHAR}                 {if(!error_mode) printf("CHAR\n"); column += yyleng; return CHAR;}
{ELSE}                 {if(!error_mode) printf("ELSE\n"); column += yyleng; return ELSE;}
{WHILE}                {if(!error_mode) printf("WHILE\n"); column += yyleng; return WHILE;}
{IF}                   {if(!error_mode) printf("IF\n"); column += yyleng; return IF;}
{INT}                  {if(!error_mode) printf("INT\n"); column += yyleng; return INT;}
{SHORT}                {if(!error_mode) printf("SHORT\n"); column += yyleng; return SHORT;}
{DOUBLE}               {if(!error_mode) printf("DOUBLE\n"); column += yyleng; return DOUBLE;}
{RETURN}               {if(!error_mode) printf("RETURN\n"); column += yyleng; return RETURN;}
{VOID}                 {if(!error_mode) printf("VOID\n"); column += yyleng; return VOID;}
{BITWISEAND}           {if(!error_mode) printf("BITWISEAND\n"); column += yyleng; return BITWISEAND;}
{BITWISEOR}            {if(!error_mode) printf("BITWISEOR\n"); column += yyleng; return BITWISEOR;}
{BITWISEXOR}           {if(!error_mode) printf("BITWISEXOR\n"); column += yyleng; return BITWISEXOR;}
{AND}                  {if(!error_mode) printf("AND\n"); column += yyleng; return AND;}
{ASSIGN}               {if(!error_mode) printf("ASSIGN\n"); column += yyleng; return ASSIGN;}
{COMMA}                {if(!error_mode) printf("COMMA\n"); column += yyleng; return COMMA;}
{DIV}                  {if(!error_mode) printf("DIV\n"); column += yyleng; return DIV;}
{EQ}                   {if(!error_mode) printf("EQ\n"); column += yyleng; return EQ;}
{GE}                   {if(!error_mode) printf("GE\n"); column += yyleng; return GE;}
{GT}                   {if(!error_mode) printf("GT\n"); column += yyleng; return GT;}
{LBRACE}               {if(!error_mode) printf("LBRACE\n"); column += yyleng; return LBRACE;}
{LE}                   {if(!error_mode) printf("LE\n"); column += yyleng; return LE;}
{LPAR}                 {if(!error_mode) printf("LPAR\n"); column += yyleng; return LPAR;}
{LT}                   {if(!error_mode) printf("LT\n"); column += yyleng; return LT;}
{MOD}                  {if(!error_mode) printf("MOD\n"); column += yyleng; return MOD;}
{NE}                   {if(!error_mode) printf("NE\n"); column += yyleng; return NE;}
{NOT}                  {if(!error_mode) printf("NOT\n"); column += yyleng; return NOT;}
{OR}                   {if(!error_mode) printf("OR\n"); column += yyleng; return OR;}
{RBRACE}               {if(!error_mode) printf("RBRACE\n"); column += yyleng; return RBRACE;}
{RPAR}                 {if(!error_mode) printf("RPAR\n"); column += yyleng; return RPAR;}
{SEMI}                 {if(!error_mode) printf("SEMI\n"); column += yyleng; return SEMI;}
{ID}                   {if(!error_mode) printf("ID(%s)\n", yytext); column += yyleng; yylval.str_value = strdup(yytext); return ID;}
{INTLIT}               {if(!error_mode) printf("INTLIT(%s)\n", yytext); column += yyleng; yylval.str_value = strdup(yytext); return INTLIT;}
{REALLIT}              {if(!error_mode) printf("REALLIT(%s)\n", yytext); column += yyleng; yylval.str_value = strdup(yytext); return REALLIT;}

    /* TRATAMENTO DE CHRLIT */
{CHRLIT}               {if(!error_mode) printf("CHRLIT(%s)\n", yytext); column += yyleng; yylval.str_value = strdup(yytext); return CHRLIT;}
\'([^\n\r\'\\]|\\.)*\' {printf("Line %d, col %d: invalid char constant (%s)\n", line, column, yytext); column += yyleng;}
\'[^\n\r\']*\'?        {printf("Line %d, col %d: unterminated char constant\n", line, column);}

" "|"\t"|"\f"          {column += yyleng;}
"\n"|"\r"|"\r\n"       {line++; column = 1;}
.                      {printf("Line %d, col %d: illegal character (%c)\n", line, column, *yytext); column += yyleng;}

%%

int main(int argc, char *argv[]) {
    if (argc > 1) {
        if(strcmp(argv[1],"-l") == 0) {
            error_mode = 0;
        }
    }
    yyparse();
    return 0;
}

int yywrap() {
    return 1;
}