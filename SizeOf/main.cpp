#include <iostream>
#include <cstdlib>
#include  <string>
#include <cstdio>
#include <vector>

using namespace std;


int main()
{
	cout <<  sizeof(int) << " int size" << endl;
	cout <<  sizeof(char) << " char size" << endl;
	cout <<  sizeof(double) << " doble size" << endl;
	cout <<  sizeof(float) << " float size" << endl;

	int buffer[10000];

	cout << sizeof(buffer) << " buffer" << endl;

	const int BUFFER_SIZE = 100;
	char myBuffer[BUFFER_SIZE];

	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		cout << myBuffer[i];
	}

	printf("Q!");
	int tmp;
	cin >> tmp;

	return 0;
}