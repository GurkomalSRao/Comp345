#include "gameLogger.h"


gameLogger::gameLogger()
{
}
gameLogger::gameLogger(ConcreteMap* m, AbstractCharacter* c){
	_map = m;
	_char = c;
}

gameLogger::~gameLogger()
{
}

void gameLogger::display(){

}