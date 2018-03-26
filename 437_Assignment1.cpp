#include <iostream>
#include "components.h"
#include "functions.h"
#include "FSM.h"
#include <time.h>


int main()
{
	Variables * V = new Variables;					//declare variables inside struct V
	V->timer = 10;
	V->yellowLed = 1;
	V->greenLed = 0;

	bool WWIP, WWIO, CWIP, CWIO, DIP, DIO, TIR, EC;			//declare conditions
	WWIP = V->timer < 10;
	WWIO = V->timer >= 10;
	CWIP = V->timer < 20;
	CWIO = V->timer >= 20;
	DIP = V->timer < 60;
	DIO = V->timer >= 60;
	TIR = V->timer == 0;
	EC = true;

	// std::cout<<&WWIP<<"\n";
	// std::cout<<&WWIO<<"\n";
	// std::cout<<&CWIP<<"\n";
	// std::cout<<&CWIO<<"\n";
	// std::cout<<&DIP<<"\n";
	// std::cout<<&DIO<<"\n";
	// std::cout<<&TIR<<"\n";
	// std::cout<<&EC<<"\n";


	State off("off");				//name states same as member variable name
	State idle("idle");
	State warmWash("warmWash");
	State coldWash("coldWash");
	State drying("drying");


	Port powerButton;
	Port warmWashButton;
	Port coldWashButton;
	Port clockSignal;

	powerButton.enable();					//select ports to be enabled before declaring transitions
	coldWashButton.disable();
	warmWashButton.enable();
	clockSignal.enable();


	Condition warmWashInProgress(&WWIP);			//takes in boolean expression as argument
	Condition warmWashIsOver(&WWIO);

	Condition coldWashInProgress(&CWIP);
	Condition coldWashIsOver(&CWIO);

	Condition dryingInProgress(&DIP);
	Condition dryingIsOver(&DIO);

	Condition timerIsReset(&TIR);
	Condition emptyCondition(&EC);						//always true

	//Action takes in user-implemented function and variable struct
	Action <Variables> incrementTimerAction(incrementTimer, V);		//and turn on yellowLed, which means "in progress"
	Action <Variables> resetTimerAction(resetTimer, V);
	Action <Variables> initializeAction(initialize, V);				//reset timer and turn on greenLed, which means "ready to wash"
	Action <Variables> powerOffAction(powerOff, V);					//turn off all LEDs
	Action <Variables> emptyAction(empty, V);						//do nothing


	//Transition(State, State, Port, Condition, Action)

	Transition turnOn(off, idle, powerButton, &emptyCondition, initializeAction);

	Transition selectWarmWash(idle, warmWash, warmWashButton, &timerIsReset, emptyAction);
	Transition continueWarmWash(warmWash, warmWash, clockSignal, &warmWashInProgress, incrementTimerAction);

	Transition selectColdWash(idle, coldWash, coldWashButton, &timerIsReset, emptyAction);
	Transition continueColdWash(coldWash, coldWash, clockSignal, &coldWashInProgress, incrementTimerAction);

	Transition warmWashToDrying(warmWash, drying, clockSignal, &warmWashIsOver, resetTimerAction);
	Transition coldWashToDrying(coldWash, drying, clockSignal, &coldWashIsOver, resetTimerAction);

	Transition continueDrying(drying, drying, clockSignal, &dryingInProgress, incrementTimerAction);
	Transition doneDrying(drying, idle, clockSignal, &dryingIsOver, resetTimerAction);

	Transition shutDown(idle, off, powerButton, &emptyCondition, powerOffAction);


	States Q;
	Q.push_back(off);
	Q.push_back(idle);
	Q.push_back(warmWash);
	Q.push_back(coldWash);
	Q.push_back(drying);

	Transitions T;
	T.push_back(turnOn);

	T.push_back(selectWarmWash);
	T.push_back(continueWarmWash);

	T.push_back(selectColdWash);
	T.push_back(continueColdWash);

	T.push_back(warmWashToDrying);
	T.push_back(coldWashToDrying);

	T.push_back(continueDrying);
	T.push_back(doneDrying);

	T.push_back(shutDown);


	FSM washingMachine(Q, off, T);

	washingMachine.run(1);

	std::cout<<V->timer<<"\n";
}

	// powerButton.enable();

	// Transition turnOn(off, idle, powerButton, emptyCondition, initializeAction);

	// std::cout<<powerButton.isEnabled<<"\n";
	// std::cout<<emptyCondition.checkCondition()<<"\n";
	// std::cout<<off.getName()<<"\n";
	// std::cout<<idle.getName()<<"\n";

	// std::cout<<turnOn.isValid(off)<<"\n";



	//interaction has ports, condition and action
	//for interaction to be enabled, ports must be enabled, condition must be true.
	//for a port to be enabled, its FSM must be at a state with a transition T that has port P
	//and the condition of the transition must be true
