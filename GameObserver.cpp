#include "GameObserver.h"


GameObserver::GameObserver()
{
}

//void GameObserver::attachObserver(Observer* o){
//	
//}

GameObserver::GameObserver(gameEngine* game)
{
	_game = game;
	_game->Attach(this);
}

GameObserver::~GameObserver()
{
	_game->Detach(this);
}

void GameObserver::Record()
{
	//cout << s << "!" << endl;
}

void GameObserver::Update()
{
	
}
