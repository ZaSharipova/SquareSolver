#include <stdio.h>
#include <limits.h>

enum RootsCount{
    kZeroRoots = 0,
    kOneRoot   = 1,
    kTwoRoots  = 2,
    kInfRoots  = INT_MAX,
};

int find_result(float a, float b, float c, float *result1, float *result2);
bool is_zero(float number);
bool is_negative(float number);
float calculate_discriminant(float a, float b, float c);
int find_linear_root(float b, float c, float *result1);
int find_quadratic_roots(float a, float b, float c, float *result1, float *result2);
void sort_result(float *result1, float *result2);