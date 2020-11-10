#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include "functions.h"

NodePtr* createNode(char* type) {
    // 
    NodePtr* new_node = (NodePtr*)malloc(sizeof(NodePtr));
    new_node->type = type;
    new_node->n = 0;

    new_node->parent = NULL;
    new_node->children = NULL;
    new_node->next = NULL;
    return new_node;
}

NodePtr* appendNode(NodePtr* parent_node, NodePtr* inserted_node) {
    // adicionar a ast
    if(inserted_node != NULL) {
        inserted_node->parent = parent_node;
        inserted_node->next = parent_node -> children;
        parent_node->children = inserted_node;
        parent_node->n++;
    }
    return parent_node;
}

void printNode(NodePtr* node){
    if(node->parent != NULL) {
        printf("Node name:%s Children #:%d Parent:%d\n", node->type, node->n, node->parent);
    }
}

void printTree(NodePtr* root_node){
    NodePtr* temp = root_node;
    while (temp!=NULL) {
        NodePtr* temp2 = temp->next;
        printNode(temp);
        while(temp2 != NULL){
            printNode(temp2);
            temp2 = temp2->next;
        }
        temp = temp->children;
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

    if(current_node->type){
        free(current_node->type);
    }
    free(current_node);
}
    