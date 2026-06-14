#include <stdio.h>
#include <stdlib.h>

int main() {
    char* line = NULL;
    size_t len = 0;
    long read;

    puts("Welcome to the Echo Machine! (Press Ctrl + D to finish)");
    puts("Please enter anything:");
    while((read = getline(&line, &len, stdin)) != -1) {
        printf("You entered: %s\n", line);
        puts("Please enter anything:");
    }
    free(line);

    return 0;
}
