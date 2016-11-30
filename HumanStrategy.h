#pragma once

//COMP 345 Assignment 3
//Created by: Justin Velicogna
//Student ID: 40005294

enum Direction;


#include <vector>
#include<iostream>
#include <string>
#include "SpriteStrategy.h"
#include "ConcreteMap.h"//for the direction enum
#include "CharacterSprite.h"
using namespace std;

//! Implementation of a strategy for the player
class HumanStrategy : public SpriteStrategy {
public:
	int getStrategy(){
		return 1;
	}

	//!Implementation of a strategy for the player
	//! @param speed: the number of moves per turn
	//! @param attacks: the number of attacks per turn
	//! @param me: the character executing the strategy
	//! @param avatar: the player character
	//! @param monsters: a list of monsters
	//! @param function: the function to be performed to update the map
	void execute(int speed, int attacks, CharacterSprite* me, CharacterSprite* avatar, vector<CharacterSprite*>* monsters, ConcreteMap* m) {
		cout << "Move using WASD, or press F to stop moving";
		for (int i = 0; i < speed; i++)
		{
			char c;
			cin >> c;
			c = toupper(c);
			switch (c)
			{
			case 'W':
				if (!(m->moveCharacter(Direction::up, me)))
					i--;
				break;
			case 'S':
				if (!(m->moveCharacter(Direction::down, me)))
					i--;
				break;
			case 'A':
				if (!(m->moveCharacter(Direction::left, me)))
					i--;
				break;
			case 'D':
				if (!(m->moveCharacter(Direction::right, me)))
					i--;
				break;
			case 'F':
				i = speed;
				break;
			default:
				i--;
				cout << "Bad input" << endl;
				break;

			}
			
			//function(avatar, monsters);
		}
		cout << "Press WASD to attack in that direction! Or press F to stop attacking.";
		for (int i = 0; i < attacks; i++)
		{
			bool dontattack = false;
			char c;
			cin >> c;
			c = toupper(c);
			Coordinates toatk;
			toatk.x = me->pos.x;
			toatk.y = me->pos.y;
			switch (c)
			{
			case 'W':
				toatk.x--;
				break;
			case 'S':
				toatk.x++;
				break;
			case 'A':
				toatk.y--;
				break;
			case 'D':
				toatk.y++;
				break;
			case 'F':
				i = attacks;
				dontattack = true;
				break;
			default:
				i--;
				dontattack = true;
				cout << "Bad input" << endl;
				break;

			}
			if (!dontattack){
				for (int j = 0; j < monsters->size();j++)
				{
					if ((monsters->at(j)->pos.x == toatk.x && monsters->at(j)->pos.y == toatk.y))
					{
						me->attack(monsters->at(j));
						cout << "You give the monster a knuckle sandwich!" << endl;
					}
				}
			}
		}
		cout << "Press WASD to perform a free action! Or press anything else to perform no free action.";//Warning: free actions may be hilarious
		string c;
		cin >> c;
		if (c == "W" || c == "w"){
			cout << "You let out a mighty wail! It was not effective." << endl;
		}
		if (c == "S" || c == "s"){
			cout << "You sniff around. It smells like someone needs to clean this place up." << endl;
		}
		if (c == "A" || c == "a"){
			cout << "You act out an impression of your enemy, they are not impressed." << endl;
		}
		if (c == "D" || c == "d"){
			cout << "You start dancing. Though you feel like your moves are smooth, noone else shares your opinion." << endl;
		}
		if(c == "get ye flask"){//easter egg
			cout << "You find a flask and quaff it down. It invigorates you" << endl;
		}
		system("pause");
		

	

	}
};

