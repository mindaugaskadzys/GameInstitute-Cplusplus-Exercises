#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>
using namespace std;

//enum for item type
enum Item_Type { Weapons, Armours, Potions, None };

//Ex 5.6.6 A Store
struct Item
{
	string mName;
	int mCost;

	//define type
	virtual Item_Type getItemType() { return None; }
	//compare types
	static bool compareTo(Item* first, Item* second) { return (first->getItemType() > second->getItemType()); }
	//is item equippable?
	virtual bool isEquippable() { return false; }

	//print item description
	virtual void printValues()  { cout << mName << " (" << mCost << " gold)"; }

};

#endif