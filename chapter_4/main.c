#include <stdio.h>

void print_hello_world(void);

int main() {
	print_hello_world();

	return 0;
}

// the void keyword indicates that the function accepts no arguments
void print_hello_world(void) {
	printf("Hello, world!\n");
}
