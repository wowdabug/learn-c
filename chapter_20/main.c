#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define INVENTORY_SIZE 36

typedef enum item {
	NONE,
	SWORD,
	PICKAXE,
	AXE,
	SHOVEL
} Item;

const char *get_item_name(Item item) {
	switch (item) {
		case NONE:
			return "none";
		case SWORD:
			return "sword";		
		case PICKAXE:
			return "pickaxe";														
		case AXE:
			return "axe";
		case SHOVEL:
			return "shovel";
		default:
			return "";
	}
}

typedef struct slot {
	Item item;
	int quantity;
} Slot;

typedef struct inventory {
	Slot slots[INVENTORY_SIZE];
} Inventory;

void print_inventory(const Inventory *inventory) {
	for (int i = 0; i < INVENTORY_SIZE; ++i) {
		const Slot slot = inventory->slots[i];
		if (slot.item != NONE) {
			printf("%s: %d\n", get_item_name(slot.item), slot.quantity);
		}
	}
}

// structs can be self-referential in c
// this is an example of a linked list struct
typedef struct node {
	int data;
	struct node *next;
} Node;

// this struct has flexible array members
typedef struct string {
	size_t len;
	char data[];
} String;

String *create_string(const char *c_string) {
	size_t len = strlen(c_string);
	String *string = malloc(sizeof(*string) + len + 1);
	string->len = len;
	memcpy(string->data, c_string, len + 1);
	return string;
}

typedef struct padded {
	int a;
	char b;
	int c;
	char d;
} Padded;

typedef struct parent {
	int a;
} Parent;

typedef struct child {
	Parent super;
	int b;
} Child;

void print_parent(void *p) {
	Parent *self = p;
	printf("Parent: %d\n", self->a);
}

void print_child(Child *self) {
	printf("Child: %d\n", self->b);
}

// bit-fields can be used to efficiently pack values
// arrays or pointers to bit-fields are disallowed
// compilers may still add padding
typedef struct bit_fields {
	unsigned int a : 1;
	unsigned int b : 2;
	unsigned int : 0; // zero-width unnamed bit-field (to split a & b and c & d into 2 seperate ints)
	unsigned int c : 3;
	unsigned int d : 4;
} BitFields;

// in a union fields overlap in memory
typedef union example_union {
	int a;
	double b;
} ExampleUnion;

typedef struct a {
	int a;
	double b;
} A;

typedef struct b {
	int a;
	double b;
} B;

// the common initial sequence of structs can be accessed through unions
typedef union c {
	A a;
	B b;
} C;

// unnamed structs can be put in unions
typedef union d {
	struct {
		int a;
		int b;
	} a;
	struct {
		int a;
		int b;
	} b;
} D;

int main(void) {
	puts("Hello, world!");

	// nested structs and arrays can be initialized in many ways
	const Inventory inventory1 = {
		.slots[0] = {
			.item = SWORD,
			.quantity = 1
		},
		.slots[1].item = PICKAXE,
		.slots[1].quantity = 1,
	};

	print_inventory(&inventory1);

	const Inventory inventory2 = {
		.slots = {
			[0].item = AXE,
			[0].quantity = 1,
			[1] = {
				.item = SHOVEL,
				.quantity = 1
			}
		}
	};

	print_inventory(&inventory2);

	// this is an anonymous struct
	// usually it's better to avoid using them
	struct {
		char *name;
		int legs;
	} animal;

	animal.name = "bear";
	animal.legs = 4;

	printf("A %s has %d legs\n", animal.name, animal.legs);

	String *s = create_string("Hello, world!");
	printf("%s\n", s->data);
	free(s);

	// c is allowed to pad bytes in structs, so don't always trust sizeof()
    printf("%zu\n", sizeof(int) + sizeof(char) + sizeof(int) + sizeof(char));
    printf("%zu\n", sizeof(Padded));

	// offsetof() helps find where fields are in padded structs
    printf("%zu\n", offsetof(Padded, a));
    printf("%zu\n", offsetof(Padded, b));
    printf("%zu\n", offsetof(Padded, c));
    printf("%zu\n", offsetof(Padded, d));

	// we can mimic OOP by abusing structs and pointers
	Child c = {
		.super.a = 1,
		.b = 2
	};

	print_parent(&c);
	print_child(&c);

	[[maybe_unused]] BitFields bf = {
		.a = 1,
		.b = 3,
		.c = 7,
		.d = 15
	};

	// type-pruning (writing to one union field and reading from another)
	ExampleUnion u;
	u.b = 3.14159;
	printf("%d\n", u.a);

	// you can cast pointers to unions to the types of fields in the union
	ExampleUnion *p = &u;
	[[maybe_unused]] int *int_ptr = (int *)p;
	[[maybe_unused]] double *double_ptr = (double *)p;

	// and back!
	[[maybe_unused]] ExampleUnion *union_ptr = (ExampleUnion *)int_ptr;
}
