#include <iostream>
#include <ncurses.h>
#include "map.h"
#include "game.h"

using namespace std;

Game::Game(){
  moveCnt = 0;
  pushCnt = 0;
  lev = 1;
  obj = new Object[MAX];
}

int Game::getMoveCnt(){
  return moveCnt;
}

int Game::getPushCnt(){
  return pushCnt;
}

void Game::palette(){
  init_color(COLOR_BLACK,0,0,0);
  init_pair(1,COLOR_BLACK,COLOR_BLACK) ;
  init_pair(2,COLOR_GREEN,COLOR_BLACK);
  init_pair(3,COLOR_RED,COLOR_BLACK);
  init_pair(4,COLOR_BLUE, COLOR_BLACK);
  init_pair(5,COLOR_MAGENTA,COLOR_BLACK);
  init_pair(6,COLOR_WHITE,COLOR_BLACK);
}

void Game::levelUp(){
  lev++;  // 맵 클리어 시 level 올려주는 함수
}

void Game::levelList(){
  switch(lev){
  case 1:
    gameMap.loadMap1();
    break;
  case 2:
    gameMap.loadMap2();
    break;
  case 3:
    gameMap.loadMap3();
    break;
  case 4:
    gameMap.loadMap4();
    break;
  case 5:
    gameMap.loadMap5();
    break;
  default:
    break;
  }
}

void Game::level(){
  gameMap.nBox = 0;
  clear();
  //맵 읽어들이기
  if(lev<=5){
    levelList();
    mvprintw(5,33,"Level : %d",lev);
    for(int y=0;y<gameMap.height;y++){
      for(int x=0;x<gameMap.wide;x++){
        switch(gameMap.map[y][x]){
        case 0:
          mvaddch(y+10,x+33,'-'|COLOR_PAIR(1));
          break;
        case 1:
          mvaddch(y+10,x+33,'@'|COLOR_PAIR(2));
          break;
        case 2:
          mvaddch(y+10,x+33,'x'|COLOR_PAIR(3));
          break;
        case 3:
          mvaddch(y+10,x+33,'-'|COLOR_PAIR(1)); //박스가 움직인 자리도 '-'(공백)처리
          gameMap.nBox += 1; //박스의 개수
          obj[gameMap.nBox].ozn = mvinch(y + 10, x + 33); //박스 위치받아오기
          obj[gameMap.nBox].yPosition = y + 10;
          obj[gameMap.nBox].xPosition = x + 33;
          obj[gameMap.nBox].zn = 'O'; //박스를 표현할 기호
          mvaddch(obj[gameMap.nBox].yPosition,obj[gameMap.nBox].xPosition,obj[gameMap.nBox].zn | COLOR_PAIR(5));
          break;
        case 4:
          mvaddch(y+10,x+33,'-'|COLOR_PAIR(1)); //플레이어가 움직인 자리도 '-'(공백)처리
          obj[0].ozn = mvinch(y + 10, x + 33); //플레이어 위치 받아오기
          obj[0].yPosition = y + 10;
          obj[0].xPosition = x + 33;
          obj[0].zn = '*'; //플레이어 표현할 기호
          mvaddch(obj[0].yPosition,obj[0].xPosition,obj[0].zn | COLOR_PAIR(4));
          break;
        }
      }
    }
    move(obj[0].yPosition,obj[0].xPosition); //플레이어를 이동시킨다.
  }
  //맵을 모두 클리어한 경우
  else {
    attron(COLOR_PAIR(4));
    mvprintw(10,31,"Congratulation!");
    mvprintw(12,31,"Clear All Level");
    mvprintw(14,26,"Press q to quit this game");
  }
}

bool Game::checkClear(){
  chtype check;
  int cnt = 0; //'x'(목적지)에 도착한 박스의 개수
  for(int i=1; i<=gameMap.nBox;i++){
    //박스의 위치를 캐릭터 타입으로 저장
    check = (mvinch(obj[i].yPosition, obj[i].xPosition) & A_CHARTEXT);
    if(check == 120) // 'x'(목적지)와 같을 경우
      cnt++;
  }
  if(cnt == gameMap.nBox) { //전체 박스 개수와 목적지 위의 박스 개수가 같을 때
    return true;
  }
  else
    return false;
}

