#include <stdio.h>

void strassen(int A[2][2], int B[2][2], int C[2][2]) {
    int P[7], i, A1, A2, B1, B2;

    P[0] = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
    P[1] = (A[1][0] + A[1][1]) * B[0][0];
    P[2] = A[0][0] * (B[0][1] - B[1][1]);
    P[3] = A[1][1] * (B[1][0] - B[0][0]);
    P[4] = (A[0][0] + A[0][1]) * B[1][1];
    P[5] = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
    P[6] = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);

    C[0][0] = P[0] + P[3] - P[4] + P[6];
    C[0][1] = P[2] + P[4];
    C[1][0] = P[1] + P[3];
    C[1][1] = P[0] - P[1] + P[2] + P[5];
}

void display(int M[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[2][2], B[2][2], C[2][2];

    printf("Enter elements of matrix A (2x2):\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of matrix B (2x2):\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    strassen(A, B, C);

    printf("Resultant Matrix:\n");
    display(C);

    return 0;
}
