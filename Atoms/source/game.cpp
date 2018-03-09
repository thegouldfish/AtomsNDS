#include <PA9.h>       // Include for PA_Lib


#include "game.h"
#include "Explode.h"
#include "grow.h"

#include "Animator.h"

#include "../gfx/bulk/all_gfx.h"
#include "../gfx/Atoms/all_gfx.h"

#define USE_KEEP


Game::Game()
{
	setupTiles();
}

void Game::startGame()
{
	resetGame();
	setOrder();
	setupGame();
	m_SoundEffectChannel = -1;
	m_WaitForAnim = false;
	m_NextPlayer = false;
	m_UpdateBanner = true;
	m_anim.Reset();
}


// Old function for setting up the players.
// in this the players have to be in order.
void Game::SetPlayerCount(int count)
{
	numberOfPlayers = count;

	
	for(int i=0;i<MAXPLAYERS;i++)
	{
		ThePlayers[i].reset();
	}

	for(int i=0;i<numberOfPlayers;i++)
	{
		ThePlayers[i].setPlayer(kLocal);
	}
}

// Setup the players based on the types, this means
// the players don't need to be a set order (0 to 5).
void Game::SetupPlayers(PlayerType type[MAXPLAYERS],AiLevels level[MAXPLAYERS])
{
	numberOfPlayers = 0;
	for(int i=0;i<MAXPLAYERS;i++)
	{
		m_Count[i] = 0;


		PlayerType thisType = type[i];

//		PA_iDeaS_DebugPrintf("setup Players: %d %d/n",i,thisType);

		ThePlayers[i].reset();

		if(thisType != kPlayerTypeNone)
		{
			ThePlayers[i].setPlayer(thisType);

			if(thisType == kAi)
			{
				ThePlayers[i].setAiLevel(level[i]);
			}

			numberOfPlayers++;
		}
	}
}


void Game::setupGame()
{
	m_turnCounter = 0;
	finished = false;
	doneAtLestOnce = false;
	explodeCyle = false;

	for(int i=0;i<MAXPLAYERS;i++)
	{
		ThePlayers[i].SetupPlayer(i);
	}
}

void Game::ContinueGame()
{
	m_anim.unPauseAll();
}

bool Game::isPaused()
{
	if(m_PauseGame)
	{
		m_PauseGame = false;
		return true;
	}

	return false;
}

// Sets the order of play
// this is currently setup to do this in order.
void Game::setOrder()
{
	playCounter = 0;

	for(int i=0;i<MAXPLAYERS;i++)
	{
		Order[i] = -1;
	}


	for(int i=0;i<numberOfPlayers;i++)
	{
		int rnd = PA_RandMinMax(0,MAXPLAYERS-1);

		//for(int j=0;j<numberOfPlayers;j++)

		int j=0;
		while(j < numberOfPlayers)
		{
			// If the player has been picked and the player is not playing pick something else.
			if(Order[j] == rnd || !(ThePlayers[rnd].isPlaying()))
			{
				rnd = PA_RandMinMax(0,MAXPLAYERS-1);
				j = 0;
			}
			else
			{
				j++;
			}
		}

		Order[i] = rnd;
	}

	currentPlayer = Order[0];
	m_CurrentPlayerType = ThePlayers[currentPlayer].getPlayerType();
}

void Game::resetGame()
{
	currentPlayer = 0;
	m_anim.KillAnims();
	int sprite = 0;
	for(int i=0;i<7;i++)
	{
		for(int j=0;j<10;j++)
		{
			PA_StopSpriteAnim(kBottomScreen,sprite);
			Tiles[i][j].reset();
			
			m_expandBy[i][j] = 0;

			sprite++;
		}
	}
}

void Game::DebugPrint()
{
#ifdef DEBUG
	char message[256];
	char text[4];

	for(int y=0;y<7;y++)
	{		
		sprintf(message," ");
		for(int x=0;x<10;x++)
		{			
			sprintf(text,"%d%d,",(Tiles[y][x].getPlayer()+1),Tiles[y][x].getSize());
			strcat(message,text);
		}
		PA_iDeaS_DebugPrintf("%s",message);
	}	
	PA_iDeaS_DebugPrintf("\n\n");
#endif
}

