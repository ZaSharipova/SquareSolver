#include "DataChecker.h"

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <assert.h>
#include <math.h>

#include "RootsFinderSquareSolver.h"
#include "EnumsSquareSolver.h"
#include "SubsidiaryFunctionsSquareSolver.h"
#include "FileOperations.h"

const double EPSL = 1e-5L;

PossibleErrors unit_test_checker(void) {
    char *ptr = NULL;
    double *ptd1 = NULL;
    double *ptd2 = NULL;

    PossibleErrors err = kNoError;
    size_t numbers_count = 0;

    const char *filename = "data.in";

    err = all_file_test(filename, &numbers_count, &ptr, &ptd1);
    if (err != kNoError) {
        free(ptd1);
        return err;
    }
        
    filename = "data.out";
    err = all_file_test(filename, &numbers_count, &ptr, &ptd2);
    if (err != kNoError) {
        free(ptd1);
        free(ptd2);
        return err;
    }
        
    handle_compare_results(ptd1, ptd2, numbers_count);
    free(ptd1);
    free(ptd2);
        
    return err;
}

size_t file_size(FILE *file) {
    assert(file != NULL);

    long saved_pos = ftell(file);
    assert(saved_pos != -1L); 

    long seek_ret = fseek(file, 0, SEEK_END);
    assert(seek_ret == 0); 

    long size = ftell(file);
    assert(size != -1L); 

    seek_ret = fseek(file, saved_pos, SEEK_SET);
    assert(seek_ret == 0);

    return (size_t)size;
}

PossibleErrors all_file_test(const char *filename, size_t *numbers_count, char **ptr, double **ptd) {
    assert(filename != NULL);
    assert(numbers_count != NULL);
    assert(ptr != NULL);
    assert(ptd != NULL);

    PossibleErrors err = buff_input(filename, numbers_count, ptr);
    if (err != kNoError) {
        return err;
    }

    *ptd = (double *) calloc (*numbers_count, sizeof(double));
    assert(ptd != NULL);

    parse(*ptd, *ptr);
    free(*ptr);

    return err;
}

PossibleErrors buff_input(const char *filename, size_t *numbers_count, char **ptr) {
    assert(filename != NULL);
    assert(numbers_count != NULL);
    assert(ptr != NULL);

    FILE * file = NULL;
    PossibleErrors err = open_file(filename, &file, "r");
    if (err != kNoError) {
        return err;
    }

    size_t size = file_size(file);

    char *buff = (char *) calloc (size + 1, sizeof(char));

    fread(buff, sizeof buff[0], size, file);
    buff[size] = '\0';

    if (strcmp(filename, "data.in") == 0) {
        *numbers_count = nums_counter(buff, size);
    }

    *ptr = buff;

    err = close_file(file);
    if (err != kNoError) {
        return err;
    }

    return kNoError;
}

void parse(double * ptd, char * ptr) {
    assert(ptd != NULL);
    assert(ptr != NULL);

    int cnt = 0;
    int i = 0;

    int nums = 0;
    while ((nums = sscanf(ptr, "%lf %lf %lf %n", &ptd[i], &ptd[i + 1], &ptd[i + 2], &cnt)) != EOF) {
        ptr += cnt;
        i += 3;
    }

}

void handle_compare_results(double *ptd1, double *ptd2, size_t count) {
    assert(ptd1 != NULL);
    assert(ptd2 != NULL);

    for (size_t j = 0; j < count; j += 3) {

        double a = ptd1[j];
        double b = ptd1[j + 1];
        double c = ptd1[j + 2];

        RootsCount number_of_results_compared = (RootsCount)ptd2[j];
        double result1_compared = ptd2[j + 1];
        double result2_compared = ptd2[j + 2];

        test_check(a, b, c, number_of_results_compared, result1_compared, result2_compared);
    }
}

void test_check(double a, double b, double c, RootsCount number_of_results_compared, double result1_compared, double result2_compared) {

    double result1 = NAN, result2 = NAN;
    RootsCount number_of_results = find_result(a, b, c, &result1,  &result2);

    if (!(compare_answers(result1, result1_compared) && (compare_answers(result2, result2_compared)) && (number_of_results == number_of_results_compared))) {
        printf("Wrong answer to coefficients a = %lf, b = %lf, c = %lf. Your answers: number_of_roots = %d, x1 = %lf, x2 = %lf. Right answers: number_of_roots = %d, x1 = %lf, x2 = %lf\n", 
        a, b, c, number_of_results, result1, result2, number_of_results_compared, result1_compared, result2_compared);
    } else {
        printf("OK\n");
    }
}

bool compare_answers(double result, double result_compared) {
    if (isnan(result) && isnan(result_compared)) {
        return true;
    }
    return (fabsl(result - result_compared) < EPSL);
}