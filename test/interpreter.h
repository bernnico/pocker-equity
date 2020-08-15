#include <card64.h>

#ifndef INTERPRETER_H_
#define INTERPRETER_H_



/**
 * Convert set of cards presented as string to card64_t.
 */
card64_t getCard64FromString(const char * _card, uint8_t _amount);
const char * getCard64AsString(card64_t _card);


#endif /* INTERPRETER_H_ */
