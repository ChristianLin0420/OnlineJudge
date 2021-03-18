#include <stdio.h>
#include <stdlib.h>
#include "11339.h"

void do_I(Node **head,size_t pos,unsigned short val){
    int i;
    Node *nod, *tem;
    
    nod = (Node*)malloc(sizeof(Node));
    nod->val = val;
    if((*head) == 0){
        *head = nod;
        (*head)->next = 0;
        (*head)->prev = 0;
        return;
    }
    
    if(pos == 0){
        nod->next = *head;
        nod->prev = 0;
        (*head)->prev = nod;
        *head = nod;
        return;
    }
    
    tem = *head;
    
    for(i = 0; i < pos; i++){
        if((*head)->next == 0 && i+1 <= pos){
            (*head)->next = nod;;
            nod->next = 0;
            nod->prev = (*head);
            *head = tem;
            return;
        }
        (*head) = (*head)->next;
    }
    
    (*head)->prev->next = nod;
    nod->prev = (*head)->prev;
    nod->next = *head;
    (*head)->prev = nod;
    *head = tem;
    
    return;
}

void do_E(Node **head,size_t begin_pos,size_t end_pos){
    int i = 0;
    Node *cur, *del, *tem;
    
    tem = *head;
    for(i = 0; i < begin_pos; i++){
        if(*head == 0){
            *head = tem;
            return;
        }
        (*head) = (*head)->next;
    }
    if(*head == 0){
        *head = tem;
        return;
    }
    cur = (*head)->prev;
    for(i = 0; i < end_pos-begin_pos; i++){
        if(*head == 0){
            if(cur == 0){
                *head = 0;
            }
            else{
                cur->next = 0;
                *head = tem;
            }
            return;
        }
        del = (*head);
        *head = (*head)->next;
        free(del);
    }
    if(begin_pos == 0){
        (*head)->prev = 0;
    }
    else{
        cur->next = *head;
        if(*head != 0){
            (*head)->prev = cur;
        }
        *head = tem;
    }
    
    return;
}

void do_P(Node  *head,size_t pos){
    if(head == 0){
        return;
    }
    while(pos--){
        if(head->next == 0){
            break;
        }
        head = head->next;
    }
    printf("%d ", head->val);
    
    return;
}

void do_R(Node **head,unsigned short val){
    Node *cur, *tem;
    
    if(*head == 0){
        return;
    }
    while(*head != 0){
        if((*head)->val != val){
            break;
        }
        if((*head)->next == 0){
            *head = 0;
            return;
        }
        cur = (*head);
        *head = (*head)->next;
        (*head)->prev = 0;
        free(cur);
    }
    tem = *head;
    while(*head != 0){
        if((*head)->val == val){
            cur = (*head)->prev;
            (*head)->prev->next = (*head)->next;
            if((*head)->next != 0){
                (*head)->next->prev = (*head)->prev;
            }
            free(*head);
            *head = cur;
        }
        *head = (*head)->next;
    }
    *head = tem;
    
    return;
}

void do_S(Node  *head){
    while(head != 0){
        printf("%d ", head->val);
        head = head->next;
    }
    
    return;
}


int main(void) {
	Node *head=NULL;
	size_t N;
	scanf("%zu", &N);

	while(N--) {
		char op;
		unsigned short val;
		size_t pos,begin_pos,end_pos;
		scanf(" %c",&op);
		switch(op)
		{
		case 'I':
			scanf("%zu %hu",&pos,&val);
			do_I(&head,pos,val);
			break;
		case 'E':
			scanf("%zu %zu",&begin_pos,&end_pos);
			do_E(&head,begin_pos,end_pos);
			break;
		case 'P':
			scanf("%zu",&pos);
			do_P(head,pos);
			break;
		case 'R':
			scanf("%hu",&val);
			do_R(&head,val);
			break;
		case 'S':
			do_S(head);
			break;
		}
	}
    
    return 0;
}
