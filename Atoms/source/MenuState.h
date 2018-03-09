#ifndef _MENUSTATE_H_
#define _MENUSTATE_H_

#include <PA9.h>
#include "resources.h"
#include "game.h"
#include "Banner.h"
#include "resources.h"
#include "TapPoint.h"

class State;


class MenuState: public State
{
	public:

		MenuState(resources*);

		void enter();

		void update();

		void exit();

	private:
		resources* theResources;
		tapPoint selection;
};

#endif
