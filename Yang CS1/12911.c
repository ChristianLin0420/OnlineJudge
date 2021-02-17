#include<stdio.h> 
#include<string.h>

int main(void) {
	int T,t,A,B,i;
	scanf("%d",&T);

	for(t = 1;t <= T; t++) {

		int first_same_a = -1;

		char a[2000] = {'\0'};
		char b[2000] = {'\0'};

		scanf("%s %s",a,b);

		for(i=0;i<strlen(a);i++) {
			if(a[i]==b[0]) {
				for(A=i,B=0;A<strlen(a);A++,B++) {
					if(a[A]!=b[B]) break;
					if(A == strlen(a)-1 || B == strlen(b) - 1) first_same_a = i;
				}
			}

			if(first_same_a != -1) break;
		}

		if (first_same_a == -1) {
			printf("%s%s\n",a,b);
		} else {

			for(A=first_same_a,B=0;B<strlen(b);A++,B++) {
    			a[A]=b[B];
   			}
			
			printf("%s\n",a);
		}
	}

	return 0;
} 