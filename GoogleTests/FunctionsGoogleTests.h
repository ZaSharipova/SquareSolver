#ifndef FUNCTIONS_GOOGLE_TESTS_H_
#define FUNCTIONS_GOOGLE_TESTS_H_

#include "StructsSquareSolver.h"
#include "DataGoogleTests.h"

extern struct TestCase tests[MAX_TESTS];

//---------------------------------------------------------------------------------------------------------
//! Handles all the process of running all tests written to check the "find_result" function work properly.
//---------------------------------------------------------------------------------------------------------
void run_all_tests(void);

//-------------------------------------------------------
//! Function which helps put TEST information to the mas.
//!
//! @param [in] name Pointer to the name of test
//! @param [out] func function name
//-------------------------------------------------------
void register_test(const char* name, TestFunc func);

//----------------------------------------------------
//! Function which consists of check data information.
//----------------------------------------------------
TEST(TestSquare2Roots);

//----------------------------------------------
//! Handles all the process of geting TEST done.
//----------------------------------------------
void make_google_test_done(void);

#endif // FUNCTIONS_GOOGLE_TESTS_H_