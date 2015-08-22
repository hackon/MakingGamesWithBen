#include <iostream>
#include <string>

using namespace std;

class Monster
{
	string _name;
public:
	string getName()
	{
		return _name;
	}
	void setName(string name)
	{
		_name = name;
	}
	void growl()
	{
		cout << _name << " growls!!!" << endl;
	}
};

int main()
{
	Monster monster1;
	monster1.setName("Akaname");
	monster1.growl();

	system("PAUSE");
	return 0;
}