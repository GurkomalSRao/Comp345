//! @file 
//! @brief Header file for the Belt class  
//!
#pragma once
#include "ItemDecorator.h"
//! class for implementing an item of type Belt using the decorator pattern
class Belt : public ItemDecorator {
public:
	Belt(AbstractCharacter *c, Item *i) : ItemDecorator(c, i){
		this->c = c;
		this->it = i;
		deaditem = false;
		equiped = true;
	}
	//method to increment stat bonus of character based on Belt equipped
	int getAbilityScore(int index){
		return c->getAbilityScore(index) + (deaditem ? 0 : getStats(index));
	}
	//method to get stat bonus of Belt equipped
	int getStats(int i);
	//method to unequip Belt
	Item* unsetItem(string s);
	//method to validate if Belt is equipped
	bool isEquiped(string s);
	bool displayEquipedItems(string s);
	Item* getItem(string s);
	vector<Item*> getEquipment();
	~Belt();
private:
	Item *it;
	bool equiped;//validator to check if Belt is already equipped
	bool deaditem;//defines if Belt is an empty item
};