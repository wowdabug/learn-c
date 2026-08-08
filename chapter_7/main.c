#include <stdio.h>
#include <string.h>

size_t my_strlen(char *str) {
	size_t i = 0;
	while (str[i] != '\0') {
		++i;
	}
	return i;
}

int main() {
	char *string_1 = "Hello, world!";
	for (int i = 0; i < 13; ++i) {
		printf("%c", string_1[i]);
	}
	printf("\n");

	// this is a string literal
	// it is immutable, and undefined behavior will result
	[[maybe_unused]] char *string_2 = "Hello, world!";

	// declaring a string as an array makes it mutable
	char string_3[] = "Hello, world!";
	string_3[0] = 'W';
	string_3[7] = 'h';
	printf("%s\n", string_3);

	printf("%zu\n", strlen(string_1));
	printf("%zu\n", my_strlen(string_1));

	// copy strings using strcpy
	char string_4[100];
	strcpy(string_4, string_1);

	return 0;
}
