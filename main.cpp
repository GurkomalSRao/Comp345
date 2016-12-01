#include "gameEngine.h"
#include "GameObserver.h"


static bool notificationstoggle[4] {true};



static void toggleLogger(int index){

	if (notificationstoggle[index] == false)
		notificationstoggle[index] = true;
	else
		notificationstoggle[index] = false;
}

static void displayLogToggle(){
	int choice;
	cout << "GAME LOGGER TOGGLING" << endl;
	cout << " ------------------------------------------------------- " << endl;
	cout << "| 0 - Game Controller : " << notificationstoggle[0] << "    |" << endl;
	cout << "| 1 - Map Records : " << notificationstoggle[1] << "        |" << endl;
	cout << "| 2 - Combat Controller : " << notificationstoggle[2] << "  |" << endl;
	cout << "| 3 - Dice Controller : " << notificationstoggle[3] << "   | " << endl;
	cout << "| 4 - Return To Game                                    |" << endl;
	cout << " ------------------------------------------------------- " << endl;
	while (true){
		cout << "Choice: ";
		cin >> choice;
		if (choice > 0 && choice < 4){
			toggleLogger(choice);

		}
		else if (choice == 4)
			return;
		else
			cout << "Invalid Choice try again" << endl;
	}
}

int main(){
	gameEngine newGame;
	GameObserver* observeGame = new GameObserver(&newGame);
	newGame.run(&displayLogToggle, notificationstoggle);

	return 0;
}

