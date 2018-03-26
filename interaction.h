#ifndef INTERACTION_H
#define INTERACTION_H

#include "components.h"
#include "functions.h"
#include <iostream>
#include <list>


class Interaction
{
public:
	Interaction(std::list<Port> l, Condition c, Action<Variables> a);

private:
	std::list<Port> portList;
	Condition c;
	Action<Variables> a;
	bool isEnabled = 0;
};


#endif