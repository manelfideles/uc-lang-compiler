# UC-Language-Compiler
UC (subset of C99) compiler for my Compilers class.

Compile and output verbose (y.output):
 > lex uccompiler.l && yacc -dv uccompiler.y && cc -o uccompiler lex.yy.c y.tab.c
 
Run:
 > ./uccompiler -[ l | e1 | e2 | t ] < tests/testeX.uc (to run test file X, replace X with a number)
 
  empty -> prints lexical and syntax errors
  -l    -> prints lexical erros and tokens found
  -e1   -> prints lexical errors only
  -e2   -> prints lexical and syntax errors
  -t    -> prints AST
