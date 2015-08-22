#include "Input.h"
#include <iostream>

using namespace std;
void Input::getCorrInput(int& x, int& y)
{
	cout << "Enter x,y coordinates." << endl << "X: ";
	cin >> x ;
	cout << "Y: ";
	cin >> y;
}

void Input::getPlayers(char& player1, char& player2)
{
	cout << "Enter player1's character: ";
	cin >> player1;
	cout << "Enter player2's character: ";
	cin >> player2;
}