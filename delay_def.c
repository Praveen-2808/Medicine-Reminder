// Function to generate delay in microseconds
void delay_us(unsigned int dlyus)
{
    // Multiply input delay by 12 to approximate 1 microsecond delay (based on CPU clock)
    for(dlyus*=12; dlyus>0; dlyus--);  // Empty loop used for delay
}

// Function to generate delay in milliseconds
void delay_ms(unsigned int dlyms)
{
    // Multiply input delay by 12000 to approximate 1 millisecond delay
    for(dlyms*=12000; dlyms>0; dlyms--); // Empty loop used for delay
}

// Function to generate delay in seconds
void delay_s(unsigned int dlys)
{
    // Multiply input delay by 12000000 to approximate 1 second delay
    for(dlys*=12000000; dlys>0; dlys--); // Empty loop used for delay
}
