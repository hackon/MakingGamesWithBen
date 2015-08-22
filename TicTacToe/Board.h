#pragma once

class Board
{
	char _board[3][3];
	bool check(int x1, int y1, int x2, int y2, int x3, int y3);
public:
	Board();
	bool play(int x, int y, char player);
	bool hasWinner();
	void printBoard();
};
