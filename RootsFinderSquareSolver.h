#include <stdio.h>
#include <limits.h>
#include "EnumsSquareSolver.h"

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
int find_result(float a, float b, float c, float *result1, float *result2);

//---------------------------------------------
//! The function which calculates discriminant.
//!
//! @param [in] a a-coefficient
//! @param [in] b b-coefficient
//! @param [in] c c-coefficient
//!
//! @return discriminant
//---------------------------------------------
float calculate_discriminant(float a, float b, float c);

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
int find_linear_root(float b, float c, float *result1);

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
int find_quadratic_roots(float a, float b, float c, float *result1, float *result2);
