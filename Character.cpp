//! @file 
//! @brief Implementation file for the Character class  
//!

#include "Character.h"
#include <stdlib.h> 
#include <time.h>
#include <iostream>
#include <fstream>
#include <random>
#include <string>
using namespace std;

//! Constructor: passes values to each ability score and set hit points to 10
Character::Character(int str, int dex, int con, int intel, int wis, int cha)
{
	abilityScores[0] = str; 
	abilityScores[1] = dex;
	abilityScores[2] = con;
	abilityScores[3] = intel;
	abilityScores[4] = wis;
	abilityScores[5] = cha;
	level = 1;
	// and set hit points to 10
	currentHitPoints = 10 + abilityModifier(2);
	// set inital attack bonus
	baseBonusAtk = abilityModifier(0) + abilityModifier(1);
	level = 1;
	length = 1;
}

Character::Character()  //generated random ability scores and class set to fighter
{
	abilityScores[0] = abilityScore();
	abilityScores[1] = abilityScore();
	abilityScores[2] = abilityScore();
	abilityScores[3] = abilityScore();
	abilityScores[4] = abilityScore();
	abilityScores[5] = abilityScore();
	level = 1;
	
	//fill equipment slots with empty item
	/*for (int i = 0; i < 7; i++){
		equipment[i] = noItem;
	}*/
	attacks = new int(1);
	currentHitPoints = 10 + abilityModifier(2);
	characterClass = "fighter";
	baseBonusAtk = abilityModifier(0) + abilityModifier(1);
	level = 1;
	length = 1;
	Notify();
}

//! Implementation of the verification of a newly created Character
//! @return bool value, true of the character is valid (stats should be in the 3-18 range for a new character), false if invalid. 
bool Character::validateNewCharacter()
{
	for (int i = 0; i <= 5; i++)
	if (abilityScores[i]<3 || abilityScores[i]>18)
		return false;
	return true;
}

//! Implementation of fill cell, set any cell to anything it might eventually contain
//! @param damage: damage sustained by the character
void Character::hit(int damage)
{
	currentHitPoints = currentHitPoints - damage; 
	//to do later, update the character observer
	Notify();
}

//! Implementation of a getter method for currentHitPoints
//! @return int: value of currentHitPoints
int Character::getHitPoints()
{
	return currentHitPoints; 
}

void Character::setHitPoints(int hp){
	currentHitPoints = hp;
}

int Character::abilityScore()  //generates random ability score
{
	int score = 0;
	int diceTurns[4] = {};
	//score = rand() % 6 + 1;
	int lowest = 6;
	int total = 0;
	srand(time(0));
	random_device rd;
	mt19937 gen(rd());  //initializes the generater
	uniform_int_distribution<> dis(1, 6);  //generates a range from 1 to 6

	for (int i = 0; i < 4; i++)
	{

		score = dis(gen);  //calls the generater to generate a random number
		diceTurns[i] = score;

		if (diceTurns[i] < lowest)
		{
			lowest = diceTurns[i];
		}
		total += diceTurns[i];
	}
	total -= lowest;

	return total;
}

int Character::abilityModifier(int ability)
{

	return abilityScores[ability] / 2 - 5;
}

void Character::modifyHP()
{
	srand(time(0));
	random_device rd;
	mt19937 gen(rd());  //initializes the generater
	uniform_int_distribution<> dis(1, 10);  //generates a range from 1 to 10
	currentHitPoints += dis(gen) + abilityModifier(2);
	Notify();
}

void Character::setLevel(int lvl)  //updates/sets the level of the character inclduing the stats
{
	level = lvl;
	modifyHP();
	armor();
	attackBonus();
	damageBonus();
	Notify();
}

int Character::armor()
{
	armorClass = 10 + abilityModifier(1);
	return armorClass;
}

void Character::setArmor()
{
	armorClass = 10 + abilityModifier(1);
}

int* Character::attackBonus()
{
	int bonusPerRound = level;
	if (level % 5 == 1)
	{
		length++;
		attacks = new int(length);
		totalDamagePerRound = new int(length);
	}

	for (size_t i = 0; i < length - 1; i++)
	{
		if (bonusPerRound > 0)
		{
			attacks[i] = bonusPerRound;
			bonusPerRound -= 5;
		}
	}

	return attacks;
}

int Character::damageBonus()
{
	return abilityModifier(0); 
}

void Character::setBonusDamage()
{
	bonusDamage = abilityModifier(0);
}

