#ifndef _CreditState_H_
#define _CreditState_H_

class State;


class CreditState: public State
{
	public:

		CreditState();

		void enter();

		void update();

		void exit();

	private:

};

#endif
