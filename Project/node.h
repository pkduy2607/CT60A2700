#ifndef NODE_H
#define NODE_H

typedef struct Node {
    char data[20];
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(const char* key);
void printNode(Node* node);

#endif