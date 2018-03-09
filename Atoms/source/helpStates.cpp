#include "state.h"
#include "helpStates.h"
#include "Atoms.h"
#include "TextString.h"
#include <PA9.h>
#include "Animations.h"

#include "Explode.h"
#include "grow.h"

#include "../gfx/bulk/all_gfx.h"

HelpState::HelpState()
{
	IntroState = new HelpStateIntro();
	PlaceState = new HelpStatePlaceAtom();
	GrowState = new HelpStateGrowAtom();
	CriticalState = new HelpStateGoCritical();
	ExplodeState = new HelpStateExplodeAtom();
	ExplodeChangeState = new HelpStateExplodeChange();
	ExplodeChainState = new HelpStateExplodeChain();
	SwingState = new HelpStateSwing();
	WinState = new HelpStateWin();
	EndState = new HelpStateEnd();

	HelpStateMachine = new stateMachine(kHelpStateCount);
	HelpStateMachine->addState(IntroState,kHelpStateOne);
	HelpStateMachine->addState(PlaceState,kHelpStateTwo);
	HelpStateMachine->addState(GrowState,kHelpStateThree);
	HelpStateMachine->addState(CriticalState,kHelpStateFour);
	HelpStateMachine->addState(ExplodeState,kHelpStateFive);
	HelpStateMachine->addState(ExplodeChangeState,kHelpStateSix);

	HelpStateMachine->addState(ExplodeChainState,kHelpStateSeven);
	HelpStateMachine->addState(SwingState,kHelpStateEight);
	HelpStateMachine->addState(WinState,kHelpStateNine);
	HelpStateMachine->addState(EndState,kHelpStateTen);

}

void HelpState::enter()
{
	HelpStateMachine->start(kHelpStateOne,stateMachine::kOutOfOrder);	

	for(int i=0;i<70;i++)
	{
		PA_SetSpritePal(kBottomScreen,i,0);
	}
}

void HelpState::update()
{
	if(HelpStateMachine->isRunning())
	{
		HelpStateMachine->update();
	}
	else
	{
		changeState(kGameMenuState);
	}
}

void HelpState::exit()
{
	PA_ResetBgSys();
}


HelpStateBase::HelpStateBase(int txt, int nextState,bool repeats,bool ShowContinue)
{
		m_StringSize = strlen(HelpStrings[txt][kEnglish]);

		m_TextId = txt;
		m_nextState = nextState;


		m_repeat = repeats;
		m_Continue = ShowContinue;
}

void HelpStateBase::enter()
{
	m_CanGo = false;
	m_textCount = 0;

	m_textSpeed = 0;
	m_textUpdate = 0;

	PA_InitText(kTopScreen, 0);
	PA_SetTextCol(kTopScreen,12,12,12);

	PA_EasyBgLoad(kTopScreen, 1, HelpTopScreen);
	PA_EasyBgLoad(kBottomScreen,1,BottomScreen);
}

void HelpStateBase::update()
{
	if(!m_CanGo && Pad.Released.X)
	{
		m_textCount = m_StringSize;
	}


	if(m_textUpdate >= m_textSpeed)
	{
		m_textCount++;
		m_textUpdate = 0;
	}
	
	m_textUpdate++;

	PA_BoxText(kTopScreen,2,2,20,14,HelpStrings[m_TextId][g_CurrentLanguage],m_textCount);
	

	if(m_textCount > m_StringSize)
	{
		m_CanGo = true;

		int quitSquare = 16;

		if(m_Continue)
			PA_OutputText(kTopScreen,2,15,HelpStrings[kHelpContinue][g_CurrentLanguage]);

		if(m_repeat)
		{
			quitSquare = 17;
			PA_OutputText(kTopScreen,2,16,HelpStrings[kHelpRepeat][g_CurrentLanguage]);
		}

			PA_OutputText(kTopScreen,2,quitSquare,HelpStrings[kHelpQuit][g_CurrentLanguage]);
	}
}

void HelpStateBase::exit()
{


}





/*
 * Help states
 *
 *
 *
 *
 *
*/



HelpStateIntro::HelpStateIntro() : HelpStateBase(kHelpIntro,kHelpStateTwo,false,true)
{

}


