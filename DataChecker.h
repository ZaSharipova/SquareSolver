#include <stdio.h>

int unit_test_checker(void);
size_t file_size(FILE *file);
int all_file_test(const char *filename, size_t *numbers_count, char **ptr, long double **ptd);
void parse(long double * ptd, char * ptr);
void handle_compare_results(long double *ptd1, long double *ptd2, size_t count);
int buff_input(const char *filename, size_t *numbers_count, char **ptr);
void test_check(long double a, long double b, long double c, long double number_of_results_compared, long double result1_compared, long double result2_compared);
bool compare_answers(long double result, long double result_compared);