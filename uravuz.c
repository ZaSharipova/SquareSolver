#include <stdio.h>
#include <math.h>

float disc(float a, float b, float c);
int roots2(float a, float b, float c, float discr);
int find_res(float a, float b, float c);

int main(void) {
    float a = 0, b = 0, c = 0;

    scanf("%f %f %f", &a, &b, &c);

    find_res(a, b, c);
    return 0;
}

float disc(float a, float b, float c) {
    return b * b - 4 * a * c;
}

int find_res(float a, float b, float c){
    float discr = disc(a, b, c);

    if (a == 0){
        if (b!=0){
            printf("leading coefficient has to be not 0, but in linear equation root is %.3f\n", -c/b);
        } else{
            printf("coefficients are wrong\n");
        }
    } else{
        if (discr < 0){
            printf("has 0 roots\n");
        } else{
            if (discr == 0){ 
                printf("root is %.3f\n", -b/(2*a));
            }
            else{
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

    printf("roots are %.3f and %.3f\n", (res1 > res2 ? res2 : res1), (res1 > res2 ? res1 : res2));
    return 0;
}