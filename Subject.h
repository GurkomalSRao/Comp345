#pragma once
#include "Observer.h"
#include <string>
#include <list>
using namespace std;


class Observer;

class Subject {
public:
	virtual void Attach(Observer* o);
	virtual void Detach(Observer* o);
	virtual void Notify();
	virtual void NotifyGame(string s,  bool logs[4]);
	Subject();
	~Subject();
private:
	list<Observer*> *_observers;
};
