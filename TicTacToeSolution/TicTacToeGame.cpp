#include "TicTacToeGame.h"
#include <ostream>
#include <iostream>

using namespace std;
void TicTacToeGame::clearBoard()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			_board[i][j] = ' ';
		}
	}
}

void TicTacToeGame::printBoard()
{
	cout << endl;
	cout << " |1-2-3|" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << " |-----|" << endl;
		cout << i + 1 << "|" << _board[i][0] << "|" << _board[i][1] << "|" << _board[i][2] << "|" << endl;
	}
	cout << " |-----|" << endl;
}

int TicTacToeGame::getX()
{
	bool isBadInput = true;
	int x;
	while (isBadInput)
	{
		cout << "Enter X:";
		cin >> x;
		if(x < 1 || x > 3)
		{
			cout << "Invalid input" << endl;
		}
		else
		{
			isBadInput = false;
		}
	}
	return --x;
}

int TicTacToeGame::getY()
{
	bool isBadInput = true;
	int y;
	while (isBadInput)
	{
		cout << "Enter Y:";
		cin >> y;
		if (y < 1 || y > 3)
		{
			cout << "Invalid input" << endl;
		}
		else
		{
			isBadInput = false;
		}
	}
	return --y;
}

bool TicTacToeGame::placeMarker(int x, int y, char currentPlayer)
{
	if (_board[y][x] != ' ') return false;

	_board[y][x] = currentPlayer;
	return true;
}

bool TicTacToeGame::checkForVictory(const char currentPlayer)
{


	for (int i = 0; i < 3; i++)
	{
		if (_board[i][0] == currentPlayer && _board[i][0] == _board[i][1] && _board[i][1] == _board[i][2])
		{
			return true;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (_board[0][i] == currentPlayer && _board[0][i] == _board[1][i] && _board[1][i] == _board[2][i])
		{
			return true;
		}
	}

	if (_board[0][0] == currentPlayer && _board[0][0] == _board[1][1] && _board[1][1] == _board[2][2])
	{
		return true;
	}
	if (_board[2][0] == currentPlayer && _board[2][0] == _board[1][1] && _board[1][1] == _board[0][2])
	{
		return true;
	}
	return false;
}

TicTacToeGame::TicTacToeGame()
{
}

void TicTacToeGame::playGame()
{
	clearBoard();

	char player1 = 'X', player2 = 'O';

	char currentPlayer = player1;
	int x, y;
	int turn = 0;

	bool isDone = false;

	while (!isDone)
	{
		printBoard();
		x = getX();
		y = getY();

		if (!placeMarker(x, y, currentPlayer))
		{
			cout << "That spot is occupado" << endl;
		} 
		else
		{
			turn++;
			if (checkForVictory(currentPlayer))
			{
				cout << "The game is over! " << currentPlayer << " won!!!" << endl;
				isDone = true;
			} else if(turn == 9)
			{
				cout << "Its a tie game" << endl;
				isDone = true;
			}
			if (currentPlayer == player1)
			{
				currentPlayer = player2;
			}
			else
			{
				currentPlayer = player1;
			}
		}
	}

}