#include <stdio.h>
#include <string.h>
#include <limits.h>

#include "InputOutputSquareSolver.h"
#include "AllTextSquareSolver.h"
#include "RootsFinderSquareSolver.h"

int handle_input(int input_choice_result, float *a, float *b, float *c);
int handle_output(int output_choice_result, int number_of_roots, float result1, float result2);
int choice_question(void);
int input(int input_choice_result, FILE *input_file, float *a, float *b, float *c);
void clear_input_buffer(void);
void output(int output_choice_result, int number_of_roots, float result1, float result2, FILE *file);
int open_file(const char *filename, FILE **file);
int error_printer(int error_type);
int close_file(FILE *file);

int handle_input(int input_choice_result, float *a, float *b, float *c) {
    FILE *file = NULL;
    int err = kNoError;
 
    if (input_choice_result == kFile) {
        err = open_file("InputCoefficients.txt", &file);
        if (error_printer(err)) return err;
 
        err = input(input_choice_result, file, a, b, c);
        if (error_printer(err)) return err;
 
        err = close_file(file);
        if (error_printer(err)) return err;
    } else {
        example_of_input_coefficients();
        file = stdin;
        err = input(input_choice_result, file, a, b, c);
        if (error_printer(err)) return err;
    }
 
    return kNoError;
}

int handle_output(int output_choice_result, int number_of_roots, float result1, float result2) {
    FILE *file = NULL;
    int err = kNoError;
 
    if (output_choice_result == kFile) {
        err = open_file("OutputRoots.txt", &file);
        if (error_printer(err)) return err;
 
        output(output_choice_result, number_of_roots, result1, result2, file);
 
        err = close_file(file);
        if (error_printer(err)) return err;
    } else {
        output(output_choice_result, number_of_roots, result1, result2, stdout);
    }
 
    return kNoError;
}

int open_file(const char *filename, FILE **file) {
    if (strcmp(filename, "InputCoefficients.txt") == 0) {
        *file = fopen(filename, "r");
    } else {
        *file = fopen(filename, "w");
    }

    if (*file == NULL) {
        return kErrorOpening;
    }

    return kNoError;
}

int close_file(FILE *file) {
    int status = fclose(file);
    if (status != 0) {
        return kErrorClosing;
    }
    return kNoError;
}

int choice_question(void) {
    TypeOfInputOutput choice_result = kConsole;
    int status = 0;

    do{
        status = scanf("%d", &choice_result);
        if (status != 1 || (choice_result != kFile && choice_result != kConsole)) {
            problem_with_input_one_text();
            clear_input_buffer();
        }
    } while (status != 1 || (choice_result != kFile && choice_result != kConsole));

    return choice_result;
}

int input(int input_choice_result, FILE *input_file, float *a, float *b, float *c) {

    int status = fscanf(input_file, "%f %f %f", a, b, c);
    if (status != 3){
        if (input_choice_result == kFile) {
            return kBadInput;
        }
        else{
            while (status != 3) {
                problem_with_input_three_text();
                clear_input_buffer();
                status = fscanf(input_file, "%f %f %f", a, b, c);
            }
        }
    }

    return kNoError;
}


void clear_input_buffer(void) {
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF) {;}
}

int error_printer(int error_type){
    switch (error_type){
    case kNoError:
        return 0;
    case kErrorOpening:
        fprintf(stderr, "Error while opening file.\n");
        break;
    case kErrorClosing:
        fprintf(stderr, "Error while closing file.\n");
        break;
    case kBadInput:
        fprintf(stderr, "Input error! You should have entered three real numbers separated by spaces.\n");
        fprintf(stderr, "Rewrite numbers in the file or enter them in the console in the next Run.\n");
        break;
    }
    return 1;
}
void output(int output_choice_result, int number_of_roots, float result1, float result2, FILE *file) {
    if (output_choice_result == kConsole) {printf("\n");}

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

    if (output_choice_result == kFile){
        fprintf(stdout, "\n");
        fprintf(stdout, "Roots are already in a file \"OutputRoots.txt\"\n");
    }
}