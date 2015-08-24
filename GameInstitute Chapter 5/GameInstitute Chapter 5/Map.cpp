// Map.cpp

#include "Map.h"
#include <iostream>
#include "Random.h"
using namespace std;

Map::Map()
{
	// Player starts at origin (0, 0)
	mPlayerXPos = 0;
	mPlayerYPos = 0;
}

int  Map::getPlayerXPos()
{
	return mPlayerXPos;
}

int  Map::getPlayerYPos()
{
	return mPlayerYPos;
}

void Map::movePlayer()
{
	int selection = 1;
	cout << "1) North, 2) East, 3) South, 4) West: ";
	cin >> selection;

	// Update coordinates based on selection.
	switch (selection)
	{
	case 1: // North
		mPlayerYPos++;
		break;
	case 2: // East
		mPlayerXPos++;
		break;
	case 3: // South
		mPlayerYPos--;
		break;
	default: // West
		mPlayerXPos--;
		break;
	}
	cout << endl;
}

std::vector<Monster*> Map::checkRandomEncounter()
{
	int noEnemies = Random(0, 2);
	std::vector<Monster*> monsters;
	while (monsters.size() != noEnemies) {
		int roll = Random(0, 15);

		Monster* monster = 0;

		if (roll >= 0 && roll <= 4)
		{
			monster = new Monster("Orc", 10, 8, 200, 1,
				"Short Sword", 2, 7, 100);

			cout << "You encountered an Orc!" << endl;
			cout << endl;
		}
		else if (roll >= 5 && roll <= 10)
		{
			monster = new Monster("Goblin", 6, 6, 100, 0,
				"Dagger", 1, 5, 150);

			cout << "You encountered a Goblin!" << endl;
			cout << endl;
		}
		else if (roll >= 11 && roll <= 14)
		{
			monster = new Monster("Ogre", 20, 12, 500, 2,
				"Club", 3, 8, 400);

			cout << "You encountered an Ogre!" << endl;
			cout << endl;
		}
		else if (roll == 15)
		{
			monster = new Monster("Orc Lord", 25, 15, 2000, 5,
				"Two Handed Sword", 5, 20, 800);

			cout << "You encountered an Orc Lord!!!" << endl;
			cout << endl;
		}

		monsters.push_back(monster);

	}
	if (monsters.size() != 0) {
		cout << "Prepare for battle!" << endl;
	}
	return monsters;
}

void Map::printPlayerPos()
{
	cout << "Player Position = (" << mPlayerXPos << ", "
		<< mPlayerYPos << ")" << endl << endl;
}