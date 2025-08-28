#ifndef STRUCTS_H_
#define STRUCTS_H_

#include "EnumsSquareSolver.h"

struct Inout {
    TypeOfInputOutput input_choice_result;
    TypeOfInputOutput output_choice_result;
    TypeOfResult result_type;
};

struct SolutionArguments {
    double a, b, c, discriminant, result1, result2;
    RootsCount number_of_roots;
};

struct SolutionArgumentsCompared {
    double a, b, c, result1_compared, result2_compared;
    RootsCount number_of_roots_compared;
};

struct Files {
    const char *input_file, *output_file;
};

#endif // STRUCTS_H_