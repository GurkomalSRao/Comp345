#pragma once
#include "CharacterBuilder.h"
class Fighter
{
public:
	Fighter();
	~Fighter();
	void setCharacterBuilder(CharacterBuilder* ch);
	Character* getCharacter();
	void constructCharacter();
private:
	CharacterBuilder* myCharacterBuilder;
};

