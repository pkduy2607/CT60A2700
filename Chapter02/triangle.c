#include <stdio.h>

int main() {
    int height;
    printf("Enter triangle height: ");
    scanf("%d", &height);
    for(int i = 1; i < height; i++) {
        for(int j = 1; j <= height - i; j++)
            putchar(' ');
        for(int j = 1; j <= i; j++)
            putchar('*');
        putchar('\n');
    }

    return 0;
}