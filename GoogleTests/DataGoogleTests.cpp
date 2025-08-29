
#include "StructsSquareSolver.h"
#include "DataGoogleTests.h"

#include <stdio.h>
#include <cmath>
#include <limits.h>
#include <assert.h>

#define REGISTER_TEST(stroke) register_test(#stroke, stroke);
#define TEST(name) void name(void)
#define MAX_TESTS 100

int test_count;
int current_test_failed;  

typedef void (*TestFunc)(void);

struct TestCase tests[MAX_TESTS];

SolutionArgumentsCompared soolver_check[] = {
    {1, 6, 5, -5, -1, kTwoRoots},
    {1, 2, 1, -1, NAN, kOneRoot},
    {1, 5, 7, NAN, NAN, kZeroRoots},
    {0, 0, 0, NAN, NAN, kInfRoots},
    {0, -1, 2, 2, NAN, kOneRoot},
    {0, 0, -1, NAN, NAN, kZeroRoots},
};

SolutionArguments soolver[] = {
    {1, 6, 5, NAN, NAN, NAN, kZeroRoots},
    {1, 2, 1, NAN, NAN, NAN, kZeroRoots},
    {1, 5, 7, NAN, NAN, NAN, kZeroRoots},
    {0, 0, 0, NAN, NAN, NAN, kZeroRoots},
    {0, -1, 2, NAN, NAN, NAN, kZeroRoots},
    {0, 0, -1, NAN, NAN, NAN, kZeroRoots},
};
