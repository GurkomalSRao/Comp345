//! @file 
//! @brief Implementation file for the Character class  
//!

#include "Character.h"
#include <stdlib.h> 
#include <time.h>
#include <iostream>
#include <fstream>
#include "DiceObserver.h"
#include <random>
#include <string>
using namespace std;

//! Constructor: passes values to each ability score and set hit points to 10
Character::Character(int str, int dex, int con, int intel, int wis, int cha)
{
	dice = new Dice();
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
	//baseBonusAtk = abilityModifier(0) + abilityModifier(1);
	level = 1;
	//length = 1;
}
Character::Character(bool b)//exists because reasons
{
	dice = new Dice();
}
Character::Character()  //generated random ability scores and class set to fighter
{
	characterClass = "fighter";
	//dice = new Dice();
	//attacks = new int(1);
	/*abilityScores[0] = abilityScore();
	abilityScores[1] = abilityScore();
	abilityScores[2] = abilityScore();
	abilityScores[3] = abilityScore();
	abilityScores[4] = abilityScore();
	abilityScores[5] = abilityScore();
	level = 1;
	
	//fill equipment slots with empty item
	/*for (int i = 0; i < 7; i++){
		equipment[i] = noItem;
	}
	attacks = new int(1);
	currentHitPoints = 10 + abilityModifier(2);
	characterClass = "fighter";
	baseBonusAtk = abilityModifier(0) + abilityModifier(1);
	level = 1;
	length = 1;
	Notify();*/
	level = 1;
	abilityScores[0] = 0;
	abilityScores[1] = 0;
	abilityScores[2] = 0;
	abilityScores[3] = 0;
	abilityScores[4] = 0;
	abilityScores[5] = 0;
	currentHitPoints = 1;
	dice = new Dice();
	Notify();
}

Character::Character(Dice* die)
{
	dice = die;
	abilityScores[0] = abilityScore();
	abilityScores[1] = abilityScore();
	abilityScores[2] = abilityScore();
	abilityScores[3] = abilityScore();
	abilityScores[4] = abilityScore();
	abilityScores[5] = abilityScore();
	

	//fill equipment slots with empty item
	/*for (int i = 0; i < 7; i++){
	equipment[i] = noItem;
	}*/
	//attacks = new int(1);
	currentHitPoints = 10 + abilityModifier(2);
	characterClass = "fighter";
	//baseBonusAtk = abilityModifier(0) + abilityModifier(1);
	level = 1;
	//length = 1;
	Notify();
}

void Character::setCharName(string name)
{
	charName = name;
}

string Character::getCharName()
{
	return charName;
}

void Character::setDice(Dice* die)
{
	dice = die;
}

Dice* Character::getDice(){
	return dice;
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
	int roll;
	roll = dice->roll(4, 6);
//	NotifyGame("Dice Roll For Ability Score: "+roll);
	return roll;
}


int Character::abilityModifier(int ability)
{

	return abilityScores[ability] / 2 - 5;
}

void Character::modifyHP()
{
	int roll = 0;
	roll = dice->roll(1, 10);
	currentHitPoints += roll + abilityModifier(2);
	//NotifyGame("Dice Roll For HP: " + roll,logs);
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
	int armorClass = 10 + abilityModifier(1);
	return armorClass;
}

//void Character::setArmor()
//{
	//armorClass = 10 + abilityModifier(1);
//}

int Character::attackBonus()
{
	/*int bonusPerRound = level;
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
	}*/

	return abilityModifier(0);
}

int Character::getBonusAttacks(){
	return 1 +((1- level) / 5);
}

/*void Character::SetBonusAttacks(int lvl)
{
	int bonusPerRound = lvl;

	int bonusattacks = 
	int* 
	if (level % 5 == 1)
	{
		size++;
		attacks = new int(size);
		totalDamagePerRound = new int(size);
	}

	for (size_t i = 0; i < bonusattacks - 1; i++)
	{
		if (bonusPerRound > 0)
		{
			attacks[i] = bonusPerRound;
			bonusPerRound -= 5;
		}
	}
}*/

int Character::damageBonus()
{
	return abilityModifier(0); 
}

//void Character::setBonusDamage()
//{
//	bonusDamage = abilityModifier(0);
//}

int Character::getAccuracy(int attack)
{
	int roll;
	roll = dice->roll(1, 20);
	int damage = attackBonus() + roll + level - (5 * (attack - 1));

	//NotifyGame("Attack Roll: " + roll);
	return damage;
}

int Character::getDamage()
{
	int roll;
	roll = dice->roll(1,8);
	int damage = roll + damageBonus();
	//NotifyGame("Damage Roll: " + roll);
	return damage;
}

void Character::display() //displays the view of the character interface
{
	cout << "Class: " << characterClass << " Level: " << level << " HP: " << currentHitPoints << " AC: " << armor() << " Bonus Atk: ";
	cout << attackBonus() << " ";
	
	cout << " BD " << damageBonus() << endl;
	cout << "St: " << abilityScores[0] << " Dx: " << abilityScores[1] << " Co: " << abilityScores[2]
		<< " In: " << abilityScores[3] << " Wi: " << abilityScores[4] << " Ch: " << abilityScores[5] << endl << endl;
}

int Character::getLevel()
{
	return level;
}

//int Character::getBaseBonus()
//{
	//return baseBonusAtk;
//}

//int Character::getAttacksSize()
//{
	//return length;
//}

/*void Character::SetAttack()
{
	

	for (size_t i = 0; i < length; i++)
	{
		roll = dice->roll(1, 20);
		*(totalDamagePerRound + i) = *(attacks + i) + baseBonusAtk + roll;
		NotifyGame("Dice Roll For attacking: " + roll);
	}
}*/

void Character::setCharacterLevel(int lvl){
	level = lvl;
}

int Character::GetAttack(int attack)
{
	int roll;
	int damage;
	//for (size_t i = 0; i < length; i++)
	//{
		roll = dice->roll(1, 20);
		damage =  attackBonus() + roll + level -(5*(attack-1));

		//NotifyGame("Dice Roll For attacking: " + roll);
		return damage;
	//}
	//return totalDamagePerRound[attack];
}

/*int Character::getBonusAtks(int batkIndex)
{
	return *(attacks + batkIndex);
}*/

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
	//baseBonusAtk = abilityModifier(0) + abilityModifier(1);
	level = 1;
}

//void Character::initializeBonusAttack(){
	//baseBonusAtk = abilityModifier(0) + abilityModifier(1);
//}

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