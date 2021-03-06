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
      sysInt->executeFunction();
  }
}

//SYSTEMPORT
SystemPort::SystemPort(int i, FSM * m) {machine = m; ID = i;}
bool SystemPort::isEnabled() {return machine->findPort(ID);}    //searches through FSM's valid transitions for a port equal to p by ID
FSM * SystemPort::getMachine() {return machine;}

//SYSTEMINTERACTION
SystemInteraction::SystemInteraction(SystemCondition sc, std::vector<SystemPort> * sp, void (* foo)())
{sysCondition = sc; sysPorts = sp; bar = foo;}
void SystemInteraction::executeFunction()
{
  std::vector<SystemPort>::iterator sysPort;
  for(sysPort = sysPorts->begin(); sysPort != sysPorts->end(); sysPort ++)
  {
    sysPort->getMachine()->execute();
  }
  bar();
}
bool SystemInteraction::isEnabled()
{
  if(sysCondition.checkCondition() && portsEnabled())
    return true;
  return false;
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
  return false;
}

//SYSTEMCONDITION
SystemCondition::SystemCondition(bool * e) {predicate = e;}
bool SystemCondition::checkCondition() {return * predicate;}
