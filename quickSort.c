#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void fill_random(int arr[], int n, int range) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % range;
    }
}

int main() {
    srand(time(NULL));  // Seed for random number generator
    clock_t start, end;
    double cpu_time_used;

    // Case 1: Small array (10 elements), repeat to get measurable time
    int arr[10];
    double total_time = 0.0;
    int repetitions = 10000;

    for (int r = 0; r < repetitions; r++) {
        fill_random(arr, 10, 1000);
        start = clock();
        quick_sort(arr, 0, 9);
        end = clock();
        total_time += (double)(end - start) / CLOCKS_PER_SEC;
    }

    printf("Average time taken to sort array of size 10 (over %d runs): %.6f seconds\n",
           repetitions, total_time / repetitions);

    // Case 2: Larger arrays
    int sizes[] = {500, 1000, 5000, 8000, 10000};

    for (int i = 0; i < 5; i++) {
        int n = sizes[i];
        int *arr_large = (int *)malloc(n * sizeof(int));

        fill_random(arr_large, n, 10000);

        start = clock();
        quick_sort(arr_large, 0, n - 1);
        end = clock();
        cpu_time_used = (double)(end - start) / CLOCKS_PER_SEC;

        printf("Time taken to sort array of size %d: %.6f seconds\n", n, cpu_time_used);

        free(arr_large);
    }

    return 0;
}
