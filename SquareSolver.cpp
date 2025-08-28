#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "AllTextSquareSolver.h"
#include "RootsFinderSquareSolver.h"
#include "EnumsSquareSolver.h"
#include "ParseInput.h"
#include "AllInput.h"
#include "AllOutput.h"
#include "StructsSquareSolver.h"

int main(int argc, char *argv[]) {
    struct SolutionArguments solver = {.a = 0, .b = 0, .c = 0, .number_of_roots = kZeroRoots, .result1 = 0, .result2 = 0};
    struct Files filenames = {"InputCoefficients.txt", "OutputRoots.txt"};
    struct Inout flags = {.input_choice_result = kConsole, .output_choice_result = kConsole, .result_type = kShortSolution};


    PossibleErrors parse_error = parse_arguments(argc, argv, &flags, &filenames, &solver);
    if (parse_error == kBadInputCommands) {
        error_printer(parse_error);
        return kBadInputCommands;
    }
    if (parse_error == kTest) {
        return kNoError;
    }
 
    PossibleErrors handle_input_result = handle_input(&flags, &solver, filenames.input_file);
    if (handle_input_result != kNoError) {
        error_printer(handle_input_result);
        return handle_input_result; 
    }
 
    solver.number_of_roots = find_result(&solver);
 
    PossibleErrors handle_output_result = handle_output(&flags, &solver, filenames.output_file);
    if (handle_output_result != kNoError) {
        error_printer(handle_output_result);
        return handle_output_result;
    }
 
    return kNoError;
}