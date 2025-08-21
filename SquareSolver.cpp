#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "AllTextSquareSolver.h"
#include "InputOutputSquareSolver.h"
#include "RootsFinderSquareSolver.h"

int main(void) {
    float a = 0, b = 0, c = 0;
    float result1 = 0, result2 = 0;
 
    start_intro();
    input_choice_text();
    int input_choice_result = choice_question();
 
    output_choice_text();
    int output_choice_result = choice_question();
 
    if (handle_input(input_choice_result, &a, &b, &c)) {
        return 1; 
    }
 
    int number_of_roots = find_result(a, b, c, &result1, &result2);
 
    if (handle_output(output_choice_result, number_of_roots, result1, result2)) {
        return 1;
    }
 
    return 0;
}