#ifndef TNODE_H
#define TNODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TNode {
    char data[20];
    struct TNode* left;
    struct TNode* right;
} TNode;

TNode* createTNode(const char* key);
void printTNode(TNode* tnode, char start_char);
void inOrderFiltered(TNode* tnode, char start_char);
void writePreOrder(TNode* tnode, FILE* fp);
void freeNodes(TNode* tnode);

#endif