void Game::setupTiles()
{
	int sprite = 0;
	PA_LoadSprite16cPal(kBottomScreen, // Screen
			0, // Palette number
			(void*)pal_one_atom_Pal);

	PA_LoadSprite16cPal(kBottomScreen, // Screen
			1, // Palette number
			(void*)pal_two_atom_Pal);

	PA_LoadSprite16cPal(kBottomScreen, // Screen
			2, // Palette number
			(void*)pal_three_atom_Pal);

	PA_LoadSprite16cPal(kBottomScreen, // Screen
			3, // Palette number
			(void*)pal_four_atom_Pal);

	PA_LoadSprite16cPal(kBottomScreen, // Screen
			4, // Palette number
			(void*)pal_five_atom_Pal);

	PA_LoadSprite16cPal(kBottomScreen, // Screen
			5, // Palette number
			(void*)pal_six_atom_Pal);


	for(int i=0;i<7;i++)
	{
		for(int j=0;j<10;j++)
		{
			
			Tiles[i][j].SetAnimSystem(&m_anim);
			PA_CreateSprite(kBottomScreen, // Screen
					sprite, // Sprite number
					(void*)atom_Sprite, // Sprite name
					OBJ_SIZE_32X32, // Sprite size
					0, // 256 color mode
					0, // Sprite palette number
					(j*8*3)+4, (i*8*3)+4);


			PA_SetSpritePrio(kBottomScreen,sprite,1);

			if((j==0 || j == 9) && (i == 0 || i == 6))
			{
				Tiles[i][j].setup(sprite,square::kPlaceCorner);
			}
			else
			{
				if((j==0 || j == 9) || (i == 0 || i == 6))
				{
					Tiles[i][j].setup(sprite,square::kPlaceSide);
				}
				else
				{
					Tiles[i][j].setup(sprite,square::kPlaceMiddle);
				}
			}
			

			sprite++;
		}
	}
}

void Game::StopIdles()
{
	int i=0;
	int sprite = m_anim.getActiveIdle(i);

	while(sprite != -1)
	{
		int x,y;

		y = sprite / 10;
		x = sprite - (y*10);

		PA_StopSpriteAnim(kBottomScreen,sprite);
		Tiles[y][x].resetAnim();
		i++;
		sprite = m_anim.getActiveIdle(i);
	}

	m_anim.StopLoopingAnims();
}

void Game::NextPlayer()
{
	playCounter++;

	currentPlayer = Order[playCounter];	

	if(playCounter == numberOfPlayers)
	{
		playCounter = 0;
		currentPlayer = Order[playCounter];
		doneAtLestOnce = true;
	}

	if(ThePlayers[currentPlayer].isPlaying() && !ThePlayers[currentPlayer].isAlive())
	{
		NextPlayer();
	}

	StopIdles();

	for(int i=0;i<7;i++)
	{
		for(int j=0;j<10;j++)
		{			
			Tiles[i][j].StartIdleAnim(currentPlayer);
		}
	}
}

bool Game::DoInput()
{
	if(ThePlayers[currentPlayer].getPlay(Tiles))
	{
		int x = ThePlayers[currentPlayer].getLastPlayX();
		int y = ThePlayers[currentPlayer].getLastPlayY();
		
		Tiles[y][x].increaseSize(currentPlayer);
		Tiles[y][x].setAnim();


        if(Tiles[y][x].getExploded())
        {
			m_SoundEffectChannel = AS_SoundQuickPlay(Explode);
        }
        else
        {
			AS_SoundQuickPlay(grow);
        }


		return true;
	}

	return false;
}

