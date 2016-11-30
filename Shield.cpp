#include "Shield.h"

//! @file 
//! @brief Implementation file for the Shield class  
//!

//! method to get the attack bonus of the Shield
//! @return : attack bonus of Shield
int Shield::getArmorClass(){
	for (int j = 0; j < i->getInfluences().size(); j++){

		if (i->getInfluences()[j].getType() == "Armor class")
			return i->getInfluences()[j].getBonus();
	}

	return 0;
}

Shield::~Shield()
{
}
//! method to unequip the Shield
//! @param s : type of the Item
//! @return : pointer of type Item
Item* Shield::unsetItem(string s){
	if (!deaditem){
		if (s == "Shield"){
			deaditem = true;
			equiped = false;
			return i;
		}
		else
			return c->unsetItem(s);
	}
	else
		return c->unsetItem(s);

}
//! method to validate if the Shield is equipped
//! @param s : type of the Item
//! return : true if equipped, false if not
bool Shield::isEquiped(string s){
	if (equiped){
		if (s == "Shield"){
			equiped = true;
			return equiped;
		}
		else
			return c->isEquiped(s);
	}
	else
		return c->isEquiped(s);
}

bool Shield::displayEquipedItems(string s){
	if (equiped){
		if (s == "Shield"){
			i->print();
			return true;
		}
		else
			return c->displayEquipedItems(s);
	}
	else
		return c->displayEquipedItems(s);

}
Item* Shield::getItem(string s){
	if (!deaditem && equiped){
		if (s == "Shield"){
			return i;
		}
		else
			return c->getItem(s);
	}
	else
		return c->getItem(s);

}

vector<Item*> Shield::getEquipment(){
	vector<Item*> equipment;
	equipment = c->getEquipment();
	equipment.push_back(i);
	return equipment;
}