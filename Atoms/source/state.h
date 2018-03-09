#ifndef STATE_H
#define STATE_H
/* State
* By: Ross Gouldthorpe
* V0.1
* Each new state should be inherit from this base class.
*  
*
*
*/


#include <PA9.h>
class stateMachine;



class State
{
	public:
		stateMachine* machine;
		bool created;

		State();

		virtual void enter() {}

		virtual void update() {}

		virtual void exit() {}

		virtual void getMessage(int) {}

		virtual ~State() {}

		void changeState(int);
		void nextState();
		void stop();
		void sendMessage(int,int);

		State* GetState(int);
};


#endif

