#include <iostream>
#include <string>

#include "Item.h"
#include "Player.h"
#include "Shop.h"
using namespace std;

void initShops(list<Shop> &shops);
void initPlayer(Player &player);
void enterShop(Player &player, Shop &shop);

int main()
{
	list<Shop> shops;
	list<Shop>::iterator lit;
	Player player;
	string shopName;;


	initPlayer(player);
	initShops(shops);

	bool isDone = false;

	while (!isDone)
	{
		cout << "Shops" << endl;
		int i = 0;
		for (lit = shops.begin(); lit != shops.end(); lit++)
		{
			cout << i << ". " << (*lit).getName() << endl;
			i++;
		}
		
		cout << "What shop would you like to enter? Q for Quit: ";
		cin.clear();
		getline(cin, shopName);

		if(shopName == "Q" || shopName == "q")
		{
			isDone = true;
		}
		else
		{
			for (lit = shops.begin(); lit != shops.end(); lit++)
			{
				if((*lit).getName() == shopName)
				{
					enterShop(player, (*lit));
				}
			}
		}
	}


	system("PAUSE");
	return 0;
}

void initShops(list<Shop> &shops)
{
	shops.push_back(Shop("Bills Leather Shop", 500 ));
	shops.back().addItem(Item("Leather Botts", 50));
	shops.back().addItem(Item("Leather Hat", 50));
	shops.back().addItem(Item("Leather Gloves", 50));
	shops.back().addItem(Item("Leather Gauntlets", 50));
	shops.back().addItem(Item("Leather Chestplate", 100));

	shops.push_back(Shop("The Blacksmith", 1500 ));
	shops.back().addItem(Item("Iron Botts", 100));
	shops.back().addItem(Item("Iron Hat", 100));
	shops.back().addItem(Item("Iron Gloves", 100));
	shops.back().addItem(Item("Iron Gauntlets", 100));
	shops.back().addItem(Item("Iron Chestplate", 200));
	shops.back().addItem(Item("Iron Sword", 150));
	shops.back().addItem(Item("Iron Shield", 150));

	shops.push_back(Shop("Beverly's Fruity Fruit Shop", 250 ));
	shops.back().addItem(Item("Grapes", 5));
	shops.back().addItem(Item("Apple", 5));
	shops.back().addItem(Item("Orange", 5));
	shops.back().addItem(Item("Watermelon", 5));
	shops.back().addItem(Item("Tomato", 10));



}

void initPlayer(Player &player)
{
	cout << "Enter name: ";
	string name;
	getline(cin, name);
	player.init(name, 100);
	player.addItem(Item("Bronze Sword", 5));
}

void enterShop(Player &player, Shop &shop)
{
	bool isDone = false;
	char input;
	string itenName;
	Item newItem("NOITEM", 0);

	while (!isDone)
	{
		shop.printShop();
		player.printInventory();

		cout << "Would you like to buy or sell? Q to quit. (B/S): ";
		cin >> input;
		if (input == 'Q' || input == 'q')
		{
			return;
		}
		if (input == 'B' || input == 'b')
		{
			cout << "Enter the item you wish to buy: ";
			getline(cin, itenName);

			if (shop.purchaseItem(itenName, newItem))
			{
				player.addItem(newItem);
			}
			else
			{
				cout << "That is an invalid item" << endl;
				system("PAUSE");
			}
		}
		else
		{
			cout << "Enter the item you wish to sell: ";
			getline(cin, itenName); 

			if (player.removeItem(itenName, newItem))
			{
				shop.addItem(newItem);
			}
			else
			{
				cout << "That is an invalid item" << endl;
				system("PAUSE");
			}
		}
	}
}