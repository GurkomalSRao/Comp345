#include "Physics.h"
#include "iostream"

using namespace std;

Physics::Physics()
{
}


Physics::~Physics()
{
}

void Physics::moveCharacter(){
	char ch;
	cout << "Enter key to move the character ( @ is the character symbol )." << endl;
	cout << "W - Move Up" << endl;
	cout << "S - Move Down" << endl;
	cout << "A - Move Left" << endl;
	cout << "D - Move Right" << endl;
	cout << "X - Exit Program" << endl;
	while(true){
		

		cin >> ch;
		
		switch (toupper(ch)){
		case 'W':
			cout << "move up" << endl;
			break;
		case 'S':
			cout << "move down" << endl;
			break;
		case 'A':
			cout << "move left" << endl;
			break;
		case 'D':
			cout << "move right" << endl;
			break;
		case 'X':
			cout << "Game will now exit" << endl;
			system("pause");
			exit(0);
		default:
			cout << "Invalid input, try Again" << endl;

		}
		system("pause");
		system("cls");
		cout << "Enter key to move the character ( @ is the character symbol )." << endl;
		cout << "W - Move Up" << endl;
		cout << "S - Move Down" << endl;
		cout << "A - Move Left" << endl;
		cout << "D - Move Right" << endl;
		cout << "X - Exit Program" << endl;
	}
}