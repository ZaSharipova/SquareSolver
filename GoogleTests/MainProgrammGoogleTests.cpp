// #include <stdio.h>
// #include <math.h>

// #include "FunctionsGoogleTests.h"
// #include "RootsFinderSquareSolver.h"
// #include "DataGoogleTests.h"
// #include "DataChecker.h"

// #define MAX_TESTS 100
// #define TEST(name) void name(void)
// //#define REGISTER_TEST(stroke) register_test(#stroke, stroke);

// extern SolutionArgumentsCompared solver_check[];
// extern SolutionArguments solver[];

// extern struct TestCase tests[MAX_TESTS];
// extern int test_count;
// extern int current_test_failed;  

// #define EXPECT_EQ(a, b) \
//     if (!compare_answers(a, b)) { \
//         printf("[FAIL] %s %s != %s, %lf != %lf\n", __func__, #a, #b, a, b); \
//         current_test_failed = 1; \
//     }

// TEST(TestSquare2Roots) {
//     solver[0].number_of_roots = find_result(&(solver[0]));
//     EXPECT_EQ((double)solver[0].number_of_roots, (double)solver_check[0].number_of_roots_compared);
//     EXPECT_EQ(solver[0].result1, solver_check[0].result1_compared);
//     EXPECT_EQ(solver[0].result2, solver_check[0].result2_compared);
//}

// TEST(TestSquare1Root) {
//     solver[1].number_of_roots = find_result(&(solver[1]));
//     EXPECT_EQ((double)solver[1].number_of_roots, (double)solver_check[1].number_of_roots_compared);
//     EXPECT_EQ(solver[1].result1, solver_check[1].result1_compared);
//     EXPECT_EQ(solver[1].result2, solver_check[1].result2_compared);
// }

// TEST(TestSquare0Roots) {
//     solver[2].number_of_roots = find_result(&(solver[2]));
//     EXPECT_EQ((double)solver[2].number_of_roots, (double)solver_check[2].number_of_roots_compared);
//     EXPECT_EQ(solver[2].result1, solver_check[2].result1_compared);
//     EXPECT_EQ(solver[2].result2, solver_check[2].result2_compared);
// }

// TEST(TestLinearInfRoots) {
//     solver[3].number_of_roots = find_result(&(solver[3]));
//     EXPECT_EQ((double)solver[3].number_of_roots, (double)solver_check[3].number_of_roots_compared);
//     EXPECT_EQ(solver[3].result1, solver_check[3].result1_compared);
//     EXPECT_EQ(solver[3].result2, solver_check[3].result2_compared);
// }

// TEST(FailLinear1Root) {
//     solver[4].number_of_roots = find_result(&(solver[4]));
//     EXPECT_EQ((double)solver[4].number_of_roots, (double)solver_check[4].number_of_roots_compared);
//     EXPECT_EQ(solver[4].result1, solver_check[4].result1_compared);
//     EXPECT_EQ(solver[4].result2, solver_check[4].result2_compared);
// }

// TEST(FailLinear0Roots) {
//     solver[5].number_of_roots = find_result(&(solver[5]));
//     EXPECT_EQ((double)solver[5].number_of_roots, (double)solver_check[5].number_of_roots_compared);
//     EXPECT_EQ(solver[5].result1, solver_check[5].result1_compared)
//     EXPECT_EQ(solver[5].result2, solver_check[5].result2_compared);
// }

// void reg(void) {
//     REGISTER_TEST(TestSquare2Roots);
//     REGISTER_TEST(TestSquare1Root);
//     REGISTER_TEST(TestSquare0Roots);
//     REGISTER_TEST(FailLinear1Root);
//     REGISTER_TEST(TestLinearInfRoots);
//     REGISTER_TEST(FailLinear0Roots);
// }

// int main(void){
//     reg();
//     run_all_tests();
//     return 0;
// }