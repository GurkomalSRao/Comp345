#pragma once

#include <iostream>
#include "SpriteStrategy.h"
#include <random>
#include "ConcreteMap.h"

using namespace std;
//COMP 345 Assignment 3
//Created by: Justin Velicogna
//Student ID: 40005294


//enum Direction{ up, down, left, right };

//! Implementation of a strategy for aggressive monsters
class AggressiveStrategy : public SpriteStrategy {
public:
	int getStrategyNumber(){
		return 2;
	}

	//!Implementation of a strategy for aggressive monsters
	//! @param speed: the number of moves per turn
	//! @param attacks: the number of attacks per turn
	//! @param me: the character executing the strategy
	//! @param avatar: the player character
	//! @param monsters: a list of monsters
	//! @param function: the function to be performed to update the map
	void execute(int speed, int attacks, CharacterSprite* me, CharacterSprite* avatar, vector<CharacterSprite*>* monsters, ConcreteMap* m, void(*log)(),bool logs[]) {
		for (int i = 0; i < speed; i++)
		{
			if ((abs(me->pos.x - avatar->pos.x) == 1 && abs(me->pos.y - avatar->pos.y) == 0) || (abs(me->pos.x - avatar->pos.x) == 0 && abs(me->pos.y - avatar->pos.y) == 1))
				break;
			if (abs(me->pos.x - avatar->pos.x)  > abs(me->pos.y - avatar->pos.y))
			{
				if (abs(me->pos.x > avatar->pos.x))
					m->moveCharacter(Direction::up, me);
				else
					m->moveCharacter(Direction::down, me);
			}
			else{
				if (abs(me->pos.y > avatar->pos.y))
					m->moveCharacter(Direction::left, me);
				else
					m->moveCharacter(Direction::right, me);
			}
			//system("pause");

		}
		NotifyGame("Player Turn Ended", logs);
		for (int i = 0; i < attacks; i++)
		{
			if ((abs(me->pos.x - avatar->pos.x) == 1 && abs(me->pos.y - avatar->pos.y) == 0) || (abs(me->pos.x - avatar->pos.x) == 0 && abs(me->pos.y - avatar->pos.y) == 1))
			{
				me->attack(avatar,i,logs);
				if (avatar->c->getHitPoints() <= 0)
				{
					NotifyGame("Player was killed by " + me->c->getCharName(),logs);

					cout << "You died!" << endl;
					system("pause");
					exit(0);
				}

				//cout << "The monster konks you in the head" << endl;
			}
		}
		
		random_device rd;
		mt19937 gen(rd());  
		uniform_int_distribution<> dis(0, 7);  
		int randomchoice = dis(gen);

		switch (randomchoice){
			case 0:
				cout << "The moster lets out a terrifying roar! You feel pretty intimidated" << endl;
				break;
			case 1:
				cout << "The monster laughs at you. You feel ashamed" << endl;
				break;
			case 2:
				cout << "The monster makes a rude guesture at you. Your anger swells" << endl;
				break;
			case 3:
				cout << "The monster makes a yo mama joke. It's not a very good yo mama joke though." << endl;
				break;
		}
		system("pause");

		



	}
};

