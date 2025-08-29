#include "FunctionsGoogleTests.h"
#include "RootsFinderSquareSolver.h"
#include "DataChecker.h"
#include "DataGoogleTests.h"
#include "StructsSquareSolver.h"

#include <stdio.h>
#include <math.h>

void register_test(const char* name, TestFunc func) {
    if (test_count < MAX_TESTS) {
        tests[test_count].name = name;
        tests[test_count].func = func;
        test_count++;
    }
}

void run_all_tests(void) {
    //int passed = 0;
    //printf("Running %d tests...\n\n", test_count);
    for (int i = 0; i < test_count; i++) {

        current_test_failed = 0;
        tests[i].func();

        if (current_test_failed == 0) {
            printf("[PASS] %s\n", tests[i].name);
            //passed++;
        }
        printf("\n");
    }
    //printf("\nSummary: %d/%d passed\n", passed, test_count);
}

void make_google_test_done(void){
    #define EXPECT_EQ(a, b) \
        if (!compare_answers(a, b)) { \
            printf("[FAIL] %s %s != %s, %lf != %lf\n", __func__, #a, #b, a, b); \
            current_test_failed = 1; \
        }

    REGISTER_TEST(TestSquare2Roots);
    run_all_tests();
}

TEST(TestSquare2Roots) {
    soolver[0].number_of_roots = find_result(&(soolver[0]));
    EXPECT_EQ((double)soolver[0].number_of_roots, (double)soolver_check[0].number_of_roots_compared);
    EXPECT_EQ(soolver[0].result1, soolver_check[0].result1_compared);
    EXPECT_EQ(soolver[0].result2, soolver_check[0].result2_compared);
}