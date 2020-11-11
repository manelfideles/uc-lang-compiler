#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include "functions.h"

int depth = 0;

NodePtr* createNode(char* type) {
    NodePtr* new_node = (NodePtr*)malloc(sizeof(NodePtr));

    new_node->type = type;

    new_node->n = 0;
    new_node->parent = NULL;
    new_node->children = NULL;
    new_node->next = NULL;

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
    printf("%s\n", node->type);
}
void printTree(NodePtr* root_node){
    printNode(root_node);
    NodePtr *aux = root_node->children;
    if(aux != NULL) {
        depth++;
        while(aux->next != NULL){
            printTree(aux);
            aux = aux->next;
        }
        printTree(aux);
        depth--;
    }
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