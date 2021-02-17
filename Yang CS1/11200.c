#include <stdio.h>

void hanoi(int n, char A, char B, char C) {

	if (n == 1) { 
        printf("1\n"); 
        return; 
    } 

    hanoi(n - 1, A, C, B); 
    printf("%d\n", n); 
    hanoi(n - 1, C, B, A); 
}

int main(){
    int n;
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    return 0;
}