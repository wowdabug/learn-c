#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char *name;
	int age;
} Employee;

int comp(const void *ptr_1, const void *ptr_2) {
	const Employee *emp_1 = ptr_1;
	const Employee *emp_2 = ptr_2;

	if (emp_1->age < emp_2->age) {
		return -1;
	}

	if (emp_1->age > emp_2->age) {
		return 1;
	}

	return 0;
}

void print_employees(Employee *emps, int len) {
	for (int i = 0; i < len; ++i) {
		printf("%s %d\n", emps[i].name, emps[i].age);
	}
}

int main(void) {
	int x;
	int *p = &x;

	// basic pointer arithmetic
	// %p takes a void pointer, so we have to cast here
	printf("%p + 1 = %p\n", (void*)(p), (void*)(p + 1));
	printf("%p - 1 = %p\n", (void*)(p), (void*)(p - 1));

	// array-pointer equivalence
	// a[b] == *(a + b)
	int arr[] = {10, 20, 30, 40, 50};
	bool first = true;
	for (int i = 0; i < 5; ++i) {
		if (first) {
			first = false;
		} else {
			putchar(' ');
		}
		printf("%d", *(arr + i));
	}
	putchar('\n');

	// a void pointer indicates that we don't know the type is
	// memcpy() is a good example of how void pointers can be used
	char str_1[] = "Hello, world!";
	char str_2[1024];
	memcpy(str_2, str_1, 14);
	printf("%s\n", str_2);

	// you can't dereference, use pointer arithmetic, or use array notation on void pointers
	// to dereference void pointers you must first assign them into a variable of the desired type
	int y = 1;
	[[maybe_unused]] void *void_ptr = &y;

	// comp() is also a good example of how void pointers can be used
	Employee employees[] = {
		{"joe", 22},
		{"bob", 43},
		{"jim", 19}
	};
	qsort(employees, 3, sizeof(Employee), comp);
	print_employees(employees, 3);

	return 0;
}
