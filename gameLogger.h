#pragma once
#include "Observer.h"
#include "AbstractCharacter.h"
#include "ConcreteMap.h"
#include "Dice.h"
#include "gameEngine.h"

class gameLogger : public Observer
{
public:
	gameLogger();
	gameLogger(AbstractCharacter* conan, ConcreteMap* map, Dice* dice, gameEngine* game);
	~gameLogger();
private:
	ConcreteMap* _map;
	AbstractCharacter* _character;
	Dice* _dice;
	gameEngine* _game;
};