#include "FileOperations.h"

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <assert.h>

#include "AllTextSquareSolver.h"
#include "InputOutputDefines.h"


PossibleErrors open_file(const char *filename, FILE **file, const char *mode) {
    assert(mode     != NULL);
    assert(filename != NULL);
    assert(mode     != NULL);
    assert(file     != NULL);

    *file = fopen(filename, mode);
    if (*file == NULL) {
        return kErrorOpening;
    }

    return kNoError;
}

PossibleErrors close_file(FILE *file) {
    assert(file != NULL);
    assert(file != stdin);
    assert(file != stdout);

    int status = fclose(file);
    if (status != 0) {
        return kErrorClosing;
    }

    return kNoError;
}