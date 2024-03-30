#include <stdio.h>

// Function to print the pattern recursively
void printPattern(int n, int i) {
    // Base case: If i becomes greater than n, return
    if (i > n)
        return;

    // Print numbers from 1 to i
    for (int j = 1; j <= i; j++) {
        printf("%d ", j);
    }
    printf("\n");

    // Recursive call to print the next line
    printPattern(n, i + 1);
}

int main() {
    int n;
    printf("Enter the number of lines for the pattern: ");
    scanf("%d", &n);

    // Call the function to print the pattern recursively
    printPattern(n, 1);

    return 0;
}

