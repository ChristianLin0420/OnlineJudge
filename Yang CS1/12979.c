#include <stdio.h>
#include <stdbool.h>

#define MAX_COOKIE_COUNT 20
#define lli long long int

bool comboSum(lli a[], int size, lli target, int count) {

    if (target == 0 && size == 0 && count == 0)
        return false;
    else if (target == 0 && count > 0)
       	return true;
    else if (target != 0 && size == 0)
       	return false;

	size--;

	if (a[size] == 0) {
		return (comboSum(a, size, target, count));
	} else {
		return (comboSum(a, size, target, count) || comboSum(a, size, target - a[size], count + 1));
	}
};

int main() {

	int cookie_count, calory;
	lli cookies[MAX_COOKIE_COUNT] = { 0 };

	scanf("%d %d", &cookie_count, &calory);

	for(int i = 0; i < cookie_count; i++)
		scanf("%lld", &cookies[i]);

	bool result = comboSum(cookies, cookie_count, calory, 0);

	if (result) printf("YES\n");
	else printf("NO\n");

	return 0;
}