#include "types.h"   // Include custom data types (u8, u32, s32, f32)

// Function to write data or command to LCD
// Takes 8-bit data and sends it to LCD interface
void writeLCD(u8 data);

// Function to send command to LCD
// Used for LCD control operations (clear screen, cursor move, etc.)
void cmdLCD(u8 cmd);

// Function to send a single character to LCD
// Displays one ASCII character on LCD
void charLCD(u8 ascii);

// Function to initialize LCD
// Sets LCD mode, configures pins, and prepares display
void InitLCD(void);

// Function to display string on LCD
// Takes pointer to string and prints until null character
void strLCD(s8 *p);

// Function to display unsigned 32-bit integer on LCD
// Converts number to ASCII and prints digit by digit
void U32LCD(u32 n);

// Function to display signed 32-bit integer on LCD
// Handles negative sign and prints number
void s32LCD(s32 n);

// Function to display floating-point number on LCD
// fnum = number, nDP = number of decimal points
void f32LCD(f32 fnum,u8 nDP);

// Function to display hexadecimal number on LCD
// Converts number to hex format (0–9, A–F)
void HEXLCD(u32 n);

// Function to display binary number on LCD
// n = number, nbd = number of bits to display
void BinLCD(u32 n,u8 nbd);

// Function to build custom characters in LCD CGRAM
// p = pointer to pattern, nb = number of bytes
void BuildCGRAM(u8* p,u8 nb);
