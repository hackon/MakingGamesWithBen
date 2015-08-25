#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class DialogNode;

class DialogOption
{
public:
	DialogOption(string txt, int returnCode, DialogNode *nextnode);
	string text;
	int code;
	DialogNode *nextNode;
};

class DialogNode
{
public:
	DialogNode(string txt);
	string text;
	vector<DialogOption> dialogOptions;
};

class DialogTree
{
public:
	DialogTree();
	
	void init();
	void destroyTree();

	int performDialog();
private:
	vector<DialogNode *> _dialogNodes;
};

