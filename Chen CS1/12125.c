#include <stdio.h>
#include <ctype.h>

int main (void) {
	int n, l;
	scanf("%d%d", &n, &l);
    long long int num[n];
    int count = 0;
    while (n--) {
        int a;
        scanf("%d(/`A`)/ ~I__I", &a);
        if (count == 0){
            num[count] = a;
        } else {
            num[count] = a + num[count-1];
        }
        count++;
    }
    
    while (l--) {
        long long int a, b;
        scanf("%lld %lld", &a, &b);
        if (a != b) {
            if (a == 1){
                printf("%lld\n", num[b-1]);
            } else {
                printf("%lld\n", num[b-1] - num[a-2]);
            }
        } else {
            if (b == 1){
                printf("%lld\n", num[b-1]);
            } else {
                printf("%lld\n", num[b-1] - num[b-2]);
            }
    
        }
        
    }
    return 0;
}