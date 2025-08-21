#include <stdio.h>
#include "AllTextSquareSolver.h"

void start_intro(void);
void input_choice_text(void);
void output_choice_text(void);
void example_of_input_coefficients(void);
void problem_with_input_one_text(void);
void problem_with_input_three_text(void);

void start_intro(void) {
    printf("                                  y\n");                             
    printf("                                  ^\n");
    printf("                                  |\n");
    printf("                              .-' | '-.\n");
    printf("                            .'    |    '.\n");
    printf("                           /      |      \\\n");
    printf("                          /       |       \\\n");
    printf("                         /        |        \\\n");
    printf("                        /         |         \\\n");
    printf("                       /          |          \\\n");
    printf("                      /           |           \\\n");
    printf("                     /            |            \\\n");
    printf("----------------------------------+---------------------------------> x\n");
    printf("=======================================================================\n");
    printf("||                   ◣ Quadratic Equation Solver ◢                   ||\n");
    printf("=======================================================================\n");
    printf("                           ax^2 + bx + c = 0\n");
    printf("-----------------------------------------------------------------------\n");
}

void input_choice_text(void){
    printf("Please answer whether you want to enter a, b, c by file or by console:\n");
    printf("1 - by file \"InputCoefficients.txt\",\n");
    printf("2 - by console:\n");
}

void output_choice_text(void){
    printf("\n");
    printf("Please answer whether you want to see roots in a file or in a console:\n");
    printf("1 - in the file \"OutputRoots.txt\",\n");
    printf("2 - in the console:\n");
}

void example_of_input_coefficients(void){
    printf("\n");
    printf("Please enter coefficients a, b, c separated by spaces:\n");
    printf("a (float), b (float), c (float)\n");
    printf("Example: 1 -3 2\n");
}
void problem_with_input_one_text(void){
    printf("Input error! You should write just \"1\" or \"2\".\n");
    printf("Try again:\n");
}
void problem_with_input_three_text(void){
    printf("Input error! You should enter three real numbers separated by spaces.\n");
    printf("Try again:\n");
}
