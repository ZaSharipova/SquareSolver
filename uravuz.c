#include <stdio.h>
#include <math.h>

float disc(float a, float b, float c);
int find_res(float a, float b, float c);
int roots2(float a, float b, float c, float discr);

int main(void) {
    float a = 0, b = 0, c = 0;

    scanf("%f %f %f", &a, &b, &c);

    find_res(a, b, c);
    return 0;
}

float disc(float a, float b, float c) {
    return b * b - 4 * a * c;
}

int find_res(float a, float b, float c) {
    float discr = disc(a, b, c);

    if (a == 0) {
        printf("in the quadratic equation leading coefficient doesn't have to be 0\n");
        if (b != 0){
                printf("and in linear equation root is %.3f\n", -c/b);
        } else{
            if (c == 0) { printf("and this equation has infinitely many roots\n");}
            else { printf("and this equation has 0 roots\n");}
        }
    } else {
        if (discr < 0) {
            printf("this equation has 0 roots\n");
        } else{
            if (discr == 0) { 
                printf("this equation's root is %.3f\n", -b/(2 * a));
            }
            else {
                roots2(a, b, c, discr);
            }
        }
    }
    return 0;
}

int roots2(float a, float b, float c, float discr) {
    float res0_sq = sqrt(discr);
    float res1 = (-b + res0_sq) / (2 * a);
    float res2 = (-b - res0_sq) / (2 * a);

    printf("this equation's roots are %.3f and %.3f\n", (res1 > res2 ? res2 : res1), (res1 > res2 ? res1 : res2));
    return 0;
}