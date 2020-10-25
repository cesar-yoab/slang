//
// Created by modcy on 2020-10-25.
//
#include <stdlib.h>

#include "memory.h"

/*
 * A wrapper to the realloc function with the added
 * functionality of freeing memory if newSize is
 * passed as 0. Use this function with precaution
 * to avoid a memory leak.
 */
void* reallocate(void* pointer, size_t oldSize, size_t newSize) {
    if (newSize == 0) { // Free memory
        free(pointer);
        return NULL;
    }
    // Reallocate and expand array
    void* result = realloc(pointer, newSize);
    // In case we run out of memory
    if (result == NULL) exit(1);
    return result;
}