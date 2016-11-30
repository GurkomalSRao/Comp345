#include "CharacterObserver.h"
#include <iostream>
using namespace std;


CharacterObserver::CharacterObserver()
{
}

CharacterObserver::CharacterObserver(AbstractCharacter* conan)
{
	_character = conan;
	_character->Attach(this);
}

CharacterObserver::~CharacterObserver()
{
	_character->Detach(this);
}

void CharacterObserver::displayView()  //displays the charcter view 
{
	system("CLS");
	_character->display();
}


void CharacterObserver::Update()  //updates the character Observer
{
	displayView();
}