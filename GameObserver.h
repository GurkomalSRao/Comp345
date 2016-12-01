#pragma once
//#include "Observer.h"
#include "gameEngine.h"
#include <fstream>

class Observer;
//class gameEngine;

class GameObserver :
	public Observer
{
public:
	GameObserver(gameEngine* game);
	GameObserver();
	~GameObserver();
	//void attachObserver(Observer* o);
	void Record();
	void Update();
	void Update(string s, bool logs[4]){

		if (logs[0]){
			ofstream myfile;
		myfile.open("gameLogger.txt", std::ofstream::out | std::ofstream::app);
		myfile << s << "\n";
		myfile.close();
	}
	};
private:
	gameEngine* _game;
	//vector<Observer *> _allObservers;
};

