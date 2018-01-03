/*
 Developer : Warren Seto
 Experiment: 5
 */

#include <project.h>
#include <stdio.h>

/* Helper method to properly display text on the LCD */
void displayOnLCD(char8* string1, char8* string2)
{
    LCD_Char_1_Position(0u, 0u);
    LCD_Char_1_PrintString("               ");
    LCD_Char_1_Position(0u, 0u);
    LCD_Char_1_PrintString(string1);
    
    
    LCD_Char_1_Position(1u, 0u);
    LCD_Char_1_PrintString("               ");
    LCD_Char_1_Position(1u, 0u);
    LCD_Char_1_PrintString(string2);
}

/* Part One: Display an initialization message */
void firstStart1()
{
    displayOnLCD("My First", "Microcontroller");
    CyDelay(2000);
    displayOnLCD("I/O Console", "Program");
    CyDelay(2000);
    displayOnLCD("Microcontroller", "Programmer");
    CyDelay(2000);
    displayOnLCD("Press a switch", "to continue...");
}

/* Part Two: Start up procedures include a greeting and button prompting */
void firstStart2()
{
    /* Light up LEDs (1) */
    Pin_1_Write(1);   
    Pin_2_Write(1); 
    
    /* Greeting message (2) */
    displayOnLCD("Hello! I am", "friendy!");
    CyDelay(3000);
    displayOnLCD("Try pressing my", "left button...");
    
    /* Wait for action (4) */
    while (Pin_3_Read()) {}
    Pin_1_Write(0);   
    Pin_2_Write(0); 

    /* Verify (5) */
    displayOnLCD("Nice. I felt", "that press!");
    CyDelay(3000);
    
    /* Instruct */
    displayOnLCD("Press either", "button to light");
    CyDelay(3000);
    displayOnLCD("up my left LED", "or right LED...");
    CyDelay(3000);
}


int main()
{
    // Part Two
    
    CyGlobalIntEnable;
    
    LCD_Char_1_Start();

    firstStart2();
    
    displayOnLCD("Try and press", "either button!");
    
    
    uint8_t volatile leftLEDState = 0;
    uint8_t volatile rightLEDState = 0;
    
    uint8_t volatile previousLeftLEDState = 0;
    uint8_t volatile previousRightLEDState = 0;
    
	for(;;)
	{
        if (!Pin_4_Read())
        {
            if (!previousRightLEDState) 
            {
                if (rightLEDState)
                {
                    displayOnLCD("My right LED is", "OFF!");
                }
            
                else 
                {
                    displayOnLCD("My right LED is", "ON!");
                }
            
                rightLEDState = ~rightLEDState;
                Pin_1_Write(rightLEDState);
                previousRightLEDState = 1;
            }
        }
        else if (previousRightLEDState)
        {
            previousRightLEDState = 0;  
            CyDelay(100);
        }
        
        if (!Pin_3_Read())
        {
            if (!previousLeftLEDState) 
            {
                if (leftLEDState)
                {
                    displayOnLCD("My left LED is", "OFF!");
                }
            
                else 
                {
                    displayOnLCD("My left LED is", "ON!");
                }
            
                leftLEDState = ~leftLEDState;
                Pin_2_Write(leftLEDState);
                previousLeftLEDState = 1;
            }
        }
      
        else if (previousLeftLEDState) 
        {
            previousLeftLEDState = 0;
            CyDelay(100);
        }
	}
}


/*
int main()
{
    // Part One

    CyGlobalIntEnable;
    
    LCD_Char_1_Start();

    firstStart1();

    uint8_t volatile buttonState = 0;

	for(;;)
	{
        if ((Pin_3_Read() == 0) && (buttonState == 0))
        {
            buttonState = 1;
            displayOnLCD("Program complet-", "-ion succeeded");
        }
	}
}
*/
