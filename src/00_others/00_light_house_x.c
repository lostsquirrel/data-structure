/*
 * 00_light_house_x.c
 *
 *  Created on: Oct 21, 2015
 *      Author: lisong
 */

#include <stdio.h>

#define L 1000005

int y[L], le[L], ri[L];
long ans = 0;

void qsort(int a[], int b[], int l, int r) {
	int i, j, x, t;
	i = l;
	j = r;
	x = a[i + ((j - i) >> 1)];
	do {
		while (x > a[i])
			i++;
		while (x < a[j])
			j--;
		if (i <= j) {
			t = a[i];
			a[i] = a[j];
			a[j] = t;
			t = b[i];
			b[i] = b[j];
			b[j] = t;
			i++;
			j--;
		}
	} while (i <= j);
	if (i < r)
		qsort(a, b, i, r);
	if (j > l)
		qsort(a, b, l, j);
}

void Merge(int l, int mi, int r) {
	int i, j, k, n1 = mi - l + 1, n2 = r - mi;
	const int MAX = 100000005;

	for (i = 1; i <= n1; i++)
		le[i] = y[l + i - 1];
	for (i = 1; i <= n2; i++)
		ri[i] = y[mi + i];

	le[n1 + 1] = MAX;
	ri[n2 + 1] = MAX;

	i = 1;
	j = 1;
	for (k = l; k <= r; k++) {
		if (le[i] > ri[j])
			y[k] = ri[j++];
		else {
			y[k] = le[i++];
		ans += long(n2) - j + 1;
	}
}

}

void Merge_Sort(int l, int r) {
int mi;
if (l == r)
	return;
mi = l + ((r - l) >> 1);
Merge_Sort(l, mi);
Merge_Sort(mi + 1, r);
Merge(l, mi, r);
}

int main(void) {
int n, x[L];
scanf("%d", &n);
for (int i = 1; i <= n; i++) {
	scanf("%d %d\n", &x[i], &y[i]);
}

qsort(x, y, 1, n);

Merge_Sort(1, n);

printf("%ld\n", ans);

return 0;
}
