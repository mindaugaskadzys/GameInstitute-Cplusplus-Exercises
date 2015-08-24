// Player.h

#ifndef PLAYER_H
#define PLAYER_H

#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"
#include "Monster.h"
#include <string>
#include <vector>
#include "Spell.h"

class Player
{
public:
	// Constructor.
	Player();
	~Player();

	// Methods
	bool isDead();

	Armor*  getArmor();
	Weapon* getWeapon();
	int getGold();
	void setGold(int newVal);

	void takeDamage(int damage);

	void createClass();
	bool attack(Monster& monster);
	void levelUp();
	void rest();
	void viewStats();
	void victory(int xp, int gold);
	void gameover();
	void displayHitPoints();
	//Ex 5.6.4 Magic Points
	void initSpells();
	void castSpell(Monster& target);

	//Ex 5.6.6 Store
	void displayInventory();
	void addToInventory(Item* item);
	void removeFromInventory(string name);
	Item* getFromInventory(int index);
	int getInventorySize() { return mInventory.size(); }
	Weapon* equipWeapon(Weapon* weap); //return previous weapon
	Armor* equipArmor(Armor* arm); //return previous armor
	void showEquipMenu();
	Item* equipItem(Item* item); //return previously worn item

private:
	// Data members.
	std::string mName;
	std::string mClassName;
	int         mAccuracy;
	int         mHitPoints;
	int         mMaxHitPoints;
	int         mExpPoints;
	int         mNextLevelExp;
	int         mLevel;
	//int         mArmor;
	Weapon*      mWeapon;

	//Ex  5.6.1 Gold Modification
	int mGoldAmount;
	//Ex 5.6.2 Race Modification
	std::string mRaceName;
	//Ex 5.6.4 Magic Points
	int mMagicPoints;
	int mMaxMagicPoints;
	std::vector<Spell> mSpellBook;

	//Ex 5.6.6 Store
	std::vector<Item*> mInventory;
	Armor* mArmor;
};

#endif //PLAYER_H