#include "ParseInput.h"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "EnumsSquareSolver.h"
#include "AllTextSquareSolver.h"
#include "InputOutputDefines.h"
#include "SubsidiaryFunctionsSquareSolver.h"
#include "DataChecker.h"
#include "AllInput.h"
#include "StructsSquareSolver.h"


PossibleErrors parse_arguments(int argc, char *argv[], Inout *flags, Files *filenames, SolutionArguments *solver) { 
    assert(flags     != NULL);
    assert(filenames != NULL);

    if (argc > 1) {
        return parse_checker(argc, argv, flags, filenames, solver);
    } else {
        start_intro();
        first_question_in_graphics(&(flags->input_choice_result));
        second_question_in_graphics(&(flags->output_choice_result));
        third_question_in_graphics(&(flags->result_type));
    }
    return kNoError;

}

PossibleErrors parse_checker(int argc, char *argv[], Inout *flags, Files *filenames, SolutionArguments *solver) {
    assert(flags     != NULL);
    assert(filenames != NULL);

    if (argc > 1) {

        #ifndef NDEBUG
        if (strcmp(argv[1], TEST_COMMAND) == 0) {
            unit_test_checker(solver);
            return kTest;
        }
        #endif

        int pos = 1;
        bool flag_input = false;
        bool flag_output = false;

        while (pos < argc) {
            if (parse_in(argc, argv, &(flags->input_choice_result), pos, &(filenames->input_file))) {
                flag_input = true;
    
            } else if (parse_out(argc, argv, &(flags->output_choice_result), pos, &(filenames->output_file))) {
                flag_output = true;

            } else if (parse_solution(argv[pos], &(flags->result_type))) {
                pos--;

            } else {
                return kBadInputCommands;
            }
            pos += 2;
        }
        if (!flag_input || !flag_output) {
            return kBadInputCommands;
        }
    }
    return kNoError;
}

bool parse_in(int argc, char *argv[], TypeOfInputOutput *input_choice_result, int pos, const char **input_file) {
    assert(argv       != NULL);
    assert(input_file != NULL);

    if (in_out_command_checker(argc, pos, argv[pos], IN_COMMAND)) {
        pos++;
        if (strcmp(argv[pos], CONSOLE_ARGUMENT) == 0) {
            *input_choice_result = kConsole;

        } else if (strcmp(argv[pos], FILE_ARGUMENT) == 0) {
            *input_choice_result = kFile;

        } else {
            *input_choice_result = kFile;
            *input_file = argv[pos];
        }
        return true;
    }
    return false;
}

bool parse_out(int argc, char * argv[], TypeOfInputOutput *output_choice_result, int pos, const char **output_file) {
    assert(argv        != NULL);
    assert(output_file != NULL);

    if (in_out_command_checker(argc, pos, argv[pos], OUT_COMMAND)) {
        pos++;
        if (strcmp(argv[pos], CONSOLE_ARGUMENT) == 0) {
            *output_choice_result = kConsole;

        } else if (strcmp(argv[pos], FILE_ARGUMENT) == 0) {
            *output_choice_result = kFile;
            
        } else {
            *output_choice_result = kFile;
            *output_file = argv[pos];
        }
        return true;
    }
    return false;
}

bool parse_solution(char *stroke, TypeOfResult *result_type){
    assert(stroke != NULL);

    if (strcmp(stroke, SOLUTION_COMMAND) == 0){
        *result_type = kLongSolution;
        return true;
    }
    return false;
}