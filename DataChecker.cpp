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
#include "AllTextSquareSolver.h"
#include "InputOutputDefines.h"

const double EPSL = 1e-5L;

PossibleErrors unit_test_checker(SolutionArguments *solver) {
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
        
    handle_compare_results(ptd1, ptd2, numbers_count, solver);
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
    PossibleErrors err = open_file(filename, &file, READ_MODE);
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

void handle_compare_results(double *ptd1, double *ptd2, size_t count, SolutionArguments *solver) {
    assert(ptd1 != NULL);
    assert(ptd2 != NULL);

    struct SolutionArgumentsCompared Compare;

    for (size_t j = 0; j < count; j += 3) {
        Compare.a = ptd1[j];
        Compare.b = ptd1[j + 1];
        Compare.c = ptd1[j + 2];
        
        Compare.number_of_roots_compared = (RootsCount)ptd2[j];
        Compare.result1_compared = ptd2[j + 1];
        Compare.result2_compared = ptd2[j + 2];

        test_check(&Compare, solver);
    }
}

void test_check(SolutionArgumentsCompared *Compare, SolutionArguments *solver) {
    assert(Compare != NULL);

    solver->a = Compare->a, solver->b = Compare->b, solver->c = Compare->c;

    solver->result1 = NAN, solver->result2 = NAN;
    solver->number_of_roots = find_result(solver);

    if (!(compare_answers(solver->result1, Compare->result1_compared) && (compare_answers(solver->result2, Compare->result2_compared)) 
    && ((solver->number_of_roots) == (Compare->number_of_roots_compared)))) {
        print_wrong_answers(Compare, solver);
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