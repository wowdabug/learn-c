#include <stdio.h>

// this variable has file scope
// we can further modify it with extern and static
int shared = 1;

int main(void) {
	// historically, C required all the variables be defined before any code in the block
	// this is no longer the case in the C99 standard
	{
		int x = 1;
		printf("%d\n", x);
		int y = 2;
		printf("%d\n", y);
	}

	// variables can be hidden
	{
		int x = 1;
		{
			int x = 2;
			printf("%d\n", x);
		}
		printf("%d\n", x);
	}

	return 0;
}
