#include <stdio.h>
#include <string.h>

struct person {
	char *name;
	int age;
};

void print_person(struct person *p) {
	printf("Name: %s\n", p->name);
	printf("Age: %d\n", p->age);
}

void set_age(struct person *p, int new_age) {
	p->age = new_age;
}

int main(void) {
	struct person p_1 = {"Foo", 25};
	set_age(&p_1, 26);

	// we can be more specific with our initializers
	[[maybe_unused]] struct person p_2 = {.name="Bar", .age=35};

	// you can easily copy structs to each other
	p_1 = p_2;

	print_person(&p_1);
	print_person(&p_2);

	// the safest way to compare structs is using every field
	[[maybe_unused]] bool are_people_equal = strcmp(p_1.name, p_2.name) == 0 && p_1.age == p_2.age;
	printf("The two people are %s.\n", are_people_equal ? "identical" : "not identical");

	return 0;
}