void Game::expandBy(int x, int y)
{
	square::places place = Tiles[y][x].getPlace();

	if(place == square::kPlaceCorner)
	{
		if(y == 0)
		{
			m_expandBy[y+1][x]++;
		}

		if(y==6)
		{
			m_expandBy[y-1][x]++;
		}

		if(x == 0)
		{
			m_expandBy[y][x+1]++;
		}

		if(x == 9)
		{
			m_expandBy[y][x-1]++;
		}
	}
	else
	{
		if(place == square::kPlaceSide)
		{
			if(x == 0 || x == 9)
			{
				m_expandBy[y-1][x]++;
				m_expandBy[y+1][x]++;

				if(x == 0)
				{
					m_expandBy[y][x+1]++;
				}

				if(x == 9)
				{
					m_expandBy[y][x-1]++;
				}

			}

			if(y == 0 || y == 6)
			{
				m_expandBy[y][x-1]++;
				m_expandBy[y][x+1]++;

				if(y == 0)
				{
					m_expandBy[y+1][x]++;
				}

				if(y == 6)
				{
					m_expandBy[y-1][x]++;
				}
			}
		}
		else
		{
			m_expandBy[y-1][x]++;
			m_expandBy[y+1][x]++;

			m_expandBy[y][x-1]++;
			m_expandBy[y][x+1]++;
		}
	}
}




void Game::expand(int x, int y)
{
	Tiles[y][x].increaseSize(currentPlayer);
	Tiles[y][x].setAnim(true);

	/*

	square::places place = Tiles[y][x].getPlace();

	if(place == square::kPlaceCorner)
	{
		if(y == 0)
		{
			Tiles[y+1][x].increaseSize(currentPlayer);
			Tiles[y+1][x].setAnim(true);
		}

		if(y==6)
		{
			Tiles[y-1][x].increaseSize(currentPlayer);
			Tiles[y-1][x].setAnim(true);	
		}

		if(x == 0)
		{
			Tiles[y][x+1].increaseSize(currentPlayer);
			Tiles[y][x+1].setAnim(true);	
		}

		if(x == 9)
		{
			Tiles[y][x-1].increaseSize(currentPlayer);
			Tiles[y][x-1].setAnim(true);
		}
	}
	else
	{
		if(place == square::kPlaceSide)
		{
			if(x == 0 || x == 9)
			{
				Tiles[y-1][x].increaseSize(currentPlayer);
				Tiles[y-1][x].setAnim(true);	
				Tiles[y+1][x].increaseSize(currentPlayer);
				Tiles[y+1][x].setAnim(true);

				if(x == 0)
				{
					Tiles[y][x+1].increaseSize(currentPlayer);
					Tiles[y][x+1].setAnim(true);
				}

				if(x == 9)
				{
					Tiles[y][x-1].increaseSize(currentPlayer);
					Tiles[y][x-1].setAnim(true);
				}

			}

			if(y == 0 || y == 6)
			{
				Tiles[y][x-1].increaseSize(currentPlayer);
				Tiles[y][x-1].setAnim(true);	
				Tiles[y][x+1].increaseSize(currentPlayer);
				Tiles[y][x+1].setAnim(true);

				if(y == 0)
				{
					Tiles[y+1][x].increaseSize(currentPlayer);
					Tiles[y+1][x].setAnim(true);
				}

				if(y == 6)
				{
					Tiles[y-1][x].increaseSize(currentPlayer);
					Tiles[y-1][x].setAnim(true);
				}
			}
		}
		else
		{
			Tiles[y-1][x].increaseSize(currentPlayer);
			Tiles[y-1][x].setAnim(true);	
			Tiles[y+1][x].increaseSize(currentPlayer);
			Tiles[y+1][x].setAnim(true);

			Tiles[y][x-1].increaseSize(currentPlayer);
			Tiles[y][x-1].setAnim(true);
			Tiles[y][x+1].increaseSize(currentPlayer);
			Tiles[y][x+1].setAnim(true);
		}
	}
	*/
}

