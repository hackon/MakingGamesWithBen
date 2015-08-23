#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>

using namespace std;

int main()
{
	char input = ' ';
	while (input != 'q')
	{
		input = _getch();
		printf("%c", input);
	}	

	system("PAUSE");
	return 0;
}