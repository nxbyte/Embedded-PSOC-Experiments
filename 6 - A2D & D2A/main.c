/*
 Developer : Warren Seto
 Experiment: 6
 */

#include <project.h>
#include <math.h>

#define RESOLUTION 256

/* Method to generate sine values for the Sine Lookup Table */
void generateSineTable(uint8_t *inputTable)
{
    int count; // Controls the Look-up Generator Loop
    
    float resolutionAmplitude = (RESOLUTION - 1) / 4.0; // Calculate the amplitude of the sine wave given a resolution
    float radiansPerSample = (M_PI) / RESOLUTION; // Calculate the radians for a given resolution
    
    for (count = 0; count < RESOLUTION; count++)
    {
        /* Using the sine method in the math library, the value for a given sine value can be calulcated and put into the array */
        inputTable[count] = (-1 * cos(count * radiansPerSample) * resolutionAmplitude) + resolutionAmplitude;
    }
}

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    ADC_SAR_1_Start();
    VDAC8_1_Start();
    
    uint8_t sineTable[RESOLUTION];
    generateSineTable(sineTable);
    
    for(;;)
    {
        ADC_SAR_1_IsEndConversion(ADC_SAR_1_WAIT_FOR_RESULT);
        
        VDAC8_1_SetValue(sineTable[ADC_SAR_1_GetResult16() >> 4]);
    }
}

/* [] END OF FILE */
