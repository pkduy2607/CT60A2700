#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tnode.h"

TNode* createTNode(const char* key) {
    // allocate the memory for the tnode
    TNode* new_node = (TNode*)malloc(sizeof(TNode));
    if(new_node == NULL) {
        puts("Memory allocation for tnode failed.");
        return NULL;
    }

    // initialize the node
    strcpy(new_node->data, key);
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void printTNode(TNode* tnode, char start_char) {
    if(tnode != NULL) {
        if(tnode->data[0] == start_char)
            printf("(%s)", tnode->data);
    } else 
        printf("The node is NULL.");
}

void inOrderFiltered(TNode* tnode, char start_char) {
    if(tnode != NULL) {
        inOrderFiltered(tnode->left, start_char);
        printTNode(tnode, start_char);
        inOrderFiltered(tnode->right, start_char);
    }
}

void writePreOrder(TNode* tnode, FILE* fp) {
    if(tnode != NULL) {
        fprintf(fp, "%s\n", tnode->data);
        writePreOrder(tnode->left, fp);
        writePreOrder(tnode->right, fp);
    }
}

void freeNodes(TNode* tnode) {
    // check if the node is empty
    if(tnode == NULL) 
        return;

    // free the children of node
    freeNodes(tnode->left);
    freeNodes(tnode->right);

    free(tnode);
}