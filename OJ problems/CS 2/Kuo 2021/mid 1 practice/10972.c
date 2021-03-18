#include <stdio.h>
#include <string.h>

typedef struct RR{
    char data;
    struct RR *left, *right;
}BTnode;

char expr[300], sym[10] = "ABCD|&";
int pos;

BTnode* EX();
BTnode* makeNode(char);

BTnode* FA(){
    BTnode *tmp = NULL;
    char c;
    if(pos>=0){
        c = expr[pos--];
        if(c >= 'A' && c <= 'D'){
            tmp = makeNode(c);
        }
        else if(c == ')'){
            tmp = EX();
            if(expr[pos--] != '(') {printf("fuck\n"); return NULL; }
        }
    }
    return tmp;
}

BTnode* EX(){
    BTnode *root, *right;

    if(pos>=0){
        right = FA();

        if(pos>0){
            char c = expr[pos];
            if(c == '|' || c == '&'){
                root = makeNode(c);
                pos--;
                root->right = right;
                root->left = EX();
            }
            else
                root = right;
        }
        else
            root = right;
    }
    return root;
}

BTnode *makeNode(char c){
    BTnode *tmp = (BTnode*)malloc(sizeof(BTnode));
    for(int i=0; i<6; i++) if(c == sym[i]){
        tmp->data = sym[i];
        break;
    }
    tmp->left = tmp->right = NULL;
    return tmp;

}

void print(BTnode *root){
    if(root->left != NULL){
        print(root->left);
    }
    printf("%c", root->data);
    if(root->right != NULL){
        if(root->right->data == '|' || root->right->data == '&') printf("(");
        print(root->right);
        if(root->right->data == '|' || root->right->data == '&') printf(")");
    }
}

int main(){
    scanf("%s", expr);
    pos = strlen(expr)-1;
    BTnode *root = EX();
    print(root);
    return 0;
}
