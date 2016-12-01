#include "DiceObserver.h"


DiceObserver::DiceObserver()
{
}

DiceObserver::DiceObserver(Dice* d)
{
	_dice = d;
	_dice->Attach(this);
}

DiceObserver::~DiceObserver()
{
	_dice->Detach(this);
}

void DiceObserver::RecordRoll()
{
	//cout << "Roll Recorded!" << endl;
}

void DiceObserver::Update()
{
}
