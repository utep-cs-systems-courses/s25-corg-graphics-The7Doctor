#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"


void buzzer_init(){

  timerAUpmode();
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;
}



void buzzer_set_period(short cycles){

  CCR0 = cycles;
  CCR1 = cycles >> 1;
}



void buzzer_off(){

  CCR0 = 0;
  CCR1 = 0;
}

void delayCycles(){

  // delay_helper(milliseconds);
    // unsigned int i;
   // for(i = 0; i < milliseconds; i++){
     __delay_cycles(2000); //delay 1 millisecond
     // }
  
}
