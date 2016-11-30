#include "Fighter.h"


Fighter::Fighter()
{
}


Fighter::~Fighter()
{
}

void Fighter::setCharacterBuilder(CharacterBuilder* ch)
{
	myCharacterBuilder = ch;
}

Character* Fighter::getCharacter()
{
	return myCharacterBuilder->getCharacter();
}

void Fighter::constructCharacter()
{
	myCharacterBuilder->createNewCharacter();
	myCharacterBuilder->setScores();
}