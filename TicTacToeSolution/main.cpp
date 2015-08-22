#include <iostream>
#include "TicTacToeGame.h"

using namespace std;

int main()
{
	bool isDone = false;
	TicTacToeGame game;
	while (!isDone)
	{
		game.playGame();
		cout << "Would you like to play again?? (Y/N)";
		char input;
		cin >> input;
		if (input == 'N' || input == 'n')
		{
			isDone = true;
		}
	}

	system("PAUSE");
	return 0;
}