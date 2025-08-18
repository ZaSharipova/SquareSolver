#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

enum {
    ZERO_ROOTS = 0,
    ONE_ROOT   = 1,
    TWO_ROOTS  = 2,
    INF_ROOTS  = INT_MAX
};
const float EPS = 1e-6f;

void start_intro(void);
void input_coefficients(float *a, float *b, float *c);
void clear_input_buffer(void);
void answer_out(int number_of_roots, float result1, float result2);

int find_result(float a, float b, float c, float *result1, float *result2);
bool is_zero(float number);
float calculate_discriminant(float a, float b, float c);
int find_linear_root(float b, float c, float *result1);
int find_quadratic_roots(float a, float b, float c, float *result1, float *result2);
void sort_result(float *result1, float *result2);

int main(void) {
    float a = 0, b = 0, c = 0;
    float result1 = 0, result2 = 0;

    start_intro();
    input_coefficients(&a, &b, &c);

    int number_of_roots = find_result(a, b, c, &result1, &result2);
    answer_out(number_of_roots, result1, result2);

    return 0;
}

void start_intro(void){
    printf("                         y\n");                             
    printf("                         ^\n");
    printf("                         |\n");
    printf("                      .-'|'-.\n");
    printf("                    .'   |   '.\n");
    printf("                   /     |     \\\n");
    printf("                  /      |      \\\n");
    printf("                 /       |       \\\n");
    printf("                /        |        \\\n");
    printf("               /         |         \\\n");
    printf("              /          |          \\\n");
    printf("             /           |           \\ \n");
    printf("-------------------------+-------------------------> x\n");
    printf("======================================================\n");
    printf("||          ◣ Quadratic Equation Solver ◢           ||\n");
    printf("======================================================\n");
    printf("                  ax^2 + bx + c = 0                   \n");
    printf("------------------------------------------------------\n");
    printf("Please enter coefficients a, b, c separated by spaces:\n");
    printf("a (float), b (float), c (float)\n");
    printf("Example: 1 -3 2\n");
    printf("------------------------------------------------------\n");
}

void input_coefficients(float *a, float *b, float *c) {
    int status = 0;
    do {
        status = scanf("%f %f %f", a, b, c);
        if (status != 3) {
            printf("Input error! You must enter three real numbers separated by spaces.\n");
            printf("Try again:\n");
            clear_input_buffer();
        }
    } while (status != 3);
}

void clear_input_buffer(void){
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF){ }
}

int find_result(float a, float b, float c, float *result1, float *result2) {
    if (is_zero(a)) {
        return find_linear_root(b, c, result1);
    } else {
        return find_quadratic_roots(a, b, c, result1, result2);
    }
}

bool is_zero(float number){
    return fabsf(number) < EPS;
}
float calculate_discriminant(float a, float b, float c) {
    return b * b - 4 * a * c;
}

int find_linear_root(float b, float c, float *result1){
    if (!is_zero(b)){
            *result1 = -c / b;
            return ONE_ROOT;
    } else{
        if (is_zero(c)) { return INF_ROOTS;}
        else { return ZERO_ROOTS;}
    }
}

int find_quadratic_roots(float a, float b, float c, float *result1, float *result2){
    float discriminant = calculate_discriminant(a, b, c);

    if (discriminant < -EPS) {
            return ZERO_ROOTS;
    } else{
        if (is_zero(discriminant)) { 
            *result1 = -b / (2 * a);
            return ONE_ROOT;
        } else {
            *result1 = (-b + sqrtf(discriminant)) / (2 * a);
            *result2 = (-b - sqrtf(discriminant)) / (2 * a);
            return TWO_ROOTS;
        }
    }   
}

void sort_result(float *result1, float *result2){
    if (*result1 > *result2){
        float t = *result1;
        *result1 = *result2;
        *result2 = t;
    } 
}

void answer_out(int number_of_roots, float result1, float result2){
    switch (number_of_roots){
    case ZERO_ROOTS: 
        printf("This equation has 0 roots.\n");
        break;
    case ONE_ROOT: 
        printf("This equation has 1 root : %.3f.\n", result1);
        break;
    case TWO_ROOTS:
        sort_result(&result1, &result2);
        printf("This equation has 2 roots : %.3f and %.3f.\n", result1, result2);
        break;
    case INF_ROOTS: 
        printf("This equation has infinitely many roots.\n");
        break;
    default:
        printf("Unexpected number of roots: %d\n", number_of_roots); // на всякий случай
        break;
    }
}