#include "state.h"
#include "GameMenuState.h"
#include "resources.h"
#include "Atoms.h"
#include <PA9.h>

#include "../gfx/bulk/all_gfx.h"

#include "MenuButton.h"
#include "MenuMusic.h"

#include "TextString.h"


GameMenuState::GameMenuState(resources* res)
{
	theResources = res;


	selection = tapPoint(-1);

	selection.addTapPoint(72,23,170,50,1);
//	selection.addTapPoint(72,65,170,92,2);

	selection.addTapPoint(72,105,170,135,3);
	selection.addTapPoint(72,155,170,185,4);
}

void GameMenuState::enter()
{
	theResources->reset();

	PA_EasyBgLoad(kTopScreen, 1, Title_topscreen);
	PA_EasyBgLoad(kBottomScreen, 1, menu);

	if(AS_GetMP3Status() != MP3ST_PLAYING)
	{
		AS_MP3DirectPlay((u8*)MenuMusic, (u32)MenuMusic_size);
		AS_SetMP3Loop(true);
	}

	PA_Init16cBg(kBottomScreen,0);

	PA_16cCustomFont(6, Atoms_Font);


	PA_16cTextAlign(ALIGN_CENTER);
	PA_16cText(kBottomScreen, //screen 
				75, 25, 175, 40, //x1, y1, x2, y2 position
				MenuStrings[g_CurrentLanguage][kMenuLocalGame], //text
				10, //color (1-10)
				6, // text size (0-4)
				100);

/*
	PA_16cText(kBottomScreen, //screen 
				100, 70, 255, 180, //x1, y1, x2, y2 position
				MenuStrings[g_CurrentLanguage][kMenuWiFiGame], //text
				1, //color (1-10)
				6, // text size (0-4)
				100);
*/

	PA_16cTextAlign(ALIGN_CENTER);
	PA_16cText(kBottomScreen, //screen 
				75, 109, 175, 180, //x1, y1, x2, y2 position
				MenuStrings[g_CurrentLanguage][kMenuHelp], //text
				10, //color (1-10)
				6, // text size (0-4)
				100);

	PA_16cTextAlign(ALIGN_CENTER);
	PA_16cText(kBottomScreen, //screen 
				75, 155, 175, 180, //x1, y1, x2, y2 position
				MenuStrings[g_CurrentLanguage][kMenuCredits], //text
				10, //color (1-10)
				6, // text size (0-4)
				100);


}

void GameMenuState::update()
{
	selection.update();

	int selected = selection.checkTapPoint();


	switch(selected)
	{
		case 1:
		{
			changeState(kAIMenuState);
			break;
		}
/*
		case 2:
		{
			changeState(kAIMenuState);
			break;
		}
*/

		case 3:
		{
			changeState(kHelpState);
			break;
		}


		case 4:
		{
			changeState(kCreditsState);
			break;
		}
	}
}


void GameMenuState::exit()
{
	AS_SoundQuickPlay(MenuButton);
	// Put in a small delay after the menu.
	for(int i=0;i<GLOBALDELAY;i++)
	{
		PA_WaitForVBL();
	}

	PA_DeleteBg(kTopScreen, 1);
	PA_DeleteBg(kBottomScreen, 1);
	PA_DeleteBg(kBottomScreen, 0);
}
