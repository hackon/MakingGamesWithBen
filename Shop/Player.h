#pragma once
#include <string>
#include "Item.h"
#include <list>

using namespace std;
class Player
{
public:
	Player();
	void init(string name, int money);

	void printInventory();

	bool removeItem(string name, Item &item);
	void addItem(Item newItem);

	int getMoney() { return _money; }
	void subtractMoney(int amount) { _money -= amount; }

private:
	std::string _name;
	list<Item> _items;
	int _money;
};

