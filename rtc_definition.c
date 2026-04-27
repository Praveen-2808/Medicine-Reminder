#include <lpc214x.h>        // Header file for LPC214x microcontroller register definitions
#include"rtc_defines.h"    // RTC register and macro definitions
#include"types.h"          // Custom data types like u32, s32
#include"lcd.h"            // LCD function declarations

// Array to hold names of days of the week (3-letter format + null terminator)
char week[][4] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};

/*

Initialize the Real-Time Clock (RTC)

This function disables the RTC, sets the prescaler values, 

and then enables the RTC.

*/

void RTC_Init(void) 
{
        
  // Disable and reset the RTC using control register
  CCR=RTC_RESET;

#ifndef _LPC2148           // Check if the target is NOT LPC2148

  // Set prescaler integer part for RTC timing
  PREINT=PREINT_VAL;

  // Set prescaler fractional part for RTC timing
  PREFRAC=PREFRAC_VAL;

  // Enable the RTC after configuration
  CCR=RTC_ENABLE;

#else                     // If the target is LPC2148

  // Enable RTC using external clock source
  CCR=RTC_ENABLE|RTC_CLKSRC;

#endif                    // End of conditional compilation
}


/*

Get the current RTC time

hour Pointer to store the current hour

minute Pointer to store the current minute

second Pointer to store the current second

*/

void GetRTCTimeInfo(s32 *hour, s32 *minute, s32 *second)
{
  *hour=HOUR;     // Read current hour from RTC register and store in pointer
  *minute=MIN;    // Read current minute from RTC register and store in pointer
  *second=SEC;    // Read current second from RTC register and store in pointer
}


/*

Display the RTC time on LCD

hour value (0-23)

minute value (0-59)

second value (0-59) seperated by ':'

*/

void DisplayRTCTime(u32 hour, u32 minute, u32 second)
{
  // cmdLCD(0x80);         // (Commented) Would set cursor to first line

  charLCD(hour/10+48);    // Display tens digit of hour (convert to ASCII)
  charLCD(hour%10+48);    // Display units digit of hour

  charLCD(':');           // Display colon separator

  charLCD(minute/10+48);  // Display tens digit of minute
  charLCD(minute%10+48);  // Display units digit of minute

  charLCD(':');           // Display colon separator

  charLCD(second/10+48);  // Display tens digit of second
  charLCD(second%10+48);  // Display units digit of second
}


/*

Get the current RTC date

day Pointer to store the current date (1-31)

month Pointer to store the current month (1-12)

year Pointer to store the current year (four digits)

*/

void GetRTCDateInfo(s32 *day, s32 *month, s32 *year)
{
  *day=DOM;       // Read day of month from RTC register
  *month=MONTH;   // Read month from RTC register
  *year=YEAR;     // Read year from RTC register
}


/*

Display the RTC date on LCD

Day of month (1-31)

Month (1-12)

Year (four digits) and seperated by '/'

*/

void DisplayRTCDate(u32 day, u32 month, u32 year)
{
  cmdLCD(0xc0);            // Move cursor to second line of LCD

  charLCD(day/10+48);      // Display tens digit of day
  charLCD(day%10+48);      // Display units digit of day

  charLCD('/');            // Display separator

  charLCD(month/10+48);    // Display tens digit of month
  charLCD(month%10+48);    // Display units digit of month

  charLCD('/');            // Display separator

  charLCD(year/10+48);     // Display tens digit of year (2-digit format assumed)
  charLCD(year%10+48);     // Display units digit of year
}


/*

Set the RTC time

Hour to set (0-23)

Minute to set (0-59)

Second to set (0-59)

*/

void SetRTCTimeInfo(u32 hour, u32 minute, u32 second)
{
  HOUR=hour;     // Set RTC hour register
  MIN=minute;    // Set RTC minute register
  SEC=second;    // Set RTC second register
}


/*

Set the RTC date

day of month to set (1-31)

month to set (1-12)

year to set (four digits)

*/

void SetRTCDateInfo(u32 day, u32 month, u32 year)
{
  DOM=day;       // Set day of month register
  MONTH=month;   // Set month register
  YEAR=year;     // Set year register
}


/*

Get the current day of the week

dow Pointer to store Day of Week (0=Sunday, ..., 6=Saturday)

*/

void GetRTCDay(s32 *dow)
{
  *dow=DOW;      // Read day of week from RTC register
}


/*

Display the current day of the week on LCD

dow (Day of Week) (0=Sunday, ..., 6=Saturday)

*/

void DisplayRTCDay(u32 dow)
{
  cmdLCD(0x80+10);   // Move cursor to specific position on first line
  strLCD(week[dow]); // Display corresponding weekday string from array
}

/*

Set the day of the week in RTC

Day of Week to set (0=Sunday, ..., 6=Saturday)

*/

void SetRTCDay(u32 dow)
{
  DOW=dow;     // Set RTC day-of-week register
}