#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	ofstream outputFile;
	ifstream inputFile;

	/*outputFile.open("myFile.txt");
	if(outputFile.fail())
	{
		perror("myFile.txt");
		return 1;
	}

	outputFile << "Hello World" << endl;
	outputFile.close();
	*/

	inputFile.open("myFile.txt");
	if(inputFile.fail())
	{
		perror("myFile.txt");
		system("PAUSE");
		return 1;
	}

	string input;
	//getline(inputFile, input);
	while (getline(inputFile, input))
	{
		cout << input << endl;
	}

	cout << input;


	system("PAUSE");
	return 0;
}