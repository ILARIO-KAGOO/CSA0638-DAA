#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

void multiplyMatrix(int mat1[N][N], int mat2[N][N], int res[N][N], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            res[i][j] = 0;
            for (int k = 0; k < size; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int mat1[N][N], mat2[N][N], res[N][N];

    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mat1[i][j] = rand() % 10;
            mat2[i][j] = rand() % 10;
        }
    }

    clock_t start = clock();
    multiplyMatrix(mat1, mat2, res, N);
    clock_t end = clock();

    double time_taken = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Time taken for matrix multiplication: %f seconds\n", time_taken);

    return 0;
}

