/*
 * Zachary Finsterwald
 * ECE 372A - LAB 0
 * Due: February 5, 2016
 * Part 3
 */

#include <xc.h>
#include "timer.h"

#define PRESCALAR_256   3

void initTimer1(){
    TMR1            = 0;                // Keeps Count
    T1CONbits.TCKPS = PRESCALAR_256;    // Configure ticking rate
    PR1             = 39061;            // 1 Sec - Period Register
    T1CONbits.ON    = 0;                // Turn off Timer
    IFS0bits.T1IF   = 0;                // Put down the interrupt flag
}
