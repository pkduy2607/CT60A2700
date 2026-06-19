#include <stdio.h>
#include <string.h>

typedef struct Student {
    char name[10];
    int marks[5]; // Array to store marks in 5 subjects
    void (*show)(struct Student);
    float (*countGPA)(struct Student);
} Student;

void show(Student s) {
    printf("Student Name: %s\n", s.name);
    puts("Student's grade:");
    for(int i = 1; i <= 5; i++) 
        printf("Course %d: %d\n", i, s.marks[i - 1]);
}

float countGPA(Student s) {
    float total = 0;
    for(int i = 0; i < 5; i++) 
        total += s.marks[i];
    return total / 5;
}

void ConstructStudent(Student* s) {
    puts("Enter student name:");
    scanf("%10s", s->name);
    s->name[strcspn(s->name, "\n")] = '\0';
    puts("Enter grade for 5 courses.");
    for(int i = 1; i <= 5; i++) {
        printf("Course %d:\n", i);
        scanf("%d", &s->marks[i - 1]);
    }
    s->countGPA = countGPA;
    s->show = show;
    puts("");
}

int main() {
    Student s1;
    ConstructStudent(&s1);
    s1.show(s1);
    printf("GPA: %.2f\n", s1.countGPA(s1));

    return 0;
}