#ifndef ALL_OUTPUT_H_
#define ALL_OUTPUT_H_

#include "EnumsSquareSolver.h"

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
PossibleErrors handle_input(TypeOfInputOutput input_choice_result, double *a, double *b, double *c, const char *filename);

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
PossibleErrors all_file_input(TypeOfInputOutput input_choice_result, double *a, double *b, double *c, const char *filename);

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
void all_console_input(TypeOfInputOutput input_choice_result, double *a, double *b, double *c, const char *filename);

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
PossibleErrors input(TypeOfInputOutput input_choice_result, FILE *input_file, double *a, double *b, double *c);

//-------------------------------------------------------------------------------------------------
//! Handles the process of asking whether to enter coefficients from file or console (in Graphics).
//-------------------------------------------------------------------------------------------------
TypeOfInputOutput choice_question(void);

//------------------------------------------------------------------------------------------------------
//! Askes a question to enter choice of input format and "redirects" to the "choice_question".
//!
//! @param [out] input_choice_result Pointer to the 1 or 2 (kFile or kConsole)
//------------------------------------------------------------------------------------------------------
void first_question_in_graphics(TypeOfInputOutput *input_choice_result);

//------------------------------------------------------------------------------------------------------
//! Askes a question to enter choice of output format and "redirects" to the "choice_question".
//!
//! @param [out] output_choice_result Pointer to the 1 or 2 (kFile or kConsole)
//------------------------------------------------------------------------------------------------------
void second_question_in_graphics(TypeOfInputOutput *output_choice_result);

#endif // ALL_OUTPUT_H_