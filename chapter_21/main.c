#include <stdio.h>
#include <windows.h>

int main(void) {
	// these are some common escape sequences
	// uncommon ones include \a, \b, \f, \r, \t, \v, and \?
	puts("\n\'\"\\");

	// here is an example of \r (returns to beginning of line)
	for (int i = 10; i > 0; --i) {
		printf("\r%d\n", i);
		fflush(stdout);
		Sleep(1000);
	}

	// \? is used because of trigraphs, but these were removed in C23

	// these are numeric escapes
	puts("\141"); // octal
	puts("\x61"); // hex
	puts("\u0041"); // unicode
	puts("\U00000041"); // unicode

	return 0;
}
