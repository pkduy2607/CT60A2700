#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dll.h"

DLL* createList() {
    // memory allocation
    DLL* list = (DLL*)malloc(sizeof(DLL));
    if(list == NULL) {
        puts("Memory allocation for double linked list failed.");
        return NULL;
    }

    // initialize the double linked list
    list->head = NULL;

    return list;
}

int listEmpty(DLL* list) {
    return (list->head == NULL ? 1 : 0);
}

void insert(DLL* list, Node* new_node) {
    // if the list is empty, can add it immediately
    if(list->head == NULL) {
        list->head = new_node;
        return;
    }

    // if the new_node->data is smaller than the head node
    if(strcmp(new_node->data, list->head->data) < 0) {
        new_node->next = list->head;
        list->head->prev = new_node;
        list->head = new_node;
        return;
    }

    // other cases, now we will find the first node that is larger or equal to the new_node, then insert the new node before that node
    Node* current = list->head;
    while(current->next != NULL && strcmp(current->data, new_node->data) < 0) 
        current = current->next;
    
    // if the new_node is larger than all of the node in the double linked list
    if(current->next == NULL && strcmp(current->data, new_node->data) < 0) {
        current->next = new_node;
        new_node->prev = current;
        return;
    }
    // otherwise, we will add the new_node to the position before the current node
    current->prev->next = new_node;
    new_node->next = current;
    new_node->prev = current->prev;
    current->prev = new_node;
}

void displayList(DLL* list, char start_char) {
    // check if the double linked list is empty
    if(listEmpty(list)) {
        puts("The double linked list is empty.");
        return;
    }

    // check if the list has the word beginning with the character start_char
    Node* current = list->head;
    int check = 1;
    while(current != NULL) {
        if(current->data[0] == start_char) {
            check = 1;
            break;
        } else {
            current = current->next;
        }
    }
    if(check == 0) {
        printf("There is no word beginning with %c.\n", start_char);
        return;
    }

    current = list->head;
    check = 0;
    printf("List: ");
    while(current != NULL) {
        if(current->data[0] == start_char) {
            if(check == 1) 
                printf(" <-> ");
            printNode(current);
            check = 1;
        }
        current = current->next;
    }
    puts("");
}

Node* search(DLL* list, char* key) {
    if(listEmpty(list))
        return NULL;
    
    Node* current = list->head;
    while(current != NULL) {
        if(strcmp(current->data, key) == 0)
            return current;
        current = current->next;
    }

    return NULL;
}

void Remove(DLL* list, Node* node) {
    // check if the node that need to be removed is null
    if(node == NULL) 
        return;
    
    // check if the list is empty
    if(listEmpty(list))
        return;

    // remove the node
    Node* current = list->head;
    while(current != NULL) {
        if(current == node) {
            // if the removed node is the head node, we updated the head of the list and free the node
            if(current == list->head) 
                list->head = current->next;
            else {
                // otherwise we will check if it is the final node
                current->prev->next = current->next;
                if(current->next != NULL)
                    current->next->prev = current->prev;
            }
            free(current);
            break;
        } else 
            current = current->next;
    }
}

void loadTextFile(DLL* list, char* filename) {
    // open the file
    FILE* fp;
    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error opening file for reading: %s\n", filename);
        return;
    }
    // insert node from the file
    char line[20];
    while(fgets(line, sizeof(line), fp) != NULL) {
        line[strcspn(line, "\n")] = '\0';
        Node* new_node = createNode(line);
        insert(list, new_node);
    }
    // close the file
    fclose(fp);
}

void storeTextFile(DLL* list, char* filename) {
    // opening the file
    FILE* fp;
    fp = fopen(filename, "w");
    if(fp == NULL) {
        printf("Error opening file for writing: %s\n", filename);
        return;
    }
    // check if the double linked list is empty
    if(listEmpty(list)) {
        puts("There is nothing to write to the file.");
        fclose(fp);
        return;
    }
    // write data to the file
    Node* current = list->head;
    while(current != NULL) {
        fprintf(fp, "%s\n", current->data);
        current = current->next;
    }
    // close the file
    fclose(fp);
}

void freeList(DLL* list) {
    Node* current = list->head;
    while(current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
        temp = NULL;
    }
    free(list);
    list = NULL;
}