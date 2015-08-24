#include "Store.h"


Store::Store()
{
	//Initialise store inventory
	Weapon* bow = new Weapon();
	bow->mName = "Bow";
	bow->mCost = 1000;
	bow->mDamageRange.mLow = 8;
	bow->mDamageRange.mHigh = 12;

	Weapon* mace = new Weapon();
	mace->mName = "Mace";
	mace->mCost = 300;
	mace->mDamageRange.mLow = 6;
	mace->mDamageRange.mHigh = 8;

	Armor* chainmail = new Armor();
	chainmail->mName = "Chainmail Armor";
	chainmail->mCost = 500;
	chainmail->mArmorValue = 3;

	Armor* plateArmor = new Armor();
	plateArmor->mName = "Plate Armor";
	plateArmor->mCost = 1000;
	plateArmor->mArmorValue = 6;

	Potion* healingPotion = new Potion();
	healingPotion->mName = "Healing Potion";
	healingPotion->mCost = 100;
	healingPotion->mEffectValue = 10;
	healingPotion->mApplyOnSelf = true;

	Potion* fireballPotion = new Potion();
	fireballPotion->mName = "Fireball Potion";
	fireballPotion->mCost = 200;
	fireballPotion->mEffectValue = 8;
	fireballPotion->mApplyOnSelf = false;

	mStoreInventory.push_back(bow);
	mStoreInventory.push_back(mace);
	mStoreInventory.push_back(chainmail);
	mStoreInventory.push_back(plateArmor);
	mStoreInventory.push_back(healingPotion);
	mStoreInventory.push_back(fireballPotion);
}


Store::~Store()
{
	mStoreInventory.erase(mStoreInventory.begin(), mStoreInventory.end());
}


void Store::enter(Player& player) {
	cout << "Welcome to the store!" << endl;
	int choice = 0;
	while (choice != 3) {
		cout << "Balance: " << player.getGold() << " gold. Do you want to buy (1), sell (2), exit (3)? ";
		cin >> choice;
		int itemNo;
		switch (choice) {
		case 1:
			displayInventory();
			cout << "Select the item you want to buy: ";
			cin >> itemNo;
			while (itemNo < 0 || itemNo > mStoreInventory.size()) {
				cout << "Invalid selection." << endl;
				cin >> itemNo;
			}
			if (itemNo != 0) {
				if (buy(mStoreInventory[itemNo - 1], player))
					mStoreInventory.erase(mStoreInventory.begin() + itemNo - 1);
			}
			break;
		case 2:
			player.displayInventory();
			cout << "Select the item you want to sell: ";
			cin >> itemNo;
			while (itemNo < 0 || itemNo > player.getInventorySize()) {
				cout << "Invalid selection." << endl;
				cin >> itemNo;
			}
			if (itemNo != 0) {
				sell(player.getFromInventory(itemNo - 1), player);
			}
			break;
		case 3: default:
			cout << "Bye!" << endl;
			choice = 3;
			break;
		}
	}
}

void Store::displayInventory() {
	cout << "0) Cancel." << endl;
	for (int i = 0; i < mStoreInventory.size(); i++) {
		cout << (i + 1) << ") ";
		mStoreInventory[i]->printValues();
	}
	cout << endl;
}

bool Store::buy(Item* item, Player& player) {
	if (promptItem("buy", item)) {
		//check player gold vs item cost
		if (player.getGold() < item->mCost)
			cout << "You can not afford this item. Aborting..." << endl;
		else {
			cout << "Success!!" << endl;

			//deduct gold
			player.setGold(player.getGold() - item->mCost);
			//check if item can be equipped and offer to equip if so
			if (item->isEquippable()) {
				cout << "Do you wish to equip " << item->mName << "? Yes (1): ";
				int choice = 0;
				cin >> choice;
				if (choice == 1) {
					Item* oldItem = player.equipItem(item);
					sell(oldItem, player); //ask if the user wants to sell the old item
					return true;
				}
			}
			player.addToInventory(item);
			return true;
		}
	}

	return false;
}

bool Store::sell(Item* item, Player& player) {
	if (promptItem("sell", item)) {
		player.setGold(player.getGold() + item->mCost);
		mStoreInventory.push_back(item);
		player.removeFromInventory(item->mName);
		return true;
	}
	else
		return false;
}

bool Store::promptItem(string buySell, Item* item) {
	cout << "Do you want to " << buySell << " " << item->mName << " for " << item->mCost << "? Yes (1):";
	int choice;
	cin >> choice;
	if (choice != 1) {
		cout << "Aborting...";
		return false;
	}
	return true;
}