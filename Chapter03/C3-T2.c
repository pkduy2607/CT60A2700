#include <stdio.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int n, cnt = 0, maximum = 0, total = 0;
    printf("Enter positive integers (0 to stop):\n");
    do {
        scanf("%d", &n);
        cnt++;
        maximum = MAX(maximum, n);
        total += n;
    } while(n != 0);
    cnt--;
    printf("Count: %d\n", cnt);
    printf("Maximum: %d\n", maximum);
    printf("Average: %.2f\n", (float)total / cnt);

    return 0;
}