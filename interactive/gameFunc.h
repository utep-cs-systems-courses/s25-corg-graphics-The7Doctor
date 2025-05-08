#ifndef gameFunc_included
#define gameFunc_included





//void draw_ball();
void screen_update_ball();
void screen_update_user();
void set_menu();
void set_menu_update_upward();
void set_menu_update_downward();
void select_through_music();
void select_through_menu();
void move_user_up();
void move_user_down();
void move_user_left();
void move_user_right();


extern short drawPos[], controlPos[];
extern short colVelocity, colLimits[];
extern short redrawScreen;
extern char modeMusic;

#endif
