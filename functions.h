#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>

struct Variables			//contains all variables of FSM
{
	int timer;			 	//variable 1
	bool yellowLed;		 	//variable 2
	bool greenLed;		 	//variable 3
};

template <class T> void incrementTimer(T * vars)
{
	vars->timer ++;
	std::cout<<"timer incremented: "<<vars->timer<<"\n";
}

template <class T> void resetTimer(T * vars)
{
	std::cout<<"timer before reset: "<<vars->timer<<"\n";
	vars->timer = 0;
	std::cout<<"timer reset: "<<vars->timer<<"\n";
}

template <class T> void initialize(T * vars)
{
	//std::cout<<vars.timer<<" variables not initialized \n";
	vars->timer = 0;
	vars->greenLed = 1;
	std::cout<<"variables initialized: "<<vars->timer<<"\n";
}

template <class T> void powerOff(T * vars)
{
	vars->yellowLed = 0;
	vars->greenLed = 0;
	vars->timer = 0;
	std::cout<<"power off \n";
}

template <class T> void empty(T * vars) {}

#endif
