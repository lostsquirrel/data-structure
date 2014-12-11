#include <stdio.h>

#include <stdio.h>
int main( ) {
	int c;
	int line = 0;
	// printf( "Enter a value :");
	while((c = getchar( )) != EOF) {
		int n = 0;
		if (c == '\n') {
			line++;
		} else if (line == 0) {
			
		}
	}
	

	printf( "You entered: ");
	putchar( c );
	printf("\n");
	return 0;
}