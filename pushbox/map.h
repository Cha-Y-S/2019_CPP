#ifndef __MAP_H__
#define __MAP_H__

class Map{
public:
  int height; // 맵의 세로 간격
  int wide;   // 맵의 가로 간격
  int map[10][10]; // Map을 저장할 2차원 배열
  int nBox; // 각 맵 별 Box의 갯수를 저장하는 변수
  Map();
  void loadMap1();
  void loadMap2();
  void loadMap3();
  void loadMap4();
  void loadMap5();
  //loadMap은 각 Level별 Map을 불러오는 함수이다.
};

#endif
