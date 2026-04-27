#include "types.h"        // Custom data types (u8, u32, s32, etc.)
#include "defines.h"      // General macros (bit operations)
#include <lpc21xx.h>      // LPC21xx register definitions
#include "kpm_defines.h"  // Keypad pin definitions
#include "lcd.h"          // LCD functions
#include"delay.h"         // Delay functions

// Keypad lookup table mapping row-column to actual key values
u8 kpmLUT[4][4]={{'7','8','9','/'},   // Row 0
                  {'4','5','6','*'},   // Row 1
                  {'1','2','3','-'},   // Row 2
                  {'C','0','=','+'}};  // Row 3

// Initialize keypad by configuring row pins as output
void Initkpm()
{
        WNIBBLE(IODIR1,ROW0,15);   // Set lower 4 bits (rows) of Port1 as output
}

// Function to scan columns
u32 colscan()
{
        // Read column pins and check if any key is pressed
        return (RNIBBLE(IOPIN1,COL0)<15?0:1); // Return 0 if key pressed, else 1
}

// Function to identify which row is active
u32 Rowcheck()
{
        u32 rno;   // Variable to store row number

        for(rno=0;rno<4;rno++) // Loop through rows
        {
                WNIBBLE(IOPIN1,ROW0,~(1<<rno)); // Activate one row at a time

                if(colscan()==0) // If key press detected
                {
                        break;   // Exit loop with current row number
                }
        }

        // Restore rows to default state (all high)
        WNIBBLE(IOPIN1,ROW0,0X0);

        return rno; // Return detected row number
}

// Function to identify which column is active
u32 Colcheck()
{
        u32 cno;   // Variable to store column number

        for(cno=0;cno<4;cno++) // Loop through columns
        {
                if(RBIT(IOPIN1,(COL0+cno))==0) // If column line is low (pressed)
                {
                        break; // Exit loop with column number
                }
        }

        return cno; // Return detected column number
}

// Function to scan keypad and return pressed key
u8 keyscan()
{
        u32 rno,cno; // Variables for row and column
        u8 keyv;     // Variable to store key value

        while(colscan()); // Wait until a key is pressed

        rno=Rowcheck();   // Get row number
        cno=Colcheck();   // Get column number

        keyv=kpmLUT[rno][cno]; // Fetch corresponding key from lookup table

        while(!colscan()); // Wait until key is released

        return keyv; // Return key value
}

// Function to read numeric input from keypad
s32 Readnum(s32 pos)
{
        u8 key;         // Variable to store pressed key
        u32 sum=0;      // Variable to store final number
        s32 cnt=0;      // Counter for number of digits

        while(1)        // Infinite loop for input
        {
                key=keyscan();   // Read key
                delay_ms(100);   // Debounce delay

                // If numeric key (0–9) and digit count < 2
                if((key>='0'&&key<='9')&&cnt!=2)
                {
                        cnt++;   // Increment digit count

                        sum=(sum*10)+key-'0'; // Convert ASCII to number and append

                        cmdLCD(0xc0+pos);     // Move cursor to given position

                        charLCD(sum/10+48);   // Display tens digit
                        charLCD(sum%10+48);   // Display units digit
                }

                // If 'C' pressed (clear last digit)
                else if((key=='C')&&cnt!=0)
                {
                        sum/=10; // Remove last digit

                        cmdLCD(0xc0+pos);     // Move cursor

                        charLCD(sum/10+48);   // Update display
                        charLCD(sum%10+48);

                        --cnt;   // Decrement digit count
                }

                // If '=' pressed (confirm input)
                else if(key=='=')
                {
                        if(cnt!=0)
                                return sum;  // Return entered number
                        else 
                                return -1;   // Invalid input
                }

                // If '*' pressed (cancel)
                else if(key=='*')
                {
                        return -1; // Return invalid
                }
        }
}

// Function to set hour and minute using keypad scrolling
void rolling_set(s32 *hour,s32 *min)
{
        s32 flag=-1; // Flag to select hour or minute
        u8 key;      // Variable to store key input

        while(1)     // Infinite loop
        {
                key=keyscan();   // Read key
                delay_ms(100);   // Debounce delay

                if(key=='*')     // Select hour editing
                {
                        flag=0;

                        cmdLCD(0x01);       // Clear LCD
                        strLCD("HOUR");     // Display label

                        cmdLCD(0xc0);       // Move cursor

                        charLCD(*hour/10+48);
                        charLCD(*hour%10+48);
                        charLCD(':');
                        charLCD(*min/10+48);
                        charLCD(*min%10+48);

                        cmdLCD(0x80+4);
                        strLCD(" +-scroll UP");

                        cmdLCD(0xc0+5);
                        strLCD("--scroll DW");
                }

                else if(key=='/') // Select minute editing
                {
                        flag=1;

                        cmdLCD(0x01);
                        strLCD("MIN");

                        cmdLCD(0xc0);

                        charLCD(*hour/10+48);
                        charLCD(*hour%10+48);
                        charLCD(':');
                        charLCD(*min/10+48);
                        charLCD(*min%10+48); 

                        cmdLCD(0x80+4);
                        strLCD(" +-scroll UP");

                        cmdLCD(0xc0+5);
                        strLCD("--scroll DW");
                }

                // Increment hour or minute
                if(key=='+')
                {
                        if(flag==0)
                        {
                                (*hour)++;        // Increase hour
                                if(*hour>23)      // Wrap around
                                        *hour=0;
                        }
                        else if(flag==1)
                        {
                                (*min)++;         // Increase minute
                                if(*min>59)
                                        *min=0;
                        }

                        cmdLCD(0xc0); // Update display

                        charLCD(*hour/10+48);
                        charLCD(*hour%10+48);
                        charLCD(':');
                        charLCD(*min/10+48);
                        charLCD(*min%10+48);
                }

                // Decrement hour or minute
                else if(key=='-')
                {
                        if(flag==0)
                        {
                                (*hour)--;        // Decrease hour
                                if(*hour<0)
                                        *hour=23;
                        }
                        else if(flag==1)
                        {
                                (*min)--;         // Decrease minute
                                if(*min<0)
                                        *min=59;
                        }

                        cmdLCD(0xc0); // Update display

                        charLCD(*hour/10+48);
                        charLCD(*hour%10+48);
                        charLCD(':');
                        charLCD(*min/10+48);
                        charLCD(*min%10+48);
                }

                else if(key=='=') // Confirm selection
                        break;

                else if(key=='C') // Cancel
                        break;
        }
}
