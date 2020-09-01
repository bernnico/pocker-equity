#ifndef FUNC_H_
#define FUNC_H_

#include <time.h>
#include <stdlib.h>

#include "card64.h"

card64_t getRandomCards64(uint8_t numbersOfCards, uint64_t cardsInGame);

void getPosibleBoards(uint64_t * boards, uint64_t cardsInGame);
uint32_t getPosibleNBoards(card64_t * boards, card64_t cardsInGame, uint32_t n);

uint32_t getFlush(card64_t playerCards);
uint32_t getStraightFlush(card64_t playerCards);
uint32_t getStraight(card64_t playerCards);
uint32_t getHandValue(card64_t playerCards);

#endif /* FUNC_H_ */
