#include"types.h"  // Include custom data type definitions (like u32, s32)

// Function prototype to initialize the Real-Time Clock (RTC)
void RTC_Init(void);

// Function prototype to get current RTC time
// Takes pointers to store hour, minute, and second values
void GetRTCTimeInfo(s32 *,s32 *,s32 *);

// Function prototype to display time on LCD
// Takes hour, minute, and second as input
void DisplayRTCTime(u32,u32,u32);

// Function prototype to get current RTC date
// Takes pointers to store day, month, and year values
void GetRTCDateInfo(s32 *,s32 *,s32 *);

// Function prototype to display date on LCD
// Takes day, month, and year as input
void DisplayRTCDate(u32,u32,u32);

// Function prototype to set RTC time
// Takes hour, minute, and second values to update RTC
void SetRTCTimeInfo(u32,u32,u32);

// Function prototype to set RTC date
// Takes day, month, and year values to update RTC
void SetRTCDateInfo(u32,u32,u32);

// Function prototype to get day of week from RTC
// Takes pointer to store day (0–6)
void GetRTCDay(s32 *);

// Function prototype to display day of week on LCD
// Takes day value (0–6)
void DisplayRTCDay(u32);

// Function prototype to set day of week in RTC
// Takes day value (0–6)
void SetRTCDay(u32);