void Character::display() //displays the view of the character interface
{
	cout << "Class: " << characterClass << " Level: " << level << " HP: " << currentHitPoints << " AC: " << armor() << " Bonus Atk: ";
	cout << *(attacks + 0) << " ";
	for (size_t i = 1; i < length - 1; i++)
	{
		cout << *(attacks + i) << " ";
	}
	cout << " BD " << damageBonus() << endl;
	cout << "St: " << abilityScores[0] << " Dx: " << abilityScores[1] << " Co: " << abilityScores[2]
		<< " In: " << abilityScores[3] << " Wi: " << abilityScores[4] << " Ch: " << abilityScores[5] << endl << endl;
}

int Character::getLevel()
{
	return level;
}

int Character::getBaseBonus()
{
	return baseBonusAtk;
}

int Character::getAttacksSize()
{
	return length;
}

void Character::SetAttack()
{
	int roll;

	for (size_t i = 0; i < length; i++)
	{
		roll = dice.roll(1, 20);
		*(totalDamagePerRound + i) = *(attacks + i) + baseBonusAtk + roll;
	}
}

int Character::GetAttack(int attack)
{
	return totalDamagePerRound[attack];
}

int Character::getBonusAtks(int batkIndex)
{
	return *(attacks + batkIndex);
}

bool Character::equipItem(string type){  //equip item for character
	
	backpack.removeItem(type);
	return true;
}

bool Character::unequipItem( Item *item){
	
	backpack.addItem(item);
	return true;
}


void Character::monsterClass()
{
	characterClass = "monster";
}

void Character::addItemToInventory(Item* newItem){
	backpack.addItem(newItem);
}

bool Character::displayEquipedItems(string s){  //view of the items equiped by the character

	return true;
}

ItemContainer Character::getBackPack(){
	return backpack;
}
void Character::displayBackpackItems(){
		backpack.print();
}

void Character::setAbilityScores(string classType)  //sets the abilityscores according to fighter type
{
	int abilites[6] = {};
	int temp = 0;

	for (size_t i = 0; i < 6; i++)  //get all of the current ability scores
	{
		abilites[i] = abilityScores[i];
	}

	int j = 0;
	int total = 0;
	for (size_t i = 0; i < 6; i++)  //sort the ability scores by descending order
	{
		j = total;
		for (j = 0; j < 6; j++)
		{
			if (abilites[i] < abilites[j])
			{
				temp = abilites[i];
				abilites[i] = abilites[j];
				abilites[j] = temp;
			}
		}
		total++;
	}

	//Assign ability scores based the type of fighter chosen
	if (classType == "Bully")
	{
		abilityScores[0] = abilites[5];
		abilityScores[2] = abilites[4];
		abilityScores[1] = abilites[3];
		abilityScores[3] = abilites[2];
		abilityScores[5] = abilites[1];
		abilityScores[4] = abilites[0];
		fighterType = "Bully";
	}

	if (classType == "Nimble")
	{
		abilityScores[1] = abilites[5];
		abilityScores[2] = abilites[4];
		abilityScores[0] = abilites[3];
		abilityScores[3] = abilites[2];
		abilityScores[5] = abilites[1];
		abilityScores[4] = abilites[0];
		fighterType = "Nimble";
	}

	if (classType == "Tank")
	{
		abilityScores[2] = abilites[5];
		abilityScores[1] = abilites[4];
		abilityScores[0] = abilites[3];
		abilityScores[3] = abilites[2];
		abilityScores[5] = abilites[1];
		abilityScores[4] = abilites[0];
		fighterType = "Tank";
	}
	//set your inital base bonus atk
	baseBonusAtk = abilityModifier(0) + abilityModifier(1);
	level = 1;
}

void Character::initializeBonusAttack(){
	baseBonusAtk = abilityModifier(0) + abilityModifier(1);
}

void Character::setAbilityScore(int index, int value){
	abilityScores[index] = value;
}

string Character::getClass(){
	return characterClass;
}
Item* Character::unsetItem(string s){
	return NULL;
}

bool Character::isEquiped(string s){
	return NULL;
}

Item* Character::getItem(string s){
	return NULL;
}

int Character::getAbilityScore(int index){
	return abilityScores[index];
}
vector<Item*> Character::getEquipment(){
	vector<Item*> equipment;
	return equipment;
}
string Character::getFighterType(){
	return fighterType;
}
void Character::setFighterType(string s){
	fighterType = s;
}