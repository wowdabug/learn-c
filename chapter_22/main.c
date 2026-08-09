#include <stdio.h>

// you can typedef enums
// they can also be defined in file scope or block scope
// enum variants usually use SCREAMING_SNAKE_CASE
typedef enum tool {
	SWORD,
	PICKAXE,
	AXE = 2, // integer values can be forced; numbering counts up from whichever value was last specified
	SHOVEL // trailing commas are optional
} Tool;

const char *get_tool_name(Tool t) {
	switch (t) {
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

void print_tool(Tool t) {
	printf("%s\n", get_tool_name(t));
}

int main(void) {
	Tool t = SWORD;
	print_tool(t);

	return 0;
}
