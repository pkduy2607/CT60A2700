#include <stdio.h>
#include <string.h>

int main() {
    char str[200];
    printf("Please enter a string:\n");
    fgets(str, 200, stdin);
    str[strcspn(str, "\n")] = '\0';
    printf("Splitting the string by vowels:\n");
    char delim[] = "aeiouAEIOU";
    char *token = strtok(str, delim);
    while(token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, delim);
    }

    return 0;
}