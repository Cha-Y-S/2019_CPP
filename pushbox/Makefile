all:pushbox

pushbox:game.o map.o main.o
	g++ -W -Wall -o pushbox game.o map.o main.o -lncurses

map.o:map.cpp
	g++ -W -Wall -c -o map.o map.cpp -lncurses

game.o:game.cpp
	g++ -W -Wall -c -o game.o game.cpp -lncurses

main.o:main.cpp
	g++ -W -Wall -c -o main.o main.cpp -lncurses

clean:
	rm -rf *.o
