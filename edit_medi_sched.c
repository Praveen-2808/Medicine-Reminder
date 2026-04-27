#include<lpc214x.h>          // Header file for LPC214x microcontroller registers
#include<lpc21xx.h>          // Header file for LPC21xx microcontroller registers
#include"mini_proj_defines.h" // Project-specific macro definitions
#include"mini_proj.h"        // Project function declarations
#include"lcd.h"              // LCD function declarations
#include"kpm.h"              // Keypad module functions
#include"rtc.h"              // RTC function declarations
#include"types.h"            // Data type definitions (like s32, s8)
#include"delay.h"            // Delay functions

s32 hour,min,sec,date,month,year,day,flag;   // Variables for storing current time/date and control flag
s32 hour1,min1,hour2,min2,hour3,min3,com_sec; // Variables for storing 3 medicine schedule times
s32 target;
s8 ch;                                       // Variable to store keypad input character

extern s32 flag,dly; // External variables (flag reused, dly used for delay loop)

/* Function to handle menu display and comparison of time for medicine reminder */
void menu_comparision_fun()
{
    if(flag) // Check if menu should be displayed
    {
        cmdLCD(0x01);          // Clear LCD
        strLCD("1.Edit");      // Display option 1

        cmdLCD(0xc0);          // Move to second line
        strLCD("2.schedule");  // Display option 2

        cmdLCD(0x80+10);       // Move cursor position
        strLCD("3.Exit");      // Display option 3

        ch = keyscan();        // Read key input
        delay_ms(100);         // Small delay for debounce

        switch(ch)             // Check selected option
        {
            case '1':
                edit();        // Call edit function
                break;

            case '2':
                medi_schedule(); // Call schedule function
                break;

            case '3':
                flag=0;        // Exit menu
                cmdLCD(0x01);  // Clear LCD
                break;

            default:
                cmdLCD(0x01);      // Clear LCD
                strLCD("Invalid Option"); // Show error
                delay_ms(2000);   // Wait 2 seconds
        }
    }

    // Check first medicine schedule
    if((hour1==HOUR)&&(min1==MIN)&&(com_sec==SEC))
    {
        cmdLCD(0x01);              // Clear LCD
        strLCD(" Take Medicine");  // Display message
        cmdLCD(0xc0);              
        strLCD("SW2 for BUZZ OFF");// Instruction to stop buzzer

		// Turn ON buzzer
		IOSET0 = 1 << BUZZER;

		// Initialize delay flag
		dly = 1;

		// Calculate next minute safely (handles 59 ? 0)
		target = (min1 + 1) % 60;

		// Wait until:
		// 1. One minute completes OR
		// 2. User presses interrupt switch (buzz_off_interrupt sets dly = 0)
		while((MIN != target) && dly)
		{
    		delay_s(1);   // Check every second
		}

		// Turn OFF buzzer
		IOCLR0 = 1 << BUZZER;
        cmdLCD(0x01);              // Clear LCD
    }

    // Check second medicine schedule
    else if((hour2==HOUR)&&(min2==MIN)&&(com_sec==SEC))
    {
        cmdLCD(0x01);
        strLCD(" Take Medicine");
        cmdLCD(0xc0);
        strLCD("SW2 for BUZZ OFF");

        // Turn ON buzzer
		IOSET0 = 1 << BUZZER;

		// Initialize delay flag
		dly = 1;

		// Calculate next minute safely (handles 59 ? 0)
		target = (min1 + 1) % 60;

		// Wait until:
		// 1. One minute completes OR
		// 2. User presses interrupt switch (buzz_off_interrupt sets dly = 0)
		while((MIN != target) && dly)
		{
    		delay_s(1);   // Check every second
		}

		// Turn OFF buzzer
		IOCLR0 = 1 << BUZZER;
        cmdLCD(0x01);
    }

    // Check third medicine schedule
    else if((hour3==HOUR)&&(min3==MIN)&&(com_sec==SEC))
    {
        cmdLCD(0x01);
        strLCD(" Take Medicine");
        cmdLCD(0xc0);
        strLCD("SW2 for BUZZ OFF");

        // Turn ON buzzer
		IOSET0 = 1 << BUZZER;

		// Initialize delay flag
		dly = 1;

		// Calculate next minute safely (handles 59 ? 0)
		target = (min1 + 1) % 60;

		// Wait until:
		// 1. One minute completes OR
		// 2. User presses interrupt switch (buzz_off_interrupt sets dly = 0)
		while((MIN != target) && dly)
		{
    		delay_s(1);   // Check every second
		}

		// Turn OFF buzzer
		IOCLR0 = 1 << BUZZER;
        cmdLCD(0x01);
    }
}

