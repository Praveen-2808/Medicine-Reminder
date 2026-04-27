// Declaration of interrupt service routine (ISR) for edit functionality
// __irq specifies that this function is an interrupt handler
void edit_interrupt(void) __irq;

// Declaration of ISR to turn off the buzzer
// This function will be triggered by an interrupt
void buzz_off_interrupt(void) __irq;

// Function prototype for initialization routine
// This function initializes all required peripherals (LCD, RTC, keypad, etc.)
void init(void);

// Function prototype for menu comparison logic
// Likely used to compare current time with scheduled medicine time
void menu_comparision_fun(void);

// Function prototype for edit functionality
// Used to modify or set medicine timings
void edit(void);

// Function prototype for medicine scheduling
// Handles storing or managing medicine reminder timings
void medi_schedule(void);