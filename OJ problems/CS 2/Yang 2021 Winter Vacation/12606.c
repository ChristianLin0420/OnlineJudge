#include <stdio.h>
#define inf 2147483647

int main() {
    int n, x;
    int mx = -1, mn = inf;

    scanf("%d", &n);
    for (int i = 0; i < n + 1; i++) {
        scanf("%d", &x);
        mx = x > mx ? x : mx;
        mn = x < mn ? x : mn;
    }

    printf("%d\n", 2 * (mx - mn));
}

// finished