#pragma once
#include "Position.h"


class Position
{
public:
	Position();
	Position(int x, int y);
	int getX() { return _x; }
	int getY() { return _y; }
private:
	int _x;
	int _y;
};
