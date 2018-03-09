#include "Banner.h"

#include "../gfx/bulk/all_gfx.h"

#include <PA9.h> 
#include "Atoms.h"
#include "TextString.h"

#include <math.h>

// Lots of comments because too tired to code .
void Banner::ChangeOrder(int currentPlayer,  int order[6])
{
	if(currentPlayer >= 6)
		return;

	int nextUp = currentPlayer + 1;


	bool done = false;

	// The current player is being shown in the big BG.
	// Here we need to set who is next.
	// So first the prof who is going up next.



	int i = nextUp;
	int pos = 0;

	// This him shown now the rest of the profs in order.
	while(!done)
	{
		if(order[i] != -1)
		{
			// Don't want to render the current player on the up next list.
			if(i != currentPlayer)	
			{


				// because we did render something move the position to the next slot.
				pos++;
			}
		}


		// Next player coming up.
		i++;

		if(i >= 6)
		{
			i = 0;
		}

		// Once we loop back round to the 
		if(i == nextUp)
		{
			done = true;
		}
	}
}

void Banner::ShowPlayerOrder(int currentPlayer, int numberOfPlayers, int order[MAXPLAYERS], bool Alive[MAXPLAYERS])
{
	int i = currentPlayer + 1;

	int toShow = 0;
	
	bool finished = false;


	for(int i=0;i<MAXPLAYERS;i++)
	{
		if(Alive[i])
		{
			showSprite(kTopScreen,i+20);
			PA_SetSpriteAnim(kTopScreen,i+20,i);
		}
		else
		{
			hideSprite(kTopScreen,i+20);
		}
	}



	for(int i=0;i<numberOfPlayers;i++)
	{
		hideSprite(kTopScreen,i);
	}

	do
	{
		if(i >= numberOfPlayers)
		{
			i = 0;
		}


		if(Alive[order[i]])
		{
			PA_SetSpriteAnim(kTopScreen,toShow,order[i]);
			showSprite(kTopScreen,toShow);

			toShow ++;
		}

		i++;

		if(i >= numberOfPlayers)
		{
			i = 0;
		}


		if( i == currentPlayer)
		{
			finished = true;
		}

	}while(!finished);
}

void Banner::ClearOrderSprites()
{
	PA_ResetSpriteSysScreen(kTopScreen);
}

void Banner::CreateOrderSprites()
{
	int x = 256;
	for(int i=0;i<6;i++)
	{
		if(i == 1)
			x = x - 78;
		else if( i ==0 )
			x = x - 64;
		else
			x = x - 50;

			PA_CreateSprite(kTopScreen, // Screen
					i, // Sprite number
					(void*)UPnext_Sprite, // Sprite name
					OBJ_SIZE_64X64, // Sprite size
					1, // 256 color mode
					1, // Sprite palette number
					x, 0);

			PA_SetSpriteAnim(kTopScreen,i,i);

			hideSprite(kTopScreen,i);
	}


	PA_CreateSprite(kTopScreen, // Screen
		10, // Sprite number
		(void*)human_computer_Sprite, // Sprite name
		OBJ_SIZE_32X32, // Sprite size
		1, // 256 color mode
		2, // Sprite palette number
		223, 160);

		hideSprite(kTopScreen,10);


	for(int i=0;i<6;i++)
	{
		int sprite = i + 20;

		PA_CreateSprite(kTopScreen, // Screen
			sprite, // Sprite number
			(void*)Scalers_Sprite, // Sprite name
			OBJ_SIZE_32X32, // Sprite size
			1, // 256 color mode
			3, // Sprite palette number
			223, 160);

		PA_SetSpriteXY(kTopScreen,sprite,10+(i*15),192-32);

		hideSprite(kTopScreen,sprite);
	}
}


void Banner::HideBanner()
{
	PA_DeleteBg(kTopScreen, kProfScreen);
	PA_DeleteBg(kTopScreen, kConstantScreen);
	PA_DeleteBg(kTopScreen, kWiningScreen);

	hideSprite(kTopScreen,10);

	PA_16cClearZone(kTopScreen,0, 0, 255, 192);
}

void Banner::ShowBanner()
{
	PA_EasyBgLoad(kTopScreen, kConstantScreen, ingame_top);

	PA_Init16cBg(kTopScreen,0);

	PA_16cCustomFont(6, Atoms_Font);
}


