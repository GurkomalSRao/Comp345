#include "gameEngine.h"
#include "Fighter.h"
#include "AbstractCharacter.h"
#include "BullyFighterBuilder.h"
#include "CharacterBuilder.h"
#include "NimbleFighterBuilder.h"
#include "TankFighterBuilder.h"
#include "Weapon.h""
#include "Armor.h"
#include "Ring.h"
#include "Helmet.h"
#include "Belt.h"
#include "Boots.h"
#include "Shield.h"
#include <iostream>
#include <fstream>
using namespace std;

gameEngine::gameEngine()
{
	
	//myCharacter = new Character();
}

gameEngine::~gameEngine()
{
	delete myMap;
	delete observableMap;
	delete myCharacter;
}

void gameEngine::run(void(*log)(),bool logs[]){
	NotifyGame("Game Start.",logs);
	startMenu(log,logs);
}

void gameEngine::startMenu(void(*log)(), bool logs[]){//TODO:  improve menu loop
	
	char input;
	string mapName = "";
	string fileName;
	//myCharacter = new Character();
	Map* m = new Map();
	Campaign* c = new Campaign();
	dice = new Dice();
	observableDice = new DiceObserver(dice);
	
	while (true){
		Item* it;
		printMainMenu();
		cin >> input;
		switch (toupper(input)){
		case 'C':
			myCharacter = new Character();
			loadCharacter();
			NotifyGame("Character Loaded",logs);
			//cout << "here";
			
			myCharacter->setDice(dice);
			characterLoaded = true;
			observableCharacters = new CharacterObserver(myCharacter);
			break;
		case 'I':
			createItem(items, logs);

			break;
		case 'L':
			it = new Item();
			it->loadItem();
			items.push_back(it);
			itemsLoaded = true;
			system("cls");
			break;
		case 'E':
			MapEditor e;
			e.runEditor();
			system("cls");
			break;
		case 'M':
			if (loadCampaign(myCampaign))
			{
				mapLoaded = true;
				NotifyGame("Campaign Loaded.", logs);
			}
			break;
		case 'T':
			log();
			break;
		case 'P':
			if (mapLoaded)
			{
				while (!characterLoaded)
				{ 
					
					
					Fighter fighter;
					CharacterBuilder* FighterBuilder;
					int charSelect;
					printFighterSelect();
					cin >> charSelect;
					switch (charSelect){
					case 1:
						
						FighterBuilder = new BullyFighterBuilder();
						fighter.setCharacterBuilder(FighterBuilder);
						fighter.constructCharacter(dice);

						myCharacter = fighter.getCharacter();
						observableCharacters = new CharacterObserver(myCharacter);
						characterLoaded = true;
						break;
					case 2:
						FighterBuilder = new NimbleFighterBuilder();
						fighter.setCharacterBuilder(FighterBuilder);
						fighter.constructCharacter(dice);

						myCharacter = fighter.getCharacter();
						observableCharacters = new CharacterObserver(myCharacter);
						characterLoaded = true;
						break;
					case 3:
						FighterBuilder = new TankFighterBuilder();
						fighter.setCharacterBuilder(FighterBuilder);
						fighter.constructCharacter(dice);

						myCharacter = fighter.getCharacter();
						observableCharacters = new CharacterObserver(myCharacter);
						characterLoaded = true;
						break;
					default:
						cout << "Incorrect Choice Try Again" << endl;
					}
					NotifyGame("New Fighter Created", logs);
				}

				
				system("cls");
				myCharacter->setCharName("You");
				for (int omdex = 0; omdex < myCampaign->num; omdex++)
				{
					Map* mopmap;
					mopmap = new Map();
					mopmap->loadMap(myCampaign->maps[omdex]);
					myMap = new ConcreteMap(mopmap, myCharacter);
					observableMap = new MapObserver(myMap);
					for (int i = 0; i < items.size(); i++)
						myMap->loadTreasure(items[i]);
					myMap->initMap();
					observableAvatar = new SpriteObserver(myMap->getAvatar());
					observableMonsters = new vector<SpriteObserver*>();
					for (int index = 0; index < myMap->getMonsters()->size(); index++)
					{
						observableMonsters->push_back(new SpriteObserver(myMap->getMonsters()->at(index)));
					}
					observableAvatarStrategy = new SpriteStrategyObserver(myMap->getAvatar()->getStrategy());
					observableMonstersStrategy = new vector<SpriteStrategyObserver*>();
					for (int index = 0; index < myMap->getMonsters()->size(); index++)
					{
						observableMonstersStrategy->push_back(new SpriteStrategyObserver(myMap->getMonsters()->at(index)->getStrategy()));
					}

					NotifyGame("Map" + to_string(omdex) +" of Campaign Loaded.", logs);
					playGame(log, logs);
				}
				NotifyGame("Campaign Completed.", logs);
				saveCharacter();
				NotifyGame("Character Saved", logs);
			}
			else
			{
				cout << "Error: no map loaded" << endl;
			}
			break;
		case 'X':
			NotifyGame("Exit Game", logs);
			cout << "Game will now exit" << endl;
			exit(0);
		default:
			cout << "Invalid input, try Again" << endl;
		}
		system("cls");
	}
}



