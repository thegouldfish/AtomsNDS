#include "state.h"
#include "NewGameState.h"
#include "resources.h"
#include "Atoms.h"
#include <PA9.h>
#include "MenuButton.h"

#include "../gfx/bulk/all_gfx.h"

NewGameState::NewGameState(Banner* ban,Game* game)
{
	TheBaner = ban;
	TheGame = game;
}

void NewGameState::enter()
{	
	PA_ResetBgSys();
	TheBaner->SetBannerWinner(TheGame->getWinner());
	TheGame->endGame();
	TheGame->resetGame();
}

void NewGameState::update()
{
	if(Stylus.Released)
	{
		changeState(kGameMenuState);
		AS_SoundQuickPlay(MenuButton);
	}
	else
	{
		//TheGame->explodePlay();
	}
}


void NewGameState::exit()
{

	// Put in a small delay after the menu.
	for(int i=0;i<GLOBALDELAY;i++)
	{
		PA_WaitForVBL();
	}

	TheBaner->HideBanner();
//	TheGame->resetGame();
	PA_SwitchScreens();
}
