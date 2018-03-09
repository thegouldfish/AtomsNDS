// PALib Template Application

// Includes
#include <PA9.h>

#include "Atoms.h"
#include "square.h"
#include "../gfx/Atoms/all_gfx.c"
#include "../gfx/Atoms/all_gfx.h"

#include "../gfx/bulk/all_gfx.h"
#include "../gfx/bulk/all_gfx.c"

#include "game.h"
#include "Banner.h"
#include "resources.h"

#include "stateMachine.h"
#include "GameState.h"
#include "MenuState.h"
#include "NewGameState.h"
#include "CreditState.h"
#include "PauseState.h"
#include "LogoState.h"
#include "helpStates.h"
#include "GameMenuState.h"
#include "AIMenuState.h"

Game*			TheGame;
Banner*			TheBanner;
resources*		TheResources;


stateMachine*	worldStates;

GameState*		TheGameState;
MenuState*		TheMenuState;
NewGameState*	TheNewGameState;
CreditState*	TheCreditsState;
PauseState*		ThePauseState;
LogoState*		TheLogoState;
HelpState*		TheHelpState;
GameMenuState*	TheGameMenuState;
AIMenuState*	TheAIMenuState;


int main()
{
	PA_Init();    // Initializes PA_Lib
	PA_InitVBL(); // Initializes a standard VBL

	PA_InitText(kTopScreen, 0);

	PA_Init16cBg(kTopScreen,0);

	// Setup the MP3 playback.
	PA_VBLFunctionInit(AS_SoundVBL);
	AS_Init(AS_MODE_MP3 | AS_MODE_8CH);
	AS_SetDefaultSettings(AS_PCM_8BIT, 22050, AS_NO_DELAY);
	AS_SetMP3Volume(127);

	// Create all the main game elements.
	TheGame			= new Game();
	TheBanner		= new Banner();
	TheResources	= new resources();

	// set the default player count.
	TheResources->playerCount = MAXPLAYERS;

	// Main state machine
	worldStates		= new stateMachine(kStateCount);

	// Create the states.
	TheMenuState		= new MenuState(TheResources);
	TheGameState		= new GameState(TheResources,TheGame,TheBanner);
	TheNewGameState		= new NewGameState(TheBanner,TheGame);
	TheCreditsState		= new CreditState();
	ThePauseState		= new PauseState(TheResources);
	TheLogoState		= new LogoState();
	TheHelpState		= new HelpState();
	TheGameMenuState	= new GameMenuState(TheResources);
	TheAIMenuState		= new AIMenuState(TheResources);


	// Add the states to the machine.
	worldStates->addState(TheLogoState,kLogoState);
	worldStates->addState(TheCreditsState,kCreditsState);
	worldStates->addState(TheMenuState,kMenuState);
	worldStates->addState(TheGameState,kGameState);
	worldStates->addState(TheNewGameState,kNewGameState);
	worldStates->addState(ThePauseState,kPauseState);
	worldStates->addState(TheHelpState,kHelpState);
	worldStates->addState(TheGameMenuState,kGameMenuState);
	worldStates->addState(TheAIMenuState,kAIMenuState);

	// Hide the banner before the game
	TheBanner->HideBanner();

	// and start the state machine.
	worldStates->start(kLogoState,stateMachine::kOutOfOrder);



	// Simple update loop.
	while (1)
	{
		vBlankCount++;

		worldStates->update();

		PA_WaitForVBL();
	}
	
	return 0;
}

