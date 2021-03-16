#include <stdio.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
typedef long long ll;
const ll inf = 1e18;
ll len[60];

void solve(ll l, ll r, ll k)
{
    if (k == 1) {
        for (int i = l; i <= r; i++)
            printf("%c", "OuQ"[i]);
        return;
    }
    
    // O
    ll ls = l, rs = r;
    if (ls <= 0 && 0 <= rs)
        printf("O");

    // S_k-1
    ls = l - 1;
    rs = r - 1;

    if (0 <= rs && ls <= len[k - 1] - 1)
        solve(max(ls, 0), min(rs, len[k - 1] - 1), k - 1);

    // u
    ls = l - 1 - len[k - 1];
    rs = r - 1 - len[k - 1];

    if (ls <= 0 && 0 <= rs)
        printf("u");

    // S_k-1
    ls = l - 1 - len[k - 1] - 1;
    rs = r - 1 - len[k - 1] - 1;
    if (0 <= rs && ls <= len[k - 1] - 1)
        solve(max(ls, 0), min(rs, len[k - 1] - 1), k - 1);

    // Q
    ls = l - 1 - len[k - 1] - 1 - len[k - 1];
    rs = r - 1 - len[k - 1] - 1 - len[k - 1];
    if (ls <= 0 && 0 <= rs)
        printf("Q");
}

int main() {
    int n = 1;
    len[1] = 3;
    
    while ((inf - 3) / 2 > len[n]) {
        n++;
        len[n] = len[n - 1] * 2 + 3;
    }

    ll l, r, k;

    while (scanf("%lld %lld %lld", &k, &l, &r) != EOF) {
        solve(l, r, k);
        printf("\n");
    }

    return 0;
}