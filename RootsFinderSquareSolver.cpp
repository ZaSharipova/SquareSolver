#include "RootsFinderSquareSolver.h"

#include <stdio.h>
#include <cmath>
#include <limits.h>
#include <assert.h>

#include "SubsidiaryFunctionsSquareSolver.h"
#include "StructsSquareSolver.h"

RootsCount find_result(SolutionArguments *solver) {
    assert(solver != NULL);

    if (is_zero(solver->a)) {
        return find_linear_root(solver);
    } 
    return find_quadratic_roots(solver);
}

double calculate_discriminant(double a, double b, double c) {
    return b * b - 4 * a * c;
}

RootsCount find_linear_root(SolutionArguments *solver) {
    assert(solver != NULL);

    if (!is_zero(solver->b)) {
            solver->result1 = -(solver->c) / (solver->b);
            return kOneRoot;
    } else {
        if (is_zero(solver->c)) {
            return kInfRoots;
        }
        return kZeroRoots;
    }
}

RootsCount find_quadratic_roots(SolutionArguments *solver) {
    assert(solver != NULL);

    solver->discriminant = calculate_discriminant(solver->a, solver->b, solver->c);

    if (!is_negative(solver->discriminant)) {
        if (is_zero(solver->discriminant)) { 
            solver->result1 = -(solver->b) / (2 * (solver->a));
            return kOneRoot;

        } else {
            solver->result1 = (-(solver->b) + sqrt(solver->discriminant)) / (2 * (solver->a));
            solver->result2 = (-(solver->b) - sqrt(solver->discriminant)) / (2 * (solver->a));

            sort_result(&(solver->result1), &(solver->result2));

            root_zero_checker(&(solver->result1));
            root_zero_checker(&(solver->result2));
            return kTwoRoots;
        }
    }

    return kZeroRoots; 
}