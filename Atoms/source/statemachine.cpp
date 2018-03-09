/* State Machine
* By: Ross Gouldthorpe
*
*
*/

#include "statemachine.h"

	stateMachine::stateMachine(int numberOfStates)
	{
		theStates = new State*[numberOfStates];

		// NULL all the pointers for now.
		for(int i=0;i<numberOfStates;i++)
		{
			theStates[i] = 0;
		}

		Running = false;

		stateCount = numberOfStates;
		currentState = -1;
	}


	bool stateMachine::addState(State* newState, int stateNumber)
	{
		if(stateNumber < stateCount && stateNumber > -1)
		{
			theStates[stateNumber] = newState;
			newState->created = true;
			newState->machine = this;
			return true;
		}
		else
		{
			return false;
		}
	}

	void stateMachine::changeState(int state)
	{
		if(state < stateCount && state > -1 && Order == kOutOfOrder)
		{
			if(currentState != -1 && theStates[currentState] != 0)
			{
				theStates[currentState]->exit();
			}

			if(theStates[state] != 0)
			{
				theStates[state]->enter();
				currentState = state;
			}
		}
	}

	void stateMachine::update()
	{
		if(Running && currentState != -1 && theStates[currentState] != 0)
		{
			theStates[currentState]->update();
		}
	}

	void stateMachine::start(int state, stateOrder theOrder)
	{
		Order = theOrder;

		if(state < stateCount && state > -1 && theStates[state] != 0)
		{
			theStates[state]->enter();
			currentState = state;
			Running = true;
		}
	}

	void stateMachine::nextState()
	{
		if(Running && currentState != -1 && theStates[currentState] != 0)
		{

			if(theStates[currentState]->created)
			{
				theStates[currentState]->exit();
			}

			if(currentState + 1 < stateCount)
			{
				currentState++;

				if(theStates[currentState]->created)
				{
					theStates[currentState]->enter();
				}
				else
				{
					nextState();
				}
			}
			else
			{
				stop();
			}

		}
	}

	void stateMachine::stop()
	{
		if(Running && currentState != -1 && theStates[currentState] != 0)
		{
			Running = false;
			theStates[currentState]->exit();
			currentState = -1;			
		}
	}

	bool stateMachine::isRunning()
	{
		return Running;
	}

	void stateMachine::sendMessage(int state, int message)
	{
		if(Running)
		{
			if(state == -1)
			{
				for(int i=0;i<stateCount;i++)
				{
					if(theStates[i] != 0)
					{
						theStates[i]->getMessage(message);
					}
				}
			}
			else
			{
				if(theStates[state]->created)
				{
					if(theStates[state] != 0)
					{
						theStates[state]->getMessage(message);
					}
				}
			}
		}
	}

