/* 
 * File:   timer.c
 * Author: gvanhoy
 *
 * Created on August 27, 2015, 3:26 PM
 */

#include <xc.h>

#define PRESCALAR_256   3

void initTimer1(){
    TMR1            = 0;                // Keeps Count
    T1CONbits.TCKPS = PRESCALAR_256;    // Configure ticking rate
    PR1             = 39061;            // 1 Sec - Period Register
    T1CONbits.ON    = 1;                // Turn on Timer
    IEC0bits.T1IE   = 1;                // Enable Interrupt
    IPC1bits.T1IP   = 7;                // Timer 1 priority
    IFS0bits.T1IF   = 0;                // Put down the interrupt flag
}
