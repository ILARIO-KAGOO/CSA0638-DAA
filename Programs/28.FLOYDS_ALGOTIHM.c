#include <stdio.h>
#include <limits.h>

#define V 10 // Maximum number of vertices in the graph

// Function to find the shortest paths between all pairs of vertices using Floyd's algorithm
void floydWarshall(int graph[][V], int n) {
    int dist[V][V];

    // Initialize distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Compute shortest paths
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distances
    printf("Shortest distances between all pairs of vertices:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INT_MAX) {
                printf("INF\t");
            } else {
                printf("%d\t", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    // Input the adjacency matrix representing the graph
    int graph[V][V];
    printf("Enter the adjacency matrix of the graph (Enter INF for infinity):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == -1) {
                graph[i][j] = INT_MAX;
            }
        }
    }

    // Call Floyd's algorithm function
    floydWarshall(graph, n);

    return 0;
}


