#pragma once
#include "CharacterBuilder.h"
class NimbleFighterBuilder :
	public CharacterBuilder
{
public:
	NimbleFighterBuilder();
	~NimbleFighterBuilder();
	virtual void setScores();
};

