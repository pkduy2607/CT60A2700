#include <stdio.h>
#include <stdlib.h>
#define INF 1e9 + 7;
#define MAX(a, b) ((a) > (b) ? (a) : (b))

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

int find_max(List* L) {
    int res = -INF;
    Node* current = L->first;
    while(current != NULL) {
        res = MAX(res, current->data);
        current = current->next;
    }
    return res;
}

int main() {
    int n;
    printf("Enter the number of integers: ");
    scanf("%d", &n);
    List* L = create();

    printf("Enter %d integers:\n", n);
    for(int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        add(L, x);
    }

    printf("\nThe maximum value is: %d\n", find_max(L));
    Node* current = L->first;
    while(current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(L);

    return 0;
}