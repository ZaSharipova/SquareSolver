#include "AllInput.h"

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <assert.h>

#include "AllTextSquareSolver.h"
#include "SubsidiaryFunctionsSquareSolver.h"
#include "InputOutputDefines.h"
#include "ColorsToOutput.h"
#include "FileOperations.h"
#include "StructsSquareSolver.h"

PossibleErrors handle_input(Inout *flags, SolutionArguments *solver, const char *filename) {
    assert(solver   != NULL);
    assert(flags    != NULL);
    assert(filename != NULL);

    PossibleErrors err = kNoError;
 
    if (flags->input_choice_result == kFile) {
        err = all_file_input(flags->input_choice_result, solver, filename);
        if (err != kNoError) {
            return err;
        }

        // if (error_printer(err) == kBadInputGraphics) {
        //     err = close_file(file);
        //     if (err == kErrorClosing){
        //         problem_with_input_three_text_file();
        //         return kErrorClosing;
        //     }
        //     return kBadInputGraphics;
        // }

    } else {
        all_console_input(flags->input_choice_result, solver, filename);
    }
 
    return kNoError;
}

PossibleErrors all_file_input(TypeOfInputOutput input_choice_result, SolutionArguments *solver, const char *filename) {
    assert(solver   != NULL);
    assert(filename != NULL);

    FILE *file = NULL;
    int err = kNoError;

    err = open_file(filename, &file, READ_MODE);
    if (err != kNoError) {
        return kErrorOpening;
    }
 
    err = input(input_choice_result, file, solver);
    if (err != kNoError) {
        return kBadInputGraphics;
    }

    err = close_file(file);
    if (err != kNoError) {
        return kErrorClosing;
    }
    return kNoError;
}

void all_console_input(TypeOfInputOutput input_choice_result, SolutionArguments *solver, const char *filename) {
    assert(solver   != NULL);
    assert(filename != NULL);

    example_of_input_coefficients();
    input(input_choice_result, stdin, solver);
}

PossibleErrors input(TypeOfInputOutput input_choice_result, FILE *input_file, SolutionArguments *solver) {
    assert(solver     != NULL);
    assert(input_file != NULL);

    int status = fscanf(input_file, "%lf %lf %lf", &(solver->a), &(solver->b), &(solver->c));
    if (status == 3) {
        return kNoError;
    }

    if (input_choice_result == kFile) {
        return kBadInputGraphics;
    }

    while (status != 3) {
        print_problem_with_input_three_text();
        clear_input_buffer();
        status = fscanf(input_file, "%lf %lf %lf", &(solver->a), &(solver->b), &(solver->c));
    }

    return kNoError;
}

void input_question_in_graphics(TypeOfInputOutput *input_choice_result) {
    assert(input_choice_result != NULL);

    input_choice_text();
    *input_choice_result = choice_question();
}

void output_question_in_graphics(TypeOfInputOutput *output_choice_result) {
    assert(output_choice_result != NULL);

    output_choice_text();
    *output_choice_result = choice_question();
}

void solution_question_in_graphics(TypeOfResult *result_type){
    assert(result_type != NULL);

    solution_choice_text();
    *result_type = (TypeOfResult) choice_question();
}

TypeOfInputOutput choice_question() {
    TypeOfInputOutput choice_result = kConsole;
    int status = 0;

    do {
        status = scanf("%d", &choice_result);
        if (status != 1 || (choice_result != kFile && choice_result != kConsole)) {
            problem_with_input_one_text();
            clear_input_buffer();
        }

    } while (status != 1 || (choice_result != kFile && choice_result != kConsole));
    clear_input_buffer();

    return choice_result;
}
