#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bst.h"
#include "dll.h"

// function to deal with input
void getInput(char* buffer) {
    char input[20];
    while(1) {
        printf("Enter a string: ");
        if(fgets(input, sizeof(input), stdin) != NULL) {
            input[strcspn(input, "\n")] = '\0';
            if(strlen(input) > 0)
                break;
        }
        puts("Invalid string.");
    }
    strcpy(buffer, input);
}

void getFilename(char* buffer) {
    char input[20];
    printf("Enter filename: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    strcpy(buffer, input);
}

int main() {
    // declaration
    BST* tree = createTree();
    DLL* doubleLinkedList = createList();
    char input[20], start_char;
    int choice;
    // main loop
    while(1) {
        // print the menu
        puts("--- DLL operations ---");
        puts("11. Insert a string into the list");
        puts("12. Filter by initial letter in the list");
        puts("13. Search for a word in the list");
        puts("14. Delete a word from the list");
        puts("15. Load a file into the list");
        puts("16. Store the list to a file\n");
        puts("--- BST operations ---");
        puts("21. Insert a string into the tree");
        puts("22. Filter by initial letter in the tree");
        puts("23. Search for a word in the tree");
        puts("24. Delete a word from the tree");
        puts("25. Load a file into the tree");
        puts("26. Store the tree to a file\n");
        puts("0. Free the memory and exit");
        printf("Enter your choice: ");
        // get the choice of the user
        scanf("%d", &choice);
        // switch case to perform operations
        switch(choice) {
            case 11: // insert a new node to the list
                getInput(input);
                Node* new_list_node = createNode(input);
                insert(doubleLinkedList, new_list_node);
                break;
            
            case 12: // filter the list by the initial letter
                printf("Enter a character: ");
                scanf(" %c", &start_char);
                displayList(doubleLinkedList, start_char);
                break;
            
            case 13: // search for a word in the list
                getInput(input);
                Node* list_search_res = search(doubleLinkedList, input);
                if(list_search_res == NULL) 
                    puts("String not found.");
                else 
                    printf("The address is: %p\n", list_search_res);
                break;
            
            case 14: // delete a word in the list
                getInput(input);
                Node* list_delete_res = search(doubleLinkedList, input);
                if(list_delete_res == NULL) 
                    printf("Cannot delete the %s string in the list\n", input);
                else {
                    Remove(doubleLinkedList, list_delete_res);
                    printf("Deleted the node with string %s\n", input);
                }
                break;
            
            case 15: // load a file into a list
                getFilename(input);
                loadTextFile(doubleLinkedList, input);
                break;
            
            case 16: // save text to the file
                getFilename(input);
                storeTextFile(doubleLinkedList, input);
                break;

            case 21: // insert a word into the tree
                getInput(input);
                TNode* new_node = createTNode(input);
                bstInsert(tree, new_node);
                break;

            case 22: // filter the tree by initial character 
                printf("Enter a character: ");
                scanf(" %c", &start_char);
                printAlphabetical(tree, start_char);
                break;
            
            case 23: // search for a word in tree
                getInput(input);
                TNode* BST_search_res = Tsearch(tree, input);
                if(BST_search_res == NULL)
                    puts("String not found.");
                else 
                    printf("The address is %p\n", BST_search_res);
                break;
            
            case 24: // delete a word from the tree
                getInput(input);
                TRemove(tree, input);
                break;
            
            case 25: // load a file into a tree
                getFilename(input);
                TloadTextFile(tree, input);
                break;
            
            case 26: // store the tree into a file
                getFilename(input);
                TstoreTextFile(tree, input);
                break;
            
            case 0:
                freeList(doubleLinkedList);
                freeTree(tree);
                puts("Goodbye!\n");
                return 0;

            default:
                puts("Invalid choice.");
                break;
        }
    }
}