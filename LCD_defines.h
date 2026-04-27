// Define starting bit position for LCD data pins (P0.8–P0.15)
#define LCD_DATA 8

// Define pin number for RS (Register Select) control (P0.16)
#define RS 16

// Define pin number for RW (Read/Write) control (P0.18)
#define RW 18

// Define pin number for EN (Enable) control (P0.17)
#define EN 17

// ---------------- LCD COMMANDS ----------------

// Command to clear entire LCD display
#define CLEAR_LCD 0X01

// Command to return cursor to home position (0,0)
#define RET_CUR_HOME 0X02

// Command to turn OFF display
#define DISP_OFF 0X08

// Command to turn ON display (cursor OFF)
#define DISP_ON 0X0C

// Command to turn ON display with cursor visible
#define DISP_ON_CUR_ON 0X0E

// Command to turn ON display with blinking cursor
#define DISP_ON_CUR_BLINK 0X0F

// Command to set LCD in 8-bit mode with 1 display line
#define MODE_8BIT_1LINE 0X30

// Command to set LCD in 8-bit mode with 2 display lines
#define MODE_8BIT_2LINE 0X38

// Command to set LCD in 4-bit mode with 1 display line
#define MODE_4BIT_1LINE 0X20

// Command to set LCD in 4-bit mode with 2 display lines
#define MODE_4BIT_2LINE 0X28

// Command to move cursor to line 1, position 0
#define GOTO_LINE1_POS0 0X80

// Command to move cursor to line 2, position 0
#define GOTO_LINE2_POS0 0XC0

// Command to move cursor to line 3, position 0 (for larger LCDs)
#define GOTO_LINE3_POS0 0X94

// Command to move cursor to line 4, position 0 (for larger LCDs)
#define GOTO_LINE4_POS0 0XD4

// Command to shift cursor to the right
#define SHIFT_CUR_RIGHT 0X06

// Command to shift entire display to the left
#define SHIFT_DISP_LEFT 0X10

// Command to shift entire display to the right
#define SHIFT_DISP_RIGHT 0X14

// Command to set CGRAM address (used for custom characters)
#define GOTO_CGRAM 0X40
