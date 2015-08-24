// Player.cpp

#include <iostream>
#include "Player.h"
#include "Random.h"
#include <string>
#include <algorithm>
using namespace std;

Player::Player()
{
	mName = "Default";
	mClassName = "Default";
	mAccuracy = 0;
	mHitPoints = 0;
	mMaxHitPoints = 0;
	mExpPoints = 0;
	mNextLevelExp = 0;
	mLevel = 0;

	mArmor = new Armor();
	mWeapon = new Weapon();

	//Ex 5.6.1 Gold Modification
	mGoldAmount = 10000;

	//Ex 5.6.4 Magic Points
	mMagicPoints = 0;
	mMaxMagicPoints = 0;
}

Player::~Player() {
	delete mArmor;
	delete mWeapon;
	mInventory.erase(mInventory.begin(), mInventory.end());
}

bool Player::isDead()
{
	return mHitPoints <= 0;
}

Armor* Player::getArmor()
{
	return mArmor;
}

Weapon* Player::getWeapon()
{
	return mWeapon;
}

void Player::takeDamage(int damage)
{
	mHitPoints -= damage;
}

void Player::createClass()
{
	cout << "CHARACTER CLASS GENERATION" << endl;
	cout << "==========================" << endl;

	// Input character's name.
	cout << "Enter your character's name: ";
	getline(cin, mName);

	// Character selection.
	cout << "Please select a character class number..." << endl;
	cout << "1)Fighter 2)Wizard 3)Cleric 4)Thief : ";

	int characterNum = 1;
	cin >> characterNum;

	switch (characterNum)
	{
	case 1:  // Fighter
		mClassName = "Fighter";
		mAccuracy = 10;
		mHitPoints = 20;
		mMaxHitPoints = 20;
		mExpPoints = 0;
		mNextLevelExp = 200;
		mLevel = 1;

		//Ex 5.6.6 Store
		//mArmor        = 4;
		mArmor->mName = "Scale Armor";
		mArmor->mCost = 650;
		mArmor->mArmorValue = 4;

		mWeapon->mName = "Long Sword";
		mWeapon->mCost = 100;
		mWeapon->mDamageRange.mLow = 1;
		mWeapon->mDamageRange.mHigh = 8;

		//Ex 5.6.4 Magic Points
		mMagicPoints = 3;
		mMaxMagicPoints = 3;
		break;
	case 2:  // Wizard
		mClassName = "Wizard";
		mAccuracy = 5;
		mHitPoints = 10;
		mMaxHitPoints = 10;
		mExpPoints = 0;
		mNextLevelExp = 200;
		mLevel = 1;

		//Ex 5.6.6 Store
		//mArmor        = 1;
		mArmor->mName = "Robe";
		mArmor->mCost = 20;
		mArmor->mArmorValue = 1;

		mWeapon->mName = "Staff";
		mWeapon->mCost = 100;
		mWeapon->mDamageRange.mLow = 1;
		mWeapon->mDamageRange.mHigh = 4;

		//Ex 5.6.4 Magic Points
		mMagicPoints = 10;
		mMaxMagicPoints = 10;
		break;
	case 3:  // Cleric
		mClassName = "Cleric";
		mAccuracy = 8;
		mHitPoints = 15;
		mMaxHitPoints = 15;
		mExpPoints = 0;
		mNextLevelExp = 200;
		mLevel = 1;

		//Ex 5.6.6 Store
		//mArmor        = 3;
		mArmor->mName = "Chainmail Armor";
		mArmor->mCost = 500;
		mArmor->mArmorValue = 3;

		mWeapon->mName = "Flail";
		mWeapon->mCost = 100;
		mWeapon->mDamageRange.mLow = 1;
		mWeapon->mDamageRange.mHigh = 6;

		//Ex 5.6.4 Magic Points
		mMagicPoints = 6;
		mMaxMagicPoints = 6;
		break;
	default: // Thief
		mClassName = "Thief";
		mAccuracy = 7;
		mHitPoints = 12;
		mMaxHitPoints = 12;
		mExpPoints = 0;
		mNextLevelExp = 200;
		mLevel = 1;

		//Ex 5.6.6 Store
		//mArmor        = 2;
		mArmor->mName = "Leather Armor";
		mArmor->mCost = 200;
		mArmor->mArmorValue = 2;

		mWeapon->mName = "Short Sword";
		mWeapon->mCost = 100;
		mWeapon->mDamageRange.mLow = 1;
		mWeapon->mDamageRange.mHigh = 6;

		//Ex 5.6.4 Magic Points
		mMagicPoints = 3;
		mMaxMagicPoints = 3;
		break;
	}

	//Ex 5.6.2 Race Modification
	cout << endl;
	cout << "Please select a character race number..." << endl << endl;
	cout << "1)Human, no bonus/penalty. " << endl
		<< "2)Elf, +4 accuracy, -2 hit points. " << endl
		<< "3)Dwarf, +5 hit points, -2 accuracy. " << endl << endl
		<< "Enter your pick: " << endl;

	characterNum = 1;
	cin >> characterNum;

	switch (characterNum)
	{
	case 1:
		mRaceName = "Human";
		break;
	case 2:
		mRaceName = "Elf";
		mAccuracy += 4;
		mHitPoints -= 2;
		mMaxHitPoints -= 2;
		break;
	case 3: default:
		mRaceName = "Dwarf";
		mAccuracy -= 2;
		mHitPoints += 5;
		mMaxHitPoints += 5;
		break;
	}

	//Ex 5.6.4 Magic Points
	initSpells();
}

