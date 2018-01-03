/*
 Authors: Warren Seto
 Experiment: 5
 */

#include <project.h>
#include <stdio.h>

/* Helper method to properly display text on the LCD */
void displayOnLCD(char8* string1, char8* string2)
{
    /* Clear the display of the first row */
    LCD_Char_1_Position(0u, 0u);
    LCD_Char_1_PrintString("               ");
    
    /* Display first message to the display of the first row */
    LCD_Char_1_Position(0u, 0u);
    LCD_Char_1_PrintString(string1);
    
    /* Clear the display of the second row */
    LCD_Char_1_Position(1u, 0u);
    LCD_Char_1_PrintString("               ");
    
    /* Display second message to the display of the second row */
    LCD_Char_1_Position(1u, 0u);
    LCD_Char_1_PrintString(string2);
}

/* Greeting for Part One of Lab 3: Display an initialization message */
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

/* Greeting for Part Two of Lab 3: Start up procedures include a greeting and prompting button input */
void firstStart2()
{
    /* Start lighting up LEDs */
    Pin_1_Write(1);
    Pin_2_Write(1); 
    
    /* Greeting message */
    displayOnLCD("Hello! I am", "friendy!");
    CyDelay(3000);
    displayOnLCD("Try pressing my", "left button...");
    
    /* Wait for the user's action before progressing */
    while (Pin_3_Read()) {}
    Pin_1_Write(0);   
    Pin_2_Write(0); 

    /* Verify that the user pressed the button */
    displayOnLCD("Nice. I felt", "that press!");
    CyDelay(3000);
    
    /* Display Instructions for toggling the LEDs */
    displayOnLCD("Press either", "button to light");
    CyDelay(3000);
    displayOnLCD("up my left LED", "or right LED...");
    CyDelay(3000);
}

/* Part Two of Lab 3 */
int main()
{
    CyGlobalIntEnable;
    
    // Initialize the LCD Display
    LCD_Char_1_Start();
    
    // Show the greeting message for Part Two
    firstStart2();
    
    displayOnLCD("Try and press", "either button!");
    
    // Declare two variables that will hold the state of the LEDs. 0 = OFF, 1 = ON
    uint8_t volatile leftLEDState = 0;
    uint8_t volatile rightLEDState = 0;
    
    // Declare two variables that will hold the previous state of the button to account for 'bouncing'. 0 = Ready for LED toggling, 1 = Button is currently being pressed; leave the LEDs in their current state
    uint8_t volatile previousLeftLEDState = 0;
    uint8_t volatile previousRightLEDState = 0;
    
    for(;;)
    {
        // If the RIGHT button is pressed then toggle the RIGHT LED depending on its previous state
        if (!Pin_4_Read())
        {
            // This accounts for the onboard button's 'bouncing' effect for the RIGHT button by preventing the LEDs to toggle when the onboard button is held down
            if (!previousRightLEDState) 
            {
                // If the current state of the RIGHT LED is on, then display on the LCD that the LED is OFF
                if (rightLEDState)
                {
                    displayOnLCD("My right LED is", "OFF!");
                }
            
                // Otherwise, display that it will be turned ON
                else 
                {
                    displayOnLCD("My right LED is", "ON!");
                }
            
                // Set the new state of the RIGHT LED
                rightLEDState = ~rightLEDState;
                
                // Toggle the LED based on the new state of the RIGHT LED
                Pin_1_Write(rightLEDState);
                
                // Toggling this variable accounts for onboard button bouncing
                previousRightLEDState = 1;
            }
        }
        
        // Once the user stops pressing the RIGHT button, this will get the PSoC ready for another input
        else if (previousRightLEDState)
        {
            previousRightLEDState = 0;  
            CyDelay(100);
        }
        
        // If the LEFT button is pressed then toggle the LEFT LED depending on its previous state
        if (!Pin_3_Read())
        {
            // This accounts for the onboard button's 'bouncing' effect for the LEFT button by preventing the LEDs to toggle when the onboard button is held down
            if (!previousLeftLEDState) 
            {
                // If the current state of the LEFT LED is on, then display on the LCD that the LED is OFF
                if (leftLEDState)
                {
                    displayOnLCD("My left LED is", "OFF!");
                }
            
                // Otherwise, display that it will be turned ON
                else 
                {
                    displayOnLCD("My left LED is", "ON!");
                }
            
                // Set the new state of the LEFT LED
                leftLEDState = ~leftLEDState;
                
                // Toggle the LED based on the new state of the LEFT LED
                Pin_2_Write(leftLEDState);
                
                // Toggling this variable accounts for onboard button bouncing
                previousLeftLEDState = 1;
            }
        }
        
        // Once the user stops pressing the LEFT button, this will get the PSoC ready for another input
        else if (previousLeftLEDState) 
        {
            previousLeftLEDState = 0;
            CyDelay(100);
        }
    }
}
