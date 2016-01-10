/*
 * 1_exercise_1.cpp
 *
 *  Created on: Oct 24, 2015
 *      Author: lisong
 */

#include <cstdio>
#include <cstdlib>

int query(int elements[], int element, int start, int end, int *tag) {
	/*
	 int sum;
	 //	printf("%d\t%d\n", start, end);
	 if (start > end) {
	 return -1;
	 }

	 int mid = (end - start) >> 1;
	 printf("%d\n", mid);
	 if (elements[mid] == element) {
	 return mid;
	 } else if (elements[mid] > element) {
	 end = mid - 1;
	 } else if (elements[mid] < element) {
	 start = mid + 1;
	 }
	 */
	while (start <= end) {
		int mid = (start + end) / 2;
//		printf("%d\n", mid);
		if (elements[mid] == element) {
//			printf("%d %d %d \n",elements[mid] == element , (elements[mid] > element && elements[mid - 1] < element) , (elements[mid] < element && elements[mid + 1] > element));
//			printf("%d, %d %d %d \n",elements[mid + 1], elements[mid], element, elements[mid - 1]);
			*tag = 1;
			return mid;
		} else if (elements[mid] > element && elements[mid - 1] < element) {
			*tag = 0;
			return mid;
		} else if (elements[mid] < element && elements[mid + 1] > element) {
			*tag = 0;
			return mid + 1;
		} else if (elements[mid] > element) {
			end = mid - 1;
		} else if (elements[mid] < element) {
			start = mid + 1;
		}

	}
//the array does not contain the target
	return -1;
}

int query0(int elements[], int n, int element) {
	int i;
//	printf("%d", element);
	if (element < elements[0])
		return -1;
	else if (element > elements[n - 1])
		return n;
	for (i = 0; i < n; i++) {
//		printf("%d", i);
		if (elements[i] >= element) {
			return i;
		}
	}

	return n;
}
int query1(int elements[], int n, int start, int end) {
	int i, sum = 0;
//	printf("%d", element);
	for (i = 0; i < n; i++) {
//		printf("%d", i);
		if (elements[i] >= start && elements[i] <= end) {
			sum++;
		}
	}

	return sum;
}
int queryx(int elements[], int n, int start, int *tag) {
	return query(elements, start, 0, n, tag);
}

int query2(int elements[], int n, int start, int end) {
// sorted
	int tag;
	if (end < elements[0])
		return 0;
	if (start > elements[n - 1])
		return 0;
	if (start == end) {
		return queryx(elements, n, start, &tag) >= 0;
	}
	if (start <= elements[0] && end >= elements[n - 1]) {
		return n;
	} else if (start < elements[0] && end <= elements[n - 1]) {
		// 左出,右不出
		return queryx(elements, n, end, &tag) + tag;
	} else if (start >= elements[0] && end > elements[n - 1]) {
		// 左不出, 右出
		return n - queryx(elements, n, start, &tag);
	} else {
		// 左不出, 右不出
		return queryx(elements, n, end, &tag) + tag
				- queryx(elements, n, start, &tag);
	}

}
int cmpfunc(const void * a, const void * b) {
	return (*(int*) a - *(int*) b);
}

int main(void) {
	int n, m; // n 个元素 , m 次查询

	int i = 0;
	int x, y;
	scanf("%d %d", &n, &m);
	int elements[n];
	int sums[m];
	for (i = 0; i < n; i++) {
		scanf("%d", &elements[i]);
	}
	qsort(elements, n, sizeof(int), cmpfunc);
	for (i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
//		printf("%d %d\n", query0(elements, n, y) , query0(elements, n, x));
		sums[i] = query2(elements, n, x, y);
//		sums[i] = query1(elements, n, x, y);
	}

	for (i = 0; i < m; i++) {
		printf("%d\n", sums[i]);
	}

	/*

	 //int a[15] = { 3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48 };
	 int a[5] = { 1, 3, 7, 9, 11 };
	 int n = 5;
	 //qsort(a, n, sizeof(int), cmpfunc);
	 //	printf("-3\t%d\n", query(a, -3, 0, 15));
	 //	printf("3\t%d\n", query(a, 3, 0, n));
	 //	printf("9\t%d\n", query(a, 9, 0, n));
	 printf("2\t%d\n", query(a, 2, 0, n));
	 //printf("10\t%d\n", query(a, 10, 0, n));
	 */

	return 0;
}
