#include <stdio.h>

int main() {
    int n, sum = 0;
    printf("Give the integer:\n");
    scanf("%d", &n);
    while(n > 0) {
        int d = n % 10;
        n /= 10;
        if(d == 4)
            continue;
        else if(d == 8)
            break;
        else
            sum += d * d;
    }
    printf("The summation is %d.\n", sum);

    return 0;
}