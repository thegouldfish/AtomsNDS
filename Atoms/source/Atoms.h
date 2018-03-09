#ifndef _ATOMS_H_
#define _ATOMS_H_

#include <PA9.h>

#define VERSION V0.7

//#define DEBUG

enum screens {kBottomScreen,kTopScreen};

enum BGNumbers{kConstantScreen=3,kWiningScreen = 2, kProfScreen=1};

#define MAXPLAYERS 6

#define EXPLODETIME 8

// All the Main game states
enum states{
	kLogoState,kCreditsState,kMenuState,kGameMenuState,
	kGameState,kNewGameState,kPauseState,kHelpState,
	kAIMenuState,
	kStateCount};



// Player details for the game
enum AiLevels{kEasy,kNormal,kHard,kAiCount};
enum PlayerType{kLocal,kAi,kWifi,kInternet,kPlayerTypeNone};


#define GLOBALDELAY 5


// Name and number of supported langagues
enum Langs {kEnglish,kLangCount};


// Current Languge
static volatile Langs g_CurrentLanguage = kEnglish;

// V-Blank count (used for random seeds)
static volatile unsigned long vBlankCount = 0;



// Some usefull functions

inline void showSprite(int screen, int obj)
{
	PA_obj[screen][obj].atr0 &= ~ATTR0_DISABLED;
}


inline void hideSprite(int screen, int obj)
{
	PA_obj[screen][obj].atr0 |= ATTR0_DISABLED;
}

inline long randomSeed()
{
	long seed = (1 + PA_RTC.Seconds + PA_RTC.Minutes*60 + PA_RTC.Hour*3600 + PA_RTC.Day*3600*24+PA_RTC.Month*3600*24*30) + (vBlankCount * PA_RTC.Seconds);
	
#ifdef DEBUG
	PA_iDeaS_DebugPrintf("seed : %d/n",seed);
#endif
	
	return seed;
}

#endif

