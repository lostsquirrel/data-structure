/*
 *
 * 数组 实现一元多项式(一维数组) 相加
 * polynomial
 * */
#include <stdio.h>
#include <stdlib.h>

void printPolynomial(int *poly, int me);

void plus(int *p1, int me1, int *p2, int me2);

int main(void) {
	int p0[5 + 1] = {0};
	p0[0] = 1;
	p0[2] = -3;
	p0[5] = 4;
	printPolynomial(p0, 5);

	int p1[12 + 1] = {0};
	p1[12] = 9;
	p1[8] = 15;
	p1[2] = 3;
	printPolynomial(p1, 12);

	int p2[19 + 1] = {0};
	p2[19] = 26;
	p2[8] = -4;
	p2[6] = -13;
	p2[0] = 82;
//	printPolynomial(p2, 19);

	plus(p0, 5, p1, 12);
//	plus(p0, 5, p2, 19);
//	plus(p1, 12, p2, 19);
//	printPolynomial(p01, size);
}

void printPolynomial(int *poly, int me) {
	printf("f(x)=");
	int i = 0;
	int flag = 0;
	for (; i <= me; i++) {
		int x = poly[i];
		if (x > 0) {
			if (x * flag) {
				printf(" + ");
			}
			if (i == 0) {
				printf("%d", x);
			} else {
				printf("%dX^%d", x, i);
			}

			flag = 1;
		} else if (x < 0) {
			printf(" %dX^%d", x, i);
			flag = 1;
		}
//		printf("%d:%d\n", i, x);
	}
	printf("\n");
}

void plus(int *p1, int me1, int *p2, int me2) {
	printf("----------------------\n");
	int *box[] = {p1, p2};
	int max;
	int big;
	int small;
	int min;
	//找出元素多的一个,即 指数大的一个
	if (me1 > me2) {
		max = me1;
		min = me2;
		big = 0;
		small = 1;
	} else {
		max = me2;
		min = me1;
		big = 1;
		small = 0;
	}
	int i;
	//创建一块空间存放结果
	int *xx = (int*)malloc((max+1) * sizeof(int));

	for (i = 0; i <= max; i++) {
		xx[i] = 0;
		//如果较小一个还有值 则相加,
		if (i <= min) {
			xx[i] += box[small][i];
		}
		xx[i] += box[big][i];
//		printf("big %d:%d\n", i, box[big][i]);
//		printf("res %d:%d\n", i, xx[i]);

	}
	printPolynomial(xx, max);
	free(xx);
	/*
	*/
}
