#include <stdio.h>

unsigned int *retrieve(void) {
	static unsigned int counter = 0;
	return &counter;
}

void increment(void) {
	unsigned int *counter = retrieve();
	*counter ++;
}

int main(void) {
	for( int i=0;i<5;i++ ) {
		increment();
		printf("%d ", *retrieve());
	}
	return 0;
}
