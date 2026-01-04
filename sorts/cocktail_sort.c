#include "sorts.h"

static void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void cocktailSort(int arr[], int n) {
    int swapped = 1;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        swapped = 0;
        // Forward pass
        for (int i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                swap(&arr[i], &arr[i + 1]);
                swapped = 1;
            }
        }
        if (!swapped) break;
        swapped = 0;
        --end;
        // Backward pass
        for (int i = end - 1; i >= start; --i) {
            if (arr[i] > arr[i + 1]) {
                swap(&arr[i], &arr[i + 1]);
                swapped = 1;
            }
        }
        ++start;
    }
}