void HelpStateIntro::enter()
{
	HelpStateBase::enter();
}

void HelpStateIntro::update()
{
	HelpStateBase::update();


	if(m_CanGo && Pad.Released.A)
	{
		changeState(m_nextState);
	}

	if(m_CanGo && Pad.Released.B)
	{
		stop();
	}
}

void HelpStateIntro::exit()
{
	HelpStateBase::exit();
}



HelpStatePlaceAtom::HelpStatePlaceAtom() : HelpStateBase(kHelpPlaceAnAtom,kHelpStateThree,false,false)
{
	PA_LoadSpritePal(kBottomScreen,10,(void*)helpPointer_Pal);


	PA_CreateSprite(kBottomScreen, // Screen
		100, // Sprite number
		(void*)helpPointer_Sprite, // Sprite name
		OBJ_SIZE_64X64, // Sprite size
		1, // 256 color mode
		10, // Sprite palette number
		130, 65);

		hideSprite(kBottomScreen,100);
}


void HelpStatePlaceAtom::enter()
{
	HelpStateBase::enter();


	m_currentState = kGetInput;
	sprite = 0;
}

void HelpStatePlaceAtom::update()
{
	HelpStateBase::update();

	int xx = 4;
	int yy = 3;


	if(m_CanGo)
	{
		showSprite(kBottomScreen,100);
	}


	if(m_currentState == kGetInput)
	{
		if(m_CanGo && Stylus.Released)
		{
			int x = (Stylus.X -8) /8 /3;
			int y = (Stylus.Y -8) /8 /3;

			if(x == xx && y == yy)
			{
				sprite = (y * 10) + x;

				PA_StartSpriteAnimEx(kBottomScreen,sprite,Atom_grow_anims[1][kAnimStart],Atom_grow_anims[1][kAnimEnd],Atom_grow_anims[1][kAnimSpeed],ANIM_UPDOWN,1);
				m_currentState = kAnim;
				AS_SoundQuickPlay(grow);
			}
		}

		if(m_CanGo && Pad.Released.B)
		{
			stop();
		}
	}
	else if(m_currentState == kAnim)
	{
		if(PA_GetSpriteNCycles(kBottomScreen,sprite) == 0)
		{
			changeState(m_nextState);
		}
	}
}

void HelpStatePlaceAtom::exit()
{
	HelpStateBase::exit();
	
	// Put in a small delay after the menu.
	for(int i=0;i<15;i++)
	{
		PA_WaitForVBL();
	}

	hideSprite(kBottomScreen,100);

	PA_StopSpriteAnim(kBottomScreen,sprite);
	PA_SetSpriteAnim(kBottomScreen, sprite, Atom_Sizes[0]);
}



HelpStateGrowAtom::HelpStateGrowAtom() : HelpStateBase(kHelpAtomGrow,kHelpStateFour,false,false)
{

}


void HelpStateGrowAtom::enter()
{
	HelpStateBase::enter();	
	m_currentState = kGetInput;
	sprite = 34;
}

void HelpStateGrowAtom::update()
{
	HelpStateBase::update();

	int xx = 4;
	int yy = 3;

	if(m_CanGo && m_currentState == kGetInput)
	{
		PA_SetSpriteAnim(kBottomScreen, sprite, Atom_Sizes[1]);
		showSprite(kBottomScreen,100);
	}

	if(m_currentState == kGetInput)
	{
		if(m_CanGo && Stylus.Released)
		{
			int x = (Stylus.X -8) /8 /3;
			int y = (Stylus.Y -8) /8 /3;

			if(x == xx && y == yy)
			{
				sprite = (y * 10) + x;

				PA_StartSpriteAnimEx(kBottomScreen,sprite,Atom_grow_anims[2][kAnimStart],Atom_grow_anims[2][kAnimEnd],Atom_grow_anims[2][kAnimSpeed],ANIM_UPDOWN,1);
				m_currentState = kAnim;
				AS_SoundQuickPlay(grow);
			}
		}

		if(m_CanGo && Pad.Released.B)
		{
			stop();
		}
	}
	else if(m_currentState == kAnim)
	{
		if(PA_GetSpriteNCycles(kBottomScreen,sprite) == 0)
		{
			changeState(m_nextState);
		}
	}
}

