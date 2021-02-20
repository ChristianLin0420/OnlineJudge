#include <stdio.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
#define inf 2147483647
#define maxn 200005
char d[maxn];

int main() {
    int n;
    int p, l = -1;
    int time = inf;
    
    scanf("%d", &n);
    scanf("%s", d);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &p);

        if (d[i] == 'R') {
            l = p;
            continue;
        }

        if (l != -1) {
            time = min(time, (p - l) / 2);
        }
    }

    printf("%d\n", time == inf ? -1 : time);

    return 0;
}