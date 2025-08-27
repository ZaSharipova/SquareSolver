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


PossibleErrors parse_arguments(int argc, char *argv[], TypeOfInputOutput *input_choice_result, TypeOfInputOutput *output_choice_result, const char **filename_to_open_input, const char **filename_to_open_output) { 
    assert(input_choice_result != NULL);
    assert(output_choice_result != NULL);
    assert(filename_to_open_input != NULL);
    assert(filename_to_open_output != NULL);

    if (argc > 1) {
        return parse_checker(argc, argv,  input_choice_result, output_choice_result, filename_to_open_input,  filename_to_open_output);
    } else {
        start_intro();
        first_question_in_graphics(input_choice_result);
        second_question_in_graphics(output_choice_result);
    }
    return kNoError;

}

PossibleErrors parse_checker(int argc, char *argv[], TypeOfInputOutput *input_choice_result, TypeOfInputOutput *output_choice_result, const char **filename_to_open_input, const char **filename_to_open_output) {
    assert(input_choice_result != NULL);
    assert(output_choice_result != NULL);
    assert(filename_to_open_input != NULL);
    assert(filename_to_open_output != NULL);

    if (argc > 1) {

        #ifndef NDEBUG
        if (strcmp(argv[1], test_command) == 0) {
            unit_test_checker();
            return kTest;
        }
        #endif

        int pos = 1;
        bool flag_input = false;
        bool flag_output = false;

        while (pos < argc) {
            if (parse_in(argc, argv, input_choice_result, pos, filename_to_open_input)) {
                flag_input = true;
    
            } else if (parse_out(argc, argv, output_choice_result, pos, filename_to_open_output)) {
                flag_output = true;

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

bool parse_in(int argc, char *argv[], TypeOfInputOutput *input_choice_result, int pos, const char **filename_to_open_input) {
    assert(argv != NULL);
    assert(filename_to_open_input != NULL);

    if (in_out_command_checker(argc, pos, argv[pos], in_command)) {
        pos++;
        if (strcmp(argv[pos], console_argument) == 0) {
            *input_choice_result = kConsole;

        } else if (strcmp(argv[pos], file_argument) == 0) {
            *input_choice_result = kFile;

        } else {
            *input_choice_result = kFile;
            *filename_to_open_input = argv[pos];
        }
        return true;
    }
    return false;
}

bool parse_out(int argc, char * argv[], TypeOfInputOutput *output_choice_result, int pos, const char **filename_to_open_output) {
    assert(argv != NULL);
    assert(filename_to_open_output != NULL);

    if (in_out_command_checker(argc, pos, argv[pos], out_command)) {
        pos++;
        if (strcmp(argv[pos], console_argument) == 0) {
            *output_choice_result = kConsole;

        } else if (strcmp(argv[pos], file_argument) == 0) {
            *output_choice_result = kFile;
            
        } else {
            *output_choice_result = kFile;
            *filename_to_open_output = argv[pos];
        }
        return true;
    }
    return false;
}