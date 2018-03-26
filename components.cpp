#include "components.h"
#include <iostream>

State::State(std::string name)
{
	stateName = name;
}

std::string State::getName()
{
	return stateName;
}

Condition::Condition(bool *t)
{
	isTrue = t;
	//std::cout<<"condition constructor: "<<isTrue<<"\n";
}

bool Condition::checkCondition()
{
	//std::cout<<"condition check: "<<*isTrue<<"\n";
	return & isTrue;
}


Port::Port()
{
	isEnabled = false;
}

void Port::enable()
{
	isEnabled = true;
}

void Port::disable()
{
	isEnabled = false;
}


Transition::Transition(State qStart1, State qDest1, Port port1, Condition * condition1, Action <Variables> action1)
{
	qStart = qStart1; qDest = qDest1; port = port1; condition = condition1; action = action1;
	//std::cout<<"\t condition: "<<condition->checkCondition()<<"\n";   //condition points to the variable struct
}

bool Transition::isValid(State currentState)
{
	std::cout<<qStart.getName()<<" to "<<qDest.getName()<<"\n";
	std::cout<<"\t condition: "<<condition->checkCondition()<<"\n";
	std::cout<<"\t port: "<<port.isEnabled<<"\n";
	std::cout<<"\t states: "<<(currentState.getName() == qStart.getName())<<"\n";
	std::cout<<"\t timer: "<<action.variables->timer<<"\n \n";
	if((condition->checkCondition()) && (port.isEnabled) && (currentState.getName() == qStart.getName()))
	{
		//std::cout<<qStart.getName()<<" to "<<qDest.getName()<<"\n";
		return true;
	}
	return false;
}

State Transition::next()
{
	return qDest;
}

Action <Variables> Transition::getAction()
{
	return action;
}

std::list<Transition> Transitions::getTransitionsList()
{
	return transitionsList;
}

// SystemPort::SystemPort(FSM * m)
// {
// 	machine = m;
// 	isEnabled = false;
// }
//
// void SystemPort::execute()
// {
//
// }
