//! @file 
//! @brief Header file for the Dice class  
//!
#include <stdlib.h> 
#include <time.h>
#include <random>
#include <regex>
#include <iostream>
#include <string>
#pragma once

#include <stdio.h>
#include <iostream>
using namespace std;

//! class that implements the rolling of Dice 
class Dice
{
public:
	static int roll(int numberOfTimes, int diceType);
};

