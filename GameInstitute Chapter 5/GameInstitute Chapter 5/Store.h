#pragma once
#ifndef STORE_H
#define STORE_H

#include <iostream>
#include "Player.h"
#include "Range.h"
#include <vector>

using namespace std;

//Ex 5.6.6 A Store
class Store
{
public:
	Store();
	~Store();

	void enter(Player& player);

private:
	void displayInventory();
	bool buy(Item* item, Player& player); // bool for transaction success/fail
	bool sell(Item* item, Player& player); // bool for transaction success/fail
	bool promptItem(string buySell, Item* item);

	std::vector<Item*> mStoreInventory;
};

#endif