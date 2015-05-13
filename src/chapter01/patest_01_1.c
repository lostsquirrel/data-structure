#include <stdio.h>
#include <math.h>

/*给定K个整数组成的序列{ N1, N2, ..., NK }，“连续子列”被定义为{ Ni, Ni+1, ..., Nj }，
 * 其中 1 <= i <= j <= K。“最大子列和”则被定义为所有连续子列元素的和中最大者。
 * 例如给定序列{ -2, 11, -4, 13, -5, -2 }，其连续子列{ 11, -4, 13 }有最大的和20。
 * 现要求你编写程序，计算给定整数序列的最大子列和。

输入格式：

输入第1行给出正整数 K (<= 100000)；第2行给出K个整数，其间以空格分隔。

输出格式：

在一行中输出最大子列和。如果序列中所有整数皆为负数，则输出0。

输入样例：
6
-2 11 -4 13 -5 -2
输出样例：
20

passed
*/

int max_subsqu_sum_4(int a[], int n);

int main( ) {
	// 准备数据 n, res[]
	int i, n, a[100000];

	scanf("%d", &n);
	for(i=0; i<n; i++)   {
		scanf("%d", &a[i]);
	}
	printf("%d", max_subsqu_sum_4(a, n));

	return 0;
}

int max_subsqu_sum_4(int a[], int n) {

	int i;
	int sum = 0;
	int max_sum = 0;
	for (i = 0; i < n; ++i) {
		sum += a[i];
	
		if (sum > max_sum) {
			max_sum  = sum;
		} else if (sum < 0) {
			sum = 0;
		}
	}

	return max_sum;
}
