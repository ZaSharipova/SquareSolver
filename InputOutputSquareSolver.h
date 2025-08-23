#include <stdio.h>
#include "EnumsSquareSolver.h"

//-------------------------------------------------------------------------------------------------------------------
//! Parses the command starting with "--in".
//!
//! @param [in] argc Size of stroke beeing entered from console
//! @param [in] argv[] massive of stroke entered separated by " "
//! @param [out] input_choice_result Pointer to the parameter which can be "kFile" or "kConsole" to input the result
//! @param [in] i Position in argv[]
//! @param [out] filename_to_open_input Pointer to the pointer of the filename to input the result
//! 
//! @return true/false
//-------------------------------------------------------------------------------------------------------------------
bool parse_in(int argc, char * argv[], int *input_choice_result, int i, const char **filename_to_open_input);


//---------------------------------------------------------------------------------------------------------------------
//! Parses the command starting with "--out".
//!
//! @param [in] argc Size of stroke beeing entered from console
//! @param [in] argv[] massive of stroke entered separated by " "
//! @param [out] output_choice_result Pointer to the parameter which can be "kFile" or "kConsole" to output the result
//! @param [in] i Position in argv[]
//! @param [out] filename_to_open_output Pointer to the pointer of the filename to output the result
//! 
//! @return true/false
//--------------------------------------------------------------------------------------------------------------------
bool parse_out(int argc, char * argv[], int *output_choice_result, int i, const char **filename_to_open_output);

//---------------------------------------------------------------------------------------------------------------------
//! Parses the command stroke being entered (with the usage of "parse_in" and "parse_out").
//!
//! @param [in] argc Size of stroke beeing entered from console
//! @param [in] argv[] massive of stroke entered separated by " "
//! @param [out] input_choice_result Pointer to the parameter which can be "kFile" or "kConsole" to input the result
//! @param [out] output_choice_result Pointer to the parameter which can be "kFile" or "kConsole" to output the result
//! @param [out] filename_to_open_input Pointer to the pointer to the pointer of the filename to input the result
//! @param [out] filename_to_open_output Pointer to the pointer the pointer to of the filename to output the result
//!
//! @return kNoError (means there is no error) or other errors from "PossibleErrors"
//---------------------------------------------------------------------------------------------------------------------
int parse_arguments(int argc, char *argv[], int *input_choice_result, int *output_choice_result, const char **filename_to_open_input, const char **filename_to_open_output);

//------------------------------------------------------------------------------------------------------
//! Askes a question to enter choice of input format and "redirects" to the "choice_question".
//!
//! @param [out] input_choice_result Pointer to the 1 or 2 (kFile or kConsole)
//------------------------------------------------------------------------------------------------------
void first_question_in_graphics(int *input_choice_result);

//------------------------------------------------------------------------------------------------------
//! Askes a question to enter choice of output format and "redirects" to the "choice_question".
//!
//! @param [out] output_choice_result Pointer to the 1 or 2 (kFile or kConsole)
//------------------------------------------------------------------------------------------------------
void second_question_in_graphics(int *output_choice_result);

//-----------------------------------------------------------------------------------------------------------------------
//! Handles all the process of input.
//!
//! @param [in] input_choice_result parameter which can be "kFile" or "kConsole" to input the result (1 or 2 in question)
//! @param [out] a Pointer to the a-coefficient
//! @param [out] b Pointer to the b-coefficient
//! @param [out] c Pointer to the c-coefficient
//! @param [in] filename Pointer to the filename
//!
//! @return type of error from "PossibleErrors" ("kNoError" if there is no error)
//-----------------------------------------------------------------------------------------------------------------------
int handle_input(int input_choice_result, float *a, float *b, float *c, const char *filename);

//--------------------------------------------------------------------------------------------
//! Handles all the process of output.
//!
//! @param [in] output_choice_result 1 or 2 (kFile or kConsole)
//! @param [in] number_of_roots Number of roots
//! @param [in] result1 First root (if it exists, else 0 (not beeing written to the output))
//! @param [in] result2 Second root (if it exists, else 0 (not beeing written to the output))
//! @param [in] filename Pointer to the filename
//!
//! @return type of error from "PossibleErrors" ("kNoError" if there is no error)
//--------------------------------------------------------------------------------------------
int handle_output(int output_choice_result, int number_of_roots, float result1, float result2, const char *filename);

