#include <stdio.h>
#include <complex.h>

void ComplexToMatrix(const double complex z, double Matrix[2][2]) {
    double a = creal(z);
    double b = cimag(z);

    Matrix[0][0] = a;
    Matrix[0][1] = -b;
    Matrix[1][0] = b;
    Matrix[1][1] = a;
}

/*int main() {
    double complex my_z = 7.0 + 5.0 * I;
    double myMatrix[2][2];

    ComplexToMatrix(my_z, myMatrix);
    printf("Complex number: = %.1f + %.1fi\n", creal(my_z), cimag(my_z));
    puts("Matrix number:");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) 
            printf("%6.1f", myMatrix[i][j]);
        puts("");
    }

    return 0;
}*/