#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value;
    int weight;
};

int compare(const void *a, const void *b) {
    double ratioA = (double)(((struct Item *)a)->value) / ((struct Item *)a)->weight;
    double ratioB = (double)(((struct Item *)b)->value) / ((struct Item *)b)->weight;

    if (ratioA > ratioB)
        return -1;
    else if (ratioA < ratioB)
        return 1;
    else
        return 0;
}


double fractionalKnapsack(int W, struct Item arr[], int n) {

    qsort(arr, n, sizeof(arr[0]), compare);

    int currentWeight = 0; 
    double finalValue = 0.0; 

    for (int i = 0; i < n; i++) {

        if (currentWeight + arr[i].weight <= W) {
            currentWeight += arr[i].weight;
            finalValue += arr[i].value;
        } else {
        
            int remainingWeight = W - currentWeight;
            finalValue += arr[i].value * ((double)remainingWeight / arr[i].weight);
            break; 
        }
    }

    return finalValue;
}

int main() {
    int W;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item *arr = (struct Item *)malloc(n * sizeof(struct Item));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the values and weights of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d value: ", i + 1);
        scanf("%d", &arr[i].value);
        printf("Item %d weight: ", i + 1);
        scanf("%d", &arr[i].weight);
    }

    double maxValue = fractionalKnapsack(W, arr, n);

    printf("Maximum value in knapsack = %.2f\n", maxValue);

    free(arr); 

    return 0;
}

