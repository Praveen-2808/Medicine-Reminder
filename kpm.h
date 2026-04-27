#include "types.h"   // Include custom data types (u32, s32, etc.)

// Function prototype to initialize keypad module
// Configures row and column pins for keypad operation
void Initkpm(void);

// Function prototype to scan keypad columns
// Returns 0 if a key is pressed, otherwise returns 1
u32 colscan(void);

// Function prototype to identify which row is active
// Returns row number (0–3) where key is pressed
u32 Rowcheck(void);

// Function prototype to identify which column is active
// Returns column number (0–3) where key is pressed
u32 Colcheck(void);

// Function prototype to scan keypad and return pressed key value
// Uses row and column detection along with lookup table
u8 keyscan(void);

// Function prototype to read numeric input from keypad
// Takes LCD position as input and returns entered number
s32 Readnum(s32 );

// Function prototype to set hour and minute using keypad
// Uses pointer to modify hour and minute values directly
void rolling_set(s32 *,s32 *);