void HelpStateGrowAtom::exit()
{
	HelpStateBase::exit();
	
	// Put in a small delay after the menu.
	for(int i=0;i<60;i++)
	{
		PA_WaitForVBL();
	}

	hideSprite(kBottomScreen,100);

	PA_StopSpriteAnim(kBottomScreen,sprite);
	PA_SetSpriteAnim(kBottomScreen, sprite, Atom_Sizes[0]);
}







HelpStateGoCritical::HelpStateGoCritical() : HelpStateBase(kHelpGoCritical,kHelpStateFive,false,true)
{

}


void HelpStateGoCritical::enter()
{
	HelpStateBase::enter();
	ShowTable = false;
}

void HelpStateGoCritical::update()
{
	HelpStateBase::update();


	if(m_CanGo && !ShowTable)
	{
		ShowTable = true;

		int sprite = 0;

		for(int i=0;i<7;i++)
		{
			for(int j=0;j<10;j++)
			{				
				if((j==0 || j == 9) && (i == 0 || i == 6))
				{
					PA_SetSpriteAnim(kBottomScreen, sprite, Atom_Sizes[2]);
				}
				else
				{
					if((j==0 || j == 9) || (i == 0 || i == 6))
					{
						PA_SetSpriteAnim(kBottomScreen, sprite, Atom_Sizes[3]);
					}
					else
					{
						PA_SetSpriteAnim(kBottomScreen, sprite, Atom_Sizes[4]);
					}
				}
				

				sprite++;
			}
		}

	}


	if(m_CanGo && Pad.Released.A)
	{
		changeState(m_nextState);
	}

	if(m_CanGo && Pad.Released.B)
	{
		stop();
	}
}

void HelpStateGoCritical::exit()
{
	HelpStateBase::exit();

	for( int i=0;i<70;i++)
	{
		PA_SetSpriteAnim(kBottomScreen, i, Atom_Sizes[0]);
	}
}





HelpStateExplodeAtom::HelpStateExplodeAtom() : HelpStateBase(kHelpExplodeAnim,kHelpStateSix,false,false)
{

}


void HelpStateExplodeAtom::enter()
{
	HelpStateBase::enter();	
	m_currentState = kGetInput;
	sprite = 34;
}

void HelpStateExplodeAtom::update()
{
	HelpStateBase::update();

	int xx = 4;
	int yy = 3;

	if(m_CanGo && m_currentState == kGetInput)
	{
		PA_SetSpriteAnim(kBottomScreen, sprite, Atom_Sizes[3]);
		showSprite(kBottomScreen,100);
	}

	if(m_currentState == kGetInput)
	{
		if(m_CanGo && Stylus.Released)
		{
			int x = (Stylus.X -8) /8 /3;
			int y = (Stylus.Y -8) /8 /3;

			if(x == xx && y == yy)
			{
				sprite = (y * 10) + x;

				PA_StartSpriteAnimEx(kBottomScreen,sprite,Atom_grow_anims[5][kAnimStart],Atom_grow_anims[5][kAnimEnd],Atom_grow_anims[5][kAnimSpeed],ANIM_UPDOWN,1);
				m_currentState = kAnim;
				AS_SoundQuickPlay(Explode);
			}
		}

		if(m_CanGo && Pad.Released.B)
		{
			stop();
		}
	}
	else if(m_currentState == kAnim)
	{
		if(PA_GetSpriteNCycles(kBottomScreen,sprite) == 0)
		{
			for(int i=0;i<30;i++)
			{
				PA_WaitForVBL();
			}

			AS_SoundQuickPlay(grow);
			m_currentState = kAnim2;
			PA_StopSpriteAnim(kBottomScreen,sprite);
			PA_SetSpriteAnim(kBottomScreen, sprite, Atom_Sizes[0]);
			hideSprite(kBottomScreen,100);

			PA_StartSpriteAnimEx(kBottomScreen,sprite+1,Atom_grow_anims[1][kAnimStart],Atom_grow_anims[1][kAnimEnd],Atom_grow_anims[1][kAnimSpeed],ANIM_UPDOWN,1);
			PA_StartSpriteAnimEx(kBottomScreen,sprite-1,Atom_grow_anims[1][kAnimStart],Atom_grow_anims[1][kAnimEnd],Atom_grow_anims[1][kAnimSpeed],ANIM_UPDOWN,1);
			PA_StartSpriteAnimEx(kBottomScreen,sprite+10,Atom_grow_anims[1][kAnimStart],Atom_grow_anims[1][kAnimEnd],Atom_grow_anims[1][kAnimSpeed],ANIM_UPDOWN,1);
			PA_StartSpriteAnimEx(kBottomScreen,sprite-10,Atom_grow_anims[1][kAnimStart],Atom_grow_anims[1][kAnimEnd],Atom_grow_anims[1][kAnimSpeed],ANIM_UPDOWN,1);
		}
	}
	else if(m_currentState == kAnim2)
	{
		if(PA_GetSpriteNCycles(kBottomScreen,sprite-1) == 0)
		{
			changeState(m_nextState);
		}
	}
}

