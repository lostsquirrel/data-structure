/*
 *
 * 数组 实现线性表
 *
 * */

#include <stdio.h>
#include <stdlib.h>

#ifndef MAXSIZE
#define MAXSIZE 1024
#endif

typedef struct {
	int data[MAXSIZE];
	int last;
} List;

List * makeEmptyList() {
	List *ptrl;
	ptrl = (List *)malloc(sizeof(List));
	ptrl->last = -1;
	return ptrl;
}

int find(int x, List *ptrl) {
	int a = 0;
	while(a <= ptrl->last) {
		if (x == (ptrl->data)[a]) {
			return a;
		}
		a++;
	}
	return -1;
}

int * findKth(int k, List *ptrl) {
	int *res = NULL;
	if (k < ptrl->last && k >= 0) {
		res = &(ptrl->data[k]);
	}
	return res;
}

int findElement(int x, List *ptrl) {
	int i = 0;
	int res = -1;
	while(i <= ptrl->last) {
		if (x == (ptrl->data)[i]) {
			res = i;
			break;
		}
	}

	return res;
}

int insert(int i, int x, List *ptrl) {
	// 数组没存满, index 不小于零, 插入在数据尾部
	// 1 表示插入成功 0 表示插入失败
	int res = 0;
	if (ptrl->last != MAXSIZE - 1 && i >= 0 && i <= ptrl->last + 1) {
		ptrl->last += 1;
		int a = ptrl->last;
		//从i开始 所有元素向后移一个
		while(a > i) {
			ptrl->data[a] = ptrl->data[a - 1];
			a--;
		}
		ptrl->data[i] = x;
		res = 1;
	}
	return res;
}

int del(int kth, List *ptrl) {
	int res = 0;
	if (kth < ptrl->last && kth >= 0) {
		while(kth < ptrl->last) {
			ptrl->data[kth] = ptrl->data[kth + 1];
			kth++;
		}
		res = 1;
	}

	return res;
}

int delElement(int x, List *ptrl) {
	int a = 0;
//	是存在这个元素
	int tag = 0;
	while(a <= ptrl->last) {
		if (x == (ptrl->data)[a]) {
			tag = 1;
		}
		// 如果找到 元素x 的索引为 a 那么从a开始依次往前移一个
		if (tag) {
			ptrl->data[a] = ptrl->data[a  + 1];
		}
		a++;
	}
	ptrl->last -= tag;

	return tag;
}

int length(List *ptrl) {
	int res = 0;
	if (ptrl->last >= 0) {
		res = ptrl->last + 1;
	}

	return res;
}

int printList(List *ptrl) {
	if (ptrl->last >= 0) {

		int a = 0;
		for(; a <= ptrl->last; a++) {
			printf("%d ", ptrl->data[a]);
		}
		printf("length:%d\n", length(ptrl));
	}
}

void printIntPointer(int *x) {
	if (x) {
		printf("%d", *x);
	} else {
		printf("x is null");
	}
}
int main(int argc, char const *argv[])
{
	List * list = makeEmptyList();
	int data[11] = {1, 8, 5, 8, 3, 3, 7, 3, 9, 8, 9};
	int i;
	for(i = 0; i < 11; i++) {
		insert(i, data[i], list);
	}
	printList(list);
	printf("-------------------insert-------------");
	int tag = -1;
	//插入列表头 -1
	tag = insert(-1, -1, list);
	printf("tag for insert index -1 to -9: %d\n", tag);
	printList(list);

	//插入列表头
	tag = -1;
	tag = insert(0, -9, list);
	printf("tag for insert index 0 to -9: %d\n", tag);
	printList(list);

	//插入列表尾部
	tag = -1;
	tag = insert(12, -9, list);
	printf("tag for insert index 12 to -9: %d\n", tag);
	printList(list);

	//插入列表尾部 +1
	tag = -1;
	tag = insert(14, 14, list);
	printf("tag for insert index 12 to -9: %d\n", tag);
	printList(list);

	printf("-------------------find-------------");

	printf("\nvalue of index -1:");
	printIntPointer(findKth(-1, list));
	printf("\nvalue of index 3:");
	printIntPointer(findKth(3, list));
	printf("\nvalue of index 14:");
	printIntPointer(findKth(14, list));
	printf("\n");
	return 0;
}