//Ex 5.6.4 Magic Points
void Player::initSpells() {
	mSpellBook.resize(3);
	Spell magicMissile, fireball, quake;

	magicMissile.mName = "Magic Missile";
	magicMissile.mDamageRange = { 2, 5 };
	magicMissile.mMagicPointsRequired = 4;
	mSpellBook[0] = magicMissile;

	fireball.mName = "Fireball";
	fireball.mDamageRange = { 6, 8 };
	fireball.mMagicPointsRequired = 6;
	mSpellBook[1] = fireball;

	quake.mName = "Quake";
	quake.mDamageRange = { 10, 10 };
	quake.mMagicPointsRequired = 10;
	mSpellBook[2] = quake;
}

void Player::castSpell(Monster& target) {
	cout << "You have " << mMagicPoints << "MP. Select the spell you want to cast... " << endl << endl;
	for (unsigned int i = 0; i < mSpellBook.size(); i++) {
		cout << (i + 1) << ") " << mSpellBook[i].mName << " (" << mSpellBook[i].mMagicPointsRequired << "MP). ";
	}
	cout << mSpellBook.size() + 1 << ") Cancel. " << endl;
	unsigned int selection = 1;
	cin >> selection;
	selection -= 1;
	if (selection < mSpellBook.size() && selection >= 0) {
		if (mSpellBook[selection].mMagicPointsRequired > mMagicPoints) {
			cout << "Not enough magic points!" << endl;
			castSpell(target); //try again
		}
		else {
			int damageDealt = Random(mSpellBook[selection].mDamageRange);
			cout << "You cast " << mSpellBook[selection].mName << " for " << damageDealt << " damage!!" << endl;
			mMagicPoints -= mSpellBook[selection].mMagicPointsRequired;
			target.takeDamage(damageDealt);
		}
	}
	else {
		cout << "Cancelling..." << endl;
	}
}

