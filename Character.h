//! @file 
//! @brief Header file for the Character class  
//!

#pragma once
#include<string>
#include<iostream>
#include "AbstractCharacter.h"
#include "ItemContainer.h"
#include "Dice.h"

using namespace std;

//! Class that implements a character 
class Character:  public AbstractCharacter
{
public:
	Character();
	Character(bool b);
	Character(int, int, int, int, int, int);
	Character(Dice*);
	bool validateNewCharacter();
	void hit(int);
	int getBonusAttacks();
	int getHitPoints();
	void setHitPoints(int);
	int abilityScore();
	int abilityModifier(int);
	void modifyHP();
	Dice* getDice();
	void setLevel(int);
	void setCharacterLevel(int);
	int armor();
	int attackBonus();
	int damageBonus();
	bool equipItem(string);
	bool unequipItem(Item*);
	void addItemToInventory(Item*);
	void display();
	bool displayEquipedItems(string s);
	void displayBackpackItems();
	int getLevel();
	//void saveCharacter();
	//void loadCharacter();
	const Item noItem;
	void monsterClass();
	
	ItemContainer getBackPack();
	void setAbilityScore(int, int);
	void setAbilityScores(string);
	Item* unsetItem(string);
	bool isEquiped(string);
	string getClass();
	virtual int getAbilityScore(int);
	Item* getItem(string);
	vector<Item*> getEquipment();
	string getFighterType();
	void setFighterType(string);
	int getAttacksSize();
	void SetAttack();
	int GetAttack(int);
	int getBaseBonus();
	void setArmor();
	void setBonusDamage();
	void initializeBonusAttack();
	int getBonusAtks(int);
	void setDice(Dice*);
	void SetBonusAttacks(int);
	int getAccuracy(int);
	int getDamage();
	void setCharName(string);
	string getCharName();
private: 
	string characterClass;
	ItemContainer backpack;
	enum equipmentSlots {Helmet, Armor, MainHand, OffHand, Ring, Belt, Boots };
	//Item equipment[ITEM_SLOTS];
	int abilityScores[6];
	int currentHitPoints;
	int level;
	string charName;
	//int* attacks;
	//int* totalDamagePerRound = new int(1);
	//int length;
	//int baseBonusAtk;
	string fighterType;
	Dice* dice;
	//int armorClass;
	//int bonusDamage;
};

