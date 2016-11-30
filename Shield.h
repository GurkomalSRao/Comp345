//! @file 
//! @brief Header file for the Shield class  
//!

#pragma once
#include "ItemDecorator.h"
//! class for implementing an item of type Shield using the decorator pattern
class Shield : public ItemDecorator {
public:
	Shield(AbstractCharacter *c, Item *i) : ItemDecorator(c, i){
		this->c = c;
		this->it = i;
		deaditem = false;
		equiped = true;
	}
	//method to increment armor of character on Shield equipped
	int armor(){
		return c->armor() + (deaditem ? 0 : getArmorClass());
	}
	//method to get armor bonus of Shield equipped
	int getArmorClass();
	//method to unequip Shield
	Item* unsetItem(string s);
	//method to validate if Shield is equipped
	bool isEquiped(string s);
	bool displayEquipedItems(string s);
	Item* getItem(string s);
	vector<Item*> getEquipment();
	~Shield();
private:
	Item *it;
	bool deaditem;//defines if Shield is an empty item
	bool equiped;//validator to check if Shield is already equipped
};