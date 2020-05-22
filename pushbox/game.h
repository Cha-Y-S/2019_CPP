#ifndef __GAME_H__
#define __GAME_H__

struct Object{
  int xPosition;  // 박스와 플레이어의 x좌표를 저장하는 변수
  int yPosition;  // 박스와 플레이어의 y좌표를 저장하는 변수
  unsigned char zn; // 각 객체의 형태를 저장하는 변수
  chtype ozn; // 객체가 이동한 위치의 모양을 저장하는 변수
};

class Game {
private:
  const int MAX = 10; //객체의 최대 갯수 저장
  int lev;  // Level을 저장해주는 변수
  int moveCnt;
  int pushCnt;
  Object *obj;  // 각 객체를 저장하는 배열(동적할당)
  Map gameMap;  // level별 맵을 불러오기 위한 Map형 객체
  char undo;  // undo 기능을 위한 플레이어의 이전 위치 저장
  char undobox; // undo 기능을 위한 박스의 이전 위치 저장
public:
  Game();
  int getMoveCnt();
  int getPushCnt();
  void palette();
  void levelUp();
  void levelList();
  void level();
  bool checkClear();
  void play(int input);
};

#endif