/* Function to edit time and date */
void edit()
{
    s32 t1,t2,t3; // Temporary variables to track changes

    while(1) // Infinite loop for menu
    {
        cmdLCD(0x01);            // Clear LCD
        strLCD("1.EditTime");    // Display option

        cmdLCD(0xc0);
        strLCD("2.Edit Date");

        cmdLCD(0x80+10);
        strLCD("3.EXIT");

        ch = keyscan();          // Read key

        switch(ch)
        {
            case '1':
                t1=hour; t2=min; t3=sec; // Backup old time

                while(1)
                {
                    cmdLCD(0x01);
                    strLCD("1.H");
                    strLCD(" 2.M");
                    strLCD(" 3.S");
                    strLCD(" 4.<-");

                    cmdLCD(0xc0);
                    GetRTCTimeInfo(&hour,&min,&sec); // Read RTC time
                    DisplayRTCTime(hour,min,sec);    // Display time

                    ch = keyscan();
                    delay_ms(100);

                    if(ch=='1') // Edit hour
                    {
                        cmdLCD(0x80);
                        strLCD("                "); // Clear line

                        cmdLCD(0x80);
                        strLCD("HOUR");

hour:
                        cmdLCD(0xc0);
                        hour = Readnum(0); // Read hour input

                        if(hour>23) // Validate
                        {
                            cmdLCD(0x01);
                            strLCD("INVALID HOUR");

                            cmdLCD(0xc0);
                            strLCD("Enter Again");

                            delay_ms(2000);

                            cmdLCD(0x01);
                            strLCD("Enter HOUR Again");

                            cmdLCD(0xc0);
                            DisplayRTCTime(hour,min,sec);

                            goto hour; // Retry
                        }
                        else
                        {
                            if(hour!=-1)
                                HOUR = hour; // Update RTC hour
                        }
                    }

                    else if(ch=='2') // Edit minute
                    {
                        cmdLCD(0x80);
                        strLCD("                ");

                        cmdLCD(0x80);
                        strLCD("MINUTE");

min:
                        cmdLCD(0xc0+3);
                        min = Readnum(3);

                        if(min>59)
                        {
                            cmdLCD(0x01);
                            strLCD("INVALID MINUTE");

                            cmdLCD(0xc0);
                            strLCD("Enter Again");

                            delay_ms(2000);

                            cmdLCD(0x01);
                            strLCD("Enter MIN Again");

                            cmdLCD(0xc0);
                            DisplayRTCTime(hour,min,sec);

                            goto min;
                        }
                        else
                        {
                            if(min!=-1)
                                MIN = min;
                        }
                    }

                    else if(ch=='3') // Edit seconds
                    {
                        cmdLCD(0x80);
                        strLCD("                ");

                        cmdLCD(0x80);
                        strLCD("SEC");

sec:
                        cmdLCD(0xc0+6);
                        sec = Readnum(6);

                        if(sec>59)
                        {
                            cmdLCD(0x01);
                            strLCD("INVALID SEC");

                            cmdLCD(0xc0);
                            strLCD("Enter Again");

                            delay_ms(2000);

                            cmdLCD(0x01);
                            strLCD("Enter SEC Again");

                            cmdLCD(0xc0);
                            DisplayRTCTime(hour,min,sec);

                            goto sec;
                        }
                        else
                        {
                            if(sec!=-1)
                                SEC = sec;
                        }
                    }

                    else if(ch=='4') // Exit submenu
                        break;

                    else
                    {
                        cmdLCD(0x01);
                        strLCD("Invalid option");
                        delay_ms(2000);
                    }
                }

                // Check if time changed
                if((t1!=hour)||(t2!=min)||(t3!=sec))
                {
                    cmdLCD(0x01);
                    strLCD("Time updated");
                    delay_s(2);
                    break;
                }
                else break;

            case '2': // Edit date
                t1=date; t2=month; t3=year;

                while(1)
                {
                    cmdLCD(0x01);
                    strLCD("1.D");
                    strLCD(" 2.M");
                    strLCD(" 3.Y");
                    strLCD(" 4.<-");

                    cmdLCD(0xc0);
                    GetRTCDateInfo(&date,&month,&year);
                    DisplayRTCDate(date,month,year);

                    ch = keyscan();
                    delay_ms(100);

                    if(ch=='1') // Edit date
                    {
                        cmdLCD(0x80);
                        strLCD("                ");

                        cmdLCD(0x80);
                        strLCD("DATE");

date:
                        cmdLCD(0xc0);
                        date = Readnum(0);

                        if(date>31||date<=0)
                        {
                            cmdLCD(0x01);
                            strLCD("INVALID DATE");

                            cmdLCD(0xc0);
                            strLCD("Enter Again");

                            delay_ms(2000);

                            cmdLCD(0x01);
                            strLCD("Enter DATE Again");

                            cmdLCD(0xc0);
                            DisplayRTCDate(date,month,year);

                            goto date;
                        }
                        else
                        {
                            if(date!=-1)
                                DOM = date;
                        }
                    }

                    else if(ch=='2') // Edit month
                    {
                        cmdLCD(0x80);
                        strLCD("                ");

                        cmdLCD(0x80);
                        strLCD("MONTH");

month:
                        cmdLCD(0xc0+3);
                        month = Readnum(3);

                        if(month>12||date<=0)
                        {
                            cmdLCD(0x01);
                            strLCD("INVALID MONTH");

                            cmdLCD(0xc0);
                            strLCD("Enter Again");

                            delay_ms(2000);

                            cmdLCD(0x01);
                            strLCD("Enter MONTH Again");

                            cmdLCD(0xc0);
                            DisplayRTCDate(date,month,year);

                            goto month;
                        }
                        else
                        {
                            if(month!=-1)
                                MONTH = month;
                        }
                    }

                    else if(ch=='3') // Edit year
                    {
                        cmdLCD(0x80);
                        strLCD("                ");

                        cmdLCD(0x80);
                        strLCD("YEAR");

year:
                        cmdLCD(0xc0+6);
                        year = Readnum(6);

                        if(year>99||year<=0)
                        {
                            cmdLCD(0x01);
                            strLCD("INVALID YEAR");

                            cmdLCD(0xc0);
                            strLCD("Enter Again");

                            delay_ms(2000);

                            cmdLCD(0x01);
                            strLCD("Enter YEAR Again");

                            cmdLCD(0xc0);
                            DisplayRTCDate(date,month,year);

                            goto year;
                        }
                        else
                        {
                            if(year!=-1)
                                YEAR = year;
                        }
                    }

                    else if(ch=='4')
                        break;

                    else
                    {
                        cmdLCD(0x01);
                        strLCD("Invalid option");
                        delay_ms(2000);
                    }
                }

                // Check if date changed
                if(t1!=date||t2!=month||t3!=year)
                {
                    cmdLCD(0x01);
                    strLCD("Date updated");
                    delay_s(2);
                    break;
                }
                else break;

            case '3':
                return; // Exit edit function

            default:
                cmdLCD(0x01);
                strLCD("Invalid Option");
                delay_ms(2000);
                break;
        }
    }
}

