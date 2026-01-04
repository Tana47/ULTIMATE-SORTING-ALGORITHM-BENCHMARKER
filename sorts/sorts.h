#ifndef SORTS_H
#define SORTS_H

#include <stdlib.h>

// --- Memory Tracking Globals ---
extern long long current_bytes_allocated;
extern long long peak_bytes_allocated;

// --- Hijack malloc AND calloc ---
void* my_malloc(size_t size);
void* my_calloc(size_t num, size_t size); // <--- NEW
void  my_free(void* ptr);

#define malloc(x)      my_malloc(x)
#define calloc(n, s)   my_calloc(n, s) // <--- NEW
#define free(x)        my_free(x)

// --- Sorting Prototypes ---
void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);
void cocktailSort(int arr[], int n);
void combSort(int arr[], int n);
void quickSort(int arr[], int n);
void mergeSort(int arr[], int n);
void iterativeMergeSort(int arr[], int n);
void heapSort(int arr[], int n);
void shellSort(int arr[], int n);
void timSort(int arr[], int n);
void countingSort(int arr[], int n);
void radixSort(int arr[], int n);
void cycleSort(int arr[], int n);

#endif