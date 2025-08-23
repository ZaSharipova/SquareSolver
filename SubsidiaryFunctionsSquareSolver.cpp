#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>

#include "EnumsSquareSolver.h"

const float EPS = 1e-6f;

bool is_zero(float number);
bool is_negative(float number);
void sort_result(float *result1, float *result2);
void root_zero_checker(float *result1);

bool status_scan_false(int status, int choice_result);
void clear_input_buffer(void);
bool in_out_command_checker(int argc, int i, char * stroke, const char *command);

bool is_zero(float number) {
    return fabsf(number) < EPS;
}

bool is_negative(float number) {
    return number < -EPS;
}

void sort_result(float *result1, float *result2) {
    assert(result1 != NULL);
    assert(result2 != NULL);

    if (*result1 > *result2) {
        float t = *result1;
        *result1 = *result2;
        *result2 = t;
    } 
}

void root_zero_checker(float *result1){
    assert(result1 != NULL);

    if (is_zero(*result1) && is_negative(*result1)){
        *result1*=(-1);
    }
}

bool status_scan_false(int status, int choice_result){
    return (status != 1 || (choice_result != kFile && choice_result != kConsole));
}

void clear_input_buffer(void) {
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF) {
        ;
    }
}

bool in_out_command_checker(int argc, int i, char * stroke, const char *command){
    return (strcmp(stroke, command) == 0) && (i + 1 < argc);
}
