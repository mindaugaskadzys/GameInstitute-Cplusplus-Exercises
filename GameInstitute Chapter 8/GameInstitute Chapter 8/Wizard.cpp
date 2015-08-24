// Wizard.cpp
#include "Wizard.h"
#include <iostream>
using namespace std;
Wizard::Wizard()
{
	mName = "Default";
	mHitPoints = 0;
	mMagicPoints = 0;
	mArmor = 0;
}
Wizard::Wizard(string name, int hp, int mp, int armor)
{
	mName = name;
	mHitPoints = hp;
	mMagicPoints = mp;
	mArmor = armor;
}
void Wizard::print()
{
	cout << "Name= " << mName << endl;
	cout << "HP= " << mHitPoints << endl;
	cout << "MP= " << mMagicPoints << endl;
	cout << "Armor= " << mArmor << endl;
	cout << endl;
}

void Wizard::save(ofstream& outFile)
{
	/*outFile << "Name= " << mName << endl;
	outFile << "HP= " << mHitPoints << endl;
	outFile << "MP= " << mMagicPoints << endl;
	outFile << "Armor= " << mArmor << endl;
	outFile << endl;*/

	//rewrite using binary
	outFile.write(mName.c_str(), sizeof(char)*256);
	outFile.write((char*)&mHitPoints, sizeof(int));
	outFile.write((char*)&mMagicPoints, sizeof(int));
	outFile.write((char*)&mArmor, sizeof(int));
}

void Wizard::load(ifstream& inFile)
{
	/*string garbage;
	inFile >> garbage >> mName; // read name
	inFile >> garbage >> mHitPoints; // read hit points
	inFile >> garbage >> mMagicPoints;// read magic points
	inFile >> garbage >> mArmor; // read armor*/

	char* name = new char[256];
	//rewrite using binary
	inFile.read(name, sizeof(char)*256);
	inFile.read((char*)&mHitPoints, sizeof(int));
	inFile.read((char*)&mMagicPoints, sizeof(int));
	inFile.read((char*)&mArmor, sizeof(int));
	mName = name;
}