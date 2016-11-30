#pragma once

class Subject;

class Observer {
public:
	virtual ~Observer();
	virtual void Update() = 0;
protected:
	Observer();
private:
	Observer(const Observer& yRef);
	Observer& operator=(const Observer& yRef);
};
