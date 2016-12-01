//! @file 
//! @brief Header file for the Dice class  
//!
#pragma once
#include <stdlib.h> 
#include <time.h>
#include <random>
#include <regex>
#include <iostream>
#include <string>
#include "Subject.h"

#include <stdio.h>
#include <iostream>
using namespace std;

//! class that implements the rolling of Dice 
class Dice: public Subject
{
public:
	int roll(int numberOfTimes, int diceType);
};

