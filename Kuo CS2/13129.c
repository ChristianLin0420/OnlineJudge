// #include <stdio.h>
// #include <stdlib.h>
// #include "13129.h"

// Node* newNode(int data) {
//     Node *new = (Node*)malloc(sizeof(Node));
//     new -> number = data;
//     new -> next = NULL;
//     new -> prev = NULL;
//     return new;
// }

// Node* createList(int n) {
    
//     Node* node = NULL;
    
//     for (int i = 1; i <= n; i++) {
//         if (i == 1) {
//             node = newNode(i);
//             node->next = node;
//             node->prev = node;
//         } else {
//             Node *last = node->prev;
//             Node *new = (Node*)malloc(sizeof(Node));
//             new->number = i;

//             new->next = node;
//             node->prev = new;
//             new->prev = last;
//             last->next = new;
//         }
//     }

//     return node;
// }

// void solveJosephus(int n, int k) {

//     Node *current = head;

//     for (int i = 0; i < k; i++) {
//         int lucky_num;

//         scanf("%d", &lucky_num);

//         for (int m = 0; m < lucky_num - 1; m++) {
//             if (lucky_num % 2 == 0) {
//                 current = current->prev;
//             } else {
//                 current = current->next;
//             }
//             printf("%d ", current->number);
//         }

//         printf("\n----%d\n", current->number);

//         // delete the node
//         Node *temp = current;
//         if(lucky_num % 2 == 0)
//             temp = current->prev;
//         else
//             temp = current->next;

//         Node *pre = current->prev;
//         Node *next = current->next;
//         pre->next = next;
//         next->prev = pre;
//         current = temp;
//         printf("\n%d\n", current->number);
//     }
// }

// int main(){

//     int n, k;

//     while(scanf("%d%d", &n, &k) != EOF){
//         head = createList(n);
//         solveJosephus(n, k);
//     }

//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>
#include "13129.h"

Node* newNode(int  data) {
    Node* new;
    new = (Node*) malloc(sizeof(Node));
    new -> number = data;
    new -> next = NULL;
    new -> prev = NULL;
    return new;
}

Node* createList(int n) {
    Node* new , *first, *pre;
    for (int i = 1; i < n+1; i++){
        
        if ( i == 1) {
            new = newNode(i);
            first = new;
        } else if (i == n) {
            pre = new;
            new = newNode(i);
            pre -> next = new;
            new -> prev = pre;
            new -> next = first;
            first -> prev = new;
        } else {
            pre = new;
            new = newNode(i);
            pre -> next = new;
            new -> prev = pre;
        }
    }
    return first;
}

void delete (Node* del) {
    Node* pre, *nex;
    pre = del -> prev;
    nex = del -> next;
    pre -> next = nex;
    nex -> prev = pre;
}

void solveJosephus(int n, int k) {
    Node* temp, *deleted;
    temp = head;

    int del;
    scanf("%d", &del);
    int step = del-1;

    if (!(del % 2)) {
        while (step--) {
            temp = temp -> prev;
        }
        printf("%d\n", temp -> number);
        deleted = temp;
        delete(temp);
    } else {
        while (step--) {
            temp = temp -> next;
        }
        printf("%d\n", temp -> number);
        deleted = temp;
        delete(temp);
    }

    for (int i = 1; i < k; i++) {
        scanf("%d", &del);
        step = del-1;
        
        if (!(del % 2)) {
            temp = deleted -> prev;
            while (step--) {
                temp = temp -> prev;
            }
            printf("%d\n", temp -> number);
            deleted = temp;
            delete(temp);
        } else {
            temp = deleted -> next;
            while (step--) {
                temp = temp -> next;

            }
            printf("%d\n", temp -> number);
            deleted = temp;
            delete(temp);
        }

    }
    return;
}

int main(){

    int n, k;

    while(scanf("%d%d", &n, &k) != EOF){
        head = createList(n);
        solveJosephus(n, k);
    }

    return 0;
}