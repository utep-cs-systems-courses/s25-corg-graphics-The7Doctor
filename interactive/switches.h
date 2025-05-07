#ifndef switches_included
#define switches_included

#define SW1 BIT0
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3
#define SW5 BIT3

#define SWITCHES (SW1 | SW2 | SW3 | SW4)
#define SWITCH SW5

extern unsigned int limit;
extern unsigned int secondCount;

void switch_init();
void switch_interrupt_handler();

extern char switch1_state,switch2_state,switch3_state,switch4_state, switch_state_changed;
extern char mode;
//extern char switch_state_changed;

#endif
