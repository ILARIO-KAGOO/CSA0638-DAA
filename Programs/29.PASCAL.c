#include <stdio.h>

// Function to calculate the factorial of a number
unsigned long long factorial(int n) {
    unsigned long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function to calculate the value of a binomial coefficient (n choose k)
unsigned long long binomialCoefficient(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

// Function to print Pascal's Triangle
void printPascalTriangle(int numRows) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%llu ", binomialCoefficient(i, j));
        }
        printf("\n");
    }
}

int main() {
    int numRows;

    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &numRows);

    // Call the function to print Pascal's Triangle
    printPascalTriangle(numRows);

    return 0;
}

