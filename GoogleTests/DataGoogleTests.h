#ifndef DATA_GOOGLE_TESTS_H_
#define DATA_GOOGLE_TESTS_H_

#define REGISTER_TEST(stroke) register_test(#stroke, stroke);
#define TEST(name) void name(void)
#define MAX_TESTS 100

typedef void (*TestFunc)(void);

struct TestCase {
    const char* name;
    TestFunc func;
};

extern int test_count;
extern int current_test_failed;
extern SolutionArgumentsCompared soolver_check[];
extern SolutionArguments soolver[];
extern struct TestCase tests[MAX_TESTS];

#endif // DATA_GOOGLE_TESTS_H_