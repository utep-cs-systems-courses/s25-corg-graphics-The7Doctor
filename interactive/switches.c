#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"
#include "state_machine.h"

unsigned int secondCount;
unsigned int limit;

char switch1_state,switch2_state,switch3_state,switch4_state, switch_state_changed,mode;

char switch_state_changed;
int switch_state = 0;
char modeOn = 0;



static char switch_update_interrupt_sense(){
  char p2val = P2IN;

  P2IES |= (p2val & SWITCHES);
  P2IES &= (p2val | ~SWITCHES);

  return p2val;
}

static char switch1_update_interrupt_sense(){
  char p1val = P1IN;

  P1IES |= (p1val & SWITCH);
  P1IES |= (p1val | ~SWITCH);

  return p1val;
}



void switch_init(){
  P2REN |= SWITCHES;
  P2IE |= SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;

  P1REN |=SWITCH;
  P1IE |= SWITCH;
  P1OUT |= SWITCH;
  P1DIR &= SWITCH;
  switch_update_interrupt_sense();
}



void switch_interrupt_handler(){
  char p2val = switch_update_interrupt_sense();
  char p1val = switch1_update_interrupt_sense();
  
  switch1_state = (p2val & SW1) ? 0 : SW1; //tells which button of the 4 were pressed
  switch2_state = (p2val & SW2) ? 0 : SW2;
  switch3_state = (p2val & SW3) ? 0 : SW3;
  switch4_state = (p2val & SW4) ? 0 : SW3;

  mode = (p1val & SW5) ? 0: SW5;



  if (switch1_state){ //sets switch state to what was pressed
    switch_state = 1;
    switch_state_advance();
  }
  if (switch2_state){
    switch_state = 2;
    switch_state_advance();
  }

  if (switch3_state){
    switch_state = 3;
    switch_state_advance();
  }
  
  if (switch4_state){
    switch_state = 4;
    switch_state_advance();
  }
  if (mode){
    modeOn ^= 1;
    switch_state_advance();
  }

  switch_state_changed = 1; //make sure to show a button was pressed
}
