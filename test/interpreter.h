#include "card64.h"

#ifndef INTERPRETER_H_
#define INTERPRETER_H_


#define PRINT_SUIT_C "\u2663"
#define PRINT_SUIT_D "\u2666"
#define PRINT_SUIT_H "\u2665"
#define PRINT_SUIT_S "\u2660"

/**
 * Convert set of cards presented as string to card64_t.
 */
card64_t getCard64FromString(const char * _card, uint8_t _amount);

/**
 * Convert set of cards presented as card64_t to string.
 */
uint8_t getCard64AsString(card64_t _card64, char * _card, uint8_t _amount);


#endif /* INTERPRETER_H_ */
