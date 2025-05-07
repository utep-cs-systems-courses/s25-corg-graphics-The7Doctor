#include <msp430.h>
#include "switches.h"

void __interrupt_vec(PORT2_VECTOR) Port_2(){

  if (P2IFG & SWITCHES){
    P2IFG &= ~SWITCHES;
    switch_interrupt_handler();
  }
}

void __interrupt_vec(PORT1_VECTOR) Port_1(){
  if (P1IFG & SWITCH) {      /* did a button cause this interrupt? */
    P1IFG &= ~SWITCH;      /* clear pending sw interrupts */
    switch_interrupt_handler();/* single handler for all switches */
  }
}
