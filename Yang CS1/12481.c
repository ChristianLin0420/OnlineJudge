#include<stdio.h>
#include<limits.h>

int h[1000000] = {0};
int check[26][26] = {0};

int count(int l, int f) {

    if(l == f)
        return 0;
    
    if(l > f)
        return 100000;
    
    int one, two;

    one = count(l + 1, f) + (h[l] > h[l + 1] ? h[l] - h[l + 1] : h[l + 1] - h[l]);
    two = count(l + 2, f) + (h[l] > h[l + 2] ? h[l] - h[l + 2] : h[l + 2] - h[l]);

    if(one > two) {
        check[l][f] = check[l + 2][f] + 1;
        return two;
    } else if(one == two) {
        check[l][f] = (check[l + 1][f] > check[l + 2][f] ? check[l + 2][f] : check[l + 1][f]) + 1;
        return one;
    } else {
        check[l][f] = check[l + 1][f] + 1;
        return one;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    for(int i = 1;i <= n;i++) 
        scanf("%d", &h[i]);


    printf("%d ", count(1, n));
    printf("%d\n", check[1][n]);
    
    return 0;
}