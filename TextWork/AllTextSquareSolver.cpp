#include "AllTextSquareSolver.h"

#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "EnumsSquareSolver.h"
#include "ColorsToOutput.h"
#include "RootsFinderSquareSolver.h"
#include "SubsidiaryFunctionsSquareSolver.h"
#include "StructsSquareSolver.h"

void start_intro(void) {
    printf(BLUE "                                  y\n" RESET);                             
    printf(BLUE "                                  ^\n" RESET);
    printf(BLUE "                                  |\n" RESET);
    printf(BLUE "                              .-' | '-.\n" RESET);
    printf(BLUE "                            .'    |    '.\n" RESET);
    printf(BLUE "                           /      |      \\\n" RESET);
    printf(BLUE "                          /       |       \\\n" RESET);
    printf(BLUE "                         /        |        \\\n" RESET);
    printf(BLUE "                        /         |         \\\n" RESET);
    printf(BLUE "                       /          |          \\\n" RESET);
    printf(BLUE "                      /           |           \\\n" RESET);
    printf(BLUE "                     /            |            \\\n" RESET);
    printf(BLUE "----------------------------------+---------------------------------> x\n" RESET);
    printf("=======================================================================\n");
    printf("||                  " RED " ◣ Quadratic Equation Solver ◢" RESET "                   ||\n");
    printf("=======================================================================\n");
    printf("                            " GREEN "ax^2 + bx + c = 0\n" RESET);
    printf("-----------------------------------------------------------------------\n");
}

void input_choice_text(void) {
    printf("Please answer whether you want to enter " YELLOW "a" RESET ", " YELLOW "b" RESET ", " YELLOW "c" RESET " by file or by console:\n");
    printf(BLUE "1" RESET " - by file \"InputCoefficients.txt\",\n");
    printf(BLUE "2" RESET " - by console:\n");
}

void output_choice_text(void) {
    printf("\n");
    printf("Please answer whether you want to see roots in a file or in a console:\n");
    printf(BLUE "1" RESET " - in the file \"OutputRoots.txt\",\n");
    printf(BLUE "2" RESET " - in the console:\n");
}

void solution_choice_text(void){
    printf("\n");
    printf("Please answer whether you want to see full soultion or just a result:\n");
    printf(BLUE "1" RESET " - full solution,\n");
    printf(BLUE "2" RESET " - only result:\n");
}

void example_of_input_coefficients(void) {
    printf("\n");
    printf("Please enter coefficients " YELLOW "a" RESET ", " YELLOW "b" RESET ", " YELLOW "c" RESET " separated by spaces:\n");
    printf(YELLOW "a" RESET " (float), " YELLOW "b" RESET " (float), " YELLOW "c" RESET " (float)\n");
    printf("Example:" CYAN " 1 -3 2\n" RESET);
}

void problem_with_input_one_text(void) {
    printf("Input error! You should write just "  BLUE "1" RESET " or " BLUE "2" RESET ".\n");
    printf("Try again:\n");
}

void print_problem_with_input_three_text(void) {
    printf(RED "Input error! You should enter three real numbers separated by spaces.\n" RESET);
    printf("Try again:\n");
}

void problem_with_input_three_text_file(void) {
    fprintf(stderr, RED "Input error! You should have entered three real numbers separated by spaces.\n" RESET);
    fprintf(stderr, RED "Rewrite numbers in the file or enter them in the console in the next Run.\n" RESET);
}

void assert_true(void) {
    fprintf(stderr, RED "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n" RESET);
    fprintf(stderr, RED "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n\n" RESET);
    fprintf(stderr, RED "                    Assert failed!!! \n\n" RESET);
    fprintf(stderr, RED "             You are loser aahhahahahahahhah \n\n" RESET);
}


void print_conditional_int_color(FILE *file, RootsCount number_of_roots) {
    assert(file != NULL);

    fprintf(file, "This equation has ");

    if (file == stdout) {
        fprintf(file, GREEN "%d" RESET, number_of_roots);
    } else {
        fprintf(file, "%d", number_of_roots);
    }
}

