#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "AllTextSquareSolver.h"
#include "InputOutputSquareSolver.h"
#include "RootsFinderSquareSolver.h"

int main(int argc, char *argv[]) {
    float a = 0, b = 0, c = 0;
    float result1 = 0, result2 = 0;
    int number_of_roots = kZeroRoots;

    const char *filename_to_open_input = "InputCoefficients.txt";
    const char *filename_to_open_output = "OutputRoots.txt";

    int input_choice_result = kConsole;
    int output_choice_result = kConsole;

    int parse_error = parse_arguments(argc, argv, &input_choice_result, &output_choice_result, &filename_to_open_input, &filename_to_open_output);
    if (parse_error != kNoError){
        error_printer(parse_error);
        return kBadInputCommands;
    }
 
    int handle_input_result = handle_input(input_choice_result, &a, &b, &c, filename_to_open_input);
    if (handle_input_result != kNoError) {
        error_printer(handle_input_result);
        return handle_input_result; 
    }
 
    number_of_roots = find_result(a, b, c, &result1, &result2);
 
    int handle_output_result = handle_output(output_choice_result, number_of_roots, result1, result2, filename_to_open_output);
    if (handle_output_result != kNoError) {
        error_printer(handle_output_result);
        return handle_output_result;
    }
 
    return kNoError;
}