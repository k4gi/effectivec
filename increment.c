#include <stdio.h>

void increment(void) {
	static int counter = 0;
	counter ++;
	printf("%d ", counter);
}

int main(void) {
	for( int i=0; i<5; i++ ) {
		increment();
	}
	printf("\n");
	return 0;
}
