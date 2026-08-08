#include <stdio.h>

void print_values(int *arr, size_t len) {
	for (size_t i = 0; i < len; ++i) {
		printf("%d\n", arr[i]);
	}
}

// all dimensions except the first one need to be known
void print_values_2d(int arr[3][3]) {
	for (size_t i = 0; i < 3; ++i) {
		bool first = true;
		for (size_t j = 0; j < 3; ++j) {
			if (first) {
				first = false;
			} else {
				printf(", ");
			}
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}
}

int main() {
	float floats[3] = {0.5, 1.5, 2.5};
	for (size_t i = 0; i < sizeof(floats) / sizeof(float); ++i) {
		printf("floats[%zu] == %f\n", i, floats[i]);
	}

	// prints the size of 100 floats
	printf("the size of 100 floats is %zu bytes\n", sizeof(float [100]));

	// the remaining elements in the array will be automatically initialized with zero
	[[maybe_unused]] int arr_1[5] = {1, 2, 3};

	// this shortcut sets every value to zero
	[[maybe_unused]] int arr_2[7] = {0};

	// you can add as many dimensions as you want to arrays
	[[maybe_unused]] int multidimensional_arr[3][3] = {0};

	// same thing
	[[maybe_unused]] int *ptr_1 = &arr_1[0];
	[[maybe_unused]] int *ptr_2 = arr_1;

	print_values(arr_1, 5);
	print_values_2d(multidimensional_arr);

	return 0;
}
