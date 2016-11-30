//! @file 
//! @Implementation file for the Concrete Map class  
//!
#include "ConcreteMap.h"
#include "AbstractCharacter.h"
#include "AggressiveStrategy.h"
#include "HumanStrategy.h"
#include "FriendlyStrategy.h"
#include "Map.h"
#include <string>
#include <random>
using namespace std;




//! Implementation Fill treasure, fills all unassigned treasure boxes with treasure and converts them to treasuresprites.

void ConcreteMap::fillTreasure(){
	for (int i = 0; i < m->MAP_LENGTH; i++)
	for (int j = 0; j < m->MAP_WIDTH; j++)
	{
		if (m->getCell(i, j) == m->TREASURE_TILE)
		{
			int randomItem;
			int randomtype;
			int max;
			random_device rd;
			Item* tempItem = new Item();
			Enhancement tempEnhancement("Armor class", level);
			mt19937 gen(rd());  //initializes the generater
			uniform_int_distribution<> dis(0, 6);  //generates a range from 0 to 6
			enum itemTypes { Helmet, Armor, Weapon, Shield, Ring, Belt, Boots };
			randomItem = dis(gen);
			uniform_int_distribution<> ndis(0, 59); //No easy way to construct in a switch statement, so we cheat
			switch (randomItem){
			case Helmet:
				randomtype = ndis(gen) % 3;//this is cheating
				if (randomtype == 0)
				{
					tempEnhancement.setType("Intelligence");
				}
				else if (randomtype == 1)
				{
					tempEnhancement.setType("Wisdom");
				}
				else{
					tempEnhancement.setType("Armor class");
				}
				tempItem->setType("Helmet");
				break;
			case Armor:
				tempItem->setType("Armor");
				break;
			case Weapon:
				tempItem->setType("Weapon");
				randomtype = ndis(gen) % 2;
				if (randomtype == 0)
				{
					tempEnhancement.setType("Attack bonus");
				}
				else{
					tempEnhancement.setType("Damage bonus");
				}
				break;
			case Shield:
				tempItem->setType("Shield");
				break;
			case Ring:
				randomtype = ndis(gen) % 5;
				if (randomtype == 0)
				{
					tempEnhancement.setType("Stength");
				}
				else if (randomtype == 1)
				{
					tempEnhancement.setType("Constitution");
				}
				else if (randomtype == 2)
				{
					tempEnhancement.setType("Wisdom");
				}
				else if (randomtype == 3)
				{
					tempEnhancement.setType("Charisma");
				}
				else{
					tempEnhancement.setType("Armor class");
				}
				tempItem->setType("Ring");
				break;
			case Belt:
				tempItem->setType("Belt");
				randomtype = ndis(gen) % 2;
				if (randomtype == 0)
				{
					tempEnhancement.setType("Constitution");
				}
				else{
					tempEnhancement.setType("Strength");
				}
				break;
			case Boots:
				randomtype = ndis(gen) % 2;
				if (randomtype == 0)
				{
					tempEnhancement.setType("Armor class");
				}
				else{
					tempEnhancement.setType("Dexterity");
				}
				tempItem->setType("Boots");
				break;
			}
			tempItem->setInfluences(tempEnhancement);
			TreasureSprite t;
			t.i = tempItem;
			t.pos.x = i;
			t.pos.y = j;
			treasures.push_back(t);
			m->fillCell(i, j, m->BLANK_TILE);
		}
	}
}

//! Implementation coverts all monster tiles to monster sprites.

void ConcreteMap::fillMonster(){
	for (int i = 0; i < m->MAP_LENGTH; i++)
	for (int j = 0; j < m->MAP_WIDTH; j++)
		{
			if (m->getCell(i, j) == m->MONSTER_TILE)
			{
				Character* monster = new Character();
				monster->setLevel(level);
				monster->monsterClass();
				CharacterSprite mmonster;
				mmonster.c = monster;
				mmonster.pos.x = i;
				mmonster.pos.y = j;
				random_device rd;
				mt19937 gen(rd());  //initializes the generater
				uniform_int_distribution<> dis(0, 1);  //generates a range from 0 to 6
				enum itemTypes { Helmet, Armor, Weapon, Shield, Ring, Belt, Boots };
				int randomItem = dis(gen);
				if (randomItem == 0)
					mmonster.setStrategy(new AggressiveStrategy());
				else
					mmonster.setStrategy(new FriendlyStrategy());
				monsters.push_back(mmonster);
			}
			
		}
}

