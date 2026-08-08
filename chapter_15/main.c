#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

int main(void) {
	// number to string
	{
		int x = 1;
		char str[10];
		snprintf(str, sizeof(str), "%d", x);
		printf("number to string: %d -> %s\n", x, str);
	}

	// string to number
	{
		char *str = "2";
		char *str_end;
		int value = strtol(str, &str_end, 10);
		int x;
		if (str_end == str) { x = 0; } // for checking if no digits were parsed
		if (*str_end != '\0') { x = 0; } // for checking if conversion was partial
		if (errno == ERANGE) { x = 0; } // for detecting overflow under LONG_MIN or over LONG_MAX
		if (value < INT_MIN || value > INT_MAX) { x = 0; } // for converting from long to int
		x = (int)value;
		printf("string to number: %s -> %d\n", str, x);
	}

	// number to char
	{
		int x = 3;
		char c = x + '0';
		printf("number to char: %d -> %c\n", x, c);
	}

	// char to number
	{
		char c = '4';
		int x = c - '0';
		printf("char to number %c -> %d\n", c, x);
	}

	// if you convert 0 to bool it is false, otherwise it is true
	
	// if an integer type is converted to unsigned and doesn’t fit in it, the unsigned result wraps around
	// if an integer type is converted to a signed number and doesn’t fit, the result is implementation-defined

	// if a floating point type is converted to an integer type, the fractional part is discarded
	// going from integer to floating point, c finds the closest floating point number it can

	// there are also integer promotions, automatic conversions, and void* being converted to and from every pointer type

	// casting can be done by putting a new type in parentheses
	// usually casting should be avoided

	return 0;
}
