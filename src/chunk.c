//
// Created by modcy on 2020-10-25.
//
#include <stdlib.h>

#include "chunk.h"
#include "memory.h"

// Initialize bytecode array
void initChunk(Chunk* chunk) {
    chunk->count = 0;
    chunk->capacity = 0;
    chunk->code = NULL;
}

/* Append bytecode at the end of the array
*  if the array is not big enough then expand
*/
void writeChunk(Chunk* chunk, uint8_t byte) {
    // If the array is full, then expand
    if (chunk->capacity < chunk->count + 1) {
        int oldCapacity = chunk->capacity;
        chunk->capacity = GROW_CAPACITY(oldCapacity);
        chunk->code = GROW_ARRAY(uint8_t, chunk->code,
                                 oldCapacity, chunk->capacity);
    }

    // Otherwise just append to the end
    chunk->code[chunk->count] = byte;
    chunk->count++;
}

void freeChunk(Chunk* chunk) {
    FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
    initChunk(chunk);
}