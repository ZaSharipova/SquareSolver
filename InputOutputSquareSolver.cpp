#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <assert.h>

#include "InputOutputSquareSolver.h"
#include "AllTextSquareSolver.h"
#include "EnumsSquareSolver.h"
#include "SubsidiaryFunctionsSquareSolver.h"

bool parse_in(int argc, char * argv[], int *input_choice_result, int i, const char **filename_to_open_input);
bool parse_out(int argc, char * argv[], int *output_choice_result, int i, const char **filename_to_open_output);
int parse_arguments(int argc, char *argv[], int *input_choice_result, int *output_choice_result, const char **filename_to_open_input, const char **filename_to_open_output);

void first_question_in_graphics(int *input_choice_result);
void second_question_in_graphics(int *output_choice_result);

int handle_input(int input_choice_result, float *a, float *b, float *c, const char *filename);
int handle_input_commandline(float *a, float *b, float *c, FILE *file);
int handle_output(int output_choice_result, int number_of_roots, float result1, float result2, const char *filename);
int choice_question(void);
int input(int input_choice_result, FILE *input_file, float *a, float *b, float *c);
int all_file_input(int input_choice_result, float *a, float *b, float *c, const char *filename);
void all_console_input(int input_choice_result, float *a, float *b, float *c, const char *filename);
void output(int output_choice_result, int number_of_roots, float result1, float result2, FILE *file);

int open_file(const char *filename, FILE **file, const char *mode);
int error_printer(int error_type);
int close_file(FILE *file);


int parse_arguments(int argc, char *argv[], int *input_choice_result, int *output_choice_result, const char **filename_to_open_input, const char **filename_to_open_output) { 
    assert(input_choice_result != NULL);
    assert(output_choice_result != NULL);
    assert(filename_to_open_input != NULL);
    assert(filename_to_open_output != NULL);

    if (argc > 1) {
        int i = 1;
        bool flag_input = false;
        bool flag_output = false;

        while (i < argc){
            if (parse_in(argc, argv, input_choice_result, i, filename_to_open_input)){
                flag_input = true;
    
            } else if (parse_out(argc, argv, output_choice_result, i, filename_to_open_output)){
                flag_output = true;

            } else{
                return kBadInputCommands;
            }
            i+=2;
        }
        if (!flag_input || !flag_output){
            return kBadInputCommands;
        }
    } else {
        first_question_in_graphics(input_choice_result);
        second_question_in_graphics(output_choice_result);
    }
    return kNoError;

}

bool parse_in(int argc, char *argv[], int *input_choice_result, int i, const char **filename_to_open_input){
    assert(argv != NULL);
    assert(filename_to_open_input != NULL);

    if (in_out_command_checker(argc, i, argv[i], in_command)){
        i++;
        if (strcmp(argv[i], "console") == 0){
            *input_choice_result = kConsole;

        } else if (strcmp(argv[i], "file") == 0){
            *input_choice_result = kFile;

        } else{
            *input_choice_result = kFile;
            *filename_to_open_input = argv[i];
        }
        return true;
    }
    return false;
}

bool parse_out(int argc, char * argv[], int *output_choice_result, int i, const char **filename_to_open_output){
    assert(argv != NULL);
    assert(filename_to_open_output != NULL);

    if (in_out_command_checker(argc, i, argv[i], out_command)){
        i++;
        if (strcmp(argv[i], "console") == 0){
            *output_choice_result = kConsole;

        } else if (strcmp(argv[i], "file") == 0){
            *output_choice_result = kFile;
            
        } else{
            *output_choice_result = kFile;
            *filename_to_open_output = argv[i];
        }
        return true;
    }
    return false;
}

void first_question_in_graphics(int *input_choice_result) {
    assert(input_choice_result != NULL);

    start_intro();
    input_choice_text();
    *input_choice_result = choice_question();
}

void second_question_in_graphics(int *output_choice_result){
    assert(output_choice_result != NULL);

    output_choice_text();
    *output_choice_result = choice_question();
}

