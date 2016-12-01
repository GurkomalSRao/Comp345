#pragma once
#include "CharacterBuilder.h"
#include "Dice.h"
class Fighter
{
public:
	Fighter();
	~Fighter();
	void setCharacterBuilder(CharacterBuilder* ch);
	Character* getCharacter();
	void constructCharacter(Dice* d);
private:
	CharacterBuilder* myCharacterBuilder;
};

