/*
 Authors: Nikita Eisenhauer and Warren Seto
 Experiment: 8
 */

#include <project.h>

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    char* quoteString = "To each his own";
    
    /* Initialize the PSoC's Serial Connection */
    UART_1_Start();
    
    /* Initialize the PSoC's LCD */
	LCD_Char_1_Start();
	LCD_Char_1_Position(0,0);
	
    /* Local variables to control the state of the PSoC's output */
    int stringIndex = 0;
    char currentChar;
    
    /* Infinite loop to continuously send and receive characters */
    while(1)
	{
        /* Send the String through the PSoC's Serial Port */
        UART_1_PutString(quoteString);
        
        /* Get input from Tera term */
        CyDelay(500);
        currentChar = UART_1_GetChar();
		
        /* Update the LCD based on the character input */
        if (currentChar)
        {
            if (stringIndex)
            {
                LCD_Char_1_ClearDisplay();
            }
			
            /* Show additional characters from Tera term */
            LCD_Char_1_PutChar(currentChar);
            stringIndex++;
            
            if (stringIndex == 8)
            {
                LCD_Char_1_Position(0,0);
                stringIndex = 0;
            }
		}	
	}	
}
