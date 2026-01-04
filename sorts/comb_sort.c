#include "sorts.h"

static void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void combSort(int arr[], int n) {
    int gap = n;
    int swapped = 1;

    while (gap != 1 || swapped == 1) {
        // Update gap
        gap = (gap * 10) / 13;
        if (gap < 1) gap = 1;

        swapped = 0;
        for (int i = 0; i < n - gap; i++) {
            if (arr[i] > arr[i + gap]) {
                swap(&arr[i], &arr[i + gap]);
                swapped = 1;
            }
        }
    }
}