#include <stdio.h>
#include <time.h>

clock_t start, stop

double duration;

int man(void) {
	//code for prepare
	start = clock()
	//code count on time
	stop = clock()

	duration = ((double)(stop - start)) / CLOCKS_PER_SEC;

	printf("%s\n", CLOCKS_PER_SEC);

	return 0;
}
