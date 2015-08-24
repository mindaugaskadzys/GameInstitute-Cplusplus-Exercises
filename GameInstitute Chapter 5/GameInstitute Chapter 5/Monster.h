// Monster.h

#ifndef MONSTER_H
#define MONSTER_H

#include "Weapon.h"
#include <string>

// "Forward class declaration" so that we can use the Player
// class without having defined it yet.  This idea is 
// similar to a function declaration.

class Player;

class Monster
{
public:
	Monster(const std::string& name, int hp, int acc,
		int xpReward, int armor, const std::string& weaponName,
		int lowDamage, int highDamage, int goldReward);

	bool isDead();

	int         getXPReward();
	std::string getName();
	int         getArmor();

	//Ex 5.6.1 Gold Modification
	int getGoldReward();

	void attack(Player& player);
	void takeDamage(int damage);
	void displayHitPoints();

private:
	std::string mName;
	int         mHitPoints;
	int         mAccuracy;
	int         mExpReward;
	int         mArmor;
	Weapon      mWeapon;

	//Ex 5.6.1 Gold Modification
	int mGoldReward;
};

#endif //MONSTER_H