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
		virtual bool checkCondition() = 0;
};

#define COND_DECLARE(ConditionName, Expression)\
 class ConditionName : public Condition {\
 	public:\
		ConditionName(Variables * vars) { V = vars; }\
		bool checkCondition() { return Expression; }\
	private:\
		Variables * V;\
 };\


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
// template <class T>
// class Action
// {
// public:
// 	Action(){};
// 	Action(void (* foo)(T & vars), T & vars)
// 	{
// 		T & variables = vars;
// 		bar = foo;
// 	}
// 	void execute()				//executes function passed to action in constructor
// 	{
// 		bar(V);			//execute [bar]
// 	}
// 	T * variables;
// private:
// 	void (* bar)(T & vars);			//temporary function pointer used in execute
// };


// class Action			//kind of useless
// {
// public:
// 	Action(){};
// 	Action(void (* foo)()) {bar = foo;}
// 	void execute() {bar();}
// private:
// 	void (* bar)();			//temporary function pointer used in execute
// };

class Transition
{
public:
	Transition(){};
	Transition(State qStart1, State qDest1, Port port1, Condition * condition1, void (* foo)());
	bool isValid(State currentState);
	State next();
	void executeFunction();
	bool findPort(int id);

private:
	State qStart;
	State qDest;
	Port port;
	Condition * condition;
	void (* bar)();
	//Action action;
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
