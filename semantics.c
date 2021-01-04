#include "semantics.h"

int debugSym=0;
int debugAST=0;

symtab* progSymTab(NodePtr* head){
    NodePtr* aux=head;
    symtab* symTab= NULL;

    //Percorrer pelas declaracoes de variaveis, declaracoes de funcoes e definicoes de funcoes
    while (aux){
        if(!strcmp(aux->type,"Program")){
            //Criar os nos das funcoes "getchar" e "putchar" que ja estao na symbol table antes do programa correr
            symTab= initSymTab();
            aux=aux->children;
            continue;
        }
        else if(!strcmp(aux->type,"Declaration")){
            char* id= retId(aux->children->next->type);
            if(debugSym) printf("DECLARATION %s\n",id);
            if(checkSym(symTab,id)){
                //Tratamento de erro quando o nome da variavel e igual a um nome de uma variavel que ja foi previamente 
            }else{
                symTab= insertSymTabNode(symTab,NULL,createVarNode(id,aux->children->type));
            }
        }
        else if(!strcmp(aux->type,"FuncDeclaration")){
            symTab=addFuncDec(aux,symTab);
        }
        else if(!strcmp(aux->type,"FuncDefinition")){
            symTab=addFuncDef(aux,symTab);
        }
        else if(!strcmp(aux->type,"Call")){

        }
        aux=aux->next;
    }
    return symTab;
}

symtab* addFuncDec(NodePtr* head,symtab* mainSymTab){
    char* id= retId(head->children->next->type);
    if(debugSym) printf("FuncDeclaration %s\n",id);
    symtab* node=checkSym(mainSymTab,id);
    if(node){
        if(node->var){
            //Tratamento de erro quando o nome da funcao a ser definida é igual ao nome de uma variável ja previamente definida
        }else if(node->func){
            if(node->func->def){
                //tratamento de erro quando o nome da funcao corresponde ao nome de uma funcao que ja foi definida anteriormente
            }
            else{
                //tratamento de erro quando uma funcao com o mesmo nome ja foi previamente declarada 
            }
        }
    }
    else{
        func_no* new_func=createNewFuncProg(head,mainSymTab);
        mainSymTab=insertSymTabNode(mainSymTab,new_func,NULL);
    }
    return mainSymTab;
}

symtab* addFuncDef(NodePtr* head,symtab* mainSymTab){
    char* id= retId(head->children->next->type);
    if(debugSym) printf("FuncDefinition %s\n",id);
    symtab* node=checkSym(mainSymTab,id);
    if(node){
        if(node->var){
            //Tratamento de erro quando o nome da funcao a ser definida é igual ao nome de uma variável ja previamente definida
        }else if(node->func){

            if(node->func->def){
                //tratamento de erro quando o nome da funcao corresponde ao nome de uma funcao que ja foi definida anteriormente
            }
            else{
                symtab* aux_subFunc=mainSymTab;
                while (aux_subFunc)
                {
                    if(aux_subFunc->func){
                        if(!strcmp(aux_subFunc->func->name,node->func->name)) break;
                    }
                    aux_subFunc=aux_subFunc->next;
                }
                func_no* new_func=createNewFuncProg(head,mainSymTab);
                new_func->def=1;
                aux_subFunc->func=new_func;
                //Uma vez que passou todos os testes, criar o no da funcao com todos os parameteros e a sua propria symbol table
            }
        }
    }else{
        func_no* new_func=createNewFuncProg(head,mainSymTab);
        new_func->def=1;
        mainSymTab=insertSymTabNode(mainSymTab,new_func,NULL);
    }
    return mainSymTab;
}

symtab* initSymTab(){
    symtab* symTab= NULL;
    paramlist* paramPutChar=createParamNode(createVarNode("paramPutChar","Int"));
    paramlist* paramGetChar=createParamNode(createVarNode("paramGetChar","Void"));
    symTab=insertSymTabNode(symTab,createFuncNode("putchar","Int",paramPutChar),NULL);
    symTab=insertSymTabNode(symTab,createFuncNode("getchar","Int",paramGetChar),NULL);
    return symTab;
}

