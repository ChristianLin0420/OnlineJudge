#include <stdio.h>
int main(void) {
    float a,b;
    scanf("%f%f", &a,&b);
    int c = a*100;
    int d = b*100;
    printf("%d.%04d\n",(c*d)/10000,(c*d)%10000);
    return 0;
}