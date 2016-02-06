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
    TRISDbits.TRISD6 = INPUT;
    CNPUDbits.CNPUD6 = ENABLE;  // CONFIGURE INTERNAL PULL-UP RESISTOR
}