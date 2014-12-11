#include <stdio.h>

/*
最大子列和问题

*/

int max_subsqu_sum_1(int a[], int n) {
	int i, j, k;
	int sum;
	int max_sum = 0;
	int count;
	for (i = 0; i < n; ++i) {
		for (j = i; j < n; ++j) {
			sum = 0;
			//迭代 i 到 n  - 1 的下标
			for (k = i; k <= j; k++) {
	// printf("n :%d,i :%d, j :%d,k :%d,\n", n, i, j, k);
				//迭代i 到 j 的下标，并求和
				sum += a[k];
			}
			if (sum > max_sum) {
				max_sum  = sum;
			}
		}
	}
	return max_sum;
}


int max_subsqu_sum_2(int a[], int n) {
	int i, j, k;
	int sum;
	int max_sum = 0;
	int count;
	for (i = 0; i < n; ++i) {
		sum = 0;
		for (j = i; j < n; ++j) {
			//迭代 i 到 n  - 1 的下标
			sum += a[j];
			
			if (sum > max_sum) {
				max_sum  = sum;
			}
	// printf("n :%d,i :%d, j :%d,k :%d,\n", n, i, j, k);
		}
	}
	return max_sum;
}

int max_subsqu_sum_3x(int a[], int i, int j) {
	int sum = 0;
	int max_sum = 0;
	
	if (i ==  j) {
		return a[i];
	} else {
		int mid = (i + j) / 2;
		int sum_left = max_subsqu_sum_4(a, i, mid -1);
		int left_max = 0;
		int left = 0;
		int x;
		for (x = mid - 1; x >= i; x--) {
			left += a[x];
			if (left > left_max) {
				left_max = left;
			}
		}

		int sum_right = max_subsqu_sum_4(a, mid, j);
		int right_max = 0;
		int right = 0;
		for (x = mid; x < j; x++) {
			right += a[x];
			if (right > right_max) {
				right_max = right;
			}
		}

		int both = left_max + right_max;
		if (sum_left > sum_right) {
			if (both > sum_left) {
				return both;
			} else {
				return sum_left;
			}
		} else {
			if (both > sum_right) {
				return both;
			} else {
				return sum_right;
			}
		}
	}

}

int max_subsqu_sum_3(int a[], int n) {
	return max_subsqu_sum_3x(a, 0, n - 1);
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

int main(void) {
	int n = 8;
	int a[] = {4, -3, 5, -2, -1, 2, 6, -2};
	
	printf("result from max_subsqu_sum_1 is : %d\n", max_subsqu_sum_1(a, n));
	printf("result from max_subsqu_sum_2 is : %d\n", max_subsqu_sum_2(a, n));
	printf("result from max_subsqu_sum_3 is : %d\n", max_subsqu_sum_3(a, n));
	printf("result from max_subsqu_sum_4 is : %d\n", max_subsqu_sum_4(a, n));

	return 0;
}