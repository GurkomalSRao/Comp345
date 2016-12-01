//! @file 
//! @brief Header file for the Weapon class  
//!

#pragma once
#include "ItemDecorator.h"
#include "Item.h"

//! class for implementing an item of type weapon using the decorator pattern
class Weapon : public ItemDecorator {
public:
	//default constructor
	Weapon(AbstractCharacter *c, Item* i) : ItemDecorator(c,i){
		this->c = c;
		this->it = i;
		deaditem = false;
		equiped = true;
	}
	//method to increment damage bonus of character based on weapon equipped
	int damageBonus(){
		return c->damageBonus() + (deaditem ? 0 : getDamageBonus());
	}
	//method to increment attack bonus of character on weapon equipped
	int attackBonus(){
		return c->attackBonus() + (deaditem ? 0 : getAttackBonus());
	}
	//method to get attack bonus of  weapon equipped
	int getAttackBonus();
	//method to get damage bonus of  weapon equipped
	int getDamageBonus();
	//method to unequip weapon
	Item* unsetItem(string s);
	//method to validate if weapon is equipped
	bool isEquiped(string s);
	bool displayEquipedItems(string s);
	Item* getItem(string s);
	vector<Item*> getEquipment();
	~Weapon();
	bool deaditem;		//defines if weapon is an empty item
private:
	
	bool equiped;		//validator to check if weapon is already equipped
	Item *it;
};