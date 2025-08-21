#include <stdio.h>
#include <cmath>
#include <limits.h>
#include "RootsFinderSquareSolver.h"

const float EPS = 1e-6f;

int find_result(float a, float b, float c, float *result1, float *result2);
bool is_zero(float number);
bool is_negative(float number);
float calculate_discriminant(float a, float b, float c);
int find_linear_root(float b, float c, float *result1);
int find_quadratic_roots(float a, float b, float c, float *result1, float *result2);
void sort_result(float *result1, float *result2);

int find_result(float a, float b, float c, float *result1, float *result2) {
    if (is_zero(a)) {
        return find_linear_root(b, c, result1);
    } else {
        return find_quadratic_roots(a, b, c, result1, result2);
    }
}

bool is_zero(float number) {
    return fabsf(number) < EPS;
}

bool is_negative(float number) {
    return number < -EPS;
}

float calculate_discriminant(float a, float b, float c) {
    return b * b - 4 * a * c;
}

int find_linear_root(float b, float c, float *result1) {
    if (!is_zero(b)) {
            *result1 = -c / b;
            return kOneRoot;
    } else {
        if (is_zero(c)) {return kInfRoots;}
        else {return kZeroRoots;}
    }
}

int find_quadratic_roots(float a, float b, float c, float *result1, float *result2) {
    float discriminant = calculate_discriminant(a, b, c);

    if (is_negative(discriminant)) {
            return kZeroRoots;
    } else {
        if (is_zero(discriminant)) { 
            *result1 = -b / (2 * a);
            return kOneRoot;
        } else {
            *result1 = (-b + sqrtf(discriminant)) / (2 * a);
            *result2 = (-b - sqrtf(discriminant)) / (2 * a);
            sort_result(result1, result2);
            return kTwoRoots;
        }
    }   
}

void sort_result(float *result1, float *result2) {
    if (*result1 > *result2){
        float t = *result1;
        *result1 = *result2;
        *result2 = t;
    } 
}