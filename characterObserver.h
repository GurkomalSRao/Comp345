#pragma once
#include "Observer.h"
#include "AbstractCharacter.h"

class CharacterObserver : public Observer
{
public:
	CharacterObserver();
	CharacterObserver(AbstractCharacter* conan);
	~CharacterObserver();
	void Update();
	void displayView();
private:
	AbstractCharacter* _character;
};