bool Player::attack(Monster& monster)
{
	// Combat is turned based: display an options menu.  You can,
	// of course, extend this to let the player use an item,
	// cast a spell, and so on.
	int selection = 1;
	cout << "1) Attack, 2) Spell, 3) Item, 4) Run: ";
	cin >> selection;
	cout << endl;

	switch (selection)
	{
	case 1:
		cout << "You attack an " << monster.getName()
			<< " with a " << mWeapon->mName << endl;

		if (Random(0, 20) < mAccuracy)
		{
			int damage = Random(mWeapon->mDamageRange);

			int totalDamage = damage - monster.getArmor();

			if (totalDamage <= 0)
			{
				cout << "Your attack failed to penetrate "
					<< "the armor." << endl;
			}
			else
			{
				cout << "You attack for " << totalDamage
					<< " damage!" << endl;

				// Subtract from monster's hitpoints.
				monster.takeDamage(totalDamage);
			}
		}
		else
		{
			cout << "You miss!" << endl;
		}
		cout << endl;
		break;
		//Ex 5.6.4 Magic Points
	case 2:
		castSpell(monster);
		break;
	case 3:
		int potionsStart;
		potionsStart = -1;
		cout << "Choose an item to use: " << endl;
		for (int i = 0; i < mInventory.size(); i++) {
			if (mInventory[i]->getItemType() == Potions) {
				if (potionsStart == -1)
					potionsStart = i;

				cout << i - potionsStart + 1 << ") ";
				mInventory[i]->printValues();
			}
		}
		cin >> selection;
		if (potionsStart == -1)
			cout << "Empty." << endl;
		if (selection < potionsStart + 1 || selection > mInventory.size() - potionsStart) {
			cout << "Invalid choice. " << endl;
		}
		else {
			Potion* potion = dynamic_cast<Potion*>(mInventory[selection + potionsStart - 1]);
			if (potion->mApplyOnSelf) {
				cout << "You use " << potion->mName << " to heal " << potion->mEffectValue << "!" << endl;
				mHitPoints = mHitPoints + potion->mEffectValue > mMaxHitPoints ? mMaxHitPoints : mHitPoints + potion->mEffectValue;
			}
			else {
				cout << "You use " << potion->mName << " to deal " << potion->mEffectValue << " to the enemy!" << endl;
				monster.takeDamage(potion->mEffectValue);
			}
			removeFromInventory(potion->mName);
		}
		break;
	case 4:
		// 25 % chance of being able to run.
		int roll = Random(1, 4);

		if (roll == 1)
		{
			cout << "You run away!" << endl;
			return true;//<--Return out of the function.
		}
		else
		{
			cout << "You could not escape!" << endl;
			break;
		}
	}

	return false;
}

void Player::levelUp()
{
	if (mExpPoints >= mNextLevelExp)
	{
		cout << "You gained a level!" << endl;

		// Increment level.
		mLevel++;

		// Set experience points required for next level.
		mNextLevelExp = mLevel * mLevel * 1000;

		// Increase stats randomly.
		/*mAccuracy     += Random(1, 3);
		mMaxHitPoints += Random(2, 6);
		mArmor        += Random(1, 2);*/

		// Ex 5.6.3 Level up modification
		if (mClassName.compare("Fighter")) {
			mAccuracy += Random(1, 3);
			mMaxHitPoints += Random(1, 3);
			mMaxMagicPoints += Random(1, 2);
		}
		else if (mClassName.compare("Wizard")) {
			mAccuracy += 3;
			mMaxHitPoints += Random(0, 2);
			mMaxMagicPoints += Random(3, 5);
		}
		else if (mClassName.compare("Cleric")) {
			mAccuracy += 1;
			mMaxHitPoints += Random(4, 6);
			mMaxMagicPoints += Random(2, 4);
		}
		else {
			//must be Thief
			mAccuracy += Random(2, 4);
			mMaxHitPoints += Random(1, 3);
			mMaxMagicPoints += Random(1, 3);
		}

		// Give player full hitpoints when they level up.
		mHitPoints = mMaxHitPoints;
		mMagicPoints = mMaxMagicPoints;
	}
}

void Player::rest()
{
	cout << "Resting..." << endl;

	mHitPoints = mMaxHitPoints;
	mMagicPoints = mMaxMagicPoints;

	// TODO: Modify function so that random enemy encounters
	// are possible when resting.
}

void Player::viewStats()
{
	cout << "PLAYER STATS" << endl;
	cout << "============" << endl;
	cout << endl;

	cout << "Name            = " << mName << endl;
	cout << "Class           = " << mClassName << endl;
	//Ex 5.6.2 Race Modification
	cout << "Race            = " << mRaceName << endl;
	cout << "Accuracy        = " << mAccuracy << endl;
	cout << "Hitpoints       = " << mHitPoints << endl;
	cout << "MaxHitpoints    = " << mMaxHitPoints << endl;
	//Ex 5.6.4 Magic Points
	cout << "MagicPoints     = " << mMagicPoints << endl;
	cout << "MaxMagicPoints  = " << mMaxMagicPoints << endl;
	cout << "XP              = " << mExpPoints << endl;
	cout << "XP for Next Lvl = " << mNextLevelExp << endl;
	cout << "Level           = " << mLevel << endl;
	cout << endl;

	//Ex 5.6.6 A Store
	displayInventory();
	cout << endl;
}

