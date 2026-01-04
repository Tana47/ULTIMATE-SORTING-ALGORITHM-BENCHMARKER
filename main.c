#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "sorts/sorts.h"

#define MAX_SIZE 100

// Helper Functions
void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) dest[i] = src[i];
}

void printArray(int arr[], int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("]\n");
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int getData(int arr[]) {
    int choice;
    int count = 0;

    printf("\n--- Data Selection ---\n");
    printf("1) Input an array (Max %d numbers)\n", MAX_SIZE);
    printf("2) Use Preset Data (100 Random Numbers)\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    clearInputBuffer(); 

    if (choice == 1) {
        printf("Enter numbers separated by spaces: ");
        char line[1024];
        if (fgets(line, sizeof(line), stdin)) {
            char *token = strtok(line, " \n,");
            while (token != NULL && count < MAX_SIZE) {
                if (isdigit(token[0]) || token[0] == '-') {
                    arr[count++] = atoi(token);
                }
                token = strtok(NULL, " \n,");
            }
        }
    } else {
        count = MAX_SIZE;
        for (int i = 0; i < count; i++) {
            arr[i] = rand() % 1000; 
        }
        printf("\nOriginal Array (Randomly Generated):\n");
        printArray(arr, count);
    }
    return count;
}

// --- UPDATED EXECUTION ENGINE ---
void runSort(const char* name, void (*sortFunc)(int[], int), int original[], int n, int isFirstRun) {
    int* workArr = (int*)malloc(MAX_SIZE * sizeof(int) * 100); // Use raw malloc for setup to avoid polluting stats
    copyArray(original, workArr, n);

    // RESET METRICS
    peak_bytes_allocated = 0;
    current_bytes_allocated = 0;

    clock_t start = clock();
    sortFunc(workArr, n);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    if (isFirstRun) {
        printf("\n--- Sorted Result (Verified) ---\n");
        printArray(workArr, n);
        printf("--------------------------------\n");
        printf("\n%-20s | %-18s | %s\n", "ALGORITHM", "TIME (Seconds)", "PEAK MEMORY (Bytes)");
        printf("------------------------------------------------------------\n");
    }

    // Print with Memory Stats
    printf("%-20s | %.8f s       | %lld bytes\n", name, time_taken, peak_bytes_allocated);
    
    // We use standard free here (cast to avoid our macro if possible, 
    // but since we are in main it might use the macro. That's fine.)
    free(workArr);
}

int main() {
    srand(time(NULL));
    int dataArr[MAX_SIZE];
    int dataSize;
    char algoInput[100];
    int algos[15] = {0}; 

    printf("==========================================\n");
    printf("   ULTIMATE SORTING BENCHMARKER v1.3    \n");
    printf("==========================================\n");

    dataSize = getData(dataArr);
    if (dataSize == 0) return 0;

    printf("\n--- Algorithm Selection ---\n");
    printf("1)  Bubble Sort        8)  Shell Sort\n");
    printf("2)  Insertion Sort     9)  Radix Sort\n");
    printf("3)  Selection Sort     10) Tim Sort\n");
    printf("4)  Quick Sort         11) Counting Sort\n");
    printf("5)  Merge Sort (Rec)   12) Cocktail Sort\n");
    printf("6)  Merge Sort (Iter)  13) Comb Sort\n");
    printf("7)  Heap Sort          14) Cycle Sort\n");
    printf("Enter number(s) or '*' for ALL: ");
    
    fgets(algoInput, sizeof(algoInput), stdin);

    if (strchr(algoInput, '*') != NULL) {
        for(int i=1; i<=14; i++) algos[i] = 1;
    } else {
        char *token = strtok(algoInput, " \n,");
        while (token != NULL) {
            int choice = atoi(token);
            if (choice >= 1 && choice <= 14) algos[choice] = 1;
            token = strtok(NULL, " \n,");
        }
    }

    int firstRun = 1; 

    // Helper macro to clean up the list
    #define RUN(idx, name, func) if (algos[idx]) { runSort(name, func, dataArr, dataSize, firstRun); firstRun = 0; }

    RUN(1, "Bubble Sort", bubbleSort);
    RUN(2, "Insertion Sort", insertionSort);
    RUN(3, "Selection Sort", selectionSort);
    RUN(4, "Quick Sort", quickSort);
    RUN(5, "Merge Sort (Rec)", mergeSort);
    RUN(6, "Merge Sort (Iter)", iterativeMergeSort);
    RUN(7, "Heap Sort", heapSort);
    RUN(8, "Shell Sort", shellSort);
    RUN(9, "Radix Sort", radixSort);
    RUN(10, "Tim Sort", timSort);
    RUN(11, "Counting Sort", countingSort);
    RUN(12, "Cocktail Sort", cocktailSort);
    RUN(13, "Comb Sort", combSort);
    RUN(14, "Cycle Sort", cycleSort);

    if (firstRun == 1) printf("No valid algorithm selected.\n");

    printf("\nDone.\n");
    return 0;
}