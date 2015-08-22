#pragma once

class TicTacToeGame
{
	char _board[3][3];
	void clearBoard();
	void printBoard();
	int getX();
	int getY();
	bool placeMarker(int x, int y, char currentPlayer);
	bool checkForVictory(const char currentPlayer);
public:
	TicTacToeGame();
	void playGame();
};
