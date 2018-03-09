#ifndef _GAMEMENUSTATE_H_
#define _GAMEMENUSTATE_H_

#include <PA9.h>
#include "resources.h"
#include "game.h"
#include "Banner.h"
#include "resources.h"
#include "TapPoint.h"

class State;


class GameMenuState: public State
{
	public:

		GameMenuState(resources*);

		void enter();

		void update();

		void exit();

	private:
		resources* theResources;
		tapPoint selection;
};

#endif
