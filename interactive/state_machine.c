#include <msp430.h>
#include "state_machine.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

void play_mary_had_a_little_lamb() {

  // "Mary had a little lamb" notes and periods



  // E D C D E E E (Mary had a little lamb)

  buzzer_set_period(EE);  // E

  delay(W);  // Delay for note E

  buzzer_set_period(DE);  // D

  delay(W);  // Delay for note D

  buzzer_set_period(AB);  // A (C is invalid, so use A from A string)

  delay(W);  // Delay for note A

  buzzer_set_period(DE);  // D

  delay(W);  // Delay for note D

  buzzer_set_period(EE);  // E

  delay(W);  // Delay for note E

  buzzer_set_period(EE);  // E

  delay(W);  // Delay for note E



  // D D D (Mary had a little lamb)

  buzzer_set_period(DE);  // D

  delay(W);  // Delay for note D

  buzzer_set_period(DE);  // D

  delay(W);  // Delay for note D

  buzzer_set_period(DE);  // D

  delay(W);  // Delay for note D



  // E G G (Its fleece was white as snow)

  buzzer_set_period(EE);  // E

  delay(W);  // Delay for note E

  buzzer_set_period(DG);  // G

  delay(W);
  buzzer_set_period(DG);  // G

  delay(W);  // Delay for note G



  // E D C D E E E (Mary had a little lamb)

  buzzer_set_period(EE);  // E

  delay(W);  // Delay for note E

  buzzer_set_period(DE);  // D

  delay(W);  // Delay for note D

  buzzer_set_period(AB);  // A (C is invalid, so use A from A string)

  delay(W);  // Delay for note A

  buzzer_set_period(DE);  // D

  delay(W);  // Delay for note D

  buzzer_set_period(EE);  // E

  delay(W);  // Delay for note E

  buzzer_set_period(EE);  // E

  delay(W);  // Delay for note E

  buzzer_set_period(0);

}
  


void play_my_favorite_things() {

  buzzer_set_period(DE); delay(W);

  buzzer_set_period(AB); delay(W);

  buzzer_set_period(AB); delay(W);

  buzzer_set_period(DF); delay(W);



  buzzer_set_period(DE); delay(W);

  buzzer_set_period(DE); delay(W);

  buzzer_set_period(GB); delay(W);



  buzzer_set_period(DE); delay(W);

  buzzer_set_period(DE); delay(W);

  buzzer_set_period(DF); delay(W);

  buzzer_set_period(DE); delay(W);



  buzzer_set_period(DE); delay(W);

  buzzer_set_period(AB); delay(W);

  buzzer_set_period(AB); delay(W);



  buzzer_set_period(DF); delay(W);

  buzzer_set_period(DE); delay(W);

  buzzer_set_period(DE); delay(W);



  buzzer_set_period(GB); delay(W);

  buzzer_set_period(DE); delay(W);

  buzzer_set_period(DE); delay(W);



  buzzer_set_period(0); // Silence at the end

}



void switch_state_advance(){
  if(modeOn){
    switch (switch_state){
    case 1:
      buzzer_off();
      break;

    case 2:
      play_mary_had_a_little_lamb();
      break;
	
    case 3:
      play_my_favorite_things();
      break;

    case 4:
      buzzer_set_period(3822);
      break;
    }
  }else{
      switch (switch_state){
      case 1:
	buzzer_set_period(1300); //buzzer is set to a input when a certain button is pressed
	break;

      case 2:
	buzzer_set_period(200);
	break;

      case 3:
	buzzer_set_period(700);
	break;

      case 4:
	buzzer_off();
	break;
     }
  }
} 
