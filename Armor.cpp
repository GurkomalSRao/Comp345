#include "Armor.h"
//! @file 
//! @brief Implementation file for the Armor class  
//!

//! method to get the armor class bonus of the Armor
//! @return : armor class bonus
int Armor::getArmorClass(){
	for (int j = 0; j < i->getInfluences().size(); j++){

		if (i->getInfluences()[j].getType() == "Armor class")
			return i->getInfluences()[j].getBonus();
	}

	return 0;
}

Armor::~Armor()
{
}
//! method to unequip the Armor
//! @param s : type of the Item
//! @return : pointer of type Item
Item* Armor::unsetItem(string s){
	if (!deaditem){
		if (s == "Armor"){
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
//! method to validate if the Armor is equipped
//! @param s : type of the Item
//! return : true if equipped, false if not
bool Armor::isEquiped(string s){
	if (equiped){
		if (s == "Armor"){
			equiped = true;
			return equiped;
		}
		else
			return c->isEquiped(s);
	}
	else
		return c->isEquiped(s);
}


bool Armor::displayEquipedItems(string s){
	if (equiped){
		if (s == "Armor"){
			i->print();
			return true; 
		}
		else
			return c->displayEquipedItems(s);
	}
	else
		return c->displayEquipedItems(s);

}

Item* Armor::getItem(string s){
	if (!deaditem && equiped){
		if (s == "Armor"){
			return i;
		}
		else
			return c->getItem(s);
	}
	else
		return c->getItem(s);

}

vector<Item*> Armor::getEquipment(){
	vector<Item*> equipment;
	equipment = c->getEquipment();
	equipment.push_back(i);
	return equipment;
}