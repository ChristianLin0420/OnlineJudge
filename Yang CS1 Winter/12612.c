#include <stdio.h>
#include <string.h>
#define maxn 10005
char s[maxn];
char sub_s[maxn];

int main() {

    int m;
    int li, ri, ki;
    int len;

    scanf("%s", s);
    scanf("%d", &m);

    while (m--) {
        scanf("%d %d %d", &li, &ri, &ki); 
        li--; ri--; // change li, ri to 0-based

        len = ri - li + 1;
        strncpy(sub_s, s + li, len);

        for (int i = 0; i < len; ++i)
            s[li + (i + ki) % len] = sub_s[i];
    }
    
    printf("%s\n", s);

    return 0;
}
