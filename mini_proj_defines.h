// Defining pin configuration value for External Interrupt 0 (EINT0)
// This value is used to configure the specific pin as EINT0 function
#define EINT0_IP_PIN 0x0000000C

// Defining pin configuration value for External Interrupt 1 (EINT1)
// This value sets the corresponding pin to act as EINT1
#define EINT1_IP_PIN 0x000000CC

// Defining the VIC (Vectored Interrupt Controller) channel number for EINT0
// This tells the controller which interrupt line corresponds to EINT0
#define EINT0_VIC_CHNO 14

// Defining the VIC channel number for EINT1
// Used to register and handle EINT1 interrupt in the VIC
#define EINT1_VIC_CHNO 15

// Defining the pin number connected to the buzzer
// This will be used to control (ON/OFF) the buzzer in the program
#define BUZZER 5