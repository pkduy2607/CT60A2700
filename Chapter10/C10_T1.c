#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toUpperCase(char *str) {
    for(int i = 0; i < strlen(str); i++) 
        str[i] = toupper((unsigned char)str[i]);
}

void toLowerCase(char *str) {
    for(int i = 0; i < strlen(str); i++) 
        str[i] = tolower((unsigned char)str[i]);
}

int main() {
    char str[50];
    puts("Enter a string:");
    fgets(str, 50, stdin);
    puts("Choose operation:");
    puts("1. Uppercase");
    puts("2. Lowercase");
    puts("Enter your choice:");
    int choice;
    scanf("%d", &choice);

    void (*stringFunctions[])(char*) = {toUpperCase, toLowerCase};
    if(choice == 1 || choice == 2) {
        stringFunctions[choice - 1](str);
        printf("Processed String: %s\n", str);
    } else 
        puts("Invalid choice!");
    
    return 0;
}