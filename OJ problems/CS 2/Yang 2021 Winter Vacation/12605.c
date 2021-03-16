#include <stdio.h>
#define maxn 200005
char s[maxn];
int alpha_idx[30];
char map[30];

void swap_int(int* a, int* b);
void swap_char(char* a, char* b);

int main() {
    int n, m;
    char c1, c2;
    
    for(int i=0; i<26; ++i){
        alpha_idx[i] = i;
        map[i] = (char)('a'+i);
    }

    scanf("%d %d", &n, &m);  
    scanf("%s", s);
    for(int i=0; i<m; ++i){
        scanf(" %c %c", &c1, &c2);
        swap_char(&map[alpha_idx[c1-'a']], &map[alpha_idx[c2-'a']]);
        swap_int(&alpha_idx[c1-'a'], &alpha_idx[c2-'a']);       
    }

    for(int i=0; i<n; i++){
        printf("%c", map[s[i]-'a']);
    }
    printf("\n");

    return 0;
}

void swap_int(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap_char(char *a, char *b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}