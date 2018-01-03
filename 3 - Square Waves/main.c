/*
 Developer : Warren Seto
 Experiment: 3
 */

#include <project.h>
#include <stdio.h>
#include <cydevice_trm.h>

int main()
{
    CyGlobalIntEnable;

    uint8_t volatile buttonState;
    
    // Uncomment and re-run to perform experiments
    
    for(;;)
    {
        /* With no delay */
        
        Pin_1_Write(1);
        Pin_1_Write(0);
        
        
        /* Square Wave (992ms per period) */
        /*
        Pin_1_Write(1);
        CyDelay(500);
        Pin_1_Write(0);
        CyDelay(500);
        */
        
        /* Square Wave (99.2ms per period) */
        /*
        Pin_1_Write(1);
        CyDelay(50);
        Pin_1_Write(0);
        CyDelay(50);
        */
                
        /* Square Wave (992ms per period) */
        /*
        Pin_1_Write(1);
        CyDelay(500);
        Pin_1_Write(0);
        CyDelay(500);
        */

        /* Read the state of the button and light the LED accordingly */
        /*
        buttonState = Pin_3_Read();
        Pin_2_Write(~buttonState);
        */
    }
}

/* [] END OF FILE */
