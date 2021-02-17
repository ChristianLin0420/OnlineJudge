#include <stdio.h>
#include <ctype.h>

double caculator(void) {
    double ans, a, b;
    char c;

    c = getchar();
    if ( isspace(c) ) {
        ans = caculator();
    } else if (c == '+') {
        printf("( ");
        a = caculator();
        printf(" + ");
        b = caculator();
        ans = a + b;
        printf(" )");
    } else if (c == '-') {
        printf("( ");
        a = caculator();
        printf(" - ");
        b = caculator();
        ans = a - b;
        printf(" )");
    } else if (c == '*') {
        printf("( ");
        a = caculator();
        printf(" * ");
        b = caculator();
        ans = a * b;
        printf(" )");
    } else if (c == '/') {
        printf("( ");
        a = caculator();
        printf(" / ");
        b = caculator();
        ans = a / b;
        printf(" )");
    } else if ( isdigit(c) ) {
        ans = c - '0';
        printf("%c", c);
    }
    
    return ans;
}

int main() {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        double ans = caculator();
        if (ans == (double)((int)ans)) {
            printf(" = %d\n", (int)ans);
        } else {
            printf(" = %.1f\n", ans);
        }
    }
    return 0;
}