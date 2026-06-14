#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int birthYear;
    char firstName[50];
    char lastName[50];
    char gender[20];
} Person;

void sortRecordsByBirthYear(Person people[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (people[j].birthYear > people[j + 1].birthYear) {
                Person temp = people[j];
                people[j] = people[j + 1];
                people[j + 1] = temp;
            }
        }
    }
}

int main() {
    FILE* fp;
    char* line = NULL;
    size_t len = 0, recordCount = 0;
    long read;
    char filename[50];
    Person people[100];

    puts("Enter filename to be read: ");
    scanf("%49s", filename);
    fp = fopen(filename, "r");
    puts("");
    if(fp == NULL) {
        printf("Error opening file: %s\n", filename);
        return 1;
    }
    puts("Reading CSV file...\n");

    getline(&line, &len, fp);
    while((read = (long)getline(&line, &len, fp)) != -1) {
        line[strcspn(line, "\r\n")] = '\0';
        char* value = strtok(line, ",");
        people[recordCount].birthYear = atoi(value);
        value = strtok(NULL, ",");
        strcpy(people[recordCount].firstName, value);
        value = strtok(NULL, ",");
        strcpy(people[recordCount].lastName, value);
        value = strtok(NULL, ",");
        strcpy(people[recordCount].gender, value);
        recordCount++;
    }

    fclose(fp);
    free(line);

    sortRecordsByBirthYear(people, recordCount);
    printf("\nSorted Records (by Birth Year):\n");
    for (int i = 0; i < recordCount; i++) 
        printf("Birth Year: %d, Name: %s %s, Gender: %s\n", people[i].birthYear, people[i].firstName, people[i].lastName, people[i].gender);
    return 0;
}