#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int get_random_int() {
//	srand(time());
	int r = rand();
	return r;
}

int * get_random_int_array(int size, int max) {
	int *a = (int *)malloc(sizeof(int) * size);
	int i;
	for (i = 0; i < size; i++) {
		a[i] = get_random_int() % max;
	}
	return a;
}

void print_array(int *a, int size) {
	while(size) {
		printf("%d ", *a);
		a++;
		size--;
	}
	printf("\n");
}

int main(void) {
	printf("%d, %d, %d\n", get_random_int(), get_random_int(), get_random_int());
	int size = 12;
	int *a;
	a = get_random_int_array(size, 100);
	print_array(a, size);
	free(a);
}
