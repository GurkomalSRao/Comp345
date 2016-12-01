#include "CharacterSprite.h"
#include "AggressiveStrategy.h"
#include <iostream>
using namespace std;

//COMP 345 Assignment 3
//Created by: Justin Velicogna
//Student ID: 40005294


CharacterSprite::CharacterSprite()
{
	pos.x = 0;
	pos.y = 0;

}

void CharacterSprite::printEquipmentInterface(){
	cout << "EQUIPPED ITEMS" << endl;
	c->displayEquipedItems("Helmet");
	c->displayEquipedItems("Armor");
	c->displayEquipedItems("Shield");
	c->displayEquipedItems("Ring");
	c->displayEquipedItems("Belt");
	c->displayEquipedItems("Boots");
	c->displayEquipedItems("Weapon");
	cout << "BACKPACK" << endl;
	c->displayBackpackItems();
}

void CharacterSprite::displayEquipedItems(bool logs[]){
	char type;
	if (c->getBackPack().getSize() > 0){
		while (true){
			system("cls");
			printEquipmentInterface();
			NotifyGame("Loaded Equipment Interface", logs);
			cout << "ITEM EQUIPMENT SCREEN" << endl;
			cout << " ------------------------------------------------------- " << endl;
			cout << "| H - Equip/Unequip Helmet                            |" << endl;
			cout << "| A - Equip/Unequip Armor                             |" << endl;
			cout << "| S - Equip/Unequip Shield                            |" << endl;
			cout << "| R - Equip/Unequip Ring                              |" << endl;
			cout << "| L - Equip/Unequip Belt                              |" << endl;
			cout << "| B - Equip/Unequip Boots                             |" << endl;
			cout << "| W - Equip/Unequip Weapon                            |" << endl;
			cout << "| X - Resume Game                                     |" << endl;
			cout << " ------------------------------------------------------- " << endl;
			cout << "Please Select Item: ";
			cin >> type;
			switch (toupper(type)){
			case 'H':
				
				if (!c->isEquiped("Helmet")){
					if (c->getBackPack().getItem("Helmet") != NULL)
					{
						c = new Helmet(c, c->getBackPack().getItem("Helmet"));
						c->equipItem("Helmet");
						NotifyGame("Equiped Helmet", logs);
					}
				}
				else{
					c->unequipItem(c->unsetItem("Helmet"));
					NotifyGame("Equip Helmet", logs);
				}
				break;
			case 'A':
				//c->equipItem(c->getBackPack().getItem("Armor"));
				if (!c->isEquiped("Armor")){
					if (c->getBackPack().getItem("Armor") != NULL){
						c = new Armor(c, c->getBackPack().getItem("Armor"));
						c->equipItem("Armor");
						NotifyGame("Equiped Armor", logs);
					}
				}
				else{
					c->unequipItem(c->unsetItem("Armor"));
					NotifyGame("Unequiped Armor", logs);
				}
				break;
			case 'S':
				//c->equipItem(c->getBackPack().getItem("Shield"));
				if (!c->isEquiped("Shield")){
					if (c->getBackPack().getItem("Shield") != NULL){
						c = new Shield(c, c->getBackPack().getItem("Shield"));
						c->equipItem("Shield");
						NotifyGame("Equiped Shield", logs);
					}
				}
				else{
					c->unequipItem(c->unsetItem("Shield"));
					NotifyGame("Unequiped Shield", logs);
				}
				break;
			case 'R':
				//c->equipItem(c->getBackPack().getItem("Ring"));
				if (!c->isEquiped("Ring")){
					if (c->getBackPack().getItem("Ring") != NULL){
						c = new Ring(c, c->getBackPack().getItem("Ring"));
						c->equipItem("Ring");
						NotifyGame("Equiped Ring", logs);
					}
				}
				else{
					c->unequipItem(c->unsetItem("Ring"));
					NotifyGame("Unequiped Ring", logs);
				}
				break;
			case 'L':
				//c->equipItem(c->getBackPack().getItem("Belt"));
				if (!c->isEquiped("Belt")){
					if (c->getBackPack().getItem("Belt") != NULL){
						c = new Belt(c, c->getBackPack().getItem("Belt"));
						c->equipItem("Belt");
						NotifyGame("Equiped Belt", logs);
					}
				}
				else{
					c->unequipItem(c->unsetItem("Belt"));
					NotifyGame("Unequiped Belt", logs);
				}
				break;
			case 'B':
				//c->equipItem(c->getBackPack().getItem("Boots"));
				if (!c->isEquiped("Boots")){
					if (c->getBackPack().getItem("Boots") != NULL){
						c = new Boots(c, c->getBackPack().getItem("Boots"));
						c->equipItem("Boots");
						NotifyGame("Equiped Boots", logs);
					}
				}
				else{
					c->unequipItem(c->unsetItem("Boots"));
					NotifyGame("Unequiped Boots", logs);
				}
				break;
			case 'W':
				//c->equipItem(c->getBackPack().getItem("Weapon"));
				if (!c->isEquiped("Weapon")){
					if (c->getBackPack().getItem("Weapon") != NULL){
						c = new Weapon(c, c->getBackPack().getItem("Weapon"));
						c->equipItem("Weapon");
						NotifyGame("Equiped Weapon", logs);
					}
				}
				else{
					c->unequipItem(c->unsetItem("Weapon"));
					NotifyGame("Unequiped Weapon", logs);
				}
				break;
			case 'X':
				return;
			default:
				cout << "Invalid input, try Again" << endl;
			}
		}
	}
	else{
		cout << "No Items to swap, Resuming Game..." << endl;
		system("pause");
		return;
	}
}
//! Function which allows a character to attack another character
//! @param T: The target of the attack
void CharacterSprite::attack(CharacterSprite* T, int i, bool logs[4]){
	
	int acc = c->getAccuracy(i);
	int arm = T->c->armor();
	NotifyGame("Attack roll: " + to_string(acc),logs);
	NotifyGame("Armor: " + to_string(arm),logs);

		if ( acc> arm)
		{
			NotifyGame("Attack hit!",logs);
			int dmg = c->getDamage();
			
			NotifyGame("Damage roll: " + to_string(dmg),logs);
			T->c->hit(dmg);
			cout << c->getCharName() << " Attacked, and dealt " << dmg << " damage to " << T->c->getCharName() << " (" << T->c->getHitPoints() << ") hp left!" << endl;
			NotifyGame(" Attacked, and dealt " + to_string(dmg) + " damage to " + T->c->getCharName(), logs);
			system("pause");
		}
		else
		{
			NotifyGame("Attack missed!",logs);
			cout << c->getCharName() << " Attacked "<< T->c->getCharName() << " and missed!" << endl;
			//notify attack miss
			system("pause");

		}
	if (T->s->getStrategyNumber() == 3)
	{
		
		delete T->s;
		T->s = new AggressiveStrategy();

		//c->SetAttack();



		cout << "The monster decides it hates you now" << endl;
	}
}