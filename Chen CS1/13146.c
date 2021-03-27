#include <stdio.h>

int main () {
    int z;
    double a, b;
    scanf("%lf %lf %d", &a, &b, &z);

    printf("%.*lf\n", z, a*b);
}