#include <stdio.h>
#include <math.h>

float calculate_discriminant(float a, float b, float c);
int find_final_result(float a, float b, float c, float *result1, float *result2);
int start_intro(void);
int answer_out(int n, float a, float b, float c, float result1, float result2);

int main(void) {
    float a = 0, b = 0, c = 0;
    float result1 = -1e9, result2 = -1e9;

    start_intro();
    scanf("%f %f %f", &a, &b, &c);

    int n = find_final_result(a, b, c, &result1, &result2);
    answer_out(n, a, b, c, result1, result2);

    return 0;
}

int start_intro(void){
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
    printf("||            ◣ Quadratic Equation Solver ◢         ||\n");
    printf("======================================================\n");
    printf("                   ax^2 + bx + c = 0                  \n");
    printf("------------------------------------------------------\n");
    printf("Please enter coefficients a, b, c separated by spaces:\n");
    printf("a (float), b (float), c (float)\n");
    printf("Example: 1 -3 2\n");
    printf("------------------------------------------------------\n");
    return 0;
}

float calculate_discriminant(float a, float b, float c) {
    return b * b - 4 * a * c;
}

int find_final_result(float a, float b, float c, float *result1, float *result2) {
    float discriminant = calculate_discriminant(a, b, c);

    if (a == 0) {
        if (b != 0){
                *result1 = -c / b;
                return 1;
        } else{
            if (c == 0) { return 2e9;}
            else { return 0;}
        }
    } else {
        if (discriminant < 0) {
            return 0;
        } else{
            if (discriminant == 0) { 
                *result1 = -b / (2 * a);
                return 1;
            }
            else {
                *result1 = (-b + sqrt(discriminant)) / (2 * a);
                *result2 = (-b - sqrt(discriminant)) / (2 * a);
                return 2;
            }
        }
    }
}

int answer_out(int n, float a, float b, float c, float result1, float result2){

    if (a==0) {printf("This equation is not quadratic\n");}

    if (n==2e9){
        printf("And this equation has infinitely many roots\n");
    } else { 
        if (n==0){
            printf("This equation has 0 roots\n");
        } else if (n==1){
            printf("This equation has 1 root : %.3f\n", result1);
        } else{
            printf("This equation has 2 roots : %.3f and %.3f\n", ((result1 > result2) ? result2 : result1), ((result1 > result2) ? result1 : result2));
        }
    }
    return 0;
}