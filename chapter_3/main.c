#include <stdio.h>

int main() {
	printf("Hello, world!\n");

	{
		[[maybe_unused]] bool a = true;
		[[maybe_unused]] char b = 'a';
		[[maybe_unused]] signed char c = 'b';
		[[maybe_unused]] unsigned char d = 'c';
		[[maybe_unused]] short e = 1;
		[[maybe_unused]] unsigned short f = 2;
		[[maybe_unused]] int g = 3;
		[[maybe_unused]] unsigned int h = 4;
		[[maybe_unused]] long i = 5;
		[[maybe_unused]] unsigned long j = 6;
		[[maybe_unused]] long long k = 7;
		[[maybe_unused]] unsigned long long l = 8;
		[[maybe_unused]] float m = 1.5;
		[[maybe_unused]] double n = 2.5;
		[[maybe_unused]] long double o = 3.5;
		[[maybe_unused]] char* string = "Hello, world!";
	}

	printf("%zu\n", sizeof(bool));
	printf("%zu\n", sizeof(char));
	printf("%zu\n", sizeof(signed char));
	printf("%zu\n", sizeof(unsigned char));
	printf("%zu\n", sizeof(short));
	printf("%zu\n", sizeof(unsigned short));
	printf("%zu\n", sizeof(int));
	printf("%zu\n", sizeof(unsigned int));
	printf("%zu\n", sizeof(long));
	printf("%zu\n", sizeof(unsigned long));
	printf("%zu\n", sizeof(long long));
	printf("%zu\n", sizeof(unsigned long long));
	printf("%zu\n", sizeof(float));
	printf("%zu\n", sizeof(double));
	printf("%zu\n", sizeof(long double));

	int x = 1;
	int y = 2;
	bool z = true;

	x = y + 3;
	x = y - 8;
	x = y * 9;
	x = y / 2;
	x = y % 5;

	x += 3;
	x -= 8;
	x *= 9;
	x /= 2;
	x %= 5;

	x++;
	x--;
	++x;
	--x;

	x = 1, y = 2;

	printf("%s\n", z ? "true" : "false");

	(void)(x == y);
	(void)(x != y);
	(void)(x < y);
	(void)(x > y);
	(void)(x <= y);
	(void)(x >= y);

	if (z && z) {}
	if (z || z) {}
	if (!z) {}
	if (z) {} else {}

	int i = 0;
	while (i < 10) {
		printf("i = %d\n", i);
		++i;
	}

	do {
		printf("i = %d\n", i);
		++i;
	} while (i < 10);

	for (int i = 0; i < 10; ++i) {
		printf("i = %d\n", i);
	}

	i = 1;
	switch (i) {
		case 1:
			printf("one\n");
			break;
		case 2:
			printf("two\n");
			break;
		case 3:
			printf("three\n");
			break;
		default:
			printf("?\n");
			break;
	}
	
	return 0;
}
