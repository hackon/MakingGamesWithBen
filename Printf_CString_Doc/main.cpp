#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main() 
{
	int a = 12123;
	float c = 0.12311f;
	printf("%s, %d, %f", "Hello", a, c );
	printf("%s, %10d, %.2f", "Hello", a, c );

	system("PAUSE");
	return 0;
}