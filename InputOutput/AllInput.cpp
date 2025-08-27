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

PossibleErrors handle_input(TypeOfInputOutput input_choice_result, double *a, double *b, double *c, const char *filename) {
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);
    assert(filename != NULL);

    PossibleErrors err = kNoError;
 
    if (input_choice_result == kFile) {
        err = all_file_input(input_choice_result, a, b, c, filename);
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
        all_console_input(input_choice_result, a, b, c, filename);
    }
 
    return kNoError;
}

PossibleErrors all_file_input(TypeOfInputOutput input_choice_result, double *a, double *b, double *c, const char *filename) {
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);
    assert(filename != NULL);

    FILE *file = NULL;
    int err = kNoError;

    err = open_file(filename, &file, read_mode);
    if (err != kNoError) {
        return kErrorOpening;
    }
 
    err = input(input_choice_result, file, a, b, c);
    if (err != kNoError) {
        return kBadInputGraphics;
    }

    err = close_file(file);
    if (err != kNoError) {
        return kErrorClosing;
    }
    return kNoError;
}

void all_console_input(TypeOfInputOutput input_choice_result, double *a, double *b, double *c, const char *filename) {
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);
    assert(filename != NULL);

    example_of_input_coefficients();
    input(input_choice_result, stdin, a, b, c);
}

PossibleErrors input(TypeOfInputOutput input_choice_result, FILE *input_file, double *a, double *b, double *c) {
    assert(input_file != NULL);
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);

    int status = fscanf(input_file, "%lf %lf %lf", a, b, c);
    if (status == 3) {
        return kNoError;
    }

    if (input_choice_result == kFile) {
        return kBadInputGraphics;
    }

    while (status != 3) {
        print_problem_with_input_three_text();
        clear_input_buffer();
        status = fscanf(input_file, "%lf %lf %lf", a, b, c);
    }

    return kNoError;
}

void first_question_in_graphics(TypeOfInputOutput *input_choice_result) {
    assert(input_choice_result != NULL);

    input_choice_text();
    *input_choice_result = choice_question();
}

void second_question_in_graphics(TypeOfInputOutput *output_choice_result) {
    assert(output_choice_result != NULL);

    output_choice_text();
    *output_choice_result = choice_question();
}

TypeOfInputOutput choice_question(void) {
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
