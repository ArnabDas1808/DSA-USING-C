#include <stdio.h>

#define V 4
#define INF 99999

// Global distance matrix
int dist[V][V] = { {0,   3,   INF, 7}, 
                   {8,   0,   2,   INF}, 
                   {5, INF,   0,   1}, 
                   {2, INF, INF,   0} };

// Global via matrix
int via[V][V];

void printSolution(int dist[][V]);
void printVia(int via[][V]);

void floydWarshall(int dist[][V])
{
    int i, j, k;

    // Initialize via matrix with INF
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            via[i][j] = INF;
        }
    }

    // Floyd-Warshall algorithm
    for (k = 0; k < V; k++) { 
        for (i = 0; i < V; i++) {   
            for (j = 0; j < V; j++) {  
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    via[i][j] = k;  // Update via
                }
            }
        }
    }

    printSolution(dist);
    printVia(via);
}

void printSolution(int dist[][V])
{
    printf("\nThe following matrix shows the shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

void printVia(int via[][V])
{
    printf("\nThe following matrix shows the intermediate (via) vertex for shortest paths:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (via[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", via[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    floydWarshall(dist);  // Use global variable directly
    return 0;
}
