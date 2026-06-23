#include "node.h"

#ifndef DLL_H
#define DLL_H

typedef struct {
    Node* head;
} DLL;

DLL* createList();
int listEmpty(DLL* list);
void insert(DLL* list, Node* new_node);
void displayList(DLL* list, char start_char);
Node* search(DLL* list, char* key);
void Remove(DLL* list, Node* node);
void loadTextFile(DLL* list, char* filename);
void storeTextFile(DLL* list, char* filename);
void freeList(DLL* list);

#endif