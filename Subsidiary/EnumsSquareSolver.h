#ifndef ENUMS_SQUARE_SOLVER_H_
#define ENUMS_SQUARE_SOLVER_H_

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

enum RootsCount {
    kZeroRoots = 0,
    kOneRoot   = 1,
    kTwoRoots  = 2,
    kInfRoots  = -1,
};

enum PossibleErrors {
    kNoError          = 0,
    kErrorOpening     = 1,
    kBadInputCommands = 2,
    kBadInputGraphics = 3,
    kErrorClosing     = 4,
    kTest             = 5,
};

enum TypeOfInputOutput {
    kFile        = 1,
    kConsole     = 2,
    kCommandLine = 3,
};

enum TypeOfResult {
    kLongSolution  = 1,
    kShortSolution = 2,
};

#endif // ENUMS_SQUARE_SOLVER_H_