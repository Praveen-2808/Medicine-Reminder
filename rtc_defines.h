// ---------------- System Clock and Peripheral Clock Macros ----------------

// Define main oscillator frequency (12 MHz crystal)
#define FOSC  (12000000)

// Define CPU clock (CCLK) = FOSC × PLL multiplier (5 ? 60 MHz)
#define CCLK  (FOSC*5)   

// Define peripheral clock (PCLK) = CCLK / 4 (default divider ? 15 MHz)
#define PCLK  (CCLK/4)


// ---------------- RTC Prescaler Calculation Macros ----------------

// RTC requires 32.768 kHz clock for accurate 1-second increment

// PREINT and PREFRAC are used to divide PCLK to 32.768 kHz


// Formula: PREINT = integer part of (PCLK / 32768) - 1


// Formula: PREFRAC = PCLK - ((PREINT + 1) * 32768)

// Note: This information collected from LPC2129 Manual


// Calculate integer prescaler value
#define PREINT_VAL       (PCLK/32768)-1

// Calculate fractional prescaler value
#define PREFRAC_VAL  (PCLK-(PREINT_VAL+1)*32768)


// ---------------- RTC Control Register (CCR) Bit Definitions ----------------

// Bit 0: Clock Enable
// 1 ? Enable RTC counters
// 0 ? Disable RTC counters
#define RTC_ENABLE    (1<<0) 


// Bit 1: Clock Reset
// 1 ? Reset RTC counters
// 0 ? Normal operation
#define RTC_RESET          (1<<1)

  
// ---------------- Only for LPC2148 ----------------

// Bit 4: Clock Source Select
// 1 ? Use external 32.768 kHz oscillator
// 0 ? Use internal PCLK as RTC clock source
#define RTC_CLKSRC     (1<<4)

//#define _LPC2148   // Uncomment this line if using LPC2148 MCU


// ---------------- Day of Week Definitions ----------------

// Sunday ? 0
#define SUN 0

// Monday ? 1
#define MON 1

// Tuesday ? 2
#define TUE 2

// Wednesday ? 3
#define WED 3

// Thursday ? 4
#define THU 4

// Friday ? 5
#define FRI 5

// Saturday ? 6
#define SAT 6
