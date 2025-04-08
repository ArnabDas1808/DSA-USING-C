#include <stdio.h>

#define MAX 20

// Global variables
int G[MAX][MAX];  // Adjacency matrix
int x[MAX];       // Path array
int n;            // Number of nodes

void Hamiltonian(int k);
void Nextvalue(int k);

// Recursive function to generate Hamiltonian paths
void Hamiltonian(int k) {
    while (1) {
        Nextvalue(k);
        if (x[k] == 0)
            return;

        if (k == n) {
            // Check if there's an edge back to the starting node
            if (G[x[n]][x[1]] != 0) {
                printf("Hamiltonian Cycle: ");
                for (int i = 1; i <= n; i++) {
                    printf("%d ", x[i]);
                }
                printf("%d\n", x[1]); // back to start
            }
        } else {
            Hamiltonian(k + 1);
        }
    }
}

// Function to assign next valid vertex to position k in the path
void Nextvalue(int k) {
    while (1) {
        x[k] = (x[k] + 1) % (n + 1);
        if (x[k] == 0)
            return;

        if (G[x[k - 1]][x[k]] != 0) {
            int j;
            for (j = 1; j < k; j++) {
                if (x[j] == x[k])
                    break;
            }
            if (j == k) {
                if ((k < n) || (k == n && G[x[n]][x[1]] != 0))
                    return;
            }
        }
    }
}

int main() {
    int edges, u, v;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            G[i][j] = 0;

    printf("Enter connected node pairs (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        G[u][v] = 1;
        G[v][u] = 1; // undirected graph
    }

    // Initialize path: start at node 1
    for (int i = 1; i <= n; i++)
        x[i] = 0;
    x[1] = 1;

    printf("\nAll possible Hamiltonian cycles:\n");
    Hamiltonian(2);

    return 0;
}