//! Implementation generates a map which includes item, monster, and avatar tiles
//! @return : A map with avatar, treasure, and item tiles
Map* ConcreteMap::generateFullMap(){
	Map* mymap = new Map();

	for (int i = 0; i < m->MAP_LENGTH; i++)
		for (int j = 0; j < m->MAP_WIDTH; j++)
			mymap->fillCell(i, j, m->getCell(i, j));

	
	
	for (int i = 0; i < treasures.size(); i++)//add back in tiles which were converted to sprites
	{
		mymap->fillCell(treasures[i].pos.x, treasures[i].pos.y, m->TREASURE_TILE);
	}
	for (int i = 0; i < monsters.size(); i++)
	{
		mymap->fillCell(monsters[i].pos.x, monsters[i].pos.y, m->MONSTER_TILE);
	}

	mymap->fillCell(avatar.pos.x, avatar.pos.y, m->AVATAR_TILE);

	return mymap;
}
ConcreteMap::ConcreteMap(Map* ma, AbstractCharacter* myAvatar){
	m = new Map();
	avatar;
	avatar.c = myAvatar;
	avatar.setStrategy(new HumanStrategy());
	int x;
	int y;
	ma->findTile(ma->START_TILE,x,y);
	avatar.pos.x = x;
	avatar.pos.y = y;
	m->copyMap(*ma);
	level = myAvatar->getLevel();
	
}

//! Implementation Loads user defined treasure into an avaible treasure box if avaible
//! @param i: the item to be assigned 
//! @return : a boolean true if there is a treasure avaible
bool ConcreteMap::loadTreasure(Item* i){
	int x, y;
	if(!m->findTile(m->TREASURE_TILE, x, y))
		return false;

	m->fillCell(x, y, m->BLANK_TILE);
	TreasureSprite t;
	t.i = i;
	t.pos.x = x;
	t.pos.y = y;
	treasures.push_back(t);
	return true;
}

//! Implementation Initialises the map to be played
void ConcreteMap::initMap(){
	fillMonster();
	fillTreasure();
	Notify();
}

//! Implementation prints out the contents of the map, no avatar, treasure or monsters
void ConcreteMap::printMap(){
	for (int i = 0; i < m->MAP_LENGTH; i++)
	{
		for (int j = 0; j < m->MAP_WIDTH; j++)
		{
			cout << m->getCell(i, j);
		}
		cout << endl;
	}
}
//! Implementation Prints out a map with avatar, treasure, and monsters included
void ConcreteMap::printFullMap(){
	Map* mymap = generateFullMap();
	
	mymap->print();
	delete mymap;
}

//! Implementation getter for the avatar
//! @return : returns the character avatar
CharacterSprite ConcreteMap::getAvatar(){
	return avatar;
}
//! Implementation getter for the monsters
//! @return : a vector list of monsters

vector<CharacterSprite> ConcreteMap::getMonsters(){
	return monsters;
}

//! Implementation getter for the treasures
//! @return : a vector list of treasures
vector<TreasureSprite> ConcreteMap::getTreasures(){
	return treasures;
}

//! Implementation getter for the map
//! @return : the map
Map ConcreteMap::getMap(){
	return *m;
}

//! Implementation Moves the avatar in a specified direction
//! @param d: the direction to move
//! @return : wheather the avatar moved successfully
bool ConcreteMap::moveAvatar(Direction d){
	switch (d)
	{

	case up:
		if (canWalk(avatar.pos.x - 1, avatar.pos.y))
		{
			avatar.pos.x--;
			Notify();
			return true;
		}
		else{
			return false;
		}
		break;
	case down:
		if (canWalk(avatar.pos.x + 1, avatar.pos.y))
		{
			avatar.pos.x++;
			Notify();
			return true;
		}
		else{
			return false;
		}
		break;
	case Direction::left:
		if (canWalk(avatar.pos.x, avatar.pos.y - 1))
		{
			avatar.pos.y--;
			Notify();
			return true;
		}
		else{
			return false;
		}
		break;
	case Direction::right:
		if (canWalk(avatar.pos.x, avatar.pos.y + 1))
		{
			avatar.pos.y++;
			Notify();
			return true;
		}
		else{
			return false;
		}
		break;
	}
}

void ConcreteMap::NotifyMap(){
	Notify();
}


//! Implementation finds the tile underneath the avatar
//! @return : the tile under the avatar, possibly a monster or treasure
char ConcreteMap::getAvatarTile(){
	return getCell(avatar.pos.x, avatar.pos.y);
}

