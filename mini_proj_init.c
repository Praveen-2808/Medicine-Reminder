#include<lpc21xx.h>            // Header file for LPC21xx microcontroller register definitions
#include"mini_proj_defines.h" // Header file containing project-specific macros (like EINT, BUZZER)
#include"rtc_defines.h"       // Header file for RTC-related definitions
#include"rtc.h"               // Header file for RTC functions
#include"lcd.h"               // Header file for LCD functions
#include"kpm.h"               // Header file for keypad module functions
#include"mini_proj.h"         // Header file for project function declarations

void init()
{
    InitLCD();                // Initialize the LCD display
    RTC_Init();               // Initialize the Real Time Clock module
    Initkpm();                // Initialize keypad module

    // Clear bits related to EINT0 and EINT1 pin configuration in PINSEL0
    PINSEL0 &= ((u32)~3<<2)|((u32)~3<<6);

    // Configure pins as EINT0 and EINT1 using predefined macros
    PINSEL0 = EINT0_IP_PIN | EINT1_IP_PIN;

    // VICIntSelect=0;        // (Default) All interrupts are configured as IRQ (not FIQ)

    // Enable interrupts for EINT0 and EINT1 in VIC
    VICIntEnable = 1<<EINT0_VIC_CHNO | 1<<EINT1_VIC_CHNO;

    // Configure vector control register 0 for EINT0 interrupt
    VICVectCntl0 = (1<<5) | EINT0_VIC_CHNO;

    // Assign ISR (Interrupt Service Routine) address for EINT0
    VICVectAddr0 = (u32) edit_interrupt;

    // Configure vector control register 1 for EINT1 interrupt
    VICVectCntl1 = (1<<5) | EINT1_VIC_CHNO;

    // Assign ISR address for EINT1
    VICVectAddr1 = (u32) buzz_off_interrupt;

    // EXTINT=0;              // (Default) Clears external interrupt flags

    // Configure EINT0 and EINT1 as edge-triggered interrupts
    EXTMODE = (1<<1)|(1<<0);

    // EXTPOLAR=0;           // (Default) Interrupts triggered on falling edge

    // Set BUZZER pin as output
    IODIR0 |= 1<<BUZZER;

    // Set initial RTC time: (seconds, minutes, hours)
    SetRTCTimeInfo(0,8,55);

    // Set initial RTC date: (year, month, day)
    SetRTCDateInfo(23,5,26);

    // Set day of the week (Monday)
    SetRTCDay(MON);
}