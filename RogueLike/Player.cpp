#include "Player.h"
#include <random>
#include <ctime>
using namespace std;
void Player::init(int level, int health, int attack, int defense, int experience)
{
	_level = level;
	_health = health;
	_attack = attack;
	_defence = defense;
	_experience = experience;
}

int Player::attack()
{
	static default_random_engine engine(time(NULL));
	uniform_int_distribution<int> attackRoll(0, _attack);

	return attackRoll(engine);
}

void Player::setPosition(int x, int y)
{
	_x = x;
	_y = y;
}

void Player::getPosition(int& x, int& y)
{
	x = _x;
	y = _y;
}

void Player::addExperience(int experience)
{
	_experience += experience;
	while(_experience > 50)
	{
		printf("Leveled Up");
		_experience -= 50;
		_attack += 10;
		_defence += 5;
		_health += 10;
		_level++;
		system("PAUSE");
	}
}

int Player::takeDamage(int attack)
{
	attack -= _defence;
	if (attack > 0)
	{
		_health -= attack;
		if (_health <= 0)
		{
			return 1;
		}
	}
	return 0;
}