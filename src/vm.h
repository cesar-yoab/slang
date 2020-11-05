#ifndef SLANG_VM_H
#define SLANG_VM_H

#include "chunk.h"
#include "value.h"

#define STACK_MAX 256

typedef struct {
    Chunk* chunk; // Array of instructions
    uint8_t* ip; // Instruction Pointer
    Value stack[STACK_MAX];
    Value* stackTop;
}VM;

typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
} InterpretResult;

void initVM();
void freeVM();
InterpretResult interpret(const char* source);
void push(Value value);
Value pop();

#endif //SLANG_VM_H
