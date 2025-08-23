#include <stdio.h>
#include <cmath>
#include <limits.h>
#include <assert.h>
#include "RootsFinderSquareSolver.h"
#include "SubsidiaryFunctionsSquareSolver.h"

int find_result(float a, float b, float c, float *result1, float *result2);
float calculate_discriminant(float a, float b, float c);
int find_linear_root(float b, float c, float *result1);
int find_quadratic_roots(float a, float b, float c, float *result1, float *result2);

int find_result(float a, float b, float c, float *result1, float *result2) {
    assert(result1 != NULL);
    assert(result2 != NULL);

    if (is_zero(a)) {
        return find_linear_root(b, c, result1);
    } 
    return find_quadratic_roots(a, b, c, result1, result2);
}

float calculate_discriminant(float a, float b, float c) {
    return b * b - 4 * a * c;
}

int find_linear_root(float b, float c, float *result1) {
    assert(result1 != NULL);

    if (!is_zero(b)) {
            *result1 = -c / b;
            return kOneRoot;
    } else {
        if (is_zero(c)) {
            return kInfRoots;
        }
        return kZeroRoots;
    }
}

int find_quadratic_roots(float a, float b, float c, float *result1, float *result2) {
    assert(result1 != NULL);
    assert(result2 != NULL);

    float discriminant = calculate_discriminant(a, b, c);

    if (!is_negative(discriminant)){
        if (is_zero(discriminant)) { 
            *result1 = -b / (2 * a);
            return kOneRoot;

        } else {
            *result1 = (-b + sqrtf(discriminant)) / (2 * a);
            *result2 = (-b - sqrtf(discriminant)) / (2 * a);
            sort_result(result1, result2);
            root_zero_checker(result1);
            root_zero_checker(result2);
            return kTwoRoots;
        }
    }

    return kZeroRoots; 
}