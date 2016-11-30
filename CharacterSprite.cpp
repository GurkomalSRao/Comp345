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


//! Function which allows a character to attack another character
//! @param T: The target of the attack
void CharacterSprite::attack(CharacterSprite* T){
	if (T->s->getStrategy() == 3)
	{
		delete T->s;
		T->s = new AggressiveStrategy();
		cout << "The monster decides it hates you now" << endl;
	}
}