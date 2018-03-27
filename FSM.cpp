#include "FSM.h"
#include "functions.h"

FSM::FSM(States Q, State q0, Transitions T)
{
	this->Q = Q;
	this->q0 = q0;
	this->T = T;
	currentState = q0;
}

void FSM::reset(State resetState)
{
	this->q0 = resetState;
}

bool FSM::findPort(int id)
{
	for(std::list<Transition>::iterator it = T.begin(); it != T.end(); it ++)
	{
		if(it->isValid(currentState) && it->findPort(id))
		{
			return true;
		}
	}
}

void FSM::run(int n)
{
	for(int i = 1; i <= n; i ++)
	{
		for(std::list<Transition>::iterator it = T.begin(); it != T.end(); it ++)
		{
			if(it->isValid(currentState))
			{
				currentState = it->next();
				it->getAction().execute();
				//break;
			}
		}
	}
}
