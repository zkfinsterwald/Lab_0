/*
 * File: switch.c
 * Zachary Finsterwald
 * ECE 372A - LAB 0
 * Due: February 5, 2016
 */

#include <xc.h>
#include "switch.h"

#define ENABLE  1
#define INPUT   1

void initSW1(){
    TRISDbits.TRISD6    = INPUT;
    CNPUDbits.CNPUD6    = ENABLE;   // CONFIGURE INTERNAL PULL-UP RESISTOR
    CNCONDbits.ON       = 1;        // Turn on CN for port D
    CNENDbits.CNIED6    = 1;        // Enable CN for RD6
    IFS1bits.CNDIF      = 0;        // Put down interrupt flag
    IEC1bits.CNDIE      = 1;        // Enable Interrupt
    IPC8bits.CNIP       = 7;        // Interrupt Priority
}