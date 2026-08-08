#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "conversions.h"

void print_path(void) {
	char *path = getenv("PATH");
	if (path != NULL) {
		char *c = strtok(path, ";");

		while (c != NULL) {
			puts(c);
			c = strtok(NULL, ";");
		}
	}
}

int main(int argc, char **argv) {
	int sum = 0;

	for (int i = 0; i < argc; ++i) {
		printf("Argument #%d is %s\n", i, argv[i]);
	}

	for (int i = 1; i < argc; ++i) {
		int x;
		if (string_to_int(argv[i], &x)) {
			sum += x;
		} else {
			printf("Failed to convert argument #%d to int\n", i);
		}
	}

	printf("Sum: %d\n", sum);

	// after the last string is a pointer to NULL
	assert(argv[argc] == NULL);

	// this function print the PATH environment variable
	print_path();

	const bool error = false;
	if (error) {
		return EXIT_FAILURE; // exit codes should usually be from 0-255
	}
	
	return EXIT_SUCCESS; // same as 0
}
