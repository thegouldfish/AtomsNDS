#include "state.h"
#include "MenuState.h"
#include "resources.h"
#include "Atoms.h"
#include <PA9.h>
#include "MenuButton.h"

#include "../gfx/bulk/all_gfx.h"




MenuState::MenuState(resources* res)
{
	theResources = res;


	selection = tapPoint(-1);

//  No need to be able to select player one at the moment.
//	selection.addTapPoint(7,5,98,80,1);
	selection.addTapPoint(99,5,161,93,2);
	selection.addTapPoint(166,5,245,78,3);

	selection.addTapPoint(7,105,90,179,4);
	selection.addTapPoint(91,101,163,186,5);
	selection.addTapPoint(166,100,247,176,6);
}

void MenuState::enter()
{
	PA_EasyBgLoad(kTopScreen, 1, Title_topscreen);
	PA_EasyBgLoad(kBottomScreen, 0, players);
}

void MenuState::update()
{
	selection.update();

	int players = selection.checkTapPoint();

	if(players != -1)
	{
		AS_SoundQuickPlay(MenuButton);
		for(int i=0;i<players;i++)
		{
			theResources->m_PlayerDetails[i] = kLocal;
		}

		for(int i=players;i<MAXPLAYERS;i++)
		{
			theResources->m_PlayerDetails[i] = kPlayerTypeNone;
		}
		
		changeState(kGameState);
	}
}


void MenuState::exit()
{	

	// Put in a small delay after the menu.
	for(int i=0;i<GLOBALDELAY;i++)
	{
		PA_WaitForVBL();
	}

	PA_DeleteBg(kTopScreen, 1);
	PA_DeleteBg(kBottomScreen, 0);
}
