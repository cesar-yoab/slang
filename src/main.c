#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"

static void repl() {
    char line[1024];
    for(;;) {
        printf("> ");

        if(!fgets(line, sizeof(line), stdin)) {
            printf("\n");
            break;
        }

        interpret(line);
    }
}

/*
 * Now that I think about it there might be a better way to do this.
 * In essence since we don't know how big is the file
 * we read it and count how long it is... not very clever but works.
 */
static char* readFile(const char* path) {
    FILE* file = fopen(path, "rb");
    if (file == NULL) { // This happens more often than you think
        fprintf(stderr, "Could not open file \"%s.\n", path);
        exit(74);
    }

    fseek(file, 0L, SEEK_END);
    size_t fileSize = ftell(file);
    rewind(file);

    char* buffer = (char*) malloc(fileSize + 1);
    if (buffer == NULL) { // Its 2020 but just in case we run out of RAM
        fprintf(stderr, "Not enough memory to read \"%s.\n", path);
        exit(74);
    }

    size_t bytesRead = fread(buffer, sizeof(char), fileSize, file);
    if (bytesRead < fileSize) {
        fprintf(stderr, "Could not read file \"%s.\n", path);
        exit(74);
    }

    buffer[bytesRead] = '\0'; // Remember all that suffering from strings in systems class
    fclose(file);
    return buffer;
}

static void runFile(const char* path) {
    char* source = readFile(path);

    InterpretResult result = interpret(source);
    free(source);

    if (result == INTERPRET_COMPILE_ERROR) exit(65);
    if(result == INTERPRET_RUNTIME_ERROR) exit(70);
}

int main(int argc, const char* argv[]) {
    initVM();

    if (argc == 1) {
        repl();
    } else if (argc == 2) {
        runFile(argv[1]);
    } else {
        fprintf(stderr, "Usage: slang [path]\n");
        exit(64);
    }

    freeVM();
    return 0;
}
