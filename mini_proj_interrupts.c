#include<lpc21xx.h>   // Header file for LPC21xx microcontroller register definitions
#include"mini_proj.h" // Header file containing function declarations for the project
#include"types.h"     // Header file for custom data types (like s32)

// Global variables used across interrupt routines
s32 flag,dly;         // 'flag' used to trigger menu, 'dly' used for delay control

// Interrupt Service Routine (ISR) for edit interrupt (EINT0)
void edit_interrupt() __irq
{
    flag=1;           // Set flag to 1 to indicate edit/menu should be activated

    EXTINT=1<<0;      // Clear EINT0 interrupt flag by writing 1 to bit 0

    VICVectAddr=0;    // Acknowledge interrupt completion to VIC (end of ISR)
}

// Interrupt Service Routine (ISR) for buzzer OFF interrupt (EINT1)
void buzz_off_interrupt() __irq
{
    dly=0;            // Set delay variable to 0 to stop buzzer delay loop immediately

    EXTINT=1<<1;      // Clear EINT1 interrupt flag by writing 1 to bit 1

    VICVectAddr=0;    // Acknowledge interrupt completion to VIC (end of ISR)
}
