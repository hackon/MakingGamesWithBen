#include "Item.h"



Item::Item(string name, int value)
{
	_name = name;
	_value = value;
}

void Item::add()
{
	_count++;
}

void Item::remove()
{
	if (_count > 0)
	{
		_count--;
	}
}