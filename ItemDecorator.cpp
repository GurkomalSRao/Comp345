#include "ItemDecorator.h"


ItemDecorator::~ItemDecorator(){

}

void ItemDecorator::display() //displays the view of the character interface
{
	//c->attackBonus();
	cout << "Class: " << c->getClass() << " Level: " << c->getLevel() << " HP: " << c->getHitPoints() << " AC: " << armor() << " Bonus Atk: ";
	cout << c->getBonusAttacks() << " ";
	cout << " BD " << damageBonus() << endl;
	cout << "St: " << getAbilityScore(0) << " Dx: " << getAbilityScore(1) << " Co: " << getAbilityScore(2)
		<< " In: " << getAbilityScore(3) << " Wi: " << getAbilityScore(4) << " Ch: " << getAbilityScore(5) << endl << endl;


	/*cout << "Class: " << c->getClass() << " Lvl: " << c->getLevel() << " HP: " << c->getHitPoints() << " AC: " << armor() << " BA: " << attackBonus() << " BD " << damageBonus() << endl;
	cout << "St: " << getAbilityScore(0) << " Dx: " << getAbilityScore(1) << " Co: " << getAbilityScore(2)
		<< " In: " << getAbilityScore(3) << " Wi: " << getAbilityScore(4) << " Ch: " << getAbilityScore(5) << endl << endl;
		*/
}