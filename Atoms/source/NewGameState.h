#ifndef _NewGameState_H_
#define _NewGameState_H_

#include <PA9.h>
#include "resources.h"
#include "game.h"
#include "Banner.h"
#include "resources.h"
#include "TapPoint.h"

class State;


class NewGameState: public State
{
	public:

		NewGameState(Banner*,Game*);

		void enter();

		void update();

		void exit();

	private:
		Banner* TheBaner;
		Game* TheGame;
		bool m_GamePaused;
};

#endif
