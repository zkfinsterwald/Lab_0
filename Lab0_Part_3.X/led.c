/*
 * Zachary Finsterwald
 * ECE 372A - LAB 0
 * Due: February 5, 2016
 * Part 3
 */

#include <xc.h>
#include "led.h"

#define OUTPUT  0
#define OFF     0
#define ON      1

void initLEDs(){
    /* Setup LED ports as outputs and turned off */
    TRISDbits.TRISD0    = OUTPUT;
    TRISDbits.TRISD1    = OUTPUT;
    TRISDbits.TRISD2    = OUTPUT;
    LATDbits.LATD0      = OFF;
    LATDbits.LATD1      = OFF;
    LATDbits.LATD2      = OFF;
}

void turnOnLED(int led){
    switch (led) 
    {
        case 0:
            LATDbits.LATD0      = ON;
            LATDbits.LATD1      = OFF;
            LATDbits.LATD2      = OFF;
            break;
        case 1:
            LATDbits.LATD0      = OFF;
            LATDbits.LATD1      = ON;
            LATDbits.LATD2      = OFF;
            break;
        case 2:
            LATDbits.LATD0      = OFF;
            LATDbits.LATD1      = OFF;
            LATDbits.LATD2      = ON;
            break;
    }
}