#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define min_alpha_ascii_code 97

int main() {

    int length_a, length_b;

    while(scanf("%d %d", &length_a, &length_b) != EOF) {
        
        int len_a = length_a;
        int len_b = length_b;
        
        char a[len_a], b[len_b];

        scanf("%s %s", a, b);

        if (len_a != len_b) {
            printf("NO\n");
        } else {
            int a_alpha_array[26], b_alpha_array[26];
            
            for (int i = 0; i < 26; i++) {
                a_alpha_array[i] = 0;
                b_alpha_array[i] = 0;
            }

            for (int i = 0; i < len_a; i++) {
                a_alpha_array[a[i] - min_alpha_ascii_code]++;
                b_alpha_array[b[i] - min_alpha_ascii_code]++;
            }
            
            bool isValid = true;

            for (int i = 0; i < 26; i++) {
                if (a_alpha_array[i] != b_alpha_array[i]) {
                    isValid = false;
                    break;
                }
            }

            if (isValid) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }

    return 0;
}