void Player::victory(int xp, int gold)
{
	cout << "You won the battle!" << endl;
	cout << "You win: " << endl << xp
		<< " experience points!" << endl
		//Ex 5.6.1 Gold Modification
		<< gold << " gold!" << endl;

	mExpPoints += xp;
	mGoldAmount += gold;
}

void Player::gameover()
{
	cout << "You died in battle..." << endl;
	cout << endl;
	cout << "================================" << endl;
	cout << "GAME OVER!" << endl;
	cout << "================================" << endl;
	cout << "Press 'q' to quit: ";
	char q = 'q';
	cin >> q;
	cout << endl;
}

void Player::displayHitPoints()
{
	cout << mName << "'s hitpoints = " << mHitPoints << endl;
}

int Player::getGold() {
	return mGoldAmount;
}

void Player::setGold(int newVal) {
	if (newVal >= 0)
		mGoldAmount = newVal;
}

void Player::displayInventory() {
	cout << "PLAYER EQUIPMENT: " << endl;
	cout << "===========================" << endl;
	cout << "Weapon: "; mWeapon->printValues();
	cout << "Armor: ";  mArmor->printValues();
	cout << endl;

	cout << "PLAYER INVENTORY: " << endl;
	cout << "===========================" << endl;
	//Ex 5.6.1 Gold Modification
	cout << mGoldAmount << " Gold." << endl;
	for (int i = 0; i < mInventory.size(); i++) {
		cout << (i + 1) << ") ";
		mInventory[i]->printValues();
	}
	cout << endl;
}

void Player::addToInventory(Item* item) {
	int i = 0;
	for (i = 0; i < mInventory.size(); i++)
		if (mInventory[i]->getItemType() - item->getItemType() >= 0)
			break;

	mInventory.insert(mInventory.begin() + i, item);
}

void Player::removeFromInventory(string name) {
	int itemIndex = -1;
	for (int i = 0; i < mInventory.size(); i++) {
		if (name.compare(mInventory[i]->mName) == 0) {
			itemIndex = i;
			break;
		}
	}
	if (itemIndex != -1) {
		mInventory.erase(mInventory.begin() + itemIndex);
	}
}

Item* Player::getFromInventory(int index) {
	return mInventory[index];
}


Weapon* Player::equipWeapon(Weapon* weap) {
	Weapon* old = mWeapon;
	mWeapon = weap;
	return old;
}

Armor* Player::equipArmor(Armor* arm) {
	Armor* old = mArmor;
	mArmor = arm;
	return old;
}

Item* Player::equipItem(Item* item) {
	if (item == 0) return 0;

	Item* oldItem = 0;
	//Don't know how to get around the 'initialization of variable is skipped by default label error, so workaround for now
	Armor* arm = 0;
	Weapon* weap = 0;
	switch (item->getItemType()) {
	case Armours:
		arm = dynamic_cast<Armor *>(item);
		oldItem = equipArmor(arm);
		break;
	case Weapons:
		weap = dynamic_cast<Weapon *>(item);
		oldItem = equipWeapon(weap);
		break;
	default:
		break;
	}
	cout << "Swapped " << oldItem->mName << " for " << item->mName << endl;
	addToInventory(oldItem);

	return oldItem;
}

void Player::showEquipMenu() {
	cout << "Select an item to equip: " << endl;
	cout << "0) Cancel." << endl;
	//display only equippable items
	int i;
	for (i = 0; i < mInventory.size(); i++) {
		if (mInventory[i]->isEquippable()) {
			cout << (i + 1) << ") ";
			mInventory[i]->printValues();
		}
	}
	int choice = 0;
	cin >> choice;

	//check input
	if (choice < 0 || choice > i) {
		cout << "Invalid input." << endl;
	}
	else if (choice == 0) {
		return;
	}
	else {
		choice--;
		Item* item = mInventory[choice];
		equipItem(item);
		removeFromInventory(item->mName);
	}
	showEquipMenu(); //recurse
}