#include <iostream>
#include <string>

using namespace std;

class CheckerBoard
{
	char board[8][8];
public:
	void init()
	{
		for (int y = 0; y < 8; y++)
		{
			for (int x = 0; x < 8; x++)
			{
				if(((x + y) % 2) == 0)
				{
					board[y][x] = '-';
				}
				else
				{
					board[y][x] = '*';
				}
			}
		}
	}
	void print()
	{
		for (int y = 0; y < 8; y++)
		{
			for (int x = 0; x < 8; x++)
			{
				cout << board[y][x];
			}
			cout << endl;
		}
	}
};

int main()
{
	CheckerBoard checkerBoard;
	checkerBoard.init();
	checkerBoard.print();

	system("PAUSE");
	return 0;
}