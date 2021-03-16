// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>

// typedef struct _Node {
//     char s;
//     struct _Node* next;
//     struct _Node* prev;
// } Node;

// Node* newNode(char s) {
//     Node* new;
//     new = (Node*) malloc(sizeof(Node));
//     new -> s = s;
//     new -> next = NULL;
//     new -> prev = NULL;
//     return new;
// }

// int main () {
//     int n;
//     scanf("%d", &n);

//     for (int i = 0; i < n; i++)
//     {
//         int len;
//         Node* first = NULL, *new, *pre = NULL, *now = NULL;

//         scanf("%d", &len);

//         char string[len+2];

//         scanf("%s", string);
//         printf("gi");

//         for (int  j= 0; j < len; j++) {
//             printf("%c", string[j]);

//             if (islower(string[j])) {
//                 if (first == NULL) {
//                     new = newNode(string[j]);
//                     first = new;
//                     now = first;
//                 } else {
//                     pre = now;
//                     new = newNode(string[j]);
//                     pre -> next = new;
//                     new -> prev = pre;
//                 }
//             } 
//             else {
//                 if (string[j] == 'L') {
//                     // now = now -> prev;
//                     // pre = now -> prev;
//                 } else if (string[j] == 'B') {
//                     // pre = now -> prev;
//                     // pre -> next = now -> next;
//                     // free(now);
//                 } else {
//                     pre = now;
//                     now = now -> next;
//                 }
//             }
//         }

//         printf("hi");
//         Node* temp;
//         temp = first;
//         while(temp != NULL) {
//             printf("%c", temp ->s);
//             temp = temp -> next;
//         }
        
//     }
//     return 0;
    
// }


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct _Node {
    char s;
    struct _Node* next;
    struct _Node* prev;
} Node;

Node* newNode(char s) {
    Node* new;
    new = (Node*) malloc(sizeof(Node));
    new -> s = s;
    new -> next = NULL;
    new -> prev = NULL;
    return new;
}

int main () {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int len;
        Node* first = NULL, *new, *pre = NULL, *now = NULL;

        scanf("%d", &len);

        char string[len+2];

        scanf("%s", string);
        
        for (int  j = 0; j < len; j++) {

            if (islower(string[j])) {
                if (first == NULL) {
                    new = newNode(string[j]);     
                    first = new;
                    now = first;
                } else {
                    if (now -> s == '$') {
                        pre = now;
                        now -> s = string[j];
                        first = now;
                    } else if (now -> s == '#') {
                        pre = now;
                        now -> s = string[j];
                    } else {
                        pre = now;
                        new = newNode(string[j]);
                        if (now -> next != NULL) {
                            new -> next = now -> next;
                            now -> next -> prev = new;
                        }
                        pre -> next = new;
                        new -> prev = pre;
                        
                        now = new;
                    }
                    
                }
            } else {
                if (string[j] == 'L') {
                    if (now -> prev != NULL) {
                        now = now -> prev;
                    } else {
                        new = newNode('$');
                        now -> prev = new;
                        new -> next = now;
                        now = new;
                    }
    
                } else if (string[j] == 'B') {
                    pre = now -> prev;
                    pre -> next = now -> next;
                    free(now);
                    now = pre;
                } else {
                    if (now -> next != NULL) {
                        pre = now;
                        now = now -> next;
                    } else {
                        new = newNode('#');
                        now -> next = new;
                        new -> prev = now;
                        now = new;
                    }
                }
            }
        }
        
        Node* temp;
        temp = first;
        while(temp != NULL) {
            printf("%c", temp ->s);
            temp = temp -> next;
        }
        printf("\n");
    }
    return 0;
    
}