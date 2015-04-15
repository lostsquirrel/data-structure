#include <stdio.h>
/*

01-复杂度2. Maximum Subsequence Sum (25)

时间限制
400 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
CHEN, Yue
Given a sequence of K integers { N1, N2, ..., NK }.
A continuous subsequence is defined to be { Ni, Ni+1, ..., Nj }
where 1 <= i <= j <= K. The Maximum Subsequence is the continuous
subsequence which has the largest sum of its elements.
For example, given sequence { -2, 11, -4, 13, -5, -2 },
its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.

Now you are supposed to find the largest sum, together with
the first and the last numbers of the maximum subsequence.

Input Specification:

Each input file contains one test case. Each case occupies two lines.
The first line contains a positive integer K (<= 10000).
The second line contains K numbers, separated by a space.

Output Specification:

For each test case, output in one line the largest sum,
together with the first and the last numbers of the maximum subsequence.
The numbers must be separated by one space,
but there must be no extra space at the end of a line.
最后一个数字后面没有空格
In case that the maximum subsequence is not unique,
如果最大子列不唯一
output the one with the smallest indices i and j (as shown by the sample case).
取脚标小的子列
 If all the K numbers are negative, then its maximum sum is defined to be 0,
  and you are supposed to output the first and the last numbers of the whole sequence.
如果所有数字都为负数,最大子列和为零,返回整个序列的第一个和最后一个元素
Sample Input:
10
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:
10 1 4
*/


int max_subsqu_sum_2(int a[], int n, int * x, int *y);
int max_subsqu_sum_4(int a[], int n, int * x, int *y);
int main( ) {

	// 准备数据 n, res[]
	int i, n;
	int x, y, s;
	x = y = 0;
	scanf("%d", &n);
	int a[n];
	for(i=0; i<n; i++)   {
		scanf("%d", &a[i]);
	}
	s = max_subsqu_sum_2(a, n, &x, &y);

//	printf("%d %d\n", x, y);
	printf("%d %d %d\n", s, a[x], a[y]);
	return 0;
}

int max_subsqu_sum_4(int a[], int n, int * x, int *y) {
	int i;
	int sum = 0;
	int max_sum = 0;
	*x = 0;
	*y = 0;
	for (i = 0; i < n; ++i) {
		sum += a[i];

		if (sum > max_sum) {
			max_sum  = sum;
			*y = i;
		} else if (sum < 0) {
			sum = 0;
			*x = i;
			*y = i;
		}
	}
	return max_sum;
}

int max_subsqu_sum_2(int a[], int n, int * x, int *y) {
	int i, j;
	int sum = 0;
	int max_sum = 0;
	/*负数标记 (只有负数)*/
	int nagetive_tag = 1;
	/*零标记 (只有负数和零)*/
	int zero_tag = 1;
	int zero_index = -1;
	for (i = 0; i < n; ++i) {
		sum = 0;
		for (j = i; j < n; ++j) {
			//迭代 i 到 n  - 1 的下标
			sum += a[j];
			
			if (sum > max_sum) {
				max_sum  = sum;
				*x =  i;
				*y = j;
			}
		}
		if (nagetive_tag && a[i] >= 0) {
			nagetive_tag = 0;
		}

		if (zero_tag && a[i] > 0) {
			zero_tag = 0;
		}
		if (zero_index == -1 && a[i] == 0) {
			zero_index = i;
		}
	}
	/*//全部为负数*/
	if (nagetive_tag) {
		*x = 0;
		*y = n - 1;
	} else if (zero_tag) {
	/*负数和零*/
		*x = zero_index;
		*y = zero_index;
	}

	return max_sum;
}
