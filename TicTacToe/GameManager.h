#pragma once
#include "Input.h"
#include "Board.h"

class GameManager
{
	char _player1;
	char _player2;
	Board _board;
	Input _input;

public:
	GameManager();
	void init();
	bool run();
};
