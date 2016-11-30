//! @file 
//! @brief Header file for the Boots class  
//!
#pragma once
#include "ItemDecorator.h"
//! class for implementing an item of type Boots using the decorator pattern
class Boots : public ItemDecorator {
public:

	Boots(AbstractCharacter *c, Item *i) : ItemDecorator(c, i){
		this->c = c;
		this->it = i;
		deaditem = false;
		equiped = true;
	}
	//method to increment stat bonus of character based on Boots equipped
	int getAbilityScore(int index){
		return c->getAbilityScore(index) + (deaditem ? 0 : getStats(index));
	}
	//method to increment armor of character on Boots equipped
	int armor(){
		return c->armor() + (deaditem ? 0 : getArmorClass());
	}
	//method to get stat bonus of Boots equipped
	int getStats(int i);
	//method to get armor bonus of Boots equipped
	int getArmorClass();
	//method to validate if Boots is equipped
	bool isEquiped(string s);
	//method to unequip Boots
	Item* unsetItem(string s);
	bool displayEquipedItems(string s);
	Item* getItem(string s);
	vector<Item*> getEquipment();
	~Boots();
private:
	Item *it;
	bool equiped;//validator to check if Boots is already equipped
	bool deaditem;//defines if Boots is an empty item
};