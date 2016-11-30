//! @file 
//! @brief Implementation file for the Dice class  
//!
#include "Dice.h"

//! Implementation of the rolling dice
//! @param string : a string of the form "xdy[+z]".
//! @return an integer which is the addition of the value of all dice and return -1 when the expression dose not follow he right format 
int Dice::roll(int numberOfTimes, int diceType)
{
	// validate input and return -1 on invalid string input
	if (diceType == 6 || diceType == 8 || diceType == 10 || diceType == 12 || diceType == 20 || diceType == 100)
	{
		// compute result
		int total = 0;
		srand(time(0));
		random_device rd;
		mt19937 gen(rd());  //initializes the generater
		uniform_int_distribution<> dis(1, diceType);  //generates a range from 1 to 20

		for (size_t i = 0; i < numberOfTimes; i++)
		{
			total += dis(gen);
		}

		return total;
	}
	else
		return -1;
}