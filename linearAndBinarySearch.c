#include <stdio.h>

int arr[9] = {-100, -89, -56, -5, 0, 6, 10, 75, 99};
int n = 9;

int linearSearch(int no) {
    int comparisons = 0;
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == no) {
            return comparisons;
        }
    }
    return comparisons;
}

int binarySearch(int num) {
    int comparisons = 0;
    int low = 0, high = n - 1;

    while (low <= high) {
        comparisons++;
        int mid = (low + high) / 2;

        if (arr[mid] == num) {
            return comparisons;
        } else if (arr[mid] < num) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return comparisons;
}

void testSearch(int num) {
    printf("\nTesting for number: %d\n", num);
    int c1 = linearSearch(num);
    int c2 = binarySearch(num);

    printf("Linear Search found the number in %d comparisons\n", c1);
    printf("Binary Search found the number in %d comparisons\n", c2);

    if (c1 < c2) {
        printf("Linear Search is better.\n");
    } else if (c1 > c2) {
        printf("Binary Search is better.\n");
    } else {
        printf("Both searches took the same number of comparisons.\n");
    }
}

int main() {
    printf("Testing search efficiency for different cases:\n");

    testSearch(-100);
    testSearch(0);
    testSearch(99);
    testSearch(7);

    return 0;
}