bool Game::explodeCheck()
{
	bool explodes = false;


	bool Alive[MAXPLAYERS];
	for(int i=0;i<numberOfPlayers;i++)
	{
		Alive[i] = false;
	}


	for(int i=0;i<7;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(Tiles[i][j].getPlayer() != -1)
			{
				Alive[Tiles[i][j].getPlayer()] = true;
				if(Tiles[i][j].getExploded())
				{
					bool result = Tiles[i][j].explodeCheck();
					explodes |= result;
					
					if(!result)
					{
						Tiles[i][j].reset();
						expandBy(j,i);
						explodes = true;

						m_SoundEffectChannel = AS_SoundQuickPlay(Explode);
					}
				}
			}
		}
	}

	for(int i=0;i<MAXPLAYERS;i++)
	{
		m_Count[i] = 0;
	}

	for(int i=0;i<7;i++)
	{
		for(int j=0;j<10;j++)
		{
			int expanding = m_expandBy[i][j];

			if(expanding > 0)
			{
#ifdef USE_KEEP
				int size = Tiles[i][j].getSize();

				int increaseBy = 0;

				if(expanding + size > 4)
				{
					increaseBy = 4 - size;	
				}
				else
				{
					increaseBy = expanding;
				}

				for(int count = 0;count < increaseBy;count++)
				{
					expand(j,i);
				}

				m_expandBy[i][j] -= increaseBy;
#else
				int size = Tiles[i][j].getSize();

				int increaseBy = 0;
				increaseBy = expanding;

				for(int count = 0;count < increaseBy;count++)
				{
					expand(j,i);
				}

				m_expandBy[i][j] = 0;		
#endif
			}

			int player = Tiles[i][j].getPlayer();
			if(player > -1)
			{
				m_Count[player] += Tiles[i][j].getSize();
			}
		}
	}



	for(int i=0;i<MAXPLAYERS;i++)
	{
		if(ThePlayers[i].isPlaying() && ThePlayers[i].isAlive())
		{
			if(!Alive[i])
				ThePlayers[i].kill();
		}
	}

	DebugPrint();
	return explodes;
}


void Game::regularPlay()
{
	if(DoInput())
	{
		if(doneAtLestOnce)
		{
			explodeCyle = explodeCheck();
		}

		if(!explodeCyle || !doneAtLestOnce)
		{
			m_turnCounter++;
			m_NextPlayer = true;
		}
	}
}

void Game::explodePlay()
{
	explodeCyle = explodeCheck();

	if(!explodeCyle)
	{
		m_turnCounter++;
		m_NextPlayer = true;
	}
}

bool Game::gameFinish()
{
	int count = 0;

	for(int i=0;i < MAXPLAYERS;i++)
	{
		if(ThePlayers[i].isPlaying() && ThePlayers[i].isAlive())
		{
			winner = i;
			count++;
		}
	}

	// 1 person left, we have a winner.	

	if(count == 1)
	{
		finished = true;
	}

	return count != 1;
}

bool Game::IsBannerNeedingUpdating()
{
	bool temp = m_UpdateBanner;

	if(m_UpdateBanner)
	{
		m_UpdateBanner = false;
	}

	return temp;
}

void Game::update()
{
	if(!m_anim.isAnimating())
	{
		m_anim.Reset();

		if(m_NextPlayer)
		{
			NextPlayer();
			m_NextPlayer = false;
			m_UpdateBanner = true;
			m_CurrentPlayerType = ThePlayers[currentPlayer].getPlayerType();
		}

		if(explodeCyle)
		{
			explodePlay();
		}
		else
		{
			regularPlay();
		}

		if(doneAtLestOnce)
		{
			gameFinish();
		}
	}
	
	if(Pad.Released.Start)
	{
		m_PauseGame = true;
		m_anim.PauseAll();
	}
}

void Game::endGame()
{	
	PA_SwitchScreens();
	m_anim.KillAnims();
}


int Game::getNumberOfPlayers()
{
	return numberOfPlayers;
}

int* Game::getPlayerOrder()
{
	return Order;
}

bool* Game::getAlive()
{

	for(int i=0;i < MAXPLAYERS;i++)
	{
		m_Alive[i] = (ThePlayers[i].isPlaying() && ThePlayers[i].isAlive());
	}

	return m_Alive;
}