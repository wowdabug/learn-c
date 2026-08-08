#include <stdio.h>

#include "constants.h"

static void print_stuff(void) {
	i32 x = 1;
	printf("%zu\n", sizeof(x));

	printf("pi = %f\n", pi);
}

// this is an example of a multi-file c project
int main(void) {
	print_stuff();

	return 0;
}
