#pragma once
#include "Position.h"
#include <string>

class Player
{
public:
	void init(int level, int healthj, int attack, int defense, int experience);
	
	int attack();
	
	void setPosition(int x, int y);
	void getPosition(int &x, int &y);
	void addExperience(int experience);
	int takeDamage(int damage);
private:
	int _level;
	int _health;
	int _attack;
	int _defence;
	int _experience;
	int _x;
	int _y;

};
