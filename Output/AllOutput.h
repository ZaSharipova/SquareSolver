#ifndef ALL_OUTPUT_H_
#define ALL_OUTPUT_H_

#include "EnumsSquareSolver.h"
#include "StructsSquareSolver.h"

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
PossibleErrors handle_output(Inout *flags, SolutionArguments *solver, const char *filename);

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
void output(Inout *flags, SolutionArguments *solver, FILE *file);

//-------------------------------------------------------------------------------
//! Prints errors from "PossibleErrors" to the stderr and returns type of error.
//!
//! @param [in] error_type Error from "PossibleErrors"
//!
//! @return type of error from "PossibleErrors" ("kNoError" if there is no error)
//-------------------------------------------------------------------------------
PossibleErrors error_printer(PossibleErrors error_type);

#endif // ALL_OUTPUT_H_