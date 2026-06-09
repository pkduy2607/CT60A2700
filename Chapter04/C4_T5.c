#include <stdio.h>

char asciiToChar(int asciiValue) {
    return (char)asciiValue;
}

int charToAscii(char c) {
    return (int)c;
}

int main() {
    int choice;
    while(1) {
        puts("Menu:");
        puts("1. Convert ASCII value to character");
        puts("2. Convert character to ASCII value");
        puts("0. Exit");
        
        puts("Enter your choice:");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                int asciivalue;
                puts("Enter an ASCII value:");
                scanf("%d", &asciivalue);
                printf("The character for ASCII value %d is '%c'.\n", asciivalue, asciiToChar(asciivalue));
                break;
            
            case 2:
                char c;
                puts("Enter a character:");
                scanf(" %c", &c);
                printf("The ASCII value for character '%c' is %d.\n", c, charToAscii(c));
                break;
            
            case 0:
                puts("Exiting the program. Goodbye!");
                return 0;
            
            default: 
                puts("Invalid choice!");
                break;
        }
        puts("");
    }
}