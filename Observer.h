#pragma once
#include <string>
using namespace std;
class Subject;

class Observer {
public:
	virtual ~Observer();
	virtual void Update() = 0;
	virtual void Update(string s, bool logs[4]) = 0;
protected:
	Observer();
private:
	Observer(const Observer& yRef);
	Observer& operator=(const Observer& yRef);
};
