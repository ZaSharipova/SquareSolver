#include <stdio.h>
#include <limits.h>
#include "EnumsSquareSolver.h"

int find_result(float a, float b, float c, float *result1, float *result2);
float calculate_discriminant(float a, float b, float c);
int find_linear_root(float b, float c, float *result1);
int find_quadratic_roots(float a, float b, float c, float *result1, float *result2);
void root_zero_checker(float *result1);