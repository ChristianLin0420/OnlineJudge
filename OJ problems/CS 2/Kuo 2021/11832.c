#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m;
typedef struct _Node
{
    int data;
    struct _Node *next;
} Node;
 
Node* newNode(int data)
{
    Node *new = (Node*)malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;
    return new;
}

void printList (Node * fisr) {
    Node *temp;
    for (temp = fisr; temp!= NULL; temp = temp-> next) {
        printf("%d\n", temp -> data);
    }
}

Node* init_list(int size){
    Node *new, *pre = NULL, *first = NULL;

    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        new = newNode(data);

        if (first ==  NULL) {
            pre = new;
            first = new;
        } else {
            pre->next = new;
            pre = new;
        }
    }
    return first;
}

 
int main() {
    scanf("%d %d", &n, &m);
    Node* first = init_list(n);

    for (int j = 0; j < m; j++) {
        char method[4];
        scanf("%s", method);

        if (!strcmp(method, "ADD")) {
            int index, number;
            Node *now = NULL, *third = NULL, *new = NULL;

            scanf("%d %d", &index, &number);
            now = first;

            if(index == 0) {
                new = newNode(number);
                new -> next = now;
                first = new;
            } else {
                for (int k = 0; k < index - 1; k++) {
                    now = now -> next;
                }

                third = now -> next;
                new = newNode(number);
                now -> next = new;
                new -> next = third;
            }
        } else {
            int start, end;
            Node *now = NULL, *new = NULL, *pre = NULL, *new_first = NULL;
        
            scanf("%d %d", &start, &end);
            int s = start;
            int e = end + start -1;
            now = first;
            
            if (start == 0 ) {
                continue;
            } else {
                for (int k = 0; k < s ; k++) {
                    pre = now;
                    now = now -> next;
                }
                
                new_first = now;

                for (int k = 0; k < e - s; k++) {
                    now = now -> next;
                }
                pre -> next = now -> next;
                now -> next = first;
                first = new_first;
            }
            
        }
    }
    printList(first);
    return 0;
}





// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// typedef struct _Node{
//     int data;
//     struct _Node* next;
// } Node;

// Node* newNode(int data) {
//     Node* new;
//     new = (Node*) malloc(sizeof(Node));
//     new -> next = NULL;
//     new -> data = data;
//     return new;
// }

// void printList(Node* first) {
//     Node* temp;
//     temp = first;
//     while (temp != NULL) {
//         printf("%d\n", temp -> data);
//         temp = temp -> next;
//     }
//     return;
// }

// int main () {
//     int n, m;
//     scanf ("%d %d", &n, &m);

//     int data;
//     Node* new, *first, *temp;

//     scanf("%d", &data);
//     new = newNode(data);
//     first = new;
//     temp = first;

//     for (int i = 1; i < n ; i++) {   
//         int data;
//         Node* new;
//         scanf("%d", &data);
//         new = newNode(data);
//         temp -> next = new;
//         temp = new;
//     }

//     for (int j = 0; j < m; j++) {
//         char method[4];
//         Node* run, *pre;
//         run = first;
//         scanf("%s", method);
        
//         if ( !strcmp(method, "ADD")) {
            
//             int index, data;
//             scanf("%d %d", &index, &data);   
            
//             if (index == 0) {
//                 new = newNode(data);
                
//                 new -> next = run;
//                 first = new;
//             } else {
//                 for (int l = 1; l < index; l++)
//                 {
//                     pre = run;
//                     run = run -> next;
//                 }
//                 new = newNode(data);
//                 new -> next = run;
//                 pre -> next = new;
//             }
//         } else {
//             int start, end;
//             scanf("%d %d", &start, &end);

//             end = end + start - 1;
//             Node *new_first;

//             temp = first;
//             if (start == 0) {
//                 continue;
//             } else {
//                 for (int j = 0; j < start; j++) {
//                     pre = temp;
//                     temp = temp -> next;
//                 }

//                 new_first = temp;

//                 for (int k = 0; k < end - start; k++) {
//                     temp = temp -> next;
//                 }
                
//                 pre -> next = temp -> next;
//                 temp -> next = first;
//                 first = new_first;
                
                
//             }
            
//         }
        
//     }

//     printList(first);
//     return 0;
// }