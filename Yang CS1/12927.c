#include <stdio.h>
#include <stdlib.h>

#define MAX_SPECIES 32

int main(void) {
	int petris_count, query_count;
	int start, end, num = 0;
		
	scanf("%d %d", &petris_count, &query_count);

	int petri[petris_count];
	int count[MAX_SPECIES][petris_count];
	
	for(int i = 0; i < petris_count; i++)
		scanf("%d", &petri[i]);
	
	for(int i = 0; i < MAX_SPECIES; i++)
		count[i][0] = 0;
	
	count[petri[0]][0] = 1;

	for(int i = 0; i < MAX_SPECIES; i++) 
		for(int j = 1; j < petris_count; j++) 
			count[i][j] = (i == petri[j]) ? count[i][j - 1] + 1 : count[i][j - 1];


	while (query_count--) {

		num = 0;

		scanf("%d %d", &start, &end);

		for (int i = 0; i < MAX_SPECIES; i++) {
			if (start == 0) {
				if (count[i][end] != 0) num++;
			} else { 
				if(count[i][start - 1] != count[i][end]) num++;
			}
		}

		printf("%d\n", num);
		
	}	

	return 0;
}