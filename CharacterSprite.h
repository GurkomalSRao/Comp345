#pragma once
#include "SpriteStrategy.h"
#include "Character.h"
#include <string>
#include <vector>
#include "Subject.h"
#include "Weapon.h""
#include "Armor.h"
#include "Ring.h"
#include "Helmet.h"
#include "Belt.h"
#include "Boots.h"
#include "Shield.h"
//#include "GameObserver.h"

using namespace std;
//COMP 345 Assignment 3
//Created by: Justin Velicogna
//Student ID: 40005294

//! Class implementing an x and y position
class Coordinates{
public:
	int x = 0;
	int y = 0;

};
enum Direction;
//! Character implementing a character sprite
class CharacterSprite: public Subject
{
	private:
		SpriteStrategy* s;
	public:

		AbstractCharacter* c;
		CharacterSprite();
		Coordinates pos;
		void attack(CharacterSprite* t, int i, bool logs[]);
	
		//! mutator for strategy
		//! @param newStrategy: The strategy to be implemented
		void setStrategy(SpriteStrategy *newStrategy) {
			this->s = newStrategy;
		}
		SpriteStrategy* getStrategy(){
			return s;
		}

		void displayEquipedItems(bool logs[]);
		void printEquipmentInterface();
		//! performs the strategy
		//! @param avatar: the player's character
		//! @param dudes: the list of monsters
		//! @param function: the function to update the map
		void executeStrategy(CharacterSprite* avatar, vector<CharacterSprite*>* dudes, ConcreteMap* m,void(*log)(), bool logs[4]) {
		
			this->s->execute(4,c->getBonusAttacks(),this,avatar, dudes, m,log,logs);
		}
};