void gameEngine::moveCharacter(void(*log)(), bool logs[]){
	
	myMap->getAvatar()->executeStrategy(myMap->getAvatar(), myMap->getMonsters(), myMap, log,logs);
	for (int i = 0; i < myMap->getMonsters()->size(); i++)
	{
		myMap->getMonsters()->at(i)->executeStrategy(myMap->getAvatar(), myMap->getMonsters(), myMap, log,logs);
	}
	/*char ch;
	int coord_x, coord_y = 0;
	cout << "Use WASD keys to move character, E to equip Items from inventory, C to view Information, X to exit program ( " << AVATAR_TILE << " is the character symbol )." << endl;
	do{
		//myMap->getAvatar().executeStrategy();
		cin >> ch;
		ch = toupper(ch);
		myMap->findTile(AVATAR_TILE, coord_x, coord_y);
		switch (ch){
			case 'W':
				myMap->moveAvatar(up);
				break;
			case 'S':
				myMap->moveAvatar(down);
				break;
			case 'A':
				myMap->moveAvatar(Direction::left);
				break;
			case 'E':
				equipItemInterface();
				break;
			case 'D':
				myMap->moveAvatar(Direction::right);
				break;
			case 'C':
				system("cls");
				printInformation();
			case 'X':
				cout << "Game will now exit" << endl;
				system("pause");
				exit(0);
			default:
				cout << "Invalid input, try Again" << endl;
		}
	}while (ch != 'W' && ch != 'A' &&ch != 'S' &&ch != 'D' &&ch != 'X' &&ch != 'E');
	*/
}

void gameEngine::playGame(void(*log)(), bool logs[]){
	
	while (true){
		myMap->getAvatar()->c->display();
		myMap->NotifyMap();
		printEquipmentInterface();
		if (myMap->getAvatarTile() == MONSTER_TILE)
		{
			cout << "You found a monster! Monster stats: " << endl;
			//NotifyGame("Found Monster", logs);
			myMap->getMonster(myMap->getAvatar()->pos)->display();
		}
		if (myMap->getAvatarTile() == TREASURE_TILE)
		{
			NotifyGame("Found Treasure", logs);
			cout << "You got a treasure! Please check your inventory." << endl;
			//Place treasure in inventory
			myCharacter->addItemToInventory(myMap->getTreasure(myMap->getAvatar()->pos));
			myMap->removeTreasure(myMap->getAvatar()->pos);
		}
		if (myMap->getAvatarTile() == END_TILE){
			//end the game
			NotifyGame("Map Completed", logs);
			endMap();
			NotifyGame("Character Leveled Up", logs);
			return;
		}
		moveCharacter(log,logs);

	}
}

