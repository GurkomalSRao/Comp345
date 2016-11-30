//! @file 
//! @brief Header file for the Abstract Character class  
//!

#pragma once
#include<string>
#include<iostream>
#include "Item.h"
#include "Subject.h"
#include "ItemContainer.h"
const int ITEM_SLOTS = 7;
using namespace std;

//! Class that implements an abstract character
//! Abstract character implementation is to be used with Item Decorator Pattern
class AbstractCharacter : public Subject
{
public:
	virtual bool validateNewCharacter()=0;
	virtual void hit(int) = 0;
	virtual Item* unsetItem(string s) = 0;
	virtual bool isEquiped(string s) = 0;
	virtual int getHitPoints() = 0;
	virtual int abilityScore() = 0;
	virtual int abilityModifier(int) = 0;
	virtual void modifyHP() = 0;
	virtual void setLevel(int) = 0;
	virtual int armor() = 0;
	virtual void addItemToInventory(Item* i) = 0;
	virtual int* attackBonus() = 0;
	virtual int damageBonus() = 0;
	virtual string getClass()=0;
	virtual void display() = 0;
	virtual int getLevel() = 0;
	virtual int getAbilityScore(int) = 0;
	virtual bool displayEquipedItems(string) = 0;
	virtual void displayBackpackItems() = 0;
	//virtual void saveCharacter() = 0;
	//virtual void loadCharacter() = 0;
	virtual void monsterClass() = 0;
	virtual ItemContainer getBackPack() = 0;
	//int getEquipmentSize();
	virtual void setAbilityScores(string) = 0;
	virtual bool equipItem(string) = 0;
	virtual bool unequipItem(Item*) = 0;
	virtual Item* getItem(string) = 0;
	virtual vector<Item*> getEquipment() = 0;
	virtual void setHitPoints(int) = 0;
	virtual void setAbilityScore(int, int) = 0;
	virtual string getFighterType() = 0;
	virtual void setFighterType(string) = 0;
	virtual int getBaseBonus() = 0;
	virtual int getAttacksSize() = 0;
	virtual void SetAttack() = 0;
	virtual int GetAttack(int) = 0;
	virtual void setArmor() = 0;
	virtual void setBonusDamage() = 0;
	virtual int getBonusAtks(int) = 0;
	virtual void initializeBonusAttack() = 0;
	/*int damageBonus();
	bool equipItem(Item);
	bool unequipItem(string);
	void addItemToInventory(Item);
	void display();
	void displayEquipedItems();
	void displayBackpackItems();
	int getLevel();
	void saveCharacter();
	void loadCharacter();
	const Item noItem;
	void monsterClass();
	ItemContainer getBackPack();
	void setAbilityScores(string);
	Item* unsetItem(string);
	bool isEquiped(string);
	string getClass();
	virtual int getAbilityScore(int);
	
	*/
	
};

