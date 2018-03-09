
#include "state.h"
#include "statemachine.h"

State::State()
{
	machine = 0;
	created = false;
}

void State::changeState(int state)
{
	if(machine != 0)
	{
		machine->changeState(state);
	}
}

void State::nextState()
{
	if(machine != 0)
	{
		machine->nextState();
	}
}


State* State::GetState(int)
{
	return 0;
}

void State::stop()
{
	if(machine != 0)
	{
		machine->stop();
	}
}


void State::sendMessage(int state,int message)
{
	if(machine != 0)
	{
		machine->sendMessage(state,message);
	}
}