//verifica se os paramteros da funcao que esta a ser definida bate certo com os parametros quando a funcao é declarada previamente
//Poe o nomes de cada parametro na lista de parametros
paramlist* checkParams(NodePtr* head, paramlist* list){

    return list;
}
func_no* createNewFuncProg(NodePtr* head,symtab* symProg){
    if(debugSym) printf("createNewFuncProg\n");
    char* id= retId(head->children->next->type);
    paramlist* paramFunc=NULL;
    symtab* funcSymTab=NULL;
    //Passar pelos "ParamDeclaration" e inserir los de forma de nos dentro da paramlist do no da funcao
    paramFunc=createParamList(head);
    NodePtr* aux_funcbody=head->children->next->next->next;
    if(aux_funcbody){
        if(aux_funcbody->children)
            funcSymTab=createFuncSymTab(aux_funcbody->children,symProg);
            else{
                //Tratamento para quando a funcBody esta vazio
            }
    }
    func_no* new_func=createFuncNode(id,head->children->type,paramFunc);
    new_func->funcTab->next=funcSymTab;
    return new_func;
}
paramlist* createParamList(NodePtr* head){
    if(debugSym) printf("createParamList\n");

    NodePtr* aux_param=head->children->next->next->children;
    paramlist* paramFunc=NULL;
    //Passar pelos "ParamDeclaration" e inserir los de forma de nos dentro da paramlist do no da funcao
    while (aux_param){
        var_no* novo_param=NULL;
        if(aux_param->children->next){
                novo_param=createVarNode(retId(aux_param->children->next->type),aux_param->children->type);
        }
        else novo_param=createVarNode("null",aux_param->children->type);

        paramlist* paramNode=inserParam(paramFunc,novo_param);

        if(paramNode) paramFunc=paramNode;
        else; //Caso haja dois parametros iguais
        aux_param=aux_param->next;
    }
    return paramFunc;
}
symtab* createFuncSymTab(NodePtr* funcBodyHead,symtab* symTabProgram){
    if(debugSym) printf("createFuncSymTab\n");
    NodePtr* aux=funcBodyHead;
    symtab* funcSymTab=NULL;
    while (aux) {
        if(!strcmp(aux->type,"Declaration")){
            char* id=retId(aux->children->next->type);
            if(checkSym(symTabProgram,id)){
                //Tratamento de erro quando o nome da variavel é igual a um nome de uma variavel global
            }else if(checkSym(funcSymTab,id)){
                //Tratamento de erro quando o nome da variavel é igual a um nome de uma variavel que ja foi previamente declarada no decorrer da funcao 
            }else{

            }
            var_no* new_var= createVarNode(id,aux->children->type);
            funcSymTab=insertSymTabNode(funcSymTab,NULL,new_var);
        }
        else if(!strcmp(aux->type,"Call")){

        }
        else if(!strcmp(aux->type,"Return")){

        }
        aux=aux->next;
    }
    return funcSymTab;
}

symtab* checkSym(symtab* head,char* id){
    if(debugAST) printf("checkSym\n");

    symtab* aux= head;
    while (aux) {
       if(aux->func){
           if(!strcmp(aux->func->name,id)) return aux;
       }
       else if(aux->var){
           if(!strcmp(aux->var->name,id)) return aux;
       }
       aux=aux->next;
    }
    return NULL;
    
}
symtab* getNodeId(symtab* head,char* id,char* lastFunDefId){
    if(debugSym) printf("getNodeId %s\n",id);
    symtab* node=checkSym(head,id);
    if(node==NULL){
        symtab* aux=head;
        while (aux){
            if(aux->func){
                if(!strcmp(aux->func->name,lastFunDefId)){
                    node= checkSym(aux->func->funcTab,id);
                    if(node) return node;
                }
            }
            aux=aux->next;
        }
    }
    return node;
}

