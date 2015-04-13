#include <stdio.h>

/*
 1.1.2 关于空间使用 - 例：PrintN函数实现（04:08）
 输入一个正整数N，打印1到这个数之间的所有整数

 */

void printN(int n) {
	int i = 1;
	while (i <= n) {
		printf("%d\n", i);
		i++;
	}
}

void printM(int m) {
	if (m) {
		printM(m - 1);
		printf("%d\n", m);
	}
}

int main(void) {
	int x;
	scanf("%d", &x);
	printf("input number: %d\n", x);
	//printN输入1 000 000 跑了好一会
	printN(x);

	//===============递归实现
	//printM输入1 000 000 能跑（8G RAM）, 10 000 000 就不行了 Segmentation fault (core dumped)
//	printM(x);

	return 0;
}
