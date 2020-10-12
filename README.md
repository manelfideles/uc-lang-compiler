# UC-Language-Compiler
UC (subset of C99) compiler for my Compilers class.

Run:
 > lex uccompiler.l
 > clang-3.9 -o uccompiler lex.yy.cc
 > ./uccompiler -l < tests/testeX.uc (to run test file X, replace X with a number)
