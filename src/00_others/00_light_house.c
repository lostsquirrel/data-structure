/*
 * 00_light_house.c
 *
 *  Created on: Oct 20, 2015
 *      Author: lisong
 */

#include <stdio.h>

typedef struct {
	long x;
	long y;
} Point;
int x = 1;
int sumB(Point points[], int n) {
	int sum = 0;
	if (n > x) {
		sum += sumx(points[0], points, x, n);
		x++;
	}
	return sum;
}

int sumx(Point p1, Point points[], int start, int n) {
	int sum = 0;
	for (; start < n; start++) {
		Point p2 = points[start];
		if ((p2.x > p1.x && p2.y > p1.y) || (p2.x < p1.x && p2.y < p1.y)) {
			sum++;
		}
	}
	return sum;
}

int sumA(Point points[], int n) {
	int sum = 0;
	int i, j;
	for (i = 0; i < n; i++) {
		Point p1 = points[i];
		for (j = i + 1; j < n; j++) {
			Point p2 = points[j];
			//				double sinx = (p2.y - p1.y)/((p2.x - p1.x) * 1.0);
			if ((p2.x > p1.x && p2.y > p1.y) || (p2.x < p1.x && p2.y < p1.y)) {
				sum++;
			}
		}
	}
	return sum;
}

int main(void) {

	int i, n, sum = 0;
	long a, b;
	scanf("%d", &n);

	Point points[n];
	for (i = 0; i < n; i++) {
		scanf("%ld %ld", &a, &b);
		Point pointx = { a, b };
		points[i] = pointx;
	}

//	sum = sumA(points, n);
	sum = sumB(points, n);
	printf("%d", sum);

	return 0;
}
