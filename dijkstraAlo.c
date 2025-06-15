#include <stdio.h>
#include <limits.h>

#define N 10

int n;
int d[N];
int pi[N];
int flag[N];
int W[N][N];

void Initialize_Singlesource(int S) {
    for (int i = 0; i < n; i++) {
        d[i] = 999;
        pi[i] = -1;
        flag[i] = 0;
    }
    d[S] = 0;
    pi[S] = -1;
}

int w(int u, int v) {
    return W[u][v];
}

void RELAX(int u, int v) {
    if (W[u][v] != 0 && W[u][v] != 999) {
        if (d[v] > d[u] + W[u][v]) {
            d[v] = d[u] + W[u][v];
            pi[v] = u;
        }
    }
}

int EXTRACT_MIN() {
    int min = 999;
    int vertex = -1;
    for (int i = 0; i < n; i++) {
        if (flag[i] == 0 && d[i] < min) {
            min = d[i];
            vertex = i;
        }
    }
    flag[vertex] = 1;
    return vertex;
}

void dijkstraAlgorithm(int S) {
    Initialize_Singlesource(S);
    int count = n;

    while (count > 0) {
        int u = EXTRACT_MIN();
        for (int v = 0; v < n; v++) {
            if (W[u][v] != 0 && W[u][v] != 999) {
                RELAX(u, v);
            }
        }
        count--;
    }

    printf("Vertex\tDistance from source\tPredecessor\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t\t", i, d[i]);
        if (pi[i] == -1) {
            printf("None");
        } else {
            printf("%d", pi[i]);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the graph weight matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &W[i][j]);
        }
    }

    int source = 0;
    dijkstraAlgorithm(source);
    return 0;
}