Campaign* gameEngine::loadCampaign(string fname){
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
bool gameEngine::loadCampaign(Campaign* &c)
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

//bool gameEngine::loadMap(Map* &m)
//{
//	cout << "Enter file name:(q to escape) ";
//	cout << endl;
//	string soap;
//	cin >> soap;
//	if (soap == "q")
//		return false;
//
//	while (!ifstream(soap))
//	{
//		cout << "File does not exist, try again (press q to escape) ";
//		cin >> soap;
//		if (soap == "q")
//			return false;
//	}
//
//	m->loadMap(soap);
//
//	if (m->validatePath() == false)
//	{
//		cout << "Map is invalid";
//		return false;
//	}
//	return true;
//}

void gameEngine::endMap(){
	int levelUp = myCharacter->getLevel() + 1;

	myCharacter->setLevel(levelUp);
	
	//if (myCampaign)
	//saveCharacter();
	system("cls");
	//exit(0);
}

void gameEngine::createItem(vector<Item*> &items, bool logs[]){
	char type;
	string itemName;
	Enhancement tempEnhanceType;
	string itemType;
	Item* tempItem = new Item();
	int bonus;
	do{
		system("cls");
		printCreateItemMenu();
		cin >> type;
		switch (toupper(type)){
		case 'H':
			itemName = "Helmet";
			break;
		case 'A':
			itemName = "Armor";
			break;
		case 'S':
			itemName = "Shield";
			break;
		case 'R':
			itemName = "Ring";
			break;
		case 'L':
			itemName = "Belt";
			break;
		case 'B':
			itemName = "Boots";
			break;
		case 'W':
			itemName = "Weapon";
			break;
		case 'X':
			cout << "Game will now go back to main menu" << endl;
			system("pause");
			return;
		default:
			cout << "Invalid input, try Again" << endl;
		}
		system("cls");
		printEnchantmentSelection();
		cout << "Select the Enchantment for " << itemName << " :";

		cin >> type;
		switch (toupper(type)){
		case 'I':
			tempEnhanceType.setType("Intelligence");
			break;
		case 'A':
			tempEnhanceType.setType("Armor class");
			break;
		case 'W':
			tempEnhanceType.setType("Wisdom");
			break;
		case 'S':
			tempEnhanceType.setType("Strength");
			break;
		case 'C':
			tempEnhanceType.setType("Constitution");
			break;
		case 'H':
			tempEnhanceType.setType("Charisma");
			break;
		case 'D':
			tempEnhanceType.setType("Dexterity");
			break;
		case 'F':
			tempEnhanceType.setType("Attack bonus");
			break;
		case 'Q':
			tempEnhanceType.setType("Damage bonus");
			break;
		default:
			cout << "Invalid input, try Again" << endl;
		}
		system("cls");
		printEnchantmentBonusSelection();
		cout << "Select the Enchantment Bonus for: " << itemType;
		cin >> bonus;
		while (bonus < 1 && bonus > 6){
			cout << "invalid input, Try another value: ";
			cin >> bonus;
		}
		tempEnhanceType.setBonus(bonus);
		tempItem->setType(itemName);
		tempItem->setInfluences(tempEnhanceType);

		if (!tempItem->validateItem()){
			cout << "You have selected an invalid Item and Enchantment combination, Try again" << endl;
			system("pause");
		}
	} while (!tempItem->validateItem());

	NotifyGame("New Item Created", logs);
	system("cls");
	char option;
	bool notDone = true;
	while (notDone){
		cout << "What would you like to save Item to a file or Input into game?" << endl;
		cout << "S - Save to file" << endl;
		cout << "G - Insert into game" << endl;
		cout << "Option: ";
		cin >> option;

		switch (toupper(option)){
		case 'S':
			tempItem->saveItem();
			notDone = false;
			NotifyGame("New Item Saved to File", logs);
			break;
		case 'G':
			NotifyGame("New Item Inserted to Game Treasure Chests", logs);
			items.push_back(tempItem);
			notDone = false;
			break;
		default:
			cout << "Invalid input, try again: ";
		}
	}
	
}

void gameEngine::equipItemInterface(bool logs[]){
	
	char type;
	if (myCharacter->getBackPack().getSize() > 0){
		while (true){
			system("cls");
			printEquipmentInterface();
			NotifyGame("Loaded Equipment Interface", logs);
			cout << "ITEM EQUIPMENT SCREEN" << endl;
			cout << " ------------------------------------------------------- " << endl;
			cout << "| H - Equip/Unequip Helmet                            |" << endl;
			cout << "| A - Equip/Unequip Armor                             |" << endl;
			cout << "| S - Equip/Unequip Shield                            |" << endl;
			cout << "| R - Equip/Unequip Ring                              |" << endl;
			cout << "| L - Equip/Unequip Belt                              |" << endl;
			cout << "| B - Equip/Unequip Boots                             |" << endl;
			cout << "| W - Equip/Unequip Weapon                            |" << endl;
			cout << "| X - Resume Game                                     |" << endl;
			cout << " ------------------------------------------------------- " << endl;
			cout << "Please Select Item: ";
			cin >> type;
			switch (toupper(type)){
			case 'H':
				
				if (!myCharacter->isEquiped("Helmet")){
					myCharacter = new Helmet(myCharacter, myCharacter->getBackPack().getItem("Helmet"));
					myCharacter->equipItem("Helmet");
					NotifyGame("Equiped Helmet", logs);
				}
				else{
					myCharacter->unequipItem(myCharacter->unsetItem("Helmet"));
					NotifyGame("Equip Helmet", logs);
				}
				break;
			case 'A':
				//myCharacter->equipItem(myCharacter->getBackPack().getItem("Armor"));
				if (!myCharacter->isEquiped("Armor")){
					myCharacter = new Armor(myCharacter, myCharacter->getBackPack().getItem("Armor"));
					myCharacter->equipItem("Armor");
					NotifyGame("Equiped Armor", logs);
				}
				else{
					myCharacter->unequipItem(myCharacter->unsetItem("Armor"));
					NotifyGame("Unequiped Armor", logs);
				}
				break;
			case 'S':
				//myCharacter->equipItem(myCharacter->getBackPack().getItem("Shield"));
				if (!myCharacter->isEquiped("Shield")){
					myCharacter = new Shield(myCharacter, myCharacter->getBackPack().getItem("Shield"));
					myCharacter->equipItem("Shield");
					NotifyGame("Equiped Shield", logs);
				}
				else{
					myCharacter->unequipItem(myCharacter->unsetItem("Shield"));
					NotifyGame("Unequiped Shield", logs);
				}
				break;
			case 'R':
				//myCharacter->equipItem(myCharacter->getBackPack().getItem("Ring"));
				if (!myCharacter->isEquiped("Ring")){
					myCharacter = new Ring(myCharacter, myCharacter->getBackPack().getItem("Ring"));
					myCharacter->equipItem("Ring");
					NotifyGame("Equiped Ring", logs);
				}
				else{
					myCharacter->unequipItem(myCharacter->unsetItem("Ring"));
					NotifyGame("Unequiped Ring", logs);
				}
				break;
			case 'L':
				//myCharacter->equipItem(myCharacter->getBackPack().getItem("Belt"));
				if (!myCharacter->isEquiped("Belt")){
					myCharacter = new Belt(myCharacter, myCharacter->getBackPack().getItem("Belt"));
					myCharacter->equipItem("Belt");
					NotifyGame("Equiped Belt", logs);
				}
				else{
					myCharacter->unequipItem(myCharacter->unsetItem("Belt"));
					NotifyGame("Unequiped Belt", logs);
				}
				break;
			case 'B':
				//myCharacter->equipItem(myCharacter->getBackPack().getItem("Boots"));
				if (!myCharacter->isEquiped("Boots")){
					myCharacter = new Boots(myCharacter, myCharacter->getBackPack().getItem("Boots"));
					myCharacter->equipItem("Boots");
					NotifyGame("Equiped Boots", logs);
				}
				else{
					myCharacter->unequipItem(myCharacter->unsetItem("Boots"));
					NotifyGame("Unequiped Boots", logs);
				}
				break;
			case 'W':
				//myCharacter->equipItem(myCharacter->getBackPack().getItem("Weapon"));
				if (!myCharacter->isEquiped("Weapon")){
					myCharacter = new Weapon(myCharacter, myCharacter->getBackPack().getItem("Weapon"));
					myCharacter->equipItem("Weapon");
					NotifyGame("Equiped Weapon", logs);
				}
				else{
					myCharacter->unequipItem(myCharacter->unsetItem("Weapon"));
					NotifyGame("Unequiped Weapon", logs);
				}
				break;
			case 'X':
				return;
			default:
				cout << "Invalid input, try Again" << endl;
			}
		}
	}
	else{
		cout << "No Items to swap, Resuming Game..." << endl;
		system("pause");
		return;
	}

}

//! Implementation saveCharacter, saves character as binary to a file
//! @param Character: the character to be saved
void gameEngine::saveCharacter(){
	vector<Item*> equipment;
	equipment = myCharacter->getEquipment();
	string fileName;
	cout << "Input file name for character save" << endl;
	cout << "File Name: ";
	cin >> fileName;

	ofstream output(fileName);
	output << "Character.sav" << endl;	//define type of save file
	output << myCharacter->getFighterType();
	output << myCharacter->getLevel() << endl;
	output << myCharacter->getHitPoints() << endl;
	for (int i = 0; i < 6; i++)
		output << myCharacter->getAbilityScore(i) << endl;
	//for (int i = 0; )
	//output << myCharacter->armor();
	output << equipment.size() << endl;
	for (int i = 0; i < equipment.size(); i++)
	{
		output << equipment[i]->getType() << endl;
		output << equipment[i]->getInfluences().size() << endl;

		for (int j = 0; j < equipment[i]->getInfluences().size(); j++)
		{
			output << equipment[i]->getInfluences().at(j).getType() << endl;
			output << equipment[i]->getInfluences().at(j).getBonus() << endl;
		}
	}

	if (myCharacter->getBackPack().getSize() != 0){  //save the backpack
		output << myCharacter->getBackPack().getSize() << endl;
		for (int i = 0; i < myCharacter->getBackPack().getSize(); i++)
		{
			output << myCharacter->getBackPack().getItems().at(i)->getType() << endl;
			output << myCharacter->getBackPack().getItems()[i]->getInfluences().size() << endl;
			for (int j = 0; j < myCharacter->getBackPack().getItems()[i]->getInfluences().size(); j++)
			{
				output << myCharacter->getBackPack().getItems()[i]->getInfluences().at(j).getType() << endl;
				output << myCharacter->getBackPack().getItems()[i]->getInfluences().at(j).getBonus() << endl;
			}
		}
	}
	else
		output << -1;
	output.close();
}
//! Implementation loadCharacter, load a Character from a file
//! assumption: file exists and is a Character
//! @param &item: the character to be loaded
void gameEngine::loadCharacter(){
	
	string fileName;
	string fileValidation;
	string type;
	int abilityScore;
	int hp;
	int level;
	Item* tempItem;
	Enhancement *tempEnhance;
	bool badFile = false;
	int influenceSize = 0;
	int loopValidation = 0;
	int bonus = 0;
	cout << "Load File: ";
	cin >> fileName;

//	myCharacter->setFighterType("Fighter");

	ifstream input(fileName);
	do{
		while (!input.good()){
			cout << "File does not exist, try again: ";
			cin >> fileName;
			input.open(fileName);
		}
		input >> fileValidation;
		if (fileValidation == "Character.sav")//check if it is an item save file
			badFile = true;
		else{
			input.close();
			badFile = false;
			cout << "Incorrect File Loaded, select another File: " << endl;
			cin >> fileName;
			input.open(fileName);
		}
	} while (badFile == false);		//check if loading character file type
	
	input >> type;
	myCharacter->setFighterType(type);
	input >> level;
	myCharacter->setCharacterLevel(level);

	input >> hp;
	myCharacter->setHitPoints(hp);
	for (int i = 0; i < 6; i++){
		input >> abilityScore;
		myCharacter->setAbilityScore(i, abilityScore);
	}
	//myCharacter->SetAttack();

	input >> loopValidation;
	string itemType;
	string type2;
	for (int i = 0; i < loopValidation; i++)			//save equipped items
	{
		tempItem = new Item();
		
		input >> itemType;
		//getline(input, type);
		tempItem->setType(itemType);
		input >> influenceSize;
		for (int j = 0; j < influenceSize; j++)
		{
			input >> std::skipws >> type >> type2;
			if (type2 == "class" || type2 == "bonus"){
				type = type + " " + type2;
				input >> bonus;
			}
			else{
				bonus = std::stoi(type2, nullptr, 0);
			}
			
			tempEnhance = new Enhancement(type, bonus);
			tempItem->setInfluences(*tempEnhance);
			//delete tempEnhance;
		}
		if (itemType == "Helmet"){
			myCharacter = new Helmet(myCharacter, tempItem);
		}
		else if (itemType == "Armor"){
			myCharacter = new Armor(myCharacter, tempItem);
		}
		else if (itemType == "Shield"){
			myCharacter = new Shield(myCharacter, tempItem);
		}
		else if (itemType == "Ring"){
			myCharacter = new Ring(myCharacter, tempItem);
		}
		else if (itemType == "Belt"){
			myCharacter = new Belt(myCharacter, tempItem);
		}
		else if (itemType == "Boots"){
			myCharacter = new Boots(myCharacter, tempItem);
		}
		else if (itemType == "Weapon"){
			myCharacter = new Weapon(myCharacter, tempItem);
		}
		myCharacter->getLevel();
		//delete tempItem;
	}


	input >> loopValidation;
	if (loopValidation != -1){
		string typeEnhance;
		for (int i = 0; i < loopValidation; i++)		//save inventory/backpack
		{
			input >> itemType;
			tempItem = new Item();
			tempItem->setType(itemType);
			input >> influenceSize;
			for (int j = 0; j < influenceSize; j++)
			{
				
				input >> std::skipws >> typeEnhance >> type2;

				if (type2 == "class" || type2 == "bonus"){
					typeEnhance = typeEnhance + " " + type2;
					input >> bonus;
				}
				else{
					bonus = std::stoi(type2, nullptr, 0);
				}
				
				tempEnhance = new Enhancement(typeEnhance, bonus);
				tempItem->setInfluences(*tempEnhance);
				myCharacter->addItemToInventory(tempItem);
				//delete tempEnhance;
				//delete tempItem;
			}
		}
	}
	input.close();
	
	//return myCharacter;
}


/*--------------------------------------------------------------
					PRINT FUNCTIONS
---------------------------------------------------------------*/
void gameEngine::printMainMenu(){
	char charLoad = ' ';
	char mapLoad = ' ';
	if (characterLoaded)
		charLoad = 'X';
	if (mapLoaded)
		mapLoad = 'X';
	cout << " ------------------------------------------------------- " << endl;
	cout << "| C - Load Character                                    |" << endl;
	cout << "| M - Load Campaign                                     |" << endl;
	cout << "| E - Edit/Create Map                                   |" << endl;
	cout << "| I - Create Item                                       |" << endl;
	cout << "| L - Load Item                                         |" << endl;
	cout << "| P - Play Game                                         |" << endl;
	cout << "| T - Toggle Game Logger                                |" << endl;
	cout << "| X - Exit Program                                      |" << endl;
	cout << " ------------------------------------------------------- " << endl;
	cout << "|           Character Loaded [" << charLoad << "] Map Loaded [" << mapLoad << "]         |" << endl;
	cout << " ------------------------------------------------------- " << endl;
	cout << "|                      ITEMS LOADED                     | " << endl;
	cout << " ------------------------------------------------------- " << endl;
	if (itemsLoaded){


		for (int i = 0; i < items.size(); i++){
			cout << i + 1 << " - ";
			items.at(i)->print();
		}
		cout << endl;
	}
	else
		cout << "No Items Loaded" << endl;
	cout << "Please select an option: ";
}

void gameEngine::printCreateItemMenu(){
	cout << "ITEM CREATION SCREEN" << endl;
	cout << " ------------------------------------------------------- " << endl;
	cout << "| H - Create Helmet                                     |" << endl;
	cout << "| A - Create Armor                                      |" << endl;
	cout << "| S - Create Shield                                     |" << endl;
	cout << "| R - Create Ring                                       |" << endl;
	cout << "| L - Create Belt                                       |" << endl;
	cout << "| B - Create Boots                                      |" << endl;
	cout << "| W - Create Weapon                                     |" << endl;
	cout << "| X - Exit Program                                      |" << endl;
	cout << " ------------------------------------------------------- " << endl;
	cout << "Select the Item You Wish To Create: ";
}

void gameEngine::printEnchantmentSelection(){
	cout << "ITEM CREATION SCREEN" << endl;
	cout << " ------------------------------------------------------- " << endl;
	cout << "| I - Intelligence                                      |" << endl;
	cout << "| A - Armor Class                                       |" << endl;
	cout << "| W - Wisdom                                            |" << endl;
	cout << "| S - Strength                                          |" << endl;
	cout << "| C - Constitution                                      |" << endl;
	cout << "| H - Charisma                                          |" << endl;
	cout << "| D - Dexterity                                         |" << endl;
	cout << "| F - Attack Bonus                                      |" << endl;
	cout << "| Q - Damage Bonus                                      |" << endl;
	cout << " ------------------------------------------------------- " << endl;
}

void gameEngine::printEnchantmentBonusSelection(){
	cout << "ITEM CREATION SCREEN" << endl;
	cout << " ------------------------------------------------------- " << endl;
	cout << "| 1 - Enchantment + 1                                   |" << endl;
	cout << "| 2 - Enchantment + 2                                   |" << endl;
	cout << "| 3 - Enchantment + 3                                   |" << endl;
	cout << "| 4 - Enchantment + 4                                   |" << endl;
	cout << "| 5 - Enchantment + 5                                   |" << endl;
	cout << " ------------------------------------------------------- " << endl;
}

void gameEngine::printEquipmentInterface(){
	cout << "EQUIPPED ITEMS" << endl;
	myCharacter->displayEquipedItems("Helmet");
	myCharacter->displayEquipedItems("Armor");
	myCharacter->displayEquipedItems("Shield");
	myCharacter->displayEquipedItems("Ring");
	myCharacter->displayEquipedItems("Belt");
	myCharacter->displayEquipedItems("Boots");
	myCharacter->displayEquipedItems("Weapon");
	cout << "BACKPACK" << endl;
	myCharacter->displayBackpackItems();
}

void gameEngine::printInformation()
{
	cout << "Player Information" << endl;
	myCharacter->display();
	cout << endl << "Monster Infromation" << endl;
	myMap->displayMonsterInfo();
	cout << endl << endl<< "Chest Information" << endl;
	myMap->displayChestInfo();
	system("pause");
	return;
}

void gameEngine::printFighterSelect(){
	cout << "SELECT FIGHTER TYPE" << endl;
	cout << " ------------------------------------------------------- " << endl;
	cout << "| 1 - Bully                                             |" << endl;
	cout << "| 2 - Nimble                                            |" << endl;
	cout << "| 3 - Tank                                              |" << endl;
	cout << " ------------------------------------------------------- " << endl;
}