void HelpStateExplodeAtom::exit()
{
	HelpStateBase::exit();
	
	// Put in a small delay after the menu.
	for(int i=0;i<60;i++)
	{
		PA_WaitForVBL();
	}

	hideSprite(kBottomScreen,100);

	PA_StopSpriteAnim(kBottomScreen,sprite);
	PA_SetSpriteAnim(kBottomScreen, sprite, Atom_Sizes[0]);

	PA_SetSpriteAnim(kBottomScreen, sprite+1, Atom_Sizes[0]);
	PA_SetSpriteAnim(kBottomScreen, sprite-1, Atom_Sizes[0]);
	PA_SetSpriteAnim(kBottomScreen, sprite+10, Atom_Sizes[0]);
	PA_SetSpriteAnim(kBottomScreen, sprite-10, Atom_Sizes[0]);
}


HelpStateExplodeChange::HelpStateExplodeChange() : HelpStateBase(kHelpExplodeChange,kHelpStateSeven,false,false)
{

}


void HelpStateExplodeChange::enter()
{
	HelpStateBase::enter();	
	m_currentState = kGetInput;
	sprite = 34;



	PA_SetSpritePal(kBottomScreen,sprite+1,1);
	PA_SetSpritePal(kBottomScreen,sprite-1,2);
	PA_SetSpritePal(kBottomScreen,sprite+10,3);
	PA_SetSpritePal(kBottomScreen,sprite-10,4);

	m_shown = false;

}

