

#include <card64.h>
#include <stdio.h>

#include "interpreter.h"

//#include "funcs.h"


int main() {

	const char c[] = "1";

	printf("CARD %llX\n", getCard64FromString("AsAh", 2));
	printf("!!!Hello World!!! %d\n", sizeof(long));
	printf("!!!Hello World!!! %d\n", sizeof(long long));
	printf("c %d\n", sizeof(c));


	return 0;

}
