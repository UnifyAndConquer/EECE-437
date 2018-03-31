#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <vector>
#include "FSM.h"

class SystemAction
{
public:
	SystemAction(){}
	SystemAction(void (* foo)());
	void execute();
private:
	void (* bar)();
	Variables * V;
};

class SystemCondition
{
public:
	SystemCondition(){};
	SystemCondition(bool * e);
	bool checkCondition();
private:
	bool * predicate;
};

class SystemPort: public Port
{
public:
	SystemPort(int i, FSM *m);
	bool isEnabled();
	FSM * getMachine();
private:
	FSM * machine;
};

class SystemInteraction
{
public:
	SystemInteraction(SystemCondition sc, SystemAction sa, std::vector<SystemPort> * sp);
	void execute();		   				//executes the FSM transitions that enable the ports
	bool isEnabled();
	bool portsEnabled();
private:
	SystemCondition sysCondition;
	SystemAction sysAction;
	std::vector<SystemPort> *sysPorts;
};

class System
{
public:
	System(std::vector<SystemInteraction> *sysint);
	void run();
private:
	std::vector<SystemInteraction> *sysInteractions;
};

#endif