/* Function to set medicine schedule */
void medi_schedule()
{
    while(1)
    {
        cmdLCD(0x01);
        strLCD("1.MORNING");

        cmdLCD(0xc0);
        strLCD("2.NOON");

        cmdLCD(0xc0+7);
        strLCD("3.EVENING");

        cmdLCD(0x80+9);
        strLCD("4.EXIT");

        ch = keyscan();
        delay_ms(100);

        switch(ch)
        {
            case '1': // Morning schedule
                cmdLCD(0x01);
                strLCD("MORNING REMINDER");

                cmdLCD(0xc0);
                charLCD(hour1/10+48); // Display hour tens
                charLCD(hour1%10+48); // Display hour units
                charLCD(':');         // Display colon
                charLCD(min1/10+48);  // Display minute tens
                charLCD(min1%10+48);  // Display minute units

                cmdLCD(0xc0+5);
                strLCD(" *-HR /-MIN");

                rolling_set(&hour1,&min1); // Set values
                break;

            case '2': // Noon schedule
                cmdLCD(0x01);
                strLCD("NOON REMINDER");

                cmdLCD(0xc0);
                charLCD(hour2/10+48);
                charLCD(hour2%10+48);
                charLCD(':');
                charLCD(min2/10+48);
                charLCD(min2%10+48);

                rolling_set(&hour2,&min2);
                break;

            case '3': // Evening schedule
                cmdLCD(0x01);
                strLCD("EVENING REMINDER");

                cmdLCD(0xc0);
                charLCD(hour3/10+48);
                charLCD(hour3%10+48);
                charLCD(':');
                charLCD(min3/10+48);
                charLCD(min3%10+48);

                rolling_set(&hour3,&min3);
                break;

            case '4':
                ch='4'; // Exit flag
                break;

            default:
                cmdLCD(0x01);
                strLCD("Invalid Option");
                delay_ms(2000);
        }

        if(ch=='4') // Exit loop
            break;
    }
}
