#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <assert.h>
#include <math.h>
#include <sys/types.h>
#include <unistd.h>

#include "RootsFinderSquareSolver.h"
#include "InputOutputSquareSolver.h"
#include "DataChecker.h"
#include "EnumsSquareSolver.h"
#include "SubsidiaryFunctionsSquareSolver.h"

const long double EPSL = 1e-4L;

int unit_test_checker(void);
long file_size(FILE *file);
int all_file_test(const char *filename, long *numbers_count, char **ptr, long double **ptd);
void parse(long double * ptd1, char * ptr1);
void handle_compare_results(long double *ptd1, long double *ptd2, long count);
int buff_input(const char *filename, long *numbers_count, char **ptr);
void test_check(long double a, long double b, long double c, long double number_of_results_compared, long double result1_compared, long double result2_compared);
bool compare_answers(long double result, long double result_compared);

int unit_test_checker(void){
    char *ptr = NULL;
    long double *ptd1 = NULL;
    long double *ptd2 = NULL;
    int err = kNoError;
    long numbers_count = 0;

    const char *filename = "data.in";
    err = all_file_test(filename, &numbers_count, &ptr, &ptd1);
    if (err != kNoError){
        return err;
    }

    char *ptr1 = NULL;
    filename = "data.out";
    err = all_file_test(filename, &numbers_count, &ptr1, &ptd2);
    if (err != kNoError){
        return err;
    }

    handle_compare_results(ptd1, ptd2, numbers_count);

    free(ptd1);
    free(ptd2);
    return kErrorTest;
}

long file_size(FILE *file){
    assert(file != NULL);

    long saved_pos = ftell(file);
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, saved_pos, SEEK_SET);

    return size;
}

int all_file_test(const char *filename, long *numbers_count, char **ptr, long double **ptd){
    assert(filename != NULL);
    assert(numbers_count != NULL);
    assert(ptr != NULL);
    assert(ptd != NULL);

    int err = buff_input(filename, numbers_count, ptr);
    if (err != kNoError){
        return err;
    }

    *ptd = (long double *) calloc (*numbers_count, sizeof(long double));
    assert(ptd != NULL);

    parse(*ptd, *ptr);
    free(*ptr);

    return err;
}

int buff_input(const char *filename, long *numbers_count, char **ptr) {
    assert(filename != NULL);
    assert(numbers_count != NULL);
    assert(ptr != NULL);

    FILE * file = NULL;
    int err = open_file(filename, &file, "r");
    long size = file_size(file);

    char *buff = (char *) calloc (size, sizeof(char));

    fread(buff, sizeof buff[0], size, file);
    if (strcmp(filename, "data.in") == 0){
        *numbers_count = nums_counter(buff, size);
    }

    *ptr = buff;

    fclose(file);

    return err;
}

void parse(long double * ptd1, char * ptr1) {
    assert(ptd1 != NULL);
    assert(ptr1 != NULL);

    int cnt = 0;
    int i = 0;

    while (sscanf(ptr1, "%Lf %Lf %Lf %n", &ptd1[i], &ptd1[i + 1], &ptd1[i + 2], &cnt) != EOF){
        ptr1 += cnt;
        i+=3;
    }

}

void handle_compare_results(long double *ptd1, long double *ptd2, long count) {
    assert(ptd1 != NULL);
    assert(ptd2 != NULL);
    
    for (int j = 0; j < count; j += 3) {

        long double a = ptd1[j];
        long double b = ptd1[j + 1];
        long double c = ptd1[j + 2];

        long double number_of_results_compared = ptd2[j];
        long double result1_compared = ptd2[j + 1];
        long double result2_compared = ptd2[j + 2];

        test_check(a, b, c, number_of_results_compared, result1_compared, result2_compared);
    }
}

void test_check(long double a, long double b, long double c, long double number_of_results_compared, long double result1_compared, long double result2_compared){

    long double result1 = NAN, result2 = NAN;
    long double number_of_results = find_result(a, b, c, &result1,  &result2);

    if (abs(number_of_results - INT_MAX) < EPSL){
        number_of_results = 3;
    }

    if (!(compare_answers(result1, result1_compared) && (compare_answers(result2, result2_compared)) && compare_answers(number_of_results, number_of_results_compared))){
            printf("Wrong answer to coefficients a = %Lf, b = %Lf, c = %Lf. Your answers: number_of_roots = %Lf, x1 = %Lf, x2 = %Lf. Right answers: number_of_roots = %Lf, x1 = %Lf, x2 = %Lf\n", 
            a, b, c, number_of_results, result1, result2, number_of_results_compared, result1_compared, result2_compared);
    } else{
        printf("OK\n");
    }
}

bool compare_answers(long double result, long double result_compared){
    if (isnan(result) && isnan(result_compared)){
        return true;
    }
    return (fabsl(result - result_compared) < EPSL);
}


