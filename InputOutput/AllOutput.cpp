#include "AllOutput.h"

#include <stdio.h>
#include <assert.h>

#include "EnumsSquareSolver.h"
#include "InputOutputDefines.h"
#include "MyAssert.h"
#include "ColorsToOutput.h"
#include "AllTextSquareSolver.h"
#include "FileOperations.h"

PossibleErrors handle_output(TypeOfInputOutput output_choice_result, RootsCount number_of_roots, double result1, double result2, const char *filename_to_open_output) {
    assert(filename_to_open_output != NULL);

    PossibleErrors err = kNoError;
 
    if (output_choice_result == kFile) {
        FILE *file = NULL;

        err = open_file(filename_to_open_output, &file, write_mode);
        if (err != kNoError) {
            return err;
        }
 
        output(output_choice_result, number_of_roots, result1, result2, file);
 
        err = close_file(file);
        if (err != kNoError) {
            return err;
        }

    } else {
        output(output_choice_result, number_of_roots, result1, result2, stdout);
    }
 
    return kNoError;
}

void output(TypeOfInputOutput output_choice_result, RootsCount number_of_roots, double result1, double result2, FILE *file) {
    assert(file != NULL);

    printf("\n");
    fprintf(file, "This equation has ");

    switch (number_of_roots) {
    case kZeroRoots: 
        print_conditional_int_color(file, kZeroRoots);
        fprintf(file, " roots.\n");
        break;

    case kOneRoot: 
        MY_ASSERT(result1 > 0, "Результат должен быть неотрицательным, на самом деле: %lf\n", result1);

        print_conditional_int_color(file, kOneRoot);
        fprintf(file, " root: ");
        print_conditional_one_root_color(file, result1);
        break;

    case kTwoRoots:
        MY_ASSERT(result1 > 0, "Результат должен быть неотрицательным, на самом деле: %lf\n", result1);
        MY_ASSERT(result2 > 0, "Результат должен быть неотрицательным, на самом деле: %lf\n", result2);

        print_conditional_int_color(file, kTwoRoots);
        fprintf(file, " roots :");
        print_conditional_two_roots_color(file, result1, result2);
        break;

    case kInfRoots: 
        if (file == stdout) {    
            fprintf(file, GREEN "This equation has infinitely many roots.\n" RESET);
        } else {
            fprintf(file, "This equation has infinitely many roots.\n");
        }
        break;
    }

    if (output_choice_result == kFile) {
        fprintf(stdout, GREEN  "Roots are already in a file.\n" RESET);
    }
}

PossibleErrors error_printer(PossibleErrors error_type) {
    switch (error_type) {
    case kNoError:
    case kTest:
        return kNoError;

    case kErrorOpening:
        fprintf(stderr, RED "Error while opening file.\n" RESET);
        return kErrorOpening;

    case kErrorClosing:
        fprintf(stderr, RED "Error while closing file.\n" RESET);
        return kErrorClosing;

    case kBadInputCommands:
        fprintf(stderr, RED "Input error.\n" RESET);
        return kBadInputCommands;

    case kBadInputGraphics:
        problem_with_input_three_text_file();
        return kBadInputGraphics;
    
    default:
        assert(0 && RED "Invalid error.\n" RESET);
    }

    return kNoError;
}
