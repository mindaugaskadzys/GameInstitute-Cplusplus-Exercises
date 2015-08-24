#ifndef ARMOR_H
#define ARMOR_H

#include "Item.h"

//Ex 5.6.6 A Store
struct Armor : public Item
{
	int       mArmorValue;

	virtual Item_Type getItemType() { return Armours; }
	virtual bool isEquippable() { return true; }

	virtual void printValues() { Item::printValues(); cout << ", Damage reduction: " << mArmorValue << endl; }

};

#endif