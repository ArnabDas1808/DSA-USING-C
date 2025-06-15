#include <stdio.h>

int A[10] = {1, 10, -2, 3, 0, -4, 5, 15, -6, 8};
int heapsize = 10;

int RIGHT(int i) {
    return (2 * i + 2);
}

int LEFT(int i) {
    return (2 * i + 1);
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void MaxHeapify(int A[], int i) {
    int l = LEFT(i);
    int r = RIGHT(i);
    int largest = i;

    if (l < heapsize && A[l] > A[largest]) {
        largest = l;
    }
    if (r < heapsize && A[r] > A[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(&A[i], &A[largest]);
        MaxHeapify(A, largest);
    }
}

void BuildMaxHeap(int A[]) {
    for (int i = (heapsize / 2) - 1; i >= 0; i--) {
        MaxHeapify(A, i);
    }
}

void Heapsort(int A[]) {
    int originalHeapsize = heapsize;
    BuildMaxHeap(A);
    for (int i = heapsize - 1; i > 0; i--) {
        swap(&A[0], &A[i]);
        heapsize--;
        MaxHeapify(A, 0);
    }
    heapsize = originalHeapsize;
}

int main() {
    Heapsort(A);
    printf("Sorted Array is: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}
