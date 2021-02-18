#include <stdio.h>
#include <stdlib.h>

int is_leap(int n) {
    return (!(n % 400) || (!(n % 4) && n % 100)) ? 1 : 0 ;
}

int main() {
    int testcase, year;
    scanf("%d", &testcase);

    while(testcase--) {
        scanf("%d", &year);

        int same = 0, is_leap_ori = is_leap(year);
        same += is_leap(++year) ? 366 % 7 : 365 % 7;

        while(same || is_leap_ori ^ is_leap(year)) {
            same += is_leap(++year) ? 366 % 7 : 365 % 7;
            same %= 7;
        }
        printf("%d\n",year);
    }

    return 0;
}