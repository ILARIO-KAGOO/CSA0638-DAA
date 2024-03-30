#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

bool isSubsetSum(int set[], int n, int sum) {
    if (sum == 0)
        return true;
    if (n == 0 && sum != 0)
        return false;
    if (set[n - 1] > sum)
        return isSubsetSum(set, n - 1, sum);
    return isSubsetSum(set, n - 1, sum) || isSubsetSum(set, n - 1, sum - set[n - 1]);
}

int main() {
    int set[MAX_SIZE], n, sum;

    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &set[i]);

    printf("Enter the desired sum: ");
    scanf("%d", &sum);

    if (isSubsetSum(set, n, sum))
        printf("Subset with the given sum exists.\n");
    else
        printf("Subset with the given sum does not exist.\n");

    return 0;
}

