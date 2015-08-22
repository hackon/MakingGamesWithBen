#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

int main()
{
	vector<string> itemNames;
	itemNames.push_back("Gloves");
	itemNames.push_back("Boots");
	itemNames.push_back("Axes");
	itemNames.push_back("Rocks");

	itemNames[1] = itemNames.back();

	for (int i = 0; i < itemNames.size(); i++)
	{
		cout << itemNames[i] << endl;
	}

	cout << itemNames.size() << endl;

	list<string> shopItemNames;

	shopItemNames.push_back("Gloves");
	shopItemNames.push_front("Axes");

	list<string>::iterator iterator;
	for (iterator = shopItemNames.begin(); iterator != shopItemNames.end(); iterator++)
	{
		cout << *iterator << endl;
	}

	system("PAUSE");
	return 0;
}