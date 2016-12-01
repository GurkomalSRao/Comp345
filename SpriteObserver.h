#pragma once
#include "Observer.h"
#include <fstream>
#include "CharacterSprite.h"

class SpriteObserver : public Observer
{
public:
	SpriteObserver();
	SpriteObserver(CharacterSprite* sprite);
	~SpriteObserver();
	void Update();
	void Update(string s, bool logs[4]){
		if (logs[2]){
		ofstream myfile;
		myfile.open("gameLogger.txt", std::ofstream::out | std::ofstream::app);
		myfile << s << "\n";
		myfile.close();
	}
	};
private:
	CharacterSprite* _charSprite;
};

