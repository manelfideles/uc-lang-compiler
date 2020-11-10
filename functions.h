#ifndef STRUCTURES_H
#define STRUCTURES_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
typedef enum node_type {
    Program, VarDec, FuncDec, FuncDefini, ParamList, FuncBody, ParamDec,
    StatList, If, While, Return,
    Or, And, Eq, Ne, Lt, Gt, Le, Ge, Add, Sub, Mul, Div, Mod, Not, Minus, Plus, Store, Coma, Call, BitWiseAnd, BitWiseXor, BitWiseOr,
    Char, ChrLit, Id, Int, Short, IntLit, Double, RealLit, Void,
    Null
} NodeType;

typedef struct node NodePtr;

typedef struct node {
    // AST
    NodePtr* parent;
    NodePtr* children;

    // Listas Ligadas (p.ex listas de argumentos)
    NodePtr* next;
    NodePtr* prev;
    int n; // para contar o numero de filhos do nó
    int depth;

    char* value;
    NodeType type; // para diferenciar os diferentes nós
}; 

#endif

NodePtr* createNode(char* value, NodeType type);
NodePtr* psuhNode(NodePtr* parent_node, NodePtr* inserted_node);
void printNode(NodePtr* node);
void printTree(NodePtr* root_node); // int depth ??
void freeTree(NodePtr* current_node);
char* retNodeType(NodePtr* node);