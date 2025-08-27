#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "AllTextSquareSolver.h"
#include "RootsFinderSquareSolver.h"
#include "EnumsSquareSolver.h"
#include "ParseInput.h"
#include "AllInput.h"
#include "AllOutput.h"

int main(int argc, char *argv[]) {

    double a = 0, b = 0, c = 0;
    double result1 = 0, result2 = 0;
    RootsCount number_of_roots = kZeroRoots;

    const char *filename_input = "InputCoefficients.txt";
    const char *filename_output = "OutputRoots.txt";

    TypeOfInputOutput input_choice_result  = kConsole;
    TypeOfInputOutput output_choice_result = kConsole;

    PossibleErrors parse_error = parse_arguments(argc, argv, &input_choice_result, &output_choice_result, &filename_input, &filename_output);
    if (parse_error == kBadInputCommands) {
        error_printer(parse_error);
        return kBadInputCommands;
    }
    if (parse_error == kTest) {
        return kNoError;
    }
 
    PossibleErrors handle_input_result = handle_input(input_choice_result, &a, &b, &c, filename_input);
    if (handle_input_result != kNoError) {
        error_printer(handle_input_result);
        return handle_input_result; 
    }
 
    number_of_roots = find_result(a, b, c, &result1, &result2);
 
    PossibleErrors handle_output_result = handle_output(output_choice_result, number_of_roots, result1, result2, filename_output);
    if (handle_output_result != kNoError) {
        error_printer(handle_output_result);
        return handle_output_result;
    }
 
    return kNoError;
}