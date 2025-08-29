#include "SubsidiaryFunctionsSquareSolver.h"

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>

#include "EnumsSquareSolver.h"

const double EPS = 1e-12;

bool is_zero(double number) {
    return fabs(number) < EPS;
}

bool is_negative(double number) {
    return number < -EPS;
}

void sort_result(double *result1, double *result2) {
    assert(result1 != NULL);
    assert(result2 != NULL);

    if (*result1 > *result2) {
        double t = *result1;
        *result1 = *result2;
        *result2 = t;
    } 
}

void root_zero_checker(double *result) {
    assert(result != NULL);

    if (is_zero(*result) && is_negative(*result)) {
        *result *= (-1);
    }
}

void clear_input_buffer(void) {
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF) {
        ;
    }
}

bool in_out_command_checker(int argc, int i, char * stroke, const char *command) {
    assert(stroke  != NULL);
    assert(command != NULL);
    
    return (strcmp(stroke, command) == 0) && (i + 1 < argc);
}

size_t nums_counter(char * buff, size_t size) {
    size_t cnt = 0;
    for (size_t i = 0; i < size; i++) {
        if (buff[i] == '\n') {
            cnt++;
        }
    }
    cnt++;
    return cnt * 3;
}