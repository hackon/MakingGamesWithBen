#include "Level.h"
#include <fstream>
#include <iostream>
#include <cstdio>

Level::Level()
{
}

void Level::load(string fileName, Player &player)
{
	ifstream file;
	file.open(fileName);
	if(file.fail())
	{
		perror(fileName.c_str());
		system("PAUSE");
		exit(1);
	}

	string line;

	while (getline(file, line))
	{
		_levelData.push_back(line);
	}
	file.close();

	char tile;
	for (int i = 0; i < _levelData.size(); i++)
	{
		for (int j = 0; j < _levelData[i].size(); j++)
		{
			tile = _levelData[i][j];
			switch (tile)
			{
			case '@':
				player.setPosition(j, i);
				break;
			case 'D':
				_enemies.push_back(Enemy("Dragon", 'D', 100, 2000, 2000, 2000, 5000000));
				_enemies.back().setPosition(j, i);
				break;
			case 'O':
				_enemies.push_back(Enemy("Ogre", 'O', 4, 20, 20, 200, 500));
				_enemies.back().setPosition(j, i);
				break;
			case 'g':
				_enemies.push_back(Enemy("Goblin", 'g', 2, 10, 5, 40, 50));
				_enemies.back().setPosition(j, i);
				break;
			case 'S':
				_enemies.push_back(Enemy("Snake", 'S', 1, 3, 1, 10, 10));
				_enemies.back().setPosition(j, i);
				break;
			}
		}
	}
}

void Level::print()
{
	cout <<  string(100, '\n');
	for (int i = 0; i < _levelData.size(); i++)
	{
		printf("%s\n", _levelData[i].c_str());
	}
	printf("\n");
}

void Level::movePlayer(char input, Player& player)
{
	int playerX;
	int playerY;
	player.getPosition(playerX, playerY);

	switch (input)
	{
	case 'w': //up
	case 'W':
		processPlayerMove(player, playerX, playerY - 1);
		break;
	case 's': //down
	case 'S':
		processPlayerMove(player, playerX, playerY + 1);
		break;
	case 'a': //left
	case 'A':
		processPlayerMove(player, playerX - 1, playerY);
		break;
	case 'd': //right
	case 'D':
		processPlayerMove(player, playerX + 1, playerY);
		break;
	default:
		printf("Invalid input");
		break;
	}
}

void Level::updateMonsters(Player &player)
{
	char aiMove;
	int playerX;
	int playerY;
	int enemyX;
	int enemyY;
	player.getPosition(playerX, playerY);
	for (int i = 0; i < _enemies.size(); i++)
	{
		_enemies[i].getPosition(enemyX, enemyY);
		aiMove = _enemies[i].getMove(playerX, playerY);
		switch (aiMove)
		{
		case 'w': //up
		case 'W':
			processEnemyMove(player, i, enemyX, enemyY - 1);
			break;
		case 's': //down
		case 'S':
			processEnemyMove(player, i, enemyX, enemyY + 1);
			break;
		case 'a': //left
		case 'A':
			processEnemyMove(player, i, enemyX - 1, enemyY);
			break;
		case 'd': //right
		case 'D':
			processEnemyMove(player, i, enemyX + 1, enemyY);
			break;
		}
	}
}

char Level::getTile(int x, int y)
{
	return _levelData[y][x];
}

void Level::setTile(int x, int y, char tile)
{
	_levelData[y][x] = tile;
}

void Level::processPlayerMove(Player& player, int targetX, int targetY)
{
	int playerX;
	int playerY;
	player.getPosition(playerX, playerY);

	char moveTile;
	moveTile = getTile(targetX, targetY);
	switch (moveTile)
	{
	case '.':
		player.setPosition(targetX, targetY);
		setTile(targetX, targetY, '@');
		setTile(playerX, playerY, '.');
	case '#':
		break;
	default:
		battleMonster(player, targetX, targetY);
		break;
	}
}

void Level::processEnemyMove(Player& player, int enemyIndex, int targetX, int targetY)
{
	int playerX;
	int playerY;
	int enemyX;
	int enemyY;
	_enemies[enemyIndex].getPosition(enemyX, enemyY);
	player.getPosition(playerX, playerY);

	char moveTile;
	moveTile = getTile(targetX, targetY);
	switch (moveTile)
	{
	case '.':
		_enemies[enemyIndex].setPosition(targetX, targetY);
		setTile(targetX, targetY, _enemies[enemyIndex].getTile());
		setTile(enemyX, enemyY, '.');
	case '#':
		break;
	case '@':
		battleMonster(player, enemyX, enemyY);
			break;
	default:
		break;
	}
}

void Level::battleMonster(Player& player, int targetX, int targetY)
{
	int enemyX;
	int enemyY;
	int playerX;
	int playerY;
	int attackRoll;
	int attackResult;

	player.getPosition(playerX, playerY);

	for (int i = 0; i < _enemies.size(); i++)
	{
		_enemies[i].getPosition(enemyX, enemyY);
		if(targetX == enemyX && targetY == enemyY)
		{
			print();
			//Battle
			attackRoll = player.attack();
			printf("Player attacked %s with a roll of %d\n", _enemies[i].getName().c_str(), attackRoll);
			attackResult = _enemies[i].takeDamage(attackRoll);
			if(attackResult != 0)
			{
				setTile(targetX, targetY, '.');
				printf("%s died!\n", _enemies[i].getName().c_str());
				_enemies[i] = _enemies.back();
				_enemies.pop_back();
				i--;
				player.addExperience(attackResult);
				return;
			}
			
			attackRoll = _enemies[i].attack();
			printf("%s attacked Player with a roll of %d\n", _enemies[i].getName().c_str(), attackRoll);
			attackResult = player.takeDamage(attackRoll);
			if (attackResult != 0)
			{
				setTile(playerX, playerY, 'X');
				printf("You died!!!\n");
				exit(0);
			}

			system("PAUSE");
			return;
		}
	}
}