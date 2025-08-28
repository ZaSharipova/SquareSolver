#ifndef ALL_TEXT_H_
#define ALL_TEXT_H_

#include "EnumsSquareSolver.h"
#include "StructsSquareSolver.h"
#include "MyAssert.h"

#define res1(result1, result2, a) (a > 0) ? (result1) : (result2)
#define res2(summa, ans1) (summa - ans1)

//-------------------------------------------------
//! Prints graphics and tells what this program is.
//-------------------------------------------------
void start_intro(void);

//-------------------------------------------------------------------------
//! Prints question whether the user wants to choose console or file input.
//-------------------------------------------------------------------------
void input_choice_text(void);

//--------------------------------------------------------------------------
//! Prints question whether the user wants to choose console or file output.
//--------------------------------------------------------------------------
void output_choice_text(void);

void solution_choice_text(void);

//--------------------------------------------------------------------------
//! Prints example of how to enter coefficients to there was no input error.
//--------------------------------------------------------------------------
void example_of_input_coefficients(void);

//--------------------------------------------------------------------------------------------------------
//! Prints the mistake text when the number you entered is not correct (for example, it is char, not int).
//--------------------------------------------------------------------------------------------------------
void problem_with_input_one_text(void);

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//! Prints the mistake text when 3 numbers you entered from the console are not correct to the type or amount. Also, it proposes the idea of entering them one again.
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
void print_problem_with_input_three_text(void);

//---------------------------------------------------------------------------------------------------------
//! Prints the mistake text when 3 numbers you entered from the file are not correct to the type or amount.
//---------------------------------------------------------------------------------------------------------
void problem_with_input_three_text_file(void);

//---------------------------
//! Prints MY_ASSERT message.
//---------------------------
void assert_true(void);

//-------------------------------------------------------------------------------
//! Prints colored (or not colored if it is stdout) message with number of roots.
//!
//! @param [in] file Pointer to the file
//! @param [in] number_of_roots Number of roots 
//-------------------------------------------------------------------------------
void print_conditional_int_color(FILE *file, RootsCount number_of_roots);

//--------------------------------------------------------------------
//! Prints colored (or not colored if it is stdout) message with root. 
//!
//! @param [in] file Pointer to the file
//! @param [in] result1 Root of quadratic equation
//--------------------------------------------------------------------
void print_conditional_one_root_color(FILE *file, double result1);

//-----------------------------------------------------------------------
//! Prints colored (or not colored if it is stdout) message with 2 roots.
//!
//! @param [in] file Pointer to the file
//! @param [in] result1 Root1 of quadratic equation
//! @param [in] result2 Root2 of quadratic equation
//-----------------------------------------------------------------------
void print_conditional_two_roots_color(FILE *file, double result1, double result2);

int output_long_solution(SolutionArguments *solver, FILE *file);

void print_wrong_answers(SolutionArgumentsCompared *Compare, SolutionArguments *solver);

void cond_print(FILE* fn, const char* fmt, ...);

#endif // ALL_TEXT_H_