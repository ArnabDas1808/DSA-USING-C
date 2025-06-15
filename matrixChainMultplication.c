#include <stdio.h>

int n;
int p[100];
int m[100][100];
int s[100][100];

void matrix_chain() {
    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    for (int l = 2; l < n; l++) {
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = 999999;

            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (m[i][j] > q) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void print_parens(int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        print_parens(i, s[i][j]);
        print_parens(s[i][j] + 1, j);
        printf(")");
    }
}

int main() {
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    printf("Enter the dimensions: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    matrix_chain();

    printf("Minimum number of multiplications is: %d and index 1, %d\n", m[1][n - 1], n - 1);
    printf("Optimal parenthesization is: ");
    print_parens(1, n - 1);
    printf("\n");

    return 0;
}
