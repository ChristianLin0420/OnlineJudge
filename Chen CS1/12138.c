#include <stdio.h>

int main (void) {
    int n, q;
    scanf("%d %d", &n, &q);
    int i;
    long long int num[n+1];
    num[0] = 0;
    for (i = 1; i < n+1; i++) {
        long long int a;
        scanf("%lld", &a);
        if ( a > 0 ) {
            num[i] = num[i-1] + a;
        } else {
            num[i] = num[i-1];
        }
    }
    for (int j = 0; j < q; j++)
    {
        int l, r, m;
        scanf("%d %d %d", &l, &r, &m);
        if (l-1 > 0){
            if (num[l+m-1] != 0) {
                printf("%lld\n", num[l+m-1] - num[l-1]);
            } else {
                printf("%lld\n", num[l+m-1]);
            }
        } else {
            printf("%lld\n", num[l+m-1]);
        }
    }
    return 0;
}