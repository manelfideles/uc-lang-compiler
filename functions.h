#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct node NodePtr;

typedef struct node {
    // AST
    NodePtr* parent;
    NodePtr* children;

    // Listas Ligadas (p.ex listas de argumentos)
    NodePtr* next;
    int n; // para contar o numero de filhos do nó
    int depth;

    /* o type recebe o nome do token (While, If, ...).
       Se for um token com valor numérico (intlit, reallit, chrlit)
       ou um ID, é criada uma string com NomeToken(ValorNumerico)
    */
    char* type; 
} Node; 

#endif

NodePtr* createNode(char* type);
NodePtr* appendNode(NodePtr* parent_node, NodePtr* inserted_node);
void printNode(NodePtr* node);
void printTree(NodePtr* root_node); // int depth ??
void freeTree(NodePtr* current_node);