#include <stdio.h>
#include <limits.h>

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

#endif