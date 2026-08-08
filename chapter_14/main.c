#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {
	printf("char %d %d\n", CHAR_MIN, CHAR_MAX);
	putchar('\n');
	printf("signed char %d %d\n", SCHAR_MIN, SCHAR_MAX);
	printf("short %d %d\n", SHRT_MIN, SHRT_MAX);
	printf("int %d %d\n", INT_MIN, INT_MAX);
	printf("long %ld %ld\n", LONG_MIN, LONG_MAX);
	printf("long long %lld %lld\n", LLONG_MIN, LLONG_MAX);
	putchar('\n');
	printf("unsigned char %u %u\n", 0, UCHAR_MAX);
	printf("short %u %u\n", 0, USHRT_MAX);
	printf("int %u %u\n", 0, UINT_MAX);
	printf("long %lu %lu\n", 0UL, ULONG_MAX);
	printf("long long %llu %llu\n", 0ULL, ULLONG_MAX);
	putchar('\n');

	[[maybe_unused]] int binary = 0b1; // C23 supports binary
	[[maybe_unused]] int octal = 01;
	[[maybe_unused]] int decimal = 1;
	[[maybe_unused]] int hexidecimal = 0x1;
	[[maybe_unused]] double hexidecimal_float = 0x1.8p0;

	printf("%f\n", hexidecimal_float);
	printf("%e\n", hexidecimal_float);
	printf("%a\n", hexidecimal_float);
	putchar('\n');

	[[maybe_unused]] int a = 1;
	[[maybe_unused]] long int b = 1L;
	[[maybe_unused]] long long int c = 1ll;

	[[maybe_unused]] unsigned int d = 1u;
	[[maybe_unused]] unsigned long int e = 1ul;
	[[maybe_unused]] unsigned long long int f = 1ull;

	[[maybe_unused]] float g = 1.5f;
	[[maybe_unused]] double h = 1.5;
	[[maybe_unused]] long double i = 1.5L;

	// floating-point data types are stored similarly to scientific notation
	// sign × significand × 2^exponent

	// number of decimal digits that are guaranteed to be preserved
	printf("%d\n", FLT_DIG);
	printf("%d\n", DBL_DIG);
	printf("%d\n", LDBL_DIG);

	// number of decimal digits that are encoded
	printf("%d\n", FLT_DECIMAL_DIG);
	printf("%d\n", DBL_DECIMAL_DIG);
	printf("%d\n", LDBL_DECIMAL_DIG);

	return 0;
}
