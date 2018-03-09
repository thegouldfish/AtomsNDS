#include "state.h"
#include "PauseState.h"
#include "resources.h"
#include "Atoms.h"
#include <PA9.h>
#include "MenuButton.h"
#include "GameState.h"

#include "../gfx/bulk/all_gfx.h"

PauseState::PauseState(resources* res)
{
	theResources = res;


	selection = tapPoint(-1);

	selection.addTapPoint(15,160,145,185,kContinue);
	selection.addTapPoint(160,160,245,185,kQuit);	
}

void PauseState::enter()
{
	PA_EasyBgLoad(kBottomScreen, kWiningScreen, PauseScreen);
	PA_SetBgPrio(kBottomScreen,kWiningScreen,0);
}

void PauseState::update()
{
	selection.update();

	int result = selection.checkTapPoint();


	if(result == kContinue)
	{
		sendMessage(kGameState,GameState::kContinue);
		changeState(kGameState);
	}

	if(result == kQuit)
	{
		sendMessage(kGameState,GameState::kQuit);
		changeState(kGameState);
	}
}


void PauseState::exit()
{
	AS_SoundQuickPlay(MenuButton);

	// Put in a small delay after the menu.
	for(int i=0;i<GLOBALDELAY;i++)
	{
		PA_WaitForVBL();
	}

	PA_SetBgPrio(kBottomScreen,kWiningScreen,2);
	PA_DeleteBg(kBottomScreen, kWiningScreen);
}
