/*
 Developer : Warren Seto
 Experiment: 2
 */

#include <project.h>

// Constants
#define NVIC_CPUID_BASE (0xE000ED00)

// Prototype to access read_nvic_cpuid_base assembly subroutine
uint32_t read_nvic_cpuid_base(uint32_t *reg_ptr, uint32_t *implementer, uint32_t *variant, uint32_t *partno);

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Establishing a pointer to the register: NVIC_CPUID_BASE_ADDR */
    uint32_t *reg_ptr; 
    reg_ptr = (uint32_t *)NVIC_CPUID_BASE;
    
    /* Declaring values to store the NVIC_CPUID_BASE_ADDR values */
    uint32_t reg_val, implementer, variant, partno;
    
    /* Getting the values from the NVIC_CPUID_BASE_ADDR register using an assembly subroutine */
    reg_val = read_nvic_cpuid_base(reg_ptr, &implementer, &variant, &partno);
    
    return 0;
}



/* [] END OF FILE */
