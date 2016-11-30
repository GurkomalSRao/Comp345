#pragma once

#include<iostream>
#include "SpriteStrategy.h"
#include <random>
using namespace std;
//COMP 345 Assignment 3
//Created by: Justin Velicogna
//Student ID: 40005294

enum Direction;
class ConcreteMap;

//! A strategy for friendly monsters
class FriendlyStrategy : public SpriteStrategy {
public:
	int getStrategy(){
		return 3;
	}

	//!Implementation of a strategy for friendly monsters
	//! @param speed: the number of moves per turn
	//! @param attacks: the number of attacks per turn
	//! @param me: the character executing the strategy
	//! @param avatar: the player character
	//! @param monsters: a list of monsters
	//! @param function: the function to be performed to update the map
	void execute(int speed, int attacks, CharacterSprite* me, CharacterSprite* avatar, vector<CharacterSprite*>* monsters, ConcreteMap* m) {
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
			system("pause");
			

			
		}
		random_device rd;
		mt19937 gen(rd());  
		uniform_int_distribution<> dis(0, 7);  
		int randomchoice = dis(gen);

		switch (randomchoice){//warning: friendly monsters may be TOO friendly
		case 0:
			cout << "The moster asks you out to dinner. You frantically explain to the monster you already ate." << endl;
			break;
		case 1:
			cout << "The monster asks you if you think it's pretty. You stutter and give a vague answer" << endl;
			break;
		case 2:
			cout << "The monster asks your your opinion on it's new outfit. You remark that it looks nice, causing the monster to blush." << endl;
			break;
		case 3:
			cout << "The monster asks you if you have a significant other. You hastily explain to the monster that you're married to your job as an adventurer." << endl;
			break;
		}
		system("pause");




	}
};

