#include <stdio.h>

int main (void) {
    int n;
    scanf("%d", &n);
    int num[n];
    int current_max = 0;
    for (int i = 0; i < n ; i++)
    {
        int a;
        scanf("%d", &a);
        num[a - 1] = i + 1;
    }
    for (int i = 0; i < n ; i++)
    {   
        if (i != n-1) {
            int b;
            scanf("%d", &b);
            if (num[b-1] > current_max){
                printf("%d ",num[b-1]-current_max);
                current_max = num[b-1];
            } else {
                printf("0 ");
            }
        } else {
            int b;
            scanf("%d", &b);
            if (num[b-1] > current_max){
                printf("%d",num[b-1]-current_max);
                current_max = num[b-1];
            } else {
                printf("0");
            }
        }
    }
    printf("\n");
    return 0;
}