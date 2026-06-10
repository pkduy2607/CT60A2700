#include <stdio.h>
#include <complex.h>

void MatMul(const double Mat1[2][2], const double Mat2[2][2], double ResMat[2][2]);
void ComplexToMatrix(const double complex z, double Matrix[2][2]);

int main() {
    double a, b;
    printf("First complex number: ");
    scanf("%lf + %lfi", &a, &b);
    double complex x = a + b * I;
    printf("Second complex number: ");
    scanf("%lf + %lfi", &a, &b);
    double complex y = a + b * I;
    
    double mat_x[2][2];
    ComplexToMatrix(x, mat_x);
    double mat_y[2][2];
    ComplexToMatrix(y, mat_y);
    double res_mat[2][2];
    MatMul(mat_x, mat_y, res_mat);
    
    printf("[ %lf %lf ]\n", res_mat[0][0], res_mat[0][1]);
    printf("[ %lf %lf ]\n", res_mat[1][0], res_mat[1][1]);

    return 0;
}