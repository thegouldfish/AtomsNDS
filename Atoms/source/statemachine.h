#ifndef STATEMACHINE_H
#define STATEMACHINE_H

/* State Machine
* By: Ross Gouldthorpe
* V0.1
*
*/

#include "state.h"

class stateMachine
{
	public:
		// Sets the order in which the statemachine moves in.
		enum stateOrder{kInOrder,kOutOfOrder};
		
		// Creates the state machine, the int is the number of states that will be added.
		stateMachine(int sizeOfMachine);
		
		// Adds a state to the machine, this will include the state to add and the id number for the state.
		bool addState(State* stateToAdd, int stateId);

		// starts the state machine which should tell the machine which state to start and the order to run in.
		void start(int stateId,stateOrder runningOrder);
		
		// tells the machine to change to the id passed in.
		void changeState(int stateToChangeTo);
		
		//This will move the machine to the next state.
		void nextState();
		
		// returns true if the machine is running.
		bool isRunning();
		
		//Stops the machine.
		void stop();
		
		// calls the update of the running state.
		void update();
		
		// sends a message to the state.
		// If the state number is -1 it will send the message to each state
		void sendMessage(int state,int message);

	private:
		State** theStates;

		stateOrder Order;
		int stateCount;
		int currentState;
		bool Running;
};


#endif

