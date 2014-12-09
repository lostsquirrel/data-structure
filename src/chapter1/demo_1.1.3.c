#include <stdio.h>
#include <math.h>
#include <time.h>

#define MAXN 10
/*
1.1.3 关于算法效率 - 例：计算多项式值（10:17）
f(x) = ∑i*x^i  (i=[0,9])
*/

double f1(int n, double a[n], double x) {
	int i;
	double p = a[0] ;
	for (i = 0; i <= n; ++i)
	{
		p += (a[i] * pow(x, i));
	}
	return p;
}

double f2(int n, double a[n], double x) {
	int i;
	double p = a[0] ;
	for ( i = n; i> 0; --i)
	{
		p = a[i - 1] + x*p;
	}
	return p;

}
/*
f 选择执行的函数 1 f1, 2, f2
max_repeat 重复执行函数的次数
*/
void tester(int f, int max_repeat) {

	clock_t start, stop;

	double duration;
	//code for prepare
	int i;
	double a[MAXN];
	for (i=0; i < MAXN; i++) {
		a[i] = i * 1.0;
	}
	start = clock();
	//code count on time
	if (f == 1) {

		for (i=0; i < max_repeat; i++) {
			f1(MAXN -1, a, 1.1);
		}
	} else if (f == 2) {
		for (i=0; i < max_repeat; i++) {
			f2(MAXN -1, a, 1.1);
		}
	}
	stop = clock();

	duration = ((double)(stop - start)) / CLOCKS_PER_SEC;

	printf("durate for f%d is %6.2es\n", f, duration / max_repeat);
}

int main(void) {
	int max_repeat = 1e6;
	tester(1, max_repeat);
	tester(2, max_repeat);
	printf("CLK_TCK=%lu\n", CLOCKS_PER_SEC);

	return 0;
}
