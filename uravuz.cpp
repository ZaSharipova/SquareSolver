#include <stdio.h>
#include <math.h>
#include <limits.h>

#define INF_ROOTS INT_MAX
const float EPS = 1e-6;

void start_intro(void);
void input_coefficients(float *a, float *b, float *c);
void answer_out(int n, float a, float result1, float result2);

int find_result(float a, float b, float c, float *result1, float *result2);
float calculate_discriminant(float a, float b, float c);
int find_linear_root(float b, float c, float *result1);
int find_quadratic_roots(float a, float b, float c, float *result1, float *result2);
void sort_result(float *result1, float *result2);

int main(void) {
    float a = 0, b = 0, c = 0;
    float result1 = 0, result2 = 0;

    start_intro();
    input_coefficients(&a, &b, &c);

    int n = find_result(a, b, c, &result1, &result2);
    answer_out(n, a, result1, result2);

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
    int status;
    do {
        status = scanf("%f %f %f", a, b, c);
        if (status != 3) {
            printf("Input error! You must enter three real numbers separated by spaces.\n");
            printf("Try again:\n");
            while (getchar() != '\n') { }
        }
    } while (status != 3);
}

int find_result(float a, float b, float c, float *result1, float *result2) {
    if (fabsf(a) < EPS) {
        return find_linear_root(b, c, result1);
    } else {
        return find_quadratic_roots(a, b, c, result1, result2);
    }
}

float calculate_discriminant(float a, float b, float c) {
    return b * b - 4 * a * c;
}

int find_linear_root(float b, float c, float *result1){
    if (fabsf(b) > EPS){
            *result1 = -c / b;
            return 1;
    } else{
        if (fabsf(c) < EPS) { return INF_ROOTS;}
        else { return 0;}
    }
}

int find_quadratic_roots(float a, float b, float c, float *result1, float *result2){
    float discriminant = calculate_discriminant(a, b, c);

    if (discriminant < -EPS) {
            return 0;
    } else{
        if (fabsf(discriminant) < EPS) { 
            *result1 = -b / (2 * a);
            return 1;
        } else {
            *result1 = (-b + sqrt(discriminant)) / (2 * a);
            *result2 = (-b - sqrt(discriminant)) / (2 * a);
            return 2;
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

void answer_out(int n, float a, float result1, float result2){
   
    if (fabsf(a) < EPS) {printf("This equation is not quadratic\n");}

    if (n == INF_ROOTS){
        printf("And this equation has infinitely many roots\n");
    } else { 
        if (n == 0){
            printf("This equation has 0 roots\n");
        } else if (n == 1){
            printf("This equation has 1 root : %.3f\n", result1);
        } else{
            sort_result(&result1, &result2);
            printf("This equation has 2 roots : %.3f and %.3f\n", result1, result2);
        }
    }
}