void Banner::SetBannerWinner(int banner)
{
	PA_EasyBgLoad(kTopScreen, kWiningScreen, winner_bg);
	PA_EasyBgLoad(kBottomScreen, 1, Title_topscreen);

	switch(banner)
	{
		case 0:
		{
			PA_EasyBgLoad(kTopScreen, kProfScreen, winner_prof1);
			break;
		}

		case 1:
		{
			PA_EasyBgLoad(kTopScreen, kProfScreen, winner_prof2);
			break;
		}

		case 2:
		{
			PA_EasyBgLoad(kTopScreen, kProfScreen, winner_prof3);
			break;
		}

		case 3:
		{
			PA_EasyBgLoad(kTopScreen, kProfScreen, winner_prof4);
			break;
		}

		case 4:
		{
			PA_EasyBgLoad(kTopScreen, kProfScreen, winner_prof5);
			break;
		}

		case 5:
		{
			PA_EasyBgLoad(kTopScreen, kProfScreen, winner_prof6);
			break;
		}
	}
}

void Banner::SetTurnNumber(int turn)
{
	char text[HelpStringSize];

	snprintf(text,HelpStringSize,MiscStrings[g_CurrentLanguage][kMiscTurns],turn);


	PA_16cTextAlign(ALIGN_LEFT);

	//PA_16cClearZone(kTopScreen,0, 145, 255, 155);
	PA_16cText(kTopScreen, //screen 
					5, 115, 255, 125, //x1, y1, x2, y2 position
					text, //text
					1, //color (1-10)
					6, // text size (0-4)
					100);
}


void Banner::SetBanner(int banner,PlayerType Type)
{
	PA_16cTextAlign(ALIGN_LEFT);
	PA_16cClearZone(kTopScreen,0, 0, 256, 192);


	PA_16cText(kTopScreen, //screen 
					5, 85, 255, 95, //x1, y1, x2, y2 position
					ProfessorNameString[g_CurrentLanguage][(ProfessorNames)banner], //text
					ProfessorToColour[banner], //color (1-10)
					6, // text size (0-4)
					100);

	PA_EasyBgLoad(kTopScreen, kConstantScreen, ingame_top);

	showSprite(kTopScreen,10);

	if(Type == kLocal)
	{
		PA_SetSpriteAnim(kTopScreen,10,1);
	}
	else if(Type == kAi)
	{
		PA_SetSpriteAnim(kTopScreen,10,2);
	}

	switch(banner)
	{
		case 0:
		{
			PA_EasyBgLoad(kTopScreen, kProfScreen, InGameProfOne);
			break;
		}

		case 1:
		{
			PA_EasyBgLoad(kTopScreen, kProfScreen, InGameProfTwo);
			break;
		}

		case 2:
		{
			PA_EasyBgLoad(kTopScreen, kProfScreen, InGameProfThree);
			break;
		}

		case 3:
		{
			PA_EasyBgLoad(kTopScreen, kProfScreen, InGameProfFour);
			break;
		}

		case 4:
		{
			PA_EasyBgLoad(kTopScreen, kProfScreen, InGameProfFive);
			break;
		}

		case 5:
		{
			PA_EasyBgLoad(kTopScreen, kProfScreen, InGameProfSix);
			break;
		}
	}
}


Banner::Banner()
{
	// Going to have to create the sprites here.
	PA_LoadSpritePal(kTopScreen,1,(void*)UPnext_Pal);
	PA_LoadSpritePal(kTopScreen,2,(void*)human_computer_Pal);
	PA_LoadSpritePal(kTopScreen,3,(void*)Scalers_Pal);
}


void Banner::showSprite(int screen, int obj)
{
	PA_obj[screen][obj].atr0 &= ~ATTR0_DISABLED;
}


void Banner::hideSprite(int screen, int obj)
{
	PA_obj[screen][obj].atr0 |= ATTR0_DISABLED;
}

//#define USE_PURE

void Banner::ShowPlayerRatings(bool Alive[MAXPLAYERS], int count[MAXPLAYERS], int order[MAXPLAYERS])
{
	int TotalCount = 0;


	char text[100];

	int largest = 0;
	for(int i=0;i<MAXPLAYERS;i++)
	{
		if(Alive[i])
		{
			if(count[i] > largest)
				largest = count[i];

			TotalCount += count[i];
		}
	}

	if(TotalCount > 0)
	{
		for(int i=0;i<MAXPLAYERS;i++)
		{
			float percent = 0.0f;
#ifdef USE_PURE
			percent = (float)count[i] / (float)TotalCount;
#else
			percent = (float)count[i] / (float)largest;
#endif

			percent *= 29.0f;
			percent = ceil(percent);
			percent +=3.0f;

			if(percent > 32.0f)
				percent = 32.0f;

			PA_SetSpriteXY(kTopScreen,20+i,10+(i*15),192-(int)percent);
		}
	}
}