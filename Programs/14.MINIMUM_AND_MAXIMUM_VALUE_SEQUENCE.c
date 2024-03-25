#include <stdio.h>

int main() {
    int length;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &length);

    int numbers[length];

    printf("Enter %d numbers:\n", length);
    for (int i = 0; i < length; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }
    
    int min = numbers[0];
    int max = numbers[0];

    for (int i = 1; i < length; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }

    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);

    return 0;
}

