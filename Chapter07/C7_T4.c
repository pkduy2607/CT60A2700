#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

Queue* create_queue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if(q == NULL) {
        puts("Memory allocation failed.");
        return NULL;
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enQueue(Queue* q) {
    int value;
    printf("Enter value: ");
    scanf("%d", &value);

    Node* new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL) {
        puts("Memory allocation failed.");
        return;
    }
    new_node->data = value;
    new_node->next = NULL;

    if(q->front == NULL) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
    printf("Enqueued: %d\n", value);
}

void deQueue(Queue* q) {
    Node* temp = q->front;
    int value = q->front->data;
    q->front = q->front->next;
    if(q->front == NULL) 
        q->rear = NULL;
    free(temp);
    printf("Dequeued: %d\n", value);
}

void printQueue(Queue* q) {
    Node* current = q->front;
    printf("Queue:");
    while(current != NULL) {
        printf(" %d", current->data);
        current = current->next;
    }
    puts("");
}

int main() {
    Queue* q = create_queue();
    int state = 1;
    while(state) {
        puts("Menu:");
        puts("1. Enqueue");
        puts("2. Dequeue");
        puts("3. Print Queue");
        puts("4. Quit");
        printf("Choose an option: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            enQueue(q);
            break;
        
        case 2:
            deQueue(q);
            break;
        
        case 3:
            printQueue(q);
            break;
        
        case 4: 
            printf("Exiting program.\n");
            state = 0;
            break;
        
        default:
            puts("Invalid option!");
            break;
        }
    }

    Node* current = q->front;
    while(current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(q);

    return 0;
}