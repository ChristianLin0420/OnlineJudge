
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "10966.h"

BTNode* EXPR() {
    BTNode *right, *root;
    right = FACTOR();
    if(pos > 0) {
        char c = expr[pos--];
        if(c=='&'||c=='|') {
            root = makeNode(c);
            root -> right = right;
            root -> left = EXPR();
        }
        else root = right;
    } else root = right;
    return root;
}

BTNode* FACTOR() {
    char a = expr[pos--];
    BTNode *temp;
    if(a >= 'A'&& a <= 'D') temp=makeNode(a);
    else temp=EXPR();
    return temp;
}

BTNode* makeNode(char c) {
    BTNode *temp = (BTNode*)malloc(sizeof(BTNode));
    for (int i = ID_A; i <= OP_OR; i++) {
        if(c == sym[i]) {
            temp -> data = i;
            break;
        }
    }
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}
