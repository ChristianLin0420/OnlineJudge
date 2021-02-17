#include <stdio.h>

int main (void) {
	int n;
    scanf ("%d", &n);
    if (n == 1) {
        printf("10 9\n");
    } else {
	    printf("%d %d\n", 3 * n, 2 * n);
    }
	return 0;
}