#include <stdio.h>

int main(void) {
	// reading from files
	FILE* fp;
	int c_1;

	// fopen() opens the file with a mode (ex. "r" is read and "w" is write)
	fp = fopen("test.txt", "r");

	// fgetc() has the side effect of moving the cursor ahead 1 byte
	// EOF is int, which is why fgetc() returns int
	while ((c_1 = fgetc(fp)) != EOF) {
		printf("%c", c_1);
	}
	putchar('\n');

	// fclose() closes the file
	fclose(fp);

	// more reading from files
	char s[1024];
	int lines = 0;
	fp = fopen("hello_world.txt", "r");

	// fgets() takes a pointer to a char buffer to hold bytes, a maximum number of bytes to read, and a FILE* to read from
	// it returns NULL on end-of-file or error
	while (fgets(s, sizeof(s), fp) != NULL) {
		printf("%d %s", ++lines, s);
	}
	fclose(fp);

	// MORE reading from files
	char name[1024];
	float length;
	int mass;
	fp = fopen("whales.txt", "r");

	// fscanf() can be hazardous with untrusted input (fgets() + sscanf() is safer)
	while (fscanf(fp, "%s %f %d", name, &length, &mass) != EOF) {
		printf("%s, %.1f meters, %d tonnes\n", name, length, mass);
	}
	fclose(fp);

	int x = 1;

	// writing to files
	// opening an existing file in "w" mode will instantly truncate that file to 0 bytes for a full overwrite
	fp = fopen("output.txt", "w");
	fputc('a', fp);
	fputc('\n', fp);
	fputs("Hello, world!\n", fp);
	fprintf(fp, "%d\n", x);
	fclose(fp);

	// writing to binary files (fprintf()-and-friends functions should usually be avoided due to NUL)
	unsigned char bytes[] = {0, 38, 255, 3, 195, 17, 82, 120};
	fp = fopen("output_binary.txt", "wb");
	fwrite(bytes, sizeof(char), 8, fp);
	fclose(fp);

	// reading from binary files
	unsigned char c_2;
	fp = fopen("output_binary.txt", "rb");
	while (fread(&c_2, sizeof(char), 1, fp) > 0) {
		printf("%d ", c_2);
	}
	putchar('\n');
	fclose(fp);

	// make sure to serialize your binary data when you write it to a stream!
	// this is because different architectures have different endianess

	return 0;
}
