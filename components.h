#ifndef COMPONENTS_H
#define COMPONENTS_H

#include "functions.h"
#include <iostream>
#include <vector>
#include <list>

class State
{
public:
	State(){};
	State(std::string name);
	std::string getName();
private:
	std::string stateName;
};


class Condition
{
public:
	//Condition(){};
	Condition(bool *t);
	bool checkCondition();
private:
	bool * isTrue;
};


class Port
{
public:
	Port(){};
	Port(int i);
	void enable();
	void disable();
	bool isEnabled;
	int getID();
private:
	int ID;
};

// takes in pointer to function and "variables" template class, executes function on template class
template <class T>
class Action
{
public:
	Action(){};
	Action(void (* foo)(T * vars), T * vars)
	{
		bar = foo;
		variables = vars;
	}
	void execute()				//executes function passed to action in constructor
	{
		bar(variables);			//execute [bar]
	}
T * variables;

private:
	void (* bar)(T * vars);			//temporary function pointer used in execute

};

class Transition
{
public:
	Transition(){};
	Transition(State qStart1, State qDest1, Port port1, Condition * condition1, Action <Variables> action1);
	bool isValid(State currentState);
	State next();
	Action <Variables> getAction();
	bool findPort(int id);

private:
	State qStart;
	State qDest;
	Port port;
	Condition * condition;
	Action <Variables> action;
};

class States: public std::list<State>		//w hek
{
public:
	States(){};
private:
};

class Transitions: public std::list<Transition>
{
public:
	Transitions(){};
	std::list<Transition> getTransitionsList();

private:
	std::list<Transition> transitionsList;
};

#endif
