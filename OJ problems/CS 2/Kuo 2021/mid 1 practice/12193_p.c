#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node{
    struct _Node* right;
    struct _Node* left;
    int data;
} Node;

int nodes(Node* head, int level, int tal) {
    if (head->left != NULL && level > 1 ) tal = nodes(head->left, level-1, tal);
    if (head->right != NULL && level > 1 ) tal = nodes(head->right, level-1, tal);
    if (level == 1) tal += 1;
    return tal;
    
}

int max(Node* head) {
    int left = 0, right = 0;
    if (head == NULL) return 0;
    left += max(head->left);
    right += max(head->right);
    return left >= right? left + 1: right + 1;
}

int sum(Node*head, int level, int tal) {

    if (head->left != NULL && level > 1 ) tal = sum(head->left, level-1, tal);
    if (head->right != NULL && level > 1 ) tal = sum(head->right, level-1, tal);
    if (level == 1) {
        tal += head->data;
    }
    return tal;
}

Node* newNode(int d){
    Node* new;
    new = (Node*) malloc(sizeof(Node));
    new -> right = new -> left = NULL;
    new -> data = d;
    return new;
}

Node* ConTree(Node *tmp, int data) {
    Node* root = tmp;
    if (data > root ->data) {
        if (root->right != NULL) {
            ConTree(root->right,data);
        } else {
            Node * new_node = newNode(data);
            root->right = new_node;
        }
    } else {
        if (root->left != NULL) {
            ConTree(root->left,data);
        } else {
            Node * new_node = newNode(data);
            root->left = new_node;
        }
    }
    return root;
}

Node* build() {
    Node* head=NULL;
    int data, len;
    scanf("%d", &len);
    if (len == 0) return NULL;

    scanf("%d", &data);
    head = newNode(data);

    for (int i = 1; i < len; i++){
        scanf("%d", &data);
        head = ConTree(head, data);
    }
    return head;
}


void printT(Node* head) {
    if (head != NULL) {
        if (head -> left != NULL) printT(head -> left);
        printf("%d ", head->data);
        if (head -> right != NULL) printT(head->right);
    }
}



int main () {
    Node* top;
    top = build();  
    
    int step;
    char op[10];

    scanf("%d", &step);
    while(step--) {
        scanf("%s", op);
        int level;

        if (strcmp("AverLevel", op) == 0) {
            scanf("%d", &level);
            if (level == 0 || level > max(top)) {
                printf("0\n"); 
            } else {
                double ans = (double)sum(top, level, 0)/(double)nodes(top, level, 0);
                if (ans == 0.000) {
                    printf("0\n");
                } else {
                    printf("%.3f\n", ans);
                }
            }
        } else if (strcmp("SumLevel", op) == 0) {
            scanf("%d", &level);
            if (level == 0 || level > max(top)) {
                printf("0\n"); 
            } else {
                printf("%d\n", sum(top, level, 0));
            }

        } else if (strcmp("GetMax", op) == 0) {
            printf("%d\n", max(top));

        } else if (strcmp("P", op) == 0) {
            if (top == NULL){
                printf("NULL\n");
            } else {
                printT(top);
                printf("\n");
            }
        }
        
    }
    
    return 0;

}