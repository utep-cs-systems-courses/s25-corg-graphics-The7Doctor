#include <msp430.h>
#include <libTimer.h>
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"

void main(void)

{

  configureClocks();
  switch_init();
  led_init();
  buzzer_init();
  enableWDTInterrupts();
  lcd_init();

  u_char width = screenWidth, height = screenHeight;



  clearScreen(COLOR_BLUE);


  or_sr(0x18);  // CPU off, GIE on

} 
