#ifndef SLANG_VALUE_H
#define SLANG_VALUE_H

#include "common.h"

// For now this language only supports double
// precision floating point numbers
typedef double Value;

// Our array of constants
typedef struct {
    int capacity;
    int count;
    Value* values;
} ValueArray;

void initValueArray(ValueArray* array);
void writeValueArray(ValueArray* array, Value value);
void freeValueArray(ValueArray* array);
void printValue(Value value);

#endif //SLANG_VALUE_H
