#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int x[MAX]; 

int place(int k, int i) {
    for (int j = 1; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
            return 0;
        }
    }
    return 1;
}

void nQueens(int k, int n) {
    for (int i = 1; i <= n; i++) {  
        if (place(k, i)) {
            x[k] = i;
            if (k == n) { 
                for (int j = 1; j <= n; j++) {
                    printf("%d ", x[j]);
                }
                printf("\n");
            } else {
                nQueens(k + 1, n);
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of queens: ");
    scanf("%d", &n);

    if (n >= MAX) {
        printf("Too large! Use a smaller value.\n");
        return 1;
    }

    nQueens(1, n);  
    return 0;
}
