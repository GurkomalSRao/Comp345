//! @file 
//! @brief Header file for the Helmet class  
//!

#pragma once
#include "ItemDecorator.h"
//! class for implementing an item of type Helmet using the decorator pattern
class Helmet : public ItemDecorator {
public:
	Helmet(AbstractCharacter *c, Item *i) : ItemDecorator(c, i){
		this->c = c;
		this->it = i;
		deaditem = false;
		equiped = true;
	}
	//method to increment stat bonus of character based on Helmet equipped
	int getAbilityScore(int index){
		return c->getAbilityScore(index) + (deaditem ? 0 : getStats(index));
	}
	//method to increment armor of character on Helmet equipped
	int armor(){
		return c->armor() + (deaditem ? 0 : getArmorClass());
	}
	//method to get stat bonus of Helmet equipped
	int getStats(int i);
	//method to get armor bonus of Helmet equipped
	int getArmorClass();
	//method to unequip Ring
	Item* unsetItem(string s);
	//method to validate if Helmet is equipped
	bool isEquiped(string s);
	bool displayEquipedItems(string s);
	Item* getItem(string s);
	vector<Item*> getEquipment();
	bool deaditem;//defines if Helmet is an empty item
	~Helmet();
private:
	Item *it;
	bool equiped;//validator to check if Helmet is already equipped
	
};