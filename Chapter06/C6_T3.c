#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE* fp;
    char* line = NULL;
    size_t len = 0;
    long read;
    char filename[50];

    puts("Enter the file name to be read:");
    scanf("%49s", filename);
    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error opening file: %s\n", filename);
        return 1;
    }
    puts("Reading csv file...");

    getline(&line, &len, fp);
    while((read = (long)getline(&line, &len, fp)) != -1) {
        line[strcspn(line, "\r\n")] = '\0';
        char* value = strtok(line, ",");

        int birth_year = atoi(value);
        int age_in_2100 = 2100 - birth_year;

        value = strtok(NULL, ",");
        char first_name[20];
        strcpy(first_name, value);

        value = strtok(NULL, ",");
        char last_name[20];
        strcpy(last_name, value);

        value = strtok(NULL, ",");
        char gender[20];
        strcpy(gender, value);

        printf("Name: %s %s, Gender: %s, Birth year: %d, Age in 2100: %d\n", first_name, last_name, gender, birth_year, age_in_2100);
    }
    fclose(fp);
    free(line);

    return 0;
}