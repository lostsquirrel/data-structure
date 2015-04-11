#include <stdio.h>
#include <time.h>

clock_t start, stop;

int main(void) {
	//code for prepare
	start = clock();
	//code count on time
	printf("CLOCKS_PER_SEC = %ld\n", CLOCKS_PER_SEC);

	stop = clock();

	double duration = ((double)(stop - start)) / CLOCKS_PER_SEC;
	printf("itme: %f\n", duration);

	return 0;
}
