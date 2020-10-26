#include "common.h"
#include "chunk.h"
#include "debug.h"

int main(int argc, const char* argv[]) {
    Chunk chunk;
    initChunk(&chunk);

    /*
     * The idea is that the first byte contains the
     * instruction OP_CONSTANT and the second
     * the index in the array of constants so we
     * can retrive it later.
     */
    int constant = addConstant(&chunk, 1.2);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant, 123);


    writeChunk(&chunk, OP_RETURN, 123);

    disassembleChunk(&chunk, "test chunk");
    freeChunk(&chunk);

    return 0;
}
