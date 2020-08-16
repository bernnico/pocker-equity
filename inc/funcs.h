#ifndef FUNC_H_
#define FUNC_H_

#include <time.h>
#include <stdlib.h>

#include "card64.h"

uint64_t getRandomCards64(uint8_t numbersOfCards, uint64_t cardsInGame);

void getPosibleBoards(uint64_t * boards, uint64_t cardsInGame);

uint32_t getFlush(uint64_t playerCards);
uint32_t getStraightFlush(uint32_t playerCards);
uint32_t getStraight(uint64_t playerCards);
uint32_t getHandValue(uint64_t playerCards);

#endif /* FUNC_H_ */
