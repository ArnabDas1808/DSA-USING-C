#include <stdio.h>

int g[100][100];
int n;
int v[100];
int q[100];  // used as a stack for DFS

int pre(int a, int b) {
    return g[a][b] == 1;
}

void dfs() {
    int top = -1;

    for (int i = 0; i < n; i++) {
        v[i] = 0;
    }

    q[++top] = 0;  // push starting node to stack
    v[0] = 1;

    printf("DFS Traversal Order: ");

    while (top >= 0) {
        int c = q[top--];  // pop from stack
        printf("%d ", c + 1);

        for (int i = n - 1; i >= 0; i--) {  // reverse order to match typical DFS behavior
            if (pre(c, i) && !v[i]) {
                v[i] = 1;
                q[++top] = i;  // push to stack
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

    dfs();
    return 0;
}
