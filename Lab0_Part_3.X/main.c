/*
 * Zachary Finsterwald
 * ECE 372A - LAB 0
 * Due: February 5, 2016
 */

#include <xc.h>
#include <sys/attribs.h>
#include "timer.h"
#include "led.h"
#include "interrupt.h"
#include "config.h"
#include "switch.h"

#define OUTPUT 0
#define INPUT 1

//TODO: Define states of the state machine
typedef enum stateTypeEnum{
    INIT, LED_0, LED_1, LED_2
} stateType;

//TODO: Use volatile variables that change within interrupts
volatile stateType state        = INIT;
volatile stateType forwards     = LED_0;
volatile stateType backwards    = LED_0;

int main() {
    SYSTEMConfigPerformance(10000000);    //Configures low-level system parameters for 10 MHz clock
    enableInterrupts();                   //This function is necessary to use interrupts.

    initSW1();
    initLEDs();
    initTimer1();
    
    while(1){
        switch(state) {
            case INIT:
                forwards    = LED_0;
                backwards   = LED_0;
                break;
            case LED_0:
                turnOnLED(0);
                forwards    = LED_1;
                backwards   = LED_2;
                break;
            case LED_1:
                turnOnLED(1);
                forwards    = LED_2;
                backwards   = LED_0;               
                break;
            case LED_2:
                turnOnLED(2);
                forwards    = LED_0;
                backwards   = LED_1;
                break;
        }
    }
    
    return 0;
}

void __ISR(_TIMER_1_VECTOR, IPL7SRS) _T1Interupt(){
    IFS0bits.T1IF   = 0;
    
    if(PORTDbits.RD6 == 0) state = forwards;
}
