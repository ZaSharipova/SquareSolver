//------------------------------------------------------------------
//! Tests whether the number is zero (due to the measurement error).
//! @param [in] number number beeing checked
//!
//! @return true/false
//------------------------------------------------------------------
bool is_zero(long double number);

//-------------------------------------------
//! Tests whether the number is negative.
//!
//! @param [in] number number beeing checked
//!
//! @return true/false
//-------------------------------------------
bool is_negative(long double number);

//----------------------------------------------
//! Sorts result1 and result2.
//!
//! @param [out] result1 Pointer to the 1st root
//! @param [out] result2 Pointer to the 2nd root
//!
//----------------------------------------------
void sort_result(long double *result1, long double *result2);

//-------------------------------------------------------------------------
//! Checks if the root looks like "-0.000..." and changes it to "0.000...".
//!
//! @param [out] result1 Pointer to the result (root)
//-------------------------------------------------------------------------
void root_zero_checker(long double *result);

//--------------------------------------------------------------------
//! Checks whether the number entered from the file is correct (1, 2).
//!
//! @param [in] status What was the result of scanf
//! @param [in] choice_result 1 or 2 (file or console)
//!
//! @return true/false
//--------------------------------------------------------------------
bool status_scan_false(int status, int choice_result);

//----------------------
//! Clears input buffer.
//----------------------
void clear_input_buffer(void);

//------------------------------------------------------------------------------------------------------
//! Checks whether command written from commad line is "--in", "--out" and has continuation.
//!
//! @param [in] argc Size of stroke beeing entered from console
//! @param [in] i Position in argv[]
//! @param [in] stroke Pointer to the stroke which is beeing checked with "strcmp" with "--in", "--out"
//! @param [in] command Pointer to the "--in" or "--out" due to the function call
//!
//! @return true/false
//------------------------------------------------------------------------------------------------------
bool in_out_command_checker(int argc, int i, char * stroke, const char *command);

size_t nums_counter(char * buff, size_t size);