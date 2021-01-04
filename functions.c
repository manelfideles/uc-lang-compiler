#include "functions.h"

int depth = 0;

NodePtr* createNode(char* type,int lin,int col) {
    NodePtr* new_node = (NodePtr*)malloc(sizeof(NodePtr));

    new_node->type = type;
    new_node->anot= NULL;
    new_node->n = 0;
    new_node->lin=lin;
    new_node->col=col;
    new_node->parent = NULL;
    new_node->children = NULL;
    new_node->next = NULL;
    new_node->flag=0;
    return new_node;
}
NodePtr* appendNode(NodePtr* parent_node, NodePtr* inserted_node) {
    NodePtr* aux = inserted_node;
    if(inserted_node != NULL) {
        inserted_node->parent = parent_node;
        while(aux->next) aux = aux->next;
        aux->next = parent_node->children;
        parent_node->children = inserted_node;
    }
    return parent_node;
}
void printNode(NodePtr* node){
    for(int j = 0; j < depth; j++) printf("..");
    if(node->anot){
        printf("%s - %s\n", node->type,node->anot);
    }
    else{
        printf("%s\n", node->type);
    }
}
void printTree(NodePtr* node){
    NodePtr* aux = NULL;
    aux = node->children; //int->id->intlit
    printNode(node); //declaration

    depth++;
    while(aux) {
        printTree(aux);
        aux = aux->next;
    }
    depth--;
    return;
   
}
void freeTree(NodePtr* current_node){
    int i = 0;
    NodePtr* aux_act = NULL, *aux_next = NULL;
    aux_act = current_node->children;
    for (; i < current_node->n; i++){
        aux_next = aux_act->next;
        freeTree(aux_act);
        aux_act = aux_next;
    }

    if(current_node->type){
        free(current_node->type);
    }
    free(current_node);
}

char* retId(char* id){
    const char oc[2]= "(";
    char* ret=strstr(id,oc);
    ret++;
    char* name= (char*)malloc(sizeof(char)*(strlen(ret)+2));
    strncpy(name,ret,strlen(ret)-1);
    return name;
}

inf_node* createInfNode(int lin, int col){
    inf_node* new = (inf_node*)malloc(sizeof(inf_node));
    new->lin=lin;
    new->col=col;
    return new;
}