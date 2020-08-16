#include "interpreter.h"



card64_t getCard64FromString(const char * _card, uint8_t _amount) {
	if (_amount < 1 || _amount > 52 || *(_card + 2*_amount) != 0) return 0;

	card64_t ret = 0;
	card64_t temp = 0;

	int i;
	while (*_card != 0) {
		for ( i = 0; i < RANKS; i++ ) {
			if (*_card == rank[i]) {
				temp = CARD64_Xs(i);
				break;
			}
		}
		if (i == RANKS) return 0xFFULL << 56;
		_card++;

		for ( i = 0; i < SUITS; i++ ) {
			if (*_card == suit[i]) {
				ret |= temp << i;
				break;
			}
		}
		if (i == SUITS) return 0xFFULL << 56;
		_card++;
	}

	return ret;
}

uint8_t getCard64AsString(card64_t _card64, char * _card, uint8_t _amount) {
	if (_card64 == 0 || _amount < 1 || _amount > RANKS*SUITS) return 0;

	for (int i = 0; i < RANKS*SUITS; i++) {
		if (_card64 & CARD64_Ax(SUIT_C) >> i) {
			*_card = rank[ (RANKS*SUITS-i-1) / SUITS ];
			_card++;
			*_card = suit[ (RANKS*SUITS-i-1) % SUITS ];
			_card++;
		}
	}
	*_card = '\0';

	return 1;
}












