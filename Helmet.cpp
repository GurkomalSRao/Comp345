#include "Helmet.h"

//! @file 
//! @brief Implementation file for the Helmet class  
//!

//! method to get the stat bonus of the Helmet
//! @param index : index of character stat to increase
//! @return : enhancement bonus of Helmet
int Helmet::getStats(int index){
	string s;

	//find which enhancement type to increase
	switch (index){
	case 3:
		s = "Intelligence";
		break;
	case 4:
		s = "Wisdom";
		break;
	}

	for (int j = 0; j < i->getInfluences().size(); j++){
		//iterate through vector influences and return the bonus of chosen enhancement type
		if (i->getInfluences()[j].getType() == s)
			return i->getInfluences()[j].getBonus();
	}
	return 0;
}
//! method to get the armor class bonus of the Helmet
//! @return : armor class bonus
int Helmet::getArmorClass(){
	for (int j = 0; j < i->getInfluences().size(); j++){

		if (i->getInfluences()[j].getType() == "Armor class")
			return i->getInfluences()[j].getBonus();
	}

	return 0;
}

Helmet::~Helmet()
{
}
//! method to unequip the Helmet
//! @param s : type of the Item
//! @return : pointer of type Item
Item* Helmet::unsetItem(string s){
	if (!deaditem){
		if (s == "Helmet"){
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
//! method to validate if the Helmet is equipped
//! @param s : type of the Item
//! return : true if equipped, false if not
bool Helmet::isEquiped(string s){
	if (equiped){
		if (s == "Helmet"){
			equiped = true;
			return equiped;
		}
		else
			return c->isEquiped(s);
	}
	else
		return c->isEquiped(s);
}

bool Helmet::displayEquipedItems(string s){
	if (equiped){
		if (s == "Helmet"){
			i->print();
			return true;
		}
		else
			return c->displayEquipedItems(s);
	}
	else
		return c->displayEquipedItems(s);

}
Item* Helmet::getItem(string s){
	if (!deaditem && equiped){
		if (s == "Helmet"){
			return i;
		}
		else
			return c->getItem(s);
	}
	else
		return c->getItem(s);

}

vector<Item*> Helmet::getEquipment(){
	vector<Item*> equipment;
	equipment = c->getEquipment();
	equipment.push_back(i);
	return equipment;
}