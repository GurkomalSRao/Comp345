#pragma once
#include "SpriteStrategy.h"
#include "Character.h"
#include <string>
#include <vector>
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
class CharacterSprite{
	private:
		SpriteStrategy* s;
	public:
		

		AbstractCharacter* c;
		CharacterSprite();
		Coordinates pos;
		void attack(CharacterSprite* t);
	
		//! mutator for strategy
		//! @param newStrategy: The strategy to be implemented
		void setStrategy(SpriteStrategy *newStrategy) {
			this->s = newStrategy;
		}
		//! performs the strategy
		//! @param avatar: the player's character
		//! @param dudes: the list of monsters
		//! @param function: the function to update the map
		void executeStrategy(CharacterSprite* avatar, vector<CharacterSprite*>* dudes, ConcreteMap* m) {
		
			this->s->execute(4,2,this,avatar, dudes, m);

		}
};