#include "Monster.h"
#include <iostream>

using namespace std;

Monster::Monster()
{
	_name = "noname";
}

Monster::Monster(string name)
{
	_name = name;
}

void Monster::printName()
{
	cout << "Monster is named " << _name << endl;
}