#include<stdio.h>

// Function to check if a number is perfect
int isPerfect(int num) {
    int sum = 0;

    // Calculate the sum of factors of the number
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }

    // Check if the sum of factors equals the original number
    if (sum == num) {
        return 1; // The number is perfect
    } else {
        return 0; // The number is not perfect
    }
}

int main() {
    int n;
    
    printf("Enter a number: ");
    scanf("%d", &n);

    if (isPerfect(n)) {
        printf("%d is a perfect number.\n", n);
    } else {
        printf("%d is not a perfect number.\n", n);
    }

    return 0;
}

