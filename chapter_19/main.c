// here are some different include statements
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "a.h"
#include "nested/b.h"

// you can define and undefine macros
#define PI 3.14159
#undef PI

// it's conventional to use SCREAMING_SNAKE_CASE for macros
#define HELLO_WORLD "Hello, world!"

#define A
#define B
#define C 1

// these are some examples of macros with arguments
#define SQR(x) ((x) * (x))
#define MIN(x, y) ((y) < (x) ? (y) : (x))

// variable arguments (ellipses) can be used in macros
#define X(...) __VA_ARGS__

// # stringifies arguments
#define PRINT_NUMBER(x) puts(#x)

// ## concatenates 2 arguments
#define CONCAT(x, y) x ## y

// this is a multi-line macro
// note the backslashes and do-while loop
#define PRINT_NUMBERS(x, y) do { \
	for (int i = x; i < y; ++i) { \
		printf("%d\n", i); \
	} \
} while(0)

// here is an example of an assert macro
#define ASSERT_ENABLED
#ifdef ASSERT_ENABLED
	#define ASSERT(x, y) do { \
		if (!(x)) { \
			fprintf(stderr, "file %s: line %d: assertion %s failed: %s\n", __func__, __LINE__, #x, y); \
			exit(1); \
		} \
	} while(0)
#else
	#define ASSERT(x, y)
#endif

// #error and #warning are diagnostic directives
#if __STDC__ != 1
	#error "Not a standard compliant compiler"
#endif

// #warning was introduced in C23 but was present in many compilers before then
#if __STDC_VERSION__ >= 202311L
	#warning "Using #warning as a standard feature"
#endif

// there is also a big list of optional macros, but these are more important
void print_mandatory_macros(void) {
	printf("Date: %s\n", __DATE__);
	printf("Time: %s\n", __TIME__);
	printf("File: %s\n", __FILE__);
	printf("Line: %d\n", __LINE__);
	printf("Function: %s\n", __func__);
	printf("Standard compiler: %s\n", __STDC__ ? "true" : "false");
	printf("Hosted: %s\n", __STDC_HOSTED__ ? "true" : "false");
	printf("Version: %ld\n", __STDC_VERSION__);
}

int main(void) {
	puts(HELLO_WORLD);

	#ifdef A
		puts("A is defined");
	#endif

	#ifndef B
		puts("B is not defined");
	#else
		puts("B is defined");
	#endif

	#if __STDC_VERSION__ >= 202311L
		#ifdef A
			puts("A is defined");
		#elifdef B
			puts("A is not defined and B is defined");
		#elifndef C
			puts("A is not defined and C is not defined");
		#endif
	#else
		// pre-C23 you can use defined or !defined
		#ifdef A
			puts("A is defined");
		#elif defined B
			puts("A is not defined and B is defined");
		#elif !defined C
			puts("A is not defined and C is not defined");
		#endif
	#endif

	#if C == 0
		puts("C is 0");
	#elif C == 1
		puts("C is 1");
	#else
		puts("C is not 0 or 1");
	#endif

	print_mandatory_macros();

	int x = 7;
	printf("The square of %d is %d\n", x, SQR(x));

	int a = 1;
	int b = 2;
	printf("The min of %d and %d is %d\n", a, b, MIN(a, b));

	printf("%d%d%d\n", X(1, 2, 3));

	PRINT_NUMBER(3.14159);

	printf("The value of pi is %f\n", CONCAT(3.14, 159));

	PRINT_NUMBERS(0, 10);

	ASSERT(true, "message");

	// #embed includes bytes of a file as integer constants
	// there are also embed parameters such as limit(), if_empty(), prefix(), and suffix()
	// __has_embed returns 0 (__STDC_EMBED_NOT_FOUND__), 1 (__STDC_EMBED_FOUND__), or 2 (__STDC_EMBED_EMPTY__)
	#if __has_embed("data.dat")
		int d[] = {
			#embed "data.dat"
		};
	#endif

	for (size_t i = 0; i < sizeof(d) / sizeof(int); ++i) {
		printf("d[%zu] = %d\n", i, d[i]);
	}

	// there are a few standard pragmas that follow the form: #pragma STDC PRAGMA_NAME ON/OFF/DEFAULT
	// these include FP_CONTRACT, FENV_ACCESS, and CX_LIMITED_RANGE
	// _Pragma() lets you put declare pragmas that can be put inside macros

	// #line lets you override __LINE__ and __FILE__
	// there aren't many good use cases for it

	return 0;
}
