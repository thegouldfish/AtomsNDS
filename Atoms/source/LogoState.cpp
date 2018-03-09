#include "state.h"
#include "LogoState.h"
#include "resources.h"
#include "Atoms.h"
#include <PA9.h>

#include "../gfx/bulk/all_gfx.h"


LogoState::LogoState()
{

}

void LogoState::enter()
{	
	m_timer = 0;
	PA_ResetBgSys();

	PA_EasyBgLoad(kTopScreen, 1, Logo_1);
	PA_EasyBgLoad(kBottomScreen, 2, Logo_2);
}

void LogoState::update()
{
	const int count = 480;
	if(Stylus.Released || Pad.Released.Anykey)
	{
		changeState(kGameMenuState);
	}
	else
	{
		if(m_timer > count)
		{
			changeState(kGameMenuState);
		}
		m_timer++;
	}
}


void LogoState::exit()
{

	// Put in a small delay after the menu.
	for(int i=0;i<GLOBALDELAY;i++)
	{
		PA_WaitForVBL();
	}

	PA_ResetBgSys();
}
