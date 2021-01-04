#include "symtab.h"
#include "functions.h"

symtab* insertSymTabNode(symtab* head,func_no* func,var_no* var);
paramlist* inserParam(paramlist* head, var_no* var_no);
paramlist* createParamNode(var_no* var);
var_no* createVarNode(char* id, char* type);
func_no* createFuncNode(char* id,char* type,paramlist* head);
symtab* createSymTabNode(func_no* func,var_no* var);
void printTable(symtab* head);
void freeTable(symtab* head);