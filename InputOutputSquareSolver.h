#include <stdio.h>

enum PossibleErrors{
    kNoError      =  0,
    kErrorOpening = -1,
    kBadInput     = -2,
    kErrorClosing = -3,
};

enum TypeOfInputOutput{
    kFile = 1,
    kConsole = 2,
};


int handle_input(int input_choice_result, float *a, float *b, float *c);
int handle_output(int output_choice_result, int number_of_roots, float result1, float result2);
int choice_question(void);
int input(int input_choice_result, FILE *input_file, float *a, float *b, float *c);
void clear_input_buffer(void);
int error_printer(int error_type);
void output(int output_choice_result, int number_of_roots, float result1, float result2, FILE *file);
int open_file(const char *filename, FILE **file);
int close_file(FILE *file);

