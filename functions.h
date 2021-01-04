#ifndef STRUCTURES_H
#define STRUCTURES_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
typedef struct node NodePtr;
typedef struct nodeInf inf_node;
typedef struct node {
    // AST
    NodePtr* parent;
    NodePtr* children;

    // Listas Ligadas (p.ex listas de argumentos)
    NodePtr* next;
    int n; // para contar o numero de filhos do nó
    int depth;
    int lin;
    int col;
    /* o type recebe o nome do token (While, If, ...).
       Se for um token com valor numérico (intlit, reallit, chrlit)
       ou um ID, é criada uma string com NomeToken(ValorNumerico)
    */
    char* anot;
    char* type;
    int flag;
} Node; 
typedef struct nodeInf{
    int lin;
    int col;
    char* value;
}Info;
#endif
NodePtr* createNode(char* type,int lin,int col);
NodePtr* appendNode(NodePtr* parent_node, NodePtr* inserted_node);
void printNode(NodePtr* node);
void printTree(NodePtr* root_node); // int depth ??
void freeTree(NodePtr* current_node);
char* retId(char* id);
inf_node* createInfNode(int lin, int col);
