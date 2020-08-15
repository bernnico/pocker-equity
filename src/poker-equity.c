
#include <stdio.h>

#include "card64.h"
#include "interpreter.h"

//#include "funcs.h"


int main() {

	const char c[] = "AsAhQcJd3s2d";
	int len = (sizeof(c)-1)/2;

	printf("CARD %llx\n", getCard64FromString(c, len));

	char cards[len*2+1];
//	cards[len*2] = 0;
	if (getCard64AsString(getCard64FromString(c, len), cards, len))
		printf("CARD %s\n", cards);

	printf("c %lu, len %d\n", sizeof(c), len);


	return 0;
}
