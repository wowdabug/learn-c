#include <stdio.h>

void increment(int *x) {
	*x += 1;
}

int main() {
	int x = 1;
	printf("the value of x is %d\n", x);
	printf("the address of x is %p\n", (void*)&x);

	int y = 2;
	int *p = &y;
	printf("%d\n", *p);

	increment(&y);

	// you can assign pointers to NULL (or nullptr in c23)
	// NULL is just a macro for (void*)0
	[[maybe_unused]] int *null_ptr = NULL;
	[[maybe_unused]] int *nullptr_ptr = nullptr;

	return 0;
}
