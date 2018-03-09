#include "state.h"
#include "CreditState.h"
#include "resources.h"
#include "Atoms.h"
#include <PA9.h>

#include "../gfx/bulk/all_gfx.h"

#include "MenuButton.h"
#include "TextString.h"

CreditState::CreditState()
{

}

void CreditState::enter()
{	
	PA_EasyBgLoad(kTopScreen, 1, Title_topscreen);
	PA_EasyBgLoad(kBottomScreen, 2, Atoms_credits);


	PA_Init16cBg(kBottomScreen,0);

	PA_16cTextAlign(ALIGN_RIGHT);
	PA_16cText(kBottomScreen, //screen 
				0, 168, 200, 200, //x1, y1, x2, y2 position
				MiscStrings[g_CurrentLanguage][kMiscCreditsMenu], //text
				1, //color (1-10)
				6, // text size (0-4)
				100);
}

void CreditState::update()
{
	if(Stylus.Released)
	{
		AS_SoundQuickPlay(MenuButton);
		changeState(kGameMenuState);
	}
}


void CreditState::exit()
{

	// Put in a small delay after the menu.
	for(int i=0;i<GLOBALDELAY;i++)
	{
		PA_WaitForVBL();
	}

	PA_DeleteBg(kTopScreen, 2);
	PA_DeleteBg(kBottomScreen, 2);
}
