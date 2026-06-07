#include <stdio.h>

int main() {
    printf("unsigned char is %zu bytes\n", sizeof(unsigned char));
    printf("char is %zu bytes\n", sizeof(char));
    printf("int is %zu bytes\n", sizeof(int));
    printf("unsigned int is %zu bytes\n", sizeof(unsigned int));
    printf("long is %zu bytes\n", sizeof(long));
    printf("unsigned long is %zu bytes\n", sizeof(unsigned long));
    printf("long long is %zu bytes\n", sizeof(long long));
    printf("unsigned long long is %zu bytes\n", sizeof(unsigned long long));
    printf("float is %zu bytes\n", sizeof(float));
    printf("double is %zu bytes\n", sizeof(double));
    printf("long double is %zu bytes\n", sizeof(long double));
    printf("int* is %zu bytes\n", sizeof(int*));
    printf("long long* is %zu bytes\n", sizeof(long long*));
    printf("float* is %zu bytes\n", sizeof(float*));
    printf("double* is %zu bytes\n", sizeof(double*));

    return 0;
}