#include "Enemy.h"
#include <random>
#include <ctime>


Enemy::Enemy(string name, char tile, int level, int attack, int defence, int health, int experienceValue)
{
	_name = name;
	_tile = tile;
	_level = level;
	_attack = attack;
	_defence = defence;
	_health = health;
	_experienceValue = experienceValue;
}

int Enemy::attack()
{
	static default_random_engine engine(time(NULL));
	uniform_int_distribution<int> attackRoll(0, _attack);

	return attackRoll(engine);
}

int Enemy::takeDamage(int attack)
{
	attack -= _defence;
	if (attack > 0)
	{
		_health -= attack;
		if(_health <= 0)
		{
			return _experienceValue;
		}
	}
	return 0;
}

void Enemy::setPosition(int x, int y)
{
	_x = x;
	_y = y;
}

void Enemy::getPosition(int& x, int& y)
{
	x = _x;
	y = _y;
}

char Enemy::getMove(int playerX, int playerY)
{
	static default_random_engine engine(time(NULL));
	uniform_int_distribution<int> moveRoll(0, 6);

	int distance;
	int dx = _x - playerX;
	int dy = _y - playerY;
	int adx = abs(dx);
	int ady = abs(dy);;
	
	distance = adx + ady;

	if(distance <= 5)
	{
		//Moving along X axis
		if(adx > ady)
		{
			if(dx > 0)
			{
				return 'A';
			}
			else
			{
				return 'D';
			}
		}
		else
		{
			if (dy > 0)
			{
				return 'W';
			}
			else
			{
				return 'S';
			}
		}
	}
	int randomMove = moveRoll(engine);
	switch (randomMove)
	{
	case 0:
		return 'A';
	case 1:
		return 'W';
	case 2:
		return 'S';
	case 3:
		return 'D';
	default:
		return '.';

	}
}