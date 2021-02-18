#include <stdio.h>
#define MAX 1005

int main() {
    int n, m, i, tobuy = 0, nwallet = 0, ngame = 0, wallet[MAX] = {0}, game[MAX] = {0};
    scanf("%d%d", &n, &m);

    for (i = 0; i < n; i++) scanf("%d", &game[i]);
    for (i = 0; i < m; i++) scanf("%d", &wallet[i]);

    while (ngame < n) {
        if (wallet[nwallet] >= game[ngame]) {
            tobuy++;
            ngame++;
            nwallet++;
            continue;
        } else if (wallet[nwallet] < game[ngame]) {
            ngame++;
        }
    }
    
    printf("%d\n", tobuy);
    return 0;
}