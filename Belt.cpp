#include "Belt.h"
//! @file 
//! @brief Implementation file for the Belt class  
//!

//! method to get the stat bonus of the Belt
//! @param index : index of character stat to increase
//! @return : enhancement bonus of Belt

int Belt::getStats(int index){
	string s;
	//find which enhancement type to increase
	switch (index){
	case 0:
		s = "Strength";
		break;
	case 2:
		s = "Constitution";
		break;
	}

	for (int j = 0; j < i->getInfluences().size(); j++){
		//iterate through vector influences and return the bonus of chosen enhancement type
		if (i->getInfluences()[j].getType() == s)
			return i->getInfluences()[j].getBonus();
	}
	return 0;
}

Belt::~Belt()
{
}
//! method to unequip the Belt
//! @param s : type of the Item
//! @return : pointer of type Item
Item* Belt::unsetItem(string s){
	if (!deaditem){
		if (s == "Belt"){
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
//! method to validate if the Belt is equipped
//! @param s : type of the Item
//! return : true if equipped, false if not
bool Belt::isEquiped(string s){
	if (equiped){
		if (s == "Belt"){
			equiped = true;
			return equiped;
		}
		else
			return c->isEquiped(s);
	}
	else
		return c->isEquiped(s);
}
bool Belt::displayEquipedItems(string s){
	if (equiped){
		if (s == "Belt"){
			i->print();
			return true;
		}
		else
			return c->displayEquipedItems(s);
	}
	else
		return c->displayEquipedItems(s);

}
Item* Belt::getItem(string s){
	if (!deaditem && equiped){
		if (s == "Belt"){
			return i;
		}
		else
			return c->getItem(s);
	}
	else
		return c->getItem(s);

}

vector<Item*> Belt::getEquipment(){
	vector<Item*> equipment;
	equipment = c->getEquipment();
	equipment.push_back(i);
	return equipment;
}