#include "sorts.h"

static void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Internal helper function (static means it's only visible in this file)
static int partition(int arr[], int low, int high) {
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

// Internal recursive function
static void quickSortRecursive(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortRecursive(arr, low, pi - 1);
        quickSortRecursive(arr, pi + 1, high);
    }
}

// The main function exposed in sorts.h
void quickSort(int arr[], int n) {
    quickSortRecursive(arr, 0, n - 1);
}