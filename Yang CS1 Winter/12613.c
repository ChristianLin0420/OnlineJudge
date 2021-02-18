#include <stdio.h>
#include <math.h>

int main() {
    int T,a,b;
    scanf("%d", &T);

    while(T--) {
        scanf("%d%d", &a, &b);
        printf("%.0f\n", a * floor(log10(b + 1)));
    }

    return 0;
}