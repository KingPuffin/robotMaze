#include "move.h"
#include <msp430.h>

void initTimer()
{
    P1DIR |= BIT1;                // TA0CCR1 on P1.1
    P1SEL |= BIT1;                // TA0CCR1 on P1.1

    P1DIR |= BIT2;                // TA0CCR1 on P1.2
    P1SEL |= BIT2;                // TA0CCR1 on P1.2

    P2DIR |= BIT0;                // TA0CCR1 on P1.2
    P2SEL |= BIT0;                // TA0CCR1 on P1.2

    P2DIR |= BIT1;                // TA0CCR1 on P1.2
    P2SEL |= BIT1;                // TA0CCR1 on P1.2

    TACTL &= ~MC1|MC0;            // stop timer A0

    TA0CTL |= TACLR;                // clear timer A0

    TA0CTL |= TASSEL1;           // configure for SMCLK

    TA1CTL |= TACLR;                // clear timer A0

    TA1CTL |= TASSEL1;           // configure for SMCLK

    TACCR0 = 100;                // set signal period to 100 clock cycles (~100 microseconds)
    TACCR1 = 52;                // set duty cycle to 25/100 (25%)

    TA1CCR0 = 100;                // set signal period to 100 clock cycles (~100 microseconds)
    TA1CCR1 = 35;                // set duty cycle to 25/100 (25%)

    TACCTL0 |= OUTMOD_5;        // set TACCTL1 to Reset / Set mode
    TACCTL1 |= OUTMOD_5;
    TACCTL0 |= OUTMOD_5;
    TACCTL1 |= OUTMOD_5;

    TA0CTL |= MC0;                // count up
    TA1CTL |= MC0;                // count up

}

void moveForward()
{
	TA0CTL &= ~MC0;
	TA0CTL &= ~MC1;
	 TA0CCTL0 &= ~OUTMOD_7;
	 TA0CCTL1 &= ~OUTMOD_7;

	TA0CCTL0 |= OUTMOD_5;        // set TACCTL1 to Reset / Set mode
    TA0CCTL1 |= OUTMOD_7;
    TA1CCTL0 |= OUTMOD_5;
    TA1CCTL1 |= OUTMOD_7;

    TA0CTL |= MC0;                // count up
    TA1CTL |= MC0;

    __delay_cycles(50000);
}

void moveBackward()
{
	TA0CTL &= ~MC0;
	TA0CTL &= ~MC1;

    TA0CCTL0 &= ~OUTMOD_4;        // set TACCTL1 to Reset / Set mode
    TA0CCTL0 &= ~OUTMOD_5;
    TA0CCTL1 &= ~OUTMOD_7;
    TA0CCTL1 &= ~OUTMOD_5;

    TA1CCTL0 &= ~OUTMOD_4;        // set TACCTL1 to Reset / Set mode
    TA1CCTL0 &= ~OUTMOD_5;
    TA1CCTL1 &= ~OUTMOD_7;
    TA1CCTL1 &= ~OUTMOD_5;

    TA0CCTL0 |= OUTMOD_4;        // set TACCTL1 to Reset / Set mode
    TA0CCTL1 |= OUTMOD_5;
    TA1CCTL0 |= OUTMOD_4;
    TA1CCTL1 |= OUTMOD_5;

    TA0CTL |= MC0;
    TA1CTL |= MC0;

    __delay_cycles(500000);
}

void shortLeft()
{
	TA0CTL &= ~MC0;
	TA0CTL &= ~MC1;

    TA0CCTL0 &= ~OUTMOD_4;        // set TACCTL1 to Reset / Set mode
    TA0CCTL0 &= ~OUTMOD_5;
    TA0CCTL0 |= OUTMOD_4;   // set TACCTL1 to Reset / Set mode
    TA0CCTL1 |= OUTMOD_7;

    TA0CTL |= MC0;

    __delay_cycles(50000);

}

void longLeft()
{

	TA0CTL &= ~MC0;
	TA0CTL &= ~MC1;

    TA0CCTL0 |= OUTMOD_5;        // set TACCTL1 to Reset / Set mode
    TA0CCTL1 |= OUTMOD_7;

    TA0CTL |= MC0;

    __delay_cycles(50000);
}

void shortRight()
{
	TA0CTL &= ~MC0;
	TA0CTL &= ~MC1;

    TA1CCTL0 &= ~OUTMOD_4;        // set TACCTL1 to Reset / Set mode
    TA1CCTL0 &= ~OUTMOD_5;        // set TACCTL1 to Reset / Set mode
    TA1CCTL0 |= OUTMOD_4;
    TA1CCTL1 |= OUTMOD_7;

    TA0CTL |= MC0;

    __delay_cycles(50000);
}

void longRight()
{
	TA0CTL &= ~MC0;
	TA0CTL &= ~MC1;

	 TA0CCTL0 &= ~OUTMOD_7;
	 TA0CCTL1 &= ~OUTMOD_7;
    TA1CCTL0 |= OUTMOD_5;        // set TACCTL1 to Reset / Set mode
    TA1CCTL1 |= OUTMOD_7;

    TA0CTL |= MC0;

    __delay_cycles(350000);
}

void fullStop()
{
        TA0CTL &= ~(MC1 | MC0);
        TA0CCTL0 &= ~OUTMOD_4;
        TA0CCTL0 &= ~OUTMOD_7;
        TA0CCTL1 &= ~OUTMOD_5;
        TA0CCTL1 &= ~OUTMOD_7;
        TA0CCTL0 |= OUTMOD_5;                                //set to reset to stop
        TA0CCTL1 |= OUTMOD_5;
        TA0CTL |= MC0;

        TA1CTL &= ~(MC1 | MC0);
        TA1CCTL0 &= ~OUTMOD_4;
        TA1CCTL0 &= ~OUTMOD_7;
        TA1CCTL1 &= ~OUTMOD_5;
        TA1CCTL1 &= ~OUTMOD_7;
        TA1CCTL0 |= OUTMOD_5;                                //set to reset to stop
        TA1CCTL1 |= OUTMOD_5;
        TA1CTL |= MC0;
}

void reset()
{

}
