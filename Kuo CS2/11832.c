#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m;

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;
 
Node* newNode(int data) {
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

Node* init_list(int size) {
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

