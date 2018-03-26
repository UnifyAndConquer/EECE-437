#include "interaction.h"


Interaction::Interaction(std::list<Port> portList, Condition c, Action<Variables> a)
{
	this->portList = portList;
	this->c = c;
	this->a = a;
	bool portsEnabled = true;
	for(portList::iterator i = portList.begin(); i != portList.end(); i ++)
	{
		portsEnabled &= i.isEnabled;
	}
	isEnabled = portsEnabled && c.checkCondition();
}