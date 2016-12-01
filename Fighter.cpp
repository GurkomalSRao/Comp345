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

void Fighter::constructCharacter(Dice* d)
{
	myCharacterBuilder->createNewCharacter(d);
	//myCharacterBuilder->getCharacter();
	myCharacterBuilder->setScores();
}