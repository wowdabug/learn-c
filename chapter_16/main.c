#include <stdio.h>

#include "pi.h"

// static variables in file scope aren't visible outside the file

// const can be used in function parameter lists
int increment(const int x) {
	return x + 1;
}

// restrict promises that a piece of memory will only be accessed by one pointer
void swap(int *a, int *b) {
	int x;

	x = *a;
	*a = *b;
	*b = x;
}

// static variables in block scope persist between calls
void counter(void) {
	static int count = 0;
	++count;
	printf("This function has been called %d time%s\n", count, (count == 1 ? "" : "s"));
}

int main(void) {
	// const is the most common type qualifier
	const int x = 1;
	
	int y = 1;

	// const pointers
	const int* p1 = &y; // can't modify x
	int *const p2 = &y; // can't modify p2

	int a = 1;
	int b = 2;
	swap(&a, &b);

	// volatile tells the compiler that a value could unexpectedly change
	// it forces the compiler to always re-fetch the value from memory
	volatile int v = 1;

	// auto means automatic storage duration; this is the default
	auto int z = 1;

	// counter prints something different each time by utilizing static variables
	for (int i = 0; i < 4; ++i) {
		counter();
	}

	// extern lets us refer to objects in other source files
	printf("The value of pi is %f\n", pi);

	// register suggests that the variable should be stored in a CPU register
	// they are mostly obsolete now with modern compilers
	register int r = 1;

	// you can't take the address of a register
	// int *p = &z;

	return 0;
}
