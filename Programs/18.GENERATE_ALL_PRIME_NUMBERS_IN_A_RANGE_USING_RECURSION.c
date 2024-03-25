#include <stdio.h>
#include <stdbool.h>
bool isPrime(int n, int i) {
    if (n <= 2)
        return (n == 2) ? true : false;
    if (n % i == 0)
        return false;
    if (i * i > n)
        return true;
    
    return isPrime(n, i + 1);
}

void printPrimes(int start, int end) {
    if (start > end)
        return;
    
    if (isPrime(start, 2))
        printf("%d ", start);
    
    printPrimes(start + 1, end);
}

int main() {
    int start, end;

    printf("Enter the starting range: ");
    scanf("%d", &start);

    printf("Enter the ending range: ");
    scanf("%d", &end);

    printf("Prime numbers between %d and %d are: ", start, end);
    printPrimes(start, end);

    return 0;
}
