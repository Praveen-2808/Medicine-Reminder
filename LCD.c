#include "lpc21xx.h"      // LPC21xx register definitions
#include "LCD_defines.h"  // LCD pin and command definitions
#include "defines.h"      // General macros (bit operations like SETBIT, CLRBIT)
#include "delay.h"        // Delay functions
#include "types.h"        // Custom data types (u8, u32, s32, f32)

/* Function to write data/command to LCD */
void writeLCD(u8 data)
{
	SCLRBIT(IOCLR0,RW);      // Clear RW bit ? set RW=0 (write operation)
	WBYTE(IOPIN0,LCD_DATA,data); // Write 8-bit data to LCD data pins
	SSETBIT(IOSET0,EN);      // Set EN pin ? enable signal high
	delay_us(1);             // Small delay for enable pulse
	SCLRBIT(IOCLR0,EN);      // Clear EN pin ? latch data into LCD
	delay_ms(2);             // Delay for LCD internal processing
}

/* Function to send command to LCD */
void cmdLCD(u8 cmd)
{
	SCLRBIT(IOCLR0,RS);      // RS=0 ? select command register
	writeLCD(cmd);           // Send command to LCD
}

/* Function to send character to LCD */
void charLCD(u8 ascii)
{
	SSETBIT(IOSET0,RS);      // RS=1 ? select data register
	writeLCD(ascii);         // Send ASCII character to LCD
}

/* Function to initialize LCD */
void InitLCD()
{
	WBYTE(IODIR0,LCD_DATA,255); // Configure LCD data pins as output (8-bit mode)
	SETBIT(IODIR0,RS);          // Set RS pin as output (P0.16)
	SETBIT(IODIR0,RW);          // Set RW pin as output (P0.17)
	SETBIT(IODIR0,EN);          // Set EN pin as output (P0.18)
	
	delay_ms(15);               // Initial power-on delay

	cmdLCD(MODE_8BIT_1LINE);    // Function set: 8-bit mode, 1-line
	delay_ms(5);                // Delay

	cmdLCD(MODE_8BIT_1LINE);    // Repeat command (LCD init sequence)
	delay_ms(100);              // Delay

	cmdLCD(MODE_8BIT_1LINE);    // Repeat again for proper initialization
	cmdLCD(MODE_8BIT_2LINE);    // Set 2-line display mode
	cmdLCD(DISP_ON);            // Turn ON display

//	cmdLCD(SHIFT_CUR_RIGHT);  // (Optional) Shift cursor right (commented)
}

/* Function to display string on LCD */
void strLCD(s8 *p)
{
	while(*p)                  // Loop until null character
		charLCD(*p++);         // Display character and move pointer
}

/* Function to display unsigned 32-bit integer */
void U32LCD(u32 n)
{
	u8 a[10];                 // Array to store digits
	s32 i=0;                  // Index variable

	if(n==0)                  // If number is zero
	{
		charLCD('0');        // Display '0'
	}
	else 
	{
		while(n)             // Extract digits
		{
			a[i++]=(n%10)+48; // Convert digit to ASCII and store
			n/=10;            // Remove last digit
		}
		for(--i;i>=0;i--)    // Reverse and print digits
			charLCD(a[i]);
	}
}

/* Function to display signed 32-bit integer */
void s32LCD(s32 n)
{
	if(n<0)                  // If number is negative
	{
		charLCD('-');       // Display minus sign
		n=-n;               // Convert to positive
		U32LCD(n);          // Display number using unsigned function
	}
}

/* Function to display floating-point number */
void f32LCD(f32 fnum,u8 nDP)
{
	u32 n;                  // Integer part
	s32 i;                  // Loop variable

	if(fnum<0)              // Check if negative
	{
		charLCD('-');       // Display minus sign
	}

	n=fnum;                 // Extract integer part
	U32LCD(n);              // Display integer part

	for(i=0;i<nDP;i++)      // Loop for decimal places
	{
		fnum=(fnum-n)*10;   // Shift decimal digit
		n=fnum;             // Extract digit
		charLCD(n);         // Display digit
	}
}

/* Function to display hexadecimal value */
void HEXLCD(u32 n)
{
	u8 a[8],rem;            // Array for digits, remainder variable
	s32 i=0;                // Index

	if(n==0)                // If zero
	{
		charLCD('0');      // Display '0'
	}
	else
	{
		while(n)           // Extract hex digits
		{
			rem=n%16;      // Get remainder
			(rem<10)?(rem+=48):(rem+=55); // Convert to ASCII (0-9 / A-F)
			a[i++]=rem;    // Store digit
			n/=16;         // Divide by 16
		}
		for(--i;i>=0;i--)  // Print in reverse order
		{
			charLCD(a[i]);
		}
	}
}

/* Function to display binary value */
void BinLCD(u32 n,u8 nbd)
{
	s32 i;                  // Loop variable

	for(i=(nbd-1);i>=0;i--) // Loop from MSB to LSB
	{
		charLCD(((n>>i)&1)+48); // Extract bit and convert to ASCII
	}
}

/* Function to build custom character in CGRAM */
void BuildCGRAM(u8* p,u8 nb)
{
	s32 i;                  // Loop variable

	cmdLCD(GOTO_CGRAM);     // Set address to CGRAM

	for(i=0;i<=nb;i++)      // Write pattern bytes
	{
		charLCD(p[i]);      // Send each byte to LCD
	}

	cmdLCD(GOTO_LINE1_POS0); // Return cursor to first line position 0
}
