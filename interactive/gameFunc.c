#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "gameFunc.h"
#include "switches.h"
#include "state_machine.h"

short drawPos[2] = {1,10}, controlPos[2] = {2, 10};
short colVelocity = 1, colLimits[2] = {1, screenWidth/2};
short redrawScreen = 1;
//char modeOn = 0;

void
draw_ball(int col, int row, unsigned short color)
{
  fillRectangle(col-1, row-1, 3, 3, color);
}

short user_position[2] = {65, 139};

void
draw_user(int col, int row, unsigned short color)
{
  fillRectangle(col, row, 7, 17, color);
}


void
screen_update_ball()
{

  for (char axis = 0; axis < 2; axis ++)
    if (drawPos[axis] != controlPos[axis]) /* position changed? */
      goto redraw;
  
  return;/* nothing to do */

 redraw:
  draw_ball(drawPos[0], drawPos[1], COLOR_BLACK); /* erase */

  for (char axis = 0; axis < 2; axis ++)
    drawPos[axis] = controlPos[axis];
  
  draw_ball(drawPos[0], drawPos[1], COLOR_WHITE); /* draw */

}

void
screen_update_user(){
  draw_user(user_position[0], user_position[1], 1);
  // for (char axis = 0; axis < 2; axis ++)
    //   if(drawPos[axis] != controlPos[axis])
      //  goto reUse;
  // return;

  // reUse:  
  // draw_user(drawPos[0], drawPos[1], COLOR_RED);

  // for(char axis = 0; axis< 2; axis ++)
    // drawPos[axis] = controlPos[axis];
  
  //  draw_user(drawPos[0], drawPos[1], COLOR_YELLOW);
}

void
move_user_down(){
  draw_user(user_position[0], user_position[1], COLOR_BLACK);
  user_position[1] += 3;
  draw_user(user_position[0], user_position[1], COLOR_ORANGE);
}

void
move_user_up(){
  draw_user(user_position[0], user_position[1], COLOR_BLACK);
  user_position[1] -=3;
  draw_user(user_position[0], user_position[1], COLOR_ORANGE);
}

void
move_user_left(){
  draw_user(user_position[0], user_position[1], COLOR_BLACK);
  user_position[0] -=3;
  draw_user(user_position[0], user_position[1], COLOR_ORANGE);
}

void
move_user_right(){
  draw_user(user_position[0], user_position[1], COLOR_BLACK);
  user_position[0] +=3;
  draw_user(user_position[0], user_position[1], COLOR_ORANGE);
  
}


void
start_game(){
  clearScreen(COLOR_BLACK);
  screen_update_user();
  play_mega();
}

char modeMusic = 0;
short selectPos[2] = {0,0}; 


void
set_menu(){
  clearScreen(COLOR_BLACK);
  fillRectangle(30, 30, 60, 60, COLOR_ORANGE);
  drawString5x7(30, 35, "Start Game", COLOR_RED, COLOR_YELLOW);
  drawString5x7(30, 45, "Music", COLOR_RED, COLOR_ORANGE);
  drawString11x16(30,85, "Rocketer", COLOR_WHITE, COLOR_BLACK); //NEW
  selectPos[0] = 30;
  selectPos[1] = 35;
  // user_select_update();
  
}
void
set_music(){
  fillRectangle(30, 30, 60, 60, COLOR_ORANGE);
  drawString5x7(30, 55, "Song One", COLOR_RED, COLOR_YELLOW);
  drawString5x7(30, 65, "Song Two", COLOR_RED, COLOR_ORANGE);
  drawString5x7(30, 75, "Main Menu", COLOR_RED, COLOR_ORANGE); //NEW
  modeMusic =1;
  selectPos[0] = 30;
  selectPos[1] = 55;
}

void
set_menu_update_downward(){
  if(modeMusic){
    if(selectPos[0] == 30 && selectPos[1] == 55){
      fillRectangle(30, 30, 60, 60, COLOR_ORANGE);
      drawString5x7(30, 55, "Song One", COLOR_RED, COLOR_ORANGE);
      drawString5x7(30, 65, "Song Two", COLOR_RED, COLOR_YELLOW);
      drawString5x7(30, 75, "Main Menu",COLOR_RED, COLOR_ORANGE);
      selectPos[0] = 30;
      selectPos[1] = 65;
    }
    else if(selectPos[0] == 30 && selectPos[1] == 65){
      fillRectangle(30, 30, 60, 60, COLOR_ORANGE);
      drawString5x7(30, 55, "Song One", COLOR_RED, COLOR_ORANGE);
      drawString5x7(30, 65, "Song Two", COLOR_RED, COLOR_ORANGE);
      drawString5x7(30, 75, "Main Menu", COLOR_RED, COLOR_YELLOW);
      selectPos[0] = 30;
      selectPos[1] = 75;
      
    }
  }else{
    if(selectPos[0]==30 && selectPos[1]==35){
      fillRectangle(30, 30, 60, 60, COLOR_ORANGE);
      drawString5x7(30, 35, "Start Game", COLOR_RED, COLOR_ORANGE);
      drawString5x7(30,45, "Music", COLOR_RED, COLOR_YELLOW);
      selectPos[0] = 30;
      selectPos[1] = 45;
      
    }
  }
}

void
set_menu_update_upward(){
  if(modeMusic){
    if(selectPos[0] == 30 && selectPos[1] == 75){
      fillRectangle(30, 30, 60, 60, COLOR_ORANGE);
      drawString5x7(30, 55, "Song One", COLOR_RED, COLOR_ORANGE);
      drawString5x7(30, 65, "Song Two", COLOR_RED, COLOR_YELLOW);
      drawString5x7(30, 75, "Main Menu", COLOR_RED, COLOR_ORANGE);
      selectPos[0] = 30;
      selectPos[1] = 65;
      
    }
    else if(selectPos[0] == 30 && selectPos[1] == 65){
      fillRectangle(30, 30, 60, 60, COLOR_ORANGE);
      drawString5x7(30, 55, "Song One", COLOR_RED, COLOR_YELLOW);
      drawString5x7(30, 65, "Song Two", COLOR_RED, COLOR_ORANGE);
      drawString5x7(30, 75, "Main Menu", COLOR_RED, COLOR_ORANGE);
      selectPos[0] = 30;
      selectPos[1] = 55;
    }
  }else{
    if (selectPos[0]==30 && selectPos[1]==45){
      set_menu();
    }
  }
}

void
select_through_menu(){
  
  if(selectPos[0]==30 && selectPos[1]==35){
    modeOn = 1;
    start_game();
  }
  if(selectPos[0]==30 && selectPos[1]==45){
    set_music();
  }
}

void
select_through_music(){
  if(selectPos[0]==30 && selectPos[1]==55){
    play_mega();
  }else if(selectPos[0]==30 && selectPos[1]==65){
    play_my_favorite_things();
  }
  if(selectPos[0]==30 && selectPos[1] == 75){
    set_menu();
  }
}
