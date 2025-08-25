#include <stdio.h>
#include <cmath>
#include <limits.h>
#include <assert.h>

#include "RootsFinderSquareSolver.h"
#include "SubsidiaryFunctionsSquareSolver.h"

long double find_result(long double a, long double b, long double c, long double *result1, long double *result2);
long double calculate_discriminant(long double a, long double b, long double c);
long double find_linear_root(long double b, long double c, long double *result1);
long double find_quadratic_roots(long double a, long double b, long double c, long double *result1, long double *result2);

long double find_result(long double a, long double b, long double c, long double *result1, long double *result2) {
    assert(result1 != NULL);
    assert(result2 != NULL);

    if (is_zero(a)) {
        return find_linear_root(b, c, result1);
    } 
    return find_quadratic_roots(a, b, c, result1, result2);
}

long double calculate_discriminant(long double a, long double b, long double c) {
    return b * b - 4 * a * c;
}

long double find_linear_root(long double b, long double c, long double *result1) {
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

long double find_quadratic_roots(long double a, long double b, long double c, long double *result1, long double *result2) {
    assert(result1 != NULL);
    assert(result2 != NULL);

    long double discriminant = calculate_discriminant(a, b, c);

    if (!is_negative(discriminant)){
        if (is_zero(discriminant)) { 
            *result1 = -b / (2 * a);
            return kOneRoot;

        } else {
            *result1 = (-b + sqrtl(discriminant)) / (2 * a);
            *result2 = (-b - sqrtl(discriminant)) / (2 * a);
            sort_result(result1, result2);
            root_zero_checker(result1);
            root_zero_checker(result2);
            return kTwoRoots;
        }
    }

    return kZeroRoots; 
}