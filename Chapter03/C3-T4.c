#include <stdio.h>
#include <string.h>

int main() {
    char str[200];
    int cnt = 0;
    printf("Enter a sentence:\n");
    fgets(str, 200, stdin);
    str[strcspn(str, "\n")] = '\0';
    for(int i = 0; i < strlen(str); i++) {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
            cnt++;
    }
    printf("Number of vowels: %d\n", cnt);
    printf("Number of characters: %ld\n", strlen(str));

    return 0;
}