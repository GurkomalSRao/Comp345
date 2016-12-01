#pragma once
#include "Subject.h"
//COMP 345 Assignment 3
//Created by: Justin Velicogna
//Student ID: 40005294

//#include "CharacterSprite.h"
#include <vector>
using namespace std;


class CharacterSprite;
class ConcreteMap;


class SpriteStrategy : public Subject {
public:
	
	/**
	* Method whose implementation varies depending on the strategy adopted.
	*/
	virtual int getStrategyNumber() = 0;

	
	
	virtual void execute(int speed, int attacks, CharacterSprite* me, CharacterSprite* avatar, vector<CharacterSprite*>* monsters, ConcreteMap* m, void(*log)(),bool logs[4]) = 0;


	
};

