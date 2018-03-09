#include "player.h"
#include "game.h"
#include "square.h"
#include <PA9.h> 

#include <stdlib.h>

player::player()
{
	reset();
}

void player::reset()
{
	srand(randomSeed());
	playerState = kNotPlaying;
	playType = kPlayerTypeNone;
}

bool player::getPlay(square Tiles[7][10])
{
	bool result = false;

	if(playType == kLocal)
	{
		result = localPlay(Tiles);
	}

	if(playType == kAi)
	{
		result = AIPlay(Tiles);
	}


	if(!result)
	{
		lastPlayX = -1;
		lastPlayY = -1;
	}
	return result;
}

void player::setPlayer(PlayerType type)
{
	playerState = kAlive;
	playType = type;
}


void player::setAiLevel(AiLevels level)
{
	m_AiLevel = level;
}


void player::kill()
{
	playerState=kDead;
}


bool player::localPlay(square Tiles[7][10])
{
	if (Stylus.Released)
	{
		int x = (Stylus.X -8) /8 /3;
		int y = (Stylus.Y -8) /8 /3;
		
		if(Tiles[y][x].getPlayer() == -1 || Tiles[y][x].getPlayer() == playerNumber)
		{
			lastPlayX = x;
			lastPlayY = y;
			return true;
		}
	}
	return false;
}

bool player::AIPlay(square Tiles[7][10])
{
	switch(m_AiLevel)
	{
		case kEasy:
		{
			return EasyAI(Tiles);			
		}

		case kNormal:
		{
			return NormalAI(Tiles);
		}

		case kHard:
		{
			return HardAI(Tiles);
		}
	}

	return false;
}


/**
 * Easy AI
 *
 * Randomly pick a square for a number of turns.
 * if this square is empty or the same as the player
 * then put an atom there.
 *
 * else after X number of attempts to find a square the
 * AI will randomly move from the current selected square 
 * till it finds some where to put an atom.
 *
 * Not a decent AI but it will do something.
 *
**/

bool player::EasyAI(square Tiles[7][10])
{
	bool done = false;

	int tryCount = 0;
	int maxTryCount = 30;

	int randomX = 0;
	int randomY = 0;

	do
	{
		if(tryCount < maxTryCount)
		{
			randomX = rand() % 10;
			randomY = rand() % 7;
		}
		else
		{
			randomX++;

			if(randomX >= 10)
			{
				randomX = 0;
				randomY++;
			}

			if(randomY >= 7)
			{
				randomY=0;
			}
		}

		int player = Tiles[randomY][randomX].getPlayer();
		if(player == -1)
		{
			lastPlayX = randomX;
			lastPlayY = randomY;
			done = true;
		}
		else if (player == playerNumber)
		{
			lastPlayX = randomX;
			lastPlayY = randomY;
			done = true;
		}
		else
		{
			tryCount++;
		}
	}while(!done);

	

	return true;
}

bool player::NormalAI(square[7][10])
{

	return false;
}

bool player::HardAI(square[7][10])
{

	return false;
}



bool player::WiFiPlay(square Tiles[7][10])
{
	return false;
}

bool player::InternetPlay(square Tiles[7][10])
{
	return false;
}
