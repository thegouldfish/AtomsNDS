#pragma once

#include <PA9.h>
#include "resources.h"
#include "game.h"
#include "Banner.h"
#include "resources.h"
#include "TapPoint.h"


class State;


class AIMenuState: public State
{
	public:
		AIMenuState(resources*);

		void enter();

		void update();

		void exit();

		enum e_selection {kSelectNone,kSelectPlayer,kSelectAiEasy,kSelectCount};

	private:
		resources* theResources;
		tapPoint selection;

		e_selection m_playerSelection[6];

		bool m_playGame;
};