//Recebe o no e com a ajuda da symbol table já feita e o com o ponteiro para o no da ultima funçao que foi lida na AST
NodePtr* inserAnot(NodePtr* node,symtab* symTable,NodePtr* lastFunc){
    if(debugAST) printf("inserAnot %s\n",node->type);
    NodePtr* child1;
    NodePtr* child2;
    if(isRealLit(node->type)){
        node->anot = "double";
    }
    else if(!strcmp(node->type,"FuncDeclaration")){

    }
    else if(isIntLit(node->type) || isCharLit(node->type) || !strcmp(node->type, "Not") || !strcmp(node->type, "Or") || !strcmp(node->type, "And") || !strcmp(node->type, "BitWiseAnd") || !strcmp(node->type, "BitWiseOr") || !strcmp(node->type, "BitWiseXor") || !strcmp(node->type, "Eq") || !strcmp(node->type, "Ne") || !strcmp(node->type, "Le") || !strcmp(node->type, "Ge") || !strcmp(node->type, "Lt") || !strcmp(node->type, "Gt") || !strcmp(node->type,"Mod")){
        node->anot="int";
        if(node->children){

            if(node->children->next){
        

                if(!strcmp(node->children->anot,"char")){
                    if(!strcmp(node->children->next->anot,"double")) errorSemMes(node,symTable,lastFunc);
                }
                else if(!strcmp(node->children->anot,"short")){
                    if(!strcmp(node->children->next->anot,"double")) errorSemMes(node,symTable,lastFunc);
                }
                else if(!strcmp(node->children->anot,"int")){
                    if(!strcmp(node->children->next->anot,"double")) errorSemMes(node,symTable,lastFunc);
                }
                else if(!strcmp(node->children->anot,"double")){
                    if(!strcmp(node->children->next->anot,"double")) errorSemMes(node,symTable,lastFunc);
                }
            }
        }
    }
    else if(isId(node->type) && node->flag){
        symtab* idNode=getNodeId(symTable,retId(node->type),retId(lastFunc->type));
        if(idNode->var) node->anot=idNode->var->type;
        else if(idNode->func) {
            char* anot=(char*)malloc(sizeof(char)*200);
            char p[10];
            strcpy(anot,""); 
            sprintf(anot,"%s(",idNode->func->type);
            paramlist* aux_param=idNode->func->params;
            while (aux_param->next){
                sprintf(p,"%s,",aux_param->var->type);
                strcat(anot,p);
                strcpy(p,"");
                aux_param=aux_param->next;
            }
            sprintf(p,"%s)",aux_param->var->type);
            strcat(anot,p);
            strcpy(p,"");
            node->anot=anot;
        }
        else{
            node->anot="undef";
        }
    }
    else if(!strcmp(node->type,"Minus") || !strcmp(node->type,"Plus")){
        node->anot = node->children->anot;
        if(!strcmp(node->anot,"double")){
            errorSemMes(node,symTable,lastFunc);
        }
    }
    else if(!strcmp(node->type,"Call") || !strcmp(node->type,"Store")){
        if(isIntLit(node->children->type)){
            node->anot="int";
            return node;
        }
        else if(isCharLit(node->children->type)){
            node->anot="char";
            return node;
        }
        else if(isRealLit(node->children->type)){
            node->anot="char";
            return node;
        }
        else{
            symtab* idNode=getNodeId(symTable,retId(node->children->type),retId(lastFunc->type));
            if(idNode->func) node->anot=idNode->func->type;
            else  node->anot=idNode->var->type;
        }
        if(!strcmp(node->type,"Store")){
            if(node->parent){
                if(!strcmp(node->parent->type,"If")){
                    if(node->children){
                        if(node->children->next){
                            if(!strcmp(node->anot,"double")){
                                errorSemMes(node,symTable,lastFunc);
                            }
                            else if(!strcmp(node->children->anot,"char")){
                                if(!strcmp(node->children->next->anot,"double")) errorSemMes(node,symTable,lastFunc);
                            }
                            else if(!strcmp(node->children->anot,"short")){
                                if(!strcmp(node->children->next->anot,"double")) errorSemMes(node,symTable,lastFunc);
                            }
                            else if(!strcmp(node->children->anot,"int")){
                                if(!strcmp(node->children->next->anot,"double")) errorSemMes(node,symTable,lastFunc);
                            }
                        }
                    }
                }
            }
        }else{
            if(node->children){
                errorSemMes(node,symTable,lastFunc);
            }
        }
    }
    else if(!strcmp(node->type,"Comma")){
        node->anot=node->children->next->anot;
        if(!strcmp(node->anot,"double")){
            errorSemMes(node,symTable,lastFunc);
        }
    }
    else if(!strcmp(node->type,"Add") || !strcmp(node->type,"Sub") || !strcmp(node->type,"Div") || !strcmp(node->type,"Mul")){
        child1 = node->children;
        child2 = node->children->next;
        if(!strcmp(child1->anot, "undefined") || !strcmp(child2->anot, "undefined")){
            node->anot = "undefined";
        }
        else if(!strcmp(child1->anot, "double") || !strcmp(child2->anot, "double")){
            node->anot = "double";
        }
        else if(!strcmp(child1->anot, "int") || !strcmp(child2->anot, "int")){
            node->anot="int";
        }
        else if(!strcmp(child1->anot, "short") || !strcmp(child2->anot, "short")){
            node->anot="short";
        }
        else if(!strcmp(child1->anot, "char") || !strcmp(child2->anot, "char")){
            node->anot="char";
        }
        if(!strcmp(node->anot,"double")){
            errorSemMes(node,symTable,lastFunc);
        }
    }
    else if(!strcmp(node->type,"Return")){
        if(node->children){
            errorSemMes(node,symTable,lastFunc);
        }
    }
    
    return node;
}

