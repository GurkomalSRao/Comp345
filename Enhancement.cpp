//! @file 
//! @brief Implementation file for the Item class  
//!
#include "Enhancement.h"

// default constructor

//! default constructor
Enhancement::Enhancement()
{
	type = "Nothing";
	bonus = 0;
}

//! constructor that receives a type of item as a string and a bonus value as an int
//! @param type_name : type of the item
//! @param bonus_value : bonus given by the item [1..5]
Enhancement::Enhancement(string type_name, int bonus_value)
{
	type = type_name;
	bonus = bonus_value;
}

//! method to get the type of the enhancement
//! @return : type of the enhancement
string Enhancement::getType()
{
	return type;
}

//! method to get the bonus of the type
//! @return : bonus given by the item
int Enhancement::getBonus()
{
	return bonus;
}
//! method to set the type of the enhancement
//! @param name : type of the enhancement
void Enhancement::setType(string name){
	type = name;
}

//! method to set the power of the enhancement
//! @param newbones : bonus to be added
void Enhancement::setBonus(int newBonus){
	bonus = newBonus;
}