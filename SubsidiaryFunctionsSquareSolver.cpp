#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>

#include "EnumsSquareSolver.h"

const long double EPS = 1e-12L;

bool is_zero(long double number);
bool is_negative(long double number);
void sort_result(long double *result1, long double *result2);
void root_zero_checker(long double *result);

bool status_scan_false(int status, int choice_result);
void clear_input_buffer(void);
bool in_out_command_checker(int argc, int i, char * stroke, const char *command);

size_t nums_counter(char * buff, size_t size);

bool is_zero(long double number) {
    return fabsl(number) < EPS;
}

bool is_negative(long double number) {
    return number < -EPS;
}

void sort_result(long double *result1, long double *result2) {
    assert(result1 != NULL);
    assert(result2 != NULL);

    if (*result1 > *result2) {
        long double t = *result1;
        *result1 = *result2;
        *result2 = t;
    } 
}

void root_zero_checker(long double *result){
    assert(result != NULL);

    if (is_zero(*result) && is_negative(*result)){
        *result *= (-1);
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

size_t nums_counter(char * buff, size_t size){
    size_t cnt = 0;
    for (size_t i = 0; i < size; i++){
        if (buff[i] == '\n'){
            cnt++;
        }
    }
    cnt++;
    return cnt * 3;
}