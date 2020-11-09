#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
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

NodePtr* appendNode(NodePtr* parent_node, NodePtr* inserted_node) {
    // adicionar a ast
    if(inserted_node != NULL) {
        inserted_node->parent = parent_node;
        inserted_node->next = parent_node -> children;
        parent_node->children = inserted_node;
        parent_node->n++;
    }
}

    