#include "functions.h"

NodePtr* createNode(char* value, NodeType type) {
    NodePtr* new_node = (NodePtr*)malloc(sizeof(NodePtr));
    new_node->value = value;
    new_node->type = type;
    new_node->n = 0;

    new_node->parent = NULL;
    new_node->children = NULL;
    new_node->next = NULL;
    return new_node;
}

NodePtr* pushNode(NodePtr* parent_node, NodePtr* inserted_node) {
    // adicionar a ast
    if(inserted_node != NULL) {
        inserted_node->parent = parent_node;
        inserted_node->next = parent_node -> children;
        parent_node->children = inserted_node;
        parent_node->n++;
    }
}

char* retNodeType(NodePtr* node){
    char* str= (char *)malloc(sizeof(char)*20);
    switch(node->type){
        case Program :
            sprintf(str, "Program");
            return str;
        case If :
            sprintf(str, "If");
            return str;
        case While :
            sprintf(str, "While");
            return str;
        case Return :
            sprintf(str, "Return");
            return str;
        case Call :
            sprintf(str, "Call");
            return str;
        case Or :
            sprintf(str, "Or");
            return str;
        case And :
            sprintf(str, "And");
            return str;
        case Eq:
            sprintf(str, "Eq");
            return str;
        case Ne:
            sprintf(str, "Ne");
            return str;
        case Lt:
            sprintf(str, "Lt");
            return str;
        case Gt:
            sprintf(str, "Gt");
            return str;
        case Le:
            sprintf(str, "Le");
            return str;
        case Ge:
            sprintf(str, "Ge");
            return str;
        case Add:
            sprintf(str, "Add");
            return str;
        case Sub :
            sprintf(str, "Sub");
            return str;
        case Mul :
            sprintf(str, "Mul");
            return str;
        case Div :
            sprintf(str, "Div");
            return str;
        case Mod :
            sprintf(str, "Mod");
            return str;
        case Not :
            sprintf(str, "Not");
            return str;
        case Minus :
            sprintf(str, "Minus");
            return str;
        case Plus :
            sprintf(str, "Plus");
            return str;
        case Double :
            sprintf(str, "Double");
            return str;
        case Id :
            sprintf(str, "Id(%s)", node->value);
            return str;
        case Int :
            sprintf(str, "Int");
            return str;
        case RealLit :
            sprintf(str, "RealLit(%s)", node->value);
            return str;
        case Void :
            sprintf(str, "Void");
            return str;
    }
}

void printNode(NodePtr* node){
    char* str=retNodeType(node);
    printf("Valor:%s Filhos:%d Tipo:%s\n",node->value,node->n,str);
}

void printTree(NodePtr* root_node){
    NodePtr* temp=root_node;
    while (temp!=NULL) {
        NodePtr* temp2=temp->next;
        printNode(temp);
        while(temp2!=NULL){
            printNode(temp2);
            temp2=temp2->next;
        }
        temp=temp->children;
    }
}

void freeTree(NodePtr* current_node){
    int i=0;
    char * str;
    NodePtr* aux_act=NULL, *aux_next=NULL;
    aux_act = current_node->children;
    for (;i<current_node->n;i++){
        aux_next = aux_act->next;
        free_tree(aux_act);
        aux_act = aux_next;
    }

    if(current_node->value){
        free(current_node->value);
    }
    free(current_node);
}
    