#include <stdio.h>

int main() {
    FILE* fp;
    fp = fopen("chap6_task4_output.txt", "w");
    if(fp == NULL) {
        puts("Error opening file for writing!");
        return 1;
    }

    char choice = 'y';
    do {
        puts("Enter name (without spaces):");
        char name[20];
        scanf("%s", name);
        puts("Enter age:");
        int age;
        scanf("%d", &age);
        puts("Enter gender:");
        char gender[20];
        scanf("%s", gender);
        puts("Do you want to add another person? (y/n):");
        scanf(" %c", &choice);
        fprintf(fp, "%s,%d,%s\n", name, age, gender);
    } while(choice == 'y');
    fclose(fp);
    puts("Data saved successfully to chap6_task4_output.txt");

    return 0;
}