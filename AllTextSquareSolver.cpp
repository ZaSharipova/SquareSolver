#include <stdio.h>
#include "AllTextSquareSolver.h"
#include "EnumsSquareSolver.h"

void start_intro(void);
void input_choice_text(void);
void output_choice_text(void);
void example_of_input_coefficients(void);
void problem_with_input_one_text(void);
void problem_with_input_three_text(void);
void problem_with_input_three_text_file(void);
void assert_true(void);

void start_intro(void) {
    printf(BLUE "                                  y\n" RESET);                             
    printf(BLUE "                                  ^\n" RESET);
    printf(BLUE "                                  |\n" RESET);
    printf(BLUE "                              .-' | '-.\n" RESET);
    printf(BLUE "                            .'    |    '.\n" RESET);
    printf(BLUE "                           /      |      \\\n" RESET);
    printf(BLUE "                          /       |       \\\n" RESET);
    printf(BLUE "                         /        |        \\\n" RESET);
    printf(BLUE "                        /         |         \\\n" RESET);
    printf(BLUE "                       /          |          \\\n" RESET);
    printf(BLUE "                      /           |           \\\n" RESET);
    printf(BLUE "                     /            |            \\\n" RESET);
    printf(BLUE "----------------------------------+---------------------------------> x\n" RESET);
    printf("=======================================================================\n");
    printf("||                  " RED " ◣ Quadratic Equation Solver ◢" RESET "                   ||\n");
    printf("=======================================================================\n");
    printf("                            " GREEN "ax^2 + bx + c = 0\n" RESET);
    printf("-----------------------------------------------------------------------\n");
}

void input_choice_text(void){
    printf("Please answer whether you want to enter " YELLOW "a" RESET ", " YELLOW "b" RESET ", " YELLOW "c" RESET " by file or by console:\n");
    printf(BLUE "1" RESET " - by file \"InputCoefficients.txt\",\n");
    printf(BLUE "2" RESET " - by console:\n");
}

void output_choice_text(void){
    printf("\n");
    printf("Please answer whether you want to see roots in a file or in a console:\n");
    printf(BLUE "1" RESET " - in the file \"OutputRoots.txt\",\n");
    printf(BLUE "2" RESET " - in the console:\n");
}

void example_of_input_coefficients(void){
    printf("\n");
    printf("Please enter coefficients " YELLOW "a" RESET ", " YELLOW "b" RESET ", " YELLOW "c" RESET " separated by spaces:\n");
    printf(YELLOW "a" RESET " (float), " YELLOW "b" RESET " (float), " YELLOW "c" RESET " (float)\n");
    printf("Example:" CYAN " 1 -3 2\n" RESET);
}
void problem_with_input_one_text(void){
    printf("Input error! You should write just "  BLUE "1" RESET " or " BLUE "2" RESET ".\n");
    printf("Try again:\n");
}
void problem_with_input_three_text(void){
    printf(RED "Input error! You should enter three real numbers separated by spaces.\n" RESET);
    printf("Try again:\n");
}

void problem_with_input_three_text_file(void) {
    fprintf(stderr, RED "Input error! You should have entered three real numbers separated by spaces.\n" RESET);
    fprintf(stderr, RED "Rewrite numbers in the file or enter them in the console in the next Run.\n" RESET);
}

void assert_true(void){
    fprintf(stderr, RED "Assertion failed: file %s line %d\n" RESET,  __FILE__, __LINE__); 
    fprintf(stderr, RED "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n" RESET);
    fprintf(stderr, RED "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n\n" RESET);
    fprintf(stderr, RED "                    Assert failed!!! \n\n" RESET);
    fprintf(stderr, RED "             You are loser aahhahahahahahhah \n\n" RESET);
}