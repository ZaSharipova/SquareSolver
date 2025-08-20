#include <stdio.h>
#include <limits.h>
#include "InstructorSquareSolver.h"

extern float a, b, c;
extern float result1, result2;
extern int number_of_roots;

void start_intro(void);

int input_choice(void);
int output_choice(void);
int input_transfer(int input_choice_result); 
int input_with_file(void);
void input_with_console(void);
void clear_input_buffer(void);
int output(int output_choice_result);

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

int input_choice(void) {
    printf("Please answer whether you want to enter a, b, c by file or by console:\n");
    printf("1 - by file \"InputCoefficients.txt\",\n");
    printf("2 - by console:\n");

    int input_choice_result = 0;
    int status = 0;

    do{
        status = scanf("%d", &input_choice_result);
        if (status != 1 || (input_choice_result != 1 && input_choice_result != 2)){
            printf("Input error! You should write just \"1\" or \"2\".\n");
            printf("Try again:\n");
            clear_input_buffer();
        }
    } while (status != 1 || (input_choice_result != 1 && input_choice_result != 2));
    return input_choice_result;
    
}

int output_choice(void) {
    printf("\n");
    printf("Please answer whether you want to see roots in a file or in a console:\n");
    printf("1 - in the file \"OutputRoots.txt\",\n");
    printf("2 - in the console:\n");

    int output_choice_result = 0;
    int status = 0;

    do{
        status = scanf("%d", &output_choice_result);
        if (status != 1 || (output_choice_result != 1 && output_choice_result != 2)){
            printf("Input error! You should write just \"1\" or \"2\".\n");
            printf("Try again:\n");
            clear_input_buffer();
        }
    } while (status != 1 || (output_choice_result != 1 && output_choice_result != 2));
    
    return output_choice_result;
}

int input_transfer(int input_choice_result){
    if (input_choice_result == 1){
        return input_with_file();
    } else{
        input_with_console();
        return 0;
    }
}
int input_with_file(void) {
    FILE *input = NULL;

    input = fopen("InputCoefficients.txt", "r");
    if (input == NULL) {
        return -2;
    }

    int status = fscanf(input, "%f %f %f", &a, &b, &c);
    if (status != 3) {
        fclose(input);
        return -1;
    }

    fclose(input);
    return 0;
}

void input_with_console(void) {

    int status = 0;

    printf("\n");
    printf("Please enter coefficients a, b, c separated by spaces:\n");
    printf("a (float), b (float), c (float)\n");
    printf("Example: 1 -3 2\n");

    do {
        status = scanf("%f %f %f", &a, &b, &c);
        if (status != 3){
            printf("Input error! You should enter three real numbers separated by spaces.\n");
            printf("Try again:\n");
            clear_input_buffer();
        }
    } while (status != 3);
}

void clear_input_buffer(void) {
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF) {;}
}

int output(int output_choice_result) {
    FILE *file = NULL;
    if (output_choice_result == 1){
        file = fopen("OutputRoots.txt", "w");

        if (file == NULL) {
            return -1;
        }
    } else {
        file = stdout;
        fprintf(file, "\n");
    }

    switch (number_of_roots) {
    case kZeroRoots: 
        fprintf(file, "This equation has 0 roots.\n");
        break;
    case kOneRoot: 
        fprintf(file, "This equation has 1 root : %.3f.\n", result1);
        break;
    case kTwoRoots:
        fprintf(file, "This equation has 2 roots : %.3f and %.3f.\n", result1, result2);
        break;
    case kInfRoots: 
        fprintf(file, "This equation has infinitely many roots.\n");
        break;
    }
    if (output_choice_result == 1){
        fprintf(stdout, "Roots are already in a file \"OutputRoots.txt\"\n");
        fclose(file);
    }
    return 0;
}