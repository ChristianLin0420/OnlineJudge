#include <stdio.h>
#include <string.h>

char in[17] = { '\0' };
char in2[17] = { '\0' };
int npasswd = 0;
char passwd[17];

void perm(int pos, int start, int end) {
    if(pos >= 4) {
        npasswd++;
        passwd[pos] = '\0';

        if(npasswd == 1) printf("%s",passwd);
        else printf(", %s",passwd);
    }
    
    for(int i = start; i <= end; i++) {
        passwd[pos] = in[i];
        perm(pos + 1, i + 1, end);
    }
}

int main() {
    char temp;
    
    scanf("%s",in);
    
    int len = strlen(in);

    for(int a = 1;a < len; a++) {
        for(int b = 0; b < len - 1; b++) {
            if(in[b] > in[b + 1]) {
                temp = in[b];
                in[b] = in[b + 1];
                in[b + 1] = temp;
            }
        }
    }

    perm(0, 0, len - 1);
    
    printf("\n");
    
    return 0;
}