#ifndef PARSE_INPUT_H_
#define PARSE_INPUT_H_

#include "EnumsSquareSolver.h"
#include "StructsSquareSolver.h"

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
PossibleErrors parse_arguments(int argc, char *argv[], Inout *flags, Files *filenames, SolutionArguments *solver);

//---------------------------------------------------------------------------------------------------------------------
//! Handles parsing of the command stroke being entered if it's size is more then 1.
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
PossibleErrors parse_checker(int argc, char *argv[], Inout *flags, Files *filenames, SolutionArguments *solver);

//-------------------------------------------------------------------------------------------------------------------
//! Parses the command starting with "--in".
//!
//! @param [in] argc Size of stroke beeing entered from console
//! @param [in] argv[] massive of stroke entered separated by " "
//! @param [out] input_choice_result Pointer to the parameter which can be "kFile" or "kConsole" to input the result
//! @param [in] pos Position in argv[]
//! @param [out] filename_to_open_input Pointer to the pointer of the filename to input the result
//! 
//! @return true/false
//-------------------------------------------------------------------------------------------------------------------
bool parse_in(int argc, char * argv[], TypeOfInputOutput *input_choice_result, int pos, const char **filename_to_open_input);


//---------------------------------------------------------------------------------------------------------------------
//! Parses the command starting with "--out".
//!
//! @param [in] argc Size of stroke beeing entered from console
//! @param [in] argv[] massive of stroke entered separated by " "
//! @param [out] output_choice_result Pointer to the parameter which can be "kFile" or "kConsole" to output the result
//! @param [in] pos Position in argv[]
//! @param [out] filename_to_open_output Pointer to the pointer of the filename to output the result
//! 
//! @return true/false
//--------------------------------------------------------------------------------------------------------------------
bool parse_out(int argc, char * argv[], TypeOfInputOutput *output_choice_result, int pos, const char **filename_to_open_output);

//------------------------------------------------------------------------------------------------------
//Checks whether parsed element if "--verbose" or not.
//!
//! @param [in] stroke Pointer to the stroke written
//! @param [out] result_type Pointer to the result_type (which consists of informaton of user's choice)
//!
//! @return true/false
//------------------------------------------------------------------------------------------------------
bool parse_solution(char *stroke, TypeOfResult *result_type);

#endif // PARSE_INPUT_H_