#include <iostream>
#include "GameManager.h"

using namespace std;

int main()
{
	GameManager gameManager;
	do
	{
		gameManager.init();
	} while (gameManager.run());

}