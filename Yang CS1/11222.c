#include <stdio.h>

int n, q[10], count = 0;

int place(int row);
int valid(int row, int col);
int display(void);

int main(void) {
    scanf("%d", &n);
    printf("%d", place(0));
    return 0;
}

int valid(int row, int col) {
    int i;
    for (i=0; i<=row-1; i++) {
        if ( q[i] == col || row-i == col-q[i] || row-i == q[i]-col )
            return 0;
    }
    return 1;
}

int  display(void) {
    count++;
    return count;
}

int place(int row) {
    int j;
    if (row == n) {
        display();
    } else {
        for (j = 0; j < n; j++) {
            if (valid(row, j)) {
                q[row] = j;
                place(row+1);
            }
        }
    }
    return count;
}