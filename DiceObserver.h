#pragma once
#include "Observer.h"
#include <iostream>
#include <fstream>
#include "Dice.h"
class DiceObserver :
	public Observer
{
public:
	DiceObserver();
	DiceObserver(Dice* d);
	~DiceObserver();
	void RecordRoll();
	void Update();
	void Update(string s, bool logs[4]){
		if (logs[3])
		{
			ofstream myfile;
			myfile.open("gameLogger.txt", std::ofstream::out | std::ofstream::app);
			myfile << s << "\n";
			myfile.close();
		}
	};
private:
	Dice* _dice;
};

