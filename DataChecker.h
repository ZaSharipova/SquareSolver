#include <stdio.h>

long file_size(FILE *file);
void test_check(long double a, long double b, long double c, long double number_of_results_compared, long double result1_compared, long double result2_compared);
bool compare_answers(long double result, long double result_compared);
int unit_test_checker(void);
void parse(long double * ptd1, char * ptr1);
void handle_compare_results(long double *ptd1, long double *ptd2, long count);
int buff_input(const char *filename, long *numbers_count, char **ptr);