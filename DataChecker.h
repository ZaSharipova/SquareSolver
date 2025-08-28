#ifndef DATA_CHECKER_H_
#define DATA_CHECKER_H_

#include <stdio.h>

#include "EnumsSquareSolver.h"
#include "StructsSquareSolver.h"

//-------------------------------------------------------------------------------
//! Function which checks all the process of --test.
//!
//! @return type of error from "PossibleErrors" ("kNoError" if there is no error)
//-------------------------------------------------------------------------------
PossibleErrors unit_test_checker(SolutionArguments *solver);

//--------------------------------------
//! Finds the size of file in bytes.
//! @param [in] file Pointer to the file
//!
//! @return Size of file in bytes
//--------------------------------------
size_t file_size(FILE *file);

//-------------------------------------------------------------------------------
//! Handles all the process of testing results.
//! @param [in] filename Name of the file
//! @param [out] numbers_count Amount of numbers in file
//! @param [in] ptr Pointer to the pointer to the ptr
//! @param [in] ptd Pointer to the pointer to the ptd
//!
//! @return type of error from "PossibleErrors" ("kNoError" if there is no error)
//-------------------------------------------------------------------------------
PossibleErrors all_file_test(const char *filename, size_t *numbers_count, char **ptr, double **ptd);


//----------------------------------------------------------
//! Parses the buffer to numbers and puts them into the ptd.
//!
//! @param [out] ptd Pointer to the ptd
//! @param [out] ptr Pointer to the ptr
//----------------------------------------------------------
void parse(double * ptd, char * ptr);

//-------------------------------------------------
//! Handles all the process of comparing results.
//! 
//! @param [in] ptd1 Pointer to the 1st massiv ptd1
//! @param [in] ptd2 Pointer to the 2nd massiv ptd2
//! @param [in] count Amount of numbers in file
//--------------------------------------------------
void handle_compare_results(double *ptd1, double *ptd2, size_t count, SolutionArguments *solver);

//--------------------------------------------------------------------------------------
//! Handles all the process of getting file into buffer.
//! 
//! @param [in] filename Pointer to the filename
//! @param [in] numbers_count Pointer to the numbers_count (how many numbers in the file) 
//!
//! @return type of error from "PossibleErrors" ("kNoError" if there is no error)
//---------------------------------------------------------------------------------------
PossibleErrors buff_input(const char *filename, size_t *numbers_count, char **ptr);

//------------------------------------------------------------------
//! Function in which all the rusults are being checked.
//!
//! @param [in] a a-coefficient
//! @param [in] b b-coefficient
//! @param [in] c c-coefficient
//! @param [in] number_of_results_compared Number of roots from file
//! @param [in] result1_compared 1st root from file
//! @param [in] result2_compared 2nd root from file
//------------------------------------------------------------------
void test_check(SolutionArgumentsCompared *Compare, SolutionArguments *solver);

//------------------------------------------------------------
//! Checks whether two numbers are same (due to the accuracy).
//!
//! @param [in] result Result of the programm
//! @param [out] result_compared Result from the file
//!
//! @return true/false
//------------------------------------------------------------
bool compare_answers(double result, double result_compared);

#endif // DATA_CHECKER_H_