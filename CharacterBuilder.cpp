#include "CharacterBuilder.h"
#include "Dice.h"


CharacterBuilder::CharacterBuilder()
{
	
}

CharacterBuilder::~CharacterBuilder()
{
}

Character* CharacterBuilder::getCharacter()
{
	return myCharacter; 
}

void CharacterBuilder::createNewCharacter(Dice* d)
{
	myCharacter = new Character(d);
}

void CharacterBuilder::setScores()
{
	myCharacter->setAbilityScores("");
}