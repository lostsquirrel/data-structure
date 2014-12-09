#include <stdio.h>
#include <time.h>

clock_t start, stop

double duration;

int man(void) {
	//code for prepare
	start = clock()
	//code count on time
	stop = clock()

	duration = ((double)(stop - start)) / CLK_TCK;

	printf("%s\n", CLK_TCK);

	return 0;
}
