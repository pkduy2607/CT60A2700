#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* first;
    Node* last;
} List;

List* create() {
    List* L = (List*)malloc(sizeof(List));
    if(L == NULL) {
        puts("Memory allocation failed.");
        return NULL;
    }
    L->first = NULL;
    L->last = NULL;
    return L;
}

void add(List* L, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL) {
        puts("Memory allocation failed.");
        return;
    }
    new_node->data = value;
    new_node->next = NULL;
    if(L->first == NULL) {
        L->first = new_node;
        L->last = new_node;
    } else {
        L->last->next = new_node;
        L->last = new_node;
    }
}

void reverse(List* L) {
    if(L->first == NULL)
        return;
    
    Node* old_first = L->first;
    Node* current = L->first;
    Node* previous = NULL;
    while(current != NULL) {
        Node* temp = current->next;
        current->next = previous;
        previous = current;
        current = temp;
    }
    
    L->first = previous;
    L->last = old_first;
}

void print_list(List* L) {
    Node* ptr = L->first;
    while(ptr->next != NULL) {
        printf(" %d ->", ptr->data);
        ptr = ptr->next;
    }
    printf(" %d\n", ptr->data);
}

int main() {
    int n;
    printf("Enter the number of integers: ");
    scanf("%d", &n);
    List* L = create();

    printf("Enter %d integers: ", n);
    for(int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        add(L, x);
    }

    printf("Original list:");
    print_list(L);
    reverse(L);
    printf("Reversed list:");
    print_list(L);

    Node* current = L->first;
    while(current != NULL) {
        Node* tmp = current;
        current = current->next;
        free(tmp);
    }
    free(L);

    return 0;
}