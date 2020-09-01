#include <stdio.h>
#include <time.h>
#include <inttypes.h>

#include "interpreter.h"

void testInterpreter(void) {
		const char c[] = "AsQcJd3s2d";

		int len = (sizeof(c)-1)/2;

		printf("Cards %s\n", c);

		card64_t setOfCards64 = getCard64FromString(c, len);

		printf("Cards %" PRIx64 "\n", setOfCards64);

		char setOfCardsS[11];
		getCard64AsString(setOfCards64, setOfCardsS, 10);

		printf("Cards %s\n", setOfCardsS);

		printf("pik %s\n", "\u2665");
		printf("pik %s\n", "\u2666");
		printf("pik %s\n", "\u2663");
		printf("pik %s\n", "\u2660");
}
