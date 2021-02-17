#include <stdio.h>

int main (void) {

    long long int a[1000001] = {0};

    for (int i = 1; i <= 1000000; i++) {
        int num = i;
        int count = (i == 0) ? 0 : a[i - 1];

        while (num != 0) {
            if (num % 10 == 1) count++;
            num /= 10;
        }

        a[i] = count;
    }
    
    int testcase;
    scanf("%d", &testcase);

    while (testcase--) {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%lld\n", a[y] - a[x - 1]);
    }

    return 0;
}