#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bst.h"

BST* createTree() {
    // allocate memory for the tree
    BST* tree = (BST*)malloc(sizeof(BST));
    if(tree == NULL) {
        puts("Memory allocation for binary search tree failed.");
        return NULL;
    }
    // initialize the tree
    tree->root = NULL;
    return tree;
}

int treeEmpty(BST* tree) {
    if(tree == NULL || tree->root == NULL)
        return 1;
    return 0;
}

void bstInsert(BST* tree, TNode* new_tnode) {
    // check if the tree or the new nod is null
    if(tree == NULL || new_tnode == NULL)
        return;
    // check if the tree is empty
    if(tree->root == NULL) {
        tree->root = new_tnode;
        return;
    }

    // find the position to attach the new node
    TNode* current = tree->root;
    TNode* parent = NULL;
    while(current != NULL) {
        parent = current;
        int cmp = strcmp(new_tnode->data, current->data);
        if(cmp == 0) {
            free(new_tnode);
            return;
        } else if(cmp < 0) 
            current = current->left;
        else 
            current = current->right;
    }
    // attach the new node
    int cmp = strcmp(new_tnode->data, parent->data);
    if(cmp < 0) 
        parent->left = new_tnode;
    else
        parent->right = new_tnode;
}

void printAlphabetical(BST* tree, char start_char) {
    if(treeEmpty(tree)) {
        puts("Tree is empty.");
        return;
    }
    printf("Tree: ");
    inOrderFiltered(tree->root, start_char);
    puts("");
}

TNode* Tsearch(BST* tree, char* key) {
    // check if the tree is null or empty
    if(tree == NULL || tree->root == NULL) 
        return NULL;
    // searching the key
    TNode* current = tree->root;
    while(current != NULL) {
        int cmp = strcmp(current->data, key);
        if(cmp == 0)
            return current;
        else if(cmp < 0)
            current = current->right;
        else
            current = current->left;
    }
    return NULL;
}

void TRemove(BST* tree, char* key) {
    // check if the tree is null or empty
    if(tree == NULL || tree->root == NULL)
        return;
    // find the node need to delete and its parent
    TNode* current = tree->root;
    TNode* parent = NULL;
    while(current != NULL) {
        int cmp = strcmp(current->data, key);
        if(cmp == 0) 
            break;
        else {
            parent = current;
            if(cmp < 0) 
                current = current->right;
            else 
                current = current->left;
        }
    }
    // check if cannot find the node
    if(current == NULL) {
        puts("Value not found.");
        return;
    }
    // case if the node need to delete has 2 children 
    if(current->left != NULL && current->right != NULL) {
        // we need to find the smallest values on the left side of the right child node (inorder successor)
        TNode* successor = current->right;
        TNode* p_successor = current;
        while(successor->left != NULL) {
            p_successor = successor;
            successor = successor->left;
        }
        // copy the value of the inorder successor to the current node (the node we plan to remove it)
        strcpy(current->data, successor->data);
        // update the node inorder successor 
        // after being updated, now its only has 2 cases: parent has 0 or 1 child
        parent = p_successor;
        current = successor;
    }
    // find the child node of the node that need to be deleted
    TNode* child = NULL;
    if(current->left != NULL)
        child = current->left;
    else
        child = current->right;
    // case delete the root node
    if(parent == NULL)
        tree->root = child;
    else {
        if(parent->left == current)
            parent->left = child;
        else 
            parent->right = child;
    }
    // free the node
    printf("The node at address %p is deleted.\n", current);
    free(current);
}

void TloadTextFile(BST* tree, char* filename) {
    // open the file and check if it is opened successfully
    FILE* fp;
    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error opening file for reading: %s\n", filename);
        return;
    }
    // read data from the file
    char line[20];
    while(fgets(line, sizeof(line), fp) != NULL) {
        line[strcspn(line, "\n")] = '\0';
        TNode* new_node = createTNode(line);
        bstInsert(tree, new_node);
    }
    // close the file
    fclose(fp);
}

void TstoreTextFile(BST* tree, char* filename) {
    // open file and check if it is opened successfully
    FILE* fp;
    fp = fopen(filename, "w");
    if(fp == NULL) {
        printf("Error opening file for writing: %s\n", filename);
        return;
    }
    // check if the tree is empty
    if(treeEmpty(tree)) {
        puts("There is nothing to write to the file.");
        return;
    }
    // write the tree to the file
    writePreOrder(tree->root, fp);
    //close the file
    fclose(fp);
}

void freeTree(BST* tree) {
    // check if the tree is empty
    if(tree == NULL)
        return;
    // call the freeNode function from the root
    freeNodes(tree->root);
    // free the tree
    free(tree);
    tree->root = NULL;
}