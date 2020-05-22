#include <iostream>
#include <ncurses.h>
#include <fstream>
#include "map.h"
//#include "play.h"
using namespace std;

//Map의 크기를 10x10으로 설정
Map::Map(){
  height=10;
  wide=10;
  nBox=0;
}

// loadMap -> 맵 불러오는 함수
void Map::loadMap1(){
    ifstream infile;
    infile.open("map/map1.txt",ios::in);
    for (int i=0;i<10;i++){
      for(int j=0;j<10;j++){
        infile>>map[i][j];
      }
    }
    infile.close();
}

void Map::loadMap2(){
    ifstream infile;
    infile.open("map/map2.txt",ios::in);
    for (int i=0;i<10;i++){
      for(int j=0;j<10;j++){
        infile>>map[i][j];
      }
    }
    infile.close();
}

void Map::loadMap3(){
    ifstream infile;
    infile.open("map/map3.txt",ios::in);
    for (int i=0;i<10;i++){
      for(int j=0;j<10;j++){
        infile>>map[i][j];
      }
    }
    infile.close();
}

void Map::loadMap4(){
    ifstream infile;
    infile.open("map/map4.txt",ios::in);
    for (int i=0;i<10;i++){
      for(int j=0;j<10;j++){
        infile>>map[i][j];
      }
    }
    infile.close();
}

void Map::loadMap5(){
    ifstream infile;
    infile.open("map/map5.txt",ios::in);
    for (int i=0;i<10;i++){
      for(int j=0;j<10;j++){
        infile>>map[i][j];
      }
    }
    infile.close();
}
