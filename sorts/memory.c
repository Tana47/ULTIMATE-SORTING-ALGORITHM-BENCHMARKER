#include <stdio.h>
#include <stdlib.h>
#include "sorts.h"

// Undefine macros so we can use real functions inside here
#undef malloc
#undef calloc
#undef free

long long current_bytes_allocated = 0;
long long peak_bytes_allocated = 0;

void* my_malloc(size_t size) {
    current_bytes_allocated += size;
    if (current_bytes_allocated > peak_bytes_allocated) {
        peak_bytes_allocated = current_bytes_allocated;
    }
    
    void* ptr = malloc(size);
    if (!ptr) { printf("Memory Fail\n"); exit(1); }
    return ptr;
}

// NEW FUNCTION
void* my_calloc(size_t num, size_t size) {
    size_t total_size = num * size;
    
    current_bytes_allocated += total_size;
    if (current_bytes_allocated > peak_bytes_allocated) {
        peak_bytes_allocated = current_bytes_allocated;
    }

    void* ptr = calloc(num, size);
    if (!ptr) { printf("Memory Fail\n"); exit(1); }
    return ptr;
}

void my_free(void* ptr) {
    free(ptr);
}