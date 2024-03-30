#include <stdio.h>
#include <stdbool.h>

#define V 2 // Maximum number of vertices

bool isSafe(int v, bool graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

bool graphColoringUtil(bool graph[V][V], int m, int color[], int v) {
    if (v == V)
        return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1))
                return true;
            color[v] = 0;
        }
    }

    return false;
}

void graphColoring(bool graph[V][V], int m) {
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    if (!graphColoringUtil(graph, m, color, 0))
        printf("Solution does not exist\n");
    else {
        printf("Solution exists!\n");
        printf("Vertex \tColor\n");
        for (int i = 0; i < V; i++)
            printf("%d \t%d\n", i, color[i]);
    }
}

int main() {
    int m; // Number of colors
    printf("Enter the number of colors: ");
    scanf("%d", &m);

    bool graph[V][V];
    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    graphColoring(graph, m);

    return 0;
}

