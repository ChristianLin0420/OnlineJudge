#include <stdio.h>

int gcd(int a, int b) {
	if (b != 0) return gcd(b, a % b);
    return a;
}

int lcm(int a, int b) {
	if (b == 0) return a;
    return a * b / gcd(a, b);
}

int power(int a, int b) {
	if (b != 0) return (a * power(a, b - 1));
   	return 1;
}

int main() {
	int a, b, c, d;

	scanf("%d%d%d%d", &a, &b, &c, &d);

	printf("%d\n", gcd(lcm(power(a, b), c), d));
	printf("%d\n", gcd(power(lcm(a, b), c), d));
	printf("%d\n", lcm(gcd(power(a, b), c), d));
	printf("%d\n", lcm(power(gcd(a, b), c), d));
	printf("%d\n", power(gcd(lcm(a, b), c), d));
	printf("%d\n", power(lcm(gcd(a, b), c), d));

	return 0;
}