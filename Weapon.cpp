#include "Weapon.h"
//! @file 
//! @brief Implementation file for the Weapon class  
//!

//! method to get the attack bonus of the weapon
//! @return : attack bonus of weapon
int Weapon::getAttackBonus(){
	for (int j = 0; j < i->getInfluences().size(); j++){
		if (i->getInfluences().at(j).getType() == "Attack bonus")
			return i->getInfluences().at(j).getBonus();
	}
	return 0;
}

//! method to get the damage bonus of the weapon
//! @return : damage bonus of weapon
int Weapon::getDamageBonus(){
	for (int j = 0; j < i->getInfluences().size(); j++){
		if (i->getInfluences().at(j).getType() == "Damage bonus")
			return i->getInfluences().at(j).getBonus();
	}
	return 0;
}

Weapon::~Weapon()
{

}

//! method to unequip the weapon
//! @param s : type of the Item
//! @return : pointer of type Item
Item* Weapon::unsetItem(string s){
	if (!deaditem){
		if (s == "Weapon"){
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

//! method to validate if the weapon is equipped
//! @param s : type of the Item
//! return : true if equipped, false if not
bool Weapon::isEquiped(string s){
	if (equiped){
		if (s == "Weapon"){
			equiped = true;
			return equiped;
		}
		else
			return c->isEquiped(s);
	}
	else
		return c->isEquiped(s);
}

bool Weapon::displayEquipedItems(string s){
	if (equiped){
		if (s == "Weapon"){
			i->print();
			return true;
		}
		else
			return c->displayEquipedItems(s);
	}
	else
		return c->displayEquipedItems(s);

}
Item* Weapon::getItem(string s){
	if (!deaditem && equiped){
		if (s == "Weapon"){
			return i;
		}
		else
			return c->getItem(s);
	}
	else
		return c->getItem(s);

}

vector<Item*> Weapon::getEquipment(){
	vector<Item*> equipment;
	equipment = c->getEquipment();
	equipment.push_back(i);
	return equipment;
}