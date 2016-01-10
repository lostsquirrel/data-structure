/*
 * 1_exercise_2.cpp
 *
 *  Created on: Oct 27, 2015
 *      Author: lisong
 */

/*
 *
 *  Created on: Apr 9, 2015
 *      Author: lisong
 */

#include <cstdio>
#include <cstdlib>

typedef struct node {
	int value;
	struct node *next;
	struct node *prev;
} Node;

typedef struct {
	int size;
	Node *head;
	Node *last;
} List;

List list_create();

void print_list(List *p);

int list_size(List *p);

void list_add(List *p, int value);
void list_addx(List *p, int position, int value);
void list_remove(List *p, int value);

int main(void) {
	int x = 10;
	List a = list_create();

	while (x) {
//		scanf("%d", &x);
//		if (x == -1) {
//			break;
//		}
		list_add(&a, x);
//		printf("%d ", x);
		x--;
//		printf("\n");
	}
	print_list(&a);

//	printf("00000\n");
	list_addx(&a, 0, 0);
	print_list(&a);
	list_addx(&a, 11, 11);
	print_list(&a);
	list_addx(&a, 9, 99);
	print_list(&a);
//	int i,j;
//	for (i=list_size(&a) - 1; i>=0; i--) {
//		Node *x = a.head;
//		for (j=0; j<i; j++) {
//			x = x->next;
//		}
//		printf("%d", x->value);
//		if (i) {
//			printf(" ");
//		}
//	}

	return 0;
}

List list_create() {
	List a;
	a.size = 0;
	a.head = NULL;
	a.last = NULL;

	return a;
}

void list_add(List *p, int value) {
	Node *n = (Node*) malloc(sizeof(Node));
	n->value = value;
	n->next = NULL;
	n->prev = NULL;

	if (p->head) {
		p->last->next = n;
		n->prev = p->last;
		p->last = n;
	} else {
		p->head = n;
		p->last = n;
	}
	p->size++;
//	printf("%d %d \n", p->size, value);
}

void list_addx(List *p, int position, int value) {
//	printf("%d %d\n", position, value);
	Node *n = (Node*) malloc(sizeof(Node));
	n->value = value;
	n->next = NULL;

	if (position == 0) {

		n->next = p->head;
		p->head = n;
	} else if (position == p->size) {
		p->last->next = n;
		n->prev = p->last;
		p->last = n;
	} else {

		Node *x = p->head;
		while (position) {
			x = x->next;
			position--;
		}
		x->prev->next = n;
		n->prev = x->prev;
		n->next = x;
		x->prev;
	}

	p->size++;
//	printf("%d %d end\n", position, value);
}

void list_remove(List *p, int value) {
	if (list_size(p)) {
		Node *x;
		Node *y = NULL; // the last one
		for (x = p->head; x;) {
			if (x->value == value) {
				if (x == p->head) {
					p->head = x->next;

				} else if (x == p->last) {
					if (y) {
						y->next = NULL;
					}
				} else {
					if (y) {
						y->next = x->next;
					}
				}
				free(x);
				p->size--;
				break;
			}
			y = x;
			x = x->next;
		}
	}
}

void print_list(List *p) {
	printf("\nsize(%d)\n", list_size(p));
	if (list_size(p)) {
		Node *x = p->head;
//			printf("%p", x);
		do {
			printf("%d ", x->value);
			x = x->next;
		} while (x);
//		printf("%d ", x->value);
	}
	printf("\n");
}

int list_size(List *p) {
	return p->size;
}
