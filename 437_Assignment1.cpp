#include <iostream>
#include "components.h"
#include "functions.h"
#include "FSM.h"
#include <time.h>

// • make FSMPort and SystemPort inherit from the same abstract class Port
// • make Condition and Action two abstract classes from which the actual conditions and actions inherit
//   and put a reference to the variables object as a data member of both of these
// • shift everything to pointers

Variables V;				//global

int main()
{
	V.timer = 0;
	V.yellowLed = 0;
	V.greenLed = 9;

	COND_DECLARE(warmWashInProgress, (V->timer < 6));				//slight inconvenience: pointer syntax should be used here
	warmWashInProgress WWIP(&V);  										     //instantiation
	COND_DECLARE(warmWashIsOver,(V->timer >= 6));
	warmWashIsOver WWIO(&V);

	COND_DECLARE(coldWashInProgress,(V->timer < 8));
	coldWashInProgress CWIP(&V);
	COND_DECLARE(coldWashIsOver,(V->timer >=8));
	coldWashIsOver CWIO(&V);

	COND_DECLARE(dryingInProgress,(V->timer < 12));
	dryingInProgress DIP(&V);
	COND_DECLARE(dryingIsOver,(V->timer >= 12));
	dryingIsOver DIO(&V);

	COND_DECLARE(timerIsReset,(V->timer == 0));
	timerIsReset TIR(&V);

	COND_DECLARE(trueCondition, true);
	trueCondition TC(&V);


	State off("off");				//name states same as member variable name
	State idle("idle");
	State warmWash("warmWash");
	State coldWash("coldWash");
	State drying("drying");


	Port powerButton(1);
	Port warmWashButton(2);
	Port coldWashButton(3);
	Port clockSignal(4);

	powerButton.enable();					//select ports to be enabled before declaring transitions
	coldWashButton.enable();
	warmWashButton.disable();
	clockSignal.enable();

	//Transition(State, State, Port, Condition, Action)

	Transition turnOn(off, idle, powerButton, &TC, initialize);

	Transition selectWarmWash(idle, warmWash, warmWashButton, &TIR, empty);
	Transition continueWarmWash(warmWash, warmWash, clockSignal, &WWIP, incrementTimer);

	Transition selectColdWash(idle, coldWash, coldWashButton, &TIR, empty);
	Transition continueColdWash(coldWash, coldWash, clockSignal, &CWIP, incrementTimer);

	Transition warmWashToDrying(warmWash, drying, clockSignal, &WWIO, resetTimer);
	Transition coldWashToDrying(coldWash, drying, clockSignal, &CWIO, resetTimer);

	Transition continueDrying(drying, drying, clockSignal, &DIP, incrementTimer);
	Transition doneDrying(drying, idle, clockSignal, &DIO, resetTimer);

	Transition shutDown(idle, off, powerButton, &TC, powerOff);


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

	washingMachine.run(20);

	std::cout<<V.timer<<"\n";
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
