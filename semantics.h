#include "funcSymtab.h"

symtab* progSymTab(NodePtr* head);
symtab* initSymTab();
symtab* addFuncDec(NodePtr* head,symtab* mainSymTab);
symtab* addFuncDef(NodePtr* head,symtab* mainSymTab);
symtab* createFuncSymTab(NodePtr* funcBodyHead,symtab* symTabProgram);
symtab* checkSym(symtab* head,char* id);
func_no* createNewFuncProg(NodePtr* head,symtab* symProg);
paramlist* createParamList(NodePtr* head);
NodePtr* inserAnot(NodePtr* node,symtab* symTable,NodePtr* lastFuncID);
symtab* getNodeId(symtab* head,char* id,char* lastFunDefId);
char* retAnotIdFunc(symtab* idNode);
int isId(char* str);
int isRealLit(char* str);
int isCharLit(char* str);
int isIntLit(char* str);
NodePtr* anotAST(NodePtr* head,symtab* symTable,NodePtr* lastFuncID);
void errorSemMes(NodePtr* node,symtab* symTab,NodePtr* lastFuncId);
