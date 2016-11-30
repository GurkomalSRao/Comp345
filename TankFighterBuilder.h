#pragma once
#include "CharacterBuilder.h"
class TankFighterBuilder :
	public CharacterBuilder
{
public:
	TankFighterBuilder();
	~TankFighterBuilder();
	virtual void setScores();
};