void HelpStateExplodeChange::update()
{
	HelpStateBase::update();

	int xx = 4;
	int yy = 3;

	if(m_CanGo && !m_shown)
	{
		m_shown = true;
		PA_SetSpriteAnim(kBottomScreen, sprite, Atom_Sizes[3]);

		PA_SetSpriteAnim(kBottomScreen, sprite+1, Atom_Sizes[1]);
		PA_SetSpriteAnim(kBottomScreen, sprite-1, Atom_Sizes[2]);
		PA_SetSpriteAnim(kBottomScreen, sprite+10, Atom_Sizes[1]);
		PA_SetSpriteAnim(kBottomScreen, sprite-10, Atom_Sizes[2]);

		showSprite(kBottomScreen,100);
	}

	if(m_currentState == kGetInput)
	{
		if(m_CanGo && Stylus.Released)
		{
			int x = (Stylus.X -8) /8 /3;
			int y = (Stylus.Y -8) /8 /3;

			if(x == xx && y == yy)
			{
				sprite = (y * 10) + x;

				hideSprite(kBottomScreen,100);
				PA_StartSpriteAnimEx(kBottomScreen,sprite,Atom_grow_anims[5][kAnimStart],Atom_grow_anims[5][kAnimEnd],Atom_grow_anims[5][kAnimSpeed],ANIM_UPDOWN,1);
				m_currentState = kAnim;
				AS_SoundQuickPlay(Explode);
			}
		}

		if(m_CanGo && Pad.Released.B)
		{
			stop();
		}
	}
	else if(m_currentState == kAnim)
	{
		if(PA_GetSpriteNCycles(kBottomScreen,sprite) == 0)
		{
			for(int i=0;i<30;i++)
			{
				PA_WaitForVBL();
			}
			AS_SoundQuickPlay(grow);
			m_currentState = kAnim2;
			PA_SetSpriteAnim(kBottomScreen, sprite, Atom_Sizes[0]);

			PA_StartSpriteAnimEx(kBottomScreen,sprite+1,Atom_grow_anims[2][kAnimStart],Atom_grow_anims[2][kAnimEnd],Atom_grow_anims[2][kAnimSpeed],ANIM_UPDOWN,1);
			PA_StartSpriteAnimEx(kBottomScreen,sprite-1,Atom_grow_anims[3][kAnimStart],Atom_grow_anims[3][kAnimEnd],Atom_grow_anims[3][kAnimSpeed],ANIM_UPDOWN,1);
			PA_StartSpriteAnimEx(kBottomScreen,sprite+10,Atom_grow_anims[2][kAnimStart],Atom_grow_anims[2][kAnimEnd],Atom_grow_anims[2][kAnimSpeed],ANIM_UPDOWN,1);
			PA_StartSpriteAnimEx(kBottomScreen,sprite-10,Atom_grow_anims[3][kAnimStart],Atom_grow_anims[3][kAnimEnd],Atom_grow_anims[3][kAnimSpeed],ANIM_UPDOWN,1);

			PA_SetSpritePal(kBottomScreen,sprite+1,0);
			PA_SetSpritePal(kBottomScreen,sprite-1,0);
			PA_SetSpritePal(kBottomScreen,sprite+10,0);
			PA_SetSpritePal(kBottomScreen,sprite-10,0);
		}
	}
	else if(m_currentState == kAnim2)
	{
		if(PA_GetSpriteNCycles(kBottomScreen,sprite-1) == 0)
		{
			changeState(m_nextState);
		}
	}
}

void HelpStateExplodeChange::exit()
{
	HelpStateBase::exit();
	
	// Put in a small delay after the menu.
	for(int i=0;i<60;i++)
	{
		PA_WaitForVBL();
	}

	hideSprite(kBottomScreen,100);

	PA_StopSpriteAnim(kBottomScreen,sprite);
	PA_SetSpriteAnim(kBottomScreen, sprite, Atom_Sizes[0]);

	PA_SetSpriteAnim(kBottomScreen, sprite+1, Atom_Sizes[0]);
	PA_SetSpriteAnim(kBottomScreen, sprite-1, Atom_Sizes[0]);
	PA_SetSpriteAnim(kBottomScreen, sprite+10, Atom_Sizes[0]);
	PA_SetSpriteAnim(kBottomScreen, sprite-10, Atom_Sizes[0]);
}





HelpStateExplodeChain::HelpStateExplodeChain() : HelpStateBase(kHelpChaining,kHelpStateEight,false,false)
{

}


void HelpStateExplodeChain::enter()
{
	HelpStateBase::enter();	
	m_currentState = kGetInput;
	sprite = 34;



	PA_SetSpritePal(kBottomScreen,sprite-1,1);
	PA_SetSpritePal(kBottomScreen,sprite-2,2);

	m_shown = false;

}

