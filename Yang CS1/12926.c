#include<stdio.h>
double bank[1005][505]={0};
double rate[505][505]={0};
int main(void) {
	int n,n1,n2,from,to,t,N,T;
	scanf("%d %d",&N, &T);
	for(n=1;n<=N;n++) {
		scanf("%lf",&bank[1][n]);
	}
	
	for(from=1;from<=N;from++) {
		for(to=1;to<=N;to++) {
			scanf("%lf",&rate[from][to]);
		}
	}
	
	for(t=2;t <= T + 1;t++) {
		for(n1=1;n1<=N;n1++) {
			if(bank[t-1][n1]<10) {
				rate[n1][n1]=1;
				for(n2=1;n2<=N;n2++) {						
					if (n2!=n1) {
						rate[n1][n2]=0;
						rate[n2][n2]+=rate[n2][n1];
						rate[n2][n1]=0;
					}
				}
			}
		}
		
		for(n1=1;n1<=N;n1++) {
			for(n2=1;n2<=N;n2++) {
				bank[t][n1]+=bank[t-1][n2]*rate[n2][n1];
			}
		}
	}
	
	for(n=1;n<=N;n++) {
		printf("%.1f\n",bank[T + 1][n]);
	}
	return 0;
}