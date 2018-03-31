#include "components.h"
#include "functions.h"
#include <iostream>

State::State(std::string name)
{
	stateName = name;
}

std::string State::getName()
{
	return stateName;
}

Port::Port(int i)
{
	isEnabled = false;
	ID = i;
}

int Port::getID()
{
	return ID;
}

void Port::enable()
{
	isEnabled = true;
}

void Port::disable()
{
	isEnabled = false;
}

Transition::Transition(State qStart1, State qDest1, Port port1, Condition * condition1, void (* foo)())
{
	qStart = qStart1; qDest = qDest1; port = port1; condition = condition1; bar = foo;//action = action1;
	//std::cout<<"\t condition: "<<condition->checkCondition()<<"\n";   //condition points to the variable struct
}

bool Transition::isValid(State currentState)
{
	// std::cout<<qStart.getName()<<" to "<<qDest.getName()<<"\n";
	// std::cout<<"\t condition: "<<condition->checkCondition()<<"\n";
	// std::cout<<"\t port: "<<port.isEnabled<<"\n";
	// std::cout<<"\t states: "<<(currentState.getName() == qStart.getName())<<"\n";
	// std::cout<<"\t timer: "<<V.timer<<"\n \n";
	if((condition->checkCondition()) && (port.isEnabled) && (currentState.getName() == qStart.getName()))
	{
		std::cout<<qStart.getName()<<" to "<<qDest.getName()<<"\n";
		// std::cout<<"\t timer: "<<action.variables->timer<<"\n \n";
		return true;
	}
	return false;
}

State Transition::next()
{
	return qDest;
}

void Transition::executeFunction()
{
	bar();
}

// Action Transition::getAction()
// {
// 	return action;
// }

std::list<Transition> Transitions::getTransitionsList()
{
	return transitionsList;
}

bool Transition::findPort(int id)
{
	if(port.getID() == id)
		return true;
	return false;
}
