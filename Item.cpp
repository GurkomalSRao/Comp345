//! @file 
//! @brief Implementation file for the Item class  
//!

#include "Item.h"
#include <iostream>
#include <fstream>

using namespace std;

//! default constructor
const int MAX_ATTRIBUTES = 5;
const string HELMET[MAX_ATTRIBUTES]		= { "Intelligence", "Wisdom", "Armor class" };
const string ARMOR[MAX_ATTRIBUTES]		= { "Armor class" };
const string SHIELD[MAX_ATTRIBUTES]		= { "Armor class" };
const string RING[MAX_ATTRIBUTES]		= { "Armor class", "Strength", "Constitution", "Wisdom", "Charisma" };
const string BELT[MAX_ATTRIBUTES]		= { "Constitution", "Strength" };
const string BOOTS[MAX_ATTRIBUTES]		= { "Armor class", "Dexterity" };
const string WEAPON[MAX_ATTRIBUTES]		= { "Attack bonus", "Damage bonus" };

Item::Item()
{
	type = "Nothing";
}

//! constructor that receives an item type as a string and a vector containing the enhancements that this item gives
//! @param type_name : string representing the type of item
//! @param influences : vector containing all the characteristics influenced by the item
Item::Item(string type_name, vector<Enhancement> influences)
{
	// ***todo***: this constructor should verify that an new item of a certain type only 
	// enhances a character statistic valid for this item type
	type = type_name;
	influence = influences;
}

//! method to get the type of the item
//! @return : type of the item
string Item::getType()
{
	return type;
}

//! method to get the influences of the item
//! @return : vector containg the list of stats that the item enhances
vector<Enhancement> Item::getInfluences()
{
	return influence;
}

//! method to validate an item, e.g. verify that an new item of a certain type only enhances a character statistic valid for this item type
//! @return : true if the enhancement list is valid according to the rules, false if not
bool Item::validateItem()
{
	if (type == "Nothing")
		return true;
	if (type == "Helmet"){
		for (int i = 0; i <= MAX_ATTRIBUTES; i++){
			if (influence.at(0).getType() == HELMET[i])
				return true;
		}
	}
	else if (type == "Armor"){
		for (int i = 0; i <= MAX_ATTRIBUTES; i++){
			if (influence.at(0).getType() == ARMOR[i])
				return true;
		}
	}
	else if (type == "Shield"){
		for (int i = 0; i <= MAX_ATTRIBUTES; i++){
			if (influence.at(0).getType() == SHIELD[i])
				return true;
		}
	}
	else if (type == "Ring"){
		for (int i = 0; i <= MAX_ATTRIBUTES; i++){
			if (influence.at(0).getType() == RING[i])
				return true;
		}
	}
	else if (type == "Belt"){
		for (int i = 0; i <= MAX_ATTRIBUTES; i++){
			if (influence.at(0).getType() == BELT[i])
				return true;
		}
	}
	else if (type == "Boots"){
		for (int i = 0; i <= MAX_ATTRIBUTES; i++){
			if (influence.at(0).getType() == BOOTS[i])
				return true;
		}
	}
	else if (type == "Weapon"){
		for (int i = 0; i <= MAX_ATTRIBUTES; i++){
			if (influence.at(0).getType() == WEAPON[i])
				return true;
		}
	}
	return false;
}

//! Implementation saveItem, saves item as binary to a file
//! @param item: the item to be saved
void Item::saveItem(){
	string fileName;
	int numberOfInfluences = influence.size();
	cout << "File Name: ";
	cin >> fileName;

	ofstream output(fileName);

	output << "Item.sav" << endl;	//type of save
	output << type << endl;			//item type i.e Helmet, Armor, Shield

	output << numberOfInfluences << endl;
	for (int i = 0; i < numberOfInfluences; i++)
	{
		output << influence.at(i).getType() << endl;
		output << influence.at(i).getBonus() << endl;
	}
	output.close();
}

//! Implementation loadItem, load an item from a file
//! assumption: file exists
//! @param &item: the item to be loaded
void Item::loadItem()
{
	string fileName;
	string enhanceType;
	string fileValidation;
	Enhancement *tempEnhance;
	int numberOfInfluences;
	int bonus;
	bool badFile = false;
	cout << "Load File: ";
	cin >> fileName;

	ifstream input(fileName);
	do{
		while (!input.good()){
			cout << "File does not exist, try again: ";
			cin >> fileName;
			input.open(fileName);
		}
		input >> fileValidation;
		if (fileValidation == "Item.sav")//check if it is an item save file
			badFile = true;
		else{
			input.close();
			badFile = false;
			cout << "Incorrect File Loaded, select another File: " << endl;
			cin >> fileName;
			input.open(fileName);
		}
	} while (badFile == false);
	
	input >> type;						//save type of Item i.e. Helmet, Shield
	input >> numberOfInfluences;		//number of influences to be loaded

	for (int i = 0; i < numberOfInfluences; i++)
	{
		input >> enhanceType;					//type of influence i.e. Intelligence, Strength
		input >> bonus;					//bonus of influence
		tempEnhance = new Enhancement(enhanceType, bonus);
		influence.insert(influence.begin(),*tempEnhance);
		delete tempEnhance;
	}
	input.close();
}

//! method to set the Item type i.e. Armor, Shield
void Item::setType(string newType){
	type = newType;
}

//!method to set the enchantment of the item
//! @param Enhancement: the Enhancement to be saved
void Item::setInfluences(Enhancement newEnhancement){
	influence.insert(influence.begin(), newEnhancement);
}

//!print the Item type with its respective enhancement and bonus value
void Item::print(){
	if (type == "Nothing"){
		cout << "Nothing Equipped" << endl;;
	}
	else{
		cout << "Item: " << type;
		cout << " Enchantment(s): " << influence.at(0).getType() << " +" << influence.at(0).getBonus() << endl;
	}
}