//-------------------------------------------------------------------------------------------------
//! Handles the process of asking whether to enter coefficients from file or console (in Graphics).
//-------------------------------------------------------------------------------------------------
int choice_question(void);

//-------------------------------------------------------------------------------
//! Handles the process of "scanf" (or "fscanf") of 3 coefficients.
//!
//! @param [in] input_choice_result 1 or 2 (kFile or kConsole)
//! @param [in] input_file Pointer to the input coefficients file
//! @param [out] a Pointer to the a-coeeficient
//! @param [out] b Pointer to the b-coeeficient
//! @param [out] c Pointer to the c-coeeficient
//! 
//! @return type of error from "PossibleErrors" ("kNoError" if there is no error)
//-------------------------------------------------------------------------------
int input(int input_choice_result, FILE *input_file, float *a, float *b, float *c);

//-------------------------------------------------------------------------------
//! Prints errors from "PossibleErrors" to the stderr and returns type of error.
//!
//! @param [in] error_type Error from "PossibleErrors"
//!
//! @return type of error from "PossibleErrors" ("kNoError" if there is no error)
//-------------------------------------------------------------------------------
int error_printer(int error_type);

//-------------------------------------------------------------------------------------------
//! Handles the process of "printf" (or "fprintf") of roots (probably no roots).
//!
//! @param [in] output_choice_result 1 or 2 (kFile or kConsole)
//! @param [in] number_of_roots Number of roots
//! @param [in] result1 First root (if it exists, else 0 (not beeing written to the output))
//! @param [in] result2 Second root (if it exists, else 0 (not beeing written to the output))
//! @param [in] file Pointer to the output result (with roots) file
//! 
//! @return type of error from "PossibleErrors" ("kNoError" if there is no error)
//-------------------------------------------------------------------------------------------
void output(int output_choice_result, int number_of_roots, float result1, float result2, FILE *file);

//------------------------------------------------------------------------------
//! Handles all the process of opening file.
//!
//! @param [in] filename Pointer to the filename
//! @param [in] file Pointer to the open(...) of the file
//! @param [in] mode Pointer to the read or write mode in the file
//!
//! @return type of error from "PossibleErrors" ("kNoError" if there is no error)
//-------------------------------------------------------------------------------
int open_file(const char *filename, FILE **file, const char *mode);

//------------------------------------------------------------------------------
//! Handles all the process of closing file.
//!
//! @param [in] file Pointer to the open(...) of the file
//!
//! @return type of error from "PossibleErrors" ("kNoError" if there is no error)
//-------------------------------------------------------------------------------
int close_file(FILE *file);

//---------------------------------------------------------------------------------------------------------
//! Handles all the process of working with file to input coefficients (open(...), input(...). close(...)).
//!
//! @param [in] input_choice_result
//! @param [out] a Pointer to the a-coefficient
//! @param [out] b Pointer to the b-coefficient
//! @param [out] c Pointer to the c-coefficient
//! @param [in] filename Pointer to the filename
//! 
//! @return type of error from "PossibleErrors" ("kNoError" if there is no error)
//---------------------------------------------------------------------------------------------------------
int all_file_input(int input_choice_result, float *a, float *b, float *c, const char *filename);

//---------------------------------------------------------------------------------------------------------
//! Handles all the process of working with console input coefficients (input(...)).
//!
//! @param [in] input_choice_result
//! @param [out] a Pointer to the a-coefficient
//! @param [out] b Pointer to the b-coefficient
//! @param [out] c Pointer to the c-coefficient
//! @param [in] filename Pointer to the filename
//! 
//! @return type of error from "PossibleErrors" ("kNoError" if there is no error)
//---------------------------------------------------------------------------------------------------------
void all_console_input(int input_choice_result, float *a, float *b, float *c, const char *filename);