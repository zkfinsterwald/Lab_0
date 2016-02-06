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

#define OUTPUT 0
#define INPUT 1

//TODO: Define states of the state machine
typedef enum stateTypeEnum{
    INIT, LED_0, LED_1, LED_2
} stateType;

//TODO: Use volatile variables that change within interrupts
volatile stateType state        = INIT;
volatile stateType next_state   = LED_0; 

int main() {
    SYSTEMConfigPerformance(10000000);    //Configures low-level system parameters for 10 MHz clock
    enableInterrupts();                   //This function is necessary to use interrupts.

    //TODO: Write each initialization function
    initLEDs();
    initTimer1();
    
    while(1){
        switch(state) {
            case INIT:
                next_state = LED_0;
                break;
            case LED_0:
                turnOnLED(0);
                next_state = LED_1;
                break;
            case LED_1:
                turnOnLED(1);
                next_state = LED_2;                
                break;
            case LED_2:
                turnOnLED(2);
                next_state = LED_0;
                break;
        }
    }
    
    return 0;
}

//TODO: Add interrupt service routines that manage the change of states
//for particular events as needed
void __ISR(_TIMER_1_VECTOR, IPL7SRS) _T1Interupt(){
    IFS0bits.T1IF   = 0;
    state = next_state;
}
