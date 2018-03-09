#include "state.h"
#include "AIMenuState.h"
#include "resources.h"
#include <PA9.h>

#include "../gfx/bulk/all_gfx.h"

#include "MenuButton.h"
#include "TextString.h"

// Sound FX
#include "grow.h"
#include "MenuButton.h"

AIMenuState::AIMenuState(resources* res)
{
	theResources = res;


	selection = tapPoint(-1);

// One for each player
	selection.addTapPoint(32,0,95,95,0);
	selection.addTapPoint(96,0,159,95,1);
	selection.addTapPoint(160,0,223,95,2);

	selection.addTapPoint(32,96,95,192,3);
	selection.addTapPoint(96,96,159,192,4);
	selection.addTapPoint(160,96,223,192,5);

// One for forward one for back
	selection.addTapPoint(0,80,31,112,6);
	selection.addTapPoint(224,80,256,112,7);



	PA_LoadSpritePal(kBottomScreen,11,(void*)human_computer_Pal);


	int spriteNumber = 110;

	for(int i=0;i<2;i++)
	{
		for(int j=0;j<3;j++)
		{
			// 48 - 64
			// 48 - 160

			int x = 47 + (64 * j);
			int y = 64 + (96 * i);

			PA_CreateSprite(kBottomScreen, // Screen
				spriteNumber, // Sprite number
				(void*)human_computer_Sprite, // Sprite name
				OBJ_SIZE_32X32, // Sprite size
				1, // 256 color mode
				11, // Sprite palette number
				x, y);

			hideSprite(kBottomScreen,spriteNumber);

			spriteNumber++;
		}
	}
}

void AIMenuState::enter()
{
	PA_InitText(kTopScreen, 0);
	PA_SetTextCol(kTopScreen,12,12,12);

	PA_EasyBgLoad(kTopScreen, 1, HelpTopScreen);
	PA_EasyBgLoad(kBottomScreen, 0, playerSelect);

	PA_BoxText(kTopScreen,2,2,20,14,MiscStrings[g_CurrentLanguage][kMiscPlayerSelectInfo],512);

	int spriteNumber = 110;
	

	m_playerSelection[0] = kSelectPlayer;
	PA_SetSpriteAnim(kBottomScreen,spriteNumber,1);
	showSprite(kBottomScreen,spriteNumber);
	spriteNumber++;

	m_playerSelection[1] = kSelectAiEasy;
	PA_SetSpriteAnim(kBottomScreen,spriteNumber,2);
	showSprite(kBottomScreen,spriteNumber);
	spriteNumber++;

	
	for(int i = 2;i<6;i++)
	{
		m_playerSelection[i] = kSelectNone;
		PA_SetSpriteAnim(kBottomScreen,spriteNumber,0);
		showSprite(kBottomScreen,spriteNumber);
		spriteNumber++;
	}




	m_playGame = false;
}

void AIMenuState::update()
{
	selection.update();

	int	selected = selection.checkTapPoint();

	if(selected < 6 && selected != -1)
	{
		int temp = (int)m_playerSelection[selected];
		m_playerSelection[selected] = (e_selection)(temp+1);
		AS_SoundQuickPlay(grow);
	}

	int spriteNumber = 110;
	for(int i=0;i<6;i++)
	{
		if(m_playerSelection[i] >= kSelectCount)
		{
			m_playerSelection[i] = kSelectNone;
		}
		
		PA_SetSpriteAnim(kBottomScreen,spriteNumber,(int)m_playerSelection[i]);
		spriteNumber++;
	}

	if(selected == 6)
	{
		AS_SoundQuickPlay(MenuButton);
		m_playGame = false;
		changeState(kGameMenuState);
	}

	if(selected == 7)
	{
		int count = 0;
		for(int i=0;i<6;i++)
		{
			if(m_playerSelection[i] != kSelectNone)
			{
				count++;
			}
		}

		if(count > 1)
		{
			AS_SoundQuickPlay(MenuButton);
			m_playGame = true;
			changeState(kGameState);
		}
	}
}


void AIMenuState::exit()
{
	//PA_BoxText(kTopScreen,2,2,20,14,"                                                                                                   ",512);

	PA_ClearTextBg(kTopScreen);

	if(m_playGame)
	{
		for(int i=0;i<6;i++)
		{
//			PA_iDeaS_DebugPrintf("player %d is %d/n",i,m_playerSelection[i]);
			if(m_playerSelection[i] == kSelectPlayer)
			{
				theResources->m_PlayerDetails[i] = kLocal;
			}
			else if(m_playerSelection[i] == kSelectAiEasy)
			{
				theResources->m_PlayerDetails[i] = kAi;
				theResources->m_AiDetails[i] = kEasy;
			}
			else
			{
				theResources->m_PlayerDetails[i] = kPlayerTypeNone;
			}
		}
	}

	int spriteNumber = 110;
	for(int i = 0;i<6;i++)
	{		
		hideSprite(kBottomScreen,spriteNumber);
		spriteNumber++;
	}

	// Put in a small delay after the menu.
	for(int i=0;i<GLOBALDELAY;i++)
	{
		PA_WaitForVBL();
	}

	PA_DeleteBg(kTopScreen, 1);
	PA_DeleteBg(kBottomScreen, 0);
}
