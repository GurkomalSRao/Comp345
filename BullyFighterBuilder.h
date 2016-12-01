#pragma once
#include "CharacterBuilder.h"
#include "Dice.h"
class BullyFighterBuilder :
	public CharacterBuilder
{
public:
	BullyFighterBuilder();
	~BullyFighterBuilder();
	virtual void setScores();
};

