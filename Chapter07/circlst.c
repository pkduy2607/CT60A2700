#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int iData;
    struct Node* pNext;
} Node;

typedef struct {
    Node* pHead;
    size_t n;
} CircularList;

void InitList(CircularList* pList) {
    pList->pHead = NULL;
    pList->n = 0;
}

void FreeList(CircularList* pList) {
    Node* current = pList->pHead->pNext;
    while(current != pList->pHead) {
        Node* tmp = current;
        current = current->pNext;
        free(tmp);
    }
    free(current);
    free(pList);
}

void InsertEnd(CircularList* pList, const int iValue) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->iData = iValue;
    if(pList->n == 0) {
        new_node->pNext = new_node;
        pList->pHead = new_node;
    } else {
        Node* current = pList->pHead;
        while(current->pNext != pList->pHead) 
            current = current->pNext;
        current->pNext = new_node;
        new_node->pNext = pList->pHead;
    }
    pList->n++;
}

float ComputeAverage(const CircularList* pList) {
    if(pList->n == 0)
        return 0.0;
    float total = 0;
    Node* current = pList->pHead;
    while(current->pNext != pList->pHead) {
        total += current->iData;
        current = current->pNext;
    }
    return total / pList->n;
}

size_t DeleteLt(CircularList* pList, const int iValue) {
    // nếu như list rỗng
    if(pList->n == 0) 
        return 0;

    // bắt đầu xóa từ node đầu tiên, nếu mà cần xóa thì sẽ nối 
    // node trước nó với node sau nó
    Node* previous = pList->pHead;
    while(previous->pNext != pList->pHead) 
        previous = previous->pNext;
    Node* current = pList->pHead;
    int initial_n = pList->n;
    size_t cnt = 0;
    // 1 list có thể cần xóa tối đa pList->n lần
    for(size_t i = 0; i < initial_n; i++) {
        if(current->iData < iValue) {
            Node* tmp = current;
            
            // chỉ còn 1 node duy nhất
            if(pList->n == 1) {
                pList->pHead = NULL;
                pList->n = 0;
                free(tmp);
                return ++cnt;
            }
            // bỏ qua node hiện tại
            previous->pNext = current->pNext;
            // nếu node head cần xóa thì cập nhật lại node head
            if(current == pList->pHead)
                pList->pHead = current->pNext;
            
            current = current->pNext;
            free(tmp);
            pList->n--;
            cnt++;
        } else {
            previous = current;
            current = current->pNext;
        }
    }

    return cnt;
}

int main() {
    CircularList* circular_l = (CircularList*)malloc(sizeof(CircularList));
    if(circular_l == NULL) {
        puts("Memory allocation failed.");
        return 1;
    }
    InitList(circular_l);

    InsertEnd(circular_l, 4600);
    InsertEnd(circular_l, 4800);
    InsertEnd(circular_l, 5600);
    InsertEnd(circular_l, 5800);
    InsertEnd(circular_l, 5900);
    InsertEnd(circular_l, 6600);
    InsertEnd(circular_l, 6800);
    InsertEnd(circular_l, 6900);
    InsertEnd(circular_l, 7235);
    InsertEnd(circular_l, 7435);
    InsertEnd(circular_l, 7535);
    InsertEnd(circular_l, 7735);
    InsertEnd(circular_l, 7840);
    InsertEnd(circular_l, 7645);
    InsertEnd(circular_l, 7745);
    InsertEnd(circular_l, 7845);
    InsertEnd(circular_l, 7945);
    InsertEnd(circular_l, 8745);
    InsertEnd(circular_l, 8845);
    InsertEnd(circular_l, 8940);
    InsertEnd(circular_l, 8945);
    InsertEnd(circular_l, 9955);

    printf("Average: %.2f\n", ComputeAverage(circular_l));
    printf("Deleted node: %lu\n", DeleteLt(circular_l, 7840));
    printf("Average: %.2f\n", ComputeAverage(circular_l));
    FreeList(circular_l);

    return 0;
}