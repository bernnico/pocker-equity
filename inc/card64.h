#ifndef CARDSDEF_H_
#define CARDSDEF_H_

#include <stdint.h>

#define RANKS				13
#define RANK_2				0
#define RANK_3				1
#define RANK_4				2
#define RANK_5				3
#define RANK_6				4
#define RANK_7				5
#define RANK_8				6
#define RANK_9				7
#define RANK_T				8
#define RANK_J				9
#define RANK_Q				10
#define RANK_K				11
#define RANK_A				12

#define SUITS				4
#define SUIT_C				0	// Clubs
#define SUIT_D				1	// Diamonds
#define SUIT_H				2	// Heart
#define SUIT_S				3	// Spades

extern char rank[RANKS];
extern char suit[SUITS];

typedef uint64_t card64_t;

#define ADD_CARD64(_SET, _CARD)						_SET |= _CARD

// Cards data type
#define CARD64_2c									0x01ULL
#define CARD64_Ac									(CARD64_2c << (RANK_A * SUITS))
#define CARD64_Ax(_SUIT)							(CARD64_Ac << _SUIT)
#define CARD64_Xc(_RANK)							(CARD64_2c << (_RANK * SUITS)) // rank 2 := _CARD=0
#define CARD64_Xx(_RANK, _SUIT)						(CARD64_2c << (_RANK * SUITS) << _SUIT)

// All cards of same rank type
#define CARD64_2_MASK								0x0FULL
#define CARD64_A_MASK								(CARD64_2_MASK << (RANK_A * SUITS))
#define CARD64_X_MASK(_RANK)						(CARD64_2_MASK << (_RANK * SUITS))

// All cards of same suit type
#define CARD64_C_MASK								0x01111111111111ULL
#define CARD64_D_MASK								(CARD64_C_MASK << 1)
#define CARD64_H_MASK								(CARD64_C_MASK << 2)
#define CARD64_S_MASK								(CARD64_C_MASK << 3)


/* ********************************************************************************************************* */


/* Winning Hand as 32-Bit */

#define HIT_FLAG32_POSITION							28 // 28th bit => MS(HALFBYTE)
#define HIT_FLAG32_PAIR								0x0UL << HIT_FLAG32_POSITION
#define HIT_FLAG32_TWO_PAIR							0x1UL << HIT_FLAG32_POSITION
#define HIT_FLAG32_THREE_OF_A_KIND					0x2UL << HIT_FLAG32_POSITION
#define HIT_FLAG32_STRAIGHT							0x3UL << HIT_FLAG32_POSITION
#define HIT_FLAG32_FLUSH							0x4UL << HIT_FLAG32_POSITION
#define HIT_FLAG32_FULL_HOUSE						0x5UL << HIT_FLAG32_POSITION
#define HIT_FLAG32_FOUR_OF_A_KIND					0x6UL << HIT_FLAG32_POSITION
#define HIT_FLAG32_STRAIGHT_FLUSH					0x7UL << HIT_FLAG32_POSITION

// 32-Bit => 0x CF SP Th hh

#define WIN32_SET_HIGH_CARDS(_RANK_VALUE)			(uint32_t) _RANK_VALUE << (0 << 2)
#define WIN32_SET_SECOND_PAIR(_RANK_VALUE)			(uint32_t) _RANK_VALUE << (3 << 2)
#define WIN32_SET_FIRST_PAIR(_RANK_VALUE)			(uint32_t) _RANK_VALUE << (4 << 2)
#define WIN32_SET_THREE_OF_KIND(_RANK_VALUE)		(uint32_t) _RANK_VALUE << (5 << 2)
#define WIN32_SET_FOUR_OF_KIND(_RANK_VALUE)			(uint32_t) _RANK_VALUE << (6 << 2)

#endif /* CARDSDEF_H_ */
