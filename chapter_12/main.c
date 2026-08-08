#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// commented out because windows sucks
/*
void *aligned_realloc(void *ptr, size_t old_size, size_t alignment, size_t size) {
    char *new_ptr = aligned_alloc(alignment, size);
    if (new_ptr == NULL) {
		return NULL;
	}
    size_t copy_size = old_size < size ? old_size: size;
    if (ptr != NULL) {
		memcpy(new_ptr, ptr, copy_size);
	}
    free(ptr);
    return new_ptr;
}
*/

int main(void) {
	// malloc() accepts a number of bytes to allocate and returns a void pointer
	int *p_1 = malloc(sizeof(int));

	// you can check if the memory failed to be allocated
	if (p_1 == NULL) {
		fprintf(stderr, "Error allocating\n");
		return 1;
	}

	*p_1 = 12;
	printf("%d\n", *p_1);
	free(p_1);

	// calloc() makes it easier to allocate for arrays
	// it also clears the memory to zero
	int *p_2 = calloc(10, sizeof(int));
	for (int i = 0; i < 10; ++i) {
		p_2[i] = i * 10;
	}
	for (int i = 0; i < 10; ++i) {
		printf("%d ", p_2[i]);
	}
	free(p_2);
	putchar('\n');

	int *p_3 = malloc(10 * sizeof(int));
	
	// realloc() dynamically reallocates the given area of memory
	int *p_4 = realloc(p_3, 20 * sizeof(int));
	if (p_4 == NULL) {
		fprintf(stderr, "Error reallocating\n");
		return 1;
	}
	p_3 = p_4;
	for (int i = 0; i < 20; ++i) {
		p_3[i] = i * 10;
	}
	for (int i = 0; i < 20; ++i) {
		printf("%d ", p_3[i]);
	}
	free(p_3);
	putchar('\n');

	// this is equivalent to malloc(1)
	int *p_5 = realloc(NULL, 1);
	free(p_5);

	// you can also make aligned memory allocations
	// realloc() doesn't have allignment guarantees so you have to write your own
	// usually it's best to avoid reallocating custom-aligned data
	/*
	int *p_6 = aligned_alloc(64, 16 * sizeof(int));
	aligned_realloc(p_6, 16 * sizeof(int), 64, 32 * sizeof(int));
	free(p_6);
	*/

	return 0;
}
