/*
1.1.3 关于算法效率 - 例：计算多项式值（10:17）
f(x) = ∑i*x^i  (i=[0,9])
*/
#include <stdio.h>
#include <math.h>
#include <time.h>

#define MAXN 10


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
	double p = a[n] ;
	for ( i = n; i> 0; --i)
	{
		p = a[i - 1] + x*p;
	}
	return p;

}


//第1讲讨论：再试一个多项式
double f3(int n, double a[n], double x) {
	int i;
	double p = a[0] ;
	for (i = 0; i <= n; ++i)
	{
		p += (pow(x, i) / a[i]  );
	}
	return p;
}

double f4(int n, double a[n], double x) {
	int i;
	double p = 1 / a[n] ;
	for ( i = n; i> 0; --i)
	{
		p = 1/a[i - 1] + x*p;
	}
	return p;

}

/*
f 选择执行的函数 1 f1; 2, f2; 3, f3; 4, f4
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
	//code count on time
	if (f == 1) {
		start = clock();

		for (i=0; i < max_repeat; i++) {
			f1(MAXN -1, a, 1.1);
		}
		stop = clock();

	} else if (f == 2) {
		start = clock();
		for (i=0; i < max_repeat; i++) {
			f2(MAXN -1, a, 1.1);
		}
		stop = clock();

	} else if (f == 3) {
		start = clock();
		for (i=0; i < max_repeat; i++) {
			f3(MAXN -1, a, 1.1);
		}
		stop = clock();

	} else if (f == 4) {
		start = clock();
		for (i=0; i < max_repeat; i++) {
			f4(MAXN -1, a, 1.1);
		}
		stop = clock();

	}
	
	duration = ((double)(stop - start)) / CLOCKS_PER_SEC;

	printf("durate for f%d is %6.2es\n", f, duration / max_repeat);
}

int main(void) {
	int max_repeat = 1e6;
	tester(1, max_repeat);
	tester(2, max_repeat);
	tester(3, max_repeat);
	tester(4, max_repeat);
	printf("CLK_TCK=%lu\n", CLOCKS_PER_SEC);

	return 0;
}
