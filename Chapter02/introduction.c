#include <stdio.h>

int main() {
    char name[10];
    int age;
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter age: ");
    scanf("%d", &age);
    printf("Hello, %s! You are %d years old.\n", name, age);

    return 0;
}