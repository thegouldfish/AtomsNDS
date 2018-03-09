#ifndef _GAME_H_
#define _GAME_H_

#include "Atoms.h"
#include "square.h"
#include "player.h"
#include "Animator.h"
#define ATTR0_DISABLED   (2<<8) 

class Game
{
	private:

		enum GameState {kRegularPlay,kExplode,kNextPlayer,kAnimatingAtoms,kEndTurnAnim};

		GameState m_CurrentState;

		player ThePlayers[MAXPLAYERS];
		bool m_NextPlayer;
		int Order[MAXPLAYERS];
		square Tiles[7][10];
		int currentPlayer;
		int numberOfPlayers;
		bool explodeCyle;
		bool doneAtLestOnce;
		int m_turnCounter;
		int playCounter;
		bool m_PauseGame;
		int winner;
		bool finished;

		bool m_Alive[MAXPLAYERS];

		void setupGame();
		void setupTiles();
		void setOrder();
		bool gameFinish();
		void regularPlay();
		bool explodeCheck();
		void expand(int x, int y);
		bool DoInput();
		void NextPlayer();

		Animator m_anim;

		bool m_WaitForAnim;

		void StopIdles();

		bool m_UpdateBanner;

		PlayerType m_CurrentPlayerType;

		void DebugPrint();

		void expandBy(int x, int y);
		int m_expandBy[7][10];

		

	public:
		Game();

		void SetPlayerCount(int);
		void SetupPlayers(PlayerType[MAXPLAYERS],AiLevels[MAXPLAYERS]);

		inline PlayerType getPlayerType() {return m_CurrentPlayerType;}

		bool IsBannerNeedingUpdating();
		inline int getTurnCount() {return m_turnCounter;}

		bool isPaused();
		void startGame();
		void update();
		void endGame();
		void resetGame();
		void explodePlay();
		void ContinueGame();

		void TriggerOneShot();
		bool IsPlayingAnims();


		int m_SoundEffectChannel;

		bool gameFinished()
		{
			return finished;
		}


		int getPlayCounter()
		{
			return playCounter;
		}

		int getPlayer()
		{
			return currentPlayer;
		}

		int getWinner()
		{
			return winner;
		}

		int getNumberOfPlayers();
		int* getPlayerOrder();
		bool* getAlive();
		int m_Count[MAXPLAYERS];
};

#endif
