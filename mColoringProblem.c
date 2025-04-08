#include <stdio.h>

#define MAX 20

// Global variables
int G[MAX][MAX];    // Graph adjacency matrix
int x[MAX];         // Colors assigned to nodes
int n;              // Number of nodes
int m;              // Number of colors

void Nextvalue(int k);
void Algo_mColouring(int k);

// m-Coloring algorithm with recursion
void Algo_mColouring(int k) {
    while (1) {
        Nextvalue(k);
        if (x[k] == 0)
            return;

        if (k == n) {
            // Direct output here
            printf("Valid Coloring: ");
            for (int i = 1; i <= n; i++) {
                printf("Node %d → Color %d   ", i, x[i]);
            }
            printf("\n");
        } else {
            Algo_mColouring(k + 1);
        }
    }
}

// Assign next possible color to node k
void Nextvalue(int k) {
    while (1) {
        x[k] = (x[k] + 1) % (m + 1);  // Try next color
        if (x[k] == 0)
            return;  // No more colors to try

        int j;
        for (j = 1; j <= n; j++) {
            if (G[k][j] != 0 && x[k] == x[j])
                break;  // Conflict with adjacent node
        }

        if (j == n + 1)
            return;  // Found valid color
    }
}

int main() {
    int connections, u, v;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter number of connections: ");
    scanf("%d", &connections);

    // Initialize adjacency matrix
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            G[i][j] = 0;

    printf("Enter connected node pairs (u v):\n");
    for (int i = 0; i < connections; i++) {
        scanf("%d %d", &u, &v);
        G[u][v] = 1;
        G[v][u] = 1;  // Undirected graph
    }

    printf("Enter number of colors: ");
    scanf("%d", &m);

    // Initialize colors
    for (int i = 1; i <= n; i++)
        x[i] = 0;

    printf("\nAll possible valid colorings:\n");
    Algo_mColouring(1);

    return 0;
}