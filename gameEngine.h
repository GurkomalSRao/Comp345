#pragma once
#include "completeHeader.h"

class gameEngine
{
public:
	gameEngine();
	~gameEngine();
	void run();
	void startMenu();
	void moveCharacter();
	void playGame();
	void saveCharacter(Character*);
	void loadCharacter(Character*);
	bool loadMap(Map* &m);
	void spawnCharacter();
	void endMap();
	void createItem(vector<Item*>&);
	void printMainMenu();
	void printCreateItemMenu();
	void printEnchantmentSelection();
	void printEnchantmentBonusSelection();
	void printEquipmentInterface();
	void printInformation();
	void equipItemInterface();
	void printFighterSelect();
	void saveCharacter();
	void loadCharacter();

	AbstractCharacter* myCharacter;
	ConcreteMap *myMap;
	MapObserver *observableMap;
	CharacterObserver *observableCharacters;
	vector<Item*> items;

	bool characterLoaded = false;
	bool mapLoaded = false;
	bool itemsLoaded = false;

	static char const START_TILE = '<';
	static char const END_TILE = '>';
	static char const BLANK_TILE = '.';
	static char const WALL_TILE = 'X';
	static char const TREASURE_TILE = '=';
	static char const AVATAR_TILE = '@';
	static char const MONSTER_TILE = '&';
};

