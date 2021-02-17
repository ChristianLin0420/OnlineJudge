#include <stdio.h>

int main (void) {
	int n, i, l = 0, r = 0;
	scanf("%d", &n);
    char s[n];
    scanf("%s", s);

    for (i = 0; i <= n; i++) {
        if (s[i] == 'L'){
            l += 1;
        } else if (s[i] == 'R')
        {
            r += 1;
        }
    }

    printf("%d\n", r+l+1);

	return 0;
}