#include "Ring.h"
//! @file 
//! @brief Implementation file for the Ring class  
//!

//! method to get the stat bonus of the Ring
//! @param index : index of character stat to increase
//! @return : enhancement bonus of Ring
int Ring::getStats(int index){
	string s;

	//find which enhancement type to increase
	switch (index){
	case 0:
		s = "Strength";
		break;
	case 1:
		s = "Dexterity";
		break;
	case 2:
		s = "Constitution";
		break;
	case 3:
		s = "Intelligence";
		break;
	case 4:
		s = "Wisdom";
		break;
	case 5:
		s = "Charisma";
		break;
	}

	for (int j = 0; j < i->getInfluences().size(); j++){
		//iterate through vector influences and return the bonus of chosen enhancement type
		if (i->getInfluences()[j].getType() == s)
			return i->getInfluences()[j].getBonus();
	}
	return 0;	
}
//! method to get the armor class bonus of the Ring
//! @return : armor class bonus
int Ring::getArmorClass(){
	for (int j = 0; j < i->getInfluences().size(); j++){

		if (i->getInfluences()[j].getType() == "Armor class")
			return i->getInfluences()[j].getBonus();
	}
	
	return 0;
}

Ring::~Ring()
{
}
//! method to unequip the Ring
//! @param s : type of the Item
//! @return : pointer of type Item
Item* Ring::unsetItem(string s){
	if (!deaditem){
		if (s == "Ring"){
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
//! method to validate if the Ring is equipped
//! @param s : type of the Item
//! return : true if equipped, false if not
bool Ring::isEquiped(string s){
	if (equiped){
		if (s == "Ring"){
			equiped = true;
			return equiped;
		}
		else
			return c->isEquiped(s);
	}
	else
		return c->isEquiped(s);
}

bool Ring::displayEquipedItems(string s){
	if (equiped){
		if (s == "Ring"){
			i->print();
			return true;
		}
		else
			return c->displayEquipedItems(s);
	}
	else
		return c->displayEquipedItems(s);

}
Item* Ring::getItem(string s){
	if (!deaditem && equiped){
		if (s == "Ring"){
			return i;
		}
		else
			return c->getItem(s);
	}
	else
		return c->getItem(s);

}

vector<Item*> Ring::getEquipment(){
	vector<Item*> equipment;
	equipment = c->getEquipment();
	equipment.push_back(i);
	return equipment;
}