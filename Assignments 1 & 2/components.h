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

#define COND_DECLARE(VariablesObject, ConditionName, Expression)\
 class ConditionName : public Condition {\
 	public:\
		ConditionName(Variables * vars) { VariablesObject = vars; }\
		bool checkCondition() { return Expression; }\
	private:\
		Variables * VariablesObject;\
 };\


class Port
{
public:
	Port(){};
	Port(int i);
	void enable();
	void disable();
	bool checkStatus();
	int getID();
protected:
	int ID;
	bool isEnabled;
};

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
