//! @file 
//! @brief Header file for the Ring class  
//!

#pragma once
#include "ItemDecorator.h"

//! class for implementing an item of type Ring using the decorator pattern
class Ring : public ItemDecorator {
public:
	Ring(AbstractCharacter *c, Item *i) : ItemDecorator(c,i){
		this->c = c;
		this->it = i;
		deaditem = false;
		equiped = true;
	}
	//method to increment stat bonus of character based on Ring equipped
	int getAbilityScore(int index){
		return c->getAbilityScore(index) + (deaditem ? 0 : getStats(index));
	}
	//method to increment armor of character on Ring equipped
	int armor(){
		return c->armor() + (deaditem ? 0 : getArmorClass());
	}
	//method to get stat bonus of Ring equipped
	int getStats(int i );
	//method to get armor bonus of Ring equipped
	int getArmorClass();
	//method to validate if Ring is equipped
	bool isEquiped(string s);
	//method to unequip Ring
	Item* unsetItem(string s);
	bool displayEquipedItems(string s);
	Item* getItem(string s);
	vector<Item*> getEquipment();
	~Ring();
	bool deaditem;//defines if Ring is an empty item
private:
	Item *it;
	bool equiped;//validator to check if Ring is already equipped
	
};