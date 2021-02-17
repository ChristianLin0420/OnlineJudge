#include <stdio.h>

int main(){
	int T, N, M;
	int row[45][45], col[45][45];
	char nonogram[50][50];
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &N, &M);
		int tmp;
		for(int i = 0; i < N; ++i){
			scanf("%d", &tmp);
			row[i][0] = tmp;
			int j;
			for(j = 1; j <= tmp; ++j){
				scanf("%d", &row[i][j]);
			}
			row[i][j] = -1;
		}
		for(int i = 0; i < M; ++i){
			scanf("%d", &tmp);
			col[i][0] = tmp;
			int j;
			for(j = 1; j <= tmp; ++j){
				scanf("%d", &col[i][j]);
			}
			col[i][j] = -1;
		}
		for(int i = 0; i < N; ++i){
				scanf("%s", nonogram[i]);
		}
		
		int error = 0;
		for(int i = 0; i < N; i++){
			// check each row
			int r = 1;
			for(int j = 0; j < M; ++j){
				if(nonogram[i][j] == 'o'){
					if(row[i][r] > 0) row[i][r]--;
					else{
						error = 1;
						break;
					}
				}else{
					// x
					if(row[i][r] == 0) r++;
					else if((j > 0 && nonogram[i][j-1] == 'o') && row[i][r] > 0){
						error = 1;
						break;
					}
				}
			}
			if(row[i][r] == 0) r++;
			if(row[i][r] != -1){
				error = 1;
				break;
			}
			if(error) break;
		}
		for(int i = 0; i < M; i++){
			// check each col
			int r = 1;
			for(int j = 0; j < N; ++j){
				if(nonogram[j][i] == 'o'){
					if(col[i][r] > 0) col[i][r]--;
					else{
						error = 1;
						break;
					}
				}else{
					// x
					if(col[i][r] == 0) r++;
					else if((j > 0 && nonogram[j-1][i] == 'o') && col[i][r] > 0){
						error = 1;
						break;
					}
				}
			}
			if(col[i][r] == 0) r++;
			if(col[i][r] != -1){
				error = 1;
				break;
			}
			if(error) break;
		}
		
		if(error) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
