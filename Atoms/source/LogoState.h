#ifndef _LogoState_H_
#define _LogoState_H_

#include <PA9.h>
#include "resources.h"
#include "game.h"
#include "Banner.h"
#include "resources.h"
#include "TapPoint.h"

class State;


class LogoState: public State
{
	public:

		LogoState();

		void enter();

		void update();

		void exit();

	private:
		int m_timer;
};

#endif