//실제 게임 플레이를 구현
void Game::play(int input){
  bool restart = false;

  char up, left, down, right, oUp, oLeft, oDown, oRight;
  up = (mvinch(obj[0].yPosition - 1,obj[0].xPosition) & A_CHARTEXT);    //플레이어 위치의 한 칸 위
  left = (mvinch(obj[0].yPosition, obj[0].xPosition - 1) & A_CHARTEXT); //플레이어 위치의 한 칸 왼쪽
  down = (mvinch(obj[0].yPosition +1, obj[0].xPosition) & A_CHARTEXT);  //플레이어 위치의 한 칸 아래
  right = (mvinch(obj[0].yPosition,obj[0].xPosition + 1)& A_CHARTEXT);  //플레이어 위치의 한 칸 오른쪽
  oUp = (mvinch(obj[0].yPosition - 2,obj[0].xPosition) & A_CHARTEXT);   //플레이어 위치의 두 칸 위
  oLeft = (mvinch(obj[0].yPosition, obj[0].xPosition - 2) & A_CHARTEXT);//플레이어 위치의 두 칸 왼쪽
  oDown = (mvinch(obj[0].yPosition + 2, obj[0].xPosition) & A_CHARTEXT);//플레이어 위치의 두 칸 아래
  oRight = (mvinch(obj[0].yPosition,obj[0].xPosition + 2)& A_CHARTEXT); //플레이어 위치의 두 칸 오른쪽

  for(int i = 0;i<=gameMap.nBox;i++){
    mvaddch(obj[i].yPosition,obj[i].xPosition,obj[i].ozn);
  }

  // ASCII : 64 = 벽(@) 79 = 박스(O)  45 = 공백  120 = 목적지(x)
  switch(input){
  case KEY_UP:
    if(up != 64){
      if(up == 79 && (oUp == 45 || oUp == 120)){
        obj[0].yPosition -=1;
        undobox = 0;
        for(int i = 1;i <= gameMap.nBox;i++){
          if((obj[0].yPosition == obj[i].yPosition) && (obj[0].xPosition == obj[i].xPosition)){
            obj[i].yPosition -=1;
            undobox = 'w';
            pushCnt++;
          }
        }
      }
      else if (up == 79 &&(oUp == 64 || oUp == 79))
        moveCnt--;
      else if (up != 79)
        obj[0].yPosition -=1;
      moveCnt++;
    }
    if(checkClear()){
      restart = true;
      levelUp();
      level();
    }
    undo = 'w';
    break;
  case KEY_LEFT:
    if(left != 64){
      if(left == 79 &&(oLeft == 45 || oLeft == 120)){
        obj[0].xPosition -=1;
        undobox = 0;
        for(int i=1;i <=gameMap.nBox;i++){
          if((obj[0].yPosition == obj[i].yPosition) && (obj[0].xPosition == obj[i].xPosition)){
            obj[i].xPosition -=1;
            undobox = 'a';
            pushCnt++;
          }
        }
      }
      else if(left == 79 && (oLeft == 64 || oLeft == 79))
        moveCnt--;
      else if(left != 79)
        obj[0].xPosition -=1;
      moveCnt++;
    }
    if(checkClear()){
      restart = true;
      levelUp();
      level();
    }
    undo = 'a';
    break;
  case KEY_DOWN:
    if(down != 64){
      if(down == 79 && (oDown == 45 || oDown == 120)){
        obj[0].yPosition += 1;
        undobox = 0;
        for(int i = 1; i<=gameMap.nBox;i++){
          if((obj[0].yPosition == obj[i].yPosition) && (obj[0].xPosition == obj[i].xPosition)){
            obj[i].yPosition += 1;
            undobox = 's';
            pushCnt++;
          }
        }
      }
      else if(down == 79 && (oDown == 64 || oDown == 79))
        moveCnt--;
      else if(down != 79)
        obj[0].yPosition +=1;
      moveCnt++;
    }
    if(checkClear()){
      restart = true;
      levelUp();
      level();
    }
    undo = 's';
    break;
  case KEY_RIGHT:
    if(right != 64){
      if (right == 79 && (oRight == 45 || oRight == 120)){
        obj[0].xPosition +=1;
        undobox = 0;
        for(int i = 1;i<=gameMap.nBox;i++){
          if((obj[0].yPosition == obj[i].yPosition) && (obj[0].xPosition == obj[i].xPosition)){
            obj[i].xPosition +=1;
            undobox = 'd';
            pushCnt++;
          }
        }
      }
      else if(right == 79 && (oRight == 64 || oRight == 79))
        moveCnt--;
      else if(right != 79)
        obj[0].xPosition += 1;
      moveCnt++;
    }
    if(checkClear()){
      restart = true;
      levelUp();
      level();
    }
    undo = 'd';
    break;

  case KEY_BACKSPACE:
    switch(undo){
    case 'w':
      obj[0].yPosition +=1;
      for(int i=1;i<=gameMap.nBox;i++){
        if(undobox =='w' && (obj[0].yPosition == (obj[i].yPosition + 2)) && (obj[0].xPosition == obj[i].xPosition)){
          obj[i].yPosition += 1;
        }
      }
      moveCnt++;
      undo = 0;
      undobox = 0;
      break;
    case 's':
      obj[0].yPosition -=1;
      for(int i=1;i<=gameMap.nBox;i++){
        if(undobox =='s' && (obj[0].yPosition == (obj[i].yPosition - 2)) && (obj[0].xPosition == obj[i].xPosition)){
          obj[i].yPosition -= 1;
        }
      }
      moveCnt++;
      undo = 0;
      undobox = 0;
      break;
    case 'a':
      obj[0].xPosition +=1;
      for(int i=1;i<=gameMap.nBox;i++){
        if(undobox =='a' && (obj[0].yPosition == obj[i].yPosition) && (obj[0].xPosition == (obj[i].xPosition + 2))){
          obj[i].xPosition += 1;
        }
      }
      moveCnt++;
      undo = 0;
      undobox = 0;
      break;
    case 'd':
      obj[0].xPosition -=1;
      for(int i=1;i<=gameMap.nBox;i++){
        if(undobox =='d' && (obj[0].yPosition == obj[i].yPosition) && (obj[0].xPosition == (obj[i].xPosition -2))){
          obj[i].xPosition -= 1;
        }
      }
      moveCnt++;
      undo = 0;
      undobox = 0;
      break;
    }
    break;

  case 'r':
  case 'R':
    restart = true;
    level();
    break;
  default:
    break;
  }
  if(!restart){
    for(int i=0;i<=gameMap.nBox;i++){
      obj[i].ozn = mvinch(obj[i].yPosition,obj[i].xPosition);
      mvaddch(obj[i].yPosition,obj[i].xPosition,obj[i].zn | ((i == 0)?COLOR_PAIR(4) : COLOR_PAIR(5)));
    }
    move(obj[0].yPosition,obj[0].xPosition);
  }
  else
    restart = false;
}
