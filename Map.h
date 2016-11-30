//! @file 
//! @brief Implementation file for the Item class  
//!
#pragma once
#include "Subject.h"
#include <string>
using namespace std;
//! constant for map length
#define MAP_MAXLENGTH 30
#define MAP_MAXWIDTH 30

//! Class implementing a game map
class Map 
{

private:


	//const int MAP_LENGTH;
	//const int MAP_WIDTH;
	//! constant for map width

	char map[MAP_MAXLENGTH][MAP_MAXWIDTH];
	bool validatePath(char[MAP_MAXLENGTH][MAP_MAXWIDTH], int x, int y);

public:
	int const MAP_LENGTH = MAP_MAXWIDTH;
	int const MAP_WIDTH = MAP_MAXLENGTH;

	static char const START_TILE = '<';
	static char const END_TILE = '>';
	static char const BLANK_TILE = '.';
	static char const WALL_TILE = 'X';
	static char const TREASURE_TILE = '=';
	static char const AVATAR_TILE = '@';
	static char const MONSTER_TILE = '&';

	Map();
	Map(char[MAP_MAXLENGTH][MAP_MAXWIDTH]);
	bool validatePath();
	void fillCell(int x, int y, char obj);
	char getCell(int x, int y);
	bool isOccupied(int x, int y);
	bool canWalk(int x, int y);
	bool findTile(char find, int& x, int& y);
	bool saveMap(string fname);
	void loadMap(string fname);
	void print();
	void copyMap(Map m);
};

