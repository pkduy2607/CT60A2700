#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "node.h"

Node* createNode(const char* key) {
    // allocate memory for the new node
    Node* new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL) {
        puts("Memory allocation for node failed.");
        return NULL;
    }

    // initialize the node
    strcpy(new_node->data, key);
    new_node->prev = NULL;
    new_node->next = NULL;

    return new_node;
}

void printNode(Node* node) {
    if(node != NULL) 
        printf("[%s]", node->data);
    else 
        printf("The node is NULL");
}