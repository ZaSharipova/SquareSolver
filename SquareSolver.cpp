#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

typedef enum {
    kZeroRoots = 0,
    kOneRoot   = 1,
    kTwoRoots  = 2,
    kInfRoots  = INT_MAX
} RootsCount;

const float EPS = 1e-6f;

void start_intro(void);
void input_with_file(float *a, float *b, float *c);
void output_with_file(int number_of_roots, float result1, float result2);
void input_with_console(float *a, float *b, float *c);
void clear_input_buffer(void);
void output_with_console(int number_of_roots, float result1, float result2);
void input_choice(float *a, float *b, float *c);
void output_choice(int number_of_roots, float result1, float result2);

int find_result(float a, float b, float c, float *result1, float *result2);
bool is_zero(float number);
float calculate_discriminant(float a, float b, float c);
RootsCount find_linear_root(float b, float c, float *result1);
RootsCount find_quadratic_roots(float a, float b, float c, float *result1, float *result2);
void sort_result(float *result1, float *result2);

int main(void) {
    float a = 0, b = 0, c = 0;
    float result1 = 0, result2 = 0;

    start_intro();
    input_choice(&a, &b, &c);

    int number_of_roots = find_result(a, b, c, &result1, &result2);
    output_choice(number_of_roots, result1, result2);

    return 0;
}

void start_intro(void) {
    printf("                                  y\n");                             
    printf("                                  ^\n");
    printf("                                  |\n");
    printf("                              .-' | '-.\n");
    printf("                            .'    |    '.\n");
    printf("                           /      |      \\\n");
    printf("                          /       |       \\\n");
    printf("                         /        |        \\\n");
    printf("                        /         |         \\\n");
    printf("                       /          |          \\\n");
    printf("                      /           |           \\\n");
    printf("                     /            |            \\\n");
    printf("----------------------------------+---------------------------------> x\n");
    printf("=======================================================================\n");
    printf("||                   ◣ Quadratic Equation Solver ◢                   ||\n");
    printf("=======================================================================\n");
    printf("                           ax^2 + bx + c = 0\n");
    printf("-----------------------------------------------------------------------\n");
}

void input_choice(float *a, float *b, float *c) {
    printf("Please answer whether you want to enter a, b, c by file or by console:\n");
    printf("1 - by file \"InputCoefficients.txt\",\n");
    printf("2 - by console:\n");

    int question_answer1 = 0;

    scanf("%d", &question_answer1);
    if (question_answer1 == 1) {
        input_with_file(a, b, c);
    } else if (question_answer1 == 2) {
        input_with_console(a, b, c);
    }
}

void input_with_file(float *a, float *b, float *c) {
    FILE *input = NULL;

    input = fopen("InputCoefficients.txt", "r");
    if (input == NULL) {
        fprintf(stdout, "Error while opening \"InputCoefficients.txt\".\n");
        exit(EXIT_FAILURE);
    }

    int status = fscanf(input, "%f %f %f", a, b, c);
    if (status != 3) {
        fprintf(stdout, "Input error! You must enter three real numbers separated by spaces.\n");
        exit(EXIT_FAILURE);
    }

    fclose(input);
}

void input_with_console(float *a, float *b, float *c) {
    int status = 0;
    printf("\n");
    printf("Please enter coefficients a, b, c separated by spaces:\n");
    printf("a (float), b (float), c (float)\n");
    printf("Example: 1 -3 2\n");
    do {
        status = scanf("%f %f %f", a, b, c);
        if (status != 3){
            printf("Input error! You must enter three real numbers separated by spaces.\n");
            printf("Try again:\n");
            clear_input_buffer();
        }
    } while (status != 3);
}

void clear_input_buffer(void) {
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF) {;}
}

int find_result(float a, float b, float c, float *result1, float *result2) {
    if (is_zero(a)){
        return find_linear_root(b, c, result1);
    } else {
        return find_quadratic_roots(a, b, c, result1, result2);
    }
}

bool is_zero(float number) {
    return fabsf(number) < EPS;
}
float calculate_discriminant(float a, float b, float c) {
    return b * b - 4 * a * c;
}
RootsCount find_linear_root(float b, float c, float *result1) {
    if (!is_zero(b)) {
            *result1 = -c / b;
            return kOneRoot;
    } else {
        if (is_zero(c)) {return kInfRoots;}
        else {return kZeroRoots;}
    }
}

RootsCount find_quadratic_roots(float a, float b, float c, float *result1, float *result2) {
    float discriminant = calculate_discriminant(a, b, c);

    if (discriminant < -EPS) {
            return kZeroRoots;
    } else {
        if (is_zero(discriminant)) { 
            *result1 = -b / (2 * a);
            return kOneRoot;
        } else {
            *result1 = (-b + sqrtf(discriminant)) / (2 * a);
            *result2 = (-b - sqrtf(discriminant)) / (2 * a);
            return kTwoRoots;
        }
    }   
}

void sort_result(float *result1, float *result2) {
    if (*result1 > *result2){
        float t = *result1;
        *result1 = *result2;
        *result2 = t;
    } 
}

void output_choice(int number_of_roots, float result1, float result2) {
    printf("\n");
    printf("Please answer whether you want to see roots in a file or in a console:\n");
    printf("1 - in the file \"OutputRoots.txt\",\n");
    printf("2 - in the console:\n");

    int question_answer2 = 0;

    scanf("%d", &question_answer2);
    if (question_answer2 == 1) {
        output_with_file(number_of_roots, result1, result2);
        printf("\n");
        printf("OK! Answer is already in the file.\n");
    } else if (question_answer2 == 2) {
        output_with_console(number_of_roots, result1, result2);
    }
}
void output_with_file(int number_of_roots, float result1, float result2) {
    FILE *output = NULL;

    output = fopen("OutputRoots.txt", "w");
    if (output == NULL) {
        fprintf(stdout, "Error while opening \"OutputRoots.txt\".\n");
        exit(EXIT_FAILURE);
    }
    switch (number_of_roots) {
    case kZeroRoots: 
        fprintf(output, "This equation has 0 roots.\n");
        break;
    case kOneRoot: 
        fprintf(output, "This equation has 1 root : %.3f.\n", result1);
        break;
    case kTwoRoots:
        sort_result(&result1, &result2);
        fprintf(output, "This equation has 2 roots : %.3f and %.3f.\n", result1, result2);
        break;
    case kInfRoots: 
        fprintf(output, "This equation has infinitely many roots.\n");
        break;
    }

    fclose(output);
}

void output_with_console(int number_of_roots, float result1, float result2) {
    printf("\n");
    switch (number_of_roots) {
    case kZeroRoots: 
        printf("This equation has 0 roots.\n");
        break;
    case kOneRoot: 
        printf("This equation has 1 root : %.3f.\n", result1);
        break;
    case kTwoRoots:
        sort_result(&result1, &result2);
        printf("This equation has 2 roots : %.3f and %.3f.\n", result1, result2);
        break;
    case kInfRoots: 
        printf("This equation has infinitely many roots.\n");
        break;
    }
}