#include <stdio.h>

void MatMul(const double Mat1[2][2], const double Mat2[2][2], double ResMat[2][2]) {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            ResMat[i][j] = 0;
            for(int k = 0; k < 2; k++) 
                ResMat[i][j] += Mat1[i][k] * Mat2[k][j];
        }
    }
}

/*void printMatrix(const double Matrix[2][2]) {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++)
            printf("%6f ", Matrix[i][j]);
        puts("");
    }
}

int main() {
    double myMat1[2][2] = {{1.1, 2.2}, {3.3, 4.4}}, myMat2[2][2] = {{5.5, 6.6}, {7.7, 8.8}}, myResMat[2][2];
    MatMul(myMat1, myMat2, myResMat);
    puts("Matrix 1:");
    printMatrix(myMat1);
    puts("Matrix 2:");
    printMatrix(myMat2);
    puts("Matrix result of the multiplication of matrix 1 and 2:");
    printMatrix(myResMat);

    return 0;
}*/