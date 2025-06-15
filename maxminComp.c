#include <stdio.h>

int arr1[7] = {2, 6, -2, -6, 9, 3, 0};
int arr2[7] = {-6, -2, 0, 2, 3, 6, 9};
int arr3[7] = {9, 6, 3, 2, 0, -2, -6};
int n = 7;

int compare(int a, int b) {
    if (a > b) return 1;
    if (a < b) return -1;
    return 0;
}

int maxmin1(int arr[], int n) {
    int max = arr[0], min = arr[0];
    int c = 0;
    for (int i = 1; i < n; i++) {
        c++;
        if (arr[i] > max) {
            max = arr[i];
        }
        c++;
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return c;
}

int maxmin2(int arr[], int n) {
    int max = arr[0], min = arr[0];
    int c = 0;
    for (int i = 1; i < n; i++) {
        c++;
        if (arr[i] > max) {
            max = arr[i];
        } else {
            c++;
            if (arr[i] < min) {
                min = arr[i];
            }
        }
    }
    return c;
}

int main() {
    int c1, c2;

    c1 = maxmin1(arr1, n);
    printf("For Unsorted Array (arr1):\n");
    printf("Using maxmin1: Comparisons = %d\n", c1);

    c2 = maxmin2(arr1, n);
    printf("Using maxmin2: Comparisons = %d\n\n", c2);

    c1 = maxmin1(arr2, n);
    printf("For Sorted Array (arr2):\n");
    printf("Using maxmin1: Comparisons = %d\n", c1);

    c2 = maxmin2(arr2, n);
    printf("Using maxmin2: Comparisons = %d\n\n", c2);

    c1 = maxmin1(arr3, n);
    printf("For Reverse Sorted Array (arr3):\n");
    printf("Using maxmin1: Comparisons = %d\n", c1);

    c2 = maxmin2(arr3, n);
    printf("Using maxmin2: Comparisons = %d\n", c2);

    if (c1 <= c2) {
        printf("\nmaxmin1 is more efficient in terms of comparisons.\n");
    } else {
        printf("\nmaxmin2 is more efficient in terms of comparisons.\n");
    }

    return 0;
}