int handle_input(int input_choice_result, float *a, float *b, float *c, const char *filename) {
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);
    assert(filename != NULL);

    int err = kNoError;
 
    if (input_choice_result == kFile) {
        err = all_file_input(input_choice_result, a, b, c, filename);
        if (err != kNoError){
            return err;
        }

        // if (error_printer(err) == kBadInputGraphics) {
        //     err = close_file(file);
        //     if (err == kErrorClosing){
        //         problem_with_input_three_text_file();
        //         return kErrorClosing;
        //     }
        //     return kBadInputGraphics;
        // }

    } else {
        all_console_input(input_choice_result, a, b, c, filename);
    }
 
    return kNoError;
}

int all_file_input(int input_choice_result, float *a, float *b, float *c, const char *filename){
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);
    assert(filename != NULL);

    FILE *file = NULL;
    int err = kNoError;

    err = open_file(filename, &file, read_mode);

    if (err != kNoError){
        return err;
    }
 
    err = input(input_choice_result, file, a, b, c);

    if (err != kNoError){
        return kBadInputGraphics;
    }

    err = close_file(file);
    if (err != kNoError) {
        return kErrorClosing;
    }
    return kNoError;
}

void all_console_input(int input_choice_result, float *a, float *b, float *c, const char *filename) {
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);
    assert(filename != NULL);

    FILE *file = NULL;

    example_of_input_coefficients();
    file = stdin;
    input(input_choice_result, file, a, b, c);
}

int handle_output(int output_choice_result, int number_of_roots, float result1, float result2, const char *filename_to_open_output) {
    assert(filename_to_open_output != NULL);

    FILE *file = NULL;
    int err = kNoError;
 
    if (output_choice_result == kFile) {

        err = open_file(filename_to_open_output, &file, write_mode);
 
        output(output_choice_result, number_of_roots, result1, result2, file);
 
        err = close_file(file);
        if (err != kNoError) {
            return kErrorClosing;
        }

    } else {
        output(output_choice_result, number_of_roots, result1, result2, stdout);
    }
 
    return kNoError;
}

int open_file(const char *filename, FILE **file, const char *mode) {
    assert(mode != NULL);
    assert(filename != NULL);
    assert(mode != NULL);
    assert(file != NULL);

    *file = fopen(filename, mode);

    if (*file == NULL){
        return kErrorOpening;
    }

    return kNoError;
}

int close_file(FILE *file) {
    assert(file != NULL);

    int status = fclose(file);
    if (status != 0) {
        return kErrorClosing;
    }
    return kNoError;
}

int choice_question(void) {
    int choice_result = kConsole;
    int status = 0;

    do{
        status = scanf("%d", &choice_result);
        if (status_scan_false(status, choice_result)) {
            problem_with_input_one_text();
            clear_input_buffer();
        }

    } while (status_scan_false(status, choice_result));

    return choice_result;
}

int input(int input_choice_result, FILE *input_file, float *a, float *b, float *c) {
    assert(input_file != NULL);
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);

    int status = fscanf(input_file, "%f %f %f", a, b, c);
    if (status != 3){
        if (input_choice_result == kFile) {
            return kBadInputGraphics;
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

int error_printer(int error_type){
    switch (error_type){
    case kNoError:
        return kNoError;

    case kErrorOpening:
        fprintf(stderr, "Error while opening file.\n");
        return kErrorOpening;

    case kErrorClosing:
        fprintf(stderr, "Error while closing file.\n");
        return kErrorClosing;

    case kBadInputCommands:
        fprintf(stderr, "Input error.\n");
        return kBadInputCommands;

    case kBadInputGraphics:
        problem_with_input_three_text_file();
        return kBadInputGraphics;
        
    default:
        assert(0 && "Invalid error\n");
    }

    return kNoError;
}

void output(int output_choice_result, int number_of_roots, float result1, float result2, FILE *file) {
    assert(file != NULL);

    printf("\n");

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
        fprintf(stdout, "Roots are already in a file.\n");
    }
}