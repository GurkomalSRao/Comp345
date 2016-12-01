#pragma once
#include "Observer.h"
#include <vector>
#include "ConcreteMap.h"
class MapObserver :
	public Observer
{
public:
	MapObserver();
	MapObserver(ConcreteMap* m);
	~MapObserver();
	void Update();
	void Update(string s, bool logs[4]){};
	void displayMap();
private:
	ConcreteMap *_map;
};

