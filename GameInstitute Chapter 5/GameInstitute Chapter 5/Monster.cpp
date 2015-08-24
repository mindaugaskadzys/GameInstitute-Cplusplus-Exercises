// Monster.cpp

#include <iostream>
#include <string>
#include "Monster.h"
#include "Player.h"
#include "Random.h"
using namespace std;

Monster::Monster(const std::string& name, int hp, int acc,
	int xpReward, int armor, const std::string& weaponName,
	int lowDamage, int highDamage, int goldReward)
{
	mName = name;
	mHitPoints = hp;
	mAccuracy = acc;
	mExpReward = xpReward;
	mArmor = armor;
	mWeapon.mName = weaponName;
	mWeapon.mDamageRange.mLow = lowDamage;
	mWeapon.mDamageRange.mHigh = highDamage;

	//Ex 5.6.1 Gold Modification
	mGoldReward = goldReward;
}

bool Monster::isDead()
{
	return mHitPoints <= 0;
}

int Monster::getXPReward()
{
	return mExpReward;
}

std::string Monster::getName()
{
	return mName;
}

int Monster::getArmor()
{
	return mArmor;
}

//Ex 5.6.1 Gold Modification
int Monster::getGoldReward()
{
	//Return base reward + bonus based on dice roll
	return mGoldReward + mGoldReward*0.1*Random(0, 10);
}

void Monster::attack(Player& player)
{
	cout << "A " << mName << " attacks you "
		<< "with a " << mWeapon.mName << endl;

	// Test to see if the monster hit the player.
	if (Random(0, 20) < mAccuracy)
	{
		// Generate a damage value based on the weapons range.
		int damage = Random(mWeapon.mDamageRange);

		// Subtract the player's armor from damage to
		// simulate armor weakening the attack.  Note that
		// if the armor > damage this results in a negative
		// number.
		int totalDamage = damage - player.getArmor()->mArmorValue;

		// If totalDamage <= 0, then we say that, although
		// the attack hit, it did not penetrate the armor.
		if (totalDamage <= 0)
		{
			cout << "The monster's attack failed to "
				<< "penetrate your armor." << endl;
		}
		else
		{
			cout << "You are hit for " << totalDamage
				<< " damage!" << endl;

			// Subtract from players hitpoints.
			player.takeDamage(totalDamage);
		}
	}
	else
	{
		cout << "The " << mName << " missed!" << endl;
	}
	cout << endl;
}

void Monster::takeDamage(int damage)
{
	mHitPoints -= damage;
}

void Monster::displayHitPoints()
{
	cout << mName << "'s hitpoints = " << mHitPoints << endl;
}