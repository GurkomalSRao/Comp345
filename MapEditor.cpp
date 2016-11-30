#pragma once

#include <iostream>
#include <windows.h>
#include <string>
#include "Map.h"
#include "MapEditor.h"
#include <math.h>
#include <fstream>
#include "CampaignEditor.h"

using namespace std;

//COMP 345 Assignment 2
//Created by: Justin Velicogna
//Student ID: 40005294


void MapEditor::runEditor() {

	Map* m = new Map();
	


	

	HANDLE  hConsole;
	int cposx = 5;
	int cposy = 6;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	string s;
	bool end = false;
	do
	{
		for (int i = 0; i < m->MAP_LENGTH; i++)
		{
			for (int j = 0; j < m->MAP_WIDTH; j++)
			{
				if (j == cposx && i == cposy)
				{
					SetConsoleTextAttribute(hConsole, 240);//highlight position cursor is on
					cout << m->getCell(i, j);
					SetConsoleTextAttribute(hConsole, 7);
				}
				else {
					cout << m->getCell(i, j);
				}
			}
			cout << endl;
		}
		cout << endl;
		cout << "Type ? for help";
		cout << endl;

		cin >> s;
		
		for (int r = 0; r < s.length(); r++)
		{

			switch (s[r])
			{
				case '8':
					cposy--;
					cposy = max(cposy, 0);
					break;
				case '4':
					cposx--;
					cposx = max(cposx, 0);
					break;
				case '2':
					cposy++;
					cposy = min(cposy, m->MAP_WIDTH-1);
					break;
				case '6':
					cposx++;
					cposx = min(cposx, m->MAP_LENGTH-1);
					break;
				case 'x':
				case 'w':
					m->fillCell(cposy, cposx, m->WALL_TILE);
					break;
				case 'f':
				case '.':
					m->fillCell(cposy, cposx, m->BLANK_TILE);
					break;
				case 'm':
				case '&':
					m->fillCell(cposy, cposx, m->MONSTER_TILE);
					break;
				case 't':
				case '=':
					m->fillCell(cposy, cposx, m->TREASURE_TILE);
					break;
				case 'b':
				case '<':
					m->fillCell(cposy, cposx, m->START_TILE);
					break;
				case 'e':
				case '>':
					m->fillCell(cposy, cposx, m->END_TILE);
					break;
				case '?':
					printRules();
					break;
				case 'l':
					Map* nm;
					if (loadMap(nm))
					delete m;
					m = nm;
					break;
				case 's':
					saveMap(m);
					break;
				case 'c':
					system("cls");
					CampaignEditor c;
					c.runEditor();
					break;
				case 'q':
					end = true;
					break;

			}
		}
			

		system("cls");
	} while (!end);
	

}
//! Implementation Map saver, saves the map to a file
//! @param m: the map to be saved
//! @return : wheather or not the save succeeded
bool MapEditor::saveMap(Map* m){
	
	if (!m->validatePath())
	{
		cout << "Warning: Map is invalid, continuing anyways..." << endl;
	}
	cout << "Enter file name:(q to escape) ";
	string soap;
	cin >> soap;
	if (soap == "q")
		return false;
	if (ifstream(soap))
	{
		string conf;
		cout << "File already exists, continue? (y to continue, abort otherise)";
		cin >> conf;
		if (conf != "y")
			return false;
	}
	return m->saveMap(soap);
}

//! Implementation Map load, loads a map from a file
//! @param &m: the map to be loaded
//! @return : wheather or not the load succeeded
bool MapEditor::loadMap(Map* &m)
{
	
	cout << "Enter file name:(q to escape) ";
	string soap;
	cin >> soap;
	if (soap == "q")
		return false;
	while(!ifstream(soap))
	{
		
		cout << "File does not exist, try again (press q to escape) ";
		cin >> soap;
		if (soap == "q")
			return false;
	}
	m = new Map();
	m->loadMap(soap);
	if (m->validatePath() == false)
	{
		cout << "Map is invalid" << endl;
		system("pause");
	}
	return true;
}

//! Prints how to use the map editor
void MapEditor::printRules(){
	system("cls");
	cout << "How to use map editor: " << endl;
	cout << "Press ENTER after typing in a command to execute" << endl;
	cout << "Multiple commands can be typed before execution" << endl;
	cout << "Commands:" << endl;
	cout << " NUMPAD move cursor (8,4,6,2 to move up,left,right,down)" << endl;
	cout << " . place floor tile" << endl;
	cout << " x,w place wall tile" << endl;
	cout << " m place monster tile" << endl;
	cout << " t,= place treasure tile" << endl;
	cout << " b,< place start tile" << endl;
	cout << " e,> place end tile" << endl;
	cout << " l load map " << endl;
	cout << " s save map " << endl;
	cout << " c run campaign editor" << endl;
	cout << " q exit editor " << endl << endl;

	system("pause");
	


}