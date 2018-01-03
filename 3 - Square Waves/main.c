/*
 Author: Warren Seto
 Experiment: 3
 */

#include <project.h>

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    uint8_t volatile buttonState;
    
    for(;;)
    {
        /* Toggle Pin continuously with no delay (produces a square wave). (1.5 microseconds per period or approximately 666666.7 Hz) */
        Pin_1_Write(1);
        Pin_1_Write(0);
        
        /* Toggle Pin continuously with a delay of 500ms. (992ms per period or approximately 2 Hz) */
        Pin_1_Write(1);
        CyDelay(500);
        Pin_1_Write(0);
        CyDelay(500);
        
        /* Toggle Pin continuously with a delay of 50ms. (99.2ms per period or approximately 20 Hz) */
        Pin_1_Write(1);
        CyDelay(50);
        Pin_1_Write(0);
        CyDelay(50);
                
        /* Toggle Pin continuously with a delay of 500ms. This will effectively link the LED 60 times in a minute. */
        Pin_1_Write(1);
        CyDelay(500);
        Pin_1_Write(0);
        CyDelay(500);

        /* Read the state of the button and toggle the output pin to light the LED accordingly. */
        buttonState = Pin_3_Read();
        Pin_2_Write(~buttonState);
    }
}

/* [] END OF FILE */
