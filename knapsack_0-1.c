#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int maxWeight, int weights[], int values[], int n) {
    int dp[n + 1][maxWeight + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= maxWeight; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][maxWeight];
}

int main() {
    int n, maxWeight;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int weights[n], values[n];

    for (int i = 0; i < n; i++) {
        printf("Enter weight of item %d: ", i + 1);
        scanf("%d", &weights[i]);
        printf("Enter value of item %d: ", i + 1);
        scanf("%d",&values[i]);
    }

    printf("Enter maximum weight capacity: ");
    scanf("%d", &maxWeight);

    int maxValue = knapsack(maxWeight, weights, values, n);
    printf("The maximum value is: %d\n", maxValue);

    return 0;
}
