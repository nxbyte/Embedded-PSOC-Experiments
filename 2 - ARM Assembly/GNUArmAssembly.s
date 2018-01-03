/*
 Developer : Warren Seto
 Experiment: 2
 */

    .syntax unified
    .text


.global read_nvic_cpuid_base

.func read_nvic_cpuid_base, read_nvic_cpuid_base

.thumb_func

read_nvic_cpuid_base:
/*
    LDR r4, [r0]
    
    PUSH {r1}
    LSR r1, r4, #24
    AND r1, r1, 0xFF
    POP {r8}
    STR r1, [r8]
    
    PUSH {r2}
    LSR r2, r4, #20
    AND r2, r2, 0xF
    POP {r9}
    STR r2, [r9]
    
    PUSH {r3}
    LSR r3, r4, #4
    LDR r6, =4095
    AND r3, r3, r6
    POP {r10}
    STR r3, [r10]
    
    MOV r0, r4
   */
   
   
   
   // INIT TESTING
   
   LDR r0, =0
   LDR r1, =1
   LDR r2, =1540
   LDR r3, =2117   
   
   // TEST FOR

   SUB r4, r3, r2
   ADD r5, r3, r2
   ORR r6, r2, r3
   AND r7, r2, r3
   STR r6, [r6]
   STR r7, [r6, #1]
   ADD r8, r0, r1
   
   
   
   
   
   
   
    BX LR

.endfunc

    .end


/* [] END OF FILE */
