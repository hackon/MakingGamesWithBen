#include "DialogTree.h"



DialogTree::DialogTree()
{
	
}

void DialogTree::init()
{
	DialogNode *node0 = new DialogNode("Hello brave warrior!");
	DialogNode *node1 = new DialogNode("I don't want to talk to you");
	DialogNode *node2 = new DialogNode("I have a quest for you!");
	DialogNode *node3 = new DialogNode("You'll get 5 gold you gready swin");
	DialogNode *node4 = new DialogNode("Collect ten dandillion.");

	node0->dialogOptions.push_back(DialogOption("Sub noob!", 0, node1));
	node0->dialogOptions.push_back(DialogOption("Hello strange voice!", 0, node2));
	_dialogNodes.push_back(node0);
	node1->dialogOptions.push_back(DialogOption("Aww!", 0, nullptr));
	_dialogNodes.push_back(node1);
	node2->dialogOptions.push_back(DialogOption("K bye", 0, nullptr));
	node2->dialogOptions.push_back(DialogOption("What is it?", 0, node4));
	node2->dialogOptions.push_back(DialogOption("What's the pay?", 0, node3));
	_dialogNodes.push_back(node2);
	node3->dialogOptions.push_back(DialogOption("Ok, what is it", 0, node4));
	node3->dialogOptions.push_back(DialogOption("That sucks im out", 0, nullptr));
	_dialogNodes.push_back(node3);
	node4->dialogOptions.push_back(DialogOption("Let's do it!!", 1, nullptr));
	node4->dialogOptions.push_back(DialogOption("No way", 0, nullptr));
	_dialogNodes.push_back(node4);
}

void DialogTree::destroyTree()
{
	for (int i = 0; i < _dialogNodes.size(); i++)
	{
		delete _dialogNodes[i];
	}

	_dialogNodes.clear();
}

int DialogTree::performDialog()
{
	if (_dialogNodes.empty()) return -1;

	DialogNode *currentNode = _dialogNodes[0];

	while (true)
	{
		cout << currentNode->text << endl << endl;

		for (int i = 0; i < currentNode->dialogOptions.size(); i++)
		{
			cout << i + 1 << ": " << currentNode->dialogOptions[i].text << endl;
		}
		cout << endl;
		int input;
		cin >> input;
		input--;

		if (input < 0 || input >= currentNode->dialogOptions.size())
		{
			cout << "Invalid input!" << endl;
		}else {
			if(currentNode->dialogOptions[input].nextNode == nullptr)
			{
				return currentNode->dialogOptions[input].code;
			}

			currentNode = currentNode->dialogOptions[input].nextNode;
			cout << endl;
		}

	}
}

DialogOption::DialogOption(string txt, int returnCode, DialogNode* nextnode)
{
	text = txt;
	code = returnCode;
	nextNode = nextnode;
}

DialogNode::DialogNode(string txt)
{
	text = txt;
}