int isId(char* str){
    if (strlen(str)>2 && str[0]=='I' && str[1]=='d' && str[2]=='(') {
        return 1;
    }
    return 0;
}

int isRealLit(char* str){
    if (strlen(str)>7 && str[0]=='R' && str[1]=='e' && str[2]=='a' && str[3]=='l' && str[4]=='L' && str[5]=='i' && str[6]=='t' && str[7]=='(') {
        return 1;
    }
    return 0;
}
int isCharLit(char* str){
    if (strlen(str)>6 && str[0]=='C' && str[1]=='h'  && str[2]=='r' && str[3]=='L' && str[4]=='i' && str[5]=='t' && str[6]=='(') {
        return 1;
    }
    return 0;
}

int isIntLit(char* str){
    if (strlen(str)>6 && str[0]=='I' && str[1]=='n' && str[2]=='t' && str[3]=='L' && str[4]=='i' && str[5]=='t' && str[6]=='(' ) {
        return 1;
    }
    return 0;
}

//Funçao recursiva que percorre a ast e chama a função "insertAnot" para inserir as anotações nos nós
NodePtr* anotAST(NodePtr* head,symtab* symTable,NodePtr* lastFuncID){
    if(debugAST) printf("anotAST %s\n",head->type);
    NodePtr* aux= head->children;
    while (aux){
        if(!strcmp("FuncDefinition",aux->type)) lastFuncID=aux->children->next;
        aux=anotAST(aux,symTable,lastFuncID);
        aux=inserAnot(aux,symTable,lastFuncID);
        aux=aux->next;
    }
    return head;
}


