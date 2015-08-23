#pragma once
#include "Player.h"
#include <string>
#include "Level.h"
#include "Enemy.h"


using namespace std;

class GameSystem
{
public:
	GameSystem(string levelFile);
	void playGame();
	void playerMove();
private:
	Player _player;
	Level _level;
};
