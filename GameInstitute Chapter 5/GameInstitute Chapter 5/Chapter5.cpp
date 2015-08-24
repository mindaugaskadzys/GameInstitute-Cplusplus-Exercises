// Chapter5.cpp

#include "Map.h"
#include "Player.h"
#include "Store.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

//Ex 5.6.5 Random Encounters during rest
//Refactor random encounter function for reuse
bool randomEncounter(Player& player, Map& gameMap) {
	// Check for a random encounter.  This function
	// returns a null pointer if no monsters are
	// encountered.
	std::vector<Monster*> monsters;
	monsters = gameMap.checkRandomEncounter();

	// 'monster' not null, run combat simulation.
	if (monsters.size() != 0)
	{
		// Loop until a 'break' statement.
		while (true)
		{
			// Display hitpoints.
			player.displayHitPoints();
			for (int i = 0; i < monsters.size(); i++) {
				cout << i + 1 << ") ";
				monsters[i]->displayHitPoints();
			}
			cout << endl;

			cout << "Select a monster to attack: ";
			int choice = 1;
			cin >> choice;
			if (choice < 1 && choice > monsters.size()) {
				cout << "Invalid input. Defaulting to first monster." << endl;
				choice = 1;
			}

			// Player's turn to attack first.
			bool runAway = player.attack(*monsters[choice - 1]);

			if (runAway)
				break;

			if (monsters[choice - 1]->isDead())
			{
				player.victory(monsters[choice - 1]->getXPReward(), monsters[choice - 1]->getGoldReward());
				player.levelUp();
				cout << endl;
				monsters.erase(monsters.begin() + choice - 1);
			}
			//end combat if all monsters are dead
			if (monsters.size() == 0) break;

			for (int i = 0; i < monsters.size(); i++)
				monsters[i]->attack(player);

			if (player.isDead())
			{
				player.gameover();
				//return true if the game should end
				return true;
				break;
			}
		}

	}
	//return false if game should continue
	return false;
}

int main()
{
	srand(time(0));

	Map gameMap;

	Player mainPlayer;

	mainPlayer.createClass();

	// Begin adventure.
	bool done = false;
	while (!done)
	{
		// Each loop cycly we output the player position and 
		// a selection menu.

		gameMap.printPlayerPos();

		int selection = 1;
		cout << "1) Move, 2) Rest, 3) View Stats, 4) Equip, 5) Quit: ";
		cin >> selection;

		switch (selection)
		{
		case 1:
			gameMap.movePlayer();
			if (gameMap.getPlayerXPos() == 0 && gameMap.getPlayerYPos() == 1) {
				Store store;
				store.enter(mainPlayer);
			}
			//Ex 5.6.5 Random Encounters During Rest
			//Factored out random encounter for re-use
			done = randomEncounter(mainPlayer, gameMap);
			break;
		case 2:
			mainPlayer.rest();
			//Ex 5.6.5 Random Encounters During Rest
			if (rand() % 100 >= 25) {
				done = randomEncounter(mainPlayer, gameMap);
			}
			break;
		case 3:
			mainPlayer.viewStats();
			break;
		case 4:
			mainPlayer.showEquipMenu();
			break;
		case 5:
			done = true;
			break;
		}
	}
}