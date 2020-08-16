
#include <stdio.h>
#include <time.h>

#include "card64.h"
#include "interpreter.h"
#include "funcs.h"

//#include "funcs.h"


int main() {

	const char c[] = "AsQcJd3s2d";
	int len = (sizeof(c)-1)/2;

	printf("CARD %llx\n", getCard64FromString(c, len));

	char cards[len*2+1];
//	cards[len*2] = 0;
	if (getCard64AsString(getRandomCards64(len, 0), cards, len))
		printf("CARD %s\n", cards);

	printf("c %lu, len %d\n", sizeof(c), len);

	static uint64_t boards[1712304];	//2598960   1712304
	uint64_t cardsInGame = CARD64_Xx(RANK_3, SUIT_S) | CARD64_Xx(RANK_3, SUIT_H) | CARD64_Xx(RANK_3, SUIT_D) | CARD64_Xx(RANK_3, SUIT_C);
//			CARD64_Xx(RANK_5, SUIT_S) | CARD64_Xx(RANK_5, SUIT_H) | CARD64_Xx(RANK_5, SUIT_D) | CARD64_Xx(RANK_5, SUIT_C);

    struct timespec tstart={0,0}, tend={0,0};

    clock_gettime(CLOCK_MONOTONIC, &tstart);
    for (int i = 0; i < 100; i++) {
//    	getPosibleBoards(boards, cardsInGame);
    	getRandomCards64(len, 0);
    }
	clock_gettime(CLOCK_MONOTONIC, &tend);

	printf("getPosibleBoards time: %f",
						((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) -
						((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec));


	return 0;
}
