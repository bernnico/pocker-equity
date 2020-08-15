//#include "funcs.h"

//getRandomCards(uint8_t numbersOfCards, uint64_t cardsInGame) {
//	uint8_t randomImage, randomSuit;
//	uint64_t randomCards = 0, foundCard;
//
//	for (int i = 0; i < numbersOfCards; i++) {
//		do {
//			randomImage = random() % 13;
//			randomSuit = random() % 4;
//			foundCard = GET_CARD_64(randomImage, randomSuit);
//		} while ( ((cardsInGame | randomCards) & foundCard) != 0UL );
//
//		randomCards |= foundCard;
//	}
//
//	return randomCards;
//}


