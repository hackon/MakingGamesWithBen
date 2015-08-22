#include <iostream>
#include <string>

using namespace std;

const int numItems = 6;
const string shopItemsNames[numItems] = { "Boots", "Sword", "Helmet", "Kitten", "Poleaxe", "Leggings" };

void printInventory(const int playerInventory[numItems]);
void printShop();
bool buyItems(int playerInventory[]);


int main()
{
	int playerInventory[numItems] = { 0,0,0,1,0,0 };
	
	cout << "*** Welcome to the item shop! ***" << endl;
	
	do
	{
		printShop();
	
		printInventory(playerInventory);

	} while (!buyItems(playerInventory));

	system("PAUSE");
	return 0;
}

void printInventory(const int playerInventory[numItems])
{
	cout << "Your inventory is: " << endl;
	for (int i = 0; i < numItems; i++)
	{
		if(playerInventory[i] > 0)
		{
			cout << playerInventory[i] << " * " << shopItemsNames[i] << endl;
		}
	}
}

void printShop()
{
	for (int i = 0; i < numItems; i++)
	{
		cout << i + 1 << ". " << shopItemsNames[i] << endl;
	}
	cout << "**************" << endl << endl;
}

bool buyItems(int playerInventory[])
{
	cout << "What would you like to buy? Enter -1 to Quit Enter (1-" << numItems << "):";
	int input = 0;
	cin >> input;
	if (input == -1) {
		return true;
	}
	if((input - 1) < 0 || input > numItems)
	{
		cout << "you idiot!!" << endl;
	}
	else
		playerInventory[input-1]++;
	return false;
}