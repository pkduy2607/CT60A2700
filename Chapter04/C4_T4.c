#include <stdio.h>
#include <string.h>

void swapElements(char str[], int index1, int index2) {
    char tmp = str[index1];
    str[index1] = str[index2];
    str[index2] = tmp;
}

int main() {
    char str[100];
    int st, nd;
    printf("Enter a string\n");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';
    printf("Enter first index:\n");
    scanf("%d", &st);
    printf("Enter second index:\n");
    scanf("%d", &nd);
    if(0 <= st && st < strlen(str) && 0 <= nd && nd < strlen(str)) {
        swapElements(str, st, nd);
        printf("Modified string: %s\n", str);
    } else 
        printf("Indices are out of bounds.\n");
    
    return 0;
}