#pragma once
#include "AbstractCharacter.h"
#include "Item.h"
//class AbstractChra

class ItemDecorator : public AbstractCharacter
{
protected:
	AbstractCharacter *c;
	Item* i;
public:
	ItemDecorator(AbstractCharacter *c, Item* i){
		this->c = c;
		this->i = i;
	}

	~ItemDecorator();


	void setCharacterLevel(int i){
		c->setCharacterLevel(i);
	}
	int getAbilityScore(int index){

		return c->getAbilityScore(index);
	}
	int getBonusAttacks(){
		return c->getBonusAttacks();
	}
	int armor(){
		return c->armor();
	}
	bool validateNewCharacter(){
		return c->validateNewCharacter();
	}
	void hit(int i) {
		c->hit(i);
	}
	Dice* getDice(){
		return c->getDice();
	}
	int getHitPoints() {
		return c->getHitPoints();
	}
	void setHitPoints(int hp){
		c->setHitPoints(hp);
	}
	int abilityScore() {
		return c->abilityScore();
	}
	int abilityModifier(int i){
		return c->abilityModifier(i);
	}
	void modifyHP() {
		c->modifyHP();
	}
	void setLevel(int i) {
		c->setLevel(i);
	}
	int attackBonus(){
		return c->attackBonus();
	}
	int damageBonus(){
		return c->damageBonus();
	}
	string getClass(){
		return c->getClass();
	}
	void display();

	void addItemToInventory(Item* i){
		c->addItemToInventory(i);
	}
	
	int getLevel() {
		return c->getLevel();
	}
	
	bool displayEquipedItems(string s){
		return c->displayEquipedItems(s);
	}
	void displayBackpackItems(){
		c->displayBackpackItems();
	}
	/*void saveCharacter(){
		c->saveCharacter();
	}
	void loadCharacter(){
		c->loadCharacter();
	}*/
	void monsterClass(){
		c->monsterClass();
	}
	ItemContainer getBackPack(){
		return c->getBackPack();
	}
	/*int getEquipmentSize();
	void setEquipmentSize(int i){
		c->setEquipmentSize(i);
	}*/
	void setAbilityScores(string s){
		c->setAbilityScores(s);
	}

	bool equipItem(string s){
		return c->equipItem(s);
	}
	bool unequipItem(Item* i){
		return c->unequipItem(i);
	}

	Item* getItem(string s){
		return c->getItem(s);
	}
	void setAbilityScore(int index, int value){
		c->setAbilityScore(index, value);
	}
	string getFighterType(){
		return c->getFighterType();
	}
	void setFighterType(string s){
		c->setFighterType(s);
	}
	/*int getBaseBonus()
	{
		return c->getBaseBonus();
	}*/

	/* int getAttacksSize()
	{
		return c->getAttacksSize();
	}*/

	/* void SetAttack()
	{
		return c->SetAttack();
	}*/

	 int GetAttack(int attack)
	{
		return c->GetAttack(attack);
	}
	/* void setArmor()
	{
		return c->setArmor();
	}*/
	/* void setBonusDamage()
	{
		return c->setBonusDamage();
	}*/
	 /*int getBonusAtks(int i){
		return c->getBonusAtks(i);
	 }*/
	 /*void initializeBonusAttack(){
		 c->initializeBonusAttack();
	 }*/
	 void setDice(Dice* die)
	 {
		 c->setDice(die);
	 }
	 int getAccuracy(int acc)
	 {
		 return c->getAccuracy(acc);
	 }
	 int getDamage()
	 {
		 return c->getDamage();
	 }
	 void setCharName(string s)
	 {
		c->setCharName(s);
	 }
	 string getCharName()
	 {
		 return c->getCharName();
	 }

};

