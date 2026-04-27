#include"mini_proj_defines.h"  // Contains macros for interrupts, buzzer, etc.
#include"mini_proj.h"          // Contains function declarations (init, menu, etc.)
#include"lcd.h"                // LCD interface functions
#include"rtc.h"                // RTC interface functions

// Variables to store current RTC time and date values
s32 hour,min,sec,date,month,year,day;

int main()
{
        init();  // Initialize peripherals: LCD, RTC, keypad, interrupts

        while(1) // Super loop: runs continuously in embedded systems
        {
            // ----------- TIME DISPLAY -----------
            GetRTCTimeInfo(&hour,&min,&sec); // Read current time from RTC registers

            cmdLCD(0x80);                   // Set LCD cursor to first line (address 0x80)
            DisplayRTCTime(hour,min,sec);   // Display time in HH:MM:SS format

            // ----------- DATE DISPLAY -----------
            GetRTCDateInfo(&date,&month,&year); // Read current date from RTC
            DisplayRTCDate(date,month,year);    // Display date in DD/MM/YY format

            // ----------- DAY DISPLAY -----------
            GetRTCDay(&day);               // Read day of week (0–6)
            DisplayRTCDay(day);            // Display corresponding day string (SUN–SAT)

            // ----------- MENU + MEDICINE LOGIC -----------
            // Handles:
            // 1. User menu interaction (edit / schedule)
            // 2. Time comparison for medicine reminder
            // 3. Buzzer triggering when time matches
            menu_comparision_fun();
        }
}
