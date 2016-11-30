//! @file 
//! @Implementation file for the Map class  
//!
#include "Map.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

#define MAP_MAXLENGTH 30
#define MAP_MAXWIDTH 30






bool Map::validatePath(char searchgrid[MAP_MAXLENGTH][MAP_MAXWIDTH], int x, int y)
{
	if (map[x][y] == END_TILE)
		return true;
	else
		searchgrid[x][y] = '+';


	//validate north tiles
	if (x > 0 && map[x - 1][y] != WALL_TILE && searchgrid[x - 1][y] != '+')
	if (validatePath(searchgrid, x - 1, y))
		return true;
	//validate west tiles
	if (y > 0 && map[x][y - 1] != WALL_TILE && searchgrid[x][y - 1] != '+')
	if (validatePath(searchgrid, x, y - 1))
		return true;
	//validate south tiles
	if (x < MAP_LENGTH - 1 && map[x + 1][y] != WALL_TILE && searchgrid[x + 1][y] != '+')
	if (validatePath(searchgrid, x + 1, y))
		return true;
	//validate east tiles
	if (y < MAP_LENGTH - 1 && map[x][y + 1] != WALL_TILE && searchgrid[x][y + 1] != '+')
	if (validatePath(searchgrid, x, y + 1))
		return true;

	



	return false;
}

Map::Map()
{
	for (int i = 0; i<MAP_LENGTH; i++)
	for (int j = 0; j < MAP_WIDTH; j++)
		map[i][j] = BLANK_TILE;
}


Map::Map(char tomap[MAP_MAXLENGTH][MAP_MAXWIDTH])
{
	for (int i = 0; i<MAP_LENGTH; i++)
	for (int j = 0; j < MAP_WIDTH; j++)
		map[i][j] = tomap[i][j];
}


//! Implementation of the map verification
//! @return bool value, true of the map is valid (there is at least one clear path between the mandatory begin and end cell). 
bool Map::validatePath()
{


	//----Find start tile-------
	int sx;
	int sy;
	int ex;
	int ey;
	int bx;
	int by;
	if (!findTile(END_TILE, ex, ey))
		return false;
	if (!findTile(START_TILE, sx, sy))
		return false;

	map[sx][sy] = BLANK_TILE;
	if (findTile(START_TILE, bx, by))//check if there is more then one start
		return false;
	map[sx][sy] = START_TILE;

	map[ex][ey] = BLANK_TILE;
	if (findTile(END_TILE, bx, by))//check if there is more then one end
		return false;
	map[ex][ey] = END_TILE;


	char searchgrid[MAP_MAXLENGTH][MAP_MAXWIDTH];

	for (int i = 0; i<MAP_LENGTH; i++)
	for (int j = 0; j < MAP_WIDTH; j++)
		searchgrid[i][j] = ' ';

	//searchgrid[sx][sy] = '+';

	return validatePath(searchgrid, sx, sy);

	return true;
}


//! Implementation of fill cell, set any cell to anything it might eventually contain
//! @param x: an integer value of horizontal index of the map's grid
//! @param y: an integer value of vertical index of the map's grid
//! @param obj: a character value of object that fills the cell
void Map::fillCell(int x, int y, char obj)
{
	map[x][y] = obj;
}

//! Implementation of get cell, retreive the char value of a cell
//! @param x: an integer value of horizontal index of the map's grid
//! @param y: an integer value of vertical index of the map's grid
//! @return : The value of the cell in question
char Map::getCell(int x, int y)
{

	return map[x][y];
}

//! Implementation occupation of a cell, check if a cell is occupied
//! @param x: an integer value of horizontal index of the map's grid
//! @param y: an integer value of vertical index of the map's grid
//! @return : a boolean true if the cell is occupeid false otherwise
bool Map::isOccupied(int x, int y)
{
	if (map[x][y] != BLANK_TILE){
		return true;
	}
	return false;
}
//! Implementation check if a character can walk
//! @param x: an integer value of horizontal index of the map's grid
//! @param y: an integer value of vertical index of the map's grid
//! @return : a boolean true if the cell can be walked on, false otherise
bool Map::canWalk(int x, int y)
{
	if (map[x][y] != WALL_TILE){
		return true;
	}
	return false;
}

//! Implementation Cell finder, returns true is a cell is found, false otherse
//! @param &x: the X position of the cell on the map's grid
//! @param &y: the Y position of the cell on the map's grid
//! @param find: The tile to search for
//! @return : a boolean true if the cell is found somewhere in the map false otherwise
bool Map::findTile(char find, int &x, int& y)
{
	for (x = 0; x < MAP_LENGTH; x++)
	for (y = 0; y < MAP_WIDTH; y++)
	if (map[x][y] == find)
		return true;
	return false;
}

//! Implementation Map saver, saves the map to a file
//! @param fname: the name of the file to save to
//! @return : wheather or not the save succeeded
bool Map::saveMap(string fname)
{
	ofstream output(fname);
	for (int i = 0; i < MAP_LENGTH; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			output << getCell(i, j);
		}
		output << endl;
	}
	return output.good();
}

//! Implementation map loader, loads the map from a file
//! @param fname: the name of the file to load from
void Map::loadMap(string fname)
{
	
	ifstream input(fname);
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			char c = input.get();
			fillCell(i, j, c);
		}
		string str;
		getline(input, str);
	}



	
}
//! Implementation print function, prints the map
void Map::print(){
	for (int i = 0; i < MAP_MAXLENGTH; i++)
	{
		for (int j = 0; j < MAP_MAXWIDTH; j++)
		{
			cout << map[i][j];
		}
		cout << endl;
	}
}

//! Implementation map copyier, copies maps given another map
//! @param m: the map to copy
void Map::copyMap(Map m){
	
	
	for (int i = 0; i < MAP_MAXLENGTH; i++)
	{
		for (int j = 0; j < MAP_MAXWIDTH; j++)
		{
			map[i][j] = m.getCell(i, j);
		}
	}
}