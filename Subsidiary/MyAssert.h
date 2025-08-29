#ifndef MY_ASSERT_H_
#define MY_ASSERT_H_

#include "ColorsToOutput.h"

#define vprintf(file, format, ...) fprintf (file, format, ##__VA_ARGS__)

#ifdef NDEBUG
#define MY_ASSERT(condition, format, ...) (void(0))
#else
#define MY_ASSERT(condition, format, ...) \
    if (!(condition)) { \
        fprintf(stderr, RED "Assertion failed: %s, file %s, line %d.\n" RESET, #condition,  __FILE__, __LINE__); \
        assert_true(); \
        vprintf(stderr, RED format RESET, ##__VA_ARGS__); \
        abort(); \
    }
#endif

#endif