#include "functions.h"

void incrementTimer()
{
	V.timer ++;
	std::cout<<"timer incremented: "<<V.timer<<"\n";
}

void resetTimer()
{
	V.timer = 0;
	std::cout<<"timer reset: "<<V.timer<<"\n";
}

void initialize()
{
	V.timer = 0;
	V.greenLed = 1;
	std::cout<<"variables initialized: "<<V.timer<<"\n";
}

void powerOff()
{
	V.yellowLed = 0;
	V.greenLed = 0;
	V.timer = 0;
	std::cout<<"power off \n";
}

void empty() {}
