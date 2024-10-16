#include "quicksort.h"

static int partition(int *A, int low, int high) {
    int pivot = A[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (A[j] < pivot) {
            i++;
            if (i != j) {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
    A[high] = A[i + 1];
    A[i + 1] = pivot;
    return i + 1;
}

static void quicksort(int *A, int low, int high) {
    if (low < high) {
        int p = partition(A, low, high);
        quicksort(A, low, p - 1);
        quicksort(A, p + 1, high);
    }
}

void sort(int *A, int size) {
    quicksort(A, 0, size - 1);
}