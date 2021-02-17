#include <stdio.h>
int main(void) {
    int A,B,C;
    scanf("%d%d%d", &A,&B,&C);
    int three_add = (A+B+C)/2;
    printf("%d %d %d\n",three_add-B,three_add-C,three_add-A);
    return 0;
}