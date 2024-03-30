#include <stdio.h>
#include <limits.h>

#define V 10 // Maximum number of vertices in the graph

// Function to find the minimum of two numbers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to solve the TSP problem using dynamic programming
int tsp(int graph[V][V], int mask, int pos, int n, int dp[][V]) {
    // If all cities have been visited, return the cost from the last city to the starting city
    if (mask == ((1 << n) - 1)) {
        return graph[pos][0];
    }

    // If the subproblem has already been computed, return its result
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    // Initialize minimum cost to maximum integer value
    int ans = INT_MAX;

    // Try to go to an unvisited city
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) { // If the city has not been visited yet
            int newAns = graph[pos][city] + tsp(graph, mask | (1 << city), city, n, dp);
            ans = min(ans, newAns);
        }
    }

    // Save the result in the DP table
    return dp[mask][pos] = ans;
}

int main() {
    int n;
    printf("Enter the number of cities (maximum 10): ");
    scanf("%d", &n);

    int graph[V][V];

    printf("Enter the distances between cities:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize DP table with -1
    int dp[1 << V][V];
    for (int i = 0; i < (1 << V); i++) {
        for (int j = 0; j < V; j++) {
            dp[i][j] = -1;
        }
    }

    // Start the TSP from the 0th vertex
    int minCost = tsp(graph, 1, 0, n, dp);

    printf("Minimum cost of the Travelling Salesman Problem: %d\n", minCost);

    return 0;
}

