#include <stdio.h>

int main(void) {
	// this is a typedef
	typedef int MyInt;
	MyInt a = 1;

	// multple at once!
	typedef int MyInt1, MyInt2, MyInt3;
	MyInt1 b = 2;
	MyInt2 c = 3;
	MyInt3 d = 4;

	// sometimes a struct will be typedef’d to a new name
	// there are 3 main methods to do this
	struct MyStruct1 {
		int x;
		int y;
	};
	typedef struct MyStruct1 MyStruct1;

	typedef struct MyStruct2 {
		int x;
		int y;
	} MyStruct2;

	// this method uses anonymous structures
	typedef struct {
		int x;
		int y;
	} MyStruct3;

	// you can make a type that is a pointer
	// one reason to not use this is because it doesn't explicitly show that you’re declaring a pointer type
	typedef int *IntPtr;

	typedef int FiveInts[5];
	FiveInts arr = {1, 2, 3, 4, 5};

	return 0;
}
