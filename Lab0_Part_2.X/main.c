/*
 * Zachary Finsterwald
 * ECE 372A - LAB 0
 * Due: February 5, 2016
 * Part 2
 */

#include <xc.h>
#include <sys/attribs.h>
#include "timer.h"
#include "led.h"
#include "interrupt.h"
#include "config.h"

#define OUTPUT 0
#define INPUT 1


typedef enum stateTypeEnum{
    INIT, LED_0, LED_1, LED_2
} stateType;


volatile stateType state        = INIT;
volatile stateType next_state   = LED_0; 

int main() {
    SYSTEMConfigPerformance(10000000);    //Configures low-level system parameters for 10 MHz clock
    enableInterrupts();                   //This function is necessary to use interrupts.

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

// TIMER INTERRUPT
void __ISR(_TIMER_1_VECTOR, IPL7SRS) _T1Interupt(){
    IFS0bits.T1IF   = 0;    // PUT DOWN FLAG
    state = next_state;     // MOVE TO NEXT STATE
}
