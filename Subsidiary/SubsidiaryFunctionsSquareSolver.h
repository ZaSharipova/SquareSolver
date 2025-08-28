#ifndef SUBSIDIARY_FUNCTIONS_H_
#define SUBSIDIARY_FUNCTIONS_H_

#include <stdio.h>

//------------------------------------------------------------------
//! Tests whether the number is zero (due to the measurement error).
//! @param [in] number number beeing checked
//!
//! @return true/false
//------------------------------------------------------------------
bool is_zero(double number);

//-------------------------------------------
//! Tests whether the number is negative.
//!
//! @param [in] number number beeing checked
//!
//! @return true/false
//-------------------------------------------
bool is_negative(double number);

//----------------------------------------------
//! Sorts result1 and result2.
//!
//! @param [out] result1 Pointer to the 1st root
//! @param [out] result2 Pointer to the 2nd root
//!
//----------------------------------------------
void sort_result(double *result1, double *result2);

//-------------------------------------------------------------------------
//! Checks if the root looks like "-0.000..." and changes it to "0.000...".
//!
//! @param [out] result1 Pointer to the result (root)
//-------------------------------------------------------------------------
void root_zero_checker(double *result);

//----------------------
//! Clears input buffer.
//----------------------
void clear_input_buffer(void);

//------------------------------------------------------------------------------------------------------
//! Checks whether command written from command line is "--in", "--out" and has continuation.
//!
//! @param [in] argc Size of stroke beeing entered from console
//! @param [in] i Position in argv[]
//! @param [in] stroke Pointer to the stroke which is beeing checked with "strcmp" with "--in", "--out"
//! @param [in] command Pointer to the "--in" or "--out" due to the function call
//!
//! @return true/false
//------------------------------------------------------------------------------------------------------
bool in_out_command_checker(int argc, int i, char * stroke, const char *command);

//---------------------------------------------
//! Counts amount of numbers in file.
//!
//! @param [in] buff Pointer to the buffer 
//! @param [in] size Size of the file in bytes
//!
//! @return amount of numbers in file
//---------------------------------------------
size_t nums_counter(char * buff, size_t size);


#endif // SUBSIDIARY_FUNCTIONS_H_