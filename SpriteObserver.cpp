#include "SpriteObserver.h"


SpriteObserver::SpriteObserver()
{
}

SpriteObserver::SpriteObserver(CharacterSprite* sprite)
{
	_charSprite = sprite;
	_charSprite->Attach(this);
}

SpriteObserver::~SpriteObserver()
{
	_charSprite->Detach(this);
}

void SpriteObserver::Update(){

}