#include "Boots.h"
//! @file 
//! @brief Implementation file for the Boots class  
//!

//! method to get the stat bonus of the Boots
//! @param index : index of character stat to increase
//! @return : enhancement bonus of Boots

int Boots::getStats(int index){
	string s;
	//find which enhancement type to increase
	switch (index){
	case 1:
		s = "Dexterity";
		break;
	}

	for (int j = 0; j < i->getInfluences().size(); j++){
		//iterate through vector influences and return the bonus of chosen enhancement type
		if (i->getInfluences()[j].getType() == s)
			return i->getInfluences()[j].getBonus();
	}
	return 0;
}
//! method to get the armor class bonus of the Boots
//! @return : armor class bonus
int Boots::getArmorClass(){
	for (int j = 0; j < i->getInfluences().size(); j++){

		if (i->getInfluences()[j].getType() == "Armor class")
			return i->getInfluences()[j].getBonus();
	}

	return 0;
}

Boots::~Boots()
{
}
//! method to unequip the Boots
//! @param s : type of the Item
//! @return : pointer of type Item
Item* Boots::unsetItem(string s){
	if (!deaditem){
		if (s == "Boots"){
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
//! method to validate if the Boots is equipped
//! @param s : type of the Item
//! return : true if equipped, false if not
bool Boots::isEquiped(string s){
	if (equiped){
		if (s == "Boots"){
			equiped = true;
			return equiped;
		}
		else
			return c->isEquiped(s);
	}
	else
		return c->isEquiped(s);
}

bool Boots::displayEquipedItems(string s){
	if (equiped){
		if (s == "Boots"){
			i->print();
			return true;
		}
		else
			return c->displayEquipedItems(s);
	}
	else
		return c->displayEquipedItems(s);

}
Item* Boots::getItem(string s){
	if (!deaditem && equiped){
		if (s == "Boots"){
			return i;
		}
		else
			return c->getItem(s);
	}
	else
		return c->getItem(s);

}

vector<Item*> Boots::getEquipment(){
	vector<Item*> equipment;
	equipment = c->getEquipment();
	equipment.push_back(i);
	return equipment;
}