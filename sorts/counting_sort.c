#include "sorts.h"
#include <stdlib.h>
#include <string.h>

void countingSort(int arr[], int n) {
    int max = 0;
    
    // Find max element to determine range
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }

    // Allocate count array
    int* count = (int*)calloc(max + 1, sizeof(int));
    int* output = (int*)malloc(n * sizeof(int));

    // Store count of each element
    for (int i = 0; i < n; i++) count[arr[i]]++;

    // Store cumulative count
    for (int i = 1; i <= max; i++) count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy back to original array
    for (int i = 0; i < n; i++) arr[i] = output[i];

    free(count);
    free(output);
}