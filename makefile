all:
	g++ -Wall -std=c++11 src/main.cpp src/keno.cpp src/gamemanager.cpp src/player.cpp src/tools.cpp -I include -o Keno

