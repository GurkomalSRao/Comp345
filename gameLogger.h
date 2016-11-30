#pragma once
#include "Observer.h"
#include "characterObserver.h"
#include "MapObserver.h"

class gameLogger : public Observer
{
public:
	gameLogger();
	gameLogger(ConcreteMap* m, AbstractCharacter* c);
	~gameLogger();
	void display();
private:
	ConcreteMap *_map;
	AbstractCharacter *_char;
	
};

