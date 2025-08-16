#include <stdio.h>
#include <math.h>

float disc(float a0, float a1, float a2) {
    return a1 * a1 - 4 * a0 * a2;
}

int roots(float a0, float a1, float a2, float discr, float *res1, float *res2) {
    float res0_sq = sqrt(discr);
    *res1 = (-a1 + res0_sq) / (2 * a0);
    *res2 = (-a1 - res0_sq) / (2 * a0);
    return 0;
}

float mini(float res1, float res2) {
    return (res1 < res2) ? res1 : res2;
}

int main(void) {
    float a0, a1, a2;
    float res1, res2;

    scanf("%f %f %f", &a0, &a1, &a2);
    float discr = disc(a0, a1, a2);

    if (discr < 0) {
        printf("has 0 roots\n");
    } else {
        if (a0 == 0) {
            printf("root is %.3f\n", -a2 / a1);
        } else {
            roots(a0, a1, a2, discr, &res1, &res2);
            printf("roots are %.3f and %.3f\n", mini(res1, res2), (res1 > res2 ? res1 : res2));
        }
    }
    return 0;
}
