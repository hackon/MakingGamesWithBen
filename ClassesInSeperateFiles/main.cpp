#include <iostream>
#include <string>
#include "Monster.h"

using namespace std;

int main()
{
	Monster monsters[100];

	Monster monster1("Akaname");
	Monster monster2("Tora");

	monster1.printName();
	monster2.printName();

	system("PAUSE");
	return 0;
}