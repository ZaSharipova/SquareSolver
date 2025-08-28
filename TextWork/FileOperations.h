#ifndef FILE_OPERATIONS_H_
#define FILE_OPERATIONS_H_

#include <stdio.h>
#include "EnumsSquareSolver.h"

//------------------------------------------------------------------------------
//! Handles all the process of opening file.
//!
//! @param [in] filename Pointer to the filename
//! @param [in] file Pointer to the open(...) of the file
//! @param [in] mode Pointer to the read or write mode in the file
//!
//! @return type of error from "PossibleErrors" ("kNoError" if there is no error)
//-------------------------------------------------------------------------------
PossibleErrors open_file(const char *filename, FILE **file, const char *mode);

//------------------------------------------------------------------------------
//! Handles all the process of closing file.
//!
//! @param [in] file Pointer to the open(...) of the file
//!
//! @return type of error from "PossibleErrors" ("kNoError" if there is no error)
//-------------------------------------------------------------------------------
PossibleErrors close_file(FILE *file);

#endif // FILE_OPERATIONS_H_