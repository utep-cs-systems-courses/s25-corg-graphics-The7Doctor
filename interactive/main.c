#include <msp430.h>
#include <libTimer.h>
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "gameFunc.h"



void main(void)

{

  configureClocks();
  switch_init();
  led_init();
  buzzer_init();
  enableWDTInterrupts();
  lcd_init();
  or_sr(0x8);

  
  u_char width = screenWidth, height = screenHeight;



  clearScreen(COLOR_BLACK);

  redrawScreen = 1;
  set_menu();
  while (1) {/* forever */

    if (redrawScreen) {
       
       redrawScreen = 0;
       //       screen_update_user();
       screen_update_ball();

    }
    // P1OUT &= ~LED;/* led off */
    // or_sr(0x10);/**< CPU OFF */
    //    P1OUT |= LED;/* led on */

  }



  or_sr(0x18);  // CPU off, GIE on

} 
