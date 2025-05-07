#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "state_machine.h"

void

__interrupt_vec(WDT_VECTOR) WDT()

{

  secondCount++;

  if(secondCount >= 500){

    secondCount = 0; //will be XORing the leds until limit is reached

    P1OUT ^= LEDS;

  }

}
