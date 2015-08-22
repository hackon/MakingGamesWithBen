#include "Board.h"
#include <iostream>

using namespace std;

bool Board::check(int y1, int x1, int y2, int x2, int y3, int x3)
{
	return _board[y1][x1] == _board[y2][x2] == _board[y3][x3];
}

Board::Board()
{
	for (int x = 0; x < 3; x++)
	{
		for (int  y = 0; y < 3; y++)
		{
			_board[y][x] = ' ';
		}
	}
}

bool Board::play(int x, int y, char player)
{
	_board[y][x] = player;
	return hasWinner();
}

bool Board::hasWinner()
{
	if (check(0, 0, 0, 1, 0, 2) ||
		check(1, 0, 1, 1, 1, 2) ||
		check(2, 0, 2, 1, 2, 2) ||
		check(0, 0, 1, 0, 2, 0) ||
		check(0, 1, 1, 1, 2, 1) ||
		check(0, 2, 1, 0, 2, 0) ||
		check(0, 0, 1, 1, 2, 2) ||
		check(0, 2, 1, 1, 2, 0))
	{
		return true;
	}
	return false;
}

void Board::printBoard()
{
	cout << "|-----|" << endl;
	for (int y = 0; y < 3; y++)
	{
		cout << "|";
		for (int x = 0; x < 3; x++)
		{
			cout << _board[y][x] << "|";
		}
		cout << endl << "|-----|" << endl;
	}
	
}