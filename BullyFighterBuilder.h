#pragma once
#include "CharacterBuilder.h"
class BullyFighterBuilder :
	public CharacterBuilder
{
public:
	BullyFighterBuilder();
	~BullyFighterBuilder();
	virtual void setScores();
};