void HelpStateExplodeChain::update()
{
	HelpStateBase::update();

	int xx = 4;
	int yy = 3;

	if(m_CanGo && !m_shown)
	{
		m_shown = true;
		PA_SetSpriteAnim(kBottomScreen, sprite, Atom_Sizes[3]);

		PA_SetSpriteAnim(kBottomScreen, sprite-1, Atom_Sizes[3]);
		PA_SetSpriteAnim(kBottomScreen, sprite-2, Atom_Sizes[3]);

		showSprite(kBottomScreen,100);
	}

	if(m_currentState == kGetInput)
	{
		if(m_CanGo && Stylus.Released)
		{
			int x = (Stylus.X -8) /8 /3;
			int y = (Stylus.Y -8) /8 /3;

			if(x == xx && y == yy)
			{
				sprite = (y * 10) + x;

				PA_StartSpriteAnimEx(kBottomScreen,sprite,Atom_grow_anims[5][kAnimStart],Atom_grow_anims[5][kAnimEnd],Atom_grow_anims[5][kAnimSpeed],ANIM_UPDOWN,1);
				m_currentState = kAnim;
				hideSprite(kBottomScreen,100);
				AS_SoundQuickPlay(Explode);
			}
		}

		if(m_CanGo && Pad.Released.B)
		{
			stop();
		}
	}
	else if(m_currentState == kAnim)
	{
		if(PA_GetSpriteNCycles(kBottomScreen,sprite) == 0)
		{
			for(int i=0;i<30;i++)
			{
				PA_WaitForVBL();
			}

			AS_SoundQuickPlay(grow);
			AS_SoundQuickPlay(Explode);
			m_currentState = kAnim2;
			PA_SetSpriteAnim(kBottomScreen, sprite, Atom_Sizes[0]);

			// Explode sprite 33
			PA_StartSpriteAnimEx(kBottomScreen,sprite-1,Atom_grow_anims[5][kAnimStart],Atom_grow_anims[5][kAnimEnd],Atom_grow_anims[5][kAnimSpeed],ANIM_UPDOWN,1);
			PA_SetSpritePal(kBottomScreen,sprite-1,0);


			// increase size
			PA_StartSpriteAnimEx(kBottomScreen,sprite+1,Atom_grow_anims[1][kAnimStart],Atom_grow_anims[1][kAnimEnd],Atom_grow_anims[1][kAnimSpeed],ANIM_UPDOWN,1);
			PA_SetSpritePal(kBottomScreen,sprite+1,0);
			

			PA_StartSpriteAnimEx(kBottomScreen,sprite-10,Atom_grow_anims[1][kAnimStart],Atom_grow_anims[1][kAnimEnd],Atom_grow_anims[1][kAnimSpeed],ANIM_UPDOWN,1);
			PA_SetSpritePal(kBottomScreen,sprite-10,0);
			
			PA_StartSpriteAnimEx(kBottomScreen,sprite+10,Atom_grow_anims[1][kAnimStart],Atom_grow_anims[1][kAnimEnd],Atom_grow_anims[1][kAnimSpeed],ANIM_UPDOWN,1);
			PA_SetSpritePal(kBottomScreen,sprite+10,0);
		}
	}
	else if(m_currentState == kAnim2)
	{
		if(PA_GetSpriteNCycles(kBottomScreen,sprite-1) == 0)
		{
			for(int i=0;i<30;i++)
			{
				PA_WaitForVBL();
			}
			AS_SoundQuickPlay(grow);
			AS_SoundQuickPlay(Explode);
			m_currentState = kAnim3;
			PA_SetSpriteAnim(kBottomScreen, sprite-1, Atom_Sizes[0]);

			// Explode sprite 33
			PA_StartSpriteAnimEx(kBottomScreen,sprite-2,Atom_grow_anims[5][kAnimStart],Atom_grow_anims[5][kAnimEnd],Atom_grow_anims[5][kAnimSpeed],ANIM_UPDOWN,1);
			PA_SetSpritePal(kBottomScreen,sprite-2,0);


			// increase size
			PA_StartSpriteAnimEx(kBottomScreen,sprite,Atom_grow_anims[1][kAnimStart],Atom_grow_anims[1][kAnimEnd],Atom_grow_anims[1][kAnimSpeed],ANIM_UPDOWN,1);
			PA_SetSpritePal(kBottomScreen,sprite,0);
			

			PA_StartSpriteAnimEx(kBottomScreen,sprite-10-1,Atom_grow_anims[1][kAnimStart],Atom_grow_anims[1][kAnimEnd],Atom_grow_anims[1][kAnimSpeed],ANIM_UPDOWN,1);
			PA_SetSpritePal(kBottomScreen,sprite-10-1,0);
			
			PA_StartSpriteAnimEx(kBottomScreen,sprite+10-1,Atom_grow_anims[1][kAnimStart],Atom_grow_anims[1][kAnimEnd],Atom_grow_anims[1][kAnimSpeed],ANIM_UPDOWN,1);
			PA_SetSpritePal(kBottomScreen,sprite+10-1,0);
		}
	}
	else if(m_currentState == kAnim3)
	{
		if(PA_GetSpriteNCycles(kBottomScreen,sprite-2) == 0)
		{
			for(int i=0;i<30;i++)
			{
				PA_WaitForVBL();
			}
			AS_SoundQuickPlay(grow);
			m_currentState = kAnim4;
			PA_SetSpriteAnim(kBottomScreen, sprite-2, Atom_Sizes[0]);

			// Explode sprite 33
			PA_StartSpriteAnimEx(kBottomScreen,sprite-3,Atom_grow_anims[1][kAnimStart],Atom_grow_anims[1][kAnimEnd],Atom_grow_anims[1][kAnimSpeed],ANIM_UPDOWN,1);
			PA_SetSpritePal(kBottomScreen,sprite-3,0);


			// increase size
			PA_StartSpriteAnimEx(kBottomScreen,sprite-1,Atom_grow_anims[1][kAnimStart],Atom_grow_anims[1][kAnimEnd],Atom_grow_anims[1][kAnimSpeed],ANIM_UPDOWN,1);
			PA_SetSpritePal(kBottomScreen,sprite-1,0);

			PA_StartSpriteAnimEx(kBottomScreen,sprite-10-2,Atom_grow_anims[1][kAnimStart],Atom_grow_anims[1][kAnimEnd],Atom_grow_anims[1][kAnimSpeed],ANIM_UPDOWN,1);
			PA_SetSpritePal(kBottomScreen,sprite-10-2,0);
			
			PA_StartSpriteAnimEx(kBottomScreen,sprite+10-2,Atom_grow_anims[1][kAnimStart],Atom_grow_anims[1][kAnimEnd],Atom_grow_anims[1][kAnimSpeed],ANIM_UPDOWN,1);
			PA_SetSpritePal(kBottomScreen,sprite+10-2,0);
		}
	}



	else if(m_currentState == kAnim4)
	{
		PA_StopSpriteAnim(kBottomScreen, sprite-2);
		PA_SetSpriteAnim(kBottomScreen, sprite-2, Atom_Sizes[0]);

		if(PA_GetSpriteNCycles(kBottomScreen,sprite-1) == 0)
		{
			changeState(m_nextState);
		}
	}

}

