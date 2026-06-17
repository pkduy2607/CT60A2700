#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    float score;
} Student;

Student* create_student(char* name, float score) {
    Student* new_student = (Student*)malloc(sizeof(Student));
    if(new_student == NULL) {
        puts("Memory allocation failed.");
        return NULL;
    }
    strcpy(new_student->name, name);
    new_student->score = score;
    return new_student;
}

float average(Student** students, size_t n) {
    float total = 0;
    for(size_t i = 0; i < n; i++)
        total += students[i]->score;
    return total / n; 
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    Student** students = (Student**)malloc(n * sizeof(Student));
    if(students == NULL) {
        puts("Memory allocation failed.");
        return 1;
    }

    for(int i = 1; i <= 3; i++) {
        char name[50];
        printf("Enter name for student %d: ", i);
        scanf("%50s", name);
        float score;
        printf("Enter score for student %d: ", i);
        scanf("%f", &score);
        Student* student = create_student(name, score);
        students[i - 1] = student;
    }

    printf("\nThe average score of %d students is: %.2f\n", n, average(students, n));
    
    for(int i = 0; i < n; i++) 
        free(students[i]);
    free(students);

    return 0;
}