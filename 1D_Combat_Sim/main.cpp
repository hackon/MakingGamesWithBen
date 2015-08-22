#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int getNumHumans();
int getNumSkeletons();

int main()
{
	mt19937 randomGen(time(NULL));
	uniform_real_distribution<float> attach(0.0f, 1.0f);

	float humanAttack = 0.6f;
	float maxHumanHealth = 250.0f;
	float humanDamage = 200.0f;
	float currentHumanHealth = maxHumanHealth;

	float skeletonAttack = 0.3f;
	float maxSkeletonHealth = 50.0f;
	float skeletonDamage = 40.0f;
	float currentSkeletonHealth = maxSkeletonHealth;

	float attackResult;

	int startSkeletons;
	int startHumans;
	int numSkeletons;
	int numHumans;

	char turn = 'H';
	
	cout << "*** Skeletons vs Humans" << endl;

	startHumans = numHumans = getNumHumans();
	startSkeletons = numSkeletons = getNumSkeletons();

	while (numHumans > 0 && numSkeletons > 0)
	{
		attackResult = attach(randomGen);

		if (turn == 'H')
		{
			if(attackResult <= humanAttack)
			{
				currentSkeletonHealth -= humanDamage;
				if (currentSkeletonHealth < 0)
				{
					numSkeletons--;
					currentSkeletonHealth = maxSkeletonHealth;
				}
			}
			turn = 'S';
		}
		else
		{
			
			if (attackResult <= skeletonAttack)
			{
				currentHumanHealth -= skeletonDamage;
				if (currentHumanHealth < 0)
				{
					numHumans--;
					currentHumanHealth = maxHumanHealth;
				}
			}
			turn = 'H';
		}
	}

	cout << "Battle is over!!" << endl;

	if (numHumans > 0)
	{
		cout << "Humans won with " << numHumans << " left." << endl;
	}
	else
	{
		cout << "Skeletons won with " << numSkeletons << " left." << endl;
	}

	cout << startHumans - numHumans << " humans and " << startSkeletons - numSkeletons << " skeletons lost their lifes" << endl;

	system("PAUSE");
	return 0;
}

int getNumHumans()
{
	int num;
	cout << "Enter number of humans: ";
	cin >> num;
	return num;
}

int getNumSkeletons()
{
	int num;
	cout << "Enter number of skeletons: ";
	cin >> num;
	return num;
}