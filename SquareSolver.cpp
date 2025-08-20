#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include "InstructorSquareSolver.h"

float a = 0, b = 0, c = 0;
float result1 = 0, result2 = 0;
int number_of_roots = 0;

int main(void) {

    start_intro();
    int input_choice_result = input_choice();
    int output_choice_result = output_choice();

    int input_result = input_transfer(input_choice_result);

    if (input_result == -2){
        fprintf(stderr, "Error while opening \"InputCoefficients.txt\".\n");
        exit(1);
    } else if (input_result == -1){
        fprintf(stderr, "Input error! You should have entered three real numbers separated by spaces.\n");
        exit(1);
    }

    number_of_roots = find_result(a, b, c, &result1, &result2);
    int output_result = output(output_choice_result);
    if (output_result == -1){
        fprintf(stderr, "Error while opening \"OutputRoots.txt\".\n");
    }
    return 0;
}
