#ifndef ROOTS_FINDER_H_
#define ROOTS_FINDER_H_

#include <stdio.h>
#include <limits.h>

#include "EnumsSquareSolver.h"
#include "StructsSquareSolver.h"

//----------------------------------------------------------------------------------------------------------------------------------------------
//! The function which redirects tou to another function due to the fact whether (a == 0) or not. find_result(...) also returns number of roots.
//!
//! @param [in] a a-coefficient
//! @param [in] b b-coefficient
//! @param [in] c c-coefficient
//! @param [out] result1 Pointer to the 1st root
//! @param [out] result2 Pointer to rhe 2nd root
//!
//! @return Number of roots
//----------------------------------------------------------------------------------------------------------------------------------------------
RootsCount find_result(SolutionArguments *Solver);

//---------------------------------------------
//! The function which calculates discriminant.
//!
//! @param [in] a a-coefficient
//! @param [in] b b-coefficient
//! @param [in] c c-coefficient
//!
//! @return discriminant
//---------------------------------------------
double calculate_discriminant(double a, double b, double c);

//-----------------------------------------------------------------------------------------------------------------------
//! The function which finds roots when equation is linear, it changes result1 (in main) and returns number of solutions.
//!
//! @param [in] b b-coefficient
//! @param [in] c c-coefficient
//! @param [out] result1 Pointer to the 1st root
//!
//! @return Number of roots
//!
//! @note In case of infinite number of roots, returns kInfRoots = INT_MAX.
//-----------------------------------------------------------------------------------------------------------------------
RootsCount find_linear_root(SolutionArguments *Solver);

//--------------------------------------------------------------------------------------------------------------------------
//! The function which finds roots when equation is quadratic, it changes result1 (in main) and returns number of solutions.
//!
//! @param [in] a a-coefficient
//! @param [in] b b-coefficient
//! @param [in] c c-coefficient
//! @param [out] result1 Pointer to the 1st root
//! @param [out] result2 Pointer to rhe 2nd root
//!
//! @return Number of roots in quadratic equation
//--------------------------------------------------------------------------------------------------------------------------
RootsCount find_quadratic_roots(SolutionArguments *Solver);

#endif // ROOTS_FINDER_H_
