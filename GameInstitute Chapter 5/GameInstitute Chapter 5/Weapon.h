// Weapon.h

#ifndef WEAPON_H
#define WEAPON_H

#include "Range.h"
#include "Item.h"

struct Weapon : public Item
{
	Range       mDamageRange;

	virtual Item_Type getItemType() { return Weapons; }
	virtual bool isEquippable() { return true; }

	virtual void printValues() { Item::printValues(); cout << ", Damage: " << mDamageRange.mLow << "-" << mDamageRange.mHigh << "." << endl; }

};

#endif //WEAPON_H