// Prevent multiple inclusion of this header file
#ifndef __DEFINES_H__
#define __DEFINES_H__

// ---------------- BIT MANIPULATION ----------------

// Set a specific bit (BITPOS) in WORD (other bits remain unchanged)
#define SETBIT(WORD,BITPOS) (WORD|=1<<BITPOS)

// Clear a specific bit (BITPOS) in WORD (other bits remain unchanged)
#define CLRBIT(WORD,BITPOS) (WORD&=~(1<<BITPOS))

// Set only one bit (BITPOS) in WORD by assigning value (overwrites entire WORD)
#define SSETBIT(WORD,BITPOS) (WORD=1<<BITPOS)

// Clear operation intended, but actually assigns same as SSETBIT (overwrites WORD)
// Note: This behaves same as SSETBIT (not true clear operation)
#define SCLRBIT(WORD,BITPOS) (WORD=1<<BITPOS)


// ---------------- WRITE OPERATIONS ----------------

// Write 8-bit value (BYTE) into WORD starting from bit position SBITPOS
// Clears existing 8 bits at that position and inserts new value
#define WBYTE(WORD,SBITPOS,BYTE)\
WORD=(WORD&~(0XFF<<SBITPOS)|(BYTE<<SBITPOS))

// Write 4-bit value (nibble) into WORD starting from bit position SBITPOS
// Clears existing 4 bits and inserts new value
#define WNIBBLE(WORD,SBITPOS,BYTE)\
WORD=(WORD&~(0XF<<SBITPOS)|(BYTE<<SBITPOS))


// ---------------- READ OPERATIONS ----------------

// Read a single bit from WORD at BITPOS (returns 0 or 1)
#define RBIT(WORD,BITPOS) ((WORD>>BITPOS)&1)

// Read 4-bit value (nibble) from WORD starting at SBITPOS (returns 0–15)
#define RNIBBLE(WORD,SBITPOS) ((WORD>>SBITPOS)&15)

#endif
