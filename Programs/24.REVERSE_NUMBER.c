#include<stdio.h>

// Function to find the reverse of a number recursively
int reverseNumber(int num, int rev)
{
    // Base case: if the number becomes 0, return the reverse
    if (num == 0)
        return rev;
    else {
        // Extract the last digit of the number
        int digit = num % 10;
        // Update the reverse number
        rev = rev * 10 + digit;
        // Recursive call with the remaining digits
        return reverseNumber(num / 10, rev);
    }
}

int main()
{
    int num, reversed;

    // Input the number from the user
    printf("Enter a number: ");
    scanf("%d", &num);

    // Call the function to find the reverse of the number
    reversed = reverseNumber(num, 0);

    // Output the reversed number
    printf("Reverse of the number: %d\n", reversed);

    return 0;
}

