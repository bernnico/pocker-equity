#include "funcs.h"

uint64_t getRandomCards64(uint8_t numbersOfCards, uint64_t cardsInGame) {
	srand(time(NULL));

	uint8_t randomImage, randomSuit;
	uint64_t randomCards = 0, foundCard;

	for (int i = 0; i < numbersOfCards; i++) {
		do {
			randomImage = rand() % 13;
			randomSuit = rand() % 4;
			foundCard = CARD64_Xx(randomImage, randomSuit);
		} while ( ((cardsInGame | randomCards) & foundCard) != 0UL );

		randomCards |= foundCard;
	}

	return randomCards;
}

#define LASTBOARD			(	CARD64_Xx(RANK_A, SUIT_C) | \
								CARD64_Xx(RANK_A, SUIT_D) | \
								CARD64_Xx(RANK_A, SUIT_H) | \
								CARD64_Xx(RANK_A, SUIT_S) | \
								CARD64_Xx(RANK_K, SUIT_C)	)

void getPosibleBoards(uint64_t * boards, uint64_t cardsInGame) {
		uint64_t card3s = CARD64_Xx(RANK_3, SUIT_S); // 3s;
		uint64_t card2c = CARD64_Xx(RANK_2, SUIT_C); // 2c;
		uint64_t card2d = CARD64_Xx(RANK_2, SUIT_D); // 2d;
		uint64_t card2h = CARD64_Xx(RANK_2, SUIT_H); // 2h;
		uint64_t card2s = CARD64_Xx(RANK_2, SUIT_S); // 2s;
		uint64_t board = card3s|card2c|card2d|card2h|card2s;

		uint32_t size = 0;

		if ((cardsInGame & board) == 0) {
			boards[0] = board;
			size++;
		}

		while (board != LASTBOARD) {
			if (card3s != CARD64_Xx(RANK_A, SUIT_C)) {      // Ac
				card3s <<= 1;
			}
			else if (card2c != CARD64_Xx(RANK_A, SUIT_D)) { // Ad
				card2c <<= 1;
				card3s = card2c << 1;
			}
			else if (card2d != CARD64_Xx(RANK_A, SUIT_H)) { // Ah
				card2d <<= 1;
				card2c = card2d << 1;
				card3s = card2c << 1;
			}
			else if (card2h != CARD64_Xx(RANK_A, SUIT_S)) { // As
				card2h <<= 1;
				card2d = card2h << 1;
				card2c = card2d << 1;
				card3s = card2c << 1;
			}
			else /* if (card2s != CARD64_Xx(RANK_K, SUIT_C)) */ { // Ks
				card2s <<= 1;
				card2h = card2s << 1;
				card2d = card2h << 1;
				card2c = card2d << 1;
				card3s = card2c << 1;
			}

			board = card3s|card2c|card2d|card2h|card2s;

			if ((cardsInGame & board) == 0) {
				boards[size] = board;
				size++;
			}
		}
}
