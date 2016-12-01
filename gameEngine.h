#pragma once
#include "Campaign.h"
#include "CampaignEditor.h"

#include "characterObserver.h"
#include "Enhancement.h"
#include "Item.h"
#include "ItemContainer.h"
#include "Map.h"
#include "MapEditor.h"
#include "MapObserver.h"
#include "ConcreteMap.h"
#include "Fighter.h"
#include "BullyFighterBuilder.h"
#include "CharacterBuilder.h"
#include "NimbleFighterBuilder.h"
#include "TankFighterBuilder.h"
#include "Character.h"
#include "DiceObserver.h"
#include "SpriteObserver.h"
#include "SpriteStrategyObserver.h"
//#include "SpriteStrategy.h"
#include "Subject.h"



class gameEngine: public Subject
{
public:
	gameEngine();
	~gameEngine();
	void run(void(*log)(),bool logs[]);
	void startMenu(void(*log)(), bool logs[4]);
	void moveCharacter(void(*log)(), bool logs[4]);
	void playGame(void(*log)(), bool logs[4]);
	void saveCharacter(Character*);
	void loadCharacter(Character*);
	bool loadMap(Map* &m);
	void spawnCharacter();
	void endMap();
	void createItem(vector<Item*>&, bool[]);
	void printMainMenu();
	void printCreateItemMenu();
	void printEnchantmentSelection();
	void printEnchantmentBonusSelection();
	void printEquipmentInterface();
	void printInformation();
	void equipItemInterface(bool[]);
	void printFighterSelect();
	void saveCharacter();
	void loadCharacter();
	Campaign* loadCampaign(string);
	bool loadCampaign(Campaign* &c);

	Campaign* myCampaign;
	AbstractCharacter* myCharacter;
	ConcreteMap *myMap;
	MapObserver* observableMap;
	CharacterObserver* observableCharacters;
	DiceObserver* observableDice;
	SpriteObserver* observableAvatar;
	vector<SpriteObserver*>* observableMonsters;
	SpriteStrategyObserver* observableAvatarStrategy;
	vector<SpriteStrategyObserver*>* observableMonstersStrategy;
	vector<Item*> items;
	Dice* dice;


	
	
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

