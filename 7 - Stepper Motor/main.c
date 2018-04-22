/*
 Authors: Nikita Eisenhauer and Warren Seto
 Experiment: 7
 */

#include <project.h>

#define ROTATE_DURATION (2048)
#define PHASE_STEPS (8)

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    /* An array that contains all the states for the motor (clockwise and counter-clockwise) */
    int phase[2][PHASE_STEPS] =
    {
        {1, 3, 2, 6, 4, 12, 8, 9}, // dir = 0
        {9, 8, 12, 4, 6, 2, 3, 1}, // dir = 1
    };
    
    /* Sets the rotation direction for the motor */
    int dir = 1;
    
    /* Number of iterations that the motor will run for one direction */
    int count;
    
    /* Infinite loop to keep the motor running for one direction of rotation*/
    while (1)
    {
        for (count = 0; count < ROTATE_DURATION; count++)
        {
            Pin_1_Write(phase[dir][count % PHASE_STEPS]);
            CyDelay(10);
        }
        
        CyDelay(500);
        
        /* After rotating in one direction, change to the opposite direction */
        dir = !dir;
    }
}
