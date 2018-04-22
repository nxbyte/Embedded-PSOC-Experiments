
// Authors: Nikita Eisenhauer, Brandon Siebert and Warren Seto
// Experiment: 2

.syntax unified
.text

.global read_nvic_cpuid_base

.func read_nvic_cpuid_base, read_nvic_cpuid_base

.thumb_func

read_nvic_cpuid_base:

    LDR r4, [r0] // Get the value from the address in r0 and set it to r4
    
    PUSH {r1} // Push the Address of r1 (implementer) in the stack
    LSR r1, r4, #24 // Get the values with a shift 24 bits to the Right
    AND r1, r1, 0xFF // Bit Mask only the number of bits needed
    POP {r8} // Pop the Address of r1 from the stack and put it in a temporary register
    STR r1, [r8] // Store the value of r1 into the recently popped address in memory (implementer)
    
    PUSH {r2} // Save the Address of r2 (variant) in the stack
    LSR r2, r4, #20 // Get the values with a shift 20 bits to the Right
    AND r2, r2, 0xF // Bit Mask only the number of bits needed
    POP {r9} // Pop the Address of r2 from the stack and put it in a temporary register
    STR r2, [r9] // Store the value of r2 into the recently popped address in memory (variant)
    
    PUSH {r3} // Save the Address of r3 (partno) in the stack
    LSR r3, r4, #4 // Get the values with a shift 4 bits to the Right
    LDR r6, =4095 // A way to load a big immediate into the operation. Workaround for 0xFFF
    AND r3, r3, r6 // Bit Mask only the number of bits needed
    POP {r10} // Pop the Address of r3 from the stack and put it in a temporary register
    STR r3, [r10] // Store the value of r3 into the recently popped address in memory (partno)
    
    MOV r0, r4 // Put the value (uint32_t) originally loaded in r4 into r0 which will be returned from this subroutine
    
    BX LR

.endfunc

    .end
