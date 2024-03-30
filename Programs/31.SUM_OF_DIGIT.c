#include <stdio.h>

int main() {
    int number, sum = 0, digit;

    // Input from user
    printf("Enter a number: ");
    scanf("%d", &number);

    // Calculate sum of digits
    while (number != 0) {
        digit = number % 10; // Extract the last digit
        sum += digit; // Add the last digit to sum
        number /= 10; // Remove the last digit from the number
    }

    // Output the sum
    printf("Sum of digits: %d\n", sum);

    return 0;
}

