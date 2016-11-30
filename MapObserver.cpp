//! @file 
//! @brief Implementation file for the Map Observer class  
//!
#include "MapObserver.h"
#include <iostream>
#include <random>

using namespace std;

/*MapObserver::MapObserver()
{
	_map = new ConcreteMap;
	_map->Attach(this);
}*/

MapObserver::MapObserver(ConcreteMap* m)
{
	_map = m;
	_map->Attach(this);
}

MapObserver::~MapObserver()
{
	_map->Detach(this);
}

void MapObserver::Update(){
	displayMap();
}

void MapObserver::displayMap(){

	system("cls");
	cout << endl << "----------------FULL MAP---------------- "<< endl;
	_map->printFullMap();
	
	/*for (int i = 0; i < MAP_MAXLENGTH; i++){
		for (int j = 0; j < MAP_MAXWIDTH; j++){
			cout << _map->getCell(i, j);
		}
		cout << endl;
	}*/
}