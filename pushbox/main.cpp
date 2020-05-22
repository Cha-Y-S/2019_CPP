#include <iostream>
#include <ncurses.h>
#include "map.h"
#include "game.h"

using namespace std;

int main(){
  Game g;

  int ch;

  initscr();
  noecho();
  resize_term(100,80);
  keypad(stdscr,true);

  start_color();

  g.palette();

  curs_set(0);

  border('|','|','-','-','*','*','*','*');

  mvprintw(11,28,"Press Any Key To Start Game");
  refresh();
  getch();

  g.level();
  border('|','|','-','-','*','*','*','*');
  refresh();

  while((ch = getch()) != 'q'){
    if(ch == 'Q')
      break;
    g.play(ch);
    attron(COLOR_PAIR(6));
    border('|','|','-','-','*','*','*','*');
    mvprintw(1,33,"move : %d",g.getMoveCnt());
    mvprintw(3,33,"push : %d",g.getPushCnt());
    mvprintw(1,1,"Restart : press R");
    mvprintw(2,1,"Undo : press Back Space");
    mvprintw(3,1,"Undo can cancel last behavior");
  }

  endwin();

  return 0;
}
