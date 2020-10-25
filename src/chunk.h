//
// Created by modcy on 2020-10-25.
//

#ifndef SLANG_CHUNK_H
#define SLANG_CHUNK_H

#include "common.h"

// Each instruction has a one-byte "operation code"
typedef enum {
    OP_RETURN,
}OpCode;

// Eventually holds a series of instructions
// This data structure represents a dynamic array
typedef struct {
    int count;
    int capacity;
    uint8_t* code;
} Chunk;

void initChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte);
void freeChunk(Chunk* chunk);

#endif //SLANG_CHUNK_H
