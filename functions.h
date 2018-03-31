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

// void incrementTimer(Variables & vars)
// {
// 	vars.timer ++;
// 	std::cout<<"timer incremented: "<<vars.timer<<"\n";
// }
//
// void resetTimer(Variables &vars)
// {
// 	std::cout<<"timer before reset: "<<vars.timer<<"\n";
// 	vars.timer = 0;
// 	std::cout<<"timer reset: "<<vars.timer<<"\n";
// }
//
// void initialize(Variables &vars)
// {
// 	//std::cout<<vars.timer<<" variables not initialized \n";
// 	vars.timer = 0;
// 	vars.greenLed = 1;
// 	std::cout<<"variables initialized: "<<vars.timer<<"\n";
// }
//
// void powerOff(Variables &vars)
// {
// 	vars.yellowLed = 0;
// 	vars.greenLed = 0;
// 	vars.timer = 0;
// 	std::cout<<"power off \n";
// }
//
// void empty(Variables &vars) {}

#endif
