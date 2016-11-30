#include "CharacterBuilder.h"

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

void CharacterBuilder::createNewCharacter()
{
	myCharacter = new Character();
}

void CharacterBuilder::setScores()
{
	myCharacter->setAbilityScores("");
}