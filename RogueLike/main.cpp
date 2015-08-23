#include <iostream>
#include <string>
#include <cstdlib>
#include "GameSystem.h"
#include "Player.h"

using namespace std;

int main()
{
	GameSystem game("level1.txt");

	game.playGame();

	system("PAUSE");
	return 0;
}