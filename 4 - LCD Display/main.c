/*
 Developer : Warren Seto
 Experiment: 4
 */

#include <project.h>

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */

char* quoteString = "To\n";
	
	// Local variablers to control the state of the PSoC's output
	int stringIndex = 0;
	char currentChar;
	
	// Init
	UART_1_Start();
	LCD_Char_1_Start();
	
	LCD_Char_1_Position(0,0);
	
	while(1)
	{
        UART_1_PutString(quoteString);
        CyDelay(10);
		currentChar = UART_1_GetChar();
		
		if (currentChar)
		{
			if (stringIndex)
			{
				LCD_Char_1_ClearDisplay();			
			}
			
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

/* [] END OF FILE */
