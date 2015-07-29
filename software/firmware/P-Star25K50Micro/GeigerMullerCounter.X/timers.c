/*
 * Geiger-Muller Counter
 * Author: Robert Gawron
 * Sorce code from: https://github.com/RobertGawron/GeigerMullerCounter
 *
 * Credits:
 * 1. Timer configuration based on http://blog.irwellsprings.com/getting-started-with-pic-microcontrollersthe-timer-peripheral-and-interrupts/
 * 
 */
#include "timers.h"
#include <xc.h>
#include <stdbool.h>

bool sendDataToPC;

/* Should be static */
int  ledState;

#include "measure.h"

inline void timer_interrupt()
{
        static char i = 0;
        PIR1bits.TMR1IF = 0;
        T1CONbits.TMR1ON = 0;   // Turn timer off to reset count register
        TMR1H = 0x0B;   // Reset timer count - 0x0BDB = 1Hz
        TMR1L = 0xDB;   //
        T1CONbits.TMR1ON = 1;   // Turn timer back on
 
        ledState++;
        //if(ledState == 10*12*2*6)
        if(ledState == 10*12)
        {
            PORTBbits.RB6 = ~PORTBbits.RB6; 
            ledState = 0;
            sendDataToPC = true;
            //measure_update();
        }
}

void timers_init(void)
{
    ledState=0;
    sendDataToPC = false;
    

    TRISBbits.TRISB6 = 0;   // This sets pin RB6 to output

    // Setup Timer 1
    T1CON = 0;
    T1CONbits.T1CKPS0 = 1;  // T1CKPS = 11 = 1:8 prescaler
    T1CONbits.T1CKPS1 = 1;  // so timer clock = 1MHz / 8 = 125kHz
    /* Calculating for 1 Hz LED flash, so period needs to be 2Hz as
     * interrupt toggles between on/off. Timer 1 clock is 125kHz, so
     * for 2Hz, we divide 125kHz by 2 = 62,500. Then we subtract this
     * from the rollover value of 65,535, so 65,535 - 62,500 = 3035
     * which is 0x0BDB in hex. Timer 1 has two 8-bit high and low
     * registers, so we put 0x0B in the high and 0xDB in the low */
    /* 16/8 = 4Mhz -> 2Mhz
     
     */
    TMR1H = 0x0B;           // 65,535 - 62500 = 3035 = 0x0BDB
    TMR1L = 0xDB;           // to count for 0.5 seconds till timer rollover
    T1CONbits.TMR1ON = 1;   // Turn timer on
    INTCONbits.GIE = 1;     // Enable global interrupts
    INTCONbits.PEIE = 1;    // Enable peripheral interrupts
    PIR1bits.TMR1IF = 0;    // Clear Timer 1 interrupt flag
    PIE1bits.TMR1IE = 1;    // Enable Timer 1 interrupt
}