//print dos erros mediante o tipo do no que a função recebe
void errorSemMes(NodePtr* node,symtab* symTab,NodePtr* lastFuncId){
    int lin=0,col=0;
    if((!strcmp(node->type,"Store") || !strcmp(node->type,"Comma") || !strcmp(node->type,"Add") || !strcmp(node->type,"Sub") || !strcmp(node->type,"Div") || !strcmp(node->type,"Mul") || !strcmp(node->type,"Minus") || !strcmp(node->type,"Plus")) && !strcmp(node->anot,"double")){
        lin=node->children->lin;
        col=node->children->col + strlen(retId(node->children->type));
        printf("Line %d, col %d: Conflicting types (got double, expected int)\n",lin,col);
    }
    else if(!strcmp(node->type,"Store") || !strcmp(node->type,"Mod") || !strcmp(node->type, "Or") || !strcmp(node->type, "And") || !strcmp(node->type, "BitWiseAnd") || !strcmp(node->type, "BitWiseOr") || !strcmp(node->type, "BitWiseXor")){
        char* op=NULL;

        if(!strcmp(node->type,"Store")) op="=";
        else if(!strcmp(node->type,"Mod")) {
            if(node->children){
                lin=node->children->lin;
                col=node->children->col + strlen(retId(node->children->type));
            }
            printf("Line %d, col %d: Operator %c cannot be applied to types %s, %s\n",node->lin,node->col,'%',node->children->anot,node->children->next->anot);
            return;
        }
        else if(!strcmp(node->type, "Or")) op="||";
        else if(!strcmp(node->type, "And")) op="&&";
        else if(!strcmp(node->type, "BitWiseAnd")) op="&";
        else if(!strcmp(node->type, "BitWiseOr")) op="|";
        else if(!strcmp(node->type, "BitWiseXor")) op="^";
        if(node->children){
            lin=node->children->lin;
            col=node->children->col + strlen(retId(node->children->type));
        }
        
        printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n",node->lin,node->col,op,node->children->anot,node->children->next->anot);
    }
    else if(!strcmp(node->type,"Call")){
        symtab* aux=symTab;
        int contParam=0;
        int actParams=0;
        paramlist* aux_param=NULL;
        while (aux)
        {
            if(aux->func){
                if(!strcmp(aux->func->name,retId(node->children->type))) {
                    aux_param=aux->func->params;
                    break;
                }
            }
            aux=aux->next;
        }
        NodePtr* aux_node=node->children->next;
        if(!strcmp(aux_param->var->type,"void")){
            if(aux_node) {
                while (aux_node){
                    contParam++;
                    aux_node=aux_node->next;
                }
                printf("Line %d, col %d: Wrong number of arguments to function %s(got %d, required 0)\n",node->lin,node->col,retId(node->children->type),contParam);
            }
        }
        else{
            while (aux_node){
                contParam++;
                aux_node=aux_node->next;
            }
            
            while (aux_param)
            {
                actParams++;
                aux_param=aux_param->next;
            }
            if(contParam!=actParams){
                printf("Line %d, col %d: Wrong number of arguments to function %s(got %d, required %d)\n",node->lin,node->col,retId(node->children->type),contParam,actParams);
            }
        }
        
    }
    else if(!strcmp(node->type,"Return")){
        symtab* aux=symTab;
        char* type=NULL;
        while (aux){
            if(aux->func){
                if(!strcmp(aux->func->name,retId(lastFuncId->type))){
                    type= aux->func->type;
                    break;
                }
            }
            aux=aux->next;
        }
        if(node->children->anot){
            if(strcmp(node->children->anot,type)!=0 && (!(!strcmp(node->children->anot,"int") && !strcmp(type,"double")) && !(isCharLit(node->children->type) && !strcmp(type,"char")))){
                printf("Line %d, col %d: Conflicting types (got %s, expected %s)\n",node->lin,node->col,node->children->anot,type);
            }
            
        }else{
            if(strcmp(type,"void")!=0){
                printf("Line %d, col %d: Conflicting types (got void, expected %s)\n",node->lin,node->col,type);
            }
        }
    }
}   