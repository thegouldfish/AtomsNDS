#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Atoms.h"

class Game;
class square;

class player
{
	public:
		enum Playing{kNotPlaying,kDead,kAlive};

		player();

		inline void SetupPlayer(int player)
		{
			playerNumber = player;
		}


		bool getPlay(square[7][10]);

		void setPlayer(PlayerType);

		void setAiLevel(AiLevels);

		void kill();

		void reset();

		inline int getLastPlayX()
		{
			return lastPlayX;
		}

		inline int getLastPlayY()
		{
			return lastPlayY;
		}

		inline bool isPlaying()
		{
			return playerState != kNotPlaying;
		}


		inline bool isAlive()
		{
			return playerState == kAlive;
		}

		inline PlayerType getPlayerType() {return playType;}



	private:

		bool localPlay(square[7][10]);

		bool AIPlay(square[7][10]);
		bool EasyAI(square[7][10]);
		bool NormalAI(square[7][10]);
		bool HardAI(square[7][10]);


		bool WiFiPlay(square[7][10]);
		
		bool InternetPlay(square[7][10]);


		int lastPlayX;
		int lastPlayY;

		PlayerType playType;
		Playing playerState;
		int playerNumber;

		AiLevels m_AiLevel;
};


#endif
