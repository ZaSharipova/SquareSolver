#include "RootsFinderSquareSolver.h"

#include <stdio.h>
#include <cmath>
#include <limits.h>
#include <assert.h>

#include "SubsidiaryFunctionsSquareSolver.h"

RootsCount find_result(double a, double b, double c, double *result1, double *result2) {
    assert(result1 != NULL);
    assert(result2 != NULL);

    if (is_zero(a)) {
        return find_linear_root(b, c, result1);
    } 
    return find_quadratic_roots(a, b, c, result1, result2);
}

double calculate_discriminant(double a, double b, double c) {
    return b * b - 4 * a * c;
}

RootsCount find_linear_root(double b, double c, double *result1) {
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

RootsCount find_quadratic_roots(double a, double b, double c, double *result1, double *result2) {
    assert(result1 != NULL);
    assert(result2 != NULL);

    double discriminant = calculate_discriminant(a, b, c);

    if (!is_negative(discriminant)) {
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