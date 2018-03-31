#ifndef FSM_H
#define FSM_H

#include "components.h"
#include <iostream>

class FSM
{
public:
	FSM(){};
	FSM(States Q, State q0, Transitions T);
	void reset(State resetState);
	void run(int n);
	void execute();
	bool findPort(int id);

private:
	States Q;
	State q0;
	Transitions T;
	State currentState;
	State nextState;
	std::vector<Transition> * validTransitions;
};

#endif
