/*
 Developer : Warren Seto
 Experiment: 1
 */

#include <project.h>
#include <stdio.h>
#include <cydevice_trm.h>

// Constants
#define NVIC_CPUID_BASE_ADDR (0xE000ED00)

// Global variables that will hold the values from various registers
uint32_t reg_val;
uint32_t implementer, variant, partno, revision;

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Establishing a pointer to the register: NVIC_CPUID_BASE_ADDR */
    uint32_t volatile *cpuPointer;
    cpuPointer = (uint32_t *) NVIC_CPUID_BASE_ADDR;
    reg_val = *cpuPointer;
    
    /* Getting the values from the NVIC_CPUID_BASE_ADDR register */
    implementer = (reg_val >> 24) & 0xFF;
    variant = (reg_val >> 20) & 0xF;
    partno = (reg_val >> 4) & 0xFFF;
    revision = (reg_val >> 0) & 0xF;
    
    /* Establishing a pointer to the register: CYREG_PRT6_DR */
    uint32_t volatile *prtPointer;
    prtPointer = (uint32_t *) CYREG_PRT6_DR;
    reg_val = *prtPointer;
    
    while (1) 
    {
        /* Modify and write the value to the [3:2] bites of the CYREG_PRT6_DR register */
        reg_val |= 1 << 2;
        reg_val |= 1 << 3;
        *prtPointer = reg_val;
        
        /* Add delay to see the effects of lighting up the LEDs after 'programming' the PSOC */
        CyDelay(500);
        
        /* Clear the specificed bits [3:2] of the CYREG_PRT6_DR register */
        reg_val &= ~(1 << 2);
        reg_val &= ~(1 << 3);
        *prtPointer = reg_val;
        
        /* Add delay to see the effects of turning off the LEDs after 'programming' the PSOC */
        CyDelay(500);
    }
    
    return 0;
}

/* [] END OF FILE */
