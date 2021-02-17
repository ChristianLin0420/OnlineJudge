#include<stdio.h>

#define MAX_SIZE 50

int main() {

	char x[MAX_SIZE][MAX_SIZE], original[MAX_SIZE][MAX_SIZE], r[MAX_SIZE];
	int row, column;
	int p = 0,k = 0,o = 0,s = o;

	scanf("%d %d", &row, &column);

	for(int i = 1;i <= MAX_SIZE - 5; i++) {
		for(int j = 1;j <= column; j++) {
			x[i][j] = 'x';
		}
	}

	for(int i = 1;i <= row; i++) {
		for(int j = 1;j <= column; j++) {
			scanf(" %c", &x[i][j]);
			original[i][j] = x[i][j];
			
			if(x[i][j]=='o') k++;
		}
	}

	p = k;

	while(p == k) {
		p = 0;
		
		for(int i = row;i >= 1; i--) {
			for(int j = 1;j <= column; j++) {
				if(original[i][j] == 'o' && original[i + 1][j] == '.') {
					p++;
					original[i + 1][j] = 'o';
					original[i][j] = '.';
				}
			}
		}
		
		if(p == k) { 
			for(int i = 1;i <= row; i++) {
				for(int j = 1;j <= column;j++) {
					x[i][j] = original[i][j];
				}
			}
		}
	}

	for(int i = 1;i <= row; i++) {
		o = 0;
		
		for(int j = 1;j <= column; j++) {
			if(x[i][j] == 'o' || x[i][j] == 'x') o++;
		}
		
		if(o == column) {
			for(int j = 1;j <= column; j++)
				x[i][j]='.';
		}
	}

	int a = 1;

	for(int i = 1;i <= row; i++) {
		s = 0;
		
		for(int j = 1;j <= column; j++) {
			if(x[i][j] != '.') s++;
		}

		if(s != 0) {
			r[a] = i;
			a++;
		}
	}

	for(int i = 1;i <= row; i++) {
		for(int j = 1;j <= column; j++) {
			if(x[i][j] == 'o') x[i][j] = 'x';
		}
	}

	for(int i = 1;i <= row + 1 - a; i++) {
		for(int j = 1;j <= column; j++) 
			printf(".");
		
		printf("\n");
	}

	for(int i = 1;i < a; i++) {
		for(int j = 1;j <= column; j++) 
			printf("%c", x[r[i]][j]);
		
		printf("\n");
	}

	return 0;	
}
