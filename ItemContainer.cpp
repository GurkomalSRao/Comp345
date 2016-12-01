//! @file 
//! @brief IMplementation file for the ItemContainer class  
//!

#include "ItemContainer.h"
#include <iostream>

//! default constructor
ItemContainer::ItemContainer()
{
	Items = vector<Item*>();
	size = 0;
}

//! constructor that takes a vector of items as input to create an ItemContainer
//! @param containeritems: vector of items to put in the new container
ItemContainer::ItemContainer( vector<Item*> containeritems)
{
	Items = containeritems;
}

//! method to get the items of the container
//! @return : return the vector of items contained in the ItemContainer
vector<Item*> ItemContainer::getItems()
{
	return Items;
}

//! method to add an item to the item container
//! @param anitem : new item to put in the ItemContainer
void ItemContainer::addItem(Item* anitem)
{
	this->Items.push_back(anitem);
	size++;
}

//! method to return the item of a certain type contained in the ItemContainer
//! assumption: the container can only contain one element of each type
//! @param itemType : type of item to extract from the container
//! @return : item of the specified kind provided in input
Item* ItemContainer::getItem(string itemType)
{
	for (int i = 0; i < size; i++)
		if (Items[i]->getType() == itemType)
			return Items[i];
	return NULL;
}
//! method that returns the size of the container (amount of items within container)
//! @return: returns an integer value that represents the size of the Item Container
int ItemContainer::getSize(){
	return size;
}

//! method to return index of a certain type contained in the ItemContainer
//! assumption: the container can only contain one element of each type
//@param itemType : type of item, variable type string
//@return : index of item, variable type int
int ItemContainer::getItemIndex(string itemType){
	for (int i = 0; i < size; i++)
		if (Items[i]->getType() == itemType)
			return i;
}

//! method to remove of a certain Item type contained in the ItemContainer
//! assumption: the container can only contain one element of each type
//@param itemType : type of item, variable type string
void ItemContainer::removeItem(string itemType){
	
	int index = getItemIndex(itemType);
	Items.erase(Items.begin() + index);
	size--;
}

//! method to print all items within the item container with their respective Enchantments and Bonuses
void ItemContainer::print(){
	cout << "Items in Inventory: " << endl;
	if (Items.size() != 0){
		for (int i = 0; i < size; i++) //iterate through container and display items with their respective stats
			Items[i]->print();
	}
	else{
		cout << "Empty Inventory" << endl;
	}

}