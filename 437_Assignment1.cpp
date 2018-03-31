#include <iostream>
#include "components.h"
#include "functions.h"
#include "FSM.h"
#include <time.h>

//README:	• conditions are declared using the COND_DECLARE macro, which takes the name of the variables instance, the name of the
//				  condition, and the expression over variables.
//				• FSM functions are declared in a file called functions.h along with FSM variables, and system functions are declared
//					in systemfunctions.h along with system variables.
//        • FSM variables should be declared inside a struct called Variables, instantiated in functions.h with the keyword extern.
//          System variables should be declared inside a struct called SystemVariables, instantiated in systemfunctions.h with the
//          keyword extern.

Variables V;				//global

int main()
{
	V.timer = 0;
	V.yellowLed = 0;
	V.greenLed = 9;

	COND_DECLARE(V, warmWashInProgress, (V->timer < 6));	   	//declaration
	warmWashInProgress WWIP(&V);  										        //instantiation
	COND_DECLARE(V, warmWashIsOver,(V->timer >= 6));					//slight inconvenience: pointer syntax should be used here
	warmWashIsOver WWIO(&V);

	COND_DECLARE(V, coldWashInProgress,(V->timer < 8));
	coldWashInProgress CWIP(&V);
	COND_DECLARE(V, coldWashIsOver,(V->timer >=8));
	coldWashIsOver CWIO(&V);

	COND_DECLARE(V, dryingInProgress,(V->timer < 12));
	dryingInProgress DIP(&V);
	COND_DECLARE(V, dryingIsOver,(V->timer >= 12));
	dryingIsOver DIO(&V);

	COND_DECLARE(V, timerIsReset,(V->timer == 0));
	timerIsReset TIR(&V);

	COND_DECLARE(V, trueCondition, true);
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

	//interaction has ports, condition and action
	//for interaction to be enabled, ports must be enabled, condition must be true.
	//for a port to be enabled, its FSM must be at a state with a transition T that has port P
	//and the condition of the transition must be true
