#include "Campaign.h"
#include "CampaignEditor.h"
#include "map.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//COMP 345 Assignment 2
//Created by: Justin Velicogna
//Student ID: 40005294

//! Runs the editor
void CampaignEditor::runEditor(){
	Campaign* c = new Campaign();
	c->num = 0;


	string input;

	do{//command loop
		if (c->num == 0)
		{
			cout << "No maps exist in campaign";
		}
		for (int i = 0; i < c->num; i++)
		{
			cout << i + 1 << ". " << c->maps[i] << endl;
		}
		cout << endl << endl << endl;

		cout << "type add to add a map" << endl;
		cout << "type swap to change the positions of two maps" << endl;
		cout << "type remove to remove a map" << endl;
		cout << "type save to save the campaign" << endl;
		cout << "type load to load a campaign" << endl;
		cout << "type q or quit to exit campaign editor mode" << endl << endl << endl;

		
		cin >> input;

		if (input == "add")
		{
			
			string s;
			if (loadMap(s))
			{
				c->maps[c->num++] = s;//do not validate that map is already added, duplicates are allowed in a campaign
			}
		}else
		if (input == "remove")
		{
			cout << "Choose a map number to remove";
			cin >> input;
			int rem = stoi(input);

			for (int i = rem - 1; i < c->num; i--)
			{
				c->maps[i] = c->maps[i + 1];
			}
			c->num--;
		}else
		if (input == "swap")
		{
			cout << "Choose the index of first map to swap: ";
			cin >> input;
			int sa = stoi(input);

			cout << "Choose the index of second map to swap: ";
			cin >> input;
			int sb = stoi(input);

			swap(c->maps[sa - 1], c->maps[sb - 1]);

		}else
		if (input == "save")
		{
			
			saveCampaign(c);
		}else
		if (input == "load")
		{
			Campaign* ca;
			if (loadCampaign(ca))
			{
				delete c;
				c = ca;
			}
		}
		


		system("cls");
	} while (input!="q" && input != "quit");



}


//! Implementation Loader, gets filename of map and loads it to campaign (and verifies map validity) 
//! @param s&: the name of the map
//! @return : wheather or not the load succeeded
bool CampaignEditor::loadMap(string &s)
{
	
	cout << "Enter file name:(q to escape) ";
	cout << endl;
	string soap;
	cin >> soap;
	if (soap == "q")
		return false;


	while (!ifstream(soap))
	{

		cout << "File does not exist, try again (press q to escape) ";
		cin >> soap;
		if (soap == "q")
			return false;
	}
	s = soap;
	
	Map m;
	m.loadMap(s);

	if (m.validatePath() == false)
	{
		cout << "Map has no path from start to finish (and was not added)";
		return false;

	}
	return true;
}

//! Implementation Saver, saves campaign to disc (and gets filename)
//! @param c: the campaign to save
//! @return : wheather or not the save succeeded
bool CampaignEditor::saveCampaign(Campaign* c){


	cout << "Enter file name:(q to escape) ";
	cout << endl;
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
	return saveCampaign(c,soap);
}

//! Implementation Saver, saves campaign to disc
//! @param c: the campaign to save
//! @param fname: The name of file to save to
//! @return : wheather or not the save succeeded
bool CampaignEditor::saveCampaign(Campaign* c, string fname){

	ofstream output(fname);
	for (int i = 0; i < c->num; i++)
	{
		output << c->maps[i] << endl;
	}
	return output.good();

}

//! Implementation Loader, Loads campaign from disc (asking for filename)
//! @param c: the campaign to load
//! @return : wheather or not the load succeeded
bool CampaignEditor::loadCampaign(Campaign* &c)
{

	cout << "Enter file name:(q to escape) ";
	cout << endl;
	string soap;
	cin >> soap;
	if (soap == "q")
		return false;
	while (!ifstream(soap))
	{

		cout << "File does not exist, try again (press q to escape) ";
		cin >> soap;
		if (soap == "q")
			return false;
	}
	c = loadCampaign(soap);
	return true;
}

//! Implementation Loader, Loads campaign from disc (asking for filename)  (validates maps and excludes unvalidated maps)
//! @param fname: the name of the file to load
//! @return : the campaign which was loaded
Campaign* CampaignEditor::loadCampaign( string fname){
	Campaign* c = new Campaign();

	ifstream input(fname);
	bool badmaps = false;

	for (int i = 0; !input.eof(); i++)
	{
		string s;
		getline(input, s);
		if (!s.empty())
		{
			Map* m = new Map();
			m->loadMap(s);
			if (!m->validatePath())
			{
				badmaps = true;
			}
			else
			{
				c->maps[c->num] = s;
				c->num++;
			}

			
		}
		
	}
	if (badmaps)
	{
		cout << "One or more maps are invalid, excluding invalid maps..." << endl;
		system("pause");
	}

	return c;

}