#ifndef SYMTAB_H
#define SYMTAB_H
#include "stdio.h"
typedef struct _t5 paramlist;
typedef struct _t3 var_no;
typedef struct _t2 func_no;
typedef struct _t1 symtab;

typedef struct _t5{
    var_no* var;
    paramlist* next;
}paramlist;

typedef struct _t3{
    char* type;
    char* name;
}var_no;

typedef struct _t2{
    char* name;
    char* type;
    int def;
    paramlist* params;
    symtab* funcTab;
}func_no;

typedef struct _t1{
    func_no* func;
    var_no* var;
    symtab* next;
}symtab;
#endif
