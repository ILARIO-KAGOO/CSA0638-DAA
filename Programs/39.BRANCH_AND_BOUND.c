#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define N 2 // Number of agents and tasks

int min(int a, int b) {
    return (a < b) ? a : b;
}

void copyArray(int dest[], int src[], int size) {
    for (int i = 0; i < size; i++)
        dest[i] = src[i];
}

// Function to find the minimum cost using Branch and Bound
void assignTask(int costMatrix[N][N], bool assigned[], int assignedTask, int totalCost, int* minCost, int assignment[]) {
    if (assignedTask == N) {
        *minCost = min(*minCost, totalCost);
        return;
    }

    for (int agent = 0; agent < N; agent++) {
        if (!assigned[agent]) {
            assigned[agent] = true;
            int newCost = totalCost + costMatrix[agent][assignedTask];

            if (newCost < *minCost) {
                int oldAssignment[N];
                copyArray(oldAssignment, assignment, N);
                assignment[agent] = assignedTask;

                assignTask(costMatrix, assigned, assignedTask + 1, newCost, minCost, assignment);

                copyArray(assignment, oldAssignment, N); // Backtrack
            }

            assigned[agent] = false;
        }
    }
}

// Function to print the assignment
void printAssignment(int assignment[]) {
    printf("Agent   Task\n");
    for (int i = 0; i < N; i++)
        printf(" %d  ->   %d\n", i, assignment[i]);
}

int main() {
    int costMatrix[N][N];

    printf("Enter the cost matrix (%d x %d):\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &costMatrix[i][j]);
        }
    }

    bool assigned[N] = {false};
    int assignment[N] = {0};
    int minCost = INT_MAX;

    assignTask(costMatrix, assigned, 0, 0, &minCost, assignment);

    printf("Minimum Cost: %d\n", minCost);
    printf("Assignment:\n");
    printAssignment(assignment);

    return 0;
}

