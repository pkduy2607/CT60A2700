#include <stdio.h>

void Swap(int* pi1, int* pi2);

void BubbleSort(int a[], const size_t n) {
    for(int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for(int j = 0; j < n - i - 1; j++) {
            if(a[j] > a[j + 1]) {
                Swap(&a[j], &a[j + 1]);
                swapped++;
            }
        }
        if(!swapped)
            break;
    }
}

int main() {
    int arr[] = {42, 717, 52, 510, 500, 57, 56, 71, 345, 200, 788, 20};
    puts("Initial array:");
    for(int i = 0; i < 12; i++) 
        printf("%d ", arr[i]);
    puts("");
    BubbleSort(arr, (size_t)sizeof(arr) / sizeof(arr[0]));
    puts("Sorted array:");
    for(int i = 0; i < 12; i++) 
        printf("%d ", *(arr + i));
    puts("");

    return 0;
}