#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>

struct Variables			//contains all variables of FSM
{
	int timer;			 	  //variable 1
	bool yellowLed;		 	//variable 2
	bool greenLed;		 	//variable 3
};

extern Variables V;

void incrementTimer();
void resetTimer();
void initialize();
void powerOff();
void empty();

#endif