//! Implementation gets the cell at a specific position, possibly a monster or treasure, but not the avatar
//! @return : the tile
char ConcreteMap::getCell(int x, int y){
	
	for (int i = 0; i < monsters.size(); i++)
	{
		if (monsters[i].pos.x == x && monsters[i].pos.y == y)
			return m->MONSTER_TILE;
	}
	for (int i = 0; i < treasures.size(); i++)
	{
		if (treasures[i].pos.x == x && treasures[i].pos.y == y)
			return m->TREASURE_TILE;
	}
	return m->getCell(x, y);

}

//! Implementation checks if a tile is occupied
//! @param x: x coordinate of the tile
//! @param y: y coordinate of the tile
//! @return : wheather or not the tile is occupied
bool ConcreteMap::isOccupied(int x, int y){
	if (m->isOccupied(x, y))
		return true;
	
	return false;
}
//! Implementation checks if a tile is passable
//! @param x: x coordinate of the tile
//! @param y: y coordinate of the tile
//! @return : wheather or not the tile can be walked on
bool ConcreteMap::canWalk(int x, int y){
	if (m->canWalk(x, y))
		return true;

	return false;
}

//! Implementation finds a tile of specified type, includes monster, treasure, or avatar tiles
//! @param find: the type of tile to be found
//! @param x: x coordinate of the tile
//! @param y: y coordinate of the tile
//! @return : wheather or not the tile was found
bool ConcreteMap::findTile(char find, int& x, int& y){
	if (find == m->AVATAR_TILE)
	{
		x = avatar.pos.x;
		y = avatar.pos.y;
		return true;
	}
	if (find == m->MONSTER_TILE)
	{
		if (monsters.empty())
			return false;
		x = monsters[0].pos.x;
		y = monsters[0].pos.y;
		return true;
	}
	if (find == m->TREASURE_TILE)
	{
		if (treasures.empty())
			return false;
		x = treasures[0].pos.x;
		y = treasures[0].pos.y;
		return true;
	}

}
bool ConcreteMap::removeMonster(int i){
	Notify();
	return false;
}

//! Implementation removes a treasure from the map
//! @param p: the position of the treasure to be removed 
//! @return : wheather or not a treasure was removed
bool ConcreteMap::removeTreasure(Coordinates p){
	for (int j = 0; j < treasures.size(); j++)
	{
		if (treasures[j].pos.x == p.x && treasures[j].pos.y == p.y)
		{
			treasures.erase(treasures.begin() + j);
			Notify();
			return true;
		}
	}
	return false;
}

//! Implementation gets a monster at a specific index
//! @param i: index of the monster
//! @return : the monster
AbstractCharacter* ConcreteMap::getMonster(int i){
	return monsters[i].c;
}

//! Implementation gets a treasure at a specific index
//! @param i: index of the item
//! @return : the ite,
Item* ConcreteMap::getTreasure(int i){
	return treasures[i].i;
}

//! Implementation gets a monster at a specific coordinates
//! @param p: coordinates of the monster
//! @return : the monster
AbstractCharacter* ConcreteMap::getMonster(Coordinates p){
	for (int i = 0; i < monsters.size(); i++)
	{
		if (monsters[i].pos.x == p.x && monsters[i].pos.y == p.y)
			return monsters[i].c;
	}
	return NULL;
}

//! Implementation gets a treasure at a specific coordinates
//! @param p: coordinates of the treasure
//! @return : the treasure
Item* ConcreteMap::getTreasure(Coordinates p){
	for (int j = 0; j < treasures.size(); j++)
	{
		if (treasures[j].pos.x == p.x && treasures[j].pos.y == p.y)
			return treasures[j].i;
	}
}
//! Implementation displays info on all monsters in the room
void ConcreteMap::displayMonsterInfo()
{
	for (size_t i = 0; i < monsters.size(); i++)
	{
		cout << "Monster" << i+1 << endl;
		monsters[i].c->display();
	}
	if (monsters.size() == 0)
	{
		cout << "No monsters in the room" << endl;
	}

}
//! Implementation displays info on all treasuresin the room
void ConcreteMap::displayChestInfo()
{
	for (size_t i = 0; i < treasures.size(); i++)
	{
		cout << "Chest" << i+1 << endl;
		treasures[i].i->print();
	}
	if (treasures.size() == 0)
	{
		cout << "No Chests in the room" << endl;
	}
}