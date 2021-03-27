#include <stdio.h>
#include <stdlib.h>
#include "13132.h"

void PrintList();

int main() {
	scanf("%d %d %d", &n, &k, &q);
	for (int i = 1; i <= n; ++ i) {
		int x;
		scanf("%d", &x);
		push(x);
	}

	while (q--) {
		char op[20];
		scanf("%s", op);
		if (op[1] == 'u') {
			int x;
			scanf("%d", &x);
			push(x);
		}
		else if (op[1] == 'o') {
			pop();
		}
		else {
			scanf(" %s", op);
			programming_tanoshi();
		}
	}

	KuoYangTeTe();
	PrintList();
}

void PrintList() {
	Node* res = head;
	while (res) {
		printf("%d ", res->val);
		res = res->next;
	}
	puts("");
}

int NodeCount = 0;
Node *mid = NULL;
Node *last = NULL;
Node *pt = NULL;

Node* createNode(int val) {
	Node* new = (Node*)malloc(sizeof(Node));
	new -> next = new -> prev = NULL;
	new -> val = val;
	new -> tag = NodeCount;
	NodeCount++;
	return new;
}

void push(int x) {

	Node *new = createNode(x);

	if (head == NULL) {
		head = new;
		mid = head;
		last = head;
	} else {
		Node *tmp = head;

		if (NodeCount % 2 == 1) {
			mid = mid -> next;
		}

		last -> next = new;
		new -> prev = last;
		last = last -> next;
	}
}

void pop() {
	if (NodeCount > 0) {

		if (NodeCount < 3) {
			mid = head -> next;
			head = head -> next;
			NodeCount--;

			if (NodeCount == 0) last = NULL;

			return;
		}

		Node *pre = mid -> prev;
		Node *nex = mid -> next;
		pre -> next = nex;
		nex -> prev = pre;

		if (NodeCount % 2 == 0) {
			mid = nex;
		} else {
			mid = pre;
		}

		NodeCount--;
	}
}

void programming_tanoshi() {
	pt = last;
}

void KuoYangTeTe() {
	if (pt != NULL) {
		while(pt != NULL) {
			pt -> val %= k;
			pt = pt -> prev;
		}
	}
}