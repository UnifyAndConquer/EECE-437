#include "system.h"
#include "systemfunctions.h"

//SYSTEM
System::System(std::vector<SystemInteraction> *sysint)
{
  sysInteractions = sysint;
}

void System::run()
{
  std::vector<SystemInteraction>::iterator sysInt;
  for(sysInt = sysInteractions->begin(); sysInt != sysInteractions->end(); sysInt ++)
  {
    if(sysInt->isEnabled())
      sysInt->execute();
  }
}

//SYSTEMPORT
SystemPort::SystemPort(FSM * m)
{
  machine = m;
}

int SystemPort::getID()
{
  return ID;
}

bool SystemPort::isEnabled()
{
  return machine->findPort(ID);     //searches through the FSM's valid transitions for a port equal to p by ID
}

//SYSTEMINTERACTION
SystemInteraction::SystemInteraction(SystemCondition sc, SystemAction sa, std::vector<SystemPort> * sp)
{
  sysCondition = sc;
  sysAction = sa;
  sysPorts = sp;
}

void SystemInteraction::execute()
{
  machine->execute();
  sysAction.execute();
}

bool SystemInteraction::isEnabled()
{
  if(sysCondition.checkCondition() && portsEnabled())
    return true;
}

bool SystemInteraction::portsEnabled()
{
  if(!sysPorts->empty())
  {
    bool sig = true;
    std::vector<SystemPort>::iterator s;
    for(s = sysPorts->begin(); s != sysPorts->end(); s ++)
    {
      sig &= s->isEnabled();
    }
    return sig;
  }
  return true;
}

//SYSTEMCONDITION
SystemCondition::SystemCondition(bool * e)
{
  predicate = e;
}

bool SystemCondition::checkCondition()
{
  return * predicate;
}

//SYSTEMACTION
SystemAction::SystemAction(void (*foo)())
{
  bar = foo;
}
// int main()
// {
//
//
//   return 0;
// }
