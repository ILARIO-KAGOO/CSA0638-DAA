#include <stdio.h>
#include <limits.h>

#define INF INT_MAX

// Helper function to calculate the sum of probabilities
float sum(float freq[], int i, int j) {
    float s = 0;
    for (int k = i; k <= j; k++)
        s += freq[k];
    return s;
}

// Function to find the optimal binary search tree cost
float optimalSearchTree(float freq[], int n) {
    float cost[n][n];

    // For a single node, the cost is equal to its frequency
    for (int i = 0; i < n; i++)
        cost[i][i] = freq[i];

    // Consider chains of increasing length
    for (int L = 2; L <= n; L++) {
        // For chains of length L, consider all possible subtrees
        for (int i = 0; i <= n - L + 1; i++) {
            int j = i + L - 1;
            cost[i][j] = INF;

            // Try making all keys in the interval [i, j] as root
            for (int r = i; r <= j; r++) {
                float c = ((r > i) ? cost[i][r - 1] : 0) +
                          ((r < j) ? cost[r + 1][j] : 0) + sum(freq, i, j);
                if (c < cost[i][j])
                    cost[i][j] = c;
            }
        }
    }
    return cost[0][n - 1];
}

int main() {
    int n;
    printf("Enter the number of keys: ");
    scanf("%d", &n);

    float freq[n];
    printf("Enter the frequencies of keys:\n");
    for (int i = 0; i < n; i++) {
        printf("Frequency of key %d: ", i + 1);
        scanf("%f", &freq[i]);
    }

    printf("Cost of optimal binary search tree is: %f\n", optimalSearchTree(freq, n));
    return 0;
}

