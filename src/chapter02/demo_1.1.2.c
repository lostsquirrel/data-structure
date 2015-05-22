/*
 *
 数组 实现一元多项式(二维数组) 相加
 * created on 2015-05-17
 * */
#include <stdio.h>
#include <stdlib.h>

void print(int poly[][2], int size);
void plus(int po[][2], int s_po, int pl[][2], int s_pl);
int main(void) {
	int p1[][2] = { 9, 12, 15, 8, 3, 2 };b
//	print(p1, 3);

	int p2[][2] = { 26, 19, -4, 8, -13, 6, 82, 0 };
	plus(p1, 3, p2, 8);
	int p3[][2] = { 26, 19, 9, 12, 11, 8, -13, 6, 3, 2, 82, 0 };
	plus(p1, 3, p3, 12);
}

void print(int poly[][2], int size) {
	int i;
	for (i = 0; i < size; i++) {
		if (i != 0) {
			printf(" ");
			if (poly[i][0] > 0) {
				printf("+");
			}
		}
		printf("%dX^%d", poly[i][0], poly[i][1]);
	}
	printf("\n");
}
void plus(int po[][2], int s_po, int pl[][2], int s_pl) {
	int **data[2];
	int **res = (int**) malloc((s_po + s_pl) * sizeof(int));
	int ss[2];
	int size = 0;
	if (s_po > s_pl) {
		data[0] = po;
		data[1] = pl;
		ss[0] = s_po;
		ss[1] = s_pl;
	} else {
		data[0] = pl;
		data[1] = po;
		ss[0] = s_pl;
		ss[1] = s_po;
	}
	int i;
	for (i = 0; i < ss[0]; i++) {
		int *a = data[0][i];
		int *b = {0};
		if (i < ss[1]) {
			b = data[1][i];
		}
		if (a[1] == b[1]) {
			res[size][0] = a[0] + b[0];
			res[size][1] = a[1];
			size++;
		} else if (a[1] < b[1]) {
			res[size] = b;
			size++;
			res[size] = a;
			size++;
		} else {
			res[size] = a;
			size++;
			res[size] = b;
			size++;
		}
	}
	print(res, size);
	free(res);

}
