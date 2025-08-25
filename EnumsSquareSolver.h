#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#include "AllTextSquareSolver.h"

#define eprintf(format, ...) fprintf (stderr, format, __VA_ARGS__)
#ifdef NDEBUG
#define MY_ASSERT(condition, format, ...) (void(0))
#else
#define MY_ASSERT(condition, format, ...) \
    if (!(condition)){ \
        assert_true();\
        eprintf(RED format RESET, __VA_ARGS__);\
        abort(); \
    }
#endif

#ifndef SOME_OF_ENUMS
#define SOME_OF_ENUMS

    enum RootsCount{
        kZeroRoots = 0,
        kOneRoot   = 1,
        kTwoRoots  = 2,
        kInfRoots  = INT_MAX,
    };

    enum PossibleErrors{
        kNoError          = 0,
        kErrorOpening     = 1,
        kBadInputCommands = 2,
        kBadInputGraphics = 3,
        kErrorClosing     = 4,
        kErrorTest        = 5,
    };

    enum TypeOfInputOutput{
        kFile        = 1,
        kConsole     = 2,
        kCommandLine = 3,
    };

#define write_mode "w"
#define read_mode "r"

#define in_command "--in"
#define out_command "--out"

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"

#endif
