#include <stdio.h>
#include "EnumsSquareSolver.h"

bool parse_in(int argc, char * argv[], int *input_choice_result, int i, const char **filename_to_open_input);
bool parse_out(int argc, char * argv[], int *output_choice_result, int i, const char **filename_to_open_output);
int parse_arguments(int argc, char *argv[], int *input_choice_result, int *output_choice_result, const char **filename_to_open_input, const char **filename_to_open_output);

void first_question_in_graphics(int *input_choice_result);
void second_question_in_graphics(int *output_choice_result);
int handle_input(int input_choice_result, float *a, float *b, float *c, const char *filename);
int handle_output(int output_choice_result, int number_of_roots, float result1, float result2, const char *filename);
int choice_question(void);
int input(int input_choice_result, FILE *input_file, float *a, float *b, float *c);
void clear_input_buffer(void);
int error_printer(int error_type);
void output(int output_choice_result, int number_of_roots, float result1, float result2, FILE *file);
int open_file(const char *filename, FILE **file, const char *mode);
int close_file(FILE *file);

int all_file_input(int input_choice_result, float *a, float *b, float *c, const char *filename);
void all_console_input(int input_choice_result, float *a, float *b, float *c, const char *filename);