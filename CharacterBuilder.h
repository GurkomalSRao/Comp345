#pragma once
#include"Character.h"

class CharacterBuilder
{
public:
	Character* getCharacter();  //get the built character
	void createNewCharacter();  //build a character
	virtual void setScores();
	CharacterBuilder();
	~CharacterBuilder();
protected:
	Character* myCharacter;
};

