//! @file 
//! @brief Header file for the Armor class  
//!
#pragma once
#include "ItemDecorator.h"

class Armor : public ItemDecorator {
public:
	//! class for implementing an item of type Armor using the decorator pattern
	Armor(AbstractCharacter *c, Item *i) : ItemDecorator(c, i){
		this->c = c;
		this->it = i;
		deaditem = false;
		equiped = true;
	}
	//method to increment armor of character on Armor equipped
	int armor(){
		return c->armor() + (deaditem ? 0 : getArmorClass());
	}
	//method to get armor bonus of Armor equipped
	int getArmorClass();
	//method to validate if Armor is equipped
	bool isEquiped(string s);
	//method to unequip Armor
	Item* unsetItem(string s);
	bool displayEquipedItems(string s);
	Item* getItem(string s);
	vector<Item*> getEquipment();
	bool deaditem;//defines if Armor is an empty item
	//isDead();
	~Armor();
private:
	Item *it;
	bool equiped;//validator to check if Armor is already equipped
	
};