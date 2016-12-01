#pragma once
#include "Observer.h"
#include "SpriteStrategy.h"
#include <iostream>
#include <fstream>

class SpriteStrategyObserver :
	public Observer
{
public:
	SpriteStrategyObserver();
	SpriteStrategyObserver(SpriteStrategy* spriteStrategy);
	~SpriteStrategyObserver();
	void Update();
	void Update(string s, bool logs[4]){
		if (logs[3]){
		ofstream myfile;
		myfile.open("gameLogger.txt", std::ofstream::out | std::ofstream::app);
		myfile << s << "\n";
		myfile.close();
	}
	}
private:
	SpriteStrategy* _spriteStrategy;
};

