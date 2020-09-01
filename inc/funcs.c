#include "funcs.h"

card64_t getRandomCards64(uint8_t numbersOfCards, card64_t cardsInGame) {
	srand(time(NULL)); // TODO

	uint8_t randomRank, randomSuit;
	card64_t randomCards = 0, foundCard;

	for (int i = 0; i < numbersOfCards; i++) {
		do {
			randomRank = rand() % RANKS;
			randomSuit = rand() % SUITS;
			foundCard = CARD64_Xx(randomRank, randomSuit);
		} while ( ((cardsInGame | randomCards) & foundCard) != 0ULL );

		randomCards |= foundCard;
	}

	return randomCards;
}



#define LAST_BOARD			(	CARD64_Xx(RANK_A, SUIT_S) | \
								CARD64_Xx(RANK_A, SUIT_H) | \
								CARD64_Xx(RANK_A, SUIT_D) | \
								CARD64_Xx(RANK_A, SUIT_C) | \
								CARD64_Xx(RANK_K, SUIT_S)	)

void getPosibleBoards(card64_t * boards, card64_t cardsInGame) {
	card64_t card_3c = CARD64_Xx(RANK_3, SUIT_C); // 3s;
	card64_t card_2s = CARD64_Xx(RANK_2, SUIT_S); // 2c;
	card64_t card_2h = CARD64_Xx(RANK_2, SUIT_H); // 2d;
	card64_t card_2d = CARD64_Xx(RANK_2, SUIT_D); // 2h;
	card64_t card_2c = CARD64_Xx(RANK_2, SUIT_C); // 2s;

	card64_t board   = card_3c|card_2s|card_2h|card_2d|card_2c;

	int size = 0;

	if ((cardsInGame & board) == 0) {
		boards[0] = board;
		size++;
	}

	while (board != LAST_BOARD) {
		if (card_3c != CARD64_Xx(RANK_A, SUIT_S)) {      // As
			card_3c <<= 1;
		}
		else if (card_2s != CARD64_Xx(RANK_A, SUIT_H)) { // Ah
			card_2s <<= 1;
			card_3c = card_2s << 1;
		}
		else if (card_2h != CARD64_Xx(RANK_A, SUIT_D)) { // Ad
			card_2h <<= 1;
			card_2s = card_2h << 1;
			card_3c = card_2s << 1;
		}
		else if (card_2d != CARD64_Xx(RANK_A, SUIT_C)) { // Ac
			card_2d <<= 1;
			card_2h = card_2d << 1;
			card_2s = card_2h << 1;
			card_3c = card_2s << 1;
		}
		else /* if (card2c != CARD64_Xx(RANK_K, SUIT_S)) */ { // Ks
			card_2c <<= 1;
			card_2d = card_2c << 1;
			card_2h = card_2d << 1;
			card_2s = card_2h << 1;
			card_3c = card_2s << 1;
		}

		board = card_3c|card_2s|card_2h|card_2d|card_2c;

		if ((cardsInGame & board) == 0) {
			boards[size] = board;
			size++;
//			if (size == 1712304) break;
		}
	}
}

uint32_t getPosibleNBoards(card64_t * boards, card64_t cardsInGame, uint32_t n) {
	static card64_t card_3c = CARD64_Xx(RANK_3, SUIT_C); // 3s;
	static card64_t card_2s = CARD64_Xx(RANK_2, SUIT_S); // 2c;
	static card64_t card_2h = CARD64_Xx(RANK_2, SUIT_H); // 2d;
	static card64_t card_2d = CARD64_Xx(RANK_2, SUIT_D); // 2h;
	static card64_t card_2c = CARD64_Xx(RANK_2, SUIT_C); // 2s;

	card64_t board   = card_3c|card_2s|card_2h|card_2d|card_2c;

	int size = 0;

	if ((cardsInGame & board) == 0) {
		boards[0] = board;
		size++;
	}

	while (board != LAST_BOARD) {
		if (card_3c != CARD64_Xx(RANK_A, SUIT_S)) {      // As
			card_3c <<= 1;
		}
		else if (card_2s != CARD64_Xx(RANK_A, SUIT_H)) { // Ah
			card_2s <<= 1;
			card_3c = card_2s << 1;
		}
		else if (card_2h != CARD64_Xx(RANK_A, SUIT_D)) { // Ad
			card_2h <<= 1;
			card_2s = card_2h << 1;
			card_3c = card_2s << 1;
		}
		else if (card_2d != CARD64_Xx(RANK_A, SUIT_C)) { // Ac
			card_2d <<= 1;
			card_2h = card_2d << 1;
			card_2s = card_2h << 1;
			card_3c = card_2s << 1;
		}
		else /* if (card2c != CARD64_Xx(RANK_K, SUIT_S)) */ { // Ks
			card_2c <<= 1;
			card_2d = card_2c << 1;
			card_2h = card_2d << 1;
			card_2s = card_2h << 1;
			card_3c = card_2s << 1;
		}

		board = card_3c|card_2s|card_2h|card_2d|card_2c;

		if ((cardsInGame & board) == 0) {
			boards[size] = board;
			size++;
			if (board == LAST_BOARD) break;
			if (n == size) return size;
		}
	}

	card_3c = CARD64_Xx(RANK_3, SUIT_C); // 3s;
	card_2s = CARD64_Xx(RANK_2, SUIT_S); // 2c;
	card_2h = CARD64_Xx(RANK_2, SUIT_H); // 2d;
	card_2d = CARD64_Xx(RANK_2, SUIT_D); // 2h;
	card_2c = CARD64_Xx(RANK_2, SUIT_C); // 2s;

	return size;
}

