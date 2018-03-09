#ifndef _PauseState_H_
#define _PauseState_H_

#include <PA9.h>
#include "resources.h"
#include "game.h"
#include "Banner.h"
#include "resources.h"
#include "TapPoint.h"

class State;


class PauseState: public State
{
	public:

		enum Buttons {kContinue,kQuit};

		PauseState(resources*);

		void enter();

		void update();

		void exit();

	private:
		resources* theResources;
		tapPoint selection;
};

#endif
