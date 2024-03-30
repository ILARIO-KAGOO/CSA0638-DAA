#include <stdio.h>
#define N 10 // Maximum value of N

void printSolution(int board[N][N], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}

int isSafe(int board[N][N], int row, int col, int size) {
    int i, j;

    // Check this row on left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return 0;

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < size; i++, j--)
        if (board[i][j])
            return 0;

    return 1;
}

int solveNQUtil(int board[N][N], int col, int size) {
    if (col >= size)
        return 1;

    for (int i = 0; i < size; i++) {
        if (isSafe(board, i, col, size)) {
            board[i][col] = 1;

            if (solveNQUtil(board, col + 1, size))
                return 1;

            board[i][col] = 0; // Backtrack
        }
    }

    return 0;
}

int solveNQ(int size) {
    int board[N][N];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j] = 0; // Initialize the board
        }
    }

    if (solveNQUtil(board, 0, size) == 0) {
        printf("Solution does not exist\n");
        return 0;
    }

    printf("Solution exists!\n");
    printSolution(board, size);
    return 1;
}

int main() {
    int size;
    printf("Enter the size of the chessboard (N): ");
    scanf("%d", &size);

    if (size <= 0 || size > N) {
        printf("Invalid size of the chessboard.\n");
        return 1;
    }

    solveNQ(size);
    return 0;
}

