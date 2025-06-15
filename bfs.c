#include <stdio.h>

int g[100][100];
int n;
int v[100];
int q[100];

int pre(int a, int b) {
    return g[a][b] == 1;
}

void bfs() {
    int f = 0, r = 0;

    for (int i = 0; i < n; i++) {
        v[i] = 0;
    }

    q[r++] = 0;
    v[0] = 1;

    printf("BFS Traversal Order: ");

    while (f < r) {
        int c = q[f++];

        printf("%d ", c + 1);

        for (int i = 0; i < n; i++) {
            if (pre(c, i) && !v[i]) {
                v[i] = 1;
                q[r++] = i;
            }
        }
    }
    printf("\n");
}

int main() {
    printf("Enter the number of nodes present in the graph: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &g[i][j]);
        }
    }

    bfs();
    return 0;
}
