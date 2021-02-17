#include <stdio.h>
#include <stdbool.h>

int main() {
	
	int n, m;

	scanf("%d %d", &n, &m);

	int sequence_order_table[200000];

	bool check_order_table[200000] = {false};

	for(int i = 0; i < m; i++) {
		scanf("%d", &sequence_order_table[i]);
	}

	for(int i = m - 1; i >= 0; i--) {
		if (!check_order_table[sequence_order_table[i] - 1]) {
			printf("%d\n", sequence_order_table[i]);
			check_order_table[sequence_order_table[i] - 1] = true;
		}
	}

	for(int i = 0; i < n; i++) {
		if(!check_order_table[i]) {
			printf("%d\n", i + 1);
		}
	}
}