#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int path[MAX_VERTICES];
int numVertices;

void printSolution() {
    printf("Hamiltonian Circuit: ");
    for (int i = 0; i < numVertices; i++) {
        printf("%d ", path[i] + 1); // Adding 1 to vertex number to make it 1-indexed
    }
    printf("%d\n", path[0] + 1); // Complete the circuit
}

bool isValid(int v, int pos) {
    if (!graph[path[pos - 1]][v]) // If there is no edge between the last vertex in path and v
        return false;

    for (int i = 0; i < pos; i++) {
        if (path[i] == v) // If v is already included in the path
            return false;
    }

    return true;
}

bool hamiltonianCircuitUtil(int pos) {
    if (pos == numVertices) {
        if (graph[path[pos - 1]][path[0]]) // If there is an edge between the last and first vertex
            return true;
        else
            return false;
    }

    for (int v = 1; v < numVertices; v++) { // Start from vertex 1 (0 is already in the path)
        if (isValid(v, pos)) {
            path[pos] = v;
            if (hamiltonianCircuitUtil(pos + 1))
                return true;
            path[pos] = -1; // Backtrack
        }
    }

    return false;
}

void hamiltonianCircuit(int graph[][MAX_VERTICES], int n) {
    numVertices = n;
    for (int i = 0; i < numVertices; i++) {
        path[i] = -1; // Initialize path array
    }
    path[0] = 0; // Start from vertex 0
    if (!hamiltonianCircuitUtil(1)) {
        printf("No Hamiltonian Circuit exists\n");
        return;
    }
    printSolution();
}

int main() {
    int n, e;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &e);

    printf("Enter the edges (u, v) one by one:\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1; // Assuming an undirected graph
    }

    hamiltonianCircuit(graph, n);

    return 0;
}

