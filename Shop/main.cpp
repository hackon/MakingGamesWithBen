#include <iostream>
#include <string>

using namespace std;

int main()
{
	const int numItems = 6;
	string shopItemsNames[numItems] = {"Boots", "Sword", "Helmet", "Kitten", "Poleaxe", "Leggings"};

	cout << "*** Welcome to the item shop! ***" << endl;
	for (int i = 0; i < numItems; i++)
	{
		cout << shopItemsNames[i] << endl;
	}
	
	cout << "What would you like to buy?" << endl;
	system("PAUSE");
	return 0;
}