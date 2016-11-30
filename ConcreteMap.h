//! @file 
//! @Implementation file for the concrete map class 
//!
#pragma once
#include "Map.h"
#include "AbstractCharacter.h"
#include "CharacterSprite.h"
#include "Item.h"
#include <vector>
using namespace std;


//! Character implementing a character sprite

//! class implementing a treasure sprite
class TreasureSprite{
public:
	Item* i;
	Coordinates pos;
};
//! enum for directions
enum Direction{up,down,left,right};
//! Class implementing a concrete map
class ConcreteMap : public Subject
{

	private:
		Map* m;
		int level;
		CharacterSprite* avatar;
		vector<CharacterSprite*>* monsters;
		vector<TreasureSprite> treasures;


		void fillTreasure(); //Fills remaining treasure chest with randomly generated items.
		void fillMonster(); //fills remaining monster spaces with monsters, adapted to level
		Map* generateFullMap();
	public:
		//ConcreteMap(Map m); //generates an avatar if none is given, default level is one
	 	
		ConcreteMap(Map* m, AbstractCharacter* avatar);//reads character's level
		bool loadTreasure(Item* i);//places an item into a treasure chest if one is avaible, returns wheather or not treasure is avaible
		void initMap();//calls fillTreasure and fillMonster, sets avatar's position to start
		void printMap(); 
		void printFullMap();
		CharacterSprite* getAvatar(); 
		vector<CharacterSprite*>* getMonsters();
		void displayMonsterInfo();
		void displayChestInfo();
		vector<TreasureSprite> getTreasures();
		Map getMap();//returns a map, no characters will be displayed
		Map getFullMap();//Characters will be displayed
		bool moveCharacter(Direction d, CharacterSprite* ch);
		bool moveAvatar(Direction d);
		bool moveMonster(Direction d, int index);//WILL NOT BE USED, MONSTERS DO NOT MOVE
		char getAvatarTile();//returns the tile underneath the avatar, including treasure or monsters if nececerry
		char getCell(int x, int y);
		bool isOccupied(int x, int y);
		bool canWalk(int x, int y);
		bool findTile(char find, int& x, int& y);
		bool removeMonster(int i);
		bool removeTreasure(Coordinates p);
		AbstractCharacter* getMonster(int i);
		Item* getTreasure(int i);
		AbstractCharacter* getMonster(Coordinates p);
		Item* getTreasure(Coordinates p);
		void NotifyMap();
		//void update();
};

