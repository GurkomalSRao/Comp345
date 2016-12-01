#pragma once
#include"Character.h"
#include "Dice.h"

class CharacterBuilder
{
public:
	Character* getCharacter();  //get the built character
	void createNewCharacter(Dice*);  //build a character
	virtual void setScores();
	CharacterBuilder();
	~CharacterBuilder();
protected:
	Character* myCharacter;
};

