#ifndef stateMachines_included
#define stateMachines_included


void led_state_advance();
void switch_state_advance();
void play_mary_had_a_little_lamb();
void play_my_favorite_things();
void play_mega();


extern int switch_state;
extern char modeOn;

#endif
