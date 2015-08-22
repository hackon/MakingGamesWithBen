#include "GameManager.h"
#include <iostream>

using namespace std;

GameManager::GameManager()
{
	_board.printBoard();
}

void GameManager::init()
{
	_input.getPlayers(_player1, _player2);
}

bool GameManager::run()
{
	int x, y;
	bool isPlayer1 = true;
	while (!_board.hasWinner())
	{
		_input.getCorrInput(x, y);
		if (isPlayer1) 
		{
			_board.play(x, y, _player1);
		}
		else
		{
			_board.play(x, y, _player2);
		}
		isPlayer1 = !isPlayer1;
		_board.printBoard();
	}
	cout << "Winner is " << (isPlayer1 ? _player1 : _player2) << endl ;
	cout << "Another game???(Y/N)" << endl;
	char anotherGame;
	cin >> anotherGame;
	if (anotherGame == 'Y')
	{
		return true;
	}
	return false;
}