void print_conditional_one_root_color(FILE *file, double result1) {
    assert(file != NULL);

    fprintf(file, "This equation has ");

    if (file == stdout) {
        fprintf(file, CYAN "%.5lf\n" RESET, result1);
    } else {
        fprintf(file, "%.5lf\n", result1);
    }
}

void print_conditional_two_roots_color(FILE *file, double result1, double result2) {
    assert(file != NULL);

    fprintf(file, "This equation has ");

    if (file == stdout) {

        fprintf(file, CYAN " %.5lf" RESET " and " CYAN "%.5lf\n" RESET, result1, result2);
    } else {
        fprintf(file, " %.5lf and %.5lf\n",result1, result2);
    }
}

// void cond_print(FILE* fn, const char* fmt, ...) {
//     if (fn != stdout) {
//         #undef RED
//         #undef WH
//         #define .. ""

//         printf(fmt, ...);

//         #define ""
//     }
// }

int output_long_solution(SolutionArguments *solver, FILE *file) {
    assert(solver != NULL);
    assert(file != NULL);

    fprintf(file, "------------------------------------------------------------------------------------------------------------------------\n");
    fprintf(file, "                                              Solution:\n");

    if (is_zero(solver->a)) {
        fprintf(file, "\nThis equation is not square, but linear.\n");
        fprintf(file, "But we will solve it.\n\n");

        if (is_zero(solver->b)) {
            if (is_zero(solver->c)) {
                fprintf(file, "Let's try to substitute any value into function.\n");
                fprintf(file, "And in each case this value is a solution.\n");

            } else{
                fprintf(file, "Equation of a type \"const = 0\", if const != 0, doesn't have solutions.\n");
            }
            return 0;
        }
        fprintf(file, "So the only solution is : result1 = -c / b = %.5lf / %.5lf = %.5lf.\n", -(solver->a), solver->b, solver->result1);
        return 0;
    }

    fprintf(file, "\nFirst of all, let's find discriminant: discriminant = b ^ 2 - 4 * a * c.\n");
    fprintf(file, "So discriminant = %.5lf.\n", solver->discriminant);

    if (is_negative(solver->discriminant)) {
        fprintf(file, "Discriminant is negative, so this equation doesn't have roots as all function values are more, than zero.\n");
        return 0;
    }

    fprintf(file, "\nFormulas for solutions are: result1 = (-b - sqrt(discriminant)) / (2 * a) and result2 = (-b + sqrt(discriminant)) / (2 * a).\n");
    
    if (is_zero(solver->discriminant)) {
        fprintf(file, "Discriminant is zero. This is why there is only one solution.\n");
        fprintf(file, "And it is result1 = -b / (2 * a) = %.5lf / (2 * %.5lf) = %.5lf.\n", -(solver->b), (solver->a), (solver->result1));
        return 0;
    } 

    double ans1 = res1(solver->result1, solver->result2, solver->a);
    double ans2 = res2(solver->result1 + solver->result2, ans1);
    fprintf(file, "\nDiscriminant is positive. This is why there are two different solutions.\n");
    fprintf(file, "These are result1 = -b - sqrt(discriminant) / (2 * a) = (%.5lf - %.5lf) / (2 * %.5lf) = %.5lf,\n", -(solver->b), sqrt(solver->discriminant), solver->a, ans1);
    fprintf(file, "And result2 = -b + sqrt(discriminant) / (2 * a) = (%.5lf + %lf) / (2 * %.5lf) = %.5lf.\n", -(solver->b), sqrt(solver->discriminant), solver->a, ans2);
    return 0;
}

void print_wrong_answers(SolutionArgumentsCompared *Compare, SolutionArguments *solver){
    assert(Compare != NULL);
    assert(solver != NULL);

    printf("Wrong answer to coefficients a = %.5lf"
           ", b = %.5lf, c = %.5lf. Your answers: "
           "number_of_roots = %d, x1 = %.5lf, x2 = %.5lf. "
           "Right answers: number_of_roots = %d, x1 = %.5lf, x2 = %.5lf\n", 
            Compare->a, Compare->b, Compare->c, 
            solver->number_of_roots, 
            solver->result1, solver->result2, 
            Compare->number_of_roots_compared, 
            Compare->result1_compared, Compare->result2_compared);
}