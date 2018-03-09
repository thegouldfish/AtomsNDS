#include "state.h"
#include "GameState.h"
#include "game.h"
#include "Banner.h"
#include "resources.h"

#include "../gfx/bulk/all_gfx.h"
#include "../gfx/Atoms/all_gfx.h"

#include <PA9.h>       // Include for PA_Lib


GameState::GameState(resources* res,Game* game,Banner* banner)
{
	theResources = res;
	TheGame = game;
	TheBanner = banner;
	m_sitRep = kNormal;
}


void GameState::SetSitRep(int SitRep)
{
	if(SitRep > -1 && SitRep < kGameSituationCount)
	{
		m_sitRep = (GameSituation) SitRep;
	}
}

void GameState::getMessage(int sitRep)
{
	SetSitRep( sitRep);
}

void GameState::enter()
{
	if(m_sitRep == kNormal)
	{
		TheGame->SetupPlayers(theResources->m_PlayerDetails,theResources->m_AiDetails);	
		TheGame->startGame();

		PA_InitRand();
		PA_SRand(randomSeed());
		TheBanner->ShowBanner();

		PA_EasyBgLoad(kBottomScreen, 1, BottomScreen);

		TheBanner->CreateOrderSprites();
	}

	if(m_sitRep == kContinue)
	{
		m_sitRep = kNormal;
		TheGame->ContinueGame();
	}
}

void GameState::update()
{
	if(m_sitRep == kNormal)
	{
		if(TheGame->gameFinished())
		{
			changeState(kNewGameState);
		}
		else
		{

			TheGame->update();

			TheBanner->ShowPlayerRatings(TheGame->getAlive(),TheGame->m_Count,TheGame->getPlayerOrder());

			if(TheGame->IsBannerNeedingUpdating())
			{
				TheBanner->SetBanner(TheGame->getPlayer(),TheGame->getPlayerType());
				TheBanner->ShowPlayerOrder(TheGame->getPlayCounter(),TheGame->getNumberOfPlayers(),TheGame->getPlayerOrder(),TheGame->getAlive());
				TheBanner->SetTurnNumber(TheGame->getTurnCount());
			}
		}


		if(TheGame->isPaused())
		{
			m_sitRep = kPause;
			changeState(kPauseState);
		}
	}

	if(m_sitRep == kQuit)
	{
		changeState(kGameMenuState);
	}
}


void GameState::exit()
{	
	if(m_sitRep == kQuit)
	{
		TheBanner->ClearOrderSprites();
		TheBanner->HideBanner();
		TheGame->resetGame();
	}

	if(m_sitRep == kNormal)
	{
		TheBanner->ClearOrderSprites();
	}

	// Exit so set back to normal.
	m_sitRep = kNormal;

	// Put in a small delay after the menu.
	for(int i=0;i<GLOBALDELAY;i++)
	{
		PA_WaitForVBL();
	}
}
