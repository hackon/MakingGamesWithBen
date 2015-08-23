#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>

using namespace std;

int main()
{
	char input = ' ';
	string clearScreen(100, '\n');
	while (input != 'q')
	{
		input = _getch();
		cout << clearScreen;
		printf("%c", input);
	}	

	system("PAUSE");
	return 0;
}