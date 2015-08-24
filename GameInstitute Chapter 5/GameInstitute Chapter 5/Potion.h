#ifndef POTION_H
#define POTION_H

#include "Item.h"

//Ex 5.6.6 A Store
struct Potion : public Item
{
	int       mEffectValue;
	bool	  mApplyOnSelf; //Either apply value on self or enemy

	virtual Item_Type getItemType() { return Potions; }

	virtual void printValues()  { Item::printValues(); cout << ", " << (mApplyOnSelf ? "Heals " : "Deals ") << mEffectValue << " Damage." << endl; }
};

#endif