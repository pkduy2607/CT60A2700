#include <stdio.h>

int main() {
    double width, height;
    printf("Width: ");
    scanf("%le", &width);
    printf("Height: ");
    scanf("%le", &height);
    printf("Area: %le\n", width * height);

    return 0;
}