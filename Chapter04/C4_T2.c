#include <stdio.h>
#include <string.h>

void reverseString(char str[]) {
    int l = 0, r = strlen(str) - 1;
    while(l < r) {
        char tmp = str[l];
        str[l] = str[r];
        str[r] = tmp;
        l++;
        r--;
    }
}

int main() {
    char inputStr[100];

    printf("Enter a string:\n");
    fgets(inputStr, sizeof(inputStr), stdin);
    inputStr[strcspn(inputStr, "\n")] = '\0';

    reverseString(inputStr);
    printf("Reversed string: %s\n", inputStr);

    return 0;
}