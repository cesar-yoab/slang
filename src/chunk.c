#include <stdlib.h>

#include "chunk.h"
#include "memory.h"

/*
 * Initialize bytecode array and constants
 * array
 */
void initChunk(Chunk* chunk) {
    chunk->count = 0;
    chunk->capacity = 0;
    chunk->code = NULL;
    chunk->lines = NULL;
    initValueArray(&chunk->constants);
}

/* Append bytecode at the end of the array
*  if the array is not big enough then expand
*/
void writeChunk(Chunk* chunk, uint8_t byte, int line) {
    // If the array is full, then expand
    if (chunk->capacity < chunk->count + 1) {
        int oldCapacity = chunk->capacity;
        chunk->capacity = GROW_CAPACITY(oldCapacity);
        chunk->code = GROW_ARRAY(uint8_t, chunk->code,
                                 oldCapacity, chunk->capacity);
        chunk->lines = GROW_ARRAY(int, chunk->lines,
                                  oldCapacity, chunk->capacity);
    }

    // Otherwise just append to the end
    chunk->code[chunk->count] = byte;
    chunk->lines[chunk->count] = line;
    chunk->count++;
}

/*
 * Free all memory on this chunk including the
 * constants array
 */
void freeChunk(Chunk* chunk) {
    FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
    FREE_ARRAY(int, chunk->lines, chunk->capacity);
    freeValueArray(&chunk->constants);
    initChunk(chunk);
}

/*
 * After it adds the constant, it returns the index where
 * it was appended so that we can locate that same constant
 * later.
 */
int addConstant(Chunk* chunk, Value value) {
    writeValueArray(&chunk->constants, value);
    return chunk->constants.count - 1;
}