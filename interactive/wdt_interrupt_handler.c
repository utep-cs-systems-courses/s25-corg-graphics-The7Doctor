#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "state_machine.h"
#include "gameFunc.h"

void
__interrupt_vec(WDT_VECTOR) WDT()
{

  secondCount++;
  // if(secondCount >= 330){
    //secondCount = 0; //will be XORing the leds until limit is reached
    // P1OUT ^= LEDS;
    // }

  if(secondCount >= 100){
    short oldCol = controlPos[0];
    short newCol = oldCol + colVelocity;
    if(newCol <= colLimits[0] || newCol >= colLimits[1])
      colVelocity = -colVelocity;
    else
      controlPos[0] = newCol;
      secondCount = 0;
  }
  
  
  redrawScreen = 1;
}
