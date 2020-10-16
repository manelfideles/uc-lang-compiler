%{
    // Alexandre Santos 2018277730
    // Manuel Fideles 2018282990
    #include <ctype.h>
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
{MINUS}                {if(!error_mode) printf("MINUS\n"); column += yyleng;}
{PLUS}                 {if(!error_mode) printf("PLUS\n"); column += yyleng;}
{MUL}                  {if(!error_mode) printf("MUL\n"); column += yyleng;}
{CHAR}                 {if(!error_mode) printf("CHAR\n"); column += yyleng;}
{ELSE}                 {if(!error_mode) printf("ELSE\n"); column += yyleng;}
{WHILE}                {if(!error_mode) printf("WHILE\n"); column += yyleng;}
{IF}                   {if(!error_mode) printf("IF\n"); column += yyleng;}
{INT}                  {if(!error_mode) printf("INT\n"); column += yyleng;}
{SHORT}                {if(!error_mode) printf("SHORT\n"); column += yyleng;}
{DOUBLE}               {if(!error_mode) printf("DOUBLE\n"); column += yyleng;}
{RETURN}               {if(!error_mode) printf("RETURN\n"); column += yyleng;}
{VOID}                 {if(!error_mode) printf("VOID\n"); column += yyleng;}
{BITWISEAND}           {if(!error_mode) printf("BITWISEAND\n"); column += yyleng;}
{BITWISEOR}            {if(!error_mode) printf("BITWISEOR\n"); column += yyleng;}
{BITWISEXOR}           {if(!error_mode) printf("BITWISEXOR\n"); column += yyleng;}
{AND}                  {if(!error_mode) printf("AND\n"); column += yyleng;}
{ASSIGN}               {if(!error_mode) printf("ASSIGN\n"); column += yyleng;}
{COMMA}                {if(!error_mode) printf("COMMA\n"); column += yyleng;}
{DIV}                  {if(!error_mode) printf("DIV\n"); column += yyleng;}
{EQ}                   {if(!error_mode) printf("EQ\n"); column += yyleng;}
{GE}                   {if(!error_mode) printf("GE\n"); column += yyleng;}
{GT}                   {if(!error_mode) printf("GT\n"); column += yyleng;}
{LBRACE}               {if(!error_mode) printf("LBRACE\n"); column += yyleng;}
{LE}                   {if(!error_mode) printf("LE\n"); column += yyleng;}
{LPAR}                 {if(!error_mode) printf("LPAR\n"); column += yyleng;}
{LT}                   {if(!error_mode) printf("LT\n"); column += yyleng;}
{MOD}                  {if(!error_mode) printf("MOD\n"); column += yyleng;}
{NE}                   {if(!error_mode) printf("NE\n"); column += yyleng;}
{NOT}                  {if(!error_mode) printf("NOT\n"); column += yyleng;}
{OR}                   {if(!error_mode) printf("OR\n"); column += yyleng;}
{RBRACE}               {if(!error_mode) printf("RBRACE\n"); column += yyleng;}
{RPAR}                 {if(!error_mode) printf("RPAR\n"); column += yyleng;}
{SEMI}                 {if(!error_mode) printf("SEMI\n"); column += yyleng;}
{ID}                   {if(!error_mode) printf("ID(%s)\n", yytext); column += yyleng;}
{INTLIT}               {if(!error_mode) printf("INTLIT(%s)\n", yytext); column += yyleng;}
{REALLIT}              {if(!error_mode) printf("REALLIT(%s)\n", yytext); column += yyleng;}

    /* TRATAMENTO DE CHRLIT */
{CHRLIT}               {if(!error_mode) printf("CHRLIT(%s)\n", yytext); column += yyleng;}
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
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}