void HelpStateExplodeChain::exit()
{
	HelpStateBase::exit();
	
	// Put in a small delay after the menu.
	for(int i=0;i<60;i++)
	{
		PA_WaitForVBL();
	}

	hideSprite(kBottomScreen,100);

	for( int i=0;i<70;i++)
	{
		PA_StopSpriteAnim(kBottomScreen,i);
		PA_SetSpriteAnim(kBottomScreen, i, Atom_Sizes[0]);
	}
}




HelpStateSwing::HelpStateSwing() : HelpStateBase(kHelpChainSwing,kHelpStateNine,false,true)
{

}


void HelpStateSwing::enter()
{
	HelpStateBase::enter();
}

void HelpStateSwing::update()
{
	HelpStateBase::update();


	if(m_CanGo && Pad.Released.A)
	{
		changeState(m_nextState);
	}

	if(m_CanGo && Pad.Released.B)
	{
		stop();
	}
}

void HelpStateSwing::exit()
{
	HelpStateBase::exit();
}







HelpStateWin::HelpStateWin() : HelpStateBase(kHelpHowToWin,kHelpStateTen,false,true)
{

}


void HelpStateWin::enter()
{
	HelpStateBase::enter();
}

void HelpStateWin::update()
{
	HelpStateBase::update();


	if(m_CanGo && Pad.Released.A)
	{
		changeState(m_nextState);
	}

	if(m_CanGo && Pad.Released.B)
	{
		stop();
	}
}

void HelpStateWin::exit()
{
	HelpStateBase::exit();
}








HelpStateEnd::HelpStateEnd() : HelpStateBase(kHelpEnd,kHelpStateOne,false,true)
{

}


void HelpStateEnd::enter()
{
	HelpStateBase::enter();
}

void HelpStateEnd::update()
{
	HelpStateBase::update();


	if(m_CanGo && Pad.Released.A)
	{
		stop();
	}

	if(m_CanGo && Pad.Released.B)
	{
		stop();
	}
}

void HelpStateEnd::exit()
{
	HelpStateBase::exit();
}