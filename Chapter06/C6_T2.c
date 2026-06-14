#include <stdio.h>
#include <stdlib.h>

int main() {
    int sz = 4;
    int* data = (int*)malloc(sz * sizeof(int));
    if(data == NULL) {
        puts("Memory allocation failed!");
        return 1;
    }

    int n, index = 0;
    puts("Enter numbers (enter -1 to stop):");
    do {
        puts("Enter a number");
        scanf("%d", &n);
        *(data + index) = n;
        index++;
        if(index >= sz * 75 / 100) {
            sz *= 2;
            data = (int*)realloc(data, sz * sizeof(int));
            if(data == NULL) {
                puts("Memory allocation failed!");
                return 1;
            } else 
                printf("The array size increase to %d.\n", sz);
        }
    } while(n != -1);
    puts("");

    index--;
    printf("Final array (with %d elements):", index);
    for(int i = 0; i < index; i++) 
        printf(" %d", *(data + i));
    puts("");

    free(data);

    return 0;
}