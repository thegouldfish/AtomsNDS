#ifndef _GAMESTATE_H_
#define _GAMESTATE_H_

#include <PA9.h>
#include "resources.h"
#include "game.h"
#include "Banner.h"
#include "resources.h"

class State;


class GameState: public State
{
	public:


		enum GameSituation {kNormal,kPause,kQuit,kContinue,kGameSituationCount};

		GameState(resources*,Game* ,Banner* );

		void enter();

		void update();

		void exit();

		void getMessage(int);


		void SetSitRep(int);
		

	private:
		GameSituation m_sitRep;
		resources* theResources;
		Game* TheGame;
		Banner* TheBanner;
		bool m_GamePaused;
		bool m_Quit;
};

#endif
