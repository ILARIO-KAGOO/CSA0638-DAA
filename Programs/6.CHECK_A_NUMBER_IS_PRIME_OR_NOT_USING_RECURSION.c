#include <stdio.h>

int isPrime(int num, int i) {
    if (num <= 2) return (num == 2) ? 1 : 0;
    if (num % i == 0) return 0;
    return (i * i > num) ? 1 : isPrime(num, i + 1);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("%d is %sprime.\n", num, (isPrime(num, 2) ? "" : "not "));

    return 0;
}

