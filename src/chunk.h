#ifndef SLANG_CHUNK_H
#define SLANG_CHUNK_H

#include "common.h"
#include "value.h"

// Each instruction has a one-byte "operation code"
typedef enum {
    OP_CONSTANT,
    OP_ADD,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE,
    OP_NEGATE,
    OP_RETURN,
}OpCode;

// Eventually holds a series of instructions
// This data structure represents a dynamic array
typedef struct {
    int count;
    int capacity;
    uint8_t* code;
    int* lines;
    ValueArray constants;
} Chunk;

void initChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte, int line);
void freeChunk(Chunk* chunk);
int addConstant(Chunk* chunk, Value value);

#endif //SLANG_CHUNK_H
