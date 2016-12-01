#include "SpriteStrategyObserver.h"


SpriteStrategyObserver::SpriteStrategyObserver()
{
}

SpriteStrategyObserver::SpriteStrategyObserver(SpriteStrategy* spriteStrategy)
{
	_spriteStrategy = spriteStrategy;
	_spriteStrategy->Attach(this);
}

SpriteStrategyObserver::~SpriteStrategyObserver()
{
	_spriteStrategy->Detach(this);
}

void SpriteStrategyObserver::Update(){

}