uint32_t getFlush(card64_t playerCards) {
	// IS FLUSH POSSIBLE
	if ((playerCards & CARD64_C_MASK) && (playerCards & CARD64_D_MASK) &&
		(playerCards & CARD64_H_MASK) && (playerCards & CARD64_S_MASK))
		return 0;

	uint8_t s = 0, h = 0, d = 0, c = 0;
	for (int rank = 0; rank < RANKS; rank++) {
		if ((playerCards & CARD64_A_MASK >> (rank<<2)) == 0) {
			continue;
		}
		if ((playerCards & CARD64_Xx(RANK_A, SUIT_C) >> (rank<<2)) != 0) {
			c++;
		}
		if ((playerCards & CARD64_Xx(RANK_A, SUIT_D) >> (rank<<2)) != 0) {
			d++;
		}
		if ((playerCards & CARD64_Xx(RANK_A, SUIT_H) >> (rank<<2)) != 0) {
			h++;
		}
		if ((playerCards & CARD64_Xx(RANK_A, SUIT_S) >> (rank<<2)) != 0) {
			s++;
		}
	}

	uint8_t suit = 5;
	if (c > 4)			suit = 0;
	else if (d > 4)		suit = 1;
	else if (h > 4)		suit = 2;
	else if (s > 4)     suit = 3;

	uint32_t playerWinningCards = 0;
	if (suit != 5) {
		card64_t flushChecker = playerCards >> suit;
		for (int rank = 0; rank < RANKS; rank++) {
			if ((flushChecker & CARD64_Xx(RANK_A, SUIT_C) >> (rank<<2)) != 0) {
				playerWinningCards |= 0x001000 >> rank;
			}
		}
	}

	return playerWinningCards;
}

//uint32_t getStraightFlush(uint32_t playerCards) {
//	uint32_t bestFlushValue = 0;
//
//	if ((playerCards & 0x0100) != 0 ) {
//		if ((playerCards & 0x1F00) == 0x1F00)	bestFlushValue = 0x1F00;
//		if ((playerCards & 0x0F80) == 0x0F80)	bestFlushValue = 0x0F80;
//		if ((playerCards & 0x07C0) == 0x07C0)	bestFlushValue = 0x07C0;
//		if ((playerCards & 0x03E0) == 0x03E0)	bestFlushValue = 0x03E0;
//		if ((playerCards & 0x01F0) == 0x01F0)	bestFlushValue = 0x01F0;
//	}
//	if (bestFlushValue == 0 && ((playerCards & 0x0008) != 0)) {
//		if ((playerCards & 0x00F8) == 0x00F8)	bestFlushValue = 0x00F8;
//		if ((playerCards & 0x007C) == 0x007C)	bestFlushValue = 0x007C;
//		if ((playerCards & 0x003E) == 0x003E)	bestFlushValue = 0x003E;
//		if ((playerCards & 0x001F) == 0x001F)	bestFlushValue = 0x001F;
//	}
//	if (bestFlushValue == 0 && (playerCards & 0x100F) == 0x100F) bestFlushValue = 0x100F;
//
//	if (bestFlushValue != 0)
//		return HIT_FLAG32_FLUSH | bestFlushValue;
//
//	uint8_t flag = 0;
//	for (int i = 0; i < 13; i++) {
//		if (playerCards & 0x1000 >> i) {
//			bestFlushValue |= 0x1000 >> i;
//			flag++;
//			if (flag == 5) {
//				break;
//			}
//		}
//	}
//	return HIT_FLAG32_STRAIGHT_FLUSH | bestFlushValue;
//}












