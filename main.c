#include <msp430.h> 
#include "move.h"
#include "sensors.h"
/*
 * main.c
 */
void main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	initTimer();
	initSensors();
	
	P1DIR |= 0x41;
    while(1)
    {
    	midSensor();

    	if( ADC10MEM > 0x2AF )
    	{
    		P1OUT |= BIT6;
    		fullStop();
    		moveBackward();
    		shortRight();
    		fullStop();
    		longRight();
    		longRight();
    		longRight();
    		longRight();
    		longRight();
    		fullStop();
    	}
    	else
    	{
    		  P1OUT &= ~BIT6;
    	}

    	leftSensor();
        if( ADC10MEM > 0x2B5 )
    	  {
   		  P1OUT |= BIT0;
    		fullStop();
   		  longRight();
    		fullStop();
   		  }
    	  else
   		  {
    			  P1OUT &= ~BIT0;
   		  }



        fullStop();

        moveForward();

    }
}
