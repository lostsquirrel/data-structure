#include <stdio.h>


int max_subsqu_sum_2(int a[], int n, int * x, int *y) {
	int i, j, k;
	int sum;
	int max_sum = 0;
	int count = n;
	int tag = 0;
	int tag2 = 0;
	for (i = 0; i < n; ++i) {
		sum = 0;
		for (j = i; j < n; ++j) {
			//迭代 i 到 n  - 1 的下标
			sum += a[j];
			
			if (sum > max_sum) {
				max_sum  = sum;
				if (j - i < count) {
					count = j - i;
					*x =  i;
					*y = j;
				}
				tag  = 1;
			}

	// printf("n :%d,i :%d, j :%d,k :%d,\n", n, i, j, k);
		}
	}
	if (tag) {
		for (i = 0; i < n; ++i) {
			if (!a[i]) {
				*x = i;
				*y = i;
				break;
				tag2 = 1;
			}
		} 
		if(!tag2) {
			*x = 0;
			*y = n - 1;
		}
		
	}
	return max_sum;
}

int main( ) {
	
	// 准备数据 n, res[]
	int i, n, a[10000];  
	int x, y, s;
	x = y = 0;
	scanf("%d", &n);  
	for(i=0; i<n; i++)   {  
		scanf("%d", &a[i]);  
	} 
	s = max_subsqu_sum_2(a, n, &x, &y);
	printf("%d %d %d", s, x, y);
	return 0;
}