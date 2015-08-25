#include <iostream>
#include <cstdlib>
#include <string>
#include <list>

#include "DialogTree.h"

using namespace std;

int main()
{
	DialogTree dialogTree;

	dialogTree.init();

	int result = dialogTree.performDialog();

	if(result == 1)
	{
		cout << "U accepted the quest!";
	}

	dialogTree.destroyTree();

	cout << "Enter any key to continue...\n";
	int tmp;
	cin >> tmp;
	return 0;
}