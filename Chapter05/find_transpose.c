#include <stdio.h>

void FindTranspose(long double* pldbl, const size_t nRows, const size_t nCols) {
    long double tmp[nCols][nRows];
    for(size_t i = 0; i < nRows; i++) {
        for(size_t j = 0; j < nCols; j++) {
            tmp[j][i] = pldbl[i * nCols + j];
        }
    }
    for(size_t i = 0; i < nCols; i++) {
        for(size_t j = 0; j < nRows; j++) {
            pldbl[i * nRows + j] = tmp[i][j];
        }
    }
}

int main() {
    long double matrix[] = {1, 2, 3,
                            4, 5, 6};
    FindTranspose(matrix, 2, 3);
    for(size_t i = 0; i < 3; i++) {
        for(size_t j = 0; j < 2; j++) 
            printf("%.1Lf ", matrix[i * 2 + j]);
        puts("");
    }

    return 0;
}