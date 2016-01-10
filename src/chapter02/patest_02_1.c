/*
 *
 *  Created on: Apr 20, 2015
 *      Author: lisong
 *
 *     实现线性表,数组,链表
 *     设计函数求一元多项式的导数。（注：x^n（n为整数）的一阶导数为n*x^(n-1)。）

 输入格式：以指数递降方式输入多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。

 输出格式：以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。
 注意“零多项式”的指数和系数都是0，但是表示为“0 0”。

 输入样例：
 3 4 -5 2 6 1 -2 0
 输出样例：
 12 3 -10 1 6 0
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node {
	int base;
	int exp;
	struct node *next;
} Node;

typedef struct {
	Node *head;
	int last;
} List;

List * makeEmpty();
int add(int base, int exp, List *list);
void printList(const List *list);
void printNode(const Node *node);

int main(void) {
	int a, b, i;
	List *list = makeEmpty();
	char all[6] = {'a'};
//	i = scanf("%s", all);
//	printf("%s", all);
	char c;
	int pos;
	int temp;
	i = 0;
	do {
		c = getchar();
		printf("%c\n", c);
		if (c == ' ' && i > 0) {
			pos = 0;
			temp = 0;
			while (i > 0) {
				if (all[i] == '-') {
					temp *= -1;
				} else {
					temp += pow(10, pos);
				}
				i--;
			}
		} else {
			i++;
			all[i] = c;
		}
	}
	while (c != '\n' && c != EOF);
//	{
//		if (c == ' ' && i > 1) {
//			printf("%d", i);
//			while (i > 0) {
//				putchar(all[i]);
//				all[i] = 'a';
//				i--;
//			}
//			i = 1;
//		} else {
//			all[i] = c;
//			c = getchar();
//			i++;
//		}
//	}

//	printList(list);
}

List * makeEmpty() {
	List *list = (List*) malloc(sizeof(List));
	list->head = NULL;
	list->last = -1;

	return list;
}

int add(int base, int exp, List *list) {
	if (exp < 0) {
		return 0;
	}
	if (!list) {
		list = makeEmpty();
	}
	Node *node = (Node*) malloc(sizeof(Node));
	node->base = base;
	node->exp = exp;
	node->next = NULL;
	Node *x = list->head;
	if (x) {
		while (x->next) {
			x = x->next;
		}
		x->next = node;
	} else {
		list->head = node;
	}

	return 1;
}

void printList(const List *list) {
	Node *x = list->head;
	if (x) {
		while (x->next) {
			printNode(x);
			printf(" ");
			x = x->next;
		}

		printNode(x);
		printf("\n");
	} else {
//		printf("list is empty");
	}
}

void printNode(const Node *node) {
	printf("%d %d", node->base, node->exp);
}
