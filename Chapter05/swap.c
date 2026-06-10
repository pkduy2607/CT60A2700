#include <stdio.h>

void Swap(int* pi1, int* pi2) {
    int tmp = *pi1;
    *pi1 = *pi2;
    *pi2 = tmp;
}

/*int main() {
    int a = 14900, b = 13900;
    printf("Before: A = %d, B = %d\n", a, b);
    Swap(&a, &b);
    printf("After: a = %d, b = %d\n", a, b);

    return 0;
}*/