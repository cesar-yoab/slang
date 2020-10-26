#ifndef SLANG_MEMORY_H
#define SLANG_MEMORY_H

#include "common.h"

/*
 * Note that dynamic arrays can use other
 * growth factors. In our case we double the size
 * on every expansion.
 */
#define GROW_CAPACITY(capacity) \
    ((capacity) < 8 ? 8 : (capacity) * 2)

/*
 * This is just for simplicity. The macro takes care of the
 * casting with the call to reallocate which internally calls
 * to realloc from the malloc/alloc family
 */
#define GROW_ARRAY(type, pointer, oldCount, newCount) \
    (type*)reallocate(pointer, sizeof(type) * (oldCount), \
        sizeof(type) * (newCount))

/*
 * Free array memory by calling our reallocate function,
 * like GROW_ARRAY this is for simplicity.
 */
#define FREE_ARRAY(type, pointer, oldCount) \
    reallocate(pointer, sizeof(type) * (oldCount), 0)


// A wrapper to realloc also frees memory
void* reallocate(void* pointer, size_t oldSize, size_t newSize);

#endif //SLANG_MEMORY_H
